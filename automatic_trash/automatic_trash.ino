#include <Servo.h>      // เรียกใช้ไลบรารีควบคุม Servo

Servo myservo;          // สร้างตัวแปรสำหรับควบคุม Servo
int trigPin = 11;   // ขาที่ใช้ส่งเสียงออก
int echoPin = 10;   // ขาที่รับเสียงสะท้อนกลับ
int ledPin1 = 8;     // ขาที่ต่อกับหลอดไฟ LED
int ledPin2 = 7;     // ขาที่ต่อกับหลอดไฟ LED
int ledPin3 = 6;     // ขาที่ต่อกับหลอดไฟ LED

void setup() {
  pinMode(trigPin, OUTPUT);  // ตั้งค่าให้ขา trig เป็นขาออก
  pinMode(echoPin, INPUT);   // ตั้งค่าให้ขา echo เป็นขารับข้อมูล
  pinMode(ledPin1, OUTPUT);   // ตั้งค่าให้ขา LED เป็นขาออก
  pinMode(ledPin2, OUTPUT);   // ตั้งค่าให้ขา LED เป็นขาออก
  pinMode(ledPin3, OUTPUT);   // ตั้งค่าให้ขา LED เป็นขาออก

  myservo.attach(3);          // กำหนดให้ Servo ใช้ขา 3
  myservo.write(0);           // เริ่มต้นหมุน Servo ที่ 0 องศา

  Serial.begin(9600);         // เริ่มต้นการส่งข้อมูล Serial
}

void loop() {
  long duration;
  int distance;

  // ส่งสัญญาณ Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // รับสัญญาณกลับ และคำนวณระยะ
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;

  // แสดงผลระยะทาง
  Serial.print("ระยะทาง: ");
  Serial.print(distance);
  Serial.println(" ซม.");

  if (distance < 10) {
  // วัตถุอยู่ใกล้มาก → เปิดทุกดวง
  myservo.write(55); 
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  // delay(3000);

} else if (distance < 25) {
  // วัตถุอยู่ใกล้ปานกลาง → เปิด 2 ดวง
  myservo.write(0);  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);

} else if (distance < 50) {
  // วัตถุเริ่มเข้าใกล้ → เปิดแค่ดวงแรก
  myservo.write(0);  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);

} else {
  // วัตถุอยู่ไกล → ปิดทุกดวง
  myservo.write(0); 
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

  delay(100);  // รอ 1 วินาที ก่อนเริ่มวัดใหม่
}
