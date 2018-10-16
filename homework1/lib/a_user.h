#pragma once

#include "common.h"

#include <string>
#include <string_view>

namespace NAB {

class TAUser {
public:
    TAUser() = default;
    TAUser(std::string_view id);

    virtual std::string_view GetName() const;
    virtual std::string GetId() const;

    virtual void Update(const NGenericHelper::TObserverNotifyData& data);
private:
    static constexpr std::string_view Name = "AUser";
    std::string Id = "ID";
};


}  // namespace NAB