#pragma once

#include <stdlib.h>

template <typename T>
void iter(T* adress, int length, void (*func)(T&)) {
    for ( int i = 0; i < length; i++){
        func(adress[i]);
    }
}