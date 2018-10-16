#include <iostream>
#include "lib/observer.h"
#include "lib/mediator.h"
#include "lib/proxy.h"
#include "lib/common.h"
#include "lib/a_user.h"
#include "lib/b_user.h"

int main() {
    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Mediator> mediator;
    NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Proxy> proxy;
    std::cout << "Hello, World!" << std::endl;

    {
        // Observer Test

        std::cout << "{{{ start observer test" << std::endl;
        NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Observer> observer;
        NAB::TAUser a1("a1");
        NAB::TAUser a2("a2");
        NAB::TBUser b(observer);
        observer.Subscribe(NGenericHelper::EObserverEvent::OET_EVENT1, &a1);
        observer.Subscribe(NGenericHelper::EObserverEvent::OET_EVENT1, &a2);
        observer.Subscribe(NGenericHelper::EObserverEvent::OET_EVENT2, &a2);
        b.DoEvent1();
        b.DoEvent2();
        std::cout << "}}} end observer test" << std::endl;
    }
    return 0;
}