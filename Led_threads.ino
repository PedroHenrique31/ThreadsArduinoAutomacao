/*
  Autor: Pedro Henrique Cerneiro de Araújo        RA:22108287
  Autor: Bruna Stephanie Soares Gonçalves         RA:21707921
*/
// saídas analógicas para o Led
#define pinoR 6
#define pinoG 5
#define pinoB 3

//int pinoR=6,pinoG=5,pinoB=3;
int valoresPinos[]={128,199,64}; 
void setup() {
  pinMode(pinoR,OUTPUT);
  pinMode(pinoG,OUTPUT);
  pinMode(pinoB,OUTPUT);

}

void loop() {
  //static int valoresPinos[]={128,199,64};// pode ser mais interessante fazer disso uma variável global, apesar de feioso.

  analogWrite(pinoR,valoresPinos[0]);
  analogWrite(pinoG,valoresPinos[1]);
  analogWrite(pinoB,valoresPinos[2]);

  valoresPinos[0]=random(0,256);
  valoresPinos[1]=random(0,256);
  valoresPinos[2]=random(0,256);

  delay(500);

}
