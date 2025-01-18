#include <stdio.h>
#include "pico/stdlib.h"

//Definição dos pinos de GPIO
#define LED_G       11 //LED verde
#define LED_B       12 //LED Azul
#define LED_R       13 //LED Vermelho
#define buzzer_pin  21 //Buzzer A da BitDog

//prototipo de funções
void iniciar_pinos();
void som_buz(uint16_t freq, uint16_t duration_ms);
void doh();
void re();
void mi();
void fa();
void sol();
void la();
void si();

//Funções
int main() {
    stdio_init_all();
    iniciar_pinos();

    printf("Programa Iniciado\n");

    while (true) 
    {
        // Verifica se há conexão USB e se um caractere está disponível
        if (stdio_usb_connected()) {
            // Lê um caractere com timeout de 100ms (evita bloqueios)
            int c = getchar_timeout_us(100 * 1000);
            
            // Verifica se o caractere foi capturado
            if (c != PICO_ERROR_TIMEOUT) {
                // Converte para char e imprime no terminal
                printf("Tecla: l%c\n", (char)c);
                switch (c)
                {
                    case '1':
                        /* code */
                        break;
                    case '2':
                        /* code */
                        break;
                    case '3':
                        /* code */
                        break;
                    case '4':
                        /* code */
                        break;
                    case '5':
                        /* code */
                        break;
                    case '6':
                        /* code */
                        break;
                    case '7':
                        /* code */
                        break;
                    case '8':
                        /* code */
                        break;
                    case '9':
                        /* code */
                        break;
                    case '0':
                        /* code */
                        break;
                    case 'A':
                        /* code */
                        break;
                    case 'B':
                        /* code */
                        break;
                    case 'C':
                        /* code */
                        break;
                    case 'D':
                        /* code */
                        break;
                    case '*':
                        /* code */
                        break;
                    case '#':
                        /* code */
                        break;
                    default:
                        break;
                }
            }
        }
        sleep_ms(20);
    }

    return 0;
}

void iniciar_pinos(){

    //Iniciar buzzer
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);

    //Iniciar LEDs
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);

    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);

    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
}

void som_buz(uint16_t freq, uint16_t duration_ms)
{
    uint period = 1000000 / freq;  // Período do sinal em microssegundos
    uint cycles = (duration_ms * 1000) / period;  // Número de ciclos a gerar

    for (uint i = 0; i < cycles; i++) 
    {
        gpio_put(buzzer_pin, 1);  // Liga o buzzer
        sleep_us(period / 2);  // Espera metade do período
        gpio_put(buzzer_pin, 0);  // Desliga o buzzer
        sleep_us(period / 2);  // Espera metade do período
    }

}