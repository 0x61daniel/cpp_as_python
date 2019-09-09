#include "PyString.h"
#include "sdk.h"

A::A(): imp_(new PyString){};

void A::~A()
{
    delete imp_;
}

