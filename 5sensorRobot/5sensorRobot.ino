// 5 sensör ile basit çizgi izleyen robot kodu.
// Made by Emir Bilal Nayman

// Sensör Pinleri
#define S1 A5
#define S2 A4
#define S3 A3
#define S4 A2
#define S5 A1

//Motor Pinleri
#define ENB 10
#define ENA 9
#define N1 4
#define N2 5
#define N3 2
#define N4 3

void setup() {
}

void loop() {
  // Sensörden aldığımız verileri değişkenlere kaydediyoruz.
  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);
  
  if(s3 == 0){ // Ortadaki sensörümüz çizgiyi görürse iki motoru eş kuvvet ve yön ile çalıştırıyoruz.
    digitalWrite(N1, HIGH);
    digitalWrite(N2, LOW);
    digitalWrite(N3, HIGH);
    digitalWrite(N4, LOW);

    analogWrite(ENA, 200); // Hız değeri.
    analogWrite(ENB, 200); // Hız değeri.
  }
  else if(s4 == 0){ // Yakın-Sağ sensörümüz çizgiyi görürse sağ motoru düşük kuvvet ile çalıştırarak aracın sağa dönmesini sağlıyoruz.
    digitalWrite(N1, HIGH);
    digitalWrite(N2, LOW);
    digitalWrite(N3, HIGH);
    digitalWrite(N4, LOW);

    analogWrite(ENA, 200); // Hız değeri.
    analogWrite(ENB, 150); // Hız değeri, diğer motordan düşük olmalı.
  }
  else if(s2 == 0){ // Yakın-Sol sensörümüz çizgiyi görürse sol motoru düşük kuvvet ile çalıştırarak aracın sola dönmesini sağlıyoruz.
    digitalWrite(N1, HIGH);
    digitalWrite(N2, LOW);
    digitalWrite(N3, HIGH);
    digitalWrite(N4, LOW);

    analogWrite(ENA, 150); // Hız değeri, diğer motordan düşük olmalı.
    analogWrite(ENB, 200); // Hız değeri.
  }
  else if(s5 == 0){ // Uzak-Sağ sensörümüz çizgiyi görürse motorları ters yönde çalıştırarak aracın sağa keskin dönüş yapmasını sağlıyoruz.
    digitalWrite(N1, LOW);
    digitalWrite(N2, HIGH);
    digitalWrite(N3, HIGH);
    digitalWrite(N4, LOW);

    analogWrite(ENA, 200); //Hız değeri.
    analogWrite(ENB, 200); //Hız değeri.
  }
  else if(s1 == 0){ // Uzak-Sol sensörümüz çizgiyi görürse motorları ters yönde çalıştırarak aracın sola keskin dönüş yapmasını sağlıyoruz.
    digitalWrite(N1, HIGH);
    digitalWrite(N2, LOW);
    digitalWrite(N3, LOW);
    digitalWrite(N4, HIGH);

    analogWrite(ENA, 200); //Hız değeri.
    analogWrite(ENB, 200); //Hız değeri.
  }
  
}
