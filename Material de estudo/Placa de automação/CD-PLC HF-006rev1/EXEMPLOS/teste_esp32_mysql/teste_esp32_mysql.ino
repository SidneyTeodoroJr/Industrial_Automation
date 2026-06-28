#include <WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

IPAddress server_addr(xxx, xxx, xxx, xxx);  // IP address of the MySQL server
char user[] = "username";                    // MySQL username
char password[] = "password";                // MySQL password

WiFiClient client;
MySQL_Connection conn((Client *)&client);

void setup() {
  Serial.begin(9600);
  WiFi.begin("ssid", "password");            // Wi-Fi SSID and password
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  Serial.println("Connected to Wi-Fi");
  if (conn.connect(server_addr, 3306, user, password)) {
    Serial.println("Connected to MySQL server");
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  char query[128];
  strcpy(query, "SELECT * FROM mytable");
  cur_mem->execute(query);
  do {
    MySQL_Row *row = cur_mem->get_next_row();
    if (row != NULL) {
      Serial.print(row->get_string(0));
      Serial.print("\t");
      Serial.print(row->get_string(1));
      Serial.print("\t");
      Serial.println(row->get_string(2));
    }
  } while (cur_mem->has_next_row());
  delete cur_mem;
  delay(5000);
}
