#ifndef SSE2_H_
#define SSE2_H_

class SSE2 : Extension
{
public:
    virtual void addition(uint64_t[], int) = 0;
    virtual void substraction(uint64_t[], int) = 0;
};

#endif