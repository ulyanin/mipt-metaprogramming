#pragma once

#include "lib/typelist.h"

namespace NScatterHierarchy {
//
//template <class TypeList, template <class> class Unit>
//class TGenScatterHierarchy;
//
//template <class H, class ...T, template <class> class Unit>
//class TGenScatterHierarchy<TTypeList<H, T...>, Unit>
//    : public TGenScatterHierarchy<TTypeList<H>, Unit>
//    , public TGenScatterHierarchy<TTypeList<T...>, Unit>
//{
//    using TList = TTypeList<H, T...>;
//    using TLeftBase = TGenScatterHierarchy<TTypeList<H>, Unit>;
//    using TRightBase = TGenScatterHierarchy<TTypeList<T...>, Unit>;
//};
//
//template <class AtomicType, template <class> class Unit>
//class TGenScatterHierarchy<TTypeList<AtomicType>, Unit>
//    : public Unit<AtomicType>
//{
//    using TLeftBase = Unit<AtomicType>;
//};
//
//template <template <class> class Unit>
//class  TGenScatterHierarchy<TEmptyTypeList, Unit>
//{
//};

template <class TypeList>
class TGenScatterHierarchy;

template <class H, class ...T>
class TGenScatterHierarchy<TTypeList<H, T...>>
    : public TGenScatterHierarchy<TTypeList<H>>
    , public TGenScatterHierarchy<TTypeList<T...>>
{
public:
    using TList = TTypeList<H, T...>;
    using TLeftBase = TGenScatterHierarchy<TTypeList<H>>;
    using TRightBase = TGenScatterHierarchy<TTypeList<T...>>;
};

template <class AtomicType>
class TGenScatterHierarchy<TTypeList<AtomicType>>
    : public AtomicType
{
    using TLeftBase = AtomicType;
};

template <>
class  TGenScatterHierarchy<TEmptyTypeList>
{
};

}