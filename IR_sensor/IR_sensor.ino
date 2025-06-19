#define IR_SENSOR_PIN 7   // ขาที่ต่อสัญญาณ OUT ของเซนเซอร์ IR
#define LED_GREEN 3       // ขาไฟเขียว
#define LED_RED 2         // ขาไฟแดง

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  Serial.begin(9600);
  Serial.println("กำลังตรวจจับวัตถุด้วยเซนเซอร์ IR...");
}

void loop() {
  int state = digitalRead(IR_SENSOR_PIN);  // อ่านค่าจากเซนเซอร์

  if (state == LOW) {
    // ตรวจจับวัตถุได้ (เซนเซอร์ส่วนใหญ่จะให้ค่า LOW เมื่อมีวัตถุ)
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
    Serial.println("ตรวจจับวัตถุแล้ว!");
  } else {
    // ไม่มีวัตถุ
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    Serial.println("ไม่มีวัตถุ");
  }

  delay(200);  // หน่วงเวลาเล็กน้อยเพื่อความเสถียร
}