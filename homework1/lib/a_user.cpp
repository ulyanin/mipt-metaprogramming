#include "a_user.h"

#include <iostream>

std::string_view NAB::TAUser::GetName() const {
    return Name;
}

void NAB::TAUser::Update(const NGenericHelper::TObserverNotifyData& data) {
    std::cout << "Update: " << GetId() << " " << data << std::endl;
}

NAB::TAUser::TAUser(std::string_view id)
    : Id(id)
{
}

std::string NAB::TAUser::GetId() const {
    return Id;
}
