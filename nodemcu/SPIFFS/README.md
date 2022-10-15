

# SPIFFS

This is a file system to store web pages, configurations, sensor calibration data etc.

Kod dosyası ile aynı konumda /data adında bir dosya oluşturulmalı. Kullanılacak dosyalar bu path atlına koyulmalı ve arduino ide de /yools/Esp8266 littleFS Data Upload seçeneği ile cihaza yüklenmeli. 

## Methods 

### LittleFS.begin()

This method mounts file system

### LittleFS.format()

### LittleFS.open(path, mode)

Opens a file
mode should be one of them “r”, “w”, “a”, “r+”, “w+”, “a+”

r ```reading mode```

r+   ```reading and writing```

w ```writing mode```

w+ ```update mode, all previous data is erased```

a ```append mode```

a+ ```append update mode, previous data is preserved, writing is only ```