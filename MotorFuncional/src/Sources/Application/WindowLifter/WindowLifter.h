/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %WindowLifter.h%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      Mario Alberto Rivera Gonz�lez %
* %date_created:    Fri jun 30 13:41:01 2015 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 30/06/2015  | SAR/SIF/SCN_xxx               | Mario Rivera     */
/* Integration under Continuus CM                                             */
/*----------------------------------------------------------------------------*/
/*  2.0      | 22/07/2015  |                               | Mario Rivera     */
/*  Rename functions: Button_Management_1ms, Check_Button_OK_2P5ms and        */
/*  Machine_Call_100ms										                  */
/*============================================================================*/

#ifndef _WINDOWLIFTER_H                               /* To avoid double inclusion */
#define _WINDOWLIFTER_H

/* Includes */
#include "typedefs.h"
/* -------- */


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */
#define _400Mili 			400
#define _5000Mili 			5000
#define _500Mili  			500
#define _10Mili 			10
#define RESET_COUNTER		0
#define ANTI_PINCH_OK       1

/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void InitWindowLifter(void);
extern void Button_Management_1ms( void );
extern void Check_Button_OK_2P5ms( void );
void CwCktInFunc(void);
void CcwCktInFunc(void);

/* Functions macros */


/* Exported defines */


#endif /* _WINDOWLIFTER_H */