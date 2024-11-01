
// Include Libraries
#include "Arduino.h"
#include "LED.h"
#include "SolenoidValve.h"
#include "Pump.h"


// Pin Definitions
#define LEDG_PIN_VIN	6
#define LEDR_PIN_VIN	9
#define SOLENOIDVALVE1_1_PIN_COIL1	2
#define SOLENOIDVALVE2_2_PIN_COIL1	3
#define WATERPUMP_PIN_COIL1	5



// Global variables and defines

// object initialization
LED ledG(LEDG_PIN_VIN);
LED ledR(LEDR_PIN_VIN);
SolenoidValve solenoidValve1_1(SOLENOIDVALVE1_1_PIN_COIL1);
SolenoidValve solenoidValve2_2(SOLENOIDVALVE2_2_PIN_COIL1);
Pump waterpump(WATERPUMP_PIN_COIL1);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // LED - Basic Green 5mm - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
    ledG.dim(i);                      // 1. Dim Led 
    delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledG.off();                        // 3. turns off
    }
    else if(menuOption == '2') {
    // LED - Basic Red 5mm - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
    ledR.dim(i);                      // 1. Dim Led 
    delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledR.off();                        // 3. turns off
    }
    else if(menuOption == '3') {
    // 12V Solenoid Valve - 3/4'' #1 - Test Code
    // The solenoid valve will turn on and off for 500ms (0.5 sec)
    solenoidValve1_1.on(); // 1. turns on
    delay(500);       // 2. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    solenoidValve1_1.off();// 3. turns off
    delay(500);       // 4. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.

    }
    else if(menuOption == '4') {
    // 12V Solenoid Valve - 3/4'' #2 - Test Code
    // The solenoid valve will turn on and off for 500ms (0.5 sec)
    solenoidValve2_2.on(); // 1. turns on
    delay(500);       // 2. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    solenoidValve2_2.off();// 3. turns off
    delay(500);       // 4. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.

    }
    else if(menuOption == '5') {
    // Submersible Pool Water Pump - Test Code
    // The water pump will turn on and off for 2000ms (4 sec)
    waterpump.on(); // 1. turns on
    delay(2000);       // 2. waits 500 milliseconds (0.5 sec).
    waterpump.off();// 3. turns off
    delay(2000);       // 4. waits 500 milliseconds (0.5 sec).

    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) LED - Basic Green 5mm"));
    Serial.println(F("(2) LED - Basic Red 5mm"));
    Serial.println(F("(3) 12V Solenoid Valve - 3/4'' #1"));
    Serial.println(F("(4) 12V Solenoid Valve - 3/4'' #2"));
    Serial.println(F("(5) Submersible Pool Water Pump"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing LED - Basic Green 5mm"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing LED - Basic Red 5mm"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing 12V Solenoid Valve - 3/4'' #1"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing 12V Solenoid Valve - 3/4'' #2"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing Submersible Pool Water Pump"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
