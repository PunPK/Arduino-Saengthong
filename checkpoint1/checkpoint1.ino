// ประกาศหมายเลขขาของเซนเซอร์และ LED
int trigPin = 11;   // ขาที่ใช้ส่งเสียงออก
int echoPin = 10;   // ขาที่รับเสียงสะท้อนกลับ

void setup() {
  pinMode(trigPin, OUTPUT);  // ตั้งค่าให้ขา trig เป็นขาออก
  pinMode(echoPin, INPUT);   // ตั้งค่าให้ขา echo เป็นขารับข้อมูล

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

  delay(100);  // รอ 0.1 วินาที แล้วเริ่มวัดใหม่
}
