/**
 * Setups the Analog sensors
 * 1. Sets the reference voltage
 * 3. Turns of the LED
 */
void setupAnalogSensors() {
  analogReference(AR_DEFAULT); //3.3V

  //Set State power pin to output and make sure it is off
  pinMode(STATE_POWER_PIN, OUTPUT);
  digitalWrite(STATE_POWER_PIN, LOW); //turn LED off
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  debug("Digital pins set");
}


/**
 * Power up the op amp circuit
 */
void powerStateOpAmps() { 
  digitalWrite(STATE_POWER_PIN, HIGH);
  delay(DIGITAL_ON_WAIT);//Slight delay to allow the switch to happen
  debug("State op-amps On");
}

/**
 * Remove power from the op amp circuit
 */
void unpowerStateOpAmps() {
  digitalWrite(STATE_POWER_PIN, LOW);
  debug("State op-amps Off");
}


/**
 * Gets the battery voltage from the MKR Zero's internal
 * voltage divider
 * @param pointer to a data struct
 */
void getBatteryVoltage(Data* readings)
{
  readings->nodeBatt = (analogRead(ADC_BATTERY) / ADC_BITS ) * INT_BATTERY_DIVIDER_MAX;
}

/**
 * Gets the battery voltage from the Lantern monitoris
 * voltage divider
 * * @param pointer to a data struct
 */
void getSolarBatteryVoltage(Data* readings)
{
  readings->solarBatt = (analogRead(A1) / ADC_BITS ) * ADC_VREF;
}


/**
 * Dummy value for the lantern state 
 * * @param pointer to a data struct
 */
void getLanternState(Data* readings)
{
  analogReference(AR_INTERNAL1V0); //We need to change for this sensor modality
  powerStateOpAmps();
  readings->usage = analogRead(A2) / STATE_MV_CONVERSION;
  readings->charging = analogRead(A3) / STATE_MV_CONVERSION;
  unpowerStateOpAmps();
  analogReference(AR_DEFAULT);
}
