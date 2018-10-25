#pragma once

#include <ctype.h>
#include <cstddef>
#include <type_traits>

template <class... R>
struct TTypeList;

namespace NTypeList {

template <unsigned N, typename TypeList>
struct TGetImpl {
    using Result = typename TGetImpl<N - 1, typename TypeList::TTail>::Result;
};

template <typename TypeList>
struct TGetImpl<0u, TypeList> {
    using Result = typename TypeList::THead;
};

}  // namespace NTypeList

template <>
struct TTypeList<> {
    static constexpr size_t Length = 0;
    static constexpr bool IsEmpty = true;

};

using TEmptyTypeList = TTypeList<>;

template <class H, class... T>
struct TTypeList<H, T...> {
    using THead = H;
    using TTail = TTypeList<T...>;

    static constexpr size_t Length = 1 + sizeof...(T);
    static constexpr bool IsEmpty = false;

    template <unsigned N>
    using TGet = typename ::NTypeList::TGetImpl<N, TTypeList<H, T...>>::Result;
};

template <class Head, class TypeList>
struct TAddHead;

template <class Head, class ...T>
struct TAddHead<Head, TTypeList<T...>> {
    using Result = TTypeList<Head, T...>;
};

template <class T1, class T2>
struct TConcat;

template <class... T1, class... T2>
struct TConcat<TTypeList<T1...>, TTypeList<T2...>> {
    using Result = TTypeList<T1..., T2...>;
};


namespace {
    template <size_t i, class TypeList>
    struct EraseImpl;

    template <class ... T>
    class EraseImpl<0, TTypeList<T...>> {
    private:
        static_assert(!TTypeList<T...>::IsEmpty, "can't etase from empty TTypeList");
        using TypeList_ = TTypeList<T...>;
    public:
        using Result = typename TTypeList<T...>::TTail;
    };

    template <size_t n, class ...T>
    class EraseImpl<n, TTypeList<T...>> {
    private:
        using TypeList_ = TTypeList<T...>;
        static_assert(TypeList_::Length > n, "TTypelist index out of range");
        using Head_ = typename TypeList_ ::THead;
        using Tail_ = typename TypeList_ ::TTail;
        using Erased_ = typename EraseImpl<n - 1, Tail_>::Result;
    public:

        using Result = typename TAddHead<Head_, Erased_>::Result;

    };



}  // unnamed namespace

template <size_t i, class TypeList>
struct Erase;

template <size_t i, class ...T>
struct Erase<i, TTypeList<T...>> {
    using Result = typename EraseImpl<i, TTypeList<T...>>::Result;
};
