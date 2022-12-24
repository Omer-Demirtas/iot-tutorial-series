
# Alarm

## Libreries

```
#include <Time.h>
#include <TimeAlarms.h>
```

## set card time to spesific time.

```
setTime(7,29,40,1,1,22); //7:29:40am Jan 1 2010 
```

## create alarm

### Alarm Once

```
Alarm.alarmOnce(AlarmHMS(7,30,0), alarmEvent);
```
