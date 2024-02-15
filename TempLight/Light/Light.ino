int minIntensity;
int currentIntensity;
int lightButtonPin;
int inputIntensityPin;
int indecatorPin;

int lightControlPin;

bool systemState;//auto/manual
bool lightState;

void setup() {
  // put your setup code here, to run once:
minIntensity=20;
lightButtonPin=1;
lightControlPin=2;
inputIntensityPin=A4;
indecatorPin=3;
pinMode(indicatorPin,OUTPUT);
pinMode(inputIntensityPin,INPUT);
pinMode(lightControlPin,OUTPUT);
pinMode(lightButtonPin,INPUT);
Serial.begin(9600);
}

void loop() {
  //currentIntensity=analogRead(inputIntensityPin);
  Serial.println(currentIntensity);
  // put your main code here, to run repeatedly:
  intensitySystem();
  delay(100);
}

void setIntensity(int intensity){
minIntensity=intensity;
}

int getIntensity(){
return analogRead(inputIntensityPin);
}


void toggleLight(bool state){
if (state)
{
  digitalWrite(lightControlPin, LOW);
  lightState=1;
}else{
  digitalWrite(lightControlPin, HIGH);
  lightState=0;
}
}

//subSystem:auto
void autoMaintainIntensity(){
  currentIntensity= getIntensity();
  if (currentIntensity<minIntensity)
  {
    toggleLight(1);
  }else{
    toggleLight(0);
  }
}

//subSystem:manual
void manualControlIntensity(){
  int lightButtonState = digitalRead(lightButtonPin);
  
  if (lightButtonState==1 & systemState==0)
  {
    toggleLight(!lightState);
  }

}
//System
void intensitySystem(){
  intensityButtonDectect();
  if (systemState)
  {
    autoMaintainIntensity();
    digitalWrite(indicatorPin,LOW);
  }else{
    manualControlIntensity();
    digitalWrite(indicatorPin,HIGH);
  } 
}

//0 for manual system;1 for auto system
void intensityButtonDectect() {
  int lightButtonState = digitalRead(lightButtonPin);
  if (lightButtonState == HIGH) {
    systemState=!systemState;
    delay(100);
  } 
}