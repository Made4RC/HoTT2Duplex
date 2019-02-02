# HoTT2Duplex
Arduino sketch for converting telemetry data from Graupner HoTT sensors to Jeti Duplex EX

### Required hardware:
* Arduino Pro Mini 328, 16Mhz, 5V
* 2x resistor 1k5 to 4k7 Ohm (SMD 0805 fits perfect)

### Wiring
![HoTT2Duplex wiring](https://github.com/Made4RC/HoTT2Duplex/blob/master/HoTT2Duplex%20Wiring.png?raw=true)


Left side shows connection to HoTT sensor. Only use red (+) wire for GPS or Vario sensor.
Right side shows connection to Jeti reciever.

### Required libraries:
* [HoTTClient](https://github.com/Made4RC/HoTTClient)
* [JetiExSensorCppLib](https://sourceforge.net/projects/jetiexsensorcpplib/)

### Supported modules:
|Graupner Nr. |Name |Supported |Status |
|---|---|---|---|
|33601|Vario Module|Yes|working|
|S8437|GPS/VARIO Module|Yes|working|
|33718.SH|BRUSHLESS CONTROL SBEC + T, 18 A, SH Empfängerstecker|Yes|working|
|33718.SC|BRUSHLESS CONTROL SBEC + T, 18 A, SC Empfängerstecker|Yes|working|
|33718|BRUSHLESS CONTROL SBEC + T, 18 A, JR Empfängerstecker|Yes|working|
|33735|BRUSHLESS CONTROL + T T35 und G3,5 Stecker|Yes|working|
|33735.G2|BRUSHLESS CONTROL + T T35, G2 Stecker|Yes|working|
|33754.G2|BRUSHLESS CONTROL + T 45 G2|Yes|working|
|33754|BRUSHLESS CONTROL + T 45 G3,5|Yes|working|
|S3046|BRUSHLESS CONTROL 50 A, integr. Telemetrie, SBEC|Yes|unsure|
|33760|BRUSHLESS CONTROL + T 60 G3,5|Yes||
|S3031|BRUSHLESS CONTROL +T 60 Opto XT-60 D3,5|Yes||
|S3040|BRUSHLESS CONTROL +T 60 HV D3,5 XT-60|Yes||
|33770|BRUSHLESS CONTROL + T 70 G3,5|Yes|working|
|33770.D35|BRUSHLESS CONTROL +T 70 XT-60 D3,5|Yes|working|
|S3041|BRUSHLESS CONTROL +T 80 HV D3,5 XT-60 |Yes||
|S3030|BRUSHLESS CONTROL + T 100|Yes||
|S3036|BRUSHLESS CONTROL + T 100 HV G6|Yes|working|
|S3037|BRUSHLESS CONTROL + T 100 Opto G6|Yes|working|
|S3038|BRUSHLESS CONTROL + T 120 HV G6|Yes||
|S3032|BRUSHLESS CONTROL + T 120 Opto G6|Yes||
|S3033|BRUSHLESS CONTROL + T 160 Opto G6|Yes|working|
|33610|General Engine-Module 2-6S Gr. HoTT|Yes||
|33610.D35|General Engine-Module 2-6S mit XT-60|Yes||
|33611|General Air-Module 2-6S, Vario Gr. HoTT|Yes|working|
|33611.D35|General Air-Module 2-6S, Vario m. XT-60|Yes|working|
|33620|Electric Air Module2-14S, Vario HoTT|Yes, but commented out||
|33620.XT90|Electric Air Module0-14S,Vario m. XT-90|Yes, but commented out||


###### Disclaimer
- HoTT is a trademark of Graupner/SJ GmbH, see <http://www.graupner.de>
- Duplex is a trademark of JETI model s.r.o., see <http://www.jetimodel.com>
