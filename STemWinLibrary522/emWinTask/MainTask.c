/******************************************************************/
/* 名称：                                                  				*/
/* 效果：                                                        */
/* 内容：内阻仪界面                                              */
/* 作者：zhan                                                  */
/* 联系方式QQ:363116119                                        */

#include "MainTask.h"
#include  "gui.h"
#include  "adc.h"
#include  "tim2.h"
#include  "key.h"
#include  "beep.h"
#include "my_register.h"
#include "stm32f4xx_dac.h"
#include "modbus.h"
#include "ssd1963.h"
#include "tm1650.h"
#include "dac8531.h"
#include "tm7707.h"
extern struct bitDefine
{
    unsigned bit0: 1;
    unsigned bit1: 1;
    unsigned bit2: 1;
    unsigned bit3: 1;
    unsigned bit4: 1;
    unsigned bit5: 1;
    unsigned bit6: 1;
    unsigned bit7: 1;
} flagA, flagB,flagC,flagD,flagE,flagF,flagG;

extern vu8 resetflag;
extern vu8 resdone;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontHZ16;
extern WM_HWIN CreateWindow(void);
extern WM_HWIN CreateR(void);

static void ee_Delay( vu32 nCount)	 //ݲեքғʱگ˽
{
	for(; nCount != 0; nCount--);
}

/**********************************************************************************************************
*	�� �� ��: MainTask
*	����˵��: GUI������
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void MainTask(void) 
{ 
//	unsigned char  ucKeyCode;
    static int read1963;
    static int scancount;
	GUI_Init();
	WM_SetDesktopColor(GUI_BLUE);  
	GUI_Clear();//����
	WM_SetCreateFlags(WM_CF_MEMDEV);
	PROGBAR_SetDefaultSkin(PROGBAR_SKIN_FLEX);
	FRAMEWIN_SetDefaultSkin(FRAMEWIN_SKIN_FLEX);
	PROGBAR_SetDefaultSkin(PROGBAR_SKIN_FLEX);
	BUTTON_SetDefaultSkin(BUTTON_SKIN_FLEX);
	CHECKBOX_SetDefaultSkin(CHECKBOX_SKIN_FLEX);
	DROPDOWN_SetDefaultSkin(DROPDOWN_SKIN_FLEX);
	SCROLLBAR_SetDefaultSkin(SCROLLBAR_SKIN_FLEX);
	SLIDER_SetDefaultSkin(SLIDER_SKIN_FLEX);
	HEADER_SetDefaultSkin(HEADER_SKIN_FLEX);
	RADIO_SetDefaultSkin(RADIO_SKIN_FLEX);
    CreateSTARTER();
//	CreateR();//��������������Խ���
	flag_Load_CC=1;//��������Ĭ�Ͻ���CCģʽ
	GPIO_ResetBits(GPIOC,GPIO_Pin_12);//CC
	GPIO_SetBits(GPIOA,GPIO_Pin_15);//OFF
	Flag_Swtich_ON=0;
	while (1)
	{
//         if(resdone != 1)
//         {
            if(page_sw != face_starter)
            {
                if(scancount == 9)
                {
                    sLCD_WR_REG(0xf1);
                    ee_Delay(30);
                    read1963 =sLCD_Read_Data();
                    scancount = 0;
                }else{
                    scancount++;
                }
//                 if(resdone == 1)
//                 {
//                     sLCD_WR_REG(0xf1);
//                     ee_Delay(30);
//                     read1963 =sLCD_Read_Data();
//                 }
                 if(read1963 != 0x03)
                 {
                     resetflag = 1;               
                 }else{
                     resdone = 0;
                     resetflag = 0; 
                 }
            }
//         }else{
//             resetflag = 0; 
//         }
        
		TIM_SetCompare1(TIM2,Contr_Current);//��ѹ��Դ����DAC
		TIM_SetCompare2(TIM2,Contr_Voltage);//��ѹ��Դ��ѹDAC
		DAC8531_Send(Contr_Laod);//����DACֵ
		if(Flag_DAC_OFF==0)
		{
			Transformation_ADC();
		}
		if(Flag_ADC_Full==1)
		{
			Flag_ADC_Full=0;
			ADC_CH_Scan();//ADC�˲�
		}
		if(flag_TM7707_CH==1)//TM7707��ͨ������ת��
		{
			TM7707_ReadADCValue(CH_1);//CH1
		}
		else
		{
			TM7707_ReadADCValue(CH_2);//CH2
		}
		if(UART_Buffer_Rece_flag==1)
		{
			UART_Buffer_Rece_flag=0;
			UART_Action();
		}
		if(Flag_Key_Scan==1)
		{
			Flag_Key_Scan=0;
			NewKey=TM1650_Read_KEY();
			Flag_Key_Scan = 1;
		}
		Key_Funtion();//���̴���
		Temp_Comapre();//���ȿ���
		BEEP_Ring();//������
		GUI_Delay(2);//GUIˢ��
	}
  
}


/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
