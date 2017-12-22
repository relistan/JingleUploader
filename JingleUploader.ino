#include <EEPROM.h>
#include "pitches.h"

#define arraySize(a) sizeof(a)/sizeof(a[0])

short jingleBells[][2] = {
    { NOTE_E4, 8}, { NOTE_E4, 8 }, { NOTE_E4, 4},
    { NOTE_E4, 8}, { NOTE_E4, 8 }, { NOTE_E4, 4},
    { NOTE_E4, 8}, { NOTE_G4, 8 }, {NOTE_C4, 8}, {NOTE_D4, 8}, {NOTE_E4, 2},
    
    { NOTE_F4, 8 }, {NOTE_F4, 8}, {NOTE_F4, 8}, {NOTE_F4, 16}, {NOTE_F4, 16}, 
    { NOTE_F4, 8 }, {NOTE_E4, 8}, {NOTE_E4, 8}, {NOTE_E4, 16}, {NOTE_E4, 16},
    { NOTE_E4, 8}, {NOTE_D4, 8}, {NOTE_D4, 8}, {NOTE_E4, 8}, {NOTE_D4, 4}, {NOTE_G4, 4},

    { NOTE_E4, 8}, { NOTE_E4, 8 }, { NOTE_E4, 4},
    { NOTE_E4, 8}, { NOTE_E4, 8 }, { NOTE_E4, 4},
    { NOTE_E4, 8}, { NOTE_G4, 8 }, {NOTE_C4, 8}, {NOTE_D4, 8}, {NOTE_E4, 2},
    
    { NOTE_F4, 8 }, {NOTE_F4, 8}, {NOTE_F4, 8}, {NOTE_F4, 16}, {NOTE_F4, 16}, 
    { NOTE_F4, 8 }, {NOTE_E4, 8}, {NOTE_E4, 8}, {NOTE_E4, 16}, {NOTE_E4, 16},
    { NOTE_G4, 8}, {NOTE_G4, 8}, {NOTE_F4, 8}, {NOTE_D4, 8}, {NOTE_C4, 2}  
  };

void setup() {
  // put your setup code here, to run once:
  unsigned char bytes[4];

  Serial.begin(115200);

  Serial.println("Beginning EEPROM write");
  Serial.println(arraySize(jingleBells));

  for(uint16_t i = 0; i < arraySize(jingleBells); i++) {
    bytes[0] = (jingleBells[i][0] >> 8) & 0xFF;
    bytes[1] = jingleBells[i][0] & 0xFF;

    bytes[2] = (jingleBells[i][1] >> 8) & 0xFF;
    bytes[3] = jingleBells[i][1] & 0xFF;

    int j = i * 4;

    // First short
    EEPROM.write(j, bytes[0]);
    EEPROM.write(j+1, bytes[1]);

    // Second short
    EEPROM.write(j+2, bytes[2]);
    EEPROM.write(j+3, bytes[3]);
  }
  Serial.println("Finished EEPROM write");
}

void loop() {
  // put your main code here, to run repeatedly:
}
