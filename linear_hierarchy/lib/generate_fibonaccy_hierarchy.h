#include "lib/typelist.h"
#include "generate_linear_hierarchy.h"
#include "generate_scatter_hierarchy.h"
#include "fibonaccy.h"


namespace NFibonaccyHierarchy {


template <size_t rest, class AccumulativeTypeList, class TypeListOfTypeList, size_t index, size_t fib_arg, class TypeList>
struct TSplitTypeListWithFibonaccyImpl;

/*
 * [H, T...] , [..] , [[..]..] --> [T...], [H, ...], [[..]..]
 */

template <size_t rest, class AccumulativeTypeList, class TypeListOfTypeList, size_t index, size_t fib_arg, class H, class ...T>
class TSplitTypeListWithFibonaccyImpl<rest, AccumulativeTypeList, TypeListOfTypeList, index, fib_arg, TTypeList<H, T...>>
{
private:
    using TTail_ = TTypeList<T...>;
    using THead_ = H;

    using TNewAccumulativeTypeList_ = typename TAddHead<THead_, AccumulativeTypeList>::TResult;

//    static_assert(index < TTypeList<T...>::Length);

public:
    using TResult = typename TSplitTypeListWithFibonaccyImpl<
        rest - 1,
        TNewAccumulativeTypeList_,
        TypeListOfTypeList,
        index + 1,
        fib_arg,
        TTail_
    >::TResult;
};


template <size_t rest, class AccumulativeTypeList, class TypeListOfTypeList, size_t index, size_t fib_arg>
struct TSplitTypeListWithFibonaccyImpl<rest, AccumulativeTypeList, TypeListOfTypeList, index, fib_arg, TEmptyTypeList>
{
    using TResult = typename TAddHeadIf<!AccumulativeTypeList::IsEmpty, AccumulativeTypeList, TypeListOfTypeList>::TResult;
};


template <class AccumulativeTypeList, class TypeListOfTypeList, size_t index, size_t fib_arg, class H, class ...T>
class TSplitTypeListWithFibonaccyImpl<0, AccumulativeTypeList, TypeListOfTypeList, index, fib_arg, TTypeList<H, T...>>
{
private:

    using TNewTypeListOfTypeList_ = typename TAddHeadIf<!AccumulativeTypeList::IsEmpty, AccumulativeTypeList, TypeListOfTypeList>::TResult;


public:
    using TResult = typename TSplitTypeListWithFibonaccyImpl<
        fib_arg,
        TEmptyTypeList,
        TNewTypeListOfTypeList_,
        index,
        fib_arg + 1,
        TTypeList<H, T...>
    >::TResult;
};



template <class TypeList>
using TSplitTypeListWithFibonaccy = TSplitTypeListWithFibonaccyImpl<
    /* rest = */ 0,
    /* AccumulativeTypeList = */ TEmptyTypeList,
    /* TypeListOfTypeList = */ TEmptyTypeList,
    /* index = */ 0,
    /* fib_index = */ 2,
    TypeList
>;


template <template <class> class Unit, class TypeList, class Root = NLinearHierarchy::TEmptyType, class Accum = TEmptyTypeList>
struct TMapLinearHierarchy;


template <template <class> class Unit, class H, class ...T, class Root, class Accum>
struct TMapLinearHierarchy<Unit, TTypeList<H, T...>, Root, Accum>
{
private:
    using TNewAccum = typename TAddHead<NLinearHierarchy::TLinearHierarchy<H, Unit, Root>, Accum>::TResult;
public:
    using TResult = typename TMapLinearHierarchy<Unit, TTypeList<T...>, Root, TNewAccum>::TResult;
};

template <template <class> class Unit, class Root, class Accum>
struct TMapLinearHierarchy<Unit, TEmptyTypeList, Root, Accum>
{
    using TResult = Accum;
};


// [t] -> (via TSplit) [[t]]
//     -> (via TMap...) [Linear<[t]>]
//     -> (via GenScatter) Scatter<[Linear<[t]>]>
template <template <class> class Unit, class TypeList, class Root = NLinearHierarchy::TEmptyType>
struct TGenerateFibonaccyHierarchy
    : public NScatterHierarchy::TGenScatterHierarchy<
        typename TMapLinearHierarchy<
            Unit,
            typename TSplitTypeListWithFibonaccy<TypeList>::TResult,
            Root
        >::TResult
    >
{
};


} // namespace NFibonaccy

