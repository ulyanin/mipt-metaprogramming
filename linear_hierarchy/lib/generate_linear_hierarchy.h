#pragma once

#include "lib/typelist.h"

#include <iostream>
#include <cxxabi.h>
#include <string>

namespace NLinearHierarchy {


template<class T>
std::string GetNamePretty() {
    int status;
    return abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
}

class TEmptyType
{
};


template <
    typename TypeList,
    template<class, class> class Unit,
    typename Root = TEmptyType
>
class TLinearHierarchy;


template <
    typename U,
    typename ... T,
    template<class, class> class Unit,
    class Root
>
class TLinearHierarchy<TTypeList<U, T ...>, Unit, Root>:
    public Unit<U, TLinearHierarchy<TTypeList<T ...>, Unit, Root>>
{
};


template<
    template<class, class> class Unit,
    class Root
>
class TLinearHierarchy<TEmptyTypeList, Unit, Root>:
    public Unit<TEmptyTypeList, Root>
{
};


}