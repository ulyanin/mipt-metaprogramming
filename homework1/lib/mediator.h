#pragma once

#include "common.h"
#include "a_user.h"
#include "b_user.h"

#include <unordered_set>
#include <vector>
#include <exception>

namespace NGenericHelper {

//template<EGenericSpecification specification>
//class TGenericHelper;


template<>
class TGenericHelper<EGenericSpecification::Mediator> {
public:
    TGenericHelper<EGenericSpecification::Mediator>() = default;

    void Notify(const NAB::TAUser* a, EMediatorEvent event) {
        if (a->GetName() == "AUser") {
            switch (event) {
                case EMediatorEvent::Start:
                    userOnStart->OnStartAction();
                    break;
                case EMediatorEvent::Stop:
                    userOnStop->OnStopAction();
                    break;
                default:
                    throw std::invalid_argument("can't notify");
            }
        } else {
            /* smth else */
        }
    }

private:
    NAB::TBUser* userOnStart;
    NAB::TBUser* userOnStop;
};

}  // namespace NGenericHelper

