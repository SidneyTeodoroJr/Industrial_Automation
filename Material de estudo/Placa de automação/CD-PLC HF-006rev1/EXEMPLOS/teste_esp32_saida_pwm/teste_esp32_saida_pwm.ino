/*TESTE DA SAÍDA PWM
 * Varia a saída PWM 
 * de 0 a 255 e depois
 * de 255 a 0 usando
 * comando ledc
 */

int Saida_PWM = 15;
int frequencia = 1000;
int canal = 0;
int resolucao = 8;

void setup() {
  ledcSetup(canal, frequencia, resolucao);
  ledcAttachPin(Saida_PWM, canal);

}

void loop() {
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    ledcWrite(canal, dutyCycle);
    delay(5);
  }
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(canal, dutyCycle);   
    delay(5);
}
}
