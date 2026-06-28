/*Teste Entradas Analógicas
 * Lê o valor das entradas e 
 * Escreve na porta serial
 * ENTRADAS SÃO 0-10 V
 * Velocidade serial: 115200bps
 */

int Analogica_1 = 34;
int Analogica_2 = 35;

void setup() {
  Serial.begin(115200);

}

void loop() {
  Serial.println("Valor analógica 1= " + String(analogRead(Analogica_1)));
  Serial.println("Valor analógica 2= " + String(analogRead(Analogica_2)));
  Serial.println("-------------------------------");
  delay(1000);

}
