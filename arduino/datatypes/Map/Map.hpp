#ifndef MAP_H
#define MAP_H

template <typename T, typename U> class Map {
    T keys[10];
    U values[10];
    int size = 0;
    
public:
    Map();
    void append(T key, U value);
    U remove(T key);
    U get(T key);
};

#endif
