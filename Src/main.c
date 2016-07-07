#include "main.h"

static void Draw_Menu(void);
static void GetPosition(void);
static void SystemClock_Config(void);
static void Error_Handler(void);
static void Update_ColorSize(void);

int main(void) {
    /* STM32F4xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
       */
    HAL_Init();

    /* Configure the system clock to 168 MHz */
    SystemClock_Config();

    BSP_LED_Init(LED3);
    BSP_LED_Init(LED4);

    BSP_LCD_Init();

    BSP_LCD_LayerDefaultInit(1, LCD_FRAME_BUFFER_LAYER1);
    BSP_LCD_LayerDefaultInit(0, LCD_FRAME_BUFFER_LAYER0);

    BSP_LCD_SetColorKeying(0, LCD_COLOR_BLACK);
    BSP_LCD_SetColorKeying(1, LCD_COLOR_BLACK);

    BSP_LCD_DisplayOn();

    // Don't do touchschreen calibration (not using yet)
    //Touchscreen_Calibration();
    //BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

    int i = 0;
    while (1) {
        BSP_LCD_SelectLayer(i%2);

        BSP_LCD_Clear(LCD_COLOR_BLACK);
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
        BSP_LCD_SetFont(&Font12);

        char buf[10];
        sprintf(buf, "%i", i);
        BSP_LCD_DisplayStringAt(210, (BSP_LCD_GetYSize()-55), (uint8_t*) buf, LEFT_MODE);

        int xprev = 0;
        for( int j = 0; j != BSP_LCD_GetYSize(); ++j ) {
            int x = rand()%BSP_LCD_GetXSize();
            BSP_LCD_DrawLine(x, j+1, xprev, j);
            xprev = x;
        }

        ++i;
    }
}

static void Error_Handler(void)
{
    /* Turn LED4 on */
    BSP_LED_On(LED4);
    while(1)
    {
    }
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow : 
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 168000000
 *            HCLK(Hz)                       = 168000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 8000000
 *            PLL_M                          = 8
 *            PLL_N                          = 336
 *            PLL_P                          = 2
 *            PLL_Q                          = 7
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 5
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void)
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;

    /* Enable Power Control clock */
    __HAL_RCC_PWR_CLK_ENABLE();

    /* The voltage scaling allows optimizing the power consumption when the device is 
       clocked below the maximum system frequency, to update the voltage scaling value 
       regarding system frequency refer to product datasheet.  */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /* Enable HSE Oscillator and activate PLL with HSE as source */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = 2;
    RCC_OscInitStruct.PLL.PLLQ = 7;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
       clocks dividers */
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);

    while (1) { }
}

#endif
