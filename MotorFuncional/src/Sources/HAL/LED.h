/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %LED.h%
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
/*  1.0      | 17/07/2015  |                               | Mario Rivera     */
/* Integration programming layer. Driver to use Led's in any program.         */
/*----------------------------------------------------------------------------*/
/*============================================================================*/

#ifndef LED_H                               /* To avoid double inclusion */
#define LED_H

/* Includes */
/* -------- */

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

#define OUTPUT					1

#define OPEN_DRAIN_DISABLE		0
#define OPEN_DRAIN_ENABLE		1
#define LOGICAL_VALUE_OUT		1


#define OutputMotorA       					68
#define OutputMotorB        				69
#define OutputMotorC        				70
#define OutputMotorD        				71


#define OutputMotor1       					0
#define OutputMotor2        				1
#define OutputMotor3        				2
#define OutputMotor4        				3
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
extern void LED_Init( T_UBYTE lub_chanel );
extern void Led_OFF( T_UBYTE Led );
extern void Led_ON( T_UBYTE Led );
/* Functions macros */


/* Exported defines */


#endif


