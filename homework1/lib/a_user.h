#pragma once

#include "common.h"

#include <string>
#include <string_view>

namespace NAB {

class TAUser {
public:
    virtual std::string_view GetName() const;

    virtual void Update(const NGenericHelper::TObserverNotifyData& data);
private:
    static constexpr std::string_view Name = "AUser";
};


}  // namespace NAB