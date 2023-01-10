void Taking_Pill_Box_Inputs() {

  byte you_have_drink = boxes[0] + boxes[1] + boxes[2] + boxes[3] + boxes[4] + boxes[5];
  Serial.print("114 - ");
  Serial.println(you_have_drink + 79);
  dfmp3.playMp3FolderTrack(114);
  waitMilliseconds(3000);
  dfmp3.playMp3FolderTrack(you_have_drink + 79);
  waitMilliseconds(3000);
  delay(100);

  while (boxes[0] + boxes[1] + boxes[2] + boxes[3] + boxes[4] + boxes[5]) {
    byte pillbox_bt_number = Pill_Box_Buttons();

    if (pillbox_bt_number <= 6 && pillbox_bt_number != 0) {
      Serial.println(pillbox_bt_number);

      if (boxes[pillbox_bt_number - 1] == 1) {

        Serial.println(pillbox_bt_number);
        int mp3_number = 85 + (number_of_pills[pillbox_bt_number - 1] * 2) + half_or_full[pillbox_bt_number - 1];
        Serial.println(mp3_number);
        dfmp3.playMp3FolderTrack(mp3_number);
        waitMilliseconds(5000);

        if (pre_after_meals[pillbox_bt_number - 1]) {
          Serial.println("115");
          dfmp3.playMp3FolderTrack(115);
          waitMilliseconds(3000);
        }
        else {
          Serial.println("116");
          dfmp3.playMp3FolderTrack(116);
          waitMilliseconds(3000);
        }
      }
    }
    else if (pillbox_bt_number > 6 && pillbox_bt_number != 0) {
      if ( boxes[pillbox_bt_number - 7] != 0) {
        Serial.println("119");
        dfmp3.playMp3FolderTrack(119);
        waitMilliseconds(6000);
      }
      boxes[pillbox_bt_number - 7] = 0;
    }
    if (Main_Button_State() == 1) {
      byte you_have_drink = boxes[0] + boxes[1] + boxes[2] + boxes[3] + boxes[4] + boxes[5];
      Serial.println(you_have_drink + 79);
      dfmp3.playMp3FolderTrack(you_have_drink + 79);
      waitMilliseconds(3000);
      //delay(1000);
    }
  }
  Serial.println("118");
  dfmp3.playMp3FolderTrack(118);
  waitMilliseconds(6000);
  delay(5000);
}

// boxes, number_of_pills, half_or_full, pre_after_meals
