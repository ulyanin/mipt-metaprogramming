#include <memory>

#pragma once

#include "common.h"
#include "a_user.h"
#include "b_user.h"

#include <unordered_set>
#include <vector>
#include <exception>
#include <memory>

namespace NGenericHelper {


template<>
class TGenericHelper<EGenericSpecification::Mediator> {
public:
    TGenericHelper<EGenericSpecification::Mediator>() = default;

    void RegisterUsers() {
        UserOnStart = std::make_unique<NAB::TBUser>("b1");
        UserOnStop = std::make_unique<NAB::TBUser>("b2");
    }

    void Notify(const NAB::TAUser& a, EMediatorEvent event) {
        if (a.GetName() == "AUser") {
            switch (event) {
                case EMediatorEvent::Start:
                    if (UserOnStart) {
                        UserOnStart->OnStartAction();
                    }
                    break;
                case EMediatorEvent::Stop:
                    if (UserOnStop) {
                        UserOnStop->OnStopAction();
                    }
                    break;
                default:
                    throw std::invalid_argument("can't notify");
            }
        } else {
            /* smth else */
        }
    }

private:
    std::unique_ptr<NAB::TBUser> UserOnStart = nullptr;
    std::unique_ptr<NAB::TBUser> UserOnStop = nullptr;
};

}  // namespace NGenericHelper

