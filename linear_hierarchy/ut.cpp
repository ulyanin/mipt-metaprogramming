#include "ut.h"
#include "lib/generate_linear_hierarchy.h"
#include "lib/generate_scatter_hierarchy.h"
#include "lib/generate_fibonaccy_hierarchy.h"
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

template <class Base>
class TExample: public Base {
public:
    void Call() override {
        std::cout << "Call::" << GetNamePretty<decltype(*this)>() << std::endl;
        Base::Call();
    }
};

class TExample1 {
public:
    void Call1() {
        std::cout << "Call1::" << GetNamePretty<decltype(*this)>() << std::endl;
    }

};
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
    test.Call1();
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
    // it is possible to call any of F1, F2, F3:
    std::cout << static_cast<NTest2::TExample1&>(widgetInfo).F1() << std::endl;
    std::cout << static_cast<NTest2::TExample2&>(widgetInfo).F2() << std::endl;
    std::cout << static_cast<NTest2::TExample3&>(widgetInfo).F3() << std::endl;
    std::cout << "} // test2" << std::endl << std::endl;
}

namespace NTest3 {

template <size_t n>
class TInt
{
public:
    virtual size_t GetValue() const {
        return n;
    }

    virtual void PrintMe() const {
        std::cout << std::to_string(n) << std::endl;
    }

};

template <size_t n, size_t cur = 0, class TypeList = TEmptyTypeList>
struct TGenTypeList;

template <size_t n, size_t cur, class ...T>
struct TGenTypeList<n, cur, TTypeList<T...>>
{
private:
    using TElem = TInt<n>;

public:
    using TResult = typename TGenTypeList<n - 1, cur + 1, TTypeList<TElem, T...>>::TResult;
};

template <size_t cur, class ...T>
struct TGenTypeList<0, cur, TTypeList<T...>>
{
    using TResult = TTypeList<T...>;
};


using TLongTypeList = TGenTypeList<10>::TResult;
using TSplitList = typename NFibonaccyHierarchy::TSplitTypeListWithFibonaccy<TLongTypeList>::TResult;

} // namespace NTest3

void Test3()
{
    std::cout << "test 3 {" << std::endl;
    std::cout  << GetNamePretty<NTest3::TLongTypeList>() << std::endl;
    std::cout  << GetNamePretty<NTest3::TSplitList>() << std::endl;
    std::cout << "} // test 3" << std::endl << std::endl;
}


namespace NTest4 {

using TTypeListOfLinear = typename NFibonaccyHierarchy::TMapLinearHierarchy<NTest1::TExample, NTest3::TSplitList>::TResult;
using TScatter = TGenScatterHierarchy<NTest3::TSplitList>;

}

void Test4()
{

    std::cout << "test 4 {" << std::endl;
    NTest4::TScatter allall;
    std::cout << "} // test 4" << std::endl << std::endl;

}

namespace NTestFinal {

class TIntRoot {
public:
    virtual void Print() {

    }
};

template <class Base>
struct TIntUnit: public Base
{
public:
    void Print() override {
        std::cout << "PrintMe::" << GetNamePretty<decltype(*this)>() << std::endl;
        Base::Print();
    }
};

using TSuperMegaTypeOfScatterOfLinearOfTypeList = NFibonaccyHierarchy::TGenerateFibonaccyHierarchy<
    NTestFinal::TIntUnit, NTest3::TLongTypeList, NTestFinal::TIntRoot>;

}

void TestFinal() {
    std::cout << "test final {" << std::endl;
    NTestFinal::TSuperMegaTypeOfScatterOfLinearOfTypeList superMegaTypeOfScatterOfLinearOfTypeList;
    std::cout << GetNamePretty<NTestFinal::TSuperMegaTypeOfScatterOfLinearOfTypeList>() << std::endl;
    std::cout << std::endl << "first of all we could use any of function from TList<TInt<1>, TInt<2>, ...>" << std::endl;
    std::cout << static_cast<const NTest3::TInt<6>&>(superMegaTypeOfScatterOfLinearOfTypeList).GetValue() << std::endl;
    std::cout << static_cast<const NTest3::TInt<1>&>(superMegaTypeOfScatterOfLinearOfTypeList).GetValue() << std::endl;
    std::cout << std::endl << "also we could call chain of Print from Linear[3, 4]" << std::endl;
    superMegaTypeOfScatterOfLinearOfTypeList.TRightBase::TLeftBase::Print();

    std::cout << std::endl << "also out class if base of any TInt<1>..TInt<10>" << std::endl;
    std::cout << std::is_base_of_v<NTest3::TInt<1>, NTestFinal::TSuperMegaTypeOfScatterOfLinearOfTypeList> << std::endl;
    std::cout << std::is_base_of_v<NTest3::TInt<5>, NTestFinal::TSuperMegaTypeOfScatterOfLinearOfTypeList> << std::endl;
    std::cout << std::is_base_of_v<NTest3::TInt<10>, NTestFinal::TSuperMegaTypeOfScatterOfLinearOfTypeList> << std::endl;
    std::cout << "but not 11:" << std::endl;
    std::cout << std::is_base_of_v<NTest3::TInt<11>, NTestFinal::TSuperMegaTypeOfScatterOfLinearOfTypeList> << std::endl;

    std::cout << "} // test final" << std::endl << std::endl;
};