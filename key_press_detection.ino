void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(2) == LOW)
  {
    Serial.println("nokkinav ra bhai:-)");
    digitalWrite(13, HIGH);
    delay(5000);
  }
  // put your main code here, to run repeatedly:
  else
  {
    Serial.println("Nokkudu marshinav ra bai!!!!!!");
    digitalWrite(13, LOW);
  }
}
