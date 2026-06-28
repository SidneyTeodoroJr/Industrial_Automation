// EXEMPLO DE CRONOMETRO
//NÃO USAR A FUNÇÃO delay()

long SEGUNDOS = 0;
long SEGUNDOS_DESLIGADO = 0;
long MILISEGUNDOS = 0;
long SOBRA = 0;

int MINUTOS_DESLIGADO = 0;
bool PULSO_1S = 0;

int ENTRADA_01 = 36;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ENTRADA_01, INPUT);
}


void loop() {

//GERA PULSO DE 1S COM PRECISÃO
if((millis() - MILISEGUNDOS) > 1000){
  PULSO_1S = 1;
  SOBRA = SOBRA + (millis() - MILISEGUNDOS - 1000);
  while (SOBRA > 1000){
    SEGUNDOS++;
    SOBRA = SOBRA - 1000;
  }
  SEGUNDOS++;
  MILISEGUNDOS = millis();
}else{
  PULSO_1S = 0;
}

// CONTAGEM DE SEGUNDOS E MINUTOS QUANDO ENTRADA 1 = 0
if((digitalRead(ENTRADA_01) == 0) && (PULSO_1S == 1)){
  SEGUNDOS_DESLIGADO++;
  if (SEGUNDOS_DESLIGADO == 60){
    MINUTOS_DESLIGADO++;
    SEGUNDOS_DESLIGADO = 0;
    }
  }
  
if (digitalRead(ENTRADA_01) == 1){
  SEGUNDOS_DESLIGADO = 0;
  MINUTOS_DESLIGADO = 0;
}

Serial.println("Minutos Desligado = " + String(MINUTOS_DESLIGADO));
Serial.println("Segundos Desligado = " + String(SEGUNDOS_DESLIGADO));
Serial.println("----------------------------");
}
