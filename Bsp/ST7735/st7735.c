#include "st7735.h"

static void ST7735_SetAddressWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) {
	lcd7735_sendCmd(ST7735_CASET); // Column addr set
	lcd7735_sendData(0x00);            // XS15 ~ XS8
	lcd7735_sendData(x0+ST7735_XSTART);     // XSTART       XS7 ~ XS0
	lcd7735_sendData(0x00);            // XE15 ~ XE8
	lcd7735_sendData(x1+ST7735_XSTART);     // XEND         XE7 ~ XE0

	lcd7735_sendCmd(ST7735_RASET); // Row addr set
	lcd7735_sendData(0x00);
	lcd7735_sendData(y0+ST7735_YSTART);     // YSTART
	lcd7735_sendData(0x00);
	lcd7735_sendData(y1+ST7735_YSTART);     // YEND

	lcd7735_sendCmd(ST7735_WRITE_RAM);
}
void ST7735_Init() {
	LCD_RST0;               //active low
	HAL_Delay(1200);
	LCD_RST1;
	HAL_Delay(120);

	ST7735_Init_Command1();
	ST7735_Init_Command2();
//	ST7735_Display_Test();
}
void ST7735_Init_Command1(void)
{
	lcd7735_sendCmd(ST7735_SLEEP_OUT);			//  2: Out of sleep mode
	HAL_Delay(120);
	lcd7735_sendCmd(ST7735_FRAME_RATE_CTRL1);		//  3: Frame rate ctrl - normal mode
	lcd7735_sendData(0x01U);							//     Rate = fosc/(1x2+40) * (LINE+2C+2D)
	lcd7735_sendData(0x2CU);
	lcd7735_sendData(0x2DU);
	lcd7735_sendCmd(ST7735_FRAME_RATE_CTRL2);		//  4: Frame rate control - idle mode
	lcd7735_sendData(0x01U);							//  Rate = fosc/(1x2+40) * (LINE+2C+2D)
	lcd7735_sendData(0x2CU);
	lcd7735_sendData(0x2DU);
	lcd7735_sendCmd(ST7735_FRAME_RATE_CTRL3);		//  5: Frame rate ctrl - partial mode
	lcd7735_sendData(0x01U);							//     Dot inversion mode
	lcd7735_sendData(0x2CU);
	lcd7735_sendData(0x2DU);
	lcd7735_sendData(0x01U);							//     Line inversion mode
	lcd7735_sendData(0x2CU);
	lcd7735_sendData(0x2DU);
	lcd7735_sendCmd(ST7735_FRAME_INVERSION_CTRL);			//  6: Display inversion ctrl
	lcd7735_sendData(0x07U);							//     No inversion
	lcd7735_sendCmd(ST7735_PWR_CTRL1);			//  7: Power control
	lcd7735_sendData(0xA2U);
	lcd7735_sendData(0x02U);							//     -4.6V
	lcd7735_sendData(0x84U);							//     AUTO mode
	lcd7735_sendCmd(ST7735_PWR_CTRL2);			//  8: Power control
	lcd7735_sendData(0xC5U);							//     VGH25 = 2.4C VGSEL = -10 VGH = 3 * AVDD
	lcd7735_sendCmd(ST7735_PWR_CTRL3);			//  9: Power control
	lcd7735_sendData(0x0AU);							//     Opamp current small
	lcd7735_sendData(0x00U);							//     Boost frequency
	lcd7735_sendCmd(ST7735_PWR_CTRL4);			// 10: Power control
	lcd7735_sendData(0x8AU);							//     BCLK/2, Opamp current small & Medium low
	lcd7735_sendData(0x2AU);
	lcd7735_sendCmd(ST7735_PWR_CTRL5);			// 11: Power control
	lcd7735_sendData(0x8AU);
	lcd7735_sendData(0xEEU);
	lcd7735_sendCmd(ST7735_VCOMH_VCOML_CTRL1);			// 12: Power control
	lcd7735_sendData(0x0EU);
	lcd7735_sendCmd(ST7735_DISPLAY_INVERSION_OFF);			// 13: Don't invert display

	lcd7735_sendCmd(ST7735_COLOR_MODE);			// 15: set color mode
	lcd7735_sendData(0x05);							//     16-bit color							//     16-bit color
}

void ST7735_Init_Command2(void)
{
	lcd7735_sendCmd(ST7735_PV_GAMMA_CTRL);
	lcd7735_sendData(0x02U);
	lcd7735_sendData(0x1CU);
	lcd7735_sendData(0x07U);
	lcd7735_sendData(0x12U);
	lcd7735_sendData(0x37U);
	lcd7735_sendData(0x32U);
	lcd7735_sendData(0x29U);
	lcd7735_sendData(0x2DU);
	lcd7735_sendData(0x29U);
	lcd7735_sendData(0x25U);
	lcd7735_sendData(0x2BU);
	lcd7735_sendData(0x39U);
	lcd7735_sendData(0x00U);
	lcd7735_sendData(0x01U);
	lcd7735_sendData(0x03U);
	lcd7735_sendData(0x10U);
	lcd7735_sendCmd(ST7735_NV_GAMMA_CTRL);
	lcd7735_sendData(0x03U);
	lcd7735_sendData(0x1DU);
	lcd7735_sendData(0x07U);
	lcd7735_sendData(0x06U);
	lcd7735_sendData(0x2EU);
	lcd7735_sendData(0x2CU);
	lcd7735_sendData(0x29U);
	lcd7735_sendData(0x2DU);
	lcd7735_sendData(0x2EU);
	lcd7735_sendData(0x2EU);
	lcd7735_sendData(0x37U);
	lcd7735_sendData(0x3FU);
	lcd7735_sendData(0x00U);
	lcd7735_sendData(0x00U);
	lcd7735_sendData(0x02U);
	lcd7735_sendData(0x10U);

	lcd7735_sendCmd(ST7735_NORMAL_DISPLAY_OFF);
	lcd7735_sendData(0x00U);

	lcd7735_sendCmd(ST7735_DISPLAY_ON);

	lcd7735_sendCmd(ST7735_MADCTL);			// 14: Memory access control (directions)
	lcd7735_sendData(ST7735_ROTATION_North);	//     row addr/col addr, bottom to top refresh

	ST7735_FillScreen(black);
}

void ST7735_Display_Test(void){
	ST7735_FillScreen(black);
	for (int i = 0; i < 10; ++i) {
		ST7735_DrawInt(0, 0, i, green);
		HAL_Delay(1);
	}
}


void ST7735_DrawPixel(uint16_t x, uint16_t y, ST7735_Colors_t color) {
	if((x >= ST7735_WIDTH) || (y >= ST7735_HEIGHT)) { return; }

	ST7735_SetAddressWindow(x, y, x+1, y+1);
	uint8_t data[2];
	data[0] = color >> 8;
	data[1] = color & 0xFF;
	lcd7735_sendData(data[0]);
	lcd7735_sendData(data[1]);
}

/**
 * Created by Xiao.
 * @param x
 * @param y
 * @param number uint16
 * @param textColor
 */
void ST7735_DrawInt(uint16_t x, uint16_t y, uint16_t integer, ST7735_Colors_t textColor){
	char name[50]="";
	int2Str(integer, name, 1);
	ST7735_DrawString(x, y, name, textColor);
}

/**
 * Improved by Xiao.
 * @param x
 * @param y
 * @param pt	pointer to the char[] (String)
 * @param textColor
 * @return
 */
uint32_t ST7735_DrawString(uint16_t x, uint16_t y, char *pt, ST7735_Colors_t textColor){
	uint32_t count = 0;
	if( y*10 > ST7735_HEIGHT ) return 0;
	while(*pt){
		ST7735_DrawCharS((x++)*6,
		                 y*10,
		                 *pt++, textColor,
		                 black,
		                 1);
		if((x+0)*6 > ST7735_WIDTH) return count;
		count++;
	}
	return count;  // number of characters printed
}

void ST7735_DrawCharS(int16_t x, int16_t y, char c, ST7735_Colors_t textColor, ST7735_Colors_t bgColor, uint8_t size){
	uint8_t line;
	int32_t i, j;
	if((x >= ST7735_WIDTH)
	   ||  (y >= ST7735_HEIGHT)
	   ||  ((x + 5 * size - 1) < 0)
	   ||  ((y + 8 * size - 1) < 0))   {return;}

	for (i=0; i<6; i++ ) {
		if (i == 5)
			line = 0x0;
		else
			line = Font[(c*5)+i];
		for (j = 0; j<8; j++) {
			if (line & 0x1) {
				if (size == 1)
					ST7735_DrawPixel(x+i, y+j, textColor);
				else {
					ST7735_FillRectangle(x+(i*size), y+(j*size), size, size, textColor);
				}
			} else if (bgColor != textColor) {
				if (size == 1) // default size
					ST7735_DrawPixel(x+i, y+j, bgColor);
				else {  // big size
					ST7735_FillRectangle(x+i*size, y+j*size, size, size, bgColor);
				}
			}
			line >>= 1;
		}
	}
}




void ST7735_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, ST7735_Colors_t color) {
	if((x >= ST7735_WIDTH) || (y >= ST7735_HEIGHT)) return;
	if((x + w - 1) >= ST7735_WIDTH) w = ST7735_WIDTH - x;
	if((y + h - 1) >= ST7735_HEIGHT) h = ST7735_HEIGHT - y;

	ST7735_SetAddressWindow(x, y, x+w-1, y+h-1);
	LCD_DC1;
	for(y = h; y > 0; y--) {
		for(x = w; x > 0; x--) {
			lcd7735_sendData(color >> 8);
			lcd7735_sendData(color);
		}
	}

}
void ST7735_FillScreen(ST7735_Colors_t color) {
	ST7735_FillRectangle(0, 0, ST7735_WIDTH, ST7735_HEIGHT, color);
}

static void lcd7735_SPI_MOSI(uint8_t data) {
	HAL_SPI_Transmit(&hspi1, &data,sizeof(data),0x1);
}

void lcd7735_sendCmd(uint8_t cmd) {
	LCD_DC0; //Set DC LOW
	HAL_Delay(1);
//	for (int i = 0; i < 35000; ++i) {}
	lcd7735_SPI_MOSI(cmd);
}

void lcd7735_sendData(uint8_t data) {
	LCD_DC1;//Set DC HIGH
	lcd7735_SPI_MOSI(data);
}
