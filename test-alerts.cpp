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
}
