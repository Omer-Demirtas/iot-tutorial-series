#ifndef MAP_H
#define MAP_H

template <typename T, typename U> class Map {
  private:
    int size = 0;
    int mapSize;
    T* keys;
    U* values;
    
    
  public:
    Map(int mSize);
    void append(T key, U value);
    U remove(T key);
    U get(T key);
    int getSize() {return size;};
};

#endif
