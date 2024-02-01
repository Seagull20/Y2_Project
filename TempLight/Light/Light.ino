int minIntensity;
int currentIntensity;

int lightButtonPin;//记录照明开关输入接口
int inputIntensityPin;//记录光强输入接口

int lightControlPin;//记录照明输出接口  
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

//System
void intensitySystem(){
  if (!IntensityManualCheck())
  {
    autoMaintainTemperature();
  }else{
    manualControlTemperature();
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

bool IntensityManualCheck() {

  int lightButtonState = digitalRead(lightButtonPin);

  if (lightButtonState == HIGH) {
    return  true;
  } else {
     return false;
  }
}