#ifndef ARRAYMANAGER_H_
#define ARRAYMANAGER_H_

template<typename T>
class ArrayManager
{
public:
    ArrayManager();
    ArrayManager(int);

private:
    T *in, *out;
    int size;
};

#endif