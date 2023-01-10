int user_send_data;
String data;

void User_Input() {
  if (Serial.available()) {
    user_send_data = Serial.read();
    if (user_send_data == 's') {    //s = start to getting input from user
      Serial.println("Input your data");
      while (user_send_data != 'e') {     //e = end the getting input from user
        if (Serial.available()) {
          user_send_data = Serial.read();
          if (user_send_data != 10 and user_send_data != 'e') {
            if (user_send_data == 'z') {
              Data_Enter_Data_Base(data);
              data = "";
            }
            else if (user_send_data == 'd') {   //d = delete current data set
              data = "";
              Serial.println("Data Removed");
            }
            else if (user_send_data == 't') {
              Timer_Set(data);
              data = "";
            }
            else {
              data = data + char(user_send_data);
            }
          }
        }
      }
    }
    else if (user_send_data == 'r') {   //r = remove all the data from data base
      Data_Delete_Data_Base();
    }

    else if (user_send_data == 'p') {   //p = print data_set
      Print_data_base();
    }
  }
}

int int_data_set[8];
int Data_Enter_Data_Base(String data_set) {
  Serial.println(data_set);
  for (int i = 0; i < 8; i++) {
    int_data_set[i] = int(data_set[i]) - 48;
  }

  // write data on data_set 2D array
  data_base[num_of_stored_data][0] = (int_data_set[0] * 10) + int_data_set[1];
  data_base[num_of_stored_data][1] = (int_data_set[2] * 10) + int_data_set[3];
  data_base[num_of_stored_data][2] = int_data_set[4];
  data_base[num_of_stored_data][3] = int_data_set[5];
  data_base[num_of_stored_data][4] = int_data_set[6];
  data_base[num_of_stored_data][5] = int_data_set[7];

  if (num_of_stored_data < 10) {
    num_of_stored_data = num_of_stored_data + 1;
  }
  else {
    num_of_stored_data = 0;
  }
  EEPROM_write();
}


void Data_Delete_Data_Base() {
  num_of_stored_data = 0;
  Serial.println("All data deleted");
  for (byte col = 0; col < 10; col++) {
    for (byte row = 0; row < 6; row++) {
      data_base[col][row] = 255;
    }
  }
  EEPROM_write();
}

void Print_data_base() {
  Serial.println(num_of_stored_data);
  for (byte col = 0; col < 10; col++) {
    for (byte row = 0; row < 6; row++) {
      Serial.print(data_base[col][row]);
      Serial.print(',');
    }
    Serial.println();
  }
}


int int_time_set[4];
int Timer_Set(String data_set) {
  Serial.println(data_set);
  for (int i = 0; i < 4; i++) {
    int_time_set[i] = int(data_set[i]) - 48;
  }
  int h = (int_time_set[0]*10) + int_time_set[1];
  int m = (int_time_set[2]*10) + int_time_set[3];
  rtc.adjust(DateTime(2023, 1, 1, h, m, 0));
}
