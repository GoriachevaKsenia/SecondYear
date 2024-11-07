#include "BitField.h"


size_t BitField::GetMemIndex(size_t n) const{
   if (n < _sizeBit) {return n/(8 * sizeof(uint16_t));}
        throw "Bit out of range!";
}
uint16_t BitField::GetMask(size_t n) const {
    return 1 << (n % (8 * sizeof(uint16_t)));
}

BitField::BitField(size_t len) {
    _sizeBit = len;
    _memSize = (len / (8 * sizeof(uint16_t))) + (len % (8 * sizeof(uint16_t)) != 0);
    _mem = new uint16_t[_memSize];
    for (size_t i = 0; i < _memSize; ++i)
        _mem[i] = 0;
}

BitField::BitField(const BitField& tmp) {
    _sizeBit = tmp._sizeBit;
    _memSize = tmp._memSize;
    _mem = new uint16_t[_memSize];
    for (size_t i = 0; i < _memSize; ++i)
        _mem[i] = tmp._mem[i];
}

BitField& BitField::operator=(const BitField& tmp) {
   if (_sizeBit != tmp._sizeBit){
        _sizeBit = tmp._sizeBit;
        _memSize = tmp._memSize;
        delete [] _mem;
        _mem = new uint16_t[tmp._memSize];
    }
    for (size_t i = 0; i < _memSize; ++i)
        _mem[i] = tmp._mem[i];
    return *this;
}
    
size_t BitField::GetLength() const {
    return _sizeBit;
}
void BitField::SetBit(size_t n) {
    if (n >= _sizeBit)
        throw "Bit out of range!";
    _mem[GetMemIndex(n)] |= GetMask(n);
}
void BitField::ClrBit(size_t n) {
     if (n < _sizeBit)
        _mem[GetMemIndex(n)] &= ~GetMask(n);  
}
uint8_t BitField::GetBit(size_t n) const {
    uint16_t tmp = _mem[GetMemIndex(n)];
    tmp &= GetMask(n);
    return (tmp != 0 ? 1:0);
}
BitField BitField::operator|(const BitField& tmp) {
    if (_memSize != tmp._memSize){
        _sizeBit = tmp._sizeBit;
        _memSize = tmp._memSize;
        delete [] _mem;
        _mem = new uint16_t[tmp._memSize];
    }
    BitField mem = BitField(*this);
    for(int i = 0; i < _memSize; i++){
       mem._mem[i] = _mem[i] | tmp._mem[i];
    }
    return mem;
}

BitField BitField::operator&(const BitField& tmp) {
    if (_memSize != tmp._memSize){
        _sizeBit = tmp._sizeBit;
        _memSize = tmp._memSize;
        delete [] _mem;
        _mem = new uint16_t[tmp._memSize];
    }
    BitField mem = BitField(*this);
    for(int i = 0; i < _memSize; i++){
        mem._mem[i] = _mem[i] & tmp._mem[i];
    }
    return mem;
}
BitField BitField::operator^(const BitField& tmp) {
     if (_memSize != tmp._memSize){
        _sizeBit = tmp._sizeBit;
        _memSize = tmp._memSize;
        delete [] _mem;
        _mem = new uint16_t[tmp._memSize];
    }
    BitField mem = BitField(*this);
    for(int i = 0; i < _memSize; i++){
        mem._mem[i] = _mem[i] ^ tmp._mem[i];
    }
    return mem;
}
bool BitField::operator==(const BitField& tmp) const{
    if(_memSize != tmp._memSize){return false;}
    for(int i = 0; i < _memSize; i++){
        if(_mem[i] != tmp._mem[i]){return false;}
    }

    return true;
}
BitField BitField::operator~(){  // здесь неправильно
    BitField mem = BitField(*this);
    for(int i = 0; i < _sizeBit; i++){
       if(GetBit(i) == 1){mem.ClrBit(i);}
       if(GetBit(i) == 0){mem.SetBit(i);}
    }
    return mem;
}
