#pragma once

#include "typelist.h"
#include <iostream>

#include <cxxabi.h>

// source: https://habr.com/post/220217/

template<class T>
std::string GetNamePretty()
{
    int status;
    return abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
}

template<typename T>
void PrintTypeListHead(T, std::ostream& ostr)
{
    std::cout << GetNamePretty<T>();
//    std::cout << typeid(T).name();
}

template<typename ...TL>
void PrintTypeListHead(TTypeList<TL...> tl, std::ostream& ostr)
{
    ostr << tl;
}

template<typename Head, typename ...Args>
void PrintTypeListHelper(TTypeList<Head, Args...> tl, std::ostream& ostr)
{
    PrintTypeListHead(Head(), ostr);
    if constexpr (!TTypeList<Args...>::IsEmpty)
    {
        ostr << ", ";
        PrintTypeListHelper<Args...>(TTypeList<Args...>(), ostr);
    }
}


template<typename ...Args>
std::ostream& operator<<(std::ostream& ostr, TTypeList<Args...> tl)
{
    ostr << '<';
    PrintTypeListHelper(tl, ostr);
    ostr << '>';
    return ostr;
}