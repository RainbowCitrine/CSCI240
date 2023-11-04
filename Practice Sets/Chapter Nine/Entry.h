#ifndef ENTRY_H
#define ENTRY_H 


template <typename K, typename V>
class Entry
{
public: 
    typedef K Key; // key type
    typedef V Value; // value type

    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) { } // constructor
    const K& key() const {return _key;} // return key
    const V& value() const {return _value;} // return value
    void setKey(const K& k) {_key = k;} // set key
    void setValue(const V& v) {_value = v;} // set value
private: 
    K _key; // key 
    V _value; // value
};

#endif