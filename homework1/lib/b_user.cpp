#include "b_user.h"
#include "common.h"
#include "observer.h"

#include <iostream>

void NAB::TBUser::OnStartAction() {
    std::cout << "NAB::TBUser::OnStartAction" << std::endl;
}

void NAB::TBUser::OnStopAction() {
    std::cout << "NAB::TBUser::OnStopAction" << std::endl;

}

void NAB::TBUser::DoEvent1() {
    std::cout << "NAB::TBUser::DoEvent1" << std::endl;
    EventManager->Notify(NGenericHelper::OET_EVENT1, "B done event1");
}

void NAB::TBUser::DoEvent2() {
    std::cout << "NAB::TBUser::DoEvent2" << std::endl;
    EventManager->Notify(NGenericHelper::OET_EVENT2, "B done event2");
}

NAB::TBUser::TBUser(NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Observer>& eventManager)
    : EventManager(&eventManager)
{
}
