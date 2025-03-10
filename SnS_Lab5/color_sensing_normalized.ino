const int red = 3;
const int green = 5;
const int blue = 6;
const int photores = A7;
const int del = 100;
const int val = 250;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photores, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  // Serial.println("RED, GREEN, BLUE");
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(red, val);
  delay(del);
  Serial.print("RED:");
  Serial.print(analogRead(photores));
  Serial.print(",");
  analogWrite(red, 0);

  analogWrite(green, val);
  delay(del);
  Serial.print("GREEN:");
  Serial.print(1.3*analogRead(photores));
  Serial.print(",");
  analogWrite(green, 0);

  analogWrite(blue, val);
  delay(del);
  Serial.print("BLUE:");
  Serial.print(1.5*analogRead(photores));
  Serial.print(",");
  analogWrite(blue, 0);

  analogWrite(red, val);
  analogWrite(green, val);
  analogWrite(blue, val);
  delay(del);
  Serial.print("WHITE:");
  Serial.println(analogRead(photores));
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}
