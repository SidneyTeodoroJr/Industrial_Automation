#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

// CONFIGURAÇÃO DO ACESSO VIA SOFT AP
/*
const char* ssid     = "HOFFER";
const char* password = "123456789";
*/

//CONFIGURAÇÃO DO ACESSO VIA ROTEADOR
//const char* ssid = "RAFAELFX"; //VARIÁVEL QUE ARMAZENA O NOME DA REDE SEM FIO EM QUE VAI CONECTAR
//const char* password = "box135136"; //VARIÁVEL QUE ARMAZENA A SENHA DA REDE SEM FIO EM QUE VAI CONECTAR

const char* ssid = "rafaelfx"; //VARIÁVEL QUE ARMAZENA O NOME DA REDE SEM FIO EM QUE VAI CONECTAR
const char* password = "box135136"; //VARIÁVEL QUE ARMAZENA A SENHA DA REDE SEM FIO EM QUE VAI CONECTAR
 
//DEFINIÇÃO DE IP FIXO PARA O NODEMCU
IPAddress ip(192,168,1,175); //COLOQUE UMA FAIXA DE IP DISPONÍVEL DO SEU ROTEADOR. EX: 192.168.1.110 **** ISSO VARIA, NO MEU CASO É: 192.168.0.175
IPAddress gateway(192,168,0,1); //GATEWAY DE CONEXÃO (ALTERE PARA O GATEWAY DO SEU ROTEADOR)
IPAddress subnet(255,255,255,0); //MASCARA DE REDE

int saida1 = 4;
int saida2 = 16;
int saida3 = 17;
int saida4 = 18;
int saida5 = 19;
int saida6 = 23;
int entrada1 = 36;
int entrada2 = 39;
int entrada3 = 32;
int entrada4 = 33;
int entrada5 = 25;
int entrada6 = 26;
int entrada7 = 27;
int entrada8 = 14; 
int analog1 = 35;
int analog2 = 34;
int analogica1, analogica2;


// PÁGINA HTML QUE SERÁ ENVIADA AO CLIENTE
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>HOFFE WEBSERVER</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta http-equiv="refresh" content="2">
  <style>
      body { font-family: Arial; text-align: center; margin:0px auto; padding-top: 30px; background-color: #BDBDBD;}
      .button {
        padding: 10px 20px;
        font-size: 24px;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #2f4468;
        border: none;
        border-radius: 5px;
        box-shadow: 0 6px #999;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }  
      .button:hover {background-color: #1f2e45}
      .button:active {
        background-color: #1f2e45;
        box-shadow: 0 4px #666;
        transform: translateY(2px);
      }
      h3 {display: inline;}
    </style>
  <script>
    function submitMessage() {
      alert("Valor Alterado!");
      setTimeout(function(){ document.location.reload(false); }, 500);   
    }
    function toggleCheckbox(x) {
     var xhr = new XMLHttpRequest();
     xhr.open("GET", "/" + x, true);
     xhr.send();
   }
  </script></head><body>
  <H1 style='color:#FF6F00'>HOFFER WEBSERVER</H1>
  <br><br>
  <button class="button" onmousedown="toggleCheckbox('canal1_on');" ontouchstart="toggleCheckbox('canal1_on');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 01 ON</button>
  <button class="button" onmousedown="toggleCheckbox('canal1_off');" ontouchstart="toggleCheckbox('canal1_off');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 01 OFF</button>
  <br><br>
  <button class="button" onmousedown="toggleCheckbox('canal2_on');" ontouchstart="toggleCheckbox('canal2_on');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 02 ON</button>
  <button class="button" onmousedown="toggleCheckbox('canal2_off');" ontouchstart="toggleCheckbox('canal2_off');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 02 OFF</button>
  <br><br>
  <button class="button" onmousedown="toggleCheckbox('canal3_on');" ontouchstart="toggleCheckbox('canal3_on');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 03 ON</button>
  <button class="button" onmousedown="toggleCheckbox('canal3_off');" ontouchstart="toggleCheckbox('canal3_off');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 03 OFF</button>
  <br><br>
  <button class="button" onmousedown="toggleCheckbox('canal4_on');" ontouchstart="toggleCheckbox('canal4_on');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 04 ON</button>
  <button class="button" onmousedown="toggleCheckbox('canal4_off');" ontouchstart="toggleCheckbox('canal4_off');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 04 OFF</button>
  <br><br>
  <button class="button" onmousedown="toggleCheckbox('canal5_on');" ontouchstart="toggleCheckbox('canal5_on');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 05 ON</button>
  <button class="button" onmousedown="toggleCheckbox('canal5_off');" ontouchstart="toggleCheckbox('canal5_off');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 05 OFF</button>
  <br><br>
  <button class="button" onmousedown="toggleCheckbox('canal6_on');" ontouchstart="toggleCheckbox('canal6_on');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 06 ON</button>
  <button class="button" onmousedown="toggleCheckbox('canal6_off');" ontouchstart="toggleCheckbox('canal6_off');" onmouseup="toggleCheckbox('off');" ontouchend="toggleCheckbox('off');">SAIDA 06 OFF</button>
  <br><br><hr>
  <H1 style='color:#3F51B5'>STATUS ENTRADAS DIGITAIS</H1>
  <center>
  <table>
    <tr>
      <td><h3>Entrada 01: </h3></td>
      <td><h3 style='color:blue'>%dado01%</h3></td>
    </tr>
    <tr>
      <td><h3>Entrada 02: </h3></td>
      <td><h3 style='color:blue'>%dado02%</h3></td>
    </tr>
    <tr>
      <td><h3>Entrada 03: </h3></td>
      <td><h3 style='color:blue'>%dado03%</h3></td>
    </tr>
    <tr>
      <td><h3>Entrada 04: </h3></td>
      <td><h3 style='color:blue'>%dado04%</h3></td>
    </tr>
    <tr>
      <td><h3>Entrada 05: </h3></td>
      <td><h3 style='color:blue'>%dado05%</h3></td>
    </tr>
    <tr>
      <td><h3>Entrada 06: </h3></td>
      <td><h3 style='color:blue'>%dado06%</h3></td>
    </tr>
    <tr>
      <td><h3>Entrada 07: </h3></td>
      <td><h3 style='color:blue'>%dado07%</h3></td>
    </tr>
    <tr>
      <td><h3>Entrada 08: </h3></td>
      <td><h3 style='color:blue'>%dado08%</h3></td>
    </tr>
  </table>
  <hr>
  <H1 style='color:#FF0000'>STATUS ENT. ANALOGICAS</H1>
  <center>
  <table>
    <tr>
      <td><h3>Entrada 01: </h3></td>
      <td><h3 style='color:blue'>%dado09%</h3></td>
    </tr>
    <tr>
      <td><h3>Entrada 02: </h3></td>
      <td><h3 style='color:blue'>%dado10%</h3></td>
    </tr>
  </center>
  <iframe style="display:none" name="hidden-form"></iframe>
</body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

String processor(const String &var){
      if (var == "dado01"){
        if(digitalRead(entrada1) == 1){
        return String("LIGADO");
      }else{
        return String("DESLIGADO");
      }
      return String();
    }
    if (var == "dado02"){
        if(digitalRead(entrada2) == 1){
        return String("LIGADO");
      }else{
        return String("DESLIGADO");
      }
      return String();
    }
    if (var == "dado03"){
        if(digitalRead(entrada3) == 1){
        return String("LIGADO");
      }else{
        return String("DESLIGADO");
      }
      return String();
    }
    if (var == "dado04"){
        if(digitalRead(entrada4) == 1){
        return String("LIGADO");
      }else{
        return String("DESLIGADO");
      }
      return String();
    }
    if (var == "dado05"){
        if(digitalRead(entrada5) == 1){
        return String("LIGADO");
      }else{
        return String("DESLIGADO");
      }
      return String();
    }
    if (var == "dado06"){
        if(digitalRead(entrada6) == 1){
        return String("LIGADO");
      }else{
        return String("DESLIGADO");
      }
      return String();
    }
    if (var == "dado07"){
        if(digitalRead(entrada7) == 1){
        return String("LIGADO");
      }else{
        return String("DESLIGADO");
      }
      return String();
    }
    if (var == "dado08"){
        if(digitalRead(entrada8) == 1){
        return String("LIGADO");
      }else{
        return String("DESLIGADO");
      }
      return String();
    }
    if (var == "dado09"){
        return String(analogRead(analog1));
        return String();
      }
    if (var == "dado10"){
        return String(analogRead(analog2));
        return String();
      }
    }

void setup() {
  Serial.begin(115200);
  pinMode(saida1, OUTPUT);
  pinMode(saida2, OUTPUT);
  pinMode(saida3, OUTPUT);
  pinMode(saida4, OUTPUT);
  pinMode(saida5, OUTPUT);
  pinMode(saida6, OUTPUT);

  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);
  pinMode(entrada3, INPUT);
  pinMode(entrada4, INPUT);
  pinMode(entrada5, INPUT);
  pinMode(entrada6, INPUT);
  pinMode(entrada7, INPUT);
  pinMode(entrada8, INPUT);
 // pinMode(analog1, INPUT);
 // pinMode(analog2, INPUT);

  digitalWrite(saida1, LOW);
  digitalWrite(saida2, LOW);
  digitalWrite(saida3, LOW);
  digitalWrite(saida4, LOW);
  digitalWrite(saida5, LOW);
  digitalWrite(saida6, LOW);

  //CONFIGURAÇÃO PARA SOFT AP
/*
  WiFi.softAP(ssid, password);
  Serial.println();
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  */

  //CONFIGURAÇÃO PARA CONEXÃO A ROTEADOR   
  WiFi.begin(ssid, password); //PASSA OS PARÂMETROS PARA A FUNÇÃO QUE VAI FAZER A CONEXÃO COM A REDE SEM FIO
  WiFi.config(ip, gateway, subnet); //PASSA OS PARÂMETROS PARA A FUNÇÃO QUE VAI SETAR O IP FIXO
  while (WiFi.status() != WL_CONNECTED) { //ENQUANTO STATUS FOR DIFERENTE DE CONECTADO
    delay(500); //INTERVALO DE 500 MILISEGUNDOS
    Serial.print("."); //ESCREVE O CARACTER NA SERIAL
    }
  Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL
  Serial.print("Conectado a rede sem fio "); //ESCREVE O TEXTO NA SERIAL
  Serial.println(ssid); //ESCREVE O NOME DA REDE NA SERIAL
  
   // ENVIA PÁGINA PARA CLIENTE
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

    // RECEBE REQUISIÇÃO HTTP GET CANAL 1 ON
  server.on("/canal1_on", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida1, HIGH);
    request->send(200, "text/plain", "ok");
  });

  // RECEBE REQUISIÇÃO HTTP GET CANAL 1 OFF
  server.on("/canal1_off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida1, LOW);
    request->send(200, "text/plain", "ok");
  });

      // RECEBE REQUISIÇÃO HTTP GET CANAL 2 ON
  server.on("/canal2_on", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida2, HIGH);
    request->send(200, "text/plain", "ok");
  });

  // RECEBE REQUISIÇÃO HTTP GET CANAL 2 OFF
  server.on("/canal2_off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida2, LOW);
    request->send(200, "text/plain", "ok");
  });

      // RECEBE REQUISIÇÃO HTTP GET CANAL 3 ON
  server.on("/canal3_on", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida3, HIGH);
    request->send(200, "text/plain", "ok");
  });

  // RECEBE REQUISIÇÃO HTTP GET CANAL 3 OFF
  server.on("/canal3_off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida3, LOW);
    request->send(200, "text/plain", "ok");
  });

      // RECEBE REQUISIÇÃO HTTP GET CANAL 4 ON
  server.on("/canal4_on", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida4, HIGH);
    request->send(200, "text/plain", "ok");
  });

  // RECEBE REQUISIÇÃO HTTP GET CANAL 4 OFF
  server.on("/canal4_off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida4, LOW);
    request->send(200, "text/plain", "ok");
  });

        // RECEBE REQUISIÇÃO HTTP GET CANAL 5 ON
  server.on("/canal5_on", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida5, HIGH);
    request->send(200, "text/plain", "ok");
  });

  // RECEBE REQUISIÇÃO HTTP GET CANAL 5 OFF
  server.on("/canal5_off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida5, LOW);
    request->send(200, "text/plain", "ok");
  });

        // RECEBE REQUISIÇÃO HTTP GET CANAL 6 ON
  server.on("/canal6_on", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida6, HIGH);
    request->send(200, "text/plain", "ok");
  });

  // RECEBE REQUISIÇÃO HTTP GET CANAL 6 OFF
  server.on("/canal6_off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(saida6, LOW);
    request->send(200, "text/plain", "ok");
  });
  
  //MENSAGEM SE SERVIDOR NÃO ENCONTRADO
  server.onNotFound(notFound);

  //INICIALIZA SERVIDOR WEB
  server.begin();
}

void loop() {
  
}
