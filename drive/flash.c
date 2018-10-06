/******************** (C) COPYRIGHT 2014 KUNKIN********************
 * �ļ���  ��FLASH.C
 * ����    ������
 * ����    ��STM8L151K4T6 FLASHӦ�ú���
 * ����    ��
 * Ӳ�����ӣ�
 * �޸����ڣ�2014-12-22
********************************************************************/
#include "my_register.h" //NOPָ������
#include "AT24C01.h"

extern vu8 b_type;
extern vu8 buffer;
extern vu16 year1;
extern vu16 year2;
extern vu16 year3;
extern vu16 year4;
extern vu8 month1;
extern vu8 month2;
extern vu8 day1;
extern vu8 day2;
extern vu8 code1;
extern vu8 code2;
extern vu8 code3;
extern vu8 code4;
extern vu8 code5;
extern vu8 code6;
extern vu8 code7;
extern vu8 code8;


//================================================================//
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
} flagA, flagB,flagC,flagD;
//==================================================================//
void Flash_Write_all (void)
{
	vu8 data_8bit;
/***********************�������ݴ洢****************************/
  data_8bit = REG_CorrectionV >> 24;
	EEPROM_WriteByte(0x01, data_8bit);
	data_8bit = REG_CorrectionV >> 16;
	EEPROM_WriteByte(0x02, data_8bit);
	data_8bit = REG_CorrectionV >> 8;
	EEPROM_WriteByte(0x03, data_8bit);
	EEPROM_WriteByte(0x04, REG_CorrectionV);//������ѹ
	
	data_8bit = REG_ReadV_Offset >> 24;
	EEPROM_WriteByte(0x05, data_8bit);
	data_8bit = REG_ReadV_Offset >> 16;
	EEPROM_WriteByte(0x06, data_8bit);
	data_8bit = REG_ReadV_Offset >> 8;
	EEPROM_WriteByte(0x07, data_8bit);
	EEPROM_WriteByte(0x08, REG_ReadV_Offset);//������ѹ
	
	data_8bit = REG_Load_A >> 24;
	EEPROM_WriteByte(0x09, data_8bit);
	data_8bit = REG_Load_A >> 16;
	EEPROM_WriteByte(0x0A, data_8bit);
	data_8bit = REG_Load_A >> 8;
	EEPROM_WriteByte(0x0B, data_8bit);
	EEPROM_WriteByte(0x0C, REG_Load_A);//���ص���
	
	data_8bit = REG_LoadA_Offset >> 24;
	EEPROM_WriteByte(0x0D, data_8bit);
	data_8bit = REG_LoadA_Offset >> 16;
	EEPROM_WriteByte(0x0E, data_8bit);
	data_8bit = REG_LoadA_Offset >> 8;
	EEPROM_WriteByte(0x0F, data_8bit);
	EEPROM_WriteByte(0x10, REG_LoadA_Offset);//���ص���
	
	data_8bit = SET_LoadA >> 24;
	EEPROM_WriteByte(0x11, data_8bit);
	data_8bit = SET_LoadA >> 16;
	EEPROM_WriteByte(0x12, data_8bit);
	data_8bit = SET_LoadA >> 8;
	EEPROM_WriteByte(0x13, data_8bit);
	EEPROM_WriteByte(0x14, SET_LoadA);//�����趨����
	
	data_8bit = SET_LoadA_Offset >> 24;
	EEPROM_WriteByte(0x15, data_8bit);
	data_8bit = SET_LoadA_Offset >> 16;
	EEPROM_WriteByte(0x16, data_8bit);
	data_8bit = SET_LoadA_Offset >> 8;
	EEPROM_WriteByte(0x17, data_8bit);
	EEPROM_WriteByte(0x18, SET_LoadA_Offset);//�����趨����
	
	data_8bit = REG_LoadV >> 24;
	EEPROM_WriteByte(0x19, data_8bit);
	data_8bit = REG_LoadV >> 16;
	EEPROM_WriteByte(0x1A, data_8bit);
	data_8bit = REG_LoadV >> 8;
	EEPROM_WriteByte(0x1B, data_8bit);
	EEPROM_WriteByte(0x1C, REG_LoadV);//���ز�����ѹ
	
	data_8bit = REG_LoadV_Offset >> 24;
	EEPROM_WriteByte(0x1D, data_8bit);
	data_8bit = REG_LoadV_Offset >> 16;
	EEPROM_WriteByte(0x1E, data_8bit);
	data_8bit = REG_LoadV_Offset >> 8;
	EEPROM_WriteByte(0x1F, data_8bit);
	EEPROM_WriteByte(0x20, REG_LoadV_Offset);//���ز�����ѹ
	
	data_8bit = SET_LoadV >> 24;
	EEPROM_WriteByte(0x21, data_8bit);
	data_8bit = SET_LoadV >> 16;
	EEPROM_WriteByte(0x22, data_8bit);
	data_8bit = SET_LoadV >> 8;
	EEPROM_WriteByte(0x23, data_8bit);
	EEPROM_WriteByte(0x24, SET_LoadV);//�����趨��ѹ
	
	data_8bit = SET_LoadV_Offset >> 24;
	EEPROM_WriteByte(0x25, data_8bit);
	data_8bit = SET_LoadV_Offset >> 16;
	EEPROM_WriteByte(0x26, data_8bit);
	data_8bit = SET_LoadV_Offset >> 8;
	EEPROM_WriteByte(0x27, data_8bit);
	EEPROM_WriteByte(0x28, SET_LoadV_Offset);//�����趨��ѹ
	
	
	data_8bit = REG_CorrectionR >> 24;
	EEPROM_WriteByte(0x29, data_8bit);
	data_8bit = REG_CorrectionR >> 16;
	EEPROM_WriteByte(0x2A, data_8bit);
	data_8bit = REG_CorrectionR >> 8;
	EEPROM_WriteByte(0x2B, data_8bit);
	EEPROM_WriteByte(0x2C, REG_CorrectionR);//����
	
	data_8bit = REG_ReadR_Offset >> 24;
	EEPROM_WriteByte(0x2D, data_8bit);
	data_8bit = REG_ReadR_Offset >> 16;
	EEPROM_WriteByte(0x2E, data_8bit);
	data_8bit = REG_ReadR_Offset >> 8;
	EEPROM_WriteByte(0x2F, data_8bit);
	EEPROM_WriteByte(0x30, REG_ReadR_Offset);//����
	
/************��ѹ��Դ*****************************/
	data_8bit = REG_POWERA >> 24;
	EEPROM_WriteByte(0x31, data_8bit);
	data_8bit = REG_POWERA >> 16;
	EEPROM_WriteByte(0x32, data_8bit);
	data_8bit = REG_POWERA >> 8;
	EEPROM_WriteByte(0x33, data_8bit);
	EEPROM_WriteByte(0x34, REG_POWERA);//��ԴCCģʽ��������
	
	data_8bit = REG_POWERA_Offset >> 24;
	EEPROM_WriteByte(0x35, data_8bit);
	data_8bit = REG_POWERA_Offset >> 16;
	EEPROM_WriteByte(0x36, data_8bit);
	data_8bit = REG_POWERA_Offset >> 8;
	EEPROM_WriteByte(0x37, data_8bit);
	EEPROM_WriteByte(0x38, REG_POWERA_Offset);//��ԴCCģʽ��������
	
	data_8bit = SET_POWERA >> 24;
	EEPROM_WriteByte(0x39, data_8bit);
	data_8bit = SET_POWERA >> 16;
	EEPROM_WriteByte(0x3A, data_8bit);
	data_8bit = SET_POWERA >> 8;
	EEPROM_WriteByte(0x3B, data_8bit);
	EEPROM_WriteByte(0x3C, SET_POWERA);//��ԴCCģʽ�趨����
	
	
	data_8bit = SET_POWERA_Offset >> 24;
	EEPROM_WriteByte(0x3D, data_8bit);
	data_8bit = SET_POWERA_Offset >> 16;
	EEPROM_WriteByte(0x3E, data_8bit);
	data_8bit = SET_POWERA_Offset >> 8;
	EEPROM_WriteByte(0x3F, data_8bit);
	EEPROM_WriteByte(0x40, SET_POWERA_Offset);//��ԴCCģʽ�趨����
	
	
	data_8bit = REG_POWERV >> 24;
	EEPROM_WriteByte(0x41, data_8bit);
	data_8bit = REG_POWERV >> 16;
	EEPROM_WriteByte(0x42, data_8bit);
	data_8bit = REG_POWERV >> 8;
	EEPROM_WriteByte(0x43, data_8bit);
	EEPROM_WriteByte(0x44, REG_POWERV);//��Դ��ѹ����
	
	
	data_8bit = REG_POWERV_Offset >> 24;
	EEPROM_WriteByte(0x45, data_8bit);
	data_8bit = REG_POWERV_Offset >> 16;
	EEPROM_WriteByte(0x46, data_8bit);
	data_8bit = REG_POWERV_Offset >> 8;
	EEPROM_WriteByte(0x47, data_8bit);
	EEPROM_WriteByte(0x48, REG_POWERV_Offset);//��Դ��ѹ����
	
	data_8bit = SET_POWERV >> 24;
	EEPROM_WriteByte(0x49, data_8bit);
	data_8bit = SET_POWERV >> 16;
	EEPROM_WriteByte(0x4A, data_8bit);
	data_8bit = SET_POWERV >> 8;
	EEPROM_WriteByte(0x4B, data_8bit);
	EEPROM_WriteByte(0x4C, SET_POWERV);//��Դ��ѹ����
	
	data_8bit = SET_POWERV_Offset >> 24;
	EEPROM_WriteByte(0x4D, data_8bit);
	data_8bit = SET_POWERV_Offset >> 16;
	EEPROM_WriteByte(0x4E, data_8bit);
	data_8bit = SET_POWERV_Offset >> 8;
	EEPROM_WriteByte(0x4F, data_8bit);
	EEPROM_WriteByte(0x50, SET_POWERV_Offset);//��Դ��ѹ����
	
	data_8bit = CON_POWERA >> 24;
	EEPROM_WriteByte(0x51, data_8bit);
	data_8bit = CON_POWERA >> 16;
	EEPROM_WriteByte(0x52, data_8bit);
	data_8bit = CON_POWERA >> 8;
	EEPROM_WriteByte(0x53, data_8bit);
	EEPROM_WriteByte(0x54, CON_POWERA);//��ԴCV��������
	
	data_8bit = CON_POWERA_Offset >> 24;
	EEPROM_WriteByte(0x55, data_8bit);
	data_8bit = CON_POWERA_Offset >> 16;
	EEPROM_WriteByte(0x56, data_8bit);
	data_8bit = CON_POWERA_Offset >> 8;
	EEPROM_WriteByte(0x57, data_8bit);
	EEPROM_WriteByte(0x58, CON_POWERA_Offset);//��ԴCV��������
	
	
	EEPROM_WriteByte(0x59,Polar);
	EEPROM_WriteByte(0x5A,Polar1);//
	EEPROM_WriteByte(0x5B,Polar2);
	EEPROM_WriteByte(0x5C,Polar3);//
	EEPROM_WriteByte(0x5D,Polar4);
	EEPROM_WriteByte(0x5E,Polar5);
}
//===========================================================================//
void EEPROM_READ_Coeff(void)
{
/****************���Ӹ���*********************/
	REG_CorrectionV=EEPROM_READ_Byte(0x01);
	REG_CorrectionV=EEPROM_READ_Byte(0x01);
	REG_CorrectionV=REG_CorrectionV<<8;
	REG_CorrectionV=REG_CorrectionV+EEPROM_READ_Byte(0x02);
	REG_CorrectionV=REG_CorrectionV<<8;
	REG_CorrectionV=REG_CorrectionV+EEPROM_READ_Byte(0x03);
	REG_CorrectionV=REG_CorrectionV<<8;
	REG_CorrectionV=REG_CorrectionV+EEPROM_READ_Byte(0x04);
	
	REG_ReadV_Offset=EEPROM_READ_Byte(0x05);
	REG_ReadV_Offset=REG_ReadV_Offset<<8;
	REG_ReadV_Offset=REG_ReadV_Offset+EEPROM_READ_Byte(0x06);
	REG_ReadV_Offset=REG_ReadV_Offset<<8;
	REG_ReadV_Offset=REG_ReadV_Offset+EEPROM_READ_Byte(0x07);
	REG_ReadV_Offset=REG_ReadV_Offset<<8;
	REG_ReadV_Offset=REG_ReadV_Offset+EEPROM_READ_Byte(0x08);
	
	REG_Load_A=EEPROM_READ_Byte(0x09);
	REG_Load_A=REG_Load_A<<8;
	REG_Load_A=REG_Load_A+EEPROM_READ_Byte(0x0A);
	REG_Load_A=REG_Load_A<<8;
	REG_Load_A=REG_Load_A+EEPROM_READ_Byte(0x0B);
	REG_Load_A=REG_Load_A<<8;
	REG_Load_A=REG_Load_A+EEPROM_READ_Byte(0x0C);
	
	REG_LoadA_Offset=EEPROM_READ_Byte(0x0D);
	REG_LoadA_Offset=REG_LoadA_Offset<<8;
	REG_LoadA_Offset=REG_LoadA_Offset+EEPROM_READ_Byte(0x0E);
	REG_LoadA_Offset=REG_LoadA_Offset<<8;
	REG_LoadA_Offset=REG_LoadA_Offset+EEPROM_READ_Byte(0x0F);
	REG_LoadA_Offset=REG_LoadA_Offset<<8;
	REG_LoadA_Offset=REG_LoadA_Offset+EEPROM_READ_Byte(0x10);
	
	SET_LoadA=EEPROM_READ_Byte(0x11);
	SET_LoadA=SET_LoadA<<8;
	SET_LoadA=SET_LoadA+EEPROM_READ_Byte(0x12);
	SET_LoadA=SET_LoadA<<8;
	SET_LoadA=SET_LoadA+EEPROM_READ_Byte(0x13);
	SET_LoadA=SET_LoadA<<8;
	SET_LoadA=SET_LoadA+EEPROM_READ_Byte(0x14);
	
	SET_LoadA_Offset=EEPROM_READ_Byte(0x15);
	SET_LoadA_Offset=SET_LoadA_Offset<<8;
	SET_LoadA_Offset=SET_LoadA_Offset+EEPROM_READ_Byte(0x16);
	SET_LoadA_Offset=SET_LoadA_Offset<<8;
	SET_LoadA_Offset=SET_LoadA_Offset+EEPROM_READ_Byte(0x17);
	SET_LoadA_Offset=SET_LoadA_Offset<<8;
	SET_LoadA_Offset=SET_LoadA_Offset+EEPROM_READ_Byte(0x18);//
	
	
	REG_LoadV=EEPROM_READ_Byte(0x19);
	REG_LoadV=REG_LoadV<<8;
	REG_LoadV=REG_LoadV+EEPROM_READ_Byte(0x1A);
	REG_LoadV=REG_LoadV<<8;
	REG_LoadV=REG_LoadV+EEPROM_READ_Byte(0x1B);
	REG_LoadV=REG_LoadV<<8;
	REG_LoadV=REG_LoadV+EEPROM_READ_Byte(0x1C);
	
	REG_LoadV_Offset=EEPROM_READ_Byte(0x1D);
	REG_LoadV_Offset=REG_LoadV_Offset<<8;
	REG_LoadV_Offset=REG_LoadV_Offset+EEPROM_READ_Byte(0x1E);
	REG_LoadV_Offset=REG_LoadV_Offset<<8;
	REG_LoadV_Offset=REG_LoadV_Offset+EEPROM_READ_Byte(0x1F);
	REG_LoadV_Offset=REG_LoadV_Offset<<8;
	REG_LoadV_Offset=REG_LoadV_Offset+EEPROM_READ_Byte(0x20);//
	
	SET_LoadV=EEPROM_READ_Byte(0x21);
	SET_LoadV=SET_LoadV<<8;
	SET_LoadV=SET_LoadV+EEPROM_READ_Byte(0x22);
	SET_LoadV=SET_LoadV<<8;
	SET_LoadV=SET_LoadV+EEPROM_READ_Byte(0x23);
	SET_LoadV=SET_LoadV<<8;
	SET_LoadV=SET_LoadV+EEPROM_READ_Byte(0x24);
	
	SET_LoadV_Offset=EEPROM_READ_Byte(0x25);
	SET_LoadV_Offset=SET_LoadV_Offset<<8;
	SET_LoadV_Offset=SET_LoadV_Offset+EEPROM_READ_Byte(0x26);
	SET_LoadV_Offset=SET_LoadV_Offset<<8;
	SET_LoadV_Offset=SET_LoadV_Offset+EEPROM_READ_Byte(0x27);
	SET_LoadV_Offset=SET_LoadV_Offset<<8;
	SET_LoadV_Offset=SET_LoadV_Offset+EEPROM_READ_Byte(0x28);
	/*****************����********************************/
	REG_CorrectionR=EEPROM_READ_Byte(0x29);
	REG_CorrectionR=REG_CorrectionR<<8;
	REG_CorrectionR=REG_CorrectionR+EEPROM_READ_Byte(0x2A);
	REG_CorrectionR=REG_CorrectionR<<8;
	REG_CorrectionR=REG_CorrectionR+EEPROM_READ_Byte(0x2B);
	REG_CorrectionR=REG_CorrectionR<<8;
	REG_CorrectionR=REG_CorrectionR+EEPROM_READ_Byte(0x2C);
	
	REG_ReadR_Offset=EEPROM_READ_Byte(0x2D);
	REG_ReadR_Offset=REG_ReadR_Offset<<8;
	REG_ReadR_Offset=REG_ReadR_Offset+EEPROM_READ_Byte(0x2E);
	REG_ReadR_Offset=REG_ReadR_Offset<<8;
	REG_ReadR_Offset=REG_ReadR_Offset+EEPROM_READ_Byte(0x2F);
	REG_ReadR_Offset=REG_ReadR_Offset<<8;
	REG_ReadR_Offset=REG_ReadR_Offset+EEPROM_READ_Byte(0x30);
	
	
/*******************��ѹ��Դ****************************/
	REG_POWERA=EEPROM_READ_Byte(0x31);
	REG_POWERA=REG_POWERA<<8;
	REG_POWERA=REG_POWERA+EEPROM_READ_Byte(0x32);
	REG_POWERA=REG_POWERA<<8;
	REG_POWERA=REG_POWERA+EEPROM_READ_Byte(0x33);
	REG_POWERA=REG_POWERA<<8;
	REG_POWERA=REG_POWERA+EEPROM_READ_Byte(0x34);
	
	REG_POWERA_Offset=EEPROM_READ_Byte(0x35);
	REG_POWERA_Offset=REG_POWERA_Offset<<8;
	REG_POWERA_Offset=REG_POWERA_Offset+EEPROM_READ_Byte(0x36);
	REG_POWERA_Offset=REG_POWERA_Offset<<8;
	REG_POWERA_Offset=REG_POWERA_Offset+EEPROM_READ_Byte(0x37);
	REG_POWERA_Offset=REG_POWERA_Offset<<8;
	REG_POWERA_Offset=REG_POWERA_Offset+EEPROM_READ_Byte(0x38);//
	
	SET_POWERA=EEPROM_READ_Byte(0x39);
	SET_POWERA=SET_POWERA<<8;
	SET_POWERA=SET_POWERA+EEPROM_READ_Byte(0x3A);
	SET_POWERA=SET_POWERA<<8;
	SET_POWERA=SET_POWERA+EEPROM_READ_Byte(0x3B);
	SET_POWERA=SET_POWERA<<8;
	SET_POWERA=SET_POWERA+EEPROM_READ_Byte(0x3C);

	SET_POWERA_Offset=EEPROM_READ_Byte(0x3D);
	SET_POWERA_Offset=SET_POWERA_Offset<<8;
	SET_POWERA_Offset=SET_POWERA_Offset+EEPROM_READ_Byte(0x3E);
	SET_POWERA_Offset=SET_POWERA_Offset<<8;
	SET_POWERA_Offset=SET_POWERA_Offset+EEPROM_READ_Byte(0x3F);
	SET_POWERA_Offset=SET_POWERA_Offset<<8;
	SET_POWERA_Offset=SET_POWERA_Offset+EEPROM_READ_Byte(0x40);//
	
	
	REG_POWERV=EEPROM_READ_Byte(0x41);
	REG_POWERV=REG_POWERV<<8;
	REG_POWERV=REG_POWERV+EEPROM_READ_Byte(0x42);
	REG_POWERV=REG_POWERV<<8;
	REG_POWERV=REG_POWERV+EEPROM_READ_Byte(0x43);
	REG_POWERV=REG_POWERV<<8;
	REG_POWERV=REG_POWERV+EEPROM_READ_Byte(0x44);

	REG_POWERV_Offset=EEPROM_READ_Byte(0x45);
	REG_POWERV_Offset=REG_POWERV_Offset<<8;
	REG_POWERV_Offset=REG_POWERV_Offset+EEPROM_READ_Byte(0x46);
	REG_POWERV_Offset=REG_POWERV_Offset<<8;
	REG_POWERV_Offset=REG_POWERV_Offset+EEPROM_READ_Byte(0x47);
	REG_POWERV_Offset=REG_POWERV_Offset<<8;
	REG_POWERV_Offset=REG_POWERV_Offset+EEPROM_READ_Byte(0x48);//
	
	
	SET_POWERV=EEPROM_READ_Byte(0x49);
	SET_POWERV=SET_POWERV<<8;
	SET_POWERV=SET_POWERV+EEPROM_READ_Byte(0x4A);
	SET_POWERV=SET_POWERV<<8;
	SET_POWERV=SET_POWERV+EEPROM_READ_Byte(0x4B);
	SET_POWERV=SET_POWERV<<8;
	SET_POWERV=SET_POWERV+EEPROM_READ_Byte(0x4C);

	SET_POWERV_Offset=EEPROM_READ_Byte(0x4D);
	SET_POWERV_Offset=SET_POWERV_Offset<<8;
	SET_POWERV_Offset=SET_POWERV_Offset+EEPROM_READ_Byte(0x4E);
	SET_POWERV_Offset=SET_POWERV_Offset<<8;
	SET_POWERV_Offset=SET_POWERV_Offset+EEPROM_READ_Byte(0x4F);
	SET_POWERV_Offset=SET_POWERV_Offset<<8;
	SET_POWERV_Offset=SET_POWERV_Offset+EEPROM_READ_Byte(0x50);//
	
	CON_POWERA=EEPROM_READ_Byte(0x51);
	CON_POWERA=CON_POWERA<<8;
	CON_POWERA=CON_POWERA+EEPROM_READ_Byte(0x52);
	CON_POWERA=CON_POWERA<<8;
	CON_POWERA=CON_POWERA+EEPROM_READ_Byte(0x53);
	CON_POWERA=CON_POWERA<<8;
	CON_POWERA=CON_POWERA+EEPROM_READ_Byte(0x54);

	CON_POWERA_Offset=EEPROM_READ_Byte(0x55);
	CON_POWERA_Offset=CON_POWERA_Offset<<8;
	CON_POWERA_Offset=CON_POWERA_Offset+EEPROM_READ_Byte(0x56);
	CON_POWERA_Offset=CON_POWERA_Offset<<8;
	CON_POWERA_Offset=CON_POWERA_Offset+EEPROM_READ_Byte(0x57);
	CON_POWERA_Offset=CON_POWERA_Offset<<8;
	CON_POWERA_Offset=CON_POWERA_Offset+EEPROM_READ_Byte(0x58);
	
	Polar=EEPROM_READ_Byte(0x59);
	Polar1=EEPROM_READ_Byte(0x5A);
	Polar2=EEPROM_READ_Byte(0x5B);
	Polar3=EEPROM_READ_Byte(0x5C);
	Polar4=EEPROM_READ_Byte(0x5D);
	Polar5=EEPROM_READ_Byte(0x5E);
    
    t_beep=EEPROM_READ_Byte(0x60);
    para_set4 = EEPROM_READ_Byte(0x7A);
    para_set2 = EEPROM_READ_Byte(0x7B);
    b_type = EEPROM_READ_Byte(0x78);
    buffer = EEPROM_READ_Byte(0x79);
    para_set1 = EEPROM_READ_Byte(0x61);
    year1 = EEPROM_READ_Byte(0x7C);
    year2 = EEPROM_READ_Byte(0x7D);
    year3 = EEPROM_READ_Byte(0x7E);
    year4 = EEPROM_READ_Byte(0x7F);
    month1 = EEPROM_READ_Byte(0x80);
    month2 = EEPROM_READ_Byte(0x81);
    day1 = EEPROM_READ_Byte(0x82);
    day2 = EEPROM_READ_Byte(0x83);
    code1 = EEPROM_READ_Byte(0x84);
    code2 = EEPROM_READ_Byte(0x85);
    code3 = EEPROM_READ_Byte(0x86);
    code4 = EEPROM_READ_Byte(0x87);
    code5 = EEPROM_READ_Byte(0x88);
    code6 = EEPROM_READ_Byte(0x89);
    code7 = EEPROM_READ_Byte(0x8A);
    code8 = EEPROM_READ_Byte(0x8B);
    flag_Load_CC = EEPROM_READ_Byte(0x8C);
    steptime = EEPROM_READ_Byte(0x8D);
    
    set_max_v=EEPROM_READ_Byte(0x62);
	set_max_v=set_max_v<<8;
	set_max_v=set_max_v+EEPROM_READ_Byte(0x63);
	
	set_min_v=EEPROM_READ_Byte(0x64);
	set_min_v=set_min_v<<8;
	set_min_v=set_min_v+EEPROM_READ_Byte(0x65);
    
	set_max_r=EEPROM_READ_Byte(0x66);
	set_max_r=set_max_r<<8;
	set_max_r=set_max_r+EEPROM_READ_Byte(0x67);
	
	set_min_r=EEPROM_READ_Byte(0x68);
	set_min_r=set_min_r<<8;
	set_min_r=set_min_r+EEPROM_READ_Byte(0x69);

    set_max_c=EEPROM_READ_Byte(0x6A);
	set_max_c=set_max_c<<8;
	set_max_c=set_max_c+EEPROM_READ_Byte(0x6B);
	
	set_min_c=EEPROM_READ_Byte(0x6C);
	set_min_c=set_min_c<<8;
	set_min_c=set_min_c+EEPROM_READ_Byte(0x6D);
    
    pow_v=EEPROM_READ_Byte(0x6E);
	pow_v=pow_v<<8;
	pow_v=pow_v+EEPROM_READ_Byte(0x6F);
	
	pow_c=EEPROM_READ_Byte(0x70);
	pow_c=pow_c<<8;
	pow_c=pow_c+EEPROM_READ_Byte(0x71);

    load_c=EEPROM_READ_Byte(0x72);
	load_c=load_c<<8;
	load_c=load_c+EEPROM_READ_Byte(0x73); 
    
    set_init_c=EEPROM_READ_Byte(0x74);
	set_init_c=set_init_c<<8;
	set_init_c=set_init_c+EEPROM_READ_Byte(0x75);
    
    set_sbs_c=EEPROM_READ_Byte(0x76);
	set_sbs_c=set_sbs_c<<8;
	set_sbs_c=set_sbs_c+EEPROM_READ_Byte(0x77);
    
    
    
    opv1=EEPROM_READ_Byte(0x8E);
	opv1=opv1<<8;
	opv1=opv1+EEPROM_READ_Byte(0x8F);
    
    opv2=EEPROM_READ_Byte(0x90);
	opv2=opv2<<8;
	opv2=opv2+EEPROM_READ_Byte(0x91);
    
    opv3=EEPROM_READ_Byte(0x92);
	opv3=opv3<<8;
	opv3=opv3+EEPROM_READ_Byte(0x93);
    
    cov1=EEPROM_READ_Byte(0x94);
	cov1=cov1<<8;
	cov1=cov1+EEPROM_READ_Byte(0x95);
    
    cov2=EEPROM_READ_Byte(0x96);
	cov2=cov2<<8;
	cov2=cov2+EEPROM_READ_Byte(0x97);
    
    cov3=EEPROM_READ_Byte(0x98);
	cov3=cov3<<8;
	cov3=cov3+EEPROM_READ_Byte(0x99);
    
    opc1=EEPROM_READ_Byte(0x9A);
	opc1=opc1<<8;
	opc1=opc1+EEPROM_READ_Byte(0x9B);
    
    opc2=EEPROM_READ_Byte(0x9C);
	opc2=opc2<<8;
	opc2=opc2+EEPROM_READ_Byte(0x9D);
    
    opc3=EEPROM_READ_Byte(0x9E);
	opc3=opc3<<8;
	opc3=opc3+EEPROM_READ_Byte(0x9F);
    
    coc1=EEPROM_READ_Byte(0xA0);
	coc1=coc1<<8;
	coc1=coc1+EEPROM_READ_Byte(0xA1);
    
    coc2=EEPROM_READ_Byte(0xA2);
	coc2=coc2<<8;
	coc2=coc2+EEPROM_READ_Byte(0xA3);
    
    coc3=EEPROM_READ_Byte(0xA4);
	coc3=coc3<<8;
	coc3=coc3+EEPROM_READ_Byte(0xA5);
    
    set_loop_count=EEPROM_READ_Byte(0xA6);
    
    cdc_dc=EEPROM_READ_Byte(0xA7);
	cdc_dc=cdc_dc<<8;
	cdc_dc=cdc_dc+EEPROM_READ_Byte(0xA8);
    
    set_dc_cutoff_v=EEPROM_READ_Byte(0xA9);
	set_dc_cutoff_v=set_dc_cutoff_v<<8;
	set_dc_cutoff_v=set_dc_cutoff_v+EEPROM_READ_Byte(0xAA);
}
void Wrtite_Beep(void)//ѣզBEEP״ׁ̬FLASHא
{
	EEPROM_WriteByte(0x5F, Beep_Flag);
	EEPROM_WriteByte(0x60, t_beep);
}
/*****************************************************************************/
void Wrtite_S(void)//ѣզBEEP״ׁ̬FLASHא
{
	EEPROM_WriteByte(0x61, para_set1);
}

/******************************************************************************/
void Wrtite_step(void)
{
	EEPROM_WriteByte(0x8D, steptime);
}


void Write_Limits(void)
{
    vu8 data_8bit;
    
	data_8bit = set_max_v >> 8;
	EEPROM_WriteByte(0x62, data_8bit);
	EEPROM_WriteByte(0x63, set_max_v);
	
	data_8bit = set_min_v >> 8;
	EEPROM_WriteByte(0x64, data_8bit);
	EEPROM_WriteByte(0x65, set_min_v);
    
    data_8bit = set_max_r >> 8;
	EEPROM_WriteByte(0x66, data_8bit);
	EEPROM_WriteByte(0x67, set_max_r);
	
	data_8bit = set_min_r >> 8;
	EEPROM_WriteByte(0x68, data_8bit);
	EEPROM_WriteByte(0x69, set_min_r);
    
    data_8bit = set_max_c >> 8;
	EEPROM_WriteByte(0x6A, data_8bit);
	EEPROM_WriteByte(0x6B, set_max_c);
	
	data_8bit = set_min_c >> 8;
	EEPROM_WriteByte(0x6C, data_8bit);
	EEPROM_WriteByte(0x6D, set_min_c);
    
	data_8bit = pow_v >> 8;
	EEPROM_WriteByte(0x6E, data_8bit);
	EEPROM_WriteByte(0x6F, pow_v);
	
	data_8bit = pow_c >> 8;
	EEPROM_WriteByte(0x70, data_8bit);
	EEPROM_WriteByte(0x71, pow_c);
    
    data_8bit = load_c >> 8;
	EEPROM_WriteByte(0x72, data_8bit);
	EEPROM_WriteByte(0x73, load_c);
    
    data_8bit = set_init_c >> 8;
	EEPROM_WriteByte(0x74, data_8bit);
	EEPROM_WriteByte(0x75, set_init_c);
    
    data_8bit = set_sbs_c >> 8;
	EEPROM_WriteByte(0x76, data_8bit);
	EEPROM_WriteByte(0x77, set_sbs_c);



    data_8bit = opv1 >> 8;
	EEPROM_WriteByte(0x8E, data_8bit);
	EEPROM_WriteByte(0x8F, opv1);
    
    data_8bit = opv2 >> 8;
	EEPROM_WriteByte(0x90, data_8bit);
	EEPROM_WriteByte(0x91, opv2);
    
    data_8bit = opv3 >> 8;
	EEPROM_WriteByte(0x92, data_8bit);
	EEPROM_WriteByte(0x93, opv3);
    
    data_8bit = cov1 >> 8;
	EEPROM_WriteByte(0x94, data_8bit);
	EEPROM_WriteByte(0x95, cov1);
    
    data_8bit = cov2 >> 8;
	EEPROM_WriteByte(0x96, data_8bit);
	EEPROM_WriteByte(0x97, cov2);
    
    data_8bit = cov3 >> 8;
	EEPROM_WriteByte(0x98, data_8bit);
	EEPROM_WriteByte(0x99, cov3);
    
    data_8bit = opc1 >> 8;
	EEPROM_WriteByte(0x9A, data_8bit);
	EEPROM_WriteByte(0x9B, opc1);
    
    data_8bit = opc2 >> 8;
	EEPROM_WriteByte(0x9C, data_8bit);
	EEPROM_WriteByte(0x9D, opc2);
    
    data_8bit = opc3 >> 8;
	EEPROM_WriteByte(0x9E, data_8bit);
	EEPROM_WriteByte(0x9F, opc3);
    
    data_8bit = coc1 >> 8;
	EEPROM_WriteByte(0xA0, data_8bit);
	EEPROM_WriteByte(0xA1, coc1);
    
    data_8bit = coc2 >> 8;
	EEPROM_WriteByte(0xA2, data_8bit);
	EEPROM_WriteByte(0xA3, coc2);
    
    data_8bit = coc3 >> 8;
	EEPROM_WriteByte(0xA4, data_8bit);
	EEPROM_WriteByte(0xA5, coc3);
    
	EEPROM_WriteByte(0xA6, set_loop_count);
    
    data_8bit = cdc_dc >> 8;
	EEPROM_WriteByte(0xA7, data_8bit);
	EEPROM_WriteByte(0xA8, cdc_dc);
    
    data_8bit = set_dc_cutoff_v >> 8;
	EEPROM_WriteByte(0xA9, data_8bit);
	EEPROM_WriteByte(0xAA, set_dc_cutoff_v);
}

void Write_btype(void)
{
	EEPROM_WriteByte(0x78,b_type);
    EEPROM_WriteByte(0x79,buffer);
}
/************************************************************************/
void Write_alarm(void)
{
	EEPROM_WriteByte(0x7A,para_set4);
}
/************************************************************************/
void Write_oct(void)
{
	EEPROM_WriteByte(0x7B,para_set2);
}

void Write_LOAD(void)
{
    EEPROM_WriteByte(0x8C,flag_Load_CC);
}
/************************************************************************/
void Write_info(void)
{
	EEPROM_WriteByte(0x7C,year1);
    EEPROM_WriteByte(0x7D,year2);
    EEPROM_WriteByte(0x7E,year3);
    EEPROM_WriteByte(0x7F,year4);
    EEPROM_WriteByte(0x80,month1);
    EEPROM_WriteByte(0x81,month2);
    EEPROM_WriteByte(0x82,day1);
    EEPROM_WriteByte(0x83,day2);
    EEPROM_WriteByte(0x84,code1);
    EEPROM_WriteByte(0x85,code2);
    EEPROM_WriteByte(0x86,code3);
    EEPROM_WriteByte(0x87,code4);
    EEPROM_WriteByte(0x88,code5);
    EEPROM_WriteByte(0x89,code6);
    EEPROM_WriteByte(0x8A,code7);
    EEPROM_WriteByte(0x8B,code8); 
}
/******************* (C) COPYRIGHT 2015 AVER *****END OF FILE*************************/

