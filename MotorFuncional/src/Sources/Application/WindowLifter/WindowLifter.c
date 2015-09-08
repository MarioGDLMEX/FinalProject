/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %WindowLifter.c%
* Instance:         RPL_1
* %version:         2 %
* %created_by:      Mario Alberto Rivera González %
* %date_created:    Monday July  29 14:38:03 2015 %
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : Implements a module that controls windows movement.     */
/* I have in this file a few function that help me implements Close, Open.    */
/* A states machine that helpe to move trough Automatic, Manual and Anti-Pinch*/
/* mode.                                                                      */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 03/07/2015  |                               | Mario Rivera     */
/* Integration under Continuus CM                                             */
/*----------------------------------------------------------------------------*/
/*  2.0      | 22/07/2015  |                               | Mario Rivera     */
/*	Fix managment button  when occurs transition automatic to manual.       */
/*  Fix bugs when turn on led indicator close when te window is totally close.*/
/*  Fix bugs when turn on led indicator open when the window is totally open. */
/*============================================================================*/

/* Includes */


/** Own headers */
#include "WindowLifter.h"
#include "typedefs.h"
#include "LED.h"
#include "Button.h"


/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */
void States_machine_WindowLifter( void );


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

T_UBYTE rub_counter_Button_OK;
T_UBYTE option_Button;
T_UBYTE option_Button1;

/* WORD RAM variables */

/* LONG and STRUCTURE RAM variables */
Button StopCktIn;
Button CwCktIn;
Button CcwCktIn;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */
enum
{
	STOP,
	GIRO_HORARIO,
	GIRO_ANTIHORARIO
};

/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : Button_Management_1ms	
 *  Description          : This function controlls button. Check if
 *						   there's any push button and combination button.
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    YES
 **************************************************************/
 
void Button_Management_1ms(void)
{
	if( rub_counter_Button_OK )
	{
		if( Button_Unpressed(StopCktIn.channel) && option_Button1 == STOP )
		{
			option_Button = STOP;
			rub_counter_Button_OK = 0;
		}
		else if( Button_Unpressed(CwCktIn.channel) && option_Button1 == GIRO_HORARIO )
		{
			option_Button = GIRO_HORARIO;
			rub_counter_Button_OK = 0;
		}
		else if( Button_Unpressed(CcwCktIn.channel) && option_Button1 == GIRO_ANTIHORARIO )
		{
			option_Button = GIRO_ANTIHORARIO;
			rub_counter_Button_OK = 0;
		}
		else
		{
			
		}
	}
}

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : Check_Button_OK_2P5ms	
 *  Description          : This function is call to check
 *						   if any button is pressed and keeps pressed.
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  YES
 **************************************************************/
//Move to button
void Check_Button_OK_2P5ms(void)
{   
    static T_UBYTE lub_Counter = 0;
    if( rub_counter_Button_OK == 0 )
    {
    	if( StopCktIn.PushButton(StopCktIn.channel) || 
    		CwCktIn.PushButton( CwCktIn.channel) || 
    		CcwCktIn.PushButton( CcwCktIn.channel) )
	    {
	    		lub_Counter++;
	    		if( lub_Counter == 4 )
	    		{
	    			rub_counter_Button_OK = 1;
	    			if( StopCktIn.PushButton(StopCktIn.channel) )
	    				option_Button1 = STOP;
	    			else if( CwCktIn.PushButton( CwCktIn.channel) )
	    				option_Button1 = GIRO_HORARIO;
	    			else if(CcwCktIn.PushButton( CcwCktIn.channel))
	    				option_Button1 = GIRO_ANTIHORARIO;
	   				else
	   				{
	   					
	   				}
	    		}
	    		else
	    		{
	    			/*Do nothing*/
	    		}
	    }
		else
		{
			lub_Counter = 0;
		}	
    }
}



/* Inline functions */

/* ---------------- */
/**************************************************************
 *  Name                 : States_machine_WindowLifter	
 *  Description          : Check states and do actios for each state.
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  YES
 **************************************************************/
void States_machine_WindowLifter( void )
{		
	switch( option_Button )
	{
		case STOP:
		break;
		case GIRO_HORARIO:
			CwCktInFunc();
		break;
		case GIRO_ANTIHORARIO:
			CcwCktInFunc();
		break;
		default:
		break;
	}
}

void CwCktInFunc(void)
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


void CcwCktInFunc(void)
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
void InitWindowLifter(void)//SchM_Background
{
	/*Initialize LEDS*/
	LED_Init(OutputMotorA);
	LED_Init(OutputMotorB);
	LED_Init(OutputMotorC);
	LED_Init(OutputMotorD);
	LED_Init(OutputMotor1);
	LED_Init(OutputMotor2);
	LED_Init(OutputMotor3);
	LED_Init(OutputMotor4);
	/*Initialize Push buttons*/
	Button_Init(&StopCktIn,StopCktIn_PUSH);
	Button_Init(&CwCktIn,CwCktIn_PUSH);
	Button_Init(&CcwCktIn,CcwCktIn_PUSH);
	option_Button = 0;
	option_Button1 = 10;
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

