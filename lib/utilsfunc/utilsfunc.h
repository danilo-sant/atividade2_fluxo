#ifndef UTILSFUNC_H
#define UTILSFUNC_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

// OLED Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
extern Adafruit_SSD1306 display;

// Pinos dos botões
#define P1 33
#define P2 27
#define P3 14
#define BUZZER 13

// Pinos dos LEDs dos postos
#define LED_P1 32
#define LED_P2 26
#define LED_P3 12
#define LED_ABRIR 19
#define LED_FECHAR 18

// Debounce em microssegundos
#define TEMPO_DEBOUNCE 200000

// Variáveis globais
extern volatile int destinoSelecionado;
extern int postoAtual;
extern bool garraFechada;
extern unsigned long ultimoCliqueP1;
extern unsigned long ultimoCliqueP2;
extern unsigned long ultimoCliqueP3;

// Protótipos de funções
void mostrarEstado(String info);
void moverPara(int destino);
void abrirGarra();
void fecharGarra();
void simularMovimento(unsigned long tempo);
unsigned long calcularTempoMovimento(int origem, int destino);
void atualizarLEDPosto(int posto);

// Funções de interrupção
void IRAM_ATTR selecionarPosto1();
void IRAM_ATTR selecionarPosto2();
void IRAM_ATTR selecionarPosto3();

#endif