#include "unity.h"
#include "leds.h"

static uint16_t puerto;

void setUp(void)
{
    LedsInit(&puerto);
}
void tearDown(void)
{
    
}

/* Cuando inicializo el controlador todos los leds quedan apagados */
void test_LedsOffAfterCreate(void)
{
    uint16_t puerto = 0xFFFF;
    LedsInit(&puerto);
    TEST_ASSERT_EQUAL_UINT16(0X0000,puerto);
}

/* prendo un led */
void test_turnOn_one_led(void)
{
        const int  led = 2;
        LedsTurnOn(led);
        TEST_ASSERT_EQUAL_UINT16(1 << (led - 1),puerto);
}

/* apago un led */
void test_turnOff_One_led(void)
{
        const int  led = 2;
        LedsTurnOn(led);
        LedsTurnOff(led);
        TEST_ASSERT_EQUAL_UINT16(0x0000,puerto);
}

/* prendo un led sin alterar el resto */
void test_on_and_off_all_leds(void)
{
        const int  led = 2;
        LedsTurnOn(led);  
        LedsTurnOn(5);
        LedsTurnOff(5); 
        TEST_ASSERT_EQUAL_UINT16(1 << (led - 1),puerto);
}

/* Determinar si un led esta prendido */
void test_verifyLedOn(void)
{
        const int led = 2;
        bool estado;
        LedsTurnOn(led);
        estado = verifyOn(led);
        TEST_ASSERT_TRUE(estado);
}

/* Determinar si un led esta apagado */
void test_verifyLedOff(void)
{
        const int led = 2;
        bool estado;
        estado = verifyOff(led);
        TEST_ASSERT_TRUE(estado);
}
//-------------------------------------------
/* Prendo todos los leds en una operación */
void test_allLedsOn_oneOp(void)
{
        LedsAllOn(&puerto);
        TEST_ASSERT_EQUAL_UINT16(0xFFFF,puerto);
}

/* Apago todos los leds en una operación */
void test_allLedsOff_oneOp(void)
{
        LedsAllOn(&puerto);
        LedsAllOff(&puerto);
        TEST_ASSERT_EQUAL_UINT16(0x0000,puerto);
}