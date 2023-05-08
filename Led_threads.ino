/*
  Autor: Pedro Henrique Cerneiro de Araújo        RA:22108287
  Autor: Bruna Stephanie Soares Gonçalves         RA:21707921
*/

int pinoR=6,pinoG=5,pinoB=3; // saídas analógicas para o Led
void setup() {
  pinMode(pinoR,OUTPUT);
  pinMode(pinoG,OUTPUT);
  pinMode(pinoB,OUTPUT);

}

void loop() {
  int valoresPinos[]={128,199,64};

  analogWrite(pinoR,valoresPinos[0]);
  analogWrite(pinoG,valoresPinos[1]);
  analogWrite(pinoB,valoresPinos[2]);

}
