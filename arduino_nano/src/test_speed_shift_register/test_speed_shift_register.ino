// https://3d-diy.ru/wiki/components/sdvigovye-registry/

#define DATA_PIN    10 // пин данных
#define LATCH_PIN   11 // пин защелки
#define CLOCK_PIN   12 // пин тактов синхронизации

byte b[6] = {         // байты, который будут последовательно циклически выводиться в регистре
  0b00000000,
  0b11111111,
  0b11110000,
  0b00001111,
  0b10101010,
  0b01010101,
};

void setup() {
  pinMode(DATA_PIN, OUTPUT);    // инициализация пинов
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  digitalWrite(LATCH_PIN, HIGH);

  // test speed => out_595_shift~= 0,1 ms
  Serial.begin(9600);
  unsigned long int t = millis();
  for (int i = 0; i<10000; i++) {
    out_595_shift(i);
  }
  Serial.println(millis()-t); // 1076
}

void loop() {
  static byte i = 0;
  out_595_shift(b[i]);          // передача байта на регистр
  i = i == 5 ? 0 : i + 1;       // подготовка следующего байта
  delay(1000);                  // задержка между установками 1 сек
}

void out_595_shift(byte x) {
  digitalWrite(LATCH_PIN, LOW);               // "открываем защелку"
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, x); // отправляем данные
  digitalWrite(LATCH_PIN, HIGH);              // "закрываем защелку", выходные ножки регистра установлены
}
