/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "servo.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int buf_index = 0;
int ibuf_index = 0;
uint8_t data;
uint8_t buffer[4];
uint32_t ibuffer[500] = {0};
uint32_t totalStep = 0;
bool isBufReady = false;
bool isNode = false;

// Khoang 3
servo_t servo_k_3_1 = {
  &htim4,
  TIM_CHANNEL_1
};
servo_t servo_k_3_2 = {
  &htim4,
  TIM_CHANNEL_1
};
servo_t servo_k_3_3 = {
  &htim4,
  TIM_CHANNEL_1
};
servo_t servo_k_3_4 = {
  &htim4,
  TIM_CHANNEL_1
};
servo_t servo_k_3_5 = {
  &htim4,
  TIM_CHANNEL_1
};
servo_t servo_k_3_6 = {
  &htim4,
  TIM_CHANNEL_1
};

// Khoang 4
servo_t servo_k_4_1 = {
  &htim1,
  TIM_CHANNEL_4
};
servo_t servo_k_4_2 = {
  &htim1,
  TIM_CHANNEL_3
};
servo_t servo_k_4_3 = {
  &htim1,
  TIM_CHANNEL_2
};
servo_t servo_k_4_4 = {
  &htim1,
  TIM_CHANNEL_1
};
servo_t servo_k_4_5 = {
  &htim2,
  TIM_CHANNEL_1
};
servo_t servo_k_4_6 = {
  &htim2,
  TIM_CHANNEL_2
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart == &huart2)
  {
    if (buf_index == 0 && data == 254)
    {
      //do nothing for 1 byte
    }
    else
    {
      buffer[buf_index++] = data;
      if (buf_index == 4)
      {
        ibuffer[ibuf_index++] = (uint32_t)(buffer[3] << 24) | (uint32_t)(buffer[2] << 16) | (uint32_t)(buffer[1] << 8) | (uint32_t)buffer[0];
        buf_index = 0;
      }
      if (isBufReady == true)
      {
        if (data == 0xAB)
        {
          isNode = true;
        }
        data = '\0';
      }
    }
    HAL_UART_Receive_IT(&huart2, &data, 1);
  }
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart2, &data, 1);

  Servo_Init(&servo_k_3_1, servo_k_3_1.htim, servo_k_3_1.channel);
  Set_servo_5p(&servo_k_3_1);
  Servo_Init(&servo_k_3_2, servo_k_3_2.htim, servo_k_3_2.channel);
  Set_servo_5p(&servo_k_3_2);
  Servo_Init(&servo_k_3_3, servo_k_3_3.htim, servo_k_3_3.channel);
  Set_servo_5p(&servo_k_3_3);
  Servo_Init(&servo_k_3_4, servo_k_3_4.htim, servo_k_3_4.channel);
  Set_servo_5p(&servo_k_3_4);
  Servo_Init(&servo_k_3_5, servo_k_3_5.htim, servo_k_3_5.channel);
  Set_servo_5p(&servo_k_3_5);
  Servo_Init(&servo_k_3_6, servo_k_3_6.htim, servo_k_3_6.channel);
  Set_servo_5p(&servo_k_3_6);

  Servo_Init(&servo_k_4_1, servo_k_4_1.htim, servo_k_4_1.channel);
  Set_servo_5p(&servo_k_4_1);
  Servo_Init(&servo_k_4_2, servo_k_4_2.htim, servo_k_4_2.channel);
  Set_servo_5p(&servo_k_4_2);
  Servo_Init(&servo_k_4_3, servo_k_4_3.htim, servo_k_4_3.channel);
  Set_servo_5p(&servo_k_4_3);
  Servo_Init(&servo_k_4_4, servo_k_4_4.htim, servo_k_4_4.channel);
  Set_servo_5p(&servo_k_4_4);
  Servo_Init(&servo_k_4_5, servo_k_4_5.htim, servo_k_4_5.channel);
  Set_servo_5p(&servo_k_4_5);
  Servo_Init(&servo_k_4_6, servo_k_4_6.htim, servo_k_4_6.channel);
  Set_servo_5p(&servo_k_4_6);

  // HAL_UART_Receive_IT(&huart2, &data, 1);
  HAL_Delay(10000);

  uint32_t count = 0;
  isBufReady = true;
  HAL_UART_Transmit(&huart2, 0xBA, 1, 100);



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    if (isNode == true)
    {
      isNode = false;
      uint32_t bit = ibuffer[count++];

      if(((bit >> 12) & 0x00000001)) Set_servo_5p(&servo_k_3_1);
      else Set_servo_9p(&servo_k_3_1);

      if(((bit >> 13) & 0x00000001)) Set_servo_5p(&servo_k_3_2);
      else Set_servo_9p(&servo_k_3_2);

      if(((bit >> 14) & 0x00000001)) Set_servo_5p(&servo_k_3_3);
      else Set_servo_9p(&servo_k_3_3);

      if(((bit >> 15) & 0x00000001)) Set_servo_5p(&servo_k_3_4);
      else Set_servo_9p(&servo_k_3_4);

      if(((bit >> 16) & 0x00000001)) Set_servo_5p(&servo_k_3_5);
      else Set_servo_9p(&servo_k_3_5);

      if(((bit >> 17) & 0x00000001)) Set_servo_5p(&servo_k_3_6);
      else Set_servo_9p(&servo_k_3_6);

      if(((bit >> 18) & 0x00000001)) Set_servo_5p(&servo_k_4_1);
      else Set_servo_9p(&servo_k_4_1);

      if(((bit >> 19) & 0x00000001)) Set_servo_5p(&servo_k_4_2);
      else Set_servo_9p(&servo_k_4_2);

      if(((bit >> 20) & 0x00000001)) Set_servo_5p(&servo_k_4_3);
      else Set_servo_9p(&servo_k_4_3);

      if(((bit >> 21) & 0x00000001)) Set_servo_5p(&servo_k_4_4);
      else Set_servo_9p(&servo_k_4_4);

      if(((bit >> 22) & 0x00000001)) Set_servo_5p(&servo_k_4_5);
      else Set_servo_9p(&servo_k_4_5);

      if(((bit >> 23) & 0x00000001)) Set_servo_5p(&servo_k_4_6);
      else Set_servo_9p(&servo_k_4_6);

      HAL_Delay(250);

      if( (count != 1) && (count != 2) && (count != 3) && (count != 4) &&     \
          (count != 5) && (count != 12) && (count != 19) && (count != 24) &&  \
          (count != 25) && (count != 32) && (count != 39) && (count != 47) && \
          (count != 52) && (count != 54) && (count != 59) && (count != 76) && \
          (count != 85) && (count != 88) && (count != 95))
      {
        HAL_Delay(250);
      }
      else if((count == 1) || (count == 2) || (count == 3) || (count == 4) ||     \
              (count == 5) || (count == 12) || (count == 19) || (count == 24) ||  \
              (count == 25) || (count == 39) || (count == 47) || (count == 52) || \
              (count == 59) || (count == 76) || (count == 85) || (count == 88) || \
              (count == 95))
      {
        HAL_Delay(750);
      }
      else if((count == 32) || ( count == 54))
      {
        HAL_Delay(1250);
      }
    }

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */