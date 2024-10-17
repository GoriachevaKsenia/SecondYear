#include <iostream>
#include <algorithm>
#include <limits>
template<typename T>
class ArrayHandler {
private:
    T* _array;
    size_t _size;
    size_t _count;
    T Min;
    T Max;
public:
    ArrayHandler(size_t size = 10000000) {
        _array = new T[size];
        _size = size;
        _count = 0;
        Max = 0;
        Min = std::numeric_limits<T>::max();
    }

    void AppendElem(T elem) {
       _array[_count++] = elem;
        if(elem > Max)
            Max = elem;
        if(elem < Min)
            Min = elem;
    }

    bool IsContains(T elem) {
        for(int i = 0; i < _count; i++){
            if(elem == _array[i]) return true;
        }
        return false;
    }

    T GetMax() {
        return Max;
    }

    T GetMin() {
        return Min;
    }

    ~ArrayHandler() {
        delete [] _array;
    }

};