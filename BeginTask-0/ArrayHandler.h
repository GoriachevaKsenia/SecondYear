
template<typename T>
class ArrayHandler {
private:
    size_t _size;
    T* _array;
    size_t _count;
    int Min;
    int Max;
public:
    ArrayHandler(size_t size = 10) {
        _size = size;
        _array = new T[_size];
        _count = 0;
        Min = 10000000;
        Max = -1;
    }

    void AppendElem(T elem) {
        if (_count == _size){
            T* array = new T[_size];
            for(int i = 0; i < _size; i++)
                array[i] = _array[i];
            delete [] _array;
            _size++;
            _array = array;
        }
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

//std::find(_array, _array+_count, elem)!=(_array +_count);