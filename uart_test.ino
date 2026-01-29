void setup() {
  Serial.begin(115200);              // USB serial (monitor)
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // UART2: RX=16, TX=17

  Serial.println("UART Loopback Test Started");
}

void loop() {
  // Send message
  Serial2.println("Hello from ESP32");

  delay(500);

  // Check if data received
  if (Serial2.available()) {
    String received = Serial2.readString();
    Serial.print("Received: ");
    Serial.println(received);
  }

  delay(2000);
}
