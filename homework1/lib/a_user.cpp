#include "a_user.h"

#include <iostream>

std::string_view NAB::TAUser::GetName() const {
    return Name;
}

void NAB::TAUser::Update(const NGenericHelper::TObserverNotifyData& data) {
    std::cout << "NAB::TAUser::Update: " << data << std::endl;
}
