#include "Set.h"


Set::Set(size_t mp) : _bitField(mp) {
    _maxPower = mp;
}
Set::Set(const Set &s) : _maxPower(s.GetMaxPower()), _bitField(s._bitField){
} 
Set::Set(const BitField &bf) : _maxPower(bf.GetLength()), _bitField(bf){
}
size_t Set::GetMaxPower() const{
    return _maxPower;
}    
void Set::InsElem(const uint64_t Elem){
    if(Elem < _maxPower)
        _bitField.SetBit(Elem);
    else
        throw "Unable to add element";
}
void Set::DelElem(const uint64_t Elem){
    if(Elem < _maxPower)
        _bitField.ClrBit(Elem);
    else
        throw "Unable to delete element";
}
bool Set::IsMember(const uint64_t Elem) const{
    if(Elem < _maxPower){
        return _bitField.GetBit(Elem);
    }
    else return 0;
}
bool Set::operator== (const Set &s) const{
    return _bitField==s._bitField;
}
bool Set::operator!= (const Set &s) const{
    return (_bitField==s._bitField)==0;
}
Set& Set::operator=(const Set &s){
    _maxPower = s._maxPower;
    _bitField = s._bitField;
    return *this;
}
Set Set::operator+ (const uint64_t Elem){
    if(Elem < _maxPower){
        Set set = Set(*this);
        set.InsElem(Elem);
        return set;
    }
    else
        throw "Unable to add element";
}
                                  
Set Set::operator- (const uint64_t Elem){
    if(Elem < _maxPower){
        Set set = Set(*this);
        set.DelElem(Elem);
        return set;
    }
    else
        throw "Unable to delete element";
}                                
Set Set::operator+ (const Set &s){
    _bitField = _bitField | s._bitField;
    return *this;
}
Set Set::operator* (const Set &s){
    _bitField = _bitField & s._bitField;
    return *this;
}
Set Set::operator~ (){
    return ~_bitField;
}
std::vector<uint64_t> Set::GetPrimary(){
    BitField mem = _bitField;
    size_t k = 2;
    size_t l = 3;
    while(k < _maxPower){
        for(int i = l; i < _maxPower; i++){
            if((i % k) == 0)
                    mem.ClrBit(i);
                }
                k++;
                l++;
            }
            std::vector<uint64_t> vec;
            vec.push_back(1);
            for(int i = 2; i < _maxPower; i++){
                if(mem.GetBit(i)!=0)
                    vec.push_back(i);
            }
            return vec;
    //return std::vector<uint64_t>();
}