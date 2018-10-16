#pragma once

#include "common.h"
#include "observer.h"

#include <string>
#include <string_view>

namespace NAB {

class TBUser {
public:

    TBUser() = default;
    // observer constructor
    TBUser(NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Observer>& eventManager);
    // mediator constructor
    TBUser(std::string_view id);
    // proxy constructor
    TBUser(int delta, int multiplier);

    // Mediator methods start
    virtual void OnStartAction();
    virtual void OnStopAction();

    // Observer method start
    virtual void DoEvent1();
    virtual void DoEvent2();

    // ProxyMethods
    virtual std::string GenerateData();

private:

    std::string Id = "Id_";

    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Observer>* EventManager = nullptr;

    int Number_ = 0;
    int Delta_ = 0;
    int Multiplier_ = 0;

};

}  // namespace NAB