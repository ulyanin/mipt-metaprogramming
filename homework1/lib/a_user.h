#pragma once

#include "common.h"

#include <string>
#include <string_view>
#include <memory>

namespace NAB {

class TBUser;

class TAUser {
public:
    TAUser() = default;
    TAUser(std::string_view id);

    // proxy constructor
    TAUser(std::shared_ptr<TBUser> bUser);

    virtual std::string_view GetName() const;
    virtual std::string GetId() const;

    // observer methods
    virtual void Update(const NGenericHelper::TObserverNotifyData& data);

    // proxy methods
    virtual void PrintGeneratedData();

private:
    static constexpr std::string_view Name_ = "AUser";
    std::string Id_ = "ID";
    std::shared_ptr<TBUser> BUser_ = nullptr;
};


}  // namespace NAB