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

###### Disclaimer
- HoTT is a trademark of Graupner/SJ GmbH, see <http://www.graupner.de>
- Duplex is a trademark of JETI model s.r.o., see <http://www.jetimodel.com>
