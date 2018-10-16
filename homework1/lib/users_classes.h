#pragma once

#include "common.h"

#include <string>
#include <string_view>

namespace NGenericHelper {

// forward declarations

template<EGenericSpecification specification>
class TGenericHelper;

}

namespace NAB {

using TObserverNotifyData = std::string;

class TAUser {
public:
    virtual std::string_view GetName() const;

    virtual void Update(const TObserverNotifyData& data);
private:
    static constexpr std::string_view Name = "AUser";
};

class TBUser {
public:
    virtual void OnStartAction();
    virtual void OnStopAction();

private:

//    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Observer> eventManager;

};

}  // namespace NAB