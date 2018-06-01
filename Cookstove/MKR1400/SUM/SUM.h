#define NODE_ID 1                 //Set ID of the arduino (make sure this is unique)
#define STARTUP_DELAY 10000        //How long to delay before the node starts

//DEBUG
#define PRINTF 1                  //Comment out to remove debuf messages
#define SERIAL_SPEED 9600         //Serial speed

//Macro for print time
#ifdef PRINTF
# define debug(msg) _PRINT_TIME(msg)
#else
# define debug(msg) do {} while(0)
#endif

#define SECRET_PINNUMBER     ""               // SIM Pin number
#define SECRET_GPRS_APN      "giffgaff.com"   // replace GPRS APN
#define SECRET_GPRS_LOGIN    "giffgaff"       // replace with GPRS login
#define SECRET_GPRS_PASSWORD ""               // replace with GPRS password
#define GSM_CONNECT_RETRY_TIME 500            // How long to retry between gsm connection tries (0.5s)

#define MAX31850_POWER_PIN 7                  //Arduino Pin the MAX31850 3V3 is connected to
#define MAX31850_ADDR 0                       //Address of MAX31850 on 1-wire bus 
#define ONE_WIRE_BUS 2                        //Arduino Pin the MAX31850 data line is connected to

#define ADC_BITS 1023      //Max value extect from the ADC
#define INT_BATTERY_DIVIDER_MAX 4.2 //Max voltage that can be sensed from the internal voltage divider with 3.3v reference

#define MQTT_SERVER "159.65.25.153" //MQTT broker address
#define MQTT_KEEP_ALIVE 36000       //MQTT keep alive time (10hours)
#define MQTT_CLEAN_SESSION false    //MQTT start a clean session on connection
#define MQTT_TIMEOUT 1000           //MQTT 1s timeout
#define MQTT_CONNECT_RETRY_TIME 500 //How long to retry between MQTTT broker connection tries (0.5s)

#define DIGITAL_ON_WAIT 10          //Wait 10ms to ensure digital pin has switched high

#define SIP_TEMP_THRESH 0.5          //Temperature threshold (0.5C suggested, set to -1 for sense-and-send)

#define RTC_Y2K 946684800           //Unixtime stamp for 2000-01-01 00:00:00 used to set RTC as we don't care about actual time here
#define RTC_SAMPLE_TIME 25          //SET RTC alarm off every xth second in a minute



