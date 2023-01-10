#include <EEPROM.h>
#include "RTClib.h"
#define Buzzer 12
#define Main_Push_Button 8

boolean boxes[6] = {0, 0, 0, 0, 0, 0};
byte number_of_pills[6] = {0, 0, 0, 0, 0, 0};
byte half_or_full[6] = {0, 0, 0, 0, 0, 0};
byte pre_after_meals[6] = {0, 0, 0, 0, 0, 0};

//------------------------------------
#include <DFMiniMp3.h>
#include <SoftwareSerial.h>

class Mp3Notify;

SoftwareSerial secondarySerial(10, 11); // RX, TX
typedef DFMiniMp3<SoftwareSerial, Mp3Notify> DfMp3;
DfMp3 dfmp3(secondarySerial);

class Mp3Notify
{
  public:
    static void PrintlnSourceAction(DfMp3_PlaySources source, const char* action)
    {
      if (source & DfMp3_PlaySources_Sd)
      {
        Serial.print("SD Card, ");
      }
      if (source & DfMp3_PlaySources_Usb)
      {
        Serial.print("USB Disk, ");
      }
      if (source & DfMp3_PlaySources_Flash)
      {
        Serial.print("Flash, ");
      }
      Serial.println(action);
    }
    static void OnError([[maybe_unused]] DfMp3& mp3, uint16_t errorCode)
    {
      // see DfMp3_Error for code meaning
      Serial.println();
      Serial.print("Com Error ");
      Serial.println(errorCode);
    }
    static void OnPlayFinished([[maybe_unused]] DfMp3& mp3, [[maybe_unused]] DfMp3_PlaySources source, uint16_t track)
    {
      Serial.print("Play finished for #");
      Serial.println(track);
    }
    static void OnPlaySourceOnline([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources source)
    {
      PrintlnSourceAction(source, "online");
    }
    static void OnPlaySourceInserted([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources source)
    {
      PrintlnSourceAction(source, "inserted");
    }
    static void OnPlaySourceRemoved([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources source)
    {
      PrintlnSourceAction(source, "removed");
    }
};
//------------------------------------

RTC_DS1307 rtc;

int num_of_stored_data = 0; // number of data stored in data base array
int data_base[10][6] = {
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
};

byte now_time[2] = {0, 0};


void setup() {
  Serial.begin(9600);
  //----------------------------
  Serial.println("initializing...");
  dfmp3.begin();
  uint16_t volume = dfmp3.getVolume();
  Serial.print("volume ");
  Serial.println(volume);
  dfmp3.setVolume(25);

  uint16_t count = dfmp3.getTotalTrackCount(DfMp3_PlaySource_Sd);
  Serial.print("files ");
  Serial.println(count);

  Serial.println("starting...");
  //----------------------------

  EEPROM_read();
#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  pinMode(Buzzer, OUTPUT);
  pinMode(Main_Push_Button, INPUT_PULLUP);
}

void waitMilliseconds(uint16_t msWait)
{
  uint32_t start = millis();

  while ((millis() - start) < msWait)
  {
    // if you have loops with delays, its important to
    // call dfmp3.loop() periodically so it allows for notifications
    // to be handled without interrupts
    dfmp3.loop();
    delay(1);
  }
}


void loop() {
  Single_Double_Click_Events();
  User_Input();
  Time_and_Alarm();
  //Time_Telling();
  //Serial.println(analogRead(A0));
}
