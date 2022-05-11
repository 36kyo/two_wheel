// attatchinterrupt

#define ENC_A_0 2
#define ENC_B_0 4
#define ENC_A_1 3
#define ENC_B_1 5

volatile int16_t enc0 = 0;
volatile int16_t enc1 = 0;
uint32_t msCount = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ENC_A_0, INPUT_PULLUP);
  pinMode(ENC_B_0, INPUT_PULLUP);
  pinMode(ENC_A_1, INPUT_PULLUP);
  pinMode(ENC_B_1, INPUT_PULLUP);
  
  // A相が上がったら(pullupで逆 落ちたらトリガー)
  attachInterrupt(digitalPinToInterrupt(ENC_A_0), encCount0, FALLING);
  attachInterrupt(digitalPinToInterrupt(ENC_A_1), encCount1, FALLING);
  
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // serial debug print ------------------------
  uint32_t now = millis();
  if( now - msCount >= 100){ // [ms]
    Serial.println(String(enc0) + "\t" + String(enc1));
    msCount = now;
  }
  // serial debug print ------------------------
  //--------------------------------------------
}

// encoder count -------------------------------
// A相が上がるときに、
// B相がLOWなら正回転、B相がHIGHなら逆回転
// pullupで逆 highで +1 lowで-1
void encCount0(){
  enc0 += (digitalRead(ENC_B_0) == HIGH) ? 1 : -1;
}
void encCount1(){
  enc1 += (digitalRead(ENC_B_1) == HIGH) ? 1 : -1;
}
// encoder count -------------------------------