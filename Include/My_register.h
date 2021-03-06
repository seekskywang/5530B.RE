/******************** (C) COPYRIGHT 2014 KUNKIN********************
 * 文件名  ：my_register
 * 作者    ：李振
 * 描述    ：库函数版
 * 内容    ：Define register定义系统使用的寄存器，全局变量
 * 注意		 ：头文件中只能有声明，不能有定义
 * 修改日期：2014-12-9
*********************************************************************/

#include "STM32F4xx.h"
#ifndef __my_register_h__
#define __my_register_h__
//=============================================================================
void Write_Limits(void);
void Wrtite_step(void);
void OC_ADD(void);
void Wrtite_S(void);
void Write_oct(void);
void Write_alarm(void);
void Write_btype(void);
void Write_LOAD(void);
void Write_info(void);
void OC_CHECK(void);
void INPUT_POW(char* num);  
void INPUT_NUM(char* num); 
void INPUT_CDC(char* num); 
void INPUT_C(char* num);  
void INPUT_LOAD(char* num);  
void INPUT_INFO(vu8 num);
void SET_OP_DOWN(void);
void SET_OP_UP(void);
void SET_OP_RIGHT(void);
void SET_OP_LEFT(void);
void PARA_SET(void);
void SYS_INFO_RIGHT(void);
void SYS_INFO_LEFT(void);
void SYS_INFO_UP(void);
void SYS_INFO_DOWN(void);
void INPUT_INFO(vu8 num);
void CDC_OP_DOWN(void);
void CDC_OP_UP(void);
void CDC_OP_LEFT(void);
void CDC_OP_RIGHT(void);
void CDC_SET(void);
void INPUT_CDC(char* num); 
//=============================================================================
#define NOP   __nop();	  //空指令

//============================================================================
extern struct bitDefine flagA,flagB,flagC,flagD,flagE,flagF,flagG;
#define   Flag_ADC_Full             (flagA.bit1)//DMA传输完成标志位 
#define   Flag_BEEP						    	(flagA.bit2)//蜂鸣器触发标志
#define   Flag_Key_Scan							(flagA.bit3)//按键定时扫描标志
#define   UART_SEND_flag						(flagA.bit4)//串口发送完成标志
#define   UART_Buffer_Rece_flag			(flagA.bit5)//串口接收完成标志
#define   Flag_Swtich_ON      			(flagA.bit6)//启动按键处于ON标志
#define   Flag_0_5S      		      	(flagA.bit7)//显示设置电压闪烁标志

#define   Flag_1S      		         	(flagB.bit0)//显示设置电流闪烁标志
#define   Flag_5S      		        	(flagB.bit1)//退出设置状态标志
#define   Flag_Long                 (flagB.bit2)//按键长按标志
#define   Flag_DAC_OFF              (flagB.bit3)//鏄惁杞崲DAC鎺у埗鍊兼爣蹇�
#define   Flag_SetA                 (flagB.bit5)//进入设置电流标志位
#define   Flag_SetV                 (flagB.bit6)//进入设置电压标志位 
#define   Flag_DisSet               (flagB.bit7)//显示设置电压和电流标志位

#define   Flag_GE                   (flagC.bit0)//个位闪烁标志
#define   Flag_SHI                  (flagC.bit1)//十位闪烁标志
#define   Flag_BAI                  (flagC.bit2)//百位闪烁标志
#define   Flag_QIAN                 (flagC.bit3)//千位闪烁标志
#define   Flag_Beep_OFF             (flagC.bit6)//蜂鸣器关闭标志

#define   flag_Tim_USART            (flagD.bit0)//串口计算清零标志
#define   flag_Test                 (flagD.bit1)//自动测试起停标志
#define   flag_Test_PASS            (flagD.bit2)//自动测试PASS标志
#define   flag_Test_FAIL            (flagD.bit3)//自动测试FAIL标志
#define   flag_Test_Time            (flagD.bit4)//自动测试等待时间标志
#define   flag_Test_Start           (flagD.bit5)//自动测试比较开始标志
#define   flag_Test_Min             (flagD.bit6)//自动测试下限标志
#define   flag_Load_CC              (flagD.bit7)//负载CC/CV模式标志位

#define   flag_Test_Door             (flagE.bit0)//自动测试门槛标志
#define   flag_Test_SetTime          (flagE.bit1)//自动测试时间标志 
#define   flag_OVP                   (flagE.bit2)//OVP标志
#define   flag_OCP                   (flagE.bit3)//OCP标志
#define   flag_Doub                  (flagE.bit4)//按键双击
#define   flag_t_Doub                (flagE.bit5)//按键双击计时标志
#define   flag_Time_SW               (flagE.bit6)//定时功能开启标志
#define   flag_CC_MODE               (flagE.bit7)//工作模式标志

#define   flag_Adjust                (flagF.bit0)//
#define   flag_ADJ_ON                (flagF.bit1)//
#define   flag_ADJ_VL                (flagF.bit2)//
#define   flag_ADJ_VH                (flagF.bit3)//
#define   flag_ADJ_ALCC              (flagF.bit4)//
#define   flag_ADJ_AHCC              (flagF.bit5)//
#define   flag_ADJ_ALCV              (flagF.bit6)//
#define   flag_ADJ_AHCV              (flagF.bit7)//

#define   flag_DisVL                 (flagG.bit0)//
#define   flag_OverV                 (flagG.bit1)//
#define   flag_OverACC               (flagG.bit2)//
#define   flag_OverACV               (flagG.bit3)//
#define   flag_Just_Usart            (flagG.bit4)//
#define   flag_FAN_ON                (flagG.bit5)//
#define   flag_ADJ_FAN               (flagG.bit6)//
#define   flag_TM7707_CH						 (flagG.bit7)//
//=============================================================================
extern vu32 GE_V;
extern vu32 SHI_V;
extern vu32 BAI_V;
extern vu32 QIAN_V;  //数码管扫描段码
extern vu32 GE_A;
extern vu32 SHI_A;
extern vu32 BAI_A;
extern vu32 QIAN_A;
//--------------------------
extern vu8 NewKey;
extern vu8 DAC_Flag;
extern vu8 Beep_Flag;
extern vu8 t_beep;
extern vu8 t_KeyScan;
extern vu8 t_LEDScan;  //定时计数器
extern vu8 t_KEYON;
extern vu16 t_0_5S;
extern vu16 t_1S;
extern vu16 t_5S;
extern vu16 t_Basket;
extern vu16 Basket_V;
extern vu16 Basket_A;
extern vu16 t_OFF_V;
extern vu16 t_ON_V;
extern vu16 t_OFF_A;
extern vu16 t_ON_A;
extern vu8 t_USART;
extern vu16 ADJ_Write;//校准时需写入的实际值
extern vu8 OFFSET_Zore;//零点值
extern vu8 ADDR;
extern vu8 t_lock;
extern vu8 t_onoff;
extern vu16 MAX_limit;
extern vu16 MIN_limit;
extern vu16 Test_Time;
extern vu16 Test_Time1;
extern vu16 Time_sw;
extern vu16 Test_Daley;
extern vu16 Test_C_Door;
extern vu16 TEMP_OFFSET;//温度补偿值
//--------------------------
extern vu8 UART_Buffer_Size;//串口接收数据长度
extern vu8 Transmit_BUFFERsize;
//---------------------------
extern vu16 NTC_value;   //AD值
extern vu16 Imon_value;
extern vu32 Imon1_value;
extern vu16 Vmon_value;
extern vu32 Vmon1_value;
extern vu16 Rmon_value;

extern float DISS_Voltage;
extern  float DISS_POW_Voltage;
extern float DISS_Current;
extern float DISS_POW_Current;
extern float DISS_R;
extern vu16 steptime;
extern vu8 r_stable;
extern char set_limit[5];
extern vu8 bit;
extern vu8 bit1;
extern vu8 dot_flag;
extern vu8 page_sw;
extern vu8 para_set1;
extern vu8 para_set2;
extern vu8 para_set3;
extern vu8 para_set4;
extern vu8 oct_sw;
extern vu8 set_sw;
extern vu8 charge_step;
extern vu8 cutoff_flag;
extern vu8 lang;
extern vu8 r_raly;
extern vu16 steptime;
extern vu8 alert_flag;
extern vu8 t_onoff;
extern vu8 ocstop;
extern float temp;
extern vu8 mode_sw;
extern vu16 stepcount;
extern vu16 battery_c;
extern float bc_raw;
extern vu8 track;
extern vu8 clear_flag1;
extern vu8 clear_flag2;
extern vu8 clear_flag3;
extern vu8 pass;
extern vu8 b_type;
extern vu8 buffer;
extern float clear_v;
extern float clear_pv;
extern float clear_lv;
extern float temp;
extern vu8 set_loop_count;

extern vu32 Run_Control[41];	
#define onoff_ch                    Run_Control[0]  //ON/OFF
#define SET_Voltage 	    	        Run_Control[1]  //支源狮吱支压
#define SET_Current	    	    		  Run_Control[2]  //支源狮吱支路
#define SET_Voltage_Laod 					  Run_Control[3]  //睾諛狮吱支压
#define SET_Current_Laod					  Run_Control[4]  //睾諛狮吱支路
#define LOCK_KEY								    Run_Control[5]  //
#define BEEP_KEY								    Run_Control[6]  //
#define STRONG_KEY							    Run_Control[7]  //

#define MODE_Woke							   	  Run_Control[8]  //
#define POW_Voltage	    	            Run_Control[9]  //支源英支压
#define Voltage	    	                Run_Control[10]  //睾諛英支压
#define Current	    	    		    Run_Control[11]  //支源英支路
#define Laod_Current	    		    Run_Control[12]  //睾諛英支路
#define R_VLUE							Run_Control[13]  //艢亘值
#define set_max_v						Run_Control[14]  //璁剧疆娴嬮噺鐢靛帇涓婇檺
#define set_min_v						Run_Control[15]  //璁剧疆娴嬮噺鐢靛帇涓嬮檺
#define set_max_r						Run_Control[16]  //璁剧疆娴嬮噺鍐呴樆涓婇檺
#define set_min_r						Run_Control[17]  //璁剧疆娴嬮噺鍐呴樆涓嬮檺
#define set_max_c						Run_Control[18]  //璁剧疆娴嬮噺鐢垫祦涓婇檺
#define set_min_c						Run_Control[19]  //璁剧疆娴嬮噺鐢垫祦瑗跨嚎
#define set_output_v					Run_Control[20]  //璁剧疆娴嬮噺杈撳嚭鐢靛帇
#define set_output_c					Run_Control[21]  //璁剧疆娴嬮噺杈撳嚭鐢垫祦
#define set_init_c					    Run_Control[22]  //璁剧疆娴嬮噺杈撳嚭鐢靛帇
#define set_sbs_c					    Run_Control[23]  //璁剧疆娴嬮噺杈撳嚭鐢垫祦
#define set_add_c					    Run_Control[24]
#define set_c_cutoff_v					Run_Control[25]
#define set_c_cutoff_c					Run_Control[26]
#define set_dc_cutoff_v					Run_Control[27]
#define set_dc_cutoff_c					Run_Control[28]
#define start_time					    Run_Control[29]
#define end_time					    Run_Control[30]
#define opv1    					    Run_Control[31]
#define opv2    					    Run_Control[32]
#define opv3    					    Run_Control[33]
#define opc1    					    Run_Control[34]
#define opc2    					    Run_Control[35]
#define opc3    					    Run_Control[36]
#define load_c    					    Run_Control[37]
#define pow_v    					    Run_Control[38]
#define cdc_dc    					    Run_Control[39]
#define pow_c    					    Run_Control[40]


extern vu16 coff[6];
#define cov1    					    coff[0]
#define cov2    					    coff[1]
#define cov3    					    coff[2]
#define coc1    					    coff[3]
#define coc2    					    coff[4]
#define coc3    					    coff[5]										 //内阻值

/*
************************************************************************
*						椤甸潰璇嗗埆绗�
************************************************************************
*/

#define face_graph      0
#define face_cdc        1
#define face_menu       2
#define face_r          3
#define face_load       4
#define face_set        5
#define face_starter    6
#define face_sys_info   7
/*
************************************************************************
*						璁剧疆閫夐」璇嗗埆绗�
************************************************************************
*/

#define set_1           0
#define set_2           1
#define set_3           2
#define set_4           3
#define set_5           4
#define set_6           5
#define set_7           6
#define set_8           7
#define set_9           8
#define set_10          9
#define set_11          10
#define set_12          11
#define set_13          12
#define set_14          13
#define set_15          14
#define set_16          15
#define set_17          16
#define set_18          17
#define set_19          18
#define set_20          19
#define set_21          20
#define set_22          21
#define set_23          22
#define set_24          23
#define set_25          24
#define set_26          25
#define set_27          26
#define set_28          27
#define set_29          28
#define set_30          29
#define set_31          30
#define set_32          31
#define set_33          32
#define set_34          33
#define set_35          34
#define set_36          35
#define set_37          36
#define set_38          37
#define set_39          38
#define set_40          39
#define set_41          40
#define set_42          41
#define set_43          42
#define set_44          43
#define set_45          44
#define set_46          45
#define set_47          46
#define set_48          47
#define set_49          48
#define set_50          49
#define set_51          50
#define set_52          51
#define set_53          52
#define set_54          53
#define set_55          54
#define set_56          55
#define set_57          56
#define set_58          57
#define set_59          58
#define set_60          59
#define set_61          60
#define set_62          61
#define set_63          62
#define set_64          63
#define set_65          64
#define set_66          65
#define set_67          66
#define set_68          67
#define set_69          68
#define set_70          69
#define set_71          70
/*
************************************************************************
*						鍙傛暟璁剧疆璇嗗埆绗�
************************************************************************
*/

#define set_1_on            0xff
#define set_1_off           0
#define set_2_on            0xff
#define set_2_off           0
#define set_3_on            1
#define set_3_off           0
#define set_4_on            0xff
#define set_4_off           0
#define cdc_on              1
#define cdc_off             0
#define oct_on              1
#define oct_off             0
#define c_on                1
#define c_off               0
#define mode_r              1
#define mode_load           2
#define mode_pow            3
#define load_on             1
#define load_off            0
#define pow_on              1
#define pow_off             0
#define Lion                1
#define NiMH                2
#define NiCd                3
#define SLA                 4
#define LiMH                5
#define step1               0
#define step2               1
#define step3               2



extern vu16 Contr_Voltage;//
extern vu16 Contr_Current;//
extern vu16 Contr_Laod;//
extern vu32 Correct_Parametet[12];
#define  REG_CorrectionV   Correct_Parametet[0]//内阻电压测量参数
#define  REG_Load_A			   Correct_Parametet[1]//负载CC模式电流测量参数
#define  SET_LoadA			   Correct_Parametet[2]//负载CC模式控制电流参数
#define  REG_LoadV			   Correct_Parametet[3]//负载CV模式控制电压参数
#define  SET_LoadV			   Correct_Parametet[4]//负载CV模式控制电压控制参数

#define  REG_CorrectionR   Correct_Parametet[5]//内阻测量参数

#define  REG_POWERA			   Correct_Parametet[6]//电源CC模式电流测量参数
#define  SET_POWERA			   Correct_Parametet[7]//电源CC模式电流控制测量参数
#define  REG_POWERV			   Correct_Parametet[8]//电源CV模式电压测量参数
#define  SET_POWERV				 Correct_Parametet[9]//电源CV模式电压控制参数
#define  CON_POWERA				 Correct_Parametet[10]//电源CV模式电流测量参数
#define  REG_CorrectionRL    Correct_Parametet[11]//内阻测量参数



extern vu8  correct_por[6];
#define  Polar             correct_por[0]//内阻电压测量参数
#define  Polar1            correct_por[1]//负载电流测量和控制
#define  Polar2						 correct_por[2]//负载CV模式电压测量和控制
#define  Polar3						 correct_por[3]//内阻测量和电源CV模式电流测量
#define  Polar4						 correct_por[4]//电源CC模式电流测量和控制
#define  Polar5						 correct_por[5]//电源CV模式电压测量和控制

extern vu32 Correct_Strong[12];//校准系数
#define  REG_ReadV_Offset   Correct_Strong[0]//内阻电压测量参数
#define  REG_LoadA_Offset   Correct_Strong[1]//负载CC模式电流测量参数
#define  SET_LoadA_Offset   Correct_Strong[2]//负载CC模式控制电流参数
#define  REG_LoadV_Offset   Correct_Strong[3]//负载CV模式控制电压参数
#define  SET_LoadV_Offset   Correct_Strong[4]//负载CV模式控制电压控制参数

#define  REG_ReadR_Offset   Correct_Strong[5]//内阻测量参数

#define  REG_POWERA_Offset  Correct_Strong[6]//电源CC模式电流测量参数
#define  SET_POWERA_Offset  Correct_Strong[7]//电源CC模式电流控制测量参数
#define  REG_POWERV_Offset  Correct_Strong[8]//电源CV模式电压测量参数
#define  SET_POWERV_Offset	Correct_Strong[9]//电源CV模式电压控制参数
#define  CON_POWERA_Offset	Correct_Strong[10]//电源CV模式电流测量参数
#define  REG_ReadRL_Offset   Correct_Strong[11]//内阻测量参数

//---------------------------
extern vu16 ADC_NTC_Filt[50];
extern vu16 ADC_Vmon_Filt[50];
extern vu16 ADC_Imon_Filt[50];
extern vu8 UART_Buffer_Rece[16];
extern vu8 UART_Buffer_Send[20];
//============================================================================= 
#define Receive_BUFFERSIZE   10
//=============================================================================
#endif
/******************* (C) COPYRIGHT 2015 KUNKIN *****END OF FILE*************************/


