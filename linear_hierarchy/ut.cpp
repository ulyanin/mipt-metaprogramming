#include "ut.h"
#include "lib/generate_linear_hierarchy.h"
#include "lib/generate_scatter_hierarchy.h"
#include <iostream>
#include <sstream>

using namespace NLinearHierarchy;
using namespace NScatterHierarchy;

namespace NTest1 {


class TRoot {
public:
    virtual void Call() {
        std::cout << "Call::" << GetNamePretty<decltype(*this)>() << std::endl;
    }
};

template <class, class Base>
class TExample: public Base {
public:
    void Call() override {
        std::cout << "Call::" << GetNamePretty<decltype(*this)>() << std::endl;
        Base::Call();
    }
};

class TExample1 {};
class TExample2 {};
class TExample3 {};

typedef TTypeList<TExample1, TExample2, TExample3> hierarchy_list;
typedef TLinearHierarchy<hierarchy_list, TExample, TRoot> hierarchy;

} // namespace NTest1

void Test1()
{

    std::cout << "test1 {" << std::endl;
    NTest1::hierarchy test;
    test.Call();
    std::cout << "} // test1" << std::endl << std::endl;
}

namespace NTest2 {


class TExample1 {
public:
    std::string F1() {
        return "F1";
    }
};
class TExample2 {
public:
    std::string F2() {
        return "F2";
    }
};
class TExample3 {
public:
    std::string F3() {
        return "F3";
    }
};

using TWidgetInfo = TGenScatterHierarchy<TTypeList<TExample1, TExample2, TExample3>>;

template <class Base, class Derived>
std::string BaseOfPrettyPrint() {
    std::string baseName = GetNamePretty<Base>();
    std::string derivedName = GetNamePretty<Derived>();
    std::stringstream ss;
    constexpr bool isBase = std::is_base_of<Base, Derived>::value;
    ss << baseName << (isBase ? "is base of ": "is not base of ") << derivedName;
    if (isBase) {
        ss <<  std::endl << "\t\t[ class " << derivedName << ": public " << baseName << "{}; ]";
    }
    return ss.str();
}

} // namespace NTest2


void Test2()
{
    std::cout << "test2 {" << std::endl;
    std::cout << "type = " << GetNamePretty<NTest2::TWidgetInfo>() << std::endl;
    std::cout << NTest2::BaseOfPrettyPrint<NTest2::TExample1, NTest2::TWidgetInfo>() << std::endl << std::endl;
    std::cout << NTest2::BaseOfPrettyPrint<NTest2::TExample3, NTest2::TWidgetInfo>() << std::endl << std::endl;
    std::cout << NTest2::BaseOfPrettyPrint<NTest2::TWidgetInfo, NTest2::TExample1>() << std::endl << std::endl;
    NTest2::TWidgetInfo widgetInfo;
    std::cout << static_cast<NTest2::TExample1&>(widgetInfo).F1() << std::endl;
    std::cout << static_cast<NTest2::TExample2&>(widgetInfo).F2() << std::endl;
    std::cout << static_cast<NTest2::TExample3&>(widgetInfo).F3() << std::endl;
    std::cout << "} // test2" << std::endl << std::endl;
}
