// -*- c -*-
#pragma GCC diagnostic ignored "-Wwrite-strings"

typedef unsigned char byte;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "minunit.h"
#include "../SUM/struct.h"
#include "../SUM/SUM.h"
#include "../SUM/SIP.ino"

typedef unsigned char String;

int tests_run=0;
Data* readings = new Data();

static char* test_update_state(void) {
  readings->tempThermocouple = 25.1;
  readings->tempSi7021 = 23.5;
  readings->humidity = 60;
  updateState(readings);
  mu_assert("prev state should be set to 25.1", prev_temp_thermocouple == readings->tempThermocouple);
  mu_assert("prev state should be set to 23.5", prev_temp_Si7021 == readings->tempSi7021);
  mu_assert("prev state should be set to 60", prev_humidity == readings->humidity);
  return 0;
}

static char* test_has_no_event(void) {

  readings->tempThermocouple = 25;
  prev_temp_thermocouple = 25.3;

  readings->tempSi7021 = 24;
  prev_temp_Si7021 = 24.1;

  readings->humidity = 50;
  prev_humidity = 50;

  mu_assert("test_has_no_event: should be false", !hasEvent(readings));
  return 0;
}

static char* test_has_event_from_thermocouple(void) {

  readings->tempThermocouple = 25;
  prev_temp_thermocouple = 25.6;

  readings->tempSi7021 = 24;
  prev_temp_Si7021 = 24.1;

  readings->humidity = 50;
  prev_humidity = 50;

  mu_assert("test_has_event_from_thermocouple: should be true", hasEvent(readings));
  return 0;
}

static char* test_has_event_from_Si7021_temp(void) {

  readings->tempThermocouple = 25;
  prev_temp_thermocouple = 25.3;

  readings->tempSi7021 = 24;
  prev_temp_Si7021 = 24.7;

  readings->humidity = 50;
  prev_humidity = 50;

  mu_assert("test_has_event_from_Si7021_temp: should be true", hasEvent(readings));
  return 0;
}

static char* test_has_event_from_humidity(void) {

  readings->tempThermocouple = 25;
  prev_temp_thermocouple = 25.3;

  readings->tempSi7021 = 24;
  prev_temp_Si7021 = 24.1;

  readings->humidity = 50;
  prev_humidity = 52.1;

  mu_assert("test_has_event_from_humidity: should be true", hasEvent(readings));
  return 0;
}

static char* test_has_event_from_all(void) {

  readings->tempThermocouple = 25;
  prev_temp_thermocouple = 25.6;

  readings->tempSi7021 = 24;
  prev_temp_Si7021 = 24.7;

  readings->humidity = 50;
  prev_humidity = 52.1;

  mu_assert("test_has_event_from_all: should be true", hasEvent(readings));
  return 0;
}

void reset_test_state(void){
  prev_temp_thermocouple = -1;
  prev_temp_Si7021 = -1;
  prev_humidity = -1;
}

static char* all_tests(void) {
  reset_test_state();
  mu_run_test(test_update_state);
  reset_test_state();
  mu_run_test(test_has_no_event);
  reset_test_state();
  mu_run_test(test_has_event_from_thermocouple);
  reset_test_state();
  mu_run_test(test_has_event_from_Si7021_temp);
  reset_test_state();
  mu_run_test(test_has_event_from_humidity);
  reset_test_state();
  mu_run_test(test_has_event_from_all);
  return 0;
}


int main()
{
  char *result = all_tests();
  printf("START TESTS\n");
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);
  return 0;
}
