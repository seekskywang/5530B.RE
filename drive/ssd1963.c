/******************************************************************/
/* ĻԆĈ                                          					    */
/* Чڻú                                                        */
/* Śɝú ssd1963Ƚ֯ԌѲ																		    */
/* ط֟únֱ                                                    */
/* jϵ׽ʽúQQ:363116119                                        */
/******************************************************************/
#include "stm32f4xx.h"
#include <stdint.h>
#include "stm32f4xx_fsmc.h"
#include "ssd1963.h"
#include "my_register.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

/******************************************************************/
vu32     HDP=479;

vu32     HT=531;
vu32     HPS=43;
vu32     LPS=8;
vu8      HPW=10;

vu32     VDP=271;

vu32     VT=288;
vu32     VPS=12;
vu32     FPS=4;
vu8      VPW=10;

void sLCD_WR_REG(unsigned int index)
{
	*(__IO u16 *) (Bank1_LCD_C)= index;

}

void sLCD_WR_Data(unsigned int val)
{   
	*(__IO u16 *) (Bank1_LCD_D)= val; 	
}

vu16 sLCD_Read_Data(void)
{
 

   return  *(__IO u16 *) (Bank1_LCD_D);

     
}

void sLCD_OpenWindow(vu32 x1, vu32 y1, vu32 x2, vu32 y2)
{
	sLCD_WR_REG(0x002a);
	sLCD_WR_Data(x1>>8);
	sLCD_WR_Data(x1);
	sLCD_WR_Data(x2>>8);
	sLCD_WR_Data(x2);

	sLCD_WR_REG(0x002b);
	sLCD_WR_Data(y1>>8);
	sLCD_WR_Data(y1);
	sLCD_WR_Data(y2>>8);
	sLCD_WR_Data(y2);
	sLCD_WR_REG(0x002C);
}

vu16 sLCD_BGR2RGB(vu16 c)
{
  vu16  r, g, b, rgb;

  b = (c>>0)  & 0x1f;
  g = (c>>5)  & 0x3f;
  r = (c>>11) & 0x1f;
  
  rgb =  (b<<11) + (g<<5) + (r<<0);

  return( rgb );
}

void Delay_usS(vu16 ustime)
{
  vu16 ii,jj;

  for (ii=0; ii<ustime; ++ii)
  {
    jj=4;
    do
    {
      NOP;
			NOP;
			NOP;
			NOP;
			NOP;
    }while (--jj);
  }
}
void  Delay_ms(vu16 mstime)
{                                                           
  while (mstime--)
  {
    Delay_usS(1000);
  }
}
void sLCD_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;//
    
		GPIO_PinAFConfig(GPIOD,GPIO_PinSource7,GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOD,GPIO_PinSource11,GPIO_AF_FSMC);
	
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource4, GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FSMC);
	

		GPIO_PinAFConfig(GPIOE, GPIO_PinSource7 , GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource8 , GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource9 , GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource10 , GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource11 , GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource12 , GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource13 , GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource14 , GPIO_AF_FSMC);
		GPIO_PinAFConfig(GPIOE, GPIO_PinSource15 , GPIO_AF_FSMC);
    /*
        FSMC Data ڜޅԵʼۯ D0~D15
    */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_8 | 
                                    GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_0 |
                                    GPIO_Pin_1 ;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//ΆάˤԶ
		GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | 
                                    GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 |
                                    GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 ;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//ΆάˤԶ
		GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    /*
        CS      RD      RW      RS
    */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_4 | GPIO_Pin_5 |
                                    GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOD,GPIO_Pin_13);//RST_lcd
 }

 void sLCD_FSMC_Config(void)
{		
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
	FSMC_NORSRAMTimingInitTypeDef  FSMC_NORSRAMTimingInitStructure;

	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC,ENABLE);//开启FSMC时钟
	/*-- FSMC Configuration ------------------------------------------------------*/

	FSMC_NORSRAMTimingInitStructure.FSMC_AddressSetupTime = 8;
	FSMC_NORSRAMTimingInitStructure.FSMC_AddressHoldTime = 0;
	FSMC_NORSRAMTimingInitStructure.FSMC_DataSetupTime = 18;
	FSMC_NORSRAMTimingInitStructure.FSMC_BusTurnAroundDuration = 0x00;
	FSMC_NORSRAMTimingInitStructure.FSMC_CLKDivision = 0x00;
	FSMC_NORSRAMTimingInitStructure.FSMC_DataLatency = 0x00;
	FSMC_NORSRAMTimingInitStructure.FSMC_AccessMode = FSMC_AccessMode_A;

	/*
	 LCD configured as follow:
	    - Data/Address MUX = Disable
	    - Memory Type = SRAM
	    - Data Width = 16bit
	    - Write Operation = Enable
	    - Extended Mode = Enable
	    - Asynchronous Wait = Disable
	*/
	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;//  
  FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable; // 
  FSMC_NORSRAMInitStructure.FSMC_MemoryType =FSMC_MemoryType_SRAM;// FSMC_MemoryType_SRAM;  //SRAM   
  FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;//16BIT数据
  FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode =FSMC_BurstAccessMode_Disable;// FSMC_BurstAccessMode_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;   
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;  
  FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;	// 
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;   
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable; //
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable; 

  FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  //

  FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  //
}


void sLCD_Clear(u16 color)
{
    unsigned int l=480 ,w;
    /*
	sLCD_WR_REG(0x002A);	
	sLCD_WR_Data(0);	    
	sLCD_WR_Data(0);
	sLCD_WR_Data(HDP>>8);	    
	sLCD_WR_Data(HDP&0x00ff);
    sLCD_WR_REG(0x002b);	
	sLCD_WR_Data(0);	    
	sLCD_WR_Data(0);
	sLCD_WR_Data(VDP>>8);	    
	sLCD_WR_Data(VDP&0x00ff);
	*/
	sLCD_OpenWindow(0, 0, HDP, VDP);
	sLCD_WR_REG(0x002c);
    
	while(l--)
	{
	    for(w=0;w<272;w++)
		{    
			sLCD_WR_Data(color);
		//  sLCD_WR_Data(color);
		 // sLCD_WR_Data(color);
		}
	}
}

void sLCD_Init(void)
{
    vu16 DeviceCode;
    sLCD_WR_REG(0xa1);
    DeviceCode = sLCD_Read_Data();    
    DeviceCode = sLCD_Read_Data();    
    DeviceCode = sLCD_Read_Data();    
    DeviceCode = sLCD_Read_Data();    
    DeviceCode = sLCD_Read_Data();    
    DeviceCode = DeviceCode;
    //  Step 2: PLLʨ׃
    sLCD_WR_REG(0x00E2);     //0XE2ˇʨ׃PLL ք݄զǷc
    sLCD_WR_Data(0x001D);// (0x002C);//   //ʨ׃ѶƵ˽ M   0x21D for 10M
    sLCD_WR_Data(0x0002);    //ʨ׃ؖƵ˽ N
    sLCD_WR_Data(0x0004);    //ʹŜMN   PLL = INCLK*(M+1) / (N+1)  PLL ѶƵս120M PLL=8*44/3=120M

    sLCD_WR_REG(0x00E0);     //0XE0ˇPLLʹŜ݄զǷ
    sLCD_WR_Data(0x0001);    //ЈߪǴPLL
    Delay_ms(10);
	
    sLCD_WR_REG(0x00E0);     //۹ҪһՎ
    sLCD_WR_Data(0x0003);    // ʹԃ PLLطΪʱד
    Delay_ms(10);
    sLCD_WR_REG(0x0001);     // ɭݾشλ
    Delay_ms(10);

    //step 3 : ʨ׃PCLKìҲߍˇб̘ʱד
    sLCD_WR_REG(0xE6);        //ᅣ̓۴𜁘E6ˇʨ׃б̘ʱדք݄զǷ  
    sLCD_WR_Data(0x0001);//(0x01);//       //ϒքǁĻˇ4.3էì֢ٶƵÊߍࠉӔìɧڻǁĻ҈ޏճìԐʁ˸ք۰ìࠉӔՙݓճ
    sLCD_WR_Data(0x0093);//(0x93);//
    sLCD_WR_Data(0x0032);// ( 0xE0);//     //μ݇˵ì݄զǷָ®ּˇ8λԫˤքì֢oքб̘ʱדѨҪ3ٶؖޚ4ʨ׃ìٟλ՚ǰ

    //step 4 : ʨ׃LCDքДʾģʽìѨҪٹߝǁĻճСۍLCDք֧·࠘׆׽רРƥƤì
    sLCD_WR_REG(0x00B0);        //ʨ׃LCDДʾģʽܰؖҦÊ
    sLCD_WR_Data(0x0020);//(0x0018);        // ʹŜFRC 0X0018 18bit LCD࠘׆ 
    sLCD_WR_Data(0x0000);     //TFTģʽ
    sLCD_WR_Data((HDP>>8)&0X00FF);  //Set HDP         ˮƽճС
    sLCD_WR_Data(HDP&0X00FF);             //˫ؖޚìٟλ՚ǰ
    sLCD_WR_Data((VDP>>8)&0X00FF);  //Set VDP         Թֱԟէ
    sLCD_WR_Data(VDP&0X00FF);
    sLCD_WR_Data(0x0000);                        //RGB˳ѲԮѐTFTޓࠚ

    sLCD_WR_REG(0x00B4);        //ʨ׃  ˮƽДʾʱݤӎ˽
    sLCD_WR_Data((HT>>8)&0X00FF);  //Set HT ˮƽ؜לǚ
    sLCD_WR_Data(HT&0X00FF);
    sLCD_WR_Data((HPS>>8)&0X00FF);  //Set HPS ˮƽͬҽöԥߪʼλ
    sLCD_WR_Data(HPS&0X00FF);
    sLCD_WR_Data(HPW);                           //Set HPW ˮƽͬҽöԥ࠭׈
    sLCD_WR_Data((LPS>>8)&0X00FF);  //Set LPS Дʾߪʼλ
    sLCD_WR_Data(LPS&0X00FF);
    sLCD_WR_Data(0x0000);         //TFT modeЂìɧՋʨ׃

    sLCD_WR_REG(0x00B6);        //ʨ׃        ԹֱДʾʱݤӎ˽
    sLCD_WR_Data((VT>>8)&0X00FF);   //Set VT Թֱ؜לǚ
    sLCD_WR_Data(VT&0X00FF);
    sLCD_WR_Data((VPS>>8)&0X00FF);  //Set VPS Թֱͬҽöԥߪʼλ
    sLCD_WR_Data(VPS&0X00FF);
    sLCD_WR_Data(VPW);                           //Set VPWԹֱͬҽöԥ࠭׈
    sLCD_WR_Data((FPS>>8)&0X00FF);  //Set FPS  Дʾߪʼλ׃
    sLCD_WR_Data(FPS&0X00FF);
    
    sLCD_WR_REG(0X0036);    //ʨ׃Փ׷ׁܺȡָ®˳ѲìࠉӔʡÔìʏ֧ĬɏΪ0
    sLCD_WR_Data(0X0000);
    sLCD_WR_REG(0x00F0); //pixel data interface  ʨ׃б̘˽ߝޓࠚΪ16λ
    sLCD_WR_Data(0x0003); //03Ϊ 565 ք16λͨѶc
    
    //step 5 : ࠉѡcʨ׃ͼю۳Ԧmc
    //sLCD_WR_REG(0x0021);        //޸ɫͼюҕɫ׭תģʽ 

    //sLCD_WR_REG(0x00BC);//ʨ׃ͼб۳Ԧm
    //sLCD_WR_Data(0x005A);//(0x0080);//ה҈׈
    //sLCD_WR_Data(0x0064);//(0x0080);//׈
    //sLCD_WR_Data(0x005A);//(0x0080);//ѥۍ׈ֵ  //
    //sLCD_WR_Data(0x0001);//ԦmܺՊѭ

    //sLCD_Clear(0Xffff);//ˢԉїɫ
    //sLCD_Clear(0x0000000);//ۚɫ
    sLCD_WR_REG(0x0029); //display on
    
//    // step 6 ìѳڢʨ׃ìҲˇǁĻǰ4քһҽc
//    sLCD_WR_REG(0x00BE); //set PWM࠘׆
//    sLCD_WR_Data(0x0006);        //PWMƵÊ = PLL / (256* 0x06) /256        
//    sLCD_WR_Data(0x00ff); // PWMռࠕ҈ʨ׃ 
//    sLCD_WR_Data(0x09); //DBC ࠘׆PWM ʹŜ 
//    sLCD_WR_Data(0xFF); //DBC˖֯׈ʨ׃
//    sLCD_WR_Data(0x00); //DBC خС׈ʨ׃ 
//    sLCD_WR_Data(0x00);
//
//    sLCD_WR_REG(0xD4); //ʨ׃ÿٶֈܶք֧Դקֵ
//    //TH1 = display width * display height * 3 * 0.1 /16 
//    //480*272 * 3 * 0.1 /16 =990H
//    sLCD_WR_Data(0x00); // 
//    sLCD_WR_Data(0x09); // 
//    sLCD_WR_Data(0x90); // 
//  
//    //TH2 = display width * display height * 3 * 0.25 /16
//    //480*272 * 3 * 0.25 /16 =17E8H
//    sLCD_WR_Data(0x00); // 
//    sLCD_WR_Data(0xE8); // 
//
//    //TH3 = display width * display height * 3 * 0.6 /16 
//    //480*272 * 3 * 0.6 /16 =3960H
//    sLCD_WR_Data(0x00); // 
//    sLCD_WR_Data(0x39); // 
//    sLCD_WR_Data(0x60); //
//                 
//    sLCD_WR_REG(0x00d0);//ʨ׃̬֯ѳڢ࠘׆Ƥ׃ 
//    sLCD_WR_Data(0x000d); 
}

void LCD_Initializtion(void)
{   
    sLCD_GPIO_Config();
    sLCD_FSMC_Config();
    NOP;
		NOP;
		NOP;NOP;
		NOP;
		NOP;
		NOP;
    sLCD_Init();
}

void LCD_SetPoint(vu16 x,vu16 y,vu16 c)
{
    sLCD_OpenWindow(x, y, x, y);
    sLCD_WR_REG(0x2c);
    sLCD_WR_Data(c);
}

vu16 LCD_GetPoint(vu16 x, vu16 y)
{
    vu16 temp;
    
    sLCD_OpenWindow(x, y, x, y);

    sLCD_WR_REG(0x2e);
    temp = sLCD_Read_Data();
    
	return temp;
}

