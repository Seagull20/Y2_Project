int maxTemperature;
int minTemperature;
int currentTemperature;


int fanButtonPin;//记录风扇开关输入接口
int heaterButtonPin;//记录加热垫开关输入接口
int inputTempPin;//记录温度输入接口

int fanControlPin;//记录风扇输出接口
int heaterControlPin;//记录加热垫输出接口

bool TemFanSystemState;
bool fanState;
bool heatingState;

void setup() {
  // put your setup code here, to run once:
  
heaterControlPin=2;
inputTempPin=A5;
pinMode(inputTempPin,INPUT);
pinMode(heaterControlPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  //currentTemperature=analogRead(inputTempPin);
  Serial.println(currentTemperature);
  // put your main code here, to run repeatedly:
  temperatureSystem();
  delay(1000);
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
  digitalWrite(heaterControlPin, LOW);
  lightState=1;
}else{
  digitalWrite(heaterControlPin, HIGH);
  lightState=0;
}
}

void toggleFan(bool state){
  if (state)
{
  digitalWrite(fanControlPin, LOW);
  lightState=1;
}else{
  digitalWrite(fanControlPin, HIGH);
  lightState=0;
}
}

//subSystem:auto 低电平触发
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

  if (fanButtonState=1 & TemFanSystemState=0 )
  {
    toggleFan(1);
  }else{
    toggleFan(0);
  }
  if (heaterButtonState=1 & TemFanSystemState=0)
  {
    toggleHeating(1);
  }else{
    toggleHeating(0);
  }
}


//System
void temperatureSystem(){
  temperatureButtonDetect();
  if (TemFanSystemState)
  {
    autoMaintainTemperature();
    digitalWrite(indicatorPin,LOW);
  }else{
    manualControlTemperature();
    digitalWrite(indicatorPin,HIGH);
  } 
}

void temperatureButtonDetect() {

  int fanButtonState = digitalRead(fanButtonPin);
  int heaterButtonState = digitalRead(heaterButtonPin);

  if (fanButtonState == HIGH || heaterButtonState == HIGH) {
    TemFanSystemState =!TemFanSystemState;
    delay(100);
  }
}

//button check
//heating(with a indicator) and fan