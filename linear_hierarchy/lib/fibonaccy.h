#pragma once


template<int  N>
constexpr int Fibonacci() {
    return Fibonacci<N - 1>() + Fibonacci<N - 2>();
}

template<>
constexpr int Fibonacci<1>() {
    return 1;
}

template<>
constexpr int Fibonacci<0>() {
    return 0;
}