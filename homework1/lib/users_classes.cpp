//
// Created by ulyanin on 16.10.18.
//

#include "users_classes.h"
#include "generic_helper.h"

#include <iostream>

std::string_view NAB::TAUser::GetName() const {
    return Name;
}

void NAB::TAUser::Update(const NAB::TObserverNotifyData& data) {
    std::cout << "NAB::TAUser::Update: " << data << std::endl;
}


void NAB::TBUser::OnStartAction() {
    std::cout << "NAB::TBUser::OnStartAction" << std::endl;
}

void NAB::TBUser::OnStopAction() {
    std::cout << "NAB::TBUser::OnStopAction" << std::endl;

}
