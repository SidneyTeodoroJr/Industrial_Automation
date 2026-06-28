
/* Teste das entradas digitais
 * Lê o status das entradas e
 * Escreve na porta serial
 * Velocidade Serial: 115200bps
 */

int Entrada_01 = 36;
int Entrada_02 = 39;
int Entrada_03 = 32;
int Entrada_04 = 33;
int Entrada_05 = 25;
int Entrada_06 = 26;
int Entrada_07 = 27;
int Entrada_08 = 14;

void setup() {
  Serial.begin(115200);
  pinMode(Entrada_01, INPUT);
  pinMode(Entrada_02, INPUT);
  pinMode(Entrada_03, INPUT);
  pinMode(Entrada_04, INPUT);
  pinMode(Entrada_05, INPUT);
  pinMode(Entrada_06, INPUT);
  pinMode(Entrada_07, INPUT);
  pinMode(Entrada_08, INPUT);
}

void loop() {
  Serial.println("Entrada 01= " + String(digitalRead(Entrada_01)));
  Serial.println("Entrada 02= " + String(digitalRead(Entrada_02)));
  Serial.println("Entrada 03= " + String(digitalRead(Entrada_03)));
  Serial.println("Entrada 04= " + String(digitalRead(Entrada_04)));
  Serial.println("Entrada 05= " + String(digitalRead(Entrada_05)));
  Serial.println("Entrada 06= " + String(digitalRead(Entrada_06)));
  Serial.println("Entrada 07= " + String(digitalRead(Entrada_07)));
  Serial.println("Entrada 08= " + String(digitalRead(Entrada_08)));
  Serial.println("----------------------------------------");
  delay(1000);

}
