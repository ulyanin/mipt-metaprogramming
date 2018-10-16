#pragma once

#include "common.h"
#include "b_user.h"

#include <sstream>

namespace NGenericHelper {

template<>
class TGenericHelper<EGenericSpecification::Proxy> : public NAB::TBUser {
public:
    TGenericHelper<EGenericSpecification::Proxy>() = delete;

    // the same as in TBUser
    TGenericHelper<EGenericSpecification::Proxy>(int delta, int multiplier)
        : TBUser(delta, multiplier)
    {
    }

    // wrapped method of NAB::TBUser::GenerateData()
    std::string GenerateData() {
        std::stringstream ss;
        ss << "Number = '" + NAB::TBUser::GenerateData()  << "'";
        return ss.str();
    }

};

}  // namespace NGenericHelper

