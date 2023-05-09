/*
  Autor: Pedro Henrique Cerneiro de Araújo        RA:22108287
  Autor: Bruna Stephanie Soares Gonçalves         RA:21707921

  Obs: Essa biblioteca de controle de Threads precisa ser previamente instalada, e 
  pode ser encontrada no github: https://github.com/ivanseidel/ArduinoThread

*/
// inclui as bibliotecas de Thread
#include "Thread.h"
#include "ThreadController.h"


// saídas analógicas para o Led
#define pinoR 6
#define pinoG 5
#define pinoB 3

/* Agora queremos implementar diferentes tempos de ativação para os LEDs RGB, como o arduino não possui threads nem paralelismo, temos que implementar isso, 
de uma forma meio porca.
*/
#define TEMPO_R 200
#define TEMPO_G 500
#define TEMPO_B 300

// Vamos criar as threads para cada led aqui
ThreadController cpu;
Thread threadLedR,threadLedG,threadLedB;

// Vetor com valores de cor para cada pino.
int valoresPinos[]={128,199,64}; 
void setup() {
  pinMode(pinoR,OUTPUT);
  pinMode(pinoG,OUTPUT);
  pinMode(pinoB,OUTPUT);
  // Marcamos quanto tempo em milissegundos queremos que a thread dure
  threadLedR.setInterval(TEMPO_R);
  threadLedG.setInterval(TEMPO_G);
  threadLedG.setInterval(TEMPO_G);
  //Marcamos aqui o que queremos que a thread faça quando estiver rodando.
  threadLedR.onRun(funcaoR);
  threadLedG.onRun(funcaoG);
  threadLedB.onRun(funcaoB);
  //Vamos adicionar as threads na lista de processos da CPU.
  cpu.add(&threadLedR);
  cpu.add(&threadLedG);
  cpu.add(&threadLedB);


}

//Vamos colocar as threads porcas aqui:
void funcaoR(){
  //valoresPinos[0]=random(0,256);
  digitalWrite(pinoR,!digitalRead(pinoR));
}
void funcaoG(){
  digitalWrite(pinoG,!digitalRead(pinoG));
}
void funcaoB(){
  digitalWrite(pinoB,!digitalRead(pinoB));
}

void loop() {

  cpu.run();
  delay(300);
}
