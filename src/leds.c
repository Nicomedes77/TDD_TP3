#include "leds.h"

#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON 0xFFFF
#define LEDS_INDEX_OFFSET    1
#define LEDS_STATE_ON   1

static uint16_t* puerto;
static uint16_t LedsIndexToMask(int Led )
{
    return (LEDS_STATE_ON << Led-LEDS_INDEX_OFFSET);
}

void LedsInit(uint16_t* direccion){
    puerto = direccion;
    *direccion = LEDS_ALL_OFF;
}

void SetAllLeds(int leds){
    *puerto = leds;
}

void LedsTurnOn(int Led)
{
    *puerto |= LedsIndexToMask(Led) ;
}

void LedsTurnOff(int Led)
{
    *puerto &= ~LedsIndexToMask(Led) ;
}

bool verifyOn(int led)
{
    *puerto = *puerto >> (led-1);
    if(*puerto == 1) return true;
    else false;
}


