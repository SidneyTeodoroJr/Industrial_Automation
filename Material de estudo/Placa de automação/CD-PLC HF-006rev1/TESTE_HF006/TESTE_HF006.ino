
int ENTRADA_1 = 36;
int ENTRADA_2 = 39;
int ENTRADA_3 = 32;
int ENTRADA_4 = 33;
int ENTRADA_5 = 25;
int ENTRADA_6 = 26;
int ENTRADA_7 = 27;
int ENTRADA_8 = 14;

int SAIDA_1 = 4;
int SAIDA_2 = 16;
int SAIDA_3 = 17;
int SAIDA_4 = 18;
int SAIDA_5 = 19;
int SAIDA_6 = 23;


void setup() {
  // put your setup code here, to run once:
  pinMode(ENTRADA_1, INPUT);
  pinMode(ENTRADA_2, INPUT);
  pinMode(ENTRADA_3, INPUT);
  pinMode(ENTRADA_4, INPUT);
  pinMode(ENTRADA_5, INPUT);
  pinMode(ENTRADA_6, INPUT);
  pinMode(ENTRADA_7, INPUT);
  pinMode(ENTRADA_8, INPUT);

  pinMode(SAIDA_1, OUTPUT);
  pinMode(SAIDA_2, OUTPUT);
  pinMode(SAIDA_3, OUTPUT);
  pinMode(SAIDA_4, OUTPUT);
  pinMode(SAIDA_5, OUTPUT);
  pinMode(SAIDA_6, OUTPUT);

  digitalWrite(SAIDA_1, HIGH);
  delay(500);
  digitalWrite(SAIDA_2, HIGH);
  delay(500);
  digitalWrite(SAIDA_3, HIGH);
  delay(500);
  digitalWrite(SAIDA_4, HIGH);
  delay(500);
  digitalWrite(SAIDA_5, HIGH);
  delay(500);
  digitalWrite(SAIDA_6, HIGH);
  delay(500);
  digitalWrite(SAIDA_1, LOW);
  digitalWrite(SAIDA_2, LOW);
  digitalWrite(SAIDA_3, LOW);
  digitalWrite(SAIDA_4, LOW);
  digitalWrite(SAIDA_5, LOW);
  digitalWrite(SAIDA_6, LOW);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ENTRADA_1) == 1){
    digitalWrite(SAIDA_1, HIGH);
  }
  if(digitalRead(ENTRADA_2) == 1){
    digitalWrite(SAIDA_2, HIGH);
  }
  if(digitalRead(ENTRADA_3) == 1){
    digitalWrite(SAIDA_3, HIGH);
  }
  if(digitalRead(ENTRADA_4) == 1){
    digitalWrite(SAIDA_4, HIGH);
  }
  if(digitalRead(ENTRADA_5) == 1){
    digitalWrite(SAIDA_5, HIGH);
  }
  if(digitalRead(ENTRADA_6) == 1 || digitalRead(ENTRADA_7) == 1 || digitalRead(ENTRADA_8) == 1 ){
    digitalWrite(SAIDA_6, HIGH);
  }
  else{
    digitalWrite(SAIDA_6, LOW);
  }
}
