#include <map>
#include "Object.h"

class Decorator {
    private: //member data
        std::map<std::string, Object*> map; //themap
    public:
        Object* get(const std::string& a) //get value of attribute
        {
            return map[a];
        }

        void set(const std::string& a, Object* d) //set value
        {
            map[a]=d;
        }
};