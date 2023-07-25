#include "pxt.h"
using namespace pxt;

//% block
void myFunction(StringData* text) {
    int len = text->getLength();
    const char16_t* data = text->getData();

    // iterate over each char16_t element
    for(int i = 0; i < len; ++i) {
        // you can access each char16_t element as data[i]
        uBit.serial.printf("%04x ", data[i]);
    }
    uBit.serial.printf("\n");
}

namespace myExtension {
    //% shim=myExtension::myFunction
    void myFunction(String text) {
        myFunction(text->getUTF16Data());
    }
}