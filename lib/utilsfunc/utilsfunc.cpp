#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "utilsfunc.h"

// Inicialização do display OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Variáveis globais
volatile int destinoSelecionado = 0;
int postoAtual;
bool garraFechada = false;
unsigned long ultimoCliqueP1 = 0;
unsigned long ultimoCliqueP2 = 0;
unsigned long ultimoCliqueP3 = 0;

// Funções de interrupção
void IRAM_ATTR selecionarPosto1() {
  if ((micros() - ultimoCliqueP1) > TEMPO_DEBOUNCE) {
    destinoSelecionado = 1;
    ultimoCliqueP1 = micros();
  }
}

void IRAM_ATTR selecionarPosto2() {
  if ((micros() - ultimoCliqueP2) > TEMPO_DEBOUNCE) {
    destinoSelecionado = 2;
    ultimoCliqueP2 = micros();
  }
}

void IRAM_ATTR selecionarPosto3() {
  if ((micros() - ultimoCliqueP3) > TEMPO_DEBOUNCE) {
    destinoSelecionado = 3;
    ultimoCliqueP3 = micros();
  }
}

void moverPara(int destino) {
  fecharGarra();
  mostrarEstado("Movendo para posto " + String(destino));
  simularMovimento(calcularTempoMovimento(postoAtual, destino));
  atualizarLEDPosto(destino);
  abrirGarra();
  postoAtual = destino;
  mostrarEstado("Chegou ao posto " + String(postoAtual));
}

void simularMovimento(unsigned long tempo) {
  unsigned long inicio = millis();
  tone(BUZZER, 1000);  // Inicia som a 1000 Hz
  while (millis() - inicio < tempo) {
    unsigned long restante = tempo - (millis() - inicio);
    mostrarEstado("Movendo... " + String(restante / 1000) + "s");
    delay(500);
  }
  noTone(BUZZER);  // Para o som após o movimento
}

unsigned long calcularTempoMovimento(int origem, int destino) {
  int distancia = abs(origem - destino);
  if (distancia == 1) return 5000;
  else if (distancia == 2) return 10000;
  else return 0;
}

void abrirGarra() {
  digitalWrite(LED_ABRIR, HIGH);
  digitalWrite(LED_FECHAR, LOW);
  garraFechada = false;
}

void fecharGarra() {
  digitalWrite(LED_ABRIR, LOW);
  digitalWrite(LED_FECHAR, HIGH);
  garraFechada = true;
}

void atualizarLEDPosto(int posto) {
  digitalWrite(LED_P1, posto == 1);
  digitalWrite(LED_P2, posto == 2);
  digitalWrite(LED_P3, posto == 3);
}

void mostrarEstado(String info) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Posto: ");
  display.println(postoAtual);
  display.println(" ");
  display.println(" ");

  display.setCursor(0, 15);
  display.print("Destino: ");
  display.println(destinoSelecionado == 0 ? "-" : String(destinoSelecionado));
  display.println(" ");
  display.println(" ");

  display.setCursor(0, 30);
  display.print("Garra: ");
  display.println(garraFechada ? "Fechada" : "Aberta");
  display.println(" ");

  display.setCursor(0, 45);
  display.println(info);
  display.println(" ");

  display.display();
}