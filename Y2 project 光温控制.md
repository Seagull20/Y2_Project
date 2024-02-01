# 光温控制
## Parameters
|ID|Name|Description|
||||
|1| `int desiredTemperature`|用户设定的目标温度。|
|2| `int desiredIntensity`|用户设定的目标光强。|
|3| `int actualIntensity`|当前实际测量的光强。|
|4| `Boolean isManualTemperature`|温度控制是否处于手动模式。|
|5| `Boolean isManualIntensity`|光强控制是否处于手动模式。|

## Methods  
|ID|Name|Description|
||||
|1|`void setTemperature(int temperature)`|设置目标温度。
|2|`int getTemperature()`|获取当前温度。
|3|`void setIntensity(int intensity)`|设置目标光强。
|4|`int getIntensity()`|获取当前光强。
|5|`void toggleHeating(boolean state)`|开启/关闭加热。
|6| `void toggleFan(boolean state)`|开启/关闭加热。
|7| `void toggleLighting(boolean state)`|开启/关闭照明。
|8| `void autoMaintainTemperature(boolean isManual)`|自动维持温度；若在手动控制，则不执行自动控制。
|9| `void autoMaintainIntensity(boolean isManual)`|自动维持光强；若在手动控制，则不执行自动控制。
|10| `void manualTemperatureControl()`|手动温度控制。
|11| `boolean manualHeaterControl()`|手动加热垫控制。
|12| `boolean manualFanControl()`|手动风扇控制。
|13| `boolean manualLightingControl()`|手动照明控制。

## FlowChart
![](Blank%20diagram.png)
改成range