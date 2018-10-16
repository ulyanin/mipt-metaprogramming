#pragma once

#include <string>

namespace NGenericHelper {

enum EObserverEvent {
    OET_EVENT1 = 0,
    OET_EVENT2 = 1,
    OET_END = 2,
};

enum class EMediatorEvent {
    Start,
    Stop,
};

enum class EGenericSpecification {
    Mediator,
    Observer,
    Proxy,
};

template<EGenericSpecification specification>
class TGenericHelper;


using TObserverNotifyData = std::string;


}  // namespace NGenericHelper