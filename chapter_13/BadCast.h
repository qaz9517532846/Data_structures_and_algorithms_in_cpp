#ifndef QUEUEEXCEPTION_H
#define QUEUEEXCEPTION_H

#include "../chapter_2/RuntimeException.h"

class BadCast : public RuntimeException {            // Exception Class to handle Queue Empty Exceptions
    public:
        BadCast(const std::string& msg): RuntimeException(msg) {} 
};

#endif
