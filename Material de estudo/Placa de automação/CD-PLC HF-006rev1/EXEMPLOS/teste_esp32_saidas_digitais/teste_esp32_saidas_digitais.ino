/*  exemplo de escritas nas saidas digitais
 *   
 *   As saidas são acionadas sequencialmente
 *   1 a 1 a cada segundo
 *   
 */

int saida_1 = 4;
int saida_2 = 16;
int saida_3 = 17;
int saida_4 = 18;
int saida_5 = 19;
int saida_6 = 23;


void setup() {
  pinMode(saida_1, OUTPUT);
  pinMode(saida_2, OUTPUT);
  pinMode(saida_3, OUTPUT);
  pinMode(saida_4, OUTPUT);
  pinMode(saida_5, OUTPUT);
  pinMode(saida_6, OUTPUT);

}

void loop() {
  digitalWrite(saida_1, HIGH);
  delay(1000);
  digitalWrite(saida_2, HIGH);
  delay(1000);
  digitalWrite(saida_3, HIGH);
  delay(1000);
  digitalWrite(saida_4, HIGH);
  delay(1000);
  digitalWrite(saida_5, HIGH);
  delay(1000);
  digitalWrite(saida_6, HIGH);
  delay(1000);
  digitalWrite(saida_1, LOW);
  digitalWrite(saida_2, LOW);
  digitalWrite(saida_3, LOW);
  digitalWrite(saida_4, LOW);
  digitalWrite(saida_5, LOW);
  digitalWrite(saida_6, LOW);
  delay(1000);

}
