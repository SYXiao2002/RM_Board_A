//
// Created by 沈逸潇 on 2022/8/9.
//

#include "user_CLI.h"
static CLI_Command_Definition_t setLEDsWaterfulNumCommand;
static CLI_Command_Definition_t showSTM32F4ChipTempCommand;


void user_CLI_Init(){
	FreeRTOS_CLIRegisterCommand(&setLEDsWaterfulNumCommand);
	FreeRTOS_CLIRegisterCommand(&showSTM32F4ChipTempCommand);
}

static BaseType_t prvSetLEDsWaterfulNumCommand ( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
uint8_t *pxPara1StringLen = malloc(sizeof(uint8_t) * 1);
const char *pxPara1 = FreeRTOS_CLIGetParameter( pcCommandString, 1, pxPara1StringLen);

	uint8_t Para1= (uint8_t) strtol(pxPara1, NULL,10);

	if(Fused_LEDs_IO.WriteWaterfulNum( Para1 ) == LEDs_Ok){
		sprintf( pcWriteBuffer, "[Fused_LEDs] Succeed: enlightening %d LEDs.\n", Para1);
	}else{
		sprintf( pcWriteBuffer, "[Fused_LEDs] Warning: the range of Waterful_Number is [1, 8]. You just entered: %d.\n", Para1);
	}

	free(pxPara1StringLen);
	return pdFALSE;
}

static CLI_Command_Definition_t setLEDsWaterfulNumCommand = {
		"setLEDsWaterfulNum",
		"setLEDsWaterfulNum: [PARA1 {ranged in 1 and 8}].\n",
		prvSetLEDsWaterfulNumCommand,
		1,
};

static BaseType_t prvShowSTM32F4ChipTempCommand ( char *pcWriteBuffer,
												  size_t xWriteBufferLen,
												  const char *pcCommandString )
{
	sprintf(pcWriteBuffer, "[STM32F427IIHX] The chip temperature is %4.1f °C.\n", get_temprate());
	return pdFALSE;
}

static CLI_Command_Definition_t showSTM32F4ChipTempCommand = {
		"showSTM32F4ChipTemp",
		"showSTM32F4ChipTemp: [NO PARA].\n",
		prvShowSTM32F4ChipTempCommand,
		0,
};



