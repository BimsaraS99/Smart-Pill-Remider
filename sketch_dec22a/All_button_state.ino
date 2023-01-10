unsigned long previousMillis = 0;
boolean state = 0;

int Main_Button_State() {
  unsigned long currentMillis = millis();
  boolean button = digitalRead(Main_Push_Button);
  if (!button) {
    if ((currentMillis - previousMillis) > 70) {
      state = 1;
    }
  }
  else {
    previousMillis = currentMillis;
    state = 0;
  }
  return state;
}

//return 0 for no click , return 1 for single click , return 2 for double click
byte click_count, clicK = 0; boolean check = 0;
unsigned long mil, mil2;

void Single_Double_Click_Events() {
  byte click_type = Click_Detect_Single_Double();
  if (click_type == 2) {
    Time_Telling();
    //click_type = 0;
  }
  else if (click_type == 1) {
    Talk();
  }
  else {
    //doing nothing
  }
  clicK = 0;
}

int Click_Detect_Single_Double() {

  boolean pushBT = Main_Button_State();
  if (pushBT == 1 && check == 0) {
    click_count++;
    check = 1;
  }
  if (pushBT == 0) {
    check = 0;
  }
  mil = millis();
  if (click_count > 0) {
    if (mil - mil2 >= 500) {
      clicK = click_count;
      click_count = 0;
    }
  }
  else {
    mil2 = mil;
  }
  return clicK;
}

unsigned long previousMillis_analog_bt = 0;
byte button_number_save = 0;

byte Pill_Box_Buttons() {
  unsigned long currentMillis_analog_bt = millis();
  byte button_number = 0;
  int button_read = analogRead(A0);
  if (button_read > 865) {
    button_number = 1;
  }
  else if (button_read > 793) {
    button_number = 2;
  }
  else if (button_read > 730) {
    button_number = 3;
  }
  else if (button_read > 674) {
    button_number = 4;
  }
  else if (button_read > 619) {
    button_number = 5;
  }
  else if (button_read > 500) {
    button_number = 6;
  }

  if (button_number != 0) {
    if (currentMillis_analog_bt - previousMillis_analog_bt > 1500) {
      button_number_save = 0;
      //previousMillis_analog_bt = currentMillis_analog_bt;
      return (button_number + 6);
    }
    else if (currentMillis_analog_bt - previousMillis_analog_bt > 100) {
      button_number_save = button_number;
    }
  }
  else {
    for (byte mem; mem < 6; mem++) {
      if ((mem + 1) == button_number_save) {
        button_number_save = 0;
        return (mem + 1);
      }
    }
    previousMillis_analog_bt = currentMillis_analog_bt;
  }
  return 0;
}
