#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include "utilsfunc.h"

void setup() {
  Serial.begin(115200);

  // Inicializa display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Inicializa botões
  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
  pinMode(P3, INPUT_PULLUP);

  // LEDs dos postos e garra
  pinMode(LED_P1, OUTPUT);
  pinMode(LED_P2, OUTPUT);
  pinMode(LED_P3, OUTPUT);
  pinMode(LED_ABRIR, OUTPUT);
  pinMode(LED_FECHAR, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Interrupções
  attachInterrupt(digitalPinToInterrupt(P1), selecionarPosto1, FALLING);
  attachInterrupt(digitalPinToInterrupt(P2), selecionarPosto2, FALLING);
  attachInterrupt(digitalPinToInterrupt(P3), selecionarPosto3, FALLING);

  // Define posto inicial aleatório
  postoAtual = random(1, 4);
  atualizarLEDPosto(postoAtual);
  abrirGarra();
  mostrarEstado("Sistema pronto");
}

void loop() {
  if (destinoSelecionado != 0 && destinoSelecionado != postoAtual) {
    moverPara(destinoSelecionado);
    destinoSelecionado = 0;
  }
}