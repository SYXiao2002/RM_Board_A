//
// Created by 沈逸潇 on 2022/8/9.
//

#include "user_CLI.h"
#include "task.h"
#include <math.h>
static CLI_Command_Definition_t setLEDsWaterfulNumCommand;


void user_CLI_Init(){
	FreeRTOS_CLIRegisterCommand(&setLEDsWaterfulNumCommand);
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
		"setLEDsWaterfulNum: range in 1 and 8.\n",
		prvSetLEDsWaterfulNumCommand,
		1,
};



