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
  valoresPinos[0]=random(0,256);
  analogWrite(pinoR,valoresPinos[0]);
}
void threadG(){
  analogWrite(pinoG,valoresPinos[1]);
  valoresPinos[1]=random(0,256);
}
void threadB(){
  analogWrite(pinoB,valoresPinos[2]);
  valoresPinos[2]=random(0,256);
}

void loop() {
  static int tempoUltimaMudanca[]={0,0,0};
  if(millis()-tempoUltimaMudanca[0] >= TEMPO_R)
    threadR();
  if(millis()-tempoUltimaMudanca[1] >= TEMPO_G)
    threadG();
  if(millis()-tempoUltimaMudanca[2] >= TEMPO_B)
    threadB();
  delay(500);

}
