/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        Stepper.h
* Instance:         RPL_1
* %version:         1 %
* %created_by:      Edgar Mosqueda Cardenas
* %date_created:    Mon Sep 7 11:38:03 2015
*=============================================================================*/
/* DESCRIPTION :                                          */
/*============================================================================*/
/* FUNCTION COMMENT :               */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 07/09/2015  | SAR/SIF/SCN_xxx               | Edgar Mosqueda   */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef STEPPER_H                               /* To avoid double inclusion */
#define STEPPER_H

/* Includes */
#include "typedefs.h"
/* -------- */


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */
    

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
extern void InitMotor(void);
extern void Management_CAN_message( void );
extern void Message_OK( void );
void increase_speedometer(void);
void decrease_speedometer(void);

/* Functions macros */


/* Exported defines */


#endif

