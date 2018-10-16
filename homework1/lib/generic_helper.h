#pragma once

#include "common.h"
#include "users_classes.h"

#include <unordered_set>
#include <vector>
#include <exception>

namespace NGenericHelper {

enum EObserverEvent {
    OET_A = 0,
    OET_B = 1,
    OET_END = 2,
};

enum class EMediatorEvent {
    Start,
    Stop,
};

template<EGenericSpecification specification>
class TGenericHelper;

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

    void Notify(EObserverEvent event, const NAB::TObserverNotifyData& data) const {
        for (NAB::TAUser* aUserPtr : Listeners_[event]) {
            aUserPtr->Update(data);
        }
    }

private:
    std::array<std::unordered_multiset<NAB::TAUser*>, OET_END> Listeners_;

};

template<>
class TGenericHelper<EGenericSpecification::Proxy> {

};

}  // namespace NGenericHelper

