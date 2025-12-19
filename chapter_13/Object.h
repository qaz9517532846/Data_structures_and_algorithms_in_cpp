#include <iostream>
#include <vector>
#include <string>
#include "BadCast.h"

class Integer; // forward declaration

class Object { // generic object
    public:
        virtual ~Object() {}  // Add virtual destructor
        int intValue() const throw(BadCast);
        std::string stringValue() const throw(BadCast);
};

class Integer : public Object {
    private:
        int value;
    public:
        Integer(int v=0) : value(v) {}
        int getValue() const
        {
            return value;
        }
};

class String : public Object {
    private:
        std::string value;
    public:
        String(std::string v="") : value(v){}
        std::string getValue() const
        {
            return value;
        }
};

int Object::intValue() const throw(BadCast) { //cast to Integer
    const Integer* p = dynamic_cast<const Integer*>(this);
    if (p == NULL) throw BadCast("Illegal attempt to cast to Integer");
    return p->getValue();
}