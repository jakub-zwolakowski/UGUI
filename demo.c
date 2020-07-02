//#include "stm32_BSP.h"   // Or whatever else you need to include for your BSP/processor
#include "ugui.h"
#include "stdint.h"

void UserSetPixel (UG_S16 x, UG_S16 y, UG_COLOR c) {
  /*
   * This line is specific to your board and libraries, and will need to be changed unless
   * you're using STM32Cube's BSP for the STM32F7 Disco Board. If not, you can remove
   * the "0xFF000000 |" part, it's just a way to fix uGUI not currently supporting the alpha channel.
   */
  // BSP_LCD_DrawPixel(x, y, 0xFF000000 | c);
}

int main(void)
{
  /* Configure uGUI */
  UG_GUI g;
  UG_Init(&g, UserSetPixel , 480, 272);

  /* Draw text with uGUI */
  UG_FontSelect(&FONT_8X14);
  UG_ConsoleSetArea(0, 60, 480, 212);
  UG_ConsoleSetBackcolor(C_BLACK);
  UG_ConsoleSetForecolor(C_RED);
  UG_ConsolePutString("Beginning System Initialization...\n");
  UG_ConsoleSetForecolor(C_GREEN);
  UG_ConsolePutString("System Initialization Complete\n");

  return 0;
}
