/*
Read the temperature from an LM75-derived temperature sensor, and display it
in Celcius every 250ms. Any LM75-derived temperature should work.
*/

#include <Temperature_LM75_Derived.h>
#include <DS18B20.h>

// The Generic_LM75 class will provide 9-bit (±0.5°C) temperature for any
// LM75-derived sensor. More specific classes may provide better resolution.
Generic_LM75 temperature;
DS18B20 ds(23);

uint8_t address[] = {40, 250, 31, 218, 4, 0, 0, 52};
uint8_t selected;

void setup() {
  while(!Serial) {}
  
  Serial.begin(9600);
  selected = ds.select(address);

  Wire.begin();
}

void loop() {
  Serial.print("{\"LM75A\" : \"");
  Serial.print(temperature.readTemperatureC());
  Serial.print("\", \"DS18B20\" : \"");
  Serial.print(ds.getTempC());
  Serial.println("\"}");
  //delay(250);
}
