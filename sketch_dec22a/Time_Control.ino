int current_hour, current_min;

void Time_and_Alarm() {
  DateTime now = rtc.now();
  current_hour = now.hour(), DEC;
  current_min = now.minute(), DEC;

  now_time[0] = current_hour;
  now_time[1] = current_min;

  for (byte i = 0; i < 10; i++) {
    if (data_base[i][0] == current_hour && data_base[i][1] == current_min) {
      alarm_time_detected();
    }
  }
}

//globel variables
boolean exit_alarm = false;

void alarm_time_detected() {
  for (byte i = 0; i < 10; i++) {
    if (data_base[i][0] == current_hour && data_base[i][1] == current_min) {
      boxes[(data_base[i][2]) - 1] = 1;
      number_of_pills[(data_base[i][2]) - 1] = data_base[i][3];
      half_or_full[(data_base[i][2]) - 1] = data_base[i][4];  // half = 1
      pre_after_meals[(data_base[i][2]) - 1] = data_base[i][5]; // pre = 1 after = 2
    }
  }

  int counter = 0;
  unsigned long previousMillis = 0;
  const long interval = 1000;

  boolean main_push_button_state = 0;
  while (!main_push_button_state && counter < 500) {
    Serial.println(counter);
    main_push_button_state = Main_Button_State();
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= 500) {
      previousMillis = currentMillis;
      counter++;
      byte value = ((counter / 100) + 1) % 2;
      digitalWrite(Buzzer, (counter % 2 * value));
    }
  }

  if (counter < 500) {
    digitalWrite(Buzzer, LOW);
    Serial.println("User clicked the button");
    Taking_Pill_Box_Inputs();
    //which means user clicked the main push button
  }
  else {
    for(byte i = 0; i < 0; i++){
      boxes[i] = 0;
      number_of_pills[i] = 0;
      half_or_full[i] = 0;
      pre_after_meals[i] = 0;
    }
    counter = 0;
    previousMillis = 0;
    digitalWrite(Buzzer, LOW);
    Serial.println("End No click");
  }
}
