
void setup() {
  // put your setup code here, to run once:

  int maxHumid = 0.8; // 数值待定
  int maxVolt = 4; // 数值待定
  int minHumid = 0.2; // 数值待定
  int minVolt = 1; // 数值待定
  int presentVolt;
  int stopButtonState;
  int resetButtonState;
  bool operationState = false; // 默认为false，即自动模式
  bool wateringState = false; // 默认为false，即没有浇水
  int humidPin = 0; // pin口待定
  int valvePin = 1; // pin口待定
  int stopButtonPin = 2; // pin口待定
  int resetButtonPin = 3; // pin口待定
  int stopLEDPin = 4; // pin口待定

}

void loop() {
  // put your main code here, to run repeatedly:

  presentVolt = int getPresentVolt(); // 得到当前 湿度检测器 输出的电压值
  stopButtonState = int getStopButtonState(); // 得到当前 stopButton 的状态
  resetButtonState = int getResetButtonState(); // 得到当前 autoButton 的状态

  void humidComparing(int presentVolt); // 执行湿度判断
  void judgeManualStopMode(int stopButtonState); //执行 手动停止（manual stop） 判断
  void judgeManualResetMode(int resetButtonState); // 执行 恢复自动模式（auto reset） 判断
  delay(100);
  
}

int getPresentVolt() { // get()函数，得到 湿度探测器 输出的电压

  return digitalRead(humidPin);
  
}

int getStopButtonState() { // get()函数，得到 停止按钮（stop button）的值

  return digitalRead(stopButtonPin);
  
}

int getResetButtonState() { // get()函数，得到 自动按钮（auto button）的值


  return digitalread(resetButtonPin);
  
}

void autoWatering() { // 浇水函数

  wateringState = true; // 使 浇水模式（wateringState）变为true
  pinMode(valvePin, HIGH); // 打开阀门
  
}

void stopWatering() { // 停止浇水函数

  wateringState = false; // 使 浇水模式（wateringState）变为false
  pinMode(valvePin, LOW); // 关闭阀门
  
}

void humidComparing(int presentVolt) { // 湿度比较函数，并且判断是否浇水/停止浇水
  
  if (operationState == true & wateringState == true) { // 当处于 手动停止模式，不改变当前任何状态，维持停止浇水
  
      
  }
  
  else { // 当不处于 手动停止模式，进行 自动浇水模式
  
    if (presentVolt >= maxVolt) { // 判断当前电压是否大于等于预设最大电压（maxVolt）
  
      void stopWatering(); // 执行 停止浇水函数
        
    }
      
    else if (presentVolt <= minVolt) { // 判断当前电压是否小雨等于预设最小电压（minVolt）
  
      void autoWatering(); // 执行 浇水函数
        
    }
      
    else {
        
    }
  }
}

void judgeManualStopMode(int stopButtonState) { // 判断是否开启了 手动停止模式

  if (stopButtonState == HIGH) { // 如果 停止按钮（stop button）按下

    operationState = true; // 手动模式状态开启
    void stopWatering(); // 执行 停止浇水函数
    digitalWrite(stopLEDPin, HIGH); // 开启 手动停止 指示灯
    
  }
}

void judgeManualResetMode(int resetButtonState) { // 判断是否开启了 reset模式

  if (resetButtonState == HIGH) { // 如果 reset（）按钮

    operationState = false; // 自动浇水模式开启
    void autoWatering(); // 执行 浇水函数
    digitalWrite(stopLEDPin, LOW); // 关闭 手动停止 指示灯
    
  }
}
