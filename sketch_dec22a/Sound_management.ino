void Time_Telling() {
  byte hours_ = now_time[0];
  byte minutes_ = now_time[1];
  byte hours_convert = 0;
  byte minutes_convert = 0;


  if (hours_ < 12) { //am times
    if (hours_ == 0) {
      hours_convert = 12;
    }
    else {
      hours_convert = hours_;
    }
    minutes_convert = minutes_ + 13;

    Serial.print("track - Good morning - ");
    Serial.println("73");
    dfmp3.playMp3FolderTrack(73);
    waitMilliseconds(2000);

    Serial.print("track - ");
    Serial.println(hours_convert);
    dfmp3.playMp3FolderTrack(hours_convert);
    waitMilliseconds(2000);

    Serial.print("track - ");
    Serial.println(minutes_convert);
    dfmp3.playMp3FolderTrack(minutes_convert);
    waitMilliseconds(2000);

    Serial.println("AM - track 77");
    dfmp3.playMp3FolderTrack(77);
    waitMilliseconds(2000);
  }

  else { //pm time
    if (hours_ == 12) {
      hours_convert = 12;
    }
    else {
      hours_convert = hours_ - 12;
    }
    minutes_convert = minutes_ + 13;

    Serial.print("track - Afternoon - ");
    Serial.println("74");
    dfmp3.playMp3FolderTrack(74);
    waitMilliseconds(2000);

    Serial.print("track - ");
    Serial.println(hours_convert);
    dfmp3.playMp3FolderTrack(hours_convert);
    waitMilliseconds(2000);

    Serial.print("track - ");
    Serial.println(minutes_convert);
    dfmp3.playMp3FolderTrack(minutes_convert);
    waitMilliseconds(2000);

    Serial.println("PM - track 78");
    dfmp3.playMp3FolderTrack(78);
    waitMilliseconds(2000);
  }
  delay(1000);
  //while (1);
}

void Talk() {
  Serial.println("You have...");
  dfmp3.playMp3FolderTrack(79);
  waitMilliseconds(2000);
}
