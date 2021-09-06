#include "stdint.h"
#include "stdbool.h"

void LedsInit(uint16_t* direccion);
void LedsAllOn(uint16_t* direccion);
void LedsAllOff(uint16_t* direccion);
void LedsTurnOn(int Led);
void LedsTurnOff(int Led);
bool verifyOn(int led);
bool verifyOff(int led);
