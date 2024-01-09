#ifndef KPN_H
#define KPN_H

#include <systemc.h>

SC_MODULE(kpn)
{
private:
    // ADD THINGS HERE
    sc_fifo<unsigned int> a, b, c, d;
    void Add();
    void Split();
    void Delay();

public:
    SC_CTOR(kpn) : a(10), b(10), c(10), d(10) // : ADD THINGS HERE
    {
        // ADD THINGS HERE
        b.write(1);
        c.write(0);
        SC_THREAD(Split);
        SC_THREAD(Add);
        SC_THREAD(Delay);
    }
};

#endif // KPN_H
