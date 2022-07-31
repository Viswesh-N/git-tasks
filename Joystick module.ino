#define M1_SENS 2
#define M1_INT 0

#define M2_SENS 3
#define M2_INT 0

volatile int count1 = 0;
volatile int count2 = 0;

int X=0;
int Y=0;
int OX=0;
int OY=0;
unsigned long timeold = 0;
int rpm1;
int rpm2;

void setup() 
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(12, OUTPUT);
  
  pinMode(M1_SENS, INPUT);
  attachInterrupt(M1_INT, motorStep1, RISING);

  pinMode(M2_SENS, INPUT);
  attachInterrupt(M2_INT, motorStep2, RISING);
  
  Serial.begin(9600);
}

void loop() 
{
  if (millis() - timeold >= 1000)
  {  
      noInterrupts();
  }
  timeold = millis(); 

  digitalWrite(12, HIGH);
  X = analogRead(A0);
  Y = analogRead(A1);
  OX = map(X,0,1023,-255,255);
  OY = map(Y,0,1023,-255,255);
  
  if(OX>0 && OY >0)
  {
  	analogWrite( 10, OX );
  	analogWrite( 11, OY );
    digitalWrite( 5, LOW);
    digitalWrite( 6, LOW);
  }
  
  else if(OX<0 && OY >0)
  {
  	analogWrite( 5, -OX );
  	analogWrite( 11, OY );
    digitalWrite( 10, LOW);
    digitalWrite( 6, LOW);
  }
  
  else if(OX<0 && OY <0)
  {
  	analogWrite( 5, -OX );
  	analogWrite( 6, -OY );
    digitalWrite( 10, LOW);
    digitalWrite( 11, LOW);
  }
  
  else if(OX>0 && OY <0)
  {
  	analogWrite( 10, OX );
  	analogWrite( 6, -OY );
    digitalWrite( 5, LOW);
    digitalWrite( 11, LOW);
  }
  
  else
  {
    digitalWrite( 5, LOW);
    digitalWrite( 6, LOW);
    digitalWrite( 10, LOW);
    digitalWrite( 11, LOW);
  }

  rpm1 = (60 * 1000 / 21 )/ (millis() - timeold)* count1; 
  rpm2 = (60 * 1000 / 21 )/ (millis() - timeold)* count2; 

  Serial.println(rpm1);
  Serial.print(" | ");
  Serial.print(rpm2);

  count1=0;
  count2=0;
  
  //Serial.print("X-axis: ");
  //Serial.print(analogRead(A0));
  //Serial.print(" | ");
  //Serial.print("Y-axis: ");
  //Serial.print(analogRead(A1));
  //Serial.print(" | ");
  //Serial.print(OX);
  //Serial.print(" | ");
  //Serial.print(OY);
  //Serial.println(" | ");
  delay(50);
  
}

void motorStep1()
{
  count1++;
  //Serial.println(count1);
}

void motorStep2()
{
  count2++;
  //Serial.println(count2);
}