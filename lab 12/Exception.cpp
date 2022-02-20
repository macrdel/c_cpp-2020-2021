//
// Created by user on xx.xx.2020.
//
#include "Exception.h"

void EmptyQ::Message() const {
    printf("Use of empty queue");
}

void EmptyL::Message() const {
    printf("Use of empty list");
}

void EmptyPointerAdd::Message() const {
    printf("Trying to add element before/after nullptr");
}