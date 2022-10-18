#include "Map.hpp";
#include "Arduino.h";


template <typename T, typename U> Map<T, U>::Map()
{
    Serial.println("Map created!!");
}

template <typename T, typename U> void Map<T, U>::append(T key, U value)
{
    size++;
    keys[size] = key;
    values[size] = value;
    Serial.print(key);
    Serial.println(value);
}

template <typename T, typename U> U Map<T, U>::get(T key)
{
  Serial.println(key);
  for (int i = 0; i < size; i++)
  {
    if(keys[i] == key)
    {
      Serial.print("found with  ");
      Serial.print(i);

      return values[i];
    }
  }
  return;
}

template class Map<String, int>;
template class Map<String, String>;
