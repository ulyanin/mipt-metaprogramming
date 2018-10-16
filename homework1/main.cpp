#include <iostream>
#include <memory>
#include "lib/observer.h"
#include "lib/mediator.h"
#include "lib/proxy.h"
#include "lib/common.h"
#include "lib/a_user.h"
#include "lib/b_user.h"

int main() {
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
    std::cout << std::endl;
    {
        // Mediator test

        std::cout << "{{{ start mediator test" << std::endl;
        NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Mediator> mediator;
        mediator.RegisterUsers();
        NAB::TAUser a("a");
        mediator.Notify(a, NGenericHelper::EMediatorEvent::Start);
        mediator.Notify(a, NGenericHelper::EMediatorEvent::Stop);
        std::cout << "}}} end mediator test" << std::endl;

    }
    std::cout << std::endl;
    {
        // Proxy test

        std::cout << "{{{ start proxy test" << std::endl;

        std::shared_ptr<NAB::TBUser> bUser1(new NAB::TBUser(2, 1));
        std::shared_ptr<NAB::TBUser> bUser2(new NGenericHelper::TGenericHelper<NGenericHelper::EGenericSpecification::Proxy>(2, 1));

        NAB::TAUser aUser1(bUser1);
        NAB::TAUser aUser2(bUser2);

        std::cout << "method without proxy:" << std::endl;
        aUser1.PrintGeneratedData();
        std::cout << "method over proxy:" << std::endl;
        aUser2.PrintGeneratedData();
        std::cout << "}}} end proxy test" << std::endl;

    }
    return 0;
}