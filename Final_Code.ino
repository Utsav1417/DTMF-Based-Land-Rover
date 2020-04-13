#define M1 5     
#define M2 6
#define M3 7
#define M4 8
#define B  4
#define L2 3
#define L1 2
#define OE 9
#define M5 10
#define M6 11
#define M7 12
#define M8 13


#define I1 19
#define I2 18
#define I3 17
#define I4 16

const int trigPin = 15;
const int echoPin = 14;

long duration;
int distance;



void forward()
{
   digitalWrite(M1, HIGH);
   digitalWrite(M2, LOW);
   digitalWrite(M3, HIGH);
   digitalWrite(M4, LOW);
   digitalWrite(B,  LOW);
   digitalWrite(L2, LOW);
   digitalWrite(L1, LOW);
   digitalWrite(OE, HIGH);
   digitalWrite(M5, HIGH);
   digitalWrite(M6, LOW);
   digitalWrite(M7, HIGH);
   digitalWrite(M8, LOW);
}

void backward()
{
   
   digitalWrite(M1, LOW);
   digitalWrite(M2, HIGH);
   digitalWrite(M3, LOW);
   digitalWrite(M4, HIGH);
   digitalWrite(B,  LOW);
   digitalWrite(L2, LOW);
   digitalWrite(L1, LOW);
   digitalWrite(OE, HIGH);
   digitalWrite(M5, LOW);
   digitalWrite(M6, HIGH);
   digitalWrite(M7, LOW);
   digitalWrite(M8, HIGH);
}

void left()
{
   
   digitalWrite(M1, HIGH);
   digitalWrite(M2, LOW);
   digitalWrite(M3, LOW);
   digitalWrite(M4, HIGH);
   digitalWrite(B,  LOW);
   digitalWrite(L2, LOW);
   digitalWrite(L1, HIGH);
   digitalWrite(OE, HIGH);
   digitalWrite(M5, HIGH);
   digitalWrite(M6, LOW);
   digitalWrite(M7, HIGH);
   digitalWrite(M8, LOW);
}

void right()
{
   digitalWrite(M1, LOW);
   digitalWrite(M2, HIGH);
   digitalWrite(M3, HIGH);
   digitalWrite(M4, LOW);
   digitalWrite(B,  LOW);
   digitalWrite(L2, HIGH);
   digitalWrite(L1, LOW);
   digitalWrite(OE, HIGH);
   digitalWrite(M5, HIGH);
   digitalWrite(M6, LOW);
   digitalWrite(M7, HIGH);
   digitalWrite(M8, LOW);
}

void stop()
{
   
   digitalWrite(M1, LOW);
   digitalWrite(M2, LOW);
   digitalWrite(M3, LOW);
   digitalWrite(M4, LOW);
   digitalWrite(B,  LOW);
   digitalWrite(L2, HIGH);
   digitalWrite(L1, HIGH);
   digitalWrite(OE, LOW);
   digitalWrite(M5, LOW);
   digitalWrite(M6, LOW);
   digitalWrite(M7, LOW);
   digitalWrite(M8, LOW);
}

void fb()
{
   
   digitalWrite(M1, HIGH);
   digitalWrite(M2, LOW);
   digitalWrite(M3, HIGH);
   digitalWrite(M4, LOW);
   digitalWrite(B,  HIGH);
   digitalWrite(L2, LOW);
   digitalWrite(L1, LOW);
   digitalWrite(M5, HIGH);
   digitalWrite(M6, LOW);
   digitalWrite(M7, HIGH);
   digitalWrite(M8, LOW);
}



void firstalarm()
{ 
   digitalWrite(B,  HIGH);
   delay(1500);
   digitalWrite(B,  LOW);
   delay(1500);
   digitalWrite(B,  HIGH);
   delay(1500);
   digitalWrite(B,  LOW);
   delay(1500);
   digitalWrite(B,  HIGH);
   delay(1500);
   digitalWrite(B,  LOW);
   
   
}

void secondalarm()
{
  digitalWrite(B,  HIGH);
   delay(500);
   digitalWrite(B,  LOW);
   delay(500);
   digitalWrite(B,  HIGH);
   delay(500);
   digitalWrite(B,  LOW);
   delay(500);
   digitalWrite(B,  HIGH);
   delay(500);
   digitalWrite(B,  LOW);
}

void thirdalarm()
{
   digitalWrite(M1, LOW);
   digitalWrite(M2, LOW);
   digitalWrite(M3, LOW);
   digitalWrite(M4, LOW);
   digitalWrite(L2, LOW);
   digitalWrite(L1, LOW);
   digitalWrite(M5, LOW);
   digitalWrite(M6, LOW);
   digitalWrite(M7, LOW);
   digitalWrite(M8, LOW);
   digitalWrite(OE, LOW);
   digitalWrite(B,  HIGH);
   delay(10);
   digitalWrite(B,  LOW);
   delay(10);
   digitalWrite(B,  HIGH);
   delay(10);
   digitalWrite(B,  LOW);
   delay(10);
   digitalWrite(B,  HIGH);
   delay(10);
   digitalWrite(B,  LOW);
     
}
void setup() 
{
  pinMode(I1, INPUT);
  pinMode(I2, INPUT);
  pinMode(I3, INPUT);
  pinMode(I4, INPUT);

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(B,  OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(M5, OUTPUT);
  pinMode(M6, OUTPUT);
  pinMode(M7, OUTPUT);
  pinMode(M8, OUTPUT);

pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600);

}

void loop() 
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;

 if(distance>=51&&distance<=150)
 firstalarm();

 else if(distance>=51&&distance<=100)
 secondalarm();

 else if(distance<=50)
 thirdalarm();

  int temp1=digitalRead(I1);
  int temp2=digitalRead(I2);
  int temp3=digitalRead(I3);
  int temp4=digitalRead(I4);


  if(temp1==1 && temp2==0 && temp3==1 && temp4==1)
  forward();

  else if(temp1==1 && temp2==1 && temp3==1 && temp4==0)
  backward();

  else if(temp1==1 && temp2==1 && temp3==0 && temp4==1)
  left();

  else if(temp1==1 && temp2==0 && temp3==0 && temp4==1)
  right();

   else if(temp1==0 && temp2==1 && temp3==0 && temp4==1)
  stop();

   else if(temp1==0 && temp2==0 && temp3==1 && temp4==1)
  fb();

  

  Serial.print("Distance: ");
  Serial.println(distance);
}
