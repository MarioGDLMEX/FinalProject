/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.c
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "Can_Manager.h"
#include "GPIO.h"
/*~E*/
/*~A*/
/*~+:Defines*/

/*~E*/
/*~A*/
/*~+:Variables*/
struct CanTest
{
	uint8_t     can_test_enable;
}CanTestStruct;
/* Temporary CAN Messages */
uint8_t msg0_OK[8]  = {0x15,0x00,0x04,0x67,0x12,0x34,0x56,0x79};
uint8_t msg1_0K[8]  = {0x21,0x89,0x12,0x34,0x56,0x00,0x00,0x00};
uint8_t msg_FAIL[8] = {0x01,0x7F,0x00,0x7F,0x00,0x00,0x00,0x00};

CAN_PduType    pdu_handler1 = { 2, 8, msg0_OK};
CAN_PduType    pdu_handler2 = { 2, 8, msg1_0K};
CAN_PduType    pdu_handler3 = { 2, 8, msg_FAIL};
uint32_t PduHandlerCnt0 = 0;
uint32_t PduHandlerCnt6 = 0;
uint8_t sendMessage = 0;
/*~E*/
/*~A*/
/*~+:Private Operations*/

/*~E*/
/*~A*/
/*~+:Public Operations*/
/*~A*/
/*~+:Can Manager Callbacks*/
CAN_MessageDataType CanMessage_PduHandler0;
CAN_MessageDataType CanMessage_PduHandler6;

void Can_Manager_PduHandler0(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler0 = CanMessage;
	PduHandlerCnt0++;
	sendMessage = 1;
}

void Can_Manager_PduHandler6(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler6 = CanMessage;
	PduHandlerCnt6++;
}
/*~E*/
/*~A*/
/*~+:Can Manager Periodic Functions*/
/*~A*/
/*~+:CanManager_SendMesage_12p5ms*/
void CanManager_SendMessage_12p5ms(void)
{
	//CAN_SendFrame(pdu_handler4);
	//CAN_SendFrame(pdu_handler5);
	if (CanTestStruct.can_test_enable)
	{
		CanTestStruct.can_test_enable = 0;
	}
}
/*~E*/
/*~A*/
/*~+:CanManager_SendMesage_25ms*/
void CanManager_SendMessage_25ms(void)
{
	//CAN_SendFrame(pdu_handler6);
}

