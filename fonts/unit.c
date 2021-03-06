/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        emWin Font Converter (ST) version 5.32                      *
*        Compiled Oct  8 2015, 11:58:55                              *
*                                                                    *
*        (c) 1998 - 2015 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: unit.c                                                *
* Font:        ����                                                  *
* Height:      24                                                    *
*                                                                    *
**********************************************************************
*                                                                    *
* Initial font height:  24                                           *
* Range disabled:       0000 - FFFF                                  *
* Character enabled:   0x43 (67)                                     *
* Character disabled:  0x43 (67)                                     *
* Character enabled:   0x43 (67)                                     *
* Character enabled:   0xB0 (176)                                    *
* Pixel index of character 0xB0 (176) at 4/4 set to 0                *
* Pixel index of character 0xB0 (176) at 5/4 set to 1                *
* Pixel index of character 0xB0 (176) at 4/5 set to 1                *
* Pixel index of character 0xB0 (176) at 1/4 set to 0                *
* Pixel index of character 0xB0 (176) at 4/1 set to 0                *
* Pixel index of character 0xB0 (176) at 4/2 set to 1                *
* Pixel index of character 0xB0 (176) at 4/3 set to 1                *
* Pixel index of character 0xB0 (176) at 4/4 set to 1                *
* Pixel index of character 0xB0 (176) at 5/2 set to 0                *
* Pixel index of character 0xB0 (176) at 5/3 set to 0                *
* Pixel index of character 0xB0 (176) at 5/4 set to 0                *
* Pixel index of character 0xB0 (176) at 4/5 set to 0                *
*                                                                    *
**********************************************************************
*/

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

/* The following line needs to be included in any file selecting the
   font.
*/
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontunit;

/* Start of unicode area <Basic Latin> */
GUI_CONST_STORAGE unsigned char acGUI_Fontunit_0043[ 34] = { /* code 0043, LATIN CAPITAL LETTER C */
  ____XXX_,________,
  __XXXXXX,________,
  _XXX___X,X_______,
  _XX_____,XX______,
  XXX_____,XX______,
  XX______,XX______,
  XX______,________,
  XX______,________,
  XX______,________,
  XX______,________,
  XX______,XX______,
  XX______,XX______,
  XXX_____,XX______,
  _XX____X,XX______,
  _XXX___X,X_______,
  __XXXXXX,________,
  ____XXX_,________};

/* Start of unicode area <Latin-1 Supplement> */
GUI_CONST_STORAGE unsigned char acGUI_Fontunit_00B0[  6] = { /* code 00B0, DEGREE SIGN */
  ________,
  _XXX____,
  X___X___,
  X___X___,
  X___X___,
  _XXX____};

GUI_CONST_STORAGE GUI_CHARINFO_EXT GUI_Fontunit_CharInfo[2] = {
   {  10,  17,   1,   4,  12, acGUI_Fontunit_0043 } /* code 0043, LATIN CAPITAL LETTER C */
  ,{   6,   6,   3,   3,  24, acGUI_Fontunit_00B0 } /* code 00B0, DEGREE SIGN */
};

GUI_CONST_STORAGE GUI_FONT_PROP_EXT GUI_Fontunit_Prop2 = {
   0x00B0 /* first character */
  ,0x00B0 /* last character  */
  ,&GUI_Fontunit_CharInfo[  1] /* address of first character */
  ,(GUI_CONST_STORAGE GUI_FONT_PROP_EXT *)0 /* pointer to next GUI_FONT_PROP_EXT */
};

GUI_CONST_STORAGE GUI_FONT_PROP_EXT GUI_Fontunit_Prop1 = {
   0x0043 /* first character */
  ,0x0043 /* last character  */
  ,&GUI_Fontunit_CharInfo[  0] /* address of first character */
  ,&GUI_Fontunit_Prop2 /* pointer to next GUI_FONT_PROP_EXT */
};

GUI_CONST_STORAGE GUI_FONT GUI_Fontunit = {
   GUI_FONTTYPE_PROP_EXT /* type of font    */
  ,24 /* height of font  */
  ,24 /* space of font y */
  ,1 /* magnification x */
  ,1 /* magnification y */
  ,{&GUI_Fontunit_Prop1}
  ,21 /* Baseline */
  ,11 /* Height of lowercase characters */
  ,17 /* Height of capital characters */
};

