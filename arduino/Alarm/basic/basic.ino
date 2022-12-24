#include <Time.h>
#include <TimeAlarms.h>

AlarmID_t myAlarm = 0;  // this will be the ID for the first allocated alarm

time_t earlyAlarmTime = AlarmHMS(7,30,0) ; // 7:30 am
time_t lateAlarmTime = AlarmHMS(9,0,0) ;  // 9 am


void setup()
{
  Serial.begin(9600);

  Serial.println("STARTED");
  setTime(7,29,40,1,1,10); // set time to 7:29:40am Jan 1 2010 
  // Alarm.alarmRepeat(earlyAlarmTime, alarmEvent);
  
  Alarm.alarmOnce(AlarmHMS(7,30,0), alarmEvent);
}

void alarmEvent()
{
  Serial.println("alarmEvent");
}



void loop()
{
  digitalClockDisplay();
  Alarm.delay(500);
}

void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}

void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
