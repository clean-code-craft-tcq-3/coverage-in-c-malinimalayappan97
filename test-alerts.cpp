#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(40, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}

TEST_CASE("classify temp according to limits") {
    REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1)== TOO_LOW); 
    REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -10)== TOO_LOW); 
    REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -100)== TOO_LOW); 
    REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 36)== TOO_HIGH); 
    REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 41)== TOO_HIGH); 
    REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 46)== TOO_HIGH); 
    REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 33)== NORMAL); 
    REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 39)== NORMAL); 
    REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 44)== NORMAL); 
}

TEST_CASE("check and alert based on temp range") {
  BatteryCharacter batteryChar ={PASSIVE_COOLING,{0}};
  
  batteryChar.coolingType = PASSIVE_COOLING;
/* check if printf is called -yet to add*/
 checkAndAlert(TO_CONTROLLER,batteryChar, -1); 
 checkAndAlert(TO_EMAIL,batteryChar ,10); 
 checkAndAlert(NO_ALERT,batteryChar ,34); 
}

TEST_CASE("check breach type") {
  /* check if printf is called -yet to add */
   sendToEmail(TOO_LOW); 
   sendToEmail(NORMAL); 
   sendToEmail(TOO_HIGH); 
}


