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
void natal1();
void natal2();

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
                        doh();
                        break;
                    case '2':
                        re();
                        break;
                    case '3':
                        mi();
                        break;
                    case '4':
                        fa();
                        break;
                    case '5':
                        sol();
                        break;
                    case '6':
                        la();
                        break;
                    case '7':
                        si();
                        break;
                    case '8':
                        natal1();
                        break;
                    case '9':
                        natal2();
                        break;
                    case '0':
                        /* code */
                        break;
                    case 'A':
                        gpio_put(LED_G, 1); // Acende o LED verde
                        break;
                    case 'B':
                        gpio_put(LED_B, 1); // Acende o LED azul
                        break;
                    case 'C':
                        gpio_put(LED_R, 1); // Acende o LED vermelho
                        break;
                    case 'D':
                        gpio_put(LED_R, 1); // Acende o LED vermelho
                        gpio_put(LED_G, 1); // Acende o LED verde
                        gpio_put(LED_B, 1); // Acende o LED azul
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

void doh(){
    som_buz(261, 500); // Frequência da nota dó e duração de 0,5 segundo
}

void re(){
    som_buz(293, 500); // Frequência da nota ré e duração de 0,5 segundo
}

void mi(){
    som_buz(330, 500); // Frequência da nota mi e duração de 0,5 segundo
}

void fa(){
    som_buz(349, 500); // Frequência da nota fá e duração de 0,5 segundo
}

void sol(){
    som_buz(392, 500); // Frequência da nota sol e duração de 0,5 segundo
}

void la(){
  som_buz(440, 500); // Frequência da nota mi e duração de 0,5 segundo
}

void si(){
    som_buz(493, 500); // Frequência da nota si e duração de 0,5 segundo
}

//Noite Feliz - Natal 1
void natal1(){
    sol();
    sleep_ms(100);
    la();
    sol();
    mi();

    sleep_ms(1000);

    sol();
    sleep_ms(100);
    la();
    sol();
    mi();

    sleep_ms(1000);

    re();
    sleep_ms(100);
    re();
    sleep_ms(100);
    si();

    sleep_ms(1000);

    doh();
    sleep_ms(100);
    doh();
    sol();

    sleep_ms(1000);

    la();
    sleep_ms(100);
    la();
    doh();
    si();
    la();
    sol();
    sleep_ms(100);
    la();
    sol();
    mi();

    sleep_ms(1000);

    la();
    sleep_ms(100);
    la();
    doh();
    si();
    la();
    sol();
    sleep_ms(100);
    la();
    sol();
    mi();

    re();
    sleep_ms(100);
    re();
    fa();
    re();
    si();
    sleep_ms(100);
    mi();

    sleep_ms(1000);

    doh();
    sol();
    mi();
    sleep_ms(100);
    fa();
    re();
    doh();
}

//Jingle Bells - Natal 2
void natal2(){
    mi(); sleep_ms(200);
    mi(); sleep_ms(200);
    mi(); sleep_ms(400);
  
    mi(); sleep_ms(200);
    mi(); sleep_ms(200);
    mi(); sleep_ms(400);

    mi(); sleep_ms(200);
    sol(); sleep_ms(200);
    doh(); sleep_ms(200);
    re(); sleep_ms(200);
    mi(); sleep_ms(600);

    fa(); sleep_ms(200);
    fa(); sleep_ms(200);
    fa(); sleep_ms(200);
    fa(); sleep_ms(200);

    fa(); sleep_ms(200);
    mi(); sleep_ms(200);
    mi(); sleep_ms(200);
    mi(); sleep_ms(200);
    mi(); sleep_ms(200);
    re(); sleep_ms(200);
    re(); sleep_ms(200);
    mi(); sleep_ms(200);
    re(); sleep_ms(200);

    sol(); sleep_ms(200);
    mi(); sleep_ms(200);
    doh(); sleep_ms(200);
    re(); sleep_ms(200);
    mi(); sleep_ms(1500);
}