#include <iostream>
#include "lib/generic_helper.h"

int main() {
    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Mediator> mediator;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}