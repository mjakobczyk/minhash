#include "extension.h"

void minhash::Extension::setElementsInSingleVariable(const int amount)
{
    this->elementsInSingleVariable = amount;
}

int minhash::Extension::getElementsInSingleVariable()
{
    return this->elementsInSingleVariable;
}