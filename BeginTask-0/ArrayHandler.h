#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>
#include <vector>
template<typename T>
class ArrayHandler {
private:
    size_t _size;
    std::vector<T> _array;
    size_t _count;
    T Min;
    T Max;
public:
    ArrayHandler(size_t size = 10) {
        _size = size;
        _count = 0;
        Max = std::numeric_limits<T>::min();
        Min = std::numeric_limits<T>::max();
    }

    void AppendElem(T elem) {
       _array.push_back(elem);
        _count++;
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
        _array.clear();
    }

};