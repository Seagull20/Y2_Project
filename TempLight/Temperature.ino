int maxTemperature;
int minTemperature;
int currentTemperature;
bool isManualTemperature;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
if (digtalread= )
{
  /* code */
}

}

void setTmperature(int temp){

}

int getTemperature(){

}


void toggleHeating(bool state){

}

void toggleFan(bool state){
  
}

void autoMaintainTemperature(bool isManual){
if (!isManual){
  currentTemperature= getTemperature();
  if (currentTemperature<minTemperature)
  {
    toggleHeating(true);
  }else if (currentTemperature>minTemperature & currentTemperature<maxTemperature)
  {
    toggleFan(0);
    toggleHeating(0);
  }else{
    toggleFan(1);
  }
}
}


bool  manualHeaterControl(){

}

bool manulFanControl(){

}

