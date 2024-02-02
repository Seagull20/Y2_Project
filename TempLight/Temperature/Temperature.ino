int maxTemperature;
int minTemperature;
int currentTemperature;


int fanButtonPin;//记录风扇开关输入接口
int heaterButtonPin;//记录加热垫开关输入接口
int inputTempPin;//记录温度输入接口

int fanControlPin;//记录风扇输出接口
int heaterControlPin;//记录加热垫输出接口



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  temperatureSystem();
}

//System
void temperatureSystem(){
  if (!tempManualCheck())
  {
    autoMaintainTemperature();
  }else{
    manualControlTemperature();
  } 
}

//subSystem:auto
void autoMaintainTemperature(){

  currentTemperature= getTemperature();
  if (currentTemperature<minTemperature)
  {
    toggleHeating(1);
  }else if (currentTemperature>=minTemperature & currentTemperature <= maxTemperature)
  {
    toggleFan(0);
    toggleHeating(0);
  }else{
    toggleFan(1);
  }
}

//subSystem:manual
void manualControlTemperature(){
  int fanButtonState = digitalRead(fanButtonPin);
  int heaterButtonState = digitalRead(heaterButtonPin);

  if (fanButtonState==HIGH)
  {
    toggleFan(1);
  }
  if (heaterButtonState==HIGH)
  {
    toggleHeating(1);
  }
}

void setTmperature(int maxTemp,int minTemp){
  maxTemperature=maxTemp;
  minTemperature=minTemp;
}

int getTemperature(){
int temp= analogRead(inputTempPin);
return  temp;
}


void toggleHeating(bool state){
if (state)
{
  digitalWrite(heaterControlPin, HIGH);
}else{
  digitalWrite(heaterControlPin, LOW);
}

}

void toggleFan(bool state){
  if (state)
{
  digitalWrite(fanControlPin, HIGH);
}else{
  digitalWrite(fanControlPin, LOW);
}
}


bool tempManualCheck() {

  int fanButtonState = digitalRead(fanButtonPin);
  int heaterButtonState = digitalRead(heaterButtonPin);

  if (fanButtonState == HIGH || heaterButtonState == HIGH) {
    return  true;
  } else {
     return false;
  }
}


