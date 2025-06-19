#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 53
#define BUZZER_PIN 4
#define LED1_PIN 3
#define LED2_PIN 2

MFRC522 mfrc522(SS_PIN, RST_PIN); // สร้างอ็อบเจกต์ MFRC522

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  
  Serial.println("Ready to scan RFID...");
}

void loop() {
  // ตรวจสอบว่ามีการ์ดให้สแกนหรือไม่
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // อ่าน UID แล้วแสดงบน Serial Monitor
  byte *uid = mfrc522.uid.uidByte;
  byte uidLength = mfrc522.uid.size;

  Serial.print("UID Tag : ");
  for (byte i = 0; i < uidLength; i++) {
    Serial.print(uid[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // ตรวจสอบ UID ที่ต้องการ
  if (uidLength == 4 &&
      uid[0] == 0x43 && uid[1] == 0x10 &&
      uid[2] == 0x99 && uid[3] == 0x12) {
    
    // กรณี: UID = 43 10 99 12
    digitalWrite(LED1_PIN, HIGH); // เปิดไฟที่ pin 3
    tone(BUZZER_PIN, 1000);       // เสียง buzzer
    delay(1000);                  // นาน 1 วินาที
    noTone(BUZZER_PIN);
    digitalWrite(LED1_PIN, LOW);

  } else if (uidLength == 4 &&
             uid[0] == 0x93 && uid[1] == 0x20 &&
             uid[2] == 0x9F && uid[3] == 0xFA) {
    
    // กรณี: UID = 93 20 9F FA
    digitalWrite(LED2_PIN, HIGH); // เปิดไฟที่ pin 2
    for (int i = 0; i < 2; i++) {
      tone(BUZZER_PIN, 1500);
      delay(300);
      noTone(BUZZER_PIN);
      delay(200);
    }
    digitalWrite(LED2_PIN, LOW);
  }

  mfrc522.PICC_HaltA(); // หยุดอ่านการ์ด
}
