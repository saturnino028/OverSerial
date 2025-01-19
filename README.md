# Atividade 2 - Microcontroladores – GPIO

Atividade realizada com o uso da biblioteca STDIO, para controle de LEDs e buzzer da placa BitDogLab. Com base nas teclas pressionadas, há o acionamento de 3 LEDs (Vermelho, Verde e Azul) e o controle sonoro de um buzzer.

A simulação no Wokwi conta com:

1) Entrada Serial;
2) 3 LEDs (Vermelho, Verde e Azul);
3) Buzzer;
4) Placa de Desenvolvimento Raspberry Pi Pico W.

Da placa de desenvolvimento BitDogLab foram usado os seguintes recursos:

1) Entrada Serial (uart0);
2) LED Verde (GPIO 11);
3) LED Azul (GPIO 12);
4) LED Vermelho (GPIO 13);
5) Buzzer (GPIO 21);
6) Placa de Desenvolvimento Raspberry Pi Pico W.

## Instruções de Uso

Foram implementadas 16 funções, sendo acionadas da seguinte forma:

- Tecla 1: Toca Nota Musical Dó;
- Tecla 2: Toca Nota Musical Ré;
- Tecla 3: Toca Nota Musical Mi;
- Tecla 4: Toca Nota Musical Fá;
- Tecla 5: Toca Nota Musical Sol;
- Tecla 6: Toca Nota Musical Lá;
- Tecla 7: Toca Nota Musical Sí;
- Tecla 8: Toca Noite Feliz (música);
- Tecla 9: Toca Jingle Bells (música);
- Tecla 0: Toca Alarme;
- Tecla *: Desliga LEDs e Buzzer;
- Tecla #: Liga LEDs e Buzzer;
- Tecla A: Liga LED Verde;
- Tecla B: Liga LED Azul;
- Tecla C: Liga LED Vermelho;
- Tecla D: Liga todos os LEDs.

## Demonstração

Simulação na plataforma Wokwi: [Teclado Interativo](https://wokwi.com/projects/420386719995015169).

Vídeo demonstrando as funcionalidades da solução implementada: [Vídeo Demonstrativo](https://youtu.be/J6NnjEEjA-M).
