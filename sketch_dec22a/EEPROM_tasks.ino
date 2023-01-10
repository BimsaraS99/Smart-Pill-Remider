void EEPROM_write() {
  Serial.println("EEPROM write");
  EEPROM.write(100, num_of_stored_data);
  for (byte col = 0; col < 10; col++) {
    for (byte row = 0; row < 6; row++) {
      EEPROM.write(row + (col*6), data_base[col][row]);
    }
  }
}

void EEPROM_read() {
  num_of_stored_data = EEPROM.read(100);
  for (byte col = 0; col < 10; col++) {
    for (byte row = 0; row < 6; row++) {
      data_base[col][row] = EEPROM.read(row + (col * 6));
    }
  }
}
