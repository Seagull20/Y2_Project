# 30/1/2024
初步确定光温控制的可能的参数与方法，及其决策流程
## 光温控制
### Parameters
|ID|Name|Description|
||||
|1| `int desiredTemperature`|用户设定的目标温度。|
|2| `int desiredIntensity`|用户设定的目标光强。|
|3| `int actualIntensity`|当前实际测量的光强。|
|4| `bool isManualTemperature`|温度控制是否处于手动模式。|
|5| `bool isManualIntensity`|光强控制是否处于手动模式。|

### Methods  
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

### FlowChart
![](Temp_Light%20flowchart_1.png)

# 1/2/2024
对参数和方法进行了更改；对系统的结果进行优化
## Intensity System
### Parameter
| ID | Name                    | Description                                         |
|:--:|-------------------------|:----------------------------------------------------|
| 1  | `int minIntensity`      | Minimum intensity level.                            |
| 2  | `int currentIntensity`  | Current intensity level.                            |
| 3  | `int lightButtonPin`    | Pin number for the light switch input interface.    |
| 4  | `int inputIntensityPin` | Pin number for the light intensity input interface. |
| 5  | `int lightControlPin`   | Pin number for the light control output interface.  |


### Method
| ID | Name                               | Description                                                                                                 |
|:--:|------------------------------------|:------------------------------------------------------------------------------------------------------------|
| 1  | `void setIntensity(int intensity)` | Sets the minimum intensity to a specified value.                                                            |
| 2  | `int getIntensity()`               | Returns the current intensity by reading from inputIntensityPin.                                            |
| 3  | `void toggleLight(bool state)`     | Toggles the light on or off based on the boolean state parameter.                                           |
| 4  | `void intensitySystem()`           | Determines whether to automatically maintain or manually control temperature based on IntensityManualCheck. |
| 5  | `void autoMaintainIntensity()`     | Automatically maintains the light intensity above a minimum level.                                          |
| 6  | `void manualControlIntensity()`    | Allows manual control of light intensity based on the state of the light button.                            |
| 7  | `bool IntensityManualCheck()`      | Checks if the light button is pressed to switch between manual and automatic control modes.                 |
## Temperature System
### Parameter 
| ID | Name                     | Description                                         |
|:--:|--------------------------|:----------------------------------------------------|
| 1  | `int maxTemperature`     | Maximum temperature limit.                          |
| 2  | `int minTemperature`     | Minimum temperature limit.                          |
| 3  | `int currentTemperature` | Current temperature level.                          |
| 4  | `int fanButtonPin`       | Pin number for the fan switch input interface.      |
| 5  | `int heaterButtonPin`    | Pin number for the heater switch input interface.   |
| 6  | `int inputTempPin`       | Pin number for the temperature input interface.     |
| 7  | `int fanControlPin`      | Pin number for the fan control output interface.    |
| 8  | `int heaterControlPin`   | Pin number for the heater control output interface. |

### Method
| ID | Name                                            | Description                                                                                                |
|----|-------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| 1  | `void temperatureSystem()`                      | Determines whether to automatically maintain or manually control temperature based on tempManualCheck.     |
| 2  | `void autoMaintainTemperature()`                | Automatically maintains the temperature within specified limits using heating or cooling as necessary.     |
| 3  | `void manualControlTemperature()`               | Allows manual control of temperature through fan and heater based on button states.                        |
| 4  | `void setTemperature(int maxTemp, int minTemp)` | Sets the maximum and minimum temperature limits.                                                           |
| 5  | `int getTemperature()`                          | Returns the current temperature by reading from inputTempPin.                                              |
| 6  | `void toggleHeating(bool state)`                | Toggles the heating on or off based on the boolean state parameter.                                        |
| 7  | `void toggleFan(bool state)`                    | Toggles the fan on or off based on the boolean state parameter.                                            |
| 8  | `bool tempManualCheck()`                        | Checks if either the fan or heater button is pressed to switch between manual and automatic control modes. |
### FlowChart
![](Temp_Light%20flowchart_2.png)