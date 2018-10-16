#include "a_user.h"
#include "b_user.h"

#include <iostream>
#include <cassert>

std::string_view NAB::TAUser::GetName() const {
    return Name_;
}

void NAB::TAUser::Update(const NGenericHelper::TObserverNotifyData& data) {
    std::cout << "Update: " << GetId() << " " << data << std::endl;
}

NAB::TAUser::TAUser(std::string_view id)
    : Id_(id)
{
}

std::string NAB::TAUser::GetId() const {
    return Id_;
}

void NAB::TAUser::PrintGeneratedData() {
    assert(BUser_ != nullptr);
    std::cout << BUser_->GenerateData() << std::endl;
}

NAB::TAUser::TAUser(std::shared_ptr<NAB::TBUser> bUser)
    : BUser_(bUser)
{
}
