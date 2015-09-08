/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %Button.h%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      Mario Alberto Rivera González %
* %date_created:    Monday July  29 14:38:03 2015 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : Contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library.             */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 17/07/2015  | 				               | Mario Rivera     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef Button_H                               /* To avoid double inclusion */
#define Button_H

/* Includes */
/* -------- */


/* Exported types and constants */
/* ---------------------------- */
#define StopCktIn_PUSH					64
#define CwCktIn_PUSH					65
#define CcwCktIn_PUSH					66

#define PRESSED							1
#define NON_PRESSED						0

#define INPUT							0
#define LOGICAL_VALUE_INT				1
#define PRESSED_BUTTON_OK				1

/* Types definition */
/* typedef */
typedef T_UBYTE(*Button_FunctionPtrType)( T_UBYTE Channel );

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
typedef struct
{
	T_UBYTE channel;
	Button_FunctionPtrType PushButton;
}Button;

enum re_states
{
	MANUAL,
	AUTOMATIC,
	OPEN,
	CLOSED,
	STANDBY,
	PINCH
};

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void Button_Init( Button *b, T_UBYTE Channel );
extern T_UBYTE Button_Unpressed( T_UBYTE lub_channel);
extern T_UBYTE Check_Button_OK(Button ls_Open, Button ls_Close, Button ls_Pinch );

/* Functions macros */


/* Exported defines */


#endif


