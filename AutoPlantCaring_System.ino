//温度
int maxTemperature = 100; // 最大温度阈值，超过此值将启动风扇降温
int minTemperature = 70; // 最小温度阈值，低于此值将启动加热垫升温
int presentTempValue; // 存储当前温度值
//温度按钮
int stopButtonState = LOW; // 存储停止按钮的状态
int resetButtonState = LOW; // 存储重置按钮的状态
//光照按钮
int stopButtonLIGState = LOW; // 存储停止按钮的状态
int resetButtonLIGState = LOW; // 存储重置按钮的状态
bool operationState = false; // 操作模式，默认为false，即自动模式---温度，温度和水阀
//bool operationStateLIG = false; // 操作模式，默认为false，即自动模式---光照
bool heatingState = false; // 加热状态，默认为false
bool fanState = false; // 风扇状态，默认为false

bool stopCounter = false; // 控制停止操作的变量---温度
bool stopCounterLIG = false; // 控制停止操作的变量---光照
int tempPin = A0; // 温度传感器引脚
//温度
int stopButtonPin = 2; // 停止按钮引脚
int resetButtonPin = 3; // 重置按钮引脚
int stopLEDPin = 4; // 手动停止指示LED引脚
int heaterPin = 5; // 加热垫控制引脚
int fanPin = 6; // 风扇控制引脚
//光照
int lightPin = 7; // 控制灯光的引脚
int stopButtonLIGPin = 2; // 停止按钮引脚
int resetButtonLIGPin = 3; // 重置按钮引脚
int stopLEDLIGPin = 4; // 手动停止指示LED引脚
//水阀
int maxHumidValue = 400; // 数值待定
int minHumidValue = 100; // 数值待定
int presentHumidValue;
int stopButtonWaterState = LOW;
int resetButtonWaterState = LOW;
//bool operationState = false; // 默认为false，即自动模式
bool wateringState = false; // 默认为false，即没有浇水
bool stopCounterWater = false;// 控制停止操作的变量---水阀
int humidPin = A2; // pin口待定
int stopButtonWaterPin = 2; // pin口待定        -------stopButtonWaterPin=stopButtonLIGState=stopButtonState       ---→  水手动停pin=光手动停pin=温度手动停        pin=  2
int resetButtonWaterPin = 3; // pin口待定       -------resetButtonWaterPin=resetButtonLIGState=resetButtonState    ---→  水重启手动pin=光重启手动pin=温度重启手动   pin=  3
int stopLEDWaterPin = 4; // pin口待定           -------stopLEDWaterPin=stopLEDLIGPin=stopLEDPin                    ---→  水手动停指示灯pin=光手动停pin=温度手动停   pin=  4
int valveWaterPin = 8; // pin口待定



//光照
int lightSensorPin = A1; // 光照强度传感器引脚

int minLightThreshold = 20; // 最小光照阈值，低于此值将开灯
bool lightState = false; // 灯光状态，默认为false，即灯光关闭
int prensentLightValue;

void setup() {
  Serial.begin(9600);
  pinMode(stopButtonPin, INPUT);
  pinMode(resetButtonPin, INPUT);
  pinMode(stopLEDPin, OUTPUT);
  pinMode(heaterPin, OUTPUT);
  pinMode(fanPin, OUTPUT);

  pinMode(lightSensorPin, INPUT);
  pinMode(lightPin, OUTPUT);

  pinMode(stopButtonWaterPin, INPUT);
  pinMode(resetButtonWaterPin, INPUT);
  pinMode(stopLEDWaterPin, OUTPUT);
  pinMode(valveWaterPin, OUTPUT);
}

void loop() {
  presentTempValue = getPresentTemp();
  stopButtonState = getStopButtonState();
  resetButtonState = getResetButtonState();

  prensentLightValue = getPresentLight();
  stopButtonLIGState = getStopButtonLIGState();
  resetButtonLIGState = getResetButtonLIGState();

  presentHumidValue = getPresentHumid(); // 得到当前 湿度检测器 输出的湿度值
  stopButtonWaterState = getStopButtonWaterState(); // 得到当前 stopButton 的状态
  resetButtonWaterState = getResetButtonWaterState(); // 得到当前 autoButton 的状态
  
  changeStopCounter(stopButtonState);
  changeResetCounter(resetButtonState);//温度
  changeStopLIGCounter(stopButtonLIGState);
  changeResetLIGCounter(resetButtonLIGState);//光照
  changeStopWaterCounter(stopButtonWaterState);
  changeResetWaterCounter(resetButtonWaterState);//水阀


  tempComparing(presentTempValue);
  judgeManualStopMode();
  judgeManualResetMode();//温度
  

  Serial.print("current temperature value = ");
  Serial.println(presentTempValue);
  Serial.print("current operation mode is : ");
  Serial.println(operationState);
  Serial.print("heating mode is : ");
  Serial.println(heatingState);
  Serial.print("fan mode is : ");
  Serial.println(fanState);
  Serial.println("------------------------------");

  lightComparing(prensentLightValue);
  Serial.print("current light value = ");
  Serial.println(prensentLightValue);
  Serial.print("light mode is : ");
  Serial.println(lightState?"ON":"OFF");
  Serial.println("------------------------------");

  humidComparing(presentHumidValue); // 执行湿度判断
  Serial.print("current humid value = ");
  Serial.println(presentHumidValue);
  Serial.print("current operation mode is : ");
  Serial.println(operationState);
  Serial.print("current watering mode is : ");
  Serial.println(wateringState);
  Serial.println();
  delay(500);
}

int getPresentTemp() {
  
  return analogRead(tempPin);
}

int getPresentLight() {
  
  return analogRead(lightSensorPin);
}

int getStopButtonState() {
  return digitalRead(stopButtonPin);
}

int getResetButtonState() {
  return digitalRead(resetButtonPin);
}

int getStopButtonLIGState() {
  return digitalRead(stopButtonLIGPin);
}

int getResetButtonLIGState() {
  return digitalRead(resetButtonLIGPin);
}

int getPresentHumid() { // get()函数，得到 湿度探测器 输出的湿度值

  return analogRead(humidPin);
  
}

int getStopButtonWaterState() { // get()函数，得到 停止按钮（stop button）的值

  return digitalRead(stopButtonWaterPin);
  
}

int getResetButtonWaterState() { // get()函数，得到 自动按钮（auto button）的值


  return digitalRead(resetButtonWaterPin);
  
}


void changeStopCounter(int stopButtonTriggered) {
  if (stopButtonTriggered == HIGH) {

    stopCounter = true;
    
  }
}

void changeResetCounter(int resetButtonTriggered) {
  if (resetButtonTriggered == HIGH) {

    stopCounter = false;

  }
}

void changeStopLIGCounter(int stopButtonLIGTriggered) {
  if (stopButtonLIGTriggered == HIGH) {

    stopCounterLIG = true;

  }
}

void changeResetLIGCounter(int resetButtonLIGTriggered) {
  if (resetButtonLIGTriggered == HIGH) {

    stopCounterLIG = false;

  }
}

void changeStopWaterCounter (int stopButtonWaterTriggered) {

  if (stopButtonWaterTriggered == HIGH) {

    stopCounterWater = true;

  }

}

void changeResetWaterCounter (int resetButtonWaterTriggered) {

  if (resetButtonWaterTriggered == HIGH) {

    stopCounterWater = false;
    
  }
}

void autoHeating() {
  heatingState = true;
  digitalWrite(heaterPin, HIGH);
}

void autoCooling() {
  fanState = true;
  digitalWrite(fanPin, HIGH);
}

void stopHeatingCooling() {
  heatingState = false;
  fanState = false;
  digitalWrite(heaterPin, LOW);
  digitalWrite(fanPin, LOW);
}

void autolighting() {
  lightState = true;
  digitalWrite(lightPin, HIGH);
}

void stoplighting() {
  lightState = false;
  digitalWrite(lightPin, LOW);
}

void autoWatering() { // 浇水函数

  wateringState = true; // 使 浇水模式（wateringState）变为true
  digitalWrite(valveWaterPin, HIGH); // 打开阀门
  
}

void stopWatering() { // 停止浇水函数
  
  wateringState = false; // 使 浇水模式（wateringState）变为false
  digitalWrite(valveWaterPin, LOW); // 关闭阀门
  
}

void tempComparing(int comparedValue) {
  if (operationState == true) {
    // 手动停止模式，不改变当前状态
  } else {
    if (comparedValue >= maxTemperature) {
      stopHeatingCooling(); // 防止同时加热和冷却
      autoCooling();
      
    } else if (comparedValue <= minTemperature) {
      stopHeatingCooling(); // 防止同时加热和冷却
      autoHeating();
     
    } else {
      stopHeatingCooling();
    }
  }
}
void lightComparing(int comparedValueOfLight) {
  if (operationState == true) {
    // 手动停止模式，不改变当前状态
  } else {
    if (comparedValueOfLight >= minLightThreshold) {
      stoplighting();
     
    } else if (comparedValueOfLight <= minLightThreshold) {
      autolighting();
    
    } 
  }
}
void humidComparing(int comparedValueOfWater) { // 湿度比较函数，并且判断是否浇水/停止浇水
  
  if (operationState == true) { // 当处于 手动停止模式，不改变当前任何状态，维持停止浇水
  
      
  }
  
  else { // 当不处于 手动停止模式，进行 自动浇水模式
  
    if (comparedValueOfWater >= maxHumidValue) { // 判断当前电压是否大于等于预设最大湿度值（maxHumidValue）
  
      stopWatering(); // 执行 停止浇水函数
        
    }
      
    else if (comparedValueOfWater <= minHumidValue) { // 判断当前电压是否小雨等于预设最小湿度值（minHumidValue）
  
      autoWatering(); // 执行 浇水函数
        
    }
      
    else {
        
    }
  }
}

void adjustLighting(int lightLevel) {
  if (lightLevel < minLightThreshold) {
    if (!lightState) {
      digitalWrite(lightPin, HIGH); // 如果光照太暗且灯光未开，则开灯
      lightState = true;
    }
  } else {
    if (lightState) {
      digitalWrite(lightPin, LOW); // 如果光照足够且灯光已开，则关灯
      lightState = false;
    }
  }
}

void judgeManualStopMode() {
  if (stopCounter == true) {
    operationState = true; // 进入手动模式
    stopHeatingCooling(); // 停止温度控制
    stoplighting(); // 停止光照控制
    stopWatering(); // 执行 停止浇水函数
    digitalWrite(stopLEDPin, HIGH); // 打开停止指示LED（温度控制）
    digitalWrite(stopLEDLIGPin, HIGH); // 打开停止指示LED（光照控制）
    digitalWrite(stopLEDWaterPin, HIGH); // 开启 手动停止 指示灯
  }
}

void judgeManualResetMode() {
  if (stopCounter == false && operationState == true) {
    operationState = false; // 退出手动模式，返回自动模式
    // 自动模式下重新评估温度和光照条件
    tempComparing(presentTempValue); // 重新评估温度条件
    lightComparing(prensentLightValue); // 重新评估光照条件
    humidComparing(presentHumidValue);
    digitalWrite(stopLEDPin, LOW); // 关闭停止指示LED（温度控制）
    digitalWrite(stopLEDLIGPin, LOW); // 关闭停止指示LED（光照控制）
    digitalWrite(stopLEDWaterPin, LOW); // 关闭停止指示LED（水阀控制）
  }
}
