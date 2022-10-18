#include "Map.hpp";
#include "Arduino.h";


template <typename T> Map<T>::Map()
{
    Serial.println("Map created!!");
}

template <typename T> void Map<T>::append(char *str, T value)
{
    Serial.println("append");
    Serial.println(str);
    Serial.println(value);
}


template class Map<int>;
template class Map<String>;
