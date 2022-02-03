  int ledPin=5;
int pot=A4;
int en=11;
int RM1=8;
int RM2=7;
int LM1=10;
int LM2=9;
int RSen=A0;
int LSen=A2;
int MSen=A1;
int MS;
double potValue;
String state;
int light;
int speedm;
double vth=4.1;
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RSen,INPUT);
  pinMode(LSen,INPUT);
  pinMode(MSen,INPUT);
  Serial.begin(9600);
  Serial.println("forward=F ,backward=B,left=L,right=R,stop=S");
}

void loop() {
  potValue=analogRead(pot); //0-1023
  speedm=potValue*255/1023; //0-255
  int RS=digitalRead(RSen);
  int LS=digitalRead(LSen);
  double Msensor=analogRead(MSen);
  double MS1=Msensor*5/1023; //0-5
  double vth = 4.1; 
  if (MS1>vth)
    MS=1;
    else if (MS1<vth)
    MS=1;
  //Serial.println(RSen);  
  //Serial.println(LSen);
  
  if((RS==0 && MS==0 && LS==0) || (RS==0 && MS==1 && LS==0) || (RS==1 && MS==1 && LS==1))
  {
         stopm(speedm);
         Serial.println("Stop");
  }
  if((RS==1 && MS==0 && LS==0) || (RS==1 && MS==1 && LS==0))
  {
         left(speedm);
         Serial.println("left");
  }
  if((RS==0 && MS==0 && LS==1) || (RS==0 && MS==1 && LS==1))
  {
         right(speedm);
         Serial.println("right");
  }
  if(RS==1 && MS==0 && LS==1)
  {
         forward(speedm);
         Serial.println("forward");
  }
}

void forward (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          //saatgard
          digitalWrite(LM1,HIGH);
          digitalWrite(LM2,LOW);
  }
void backward (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(RM1,LOW);
          digitalWrite(RM2,HIGH);
          //saatgard
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,HIGH);
  }
void left (int sm)
  {
           analogWrite(en,sm);
           //saatgard
          digitalWrite(RM1,HIGH);
          digitalWrite(RM2,LOW);
          //saatgard
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,HIGH);
  }
void right (int sm)
  {
          analogWrite(en,sm);
          //saatgard
          digitalWrite(RM1,LOW);
          digitalWrite(RM2,HIGH);
          //saatgard
          digitalWrite(LM1,HIGH);
          digitalWrite(LM2,LOW);
  }
void stopm (int sm)
  {
           analogWrite(en,sm);
          //saatgard
          digitalWrite(RM1,LOW);
          digitalWrite(RM2,LOW);
          //saatgard
          digitalWrite(LM1,LOW);
          digitalWrite(LM2,LOW);
  }
