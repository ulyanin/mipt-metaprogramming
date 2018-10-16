#include "b_user.h"
#include "common.h"
#include "observer.h"

#include <iostream>

void NAB::TBUser::OnStartAction() {
    std::cout << "NAB::TBUser::OnStartAction:" << Id << std::endl;
}

void NAB::TBUser::OnStopAction() {
    std::cout << "NAB::TBUser::OnStopAction:" << Id << std::endl;

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

NAB::TBUser::TBUser(std::string_view id)
    : Id(id)
{
}

std::string NAB::TBUser::GenerateData() {
    return std::to_string(Delta_ + Multiplier_ * (Number_++));
}

NAB::TBUser::TBUser(int delta, int multiplier)
    : Delta_(delta)
    , Multiplier_(multiplier)
    , Number_(0)
{
}
