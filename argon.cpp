#include <charconv>

int moisture1;
int moisture2;
int moisture3;
char moisture1Val[4];
char moisture2Val[4];
char moisture3Val[4];
char buf[15];

void setup() {
    
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    
}

void addVal(int offset, char *buf, char *val) {
    
    for (int i = 0; i < 4; i++) {
        buf[offset+i] = val[i];
    }
    buf[offset+4] = ',';
}

void loop() {

  moisture1 = analogRead(A0);
  moisture2 = analogRead(A1);
  moisture3 = analogRead(A2);

  std::to_chars(moisture1Val, moisture1Val + 4, moisture1);
  std::to_chars(moisture2Val, moisture2Val + 4, moisture2);
  std::to_chars(moisture3Val, moisture3Val + 4, moisture3);
  
  addVal(0, buf, moisture1Val);
  addVal(5, buf, moisture2Val);
  addVal(10, buf, moisture3Val);
  buf[14] = '\0';

  Particle.publish("sensors", buf, PRIVATE);

  delay(1800000);
}