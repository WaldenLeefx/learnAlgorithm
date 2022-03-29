//
// Created by lee on 2021/12/22.
//

#ifndef UNTITLED_ILLEGALPARAMETERVALUE_H
#define UNTITLED_ILLEGALPARAMETERVALUE_H

#include <iostream>

class illegalParameterValue
{
public:
    illegalParameterValue() : message("Illegal Parameter Value") {}
    illegalParameterValue(const char* theMessage) {message = theMessage;}
    void outputMessage() {std::cout << message << std::endl;}

private:
    std::string message;
};

#endif //UNTITLED_ILLEGALPARAMETERVALUE_H
