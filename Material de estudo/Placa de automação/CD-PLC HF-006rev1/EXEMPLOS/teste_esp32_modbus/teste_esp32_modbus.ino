/* TESTE DE COMUNICAÇÃO MODBUS RTU SLAVE
 *  ENVIA VARIAVEIS ATRAVÉS DA REDE 
 *  PARA LEITURA COM O SOFTWARE MODSCAN
 *  ENDEREÇO: 10
 *  VELOCIDADE: 19200BPS
 *  NUMERO BITS: 8
 *  PARIDADE: NÃO
 *  STOP BITS: 2
 *  REGISTROS: 10
 *  
 */

#include <Modbus.h>
#include <ModbusSerial.h>

//TÓPICOS MODBUS
int re_de = 5;
int var1, var2, var3, var4, var5;
ModbusSerial MB_TESTE;

void setup() {
  pinMode(re_de, OUTPUT);
  digitalWrite(re_de, LOW);
  MB_TESTE.config(&Serial, 19200, SERIAL_8N2, 5);   //SEMPRE 5 NO FINAL - PINO RE_DE
  MB_TESTE.setSlaveId(10);

  //DECLARAÇÃO DOS REGISTROS
  MB_TESTE.addHreg(100);    //REGISTRO 100 = ENDEREÇO 101, E ASSIM POR DIANTE
  MB_TESTE.addHreg(101);
  MB_TESTE.addHreg(102);
  MB_TESTE.addHreg(103);
  MB_TESTE.addHreg(104);
  MB_TESTE.addHreg(105);
  MB_TESTE.addHreg(106);
  MB_TESTE.addHreg(107);
  MB_TESTE.addHreg(108);
  MB_TESTE.addHreg(109);
  
 
}

void loop() {
  // ESCREVE NOS REGISTROS DE 1 A 5   
  MB_TESTE.Hreg(100, 1);
  MB_TESTE.Hreg(101, 2);
  MB_TESTE.Hreg(102, 3);
  MB_TESTE.Hreg(103, 4);
  MB_TESTE.Hreg(104, 5);

  // LE REGISTROS DE 6 A 10
  var1 = MB_TESTE.Hreg(105);
  var2 = MB_TESTE.Hreg(106);
  var3 = MB_TESTE.Hreg(107);
  var4 = MB_TESTE.Hreg(108);
  var5 = MB_TESTE.Hreg(109);
  MB_TESTE.task();

}
