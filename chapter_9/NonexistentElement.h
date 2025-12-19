#ifndef QUEUEEXCEPTION_H
#define QUEUEEXCEPTION_H

#include "../chapter_2/RuntimeException.h"

class NonexistentElement : public RuntimeException {            // Exception Class to handle Queue Empty Exceptions
    public:
        NonexistentElement(const string& msg): RuntimeException(msg) {} 
};

#endif