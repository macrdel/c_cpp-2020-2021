//
// Created by user on xx.xx.2020.
//

#ifndef TEMPLATES_EXCEPTION_H
#define TEMPLATES_EXCEPTION_H
#include <cstdio>

class Exception {
public:
    virtual void Message() const = 0;
};

class EmptyQ : public Exception {
public:
    void Message() const;
};

class EmptyL : public Exception {
public:
    void Message() const;
};

class EmptyPointerAdd : public Exception {
public:
    void Message() const;
};

#endif //TEMPLATES_EXCEPTION_H
