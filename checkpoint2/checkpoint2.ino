// ประกาศหมายเลขขาของเซนเซอร์และ LED
int trigPin = 11;   // ขาที่ใช้ส่งเสียงออก
int echoPin = 10;   // ขาที่รับเสียงสะท้อนกลับ
int ledPin1 = 8;     // ขาที่ต่อกับหลอดไฟ LED
int ledPin2 = 7;     // ขาที่ต่อกับหลอดไฟ LED
int ledPin3 = 6;     // ขาที่ต่อกับหลอดไฟ LED
void setup() {
  pinMode(trigPin, OUTPUT);  // ตั้งค่าให้ขา trig เป็นขาออก
  pinMode(echoPin, INPUT);   // ตั้งค่าให้ขา echo เป็นขารับข้อมูล
  pinMode(ledPin1, .....);   // ตั้งค่าให้ขา LED เป็นขาออก
  pinMode(ledPin2, .....);   // ตั้งค่าให้ขา LED เป็นขาออก
  pinMode(ledPin3, .....);   // ตั้งค่าให้ขา LED เป็นขาออก
  Serial.begin(9600);        // เริ่มต้นการส่งข้อมูลไปยังหน้าจอ Serial Monitor
}

void loop() {
  // เริ่มการวัดระยะ
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);       // เริ่มจากส่งสัญญาณต่ำก่อน
  delayMicroseconds(2);             // รอ 2 ไมโครวินาที
  digitalWrite(trigPin, HIGH);      // ส่งสัญญาณสูง (คลื่นเสียง)
  delayMicroseconds(10);            // รอ 10 ไมโครวินาที
  digitalWrite(trigPin, LOW);       // หยุดส่งสัญญาณ

  duration = pulseIn(echoPin, HIGH);    // วัดระยะเวลาที่เสียงสะท้อนกลับมา
  distance = duration / 58;             // แปลงระยะเวลาเป็นระยะทาง (หน่วยเซนติเมตร)
  // แสดงผลระยะทางบน Serial Monitor
  Serial.print("ระยะทาง: ");
  Serial.print(distance);
  Serial.println(" ซม.");

if (distance < 10) {
  // วัตถุอยู่ใกล้มาก → เปิด led1 สีแดง
  digitalWrite(ledPin1, .....);
  digitalWrite(ledPin2, .....);
  digitalWrite(ledPin3, .....);

} else if (distance < 25) {
  // วัตถุอยู่ใกล้ปานกลาง → เปิด led2 สีเหลือง
  digitalWrite(ledPin1, .....);
  digitalWrite(ledPin2, .....);
  digitalWrite(ledPin3, .....);

} else if (distance < 50) {
  // วัตถุเริ่มเข้าใกล้ → เปิด led3 สีเขียว
  digitalWrite(ledPin1, .....);
  digitalWrite(ledPin2, .....);
  digitalWrite(ledPin3, .....);
} else {
  // วัตถุอยู่ไกล →  ปิดทุกดวง
  digitalWrite(ledPin1, .....);
  digitalWrite(ledPin2, .....);
  digitalWrite(ledPin3, .....);
}
  delay(100);  // รอ 0.1 วินาที แล้วเริ่มวัดใหม่
}
