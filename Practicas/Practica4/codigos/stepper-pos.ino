int subpaso = 0;
int pos = 0;
int retraso = 5;
int inst;
const int m1 = 10;
const int m2 = 11;
const int m3 = 12;
const int m4 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);}

void loop() {
  if (Serial.available()) {
    inst = Serial.readString().toInt();
    Serial.println(inst);}
  if (inst < pos)
    retroceder_paso();
  if (inst > pos)
    avanzar_paso();}

void avanzar_paso(){
  switch(subpaso){
    case 0:
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      delay(retraso);
      break;
    case 1:
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
      delay(retraso);
      break;
    case 2:
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
      delay(retraso);
      break;
    case 3:
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      delay(retraso);
      break;}
  subpaso++;
  subpaso = subpaso%4;
  pos++;}

void retroceder_paso(){
  switch(subpaso){
    case 2:
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      delay(retraso);
      break;
    case 3:
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
      delay(retraso);
      break;
    case 0:
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
      delay(retraso);
      break;
    case 1:
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      delay(retraso);
      break;}
  subpaso--;
  subpaso = (subpaso + 4)%4;
  pos--;}
