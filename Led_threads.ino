/*
  Autor: Pedro Henrique Cerneiro de Araújo        RA:22108287
  Autor: Bruna Stephanie Soares Gonçalves         RA:21707921
*/

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


int valoresPinos[]={128,199,64}; // Vetor com valores de cor para cada pino.
void setup() {
  pinMode(pinoR,OUTPUT);
  pinMode(pinoG,OUTPUT);
  pinMode(pinoB,OUTPUT);

}

//Vamos colocar as threads porcas aqui:
void threadR(){
  //valoresPinos[0]=random(0,256);
  digitalWrite(pinoR,!digitalRead(pinoR));
}
void threadG(){
  digitalWrite(pinoG,!digitalRead(pinoG));
}
void threadB(){
  digitalWrite(pinoB,!digitalRead(pinoB));
}

void loop() {
  static int tempoUltimaMudanca[]={0,0,0};
  // é meio estranho explicar, mas esse if aqui altera o valor do led A CADA TEMPO_R milisegundos.
  if(millis()-tempoUltimaMudanca[0] >= TEMPO_R)
    threadR();
  if(millis()-tempoUltimaMudanca[1] >= TEMPO_G)
    threadG();
  if(millis()-tempoUltimaMudanca[2] >= TEMPO_B)
    threadB();
  delay(500);

}
