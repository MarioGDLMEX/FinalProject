/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Stepper.c
* Instance:         RPL_1
* %version:         2 %
* %created_by:      Edgar Mosqueda Cardenas
* %date_created:    Mon Sep 7 11:38:03 2015 
*=============================================================================*/
/* DESCRIPTION :                                        */
/*============================================================================*/
/* FUNCTION COMMENT :                                                   */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 07/09/2015  |                               | Edgar Mosquesda  */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "Stepper.h"
#include "typedefs.h"
#include "LED.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */
void States_machine_Motor( void );

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

void Management_CAN_message( void )
{
	
}


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Message_OK( void )
{

	
}

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void States_machine_Motor(void)
 {
 	
 }
 
 void increase_speedometer(void)
{
    static T_UBYTE MotorCmd = 0;
    
    MotorCmd++;
    switch (MotorCmd)
    {
	    case  1:
	            Led_ON(OutputMotor1);
           		Led_OFF(OutputMotor2);
            	Led_OFF(OutputMotor3);
            	Led_OFF(OutputMotor4);
	            break;
	    case  2:
	            Led_OFF(OutputMotor1);
           		Led_ON(OutputMotor2);
            	Led_OFF(OutputMotor3);
            	Led_OFF(OutputMotor4);                 
	            break;
	    case  3:
	            Led_OFF(OutputMotor1);
           		Led_OFF(OutputMotor2);
            	Led_ON(OutputMotor3);
            	Led_OFF(OutputMotor4);               
	            break;        
	    case  4:
	           	Led_OFF(OutputMotor1);
           		Led_OFF(OutputMotor2);
            	Led_OFF(OutputMotor3);
            	Led_ON(OutputMotor4);
	            break;
	    case  5:
	            MotorCmd = 0;
	            break;                          
    }
}


void decrease_speedometer(void)
{
    static T_UBYTE MotorCmd = 0;
    
    MotorCmd++;
    switch (MotorCmd)
    {
    case  1:
            Led_ON(OutputMotor4);
            Led_OFF(OutputMotor3);
            Led_OFF(OutputMotor2);
            Led_OFF(OutputMotor1);
            break;
    case  2:
            Led_OFF(OutputMotor4);
            Led_ON(OutputMotor3);
            Led_OFF(OutputMotor2);
            Led_OFF(OutputMotor1);                  
            break;
    case  3:
            Led_OFF(OutputMotor4);
            Led_OFF(OutputMotor3);
            Led_ON(OutputMotor2);
            Led_OFF(OutputMotor1);                  
            break;        
    case  4:
            Led_OFF(OutputMotor4);
            Led_OFF(OutputMotor3);
            Led_OFF(OutputMotor2);
            Led_ON(OutputMotor1);
            break;
    case  5:
            MotorCmd = 0;
            break;                          
    
    }
}
 
/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : InitWindowLifter	
 *  Description          : This functions is called by the main.c
 *						   to initialize windowlifter
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  YES
 **************************************************************/
void InitMotor(void)//SchM_Background
{
	/*Initialize LEDS*/
	LED_Init(OutputMotor1);
	LED_Init(OutputMotor2);
	LED_Init(OutputMotor3);
	LED_Init(OutputMotor4);
	/*Initialize Push buttons*/
/*	Button_Init(&StopCktIn,StopCktIn_PUSH);
	Button_Init(&CwCktIn,CwCktIn_PUSH);
	Button_Init(&CcwCktIn,CcwCktIn_PUSH);
	option_Button = 0;
	option_Button1 = 10;*/
}


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/



