#pragma once

#include "common.h"
#include "a_user.h"

#include <unordered_set>
#include <vector>
#include <exception>

namespace NGenericHelper {

template<>
class TGenericHelper<EGenericSpecification::Observer> {
public:

    TGenericHelper<EGenericSpecification::Observer>() = default;

    void Subscribe(EObserverEvent eventType, NAB::TAUser* listener) {
        Listeners_[eventType].insert(listener);
    }

    void Unsubscribe(EObserverEvent eventType, NAB::TAUser* listener) {
        Listeners_[eventType].erase(listener);
    }

    void Notify(EObserverEvent event, const TObserverNotifyData& data) const {
        for (NAB::TAUser* aUserPtr : Listeners_[event]) {
            aUserPtr->Update(data);
        }
    }

private:
    std::array<std::unordered_multiset<NAB::TAUser*>, OET_END> Listeners_;

};


}  // namespace NGenericHelper

