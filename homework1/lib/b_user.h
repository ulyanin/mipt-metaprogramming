#pragma once

#include "common.h"
#include "observer.h"

#include <string>
#include <string_view>

namespace NAB {

class TBUser {
public:
    virtual void OnStartAction();
    virtual void OnStopAction();

private:

    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Observer> eventManager;

};

}  // namespace NAB