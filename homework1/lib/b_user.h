#pragma once

#include "common.h"
#include "observer.h"

#include <string>
#include <string_view>

namespace NAB {

class TBUser {
public:

    TBUser() = default;
    TBUser(NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Observer>& eventManager);
    TBUser(std::string_view id);

    // Mediator methods start
    virtual void OnStartAction();
    virtual void OnStopAction();

    // Observer method start
    virtual void DoEvent1();
    virtual void DoEvent2();

private:

    std::string Id = "Id";

    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Observer>* EventManager = nullptr;

};

}  // namespace NAB