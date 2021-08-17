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
    //TEST_FAIL_MESSAGE("Empezamos");
}

/* prendo un led */
void test_prender_un_led(void)
{
        const int  led = 2;
        LedsTurnOn(led);
        TEST_ASSERT_EQUAL_UINT16(1 << (led - 1),puerto);
}

/* apago un led */
void test_apagar_un_led(void)
{
        const int  led = 2;
        LedsTurnOn(led);
        LedsTurnOff(led);
        TEST_ASSERT_EQUAL_UINT16(0x0000,puerto);
}

/* prendo un led sin alterar el resto */
void test_prender_y_apagar_varios_leds(void)
{
        const int  led = 2;
        LedsTurnOn(led);  
        LedsTurnOn(5);
        LedsTurnOff(5); 
        TEST_ASSERT_EQUAL_UINT16(1 << (led - 1),puerto);
}

/* Determinar si un led esta prendido */
void test_ledPrendidoOk(void)
{
        const int  led = 2;
        LedsTurnOn(led);  
        TEST_ASSERT_EQUAL_UINT16(1 << (led - 1),puerto);
        LedsTurnOff(led);  
        TEST_ASSERT_EQUAL_UINT16(0x0000,puerto);
}

/* Determinar si un led esta apagado */
void test_ledApagadoOk(void)
{
        const int  led = 2;
        LedsTurnOff(led);  
        TEST_ASSERT_EQUAL_UINT16(0x0000,puerto);
        LedsTurnOn(led);  
        TEST_ASSERT_EQUAL_UINT16(1 << (led - 1),puerto);
}

/* Prendo todos los leds en una operación */
void test_allLedsOn_oneOp(void)
{
        const int  led = 0x0000;
        LedsTurnOn(led);  
        TEST_ASSERT_EQUAL_UINT16(1 << (led - 1),puerto);
}

/* Apago todos los leds en una operación */
void test_allLedsOff_oneOp(void)
{
        const int  led = 0xFFFF;
        LedsTurnOff(led);  
        TEST_ASSERT_EQUAL_UINT16(0x0000,puerto);
}