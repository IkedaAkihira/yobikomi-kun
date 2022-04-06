const int ECHO=2;
const int TRIG=3;
int duration;
const int YOBIKOMI=9;
int judgeCount=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHO,INPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(YOBIKOMI,OUTPUT);
  digitalWrite(YOBIKOMI,HIGH);
  delay(20*1000);
  digitalWrite(YOBIKOMI,LOW);
}

int getDuration(){
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  int duration=pulseIn(ECHO,HIGH);
  return duration;
}

void loop() {
  duration=getDuration();
  Serial.println(duration);
  if(duration<5000&&0<duration){
    judgeCount++;
    if(judgeCount>=5){
      judgeCount=0;
      digitalWrite(YOBIKOMI,HIGH);
      delay(15000);
      int d=getDuration();
      if(d<5000&&0<d)
        digitalWrite(YOBIKOMI,LOW);
       else
        delay(5*1000);
    }
    
  }else{
    judgeCount=0;
    digitalWrite(YOBIKOMI,LOW);
  }
    
}
