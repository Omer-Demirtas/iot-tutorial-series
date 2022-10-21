#include "Map.hpp";
#include "Arduino.h";


template <typename T, typename U> Map<T, U>::Map() { }

template <typename T, typename U> void Map<T, U>::append(T key, U value)
{
    size++;
    keys[size] = key;
    values[size] = value;
}

template <typename T, typename U> U Map<T, U>::get(T key)
{
  U u;
  for (int i = 0; i < size; i++)
  {
    if(keys[i] == key)
    {
      return values[i];
    }
  }
  return u;
}

template <typename T, typename U> U Map<T, U>::remove(T key)
{ }

template class Map<String, int>;
template class Map<String, String>;
