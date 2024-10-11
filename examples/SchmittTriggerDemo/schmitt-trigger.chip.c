// Wokwi Custom Chip - For docs and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright 2023 David Forrest

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin_out;
  pin_t pin_in;
  uint32_t threshold_attr;
  uint32_t hysteresis_attr;
  float threshold;
  float hysteresis;
  int state;
} chip_state_t;

static void chip_timer_event(void *user_data);

void chip_init() {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->threshold_attr = attr_init_float("threshold", 2.5);
  chip->hysteresis_attr = attr_init_float("hysteresis", 0.1);
  chip->pin_out = pin_init("OUT", OUTPUT);
  chip->pin_in = pin_init("IN", ANALOG);
  chip->state = pin_read(chip->pin_out);

  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };
  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 1000, true);

  // printf("Hello from Schmitt Trigger!\n");
}

void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;
  chip->threshold = attr_read_float(chip->threshold_attr);
  chip->hysteresis = attr_read_float(chip->hysteresis_attr);
  float volts = pin_adc_read(chip->pin_in);
  //printf("%f \n",volts);
  if(chip->state && volts < chip->threshold - chip->hysteresis){
    chip->state = 0;
    pin_write(chip->pin_out, 0);
   // printf("Fall\n");
  } else
  if(!chip->state && volts > chip->threshold + chip->hysteresis){
    chip->state = 1;
    pin_write(chip->pin_out, 1);
   // printf("Rise\n");
  }
}
