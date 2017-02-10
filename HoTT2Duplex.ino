#include "JetiExProtocol.h"
#include "HoTTClient.h"

HoTTClient sensor;
uint8_t sensorType = 0;

JetiExProtocol jetiEx;

// EAM
enum 
{
	ID_EAM_CAPACITY = 1,
	ID_EAM_CURRENT,
	ID_EAM_VOLTAGE_1,
	ID_EAM_VOLTAGE_2,
	ID_EAM_MAIN_VOLTAGE,
	ID_EAM_CELL_VOLTAGE_1,
	ID_EAM_CELL_VOLTAGE_2,
	ID_EAM_CELL_VOLTAGE_3,
	ID_EAM_CELL_VOLTAGE_4,
	ID_EAM_CELL_VOLTAGE_5,
	ID_EAM_CELL_VOLTAGE_6,
	ID_EAM_CELL_VOLTAGE_7,
	ID_EAM_CELL_VOLTAGE_8,
	ID_EAM_CELL_VOLTAGE_9,
	ID_EAM_CELL_VOLTAGE_10,
	ID_EAM_CELL_VOLTAGE_11,
	ID_EAM_CELL_VOLTAGE_12,
	ID_EAM_CELL_VOLTAGE_13,
	ID_EAM_CELL_VOLTAGE_14,
	ID_EAM_ALTITUDE,
	ID_EAM_CLIMBRATE,
	ID_EAM_TEMPERATURE_1,
	ID_EAM_TEMPERATURE_2,
	ID_EAM_RPM,
};

// GAM
enum
{
	ID_GAM_CAPACITY = 1,
	ID_GAM_CURRENT,
	ID_GAM_VOLTAGE_1,
	ID_GAM_VOLTAGE_2,
	ID_GAM_MAIN_VOLTAGE,
	ID_GAM_CELL_VOLTAGE_1,
	ID_GAM_CELL_VOLTAGE_2,
	ID_GAM_CELL_VOLTAGE_3,
	ID_GAM_CELL_VOLTAGE_4,
	ID_GAM_CELL_VOLTAGE_5,
	ID_GAM_CELL_VOLTAGE_6,
	ID_GAM_ALTITUDE,
	ID_GAM_CLIMBRATE,
	ID_GAM_FUEL_PERCENTAGE,
	ID_GAM_FUEL,
	ID_GAM_TEMPERATURE_1,
	ID_GAM_TEMPERATURE_2,
	ID_GAM_RPM,
};

// GPS
enum 
{
	ID_GPS_ALTITUDE = 1,
	ID_GPS_CLIMBRATE,
	ID_GPS_SPEED,
	ID_GPS_DISTANCE,
	ID_GPS_DIRECTION,
	ID_GPS_LOGITUDE_START_POSITION,
	ID_GPS_LATITUDE_START_POSITION,
	ID_GPS_LOGITUDE_CURRENT_POSITION,
	ID_GPS_LATITUDE_CURRENT_POSITION,
};

// VARIO
enum
{
	ID_VARIO_ALTITUDE = 1,
	ID_VARIO_CLIMBRATE,
};

// AIR-ESC
enum 
{
	ID_AIRESC_CAPACITY = 1,
	ID_AIRESC_CURRENT,
	ID_AIRESC_MAIN_VOLTAGE,
	ID_AIRESC_ESC_TEMPERATURE,
	ID_AIRESC_RPM,
};

// EAM
JetiSensor *sensors_eam[] = {
/* NOT YET TESTED
//                  id                      name               unit       data type             precision 0->0, 1->0.0, 2->0.00
	new JetiSensor( ID_EAM_CAPACITY,        "Capacity",        "mAh",	    JetiSensor::TYPE_22b, 0 ),
	new JetiSensor( ID_EAM_CURRENT,         "Current",         "A",	    JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_EAM_VOLTAGE_1,       "Voltage 1",       "V",	    JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_EAM_VOLTAGE_2,       "Voltage 2",       "V",	    JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_EAM_MAIN_VOLTAGE,    "Main voltage",    "V",	    JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_1,  "Cell 1 voltage",  "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_2,  "Cell 2 voltage",  "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_3,  "Cell 3 voltage",  "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_4,  "Cell 4 voltage",  "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_5,  "Cell 5 voltage",  "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_6,  "Cell 6 voltage",  "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_7,  "Cell 7 voltage",  "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_8,  "Cell 8 voltage",  "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_9,  "Cell 9 voltage",  "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_10, "Cell 10 voltage", "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_11, "Cell 11 voltage", "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_12, "Cell 12 voltage", "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_13, "Cell 13 voltage", "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_CELL_VOLTAGE_14, "Cell 14 voltage", "V",	    JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_EAM_ALTITUDE,        "Rel. altitude",   "m",	    JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_EAM_CLIMBRATE,       "Vario",           "m/s",	    JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_EAM_TEMPERATURE_1,   "Temperature 1",   "\xB0C",	JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_EAM_TEMPERATURE_2,   "Temperature 2",   "\xB0C",	JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_EAM_RPM,             "RPM",             "\x2Fmin",	JetiSensor::TYPE_22b, 1 ),
*/
	0 // end of array
};

// GAM
JetiSensor *sensors_gam[] = {
/* NOT YET TESTED
//                  id                      name              unit       data type             precision 0->0, 1->0.0, 2->0.00
	new JetiSensor( ID_GAM_CAPACITY,        "Capacity",       "mAh",     JetiSensor::TYPE_22b, 0 ),
	new JetiSensor( ID_GAM_CURRENT,         "Current", 	      "A",       JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_GAM_VOLTAGE_1,       "Voltage 1",      "V",       JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_GAM_VOLTAGE_2,       "Voltage 2", 	  "V",       JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_GAM_MAIN_VOLTAGE,    "Main voltage",   "V",       JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_GAM_CELL_VOLTAGE_1,  "Cell 1 voltage", "V",       JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_GAM_CELL_VOLTAGE_2,  "Cell 2 voltage", "V",       JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_GAM_CELL_VOLTAGE_3,  "Cell 3 voltage", "V",       JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_GAM_CELL_VOLTAGE_4,  "Cell 4 voltage", "V",       JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_GAM_CELL_VOLTAGE_5,  "Cell 5 voltage", "V",       JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_GAM_CELL_VOLTAGE_6,  "Cell 6 voltage", "V",       JetiSensor::TYPE_14b, 2 ),
	new JetiSensor( ID_GAM_ALTITUDE,        "Rel. altitude",  "m",       JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_GAM_CLIMBRATE,       "Vario",          "m/s",     JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_GAM_FUEL_PERCENTAGE, "Fuel percent",   "%",       JetiSensor::TYPE_14b, 0 ),
	new JetiSensor( ID_GAM_FUEL,            "Fuel",           "ml",      JetiSensor::TYPE_22b, 1 ),
	new JetiSensor( ID_GAM_TEMPERATURE_1,   "Temperature 1",  "\xB0C",   JetiSensor::TYPE_14b, 0 ),
	new JetiSensor( ID_GAM_TEMPERATURE_2,   "Temperature 2",  "\xB0C",   JetiSensor::TYPE_14b, 0 ),
	new JetiSensor( ID_GAM_RPM,             "RPM", 	          "\x2Fmin", JetiSensor::TYPE_22b, 0 ),
*/
	0 // end of array
};

// GPS
JetiSensor *sensors_gps[] = {
/* NOT YET TESTED
//                id                                name               unit    data type             precision 0->0, 1->0.0, 2->0.00
  new JetiSensor( ID_GPS_ALTITUDE,                  "Rel. altitude",   "m",	   JetiSensor::TYPE_14b, 1 ),
  new JetiSensor( ID_GPS_CLIMBRATE,                 "Vario", 		   "m/s",  JetiSensor::TYPE_14b, 1 ),
  new JetiSensor( ID_GPS_SPEED,                     "Speed",           "km/h", JetiSensor::TYPE_14b, 0 ),
  new JetiSensor( ID_GPS_DISTANCE,                  "Distance", 	   "m",    JetiSensor::TYPE_22b, 1 ),
  new JetiSensor( ID_GPS_DIRECTION,                 "Direction",       "°",	   JetiSensor::TYPE_14b, 0 ),
  new JetiSensor( ID_GPS_LOGITUDE_START_POSITION,   "Log. start pos.", "-",    JetiSensor::TYPE_GPS, 0 ),
  new JetiSensor( ID_GPS_LATITUDE_START_POSITION,   "Lat. start pos.", "-",	   JetiSensor::TYPE_GPS, 0 ),
  new JetiSensor( ID_GPS_LOGITUDE_CURRENT_POSITION, "Log. curr. pos.", "-",    JetiSensor::TYPE_GPS, 0 ),
  new JetiSensor( ID_GPS_LATITUDE_CURRENT_POSITION, "Lat. curr. pos.", "-",	   JetiSensor::TYPE_GPS, 0 ),
*/
  0 // end of array
};

// VARIO
JetiSensor *sensors_vario[] = {
//                  id                  name             unit    data type             precision 0->0, 1->0.0, 2->0.00
	new JetiSensor( ID_VARIO_ALTITUDE,  "Rel. altitude", "m",	 JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_VARIO_CLIMBRATE, "Vario", 		 "m/s",  JetiSensor::TYPE_14b, 1 ),
    0 // end of array
};

// AIR-ESC
JetiSensor *sensors_airesc[] = {
//                  id                         name            unit        data type             precision 0->0, 1->0.0, 2->0.00
	new JetiSensor( ID_AIRESC_CAPACITY,        "Capacity",     "mAh",      JetiSensor::TYPE_22b, 0 ),
	new JetiSensor( ID_AIRESC_CURRENT,         "Current", 	   "A",        JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_AIRESC_MAIN_VOLTAGE,	   "Main voltage", "V",	       JetiSensor::TYPE_14b, 1 ),
	new JetiSensor( ID_AIRESC_ESC_TEMPERATURE, "ESC Temp.",    "\xB0\x43", JetiSensor::TYPE_14b, 0 ),
	new JetiSensor( ID_AIRESC_RPM,             "RPM", 		   "/min",     JetiSensor::TYPE_22b, 0 ),
	0 // end of array
};

void setup() {
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LED_BUILTIN, OUTPUT);
	
	// Wait for esc's to initialize
	delay(3000);
	
	sensor.start();
	
	// Try to find a resonding sensor
	while (sensorType == 0) {
		digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
		
		if (sensor.probe(HOTT_AIRESC_MODULE_ID)) {
			sensorType = HOTT_AIRESC_MODULE_ID;
			jetiEx.Start( "HoTT ESC", sensors_airesc );			
		} else if (sensor.probe(HOTT_ELECTRIC_AIR_MODULE_ID)) {
			sensorType = HOTT_ELECTRIC_AIR_MODULE_ID;
			jetiEx.Start( "HoTT EAM", sensors_eam );			
		} else if (sensor.probe(HOTT_GENERAL_AIR_MODULE_ID)) {
			sensorType = HOTT_GENERAL_AIR_MODULE_ID;
			jetiEx.Start( "HoTT GAM", sensors_gam );			
		} else if (sensor.probe(HOTT_GPS_MODULE_ID)) {
			sensorType = HOTT_GPS_MODULE_ID;
			jetiEx.Start( "HoTT GPS", sensors_gps );			
		} else if (sensor.probe(HOTT_VARIO_MODULE_ID)) {
			sensorType = HOTT_VARIO_MODULE_ID;
			jetiEx.Start( "HoTT Vario", sensors_vario );			
		} 
		digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (LOW is the voltage level)

		delay(500);
	}

	digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (LOW is the voltage level)
}

void loop() {
	if (sensor.poll(sensorType)) {
		switch (sensorType) {
			case HOTT_ELECTRIC_AIR_MODULE_ID:
/* NOT YET TESTED
				jetiEx.SetSensorValue( ID_EAM_CAPACITY, sensor.capacity );
				jetiEx.SetSensorValue( ID_EAM_CURRENT, sensor.current );
				jetiEx.SetSensorValue( ID_EAM_VOLTAGE_1, sensor.voltage1 );
				jetiEx.SetSensorValue( ID_EAM_VOLTAGE_2, sensor.voltage2 );
				jetiEx.SetSensorValue( ID_EAM_MAIN_VOLTAGE, sensor.mainVoltage );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_1, sensor.cellVoltage1 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_2, sensor.cellVoltage2 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_3, sensor.cellVoltage3 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_4, sensor.cellVoltage4 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_5, sensor.cellVoltage5 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_6, sensor.cellVoltage6 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_7, sensor.cellVoltage7 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_8, sensor.cellVoltage8 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_9, sensor.cellVoltage9 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_10, sensor.cellVoltage10 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_11, sensor.cellVoltage11 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_12, sensor.cellVoltage12 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_13, sensor.cellVoltage13 );
				jetiEx.SetSensorValue( ID_EAM_CELL_VOLTAGE_14, sensor.cellVoltage14 );
				jetiEx.SetSensorValue( ID_EAM_ALTITUDE, sensor.altitude );
				jetiEx.SetSensorValue( ID_EAM_CLIMBRATE, sensor.climbRate*10 );
				jetiEx.SetSensorValue( ID_EAM_TEMPERATURE_1, sensor.temperature1 );
				jetiEx.SetSensorValue( ID_EAM_TEMPERATURE_2, sensor.temperature2 );
				jetiEx.SetSensorValue( ID_EAM_RPM, sensor.rpm );
*/
				break;
			case HOTT_GENERAL_AIR_MODULE_ID:
/* NOT YET TESTED
				jetiEx.SetSensorValue( ID_GAM_CAPACITY, sensor.capacity );
				jetiEx.SetSensorValue( ID_GAM_CURRENT, sensor.current );
				jetiEx.SetSensorValue( ID_GAM_VOLTAGE_1, sensor.voltage1 );
				jetiEx.SetSensorValue( ID_GAM_VOLTAGE_2, sensor.voltage2 );
				jetiEx.SetSensorValue( ID_GAM_MAIN_VOLTAGE, sensor.mainVoltage );
				jetiEx.SetSensorValue( ID_GAM_CELL_VOLTAGE_1, sensor.cellVoltage1 );
				jetiEx.SetSensorValue( ID_GAM_CELL_VOLTAGE_2, sensor.cellVoltage2 );
				jetiEx.SetSensorValue( ID_GAM_CELL_VOLTAGE_3, sensor.cellVoltage3 );
				jetiEx.SetSensorValue( ID_GAM_CELL_VOLTAGE_4, sensor.cellVoltage4 );
				jetiEx.SetSensorValue( ID_GAM_CELL_VOLTAGE_5, sensor.cellVoltage5 );
				jetiEx.SetSensorValue( ID_GAM_CELL_VOLTAGE_6, sensor.cellVoltage6 );
				jetiEx.SetSensorValue( ID_GAM_ALTITUDE, sensor.altitude );
				jetiEx.SetSensorValue( ID_GAM_CLIMBRATE, sensor.climbRate*10 );
				jetiEx.SetSensorValue( ID_GAM_FUEL_PERCENTAGE, sensor.fuelPercentage );
				jetiEx.SetSensorValue( ID_GAM_FUEL, sensor.fuel );
				jetiEx.SetSensorValue( ID_GAM_TEMPERATURE_1, sensor.temperature1 );
				jetiEx.SetSensorValue( ID_GAM_TEMPERATURE_2, sensor.temperature2 );
				jetiEx.SetSensorValue( ID_GAM_RPM, sensor.rpm );
 				jetiEx.SetSensorValue( ID_GAM_CAPACITY, sensor.capacity );
 				jetiEx.SetSensorValue( ID_GAM_CURRENT, sensor.current );
 				jetiEx.SetSensorValue( ID_GAM_MAIN_VOLTAGE, sensor.mainVoltage );
 				jetiEx.SetSensorValue( ID_GAM_TEMPERATURE_1, sensor.temperature1 );
 				jetiEx.SetSensorValue( ID_GAM_RPM, sensor.rpm );
*/
				break;
			case HOTT_GPS_MODULE_ID:
/* NOT YET TESTED
				jetiEx.SetSensorValue( ID_GPS_ALTITUDE, sensor.altitude );
				jetiEx.SetSensorValue( ID_GPS_CLIMBRATE, sensor.climbRate*10 );
				jetiEx.SetSensorValue( ID_GPS_SPEED, sensor.speed );
				jetiEx.SetSensorValue( ID_GPS_DISTANCE, sensor.distance );
				jetiEx.SetSensorValue( ID_GPS_DIRECTION, sensor.direction );
				jetiEx.SetSensorValue( ID_GPS_LOGITUDE_START_POSITION, sensor.logitudeStartPosition );
				jetiEx.SetSensorValue( ID_GPS_LATITUDE_START_POSITION, sensor.latitudeStartPosition );
				jetiEx.SetSensorValue( ID_GPS_LOGITUDE_CURRENT_POSITION, sensor.logitudeCurrentPosition );
				jetiEx.SetSensorValue( ID_GPS_LATITUDE_CURRENT_POSITION, sensor.latitudeCurrentPosition );
*/
				break;
			case HOTT_VARIO_MODULE_ID:
				jetiEx.SetSensorValue( ID_VARIO_ALTITUDE, sensor.altitude );
				jetiEx.SetSensorValue( ID_VARIO_CLIMBRATE, sensor.climbRate );
				break;
			case HOTT_AIRESC_MODULE_ID:
				jetiEx.SetSensorValue( ID_AIRESC_CAPACITY, sensor.capacity );
				jetiEx.SetSensorValue( ID_AIRESC_CURRENT, sensor.current );
				jetiEx.SetSensorValue( ID_AIRESC_MAIN_VOLTAGE, sensor.mainVoltage );
				jetiEx.SetSensorValue( ID_AIRESC_ESC_TEMPERATURE, sensor.ESCTemperature );
				jetiEx.SetSensorValue( ID_AIRESC_RPM, sensor.rpm );
				break;
		}
	} else {
		// fehlerhafte Antwort vom Sensor (Checksumme, angefragter und
		// antwortender Sensor unterschiedlich, ...)
	}

	HandleMenu();
	jetiEx.DoJetiSend(); 
	
	digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(10);
	digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
	delay(10);
}

void HandleMenu()
{
	static int  _nMenu = 0;
	static bool _bSetDisplay = true;

	uint8_t c = jetiEx.GetJetiboxKey();

	// down
	if ( c == 0xb0 && _nMenu < 0 ) { // <= Anzahl an Menüseiten
		_nMenu++;
		_bSetDisplay = true;
	}

	// up
	if ( c == 0xd0 ) { 
		if( _nMenu > 0 ) {
			_nMenu--;
			_bSetDisplay = true;
		} else {
			jetiEx.SetJetiboxExit();
			return;
		}
	}

	if ( !_bSetDisplay )
		return;

	switch( _nMenu ) {
		case 0: 
			jetiEx.SetJetiboxText( JetiExProtocol::LINE1, "= HoTT2Duplex =" );
			jetiEx.SetJetiboxText( JetiExProtocol::LINE2, "  Version 0.1  " );
			break;
/*
		case 1: 
			jetiEx.SetJetiboxText( JetiExProtocol::LINE1, "Menu 1 - Line 1" );
			jetiEx.SetJetiboxText( JetiExProtocol::LINE2, "Menu 1 - Line 2" );
			break;
*/
	}
	_bSetDisplay = false;
}
