#include "hal.h"
#include <array>

using namespace std;

// Состояния светодиодов процессорного модуля в процессе работы программы:
// Условие	                                                Светодиод VD6	Светодиод VD7
// Вывод анимации на линейку светодиодов модуля расширения 	Горит зеленым 	Не горит
// Остановка анимации по кнопке nBTN 	                    Не горит 	Горит красным
// Режим вывода состояний SW переключателей                	Не горит 	Горит желтым

int umain()
{
    int delay = 500;
    int x = 0;
    int s = 0;
    std::array<GPIO_PinState, 4> comb = {GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET};
    std::array<GPIO_PinState, 4> state = {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET};
    unsigned int leds_num[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5,
                                   GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9,
                                   GPIO_PIN_11, GPIO_PIN_12};
    unsigned int sw_num[] = {GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};

    while(1) {
        for(int i = 0; i < 4; i++)
        {
            GPIO_PinState sw_state = HAL_GPIO_ReadPin(GPIOE, sw_num[i]);
            state[i] = sw_state;
        }

        if (state == comb) {
            if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) != GPIO_PIN_SET) {
                HAL_Delay(delay);
                s = s^1;
            }

            if(s == 1) {
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
                continue;
            }

            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

            for(int j = 0; j < 8; j++) {
                if(j < 3) {
                    HAL_GPIO_WritePin(GPIOD, leds_num[(x + j) % 8], GPIO_PIN_SET);
                } else {
                    HAL_GPIO_WritePin(GPIOD, leds_num[(x + j) % 8], GPIO_PIN_RESET);
                }
            }

            HAL_Delay(delay);
            x = (x + 1) % 8;
        } else {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);

            x = 0;
            for(int i = 0; i < 4; i++) {
                HAL_GPIO_WritePin(GPIOD, leds_num[i], state[i]);
            }
            for(int i = 4; i < 8; i++) {
                HAL_GPIO_WritePin(GPIOD, leds_num[i], GPIO_PIN_RESET);
            }
        }
    }

    return 0;
}

//int umain()
//{
//    int i = 0;
//    int delay = 500;
//
//    for(i = 0; i < 5; i++) {
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
//        HAL_Delay(delay);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
//        HAL_Delay(delay);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
//        HAL_Delay(delay);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
//        HAL_Delay(delay);
//    }
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
//    return 0;
//}