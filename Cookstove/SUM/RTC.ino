//Include the RTC Libraries
#include "ArduinoLowPower.h"


// TODO consider calling directly from main code
/**
 * Puts the node into its sleep mode
 */
void nodeSleep(){
  LowPower.sleep(CS_SLEEP_TIME);
}

void setupNodeSleep() {
  LowPower.attachInterruptWakeup(RTC_ALARM_WAKEUP, dummy_ISR, CHANGE);
}

// TODO identify how this gets invoked
/* Function called on waking up by LowPower
 */
void dummy_ISR() {}
