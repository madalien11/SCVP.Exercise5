#include <unistd.h>
#include <systemc.h>

#include "kpn.h"

// ADD THINGS HERE
void kpn::Add() {
    while(true) {
        b.write(a.read() + c.read());
    }
}

void kpn::Delay() {
    while(true) {
        c.write(d.read());
    }
}

void kpn::Split() {
    int i = 0;
    while(i < 10) {
        unsigned int temp = b.read();
        a.write(temp);
        d.write(temp);
        std::cout << "The output e is: " << temp << std::endl; // Fibonacci numbers
        i++;
    }
    sc_stop();
}