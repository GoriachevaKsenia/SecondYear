#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>
template<typename T>
class ArrayHandler {
private:
    size_t _size;
    T* _array;
    size_t _count;
    T Min;
    T Max;
public:
    ArrayHandler(size_t size = 10) {
        _size = size;
        _array = (T*)malloc(size);
        _count = 0;
        Max = std::numeric_limits<T>::min();
        Min = std::numeric_limits<T>::max();
    }

    void AppendElem(T elem) {
       if (_count == _size){
            _array = (T*) realloc(_array, _size + sizeof(T));
        }
        _array[_count] = elem;
        _count++;
        if(elem > Max)
            Max = elem;
        if(elem < Min)
            Min = elem;
    }

    bool IsContains(T elem) {
        return std::find(_array, _array+_count, elem)!=(_array +_count);
    }

    T GetMax() {
        return Max;
    }

    T GetMin() {
        return Min;
    }

    ~ArrayHandler() {
        free(_array);
    }

};