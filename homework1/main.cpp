#include <iostream>
#include "lib/observer.h"
#include "lib/mediator.h"
#include "lib/proxy.h"

int main() {
    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Mediator> mediator;
    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Observer> observer;
    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Proxy> proxy;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}