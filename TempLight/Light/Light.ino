int minIntensity;
int currentIntensity;

int lightButtonPin;
int inputIntensityPin;

int lightControlPin;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  intensitySystem();
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
  digitalWrite(lightControlPin, HIGH);
}else{
  digitalWrite(lightControlPin, LOW);
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

  if (lightButtonState==HIGH)
  {
    toggleLight(1);
  }
}
//System
void intensitySystem(){
  if (!IntensityManualCheck())
  {
    autoMaintainIntensity();
  }else{
    manualControlIntensity();
  } 
}



bool IntensityManualCheck() {

  int lightButtonState = digitalRead(lightButtonPin);

  if (lightButtonState == HIGH) {
    return  true;
  } else {
     return false;
  }
}