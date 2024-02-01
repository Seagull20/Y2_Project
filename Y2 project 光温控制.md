# 光温控制
## Parameters
|ID|Name|Description|
||||
|1| `int desiredTemperature`|用户设定的目标温度。|
|2| `int desiredIntensity`|用户设定的目标光强。|
|3| `int actualIntensity`|当前实际测量的光强。|
|4| `bool isManualTemperature`|温度控制是否处于手动模式。|
|5| `bool isManualIntensity`|光强控制是否处于手动模式。|

## Methods  
|ID|Name|Description|
||||
|1|`void setTemperature(int temperature)`|设置目标温度。
|2|`int getTemperature()`|获取当前温度。
|3|`void setIntensity(int intensity)`|设置目标光强。
|4|`int getIntensity()`|获取当前光强。
|5|`void toggleHeating(bool state)`|开启/关闭加热。
|6| `void toggleFan(bool state)`|开启/关闭加热。
|7| `void toggleLighting(bool state)`|开启/关闭照明。
|8| `void autoMaintainTemperature(bool isManual)`|自动维持温度；若在手动控制，则不执行自动控制。
|9| `void autoMaintainIntensity(bool isManual)`|自动维持光强；若在手动控制，则不执行自动控制。
|10| `void manualTemperatureControl()`|手动温度控制。
|11| `bool manualHeaterControl()`|手动加热垫控制。
|12| `bool manualFanControl()`|手动风扇控制。
|13| `bool manualLightingControl()`|手动照明控制。

## FlowChart
![](Blank%20diagram.png)
改成range