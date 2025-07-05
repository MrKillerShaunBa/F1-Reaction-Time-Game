int led1 = D0;
int led2 = D1;
int led3 = D2;
int led4 = D3;
int led5 = D4;

int p1 = D5;
int p2 = D6;
int p3 = D7;
int p4 = D8;

int winner = -1;
bool gameStarted = false;
bool winnerFound = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(p1, INPUT_PULLUP);
  pinMode(p2, INPUT_PULLUP);
  pinMode(p3, INPUT_PULLUP);
  pinMode(p4, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(p1), p1Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(p1), p2Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(p3), p1Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(p4), p2Pressed, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);

  digitalWrite(led1,HIGH);
  delay(random(200,3000));
  digitalWrite(led2,HIGH);
  delay(random(200,3000));
  digitalWrite(led3,HIGH);
  delay(random(200,3000));
  digitalWrite(led4,HIGH);
  delay(random(200,3000));
  digitalWrite(led5,HIGH);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  gameStarted = true;
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);

   while (!winnerFound) {
    // wait
  }
  delay(1000);
  if (winner == 1){digitalWrite(led1,HIGH);}
  if (winner == 2){digitalWrite(led2,HIGH);}
  if (winner == 3){digitalWrite(led3,HIGH);}
  if (winner == 4){digitalWrite(led4,HIGH);}
  delay(3000);
  gameStarted = false;
  winnerFound = false;
  winner = -1;
}
void p1Pressed() {
  if (!gameStarted || winnerFound) return;
  winner = 1;
  winnerFound = true;
}
void p2Pressed() {
  if (!gameStarted || winnerFound) return;
  winner = 2;
  winnerFound = true;
}
void p3Pressed() {
  if (!gameStarted || winnerFound) return;
  winner = 3;
  winnerFound = true;
}
void p4Pressed() {
  if (!gameStarted || winnerFound) return;
  winner = 4;
  winnerFound = true;
}
