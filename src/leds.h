#include "stdint.h"
#include "stdbool.h"

void LedsInit(uint16_t* direccion);
void SetAllLeds(int leds);
void LedsTurnOn(int Led);
void LedsTurnOff(int Led);
bool verifyOn(int led);
bool verifyOff(int led);
