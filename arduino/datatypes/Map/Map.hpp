#ifndef MAP_H
#define MAP_H

template <typename T> class Map {
    char* key;
    T value;
    
public:
    Map();
    void append(char *str, T value);
};

#endif
