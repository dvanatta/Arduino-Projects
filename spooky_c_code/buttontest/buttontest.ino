int switchState2 = 0;
int switchState7 = 0;
int all_flag = 0;
int light5 = 1;
int light4 = 1;
int light3 = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
}

void fiesta_mode() {
  if (light3 == HIGH) {
    light4 = HIGH;
    light3 = LOW;
  }
  else if (light4 == HIGH) {
    light5 = HIGH;
    light4 = LOW;
  }
  else{
    light3 = HIGH;
    light5 = LOW;
  }
  delay(100);
  digitalWrite(3, light3);
  digitalWrite(4, light4);
  digitalWrite(5, light5);
}

void allOff(){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
void allOn(){
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

void loop() {
  switchState2 = digitalRead(2);
  switchState7 = digitalRead(7);

  if (switchState7 == HIGH){
    if (all_flag == 1) {
      all_flag = 0;
    }
    else{
      all_flag = 1;
    }
    delay(200);
  }
  
  if (switchState2 == HIGH) {
    fiesta_mode();
    }
  else if (all_flag == 1) {
    allOn();
  }
  else{
    allOff();
  }
  }
  


