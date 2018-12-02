#include <iostream>
#include "lib/typelist.h"
#include "lib/typelist_printer.h"
#include <string>

class SomeClass
{

};


int main() {
    using numberTypes = TTypeList<int, char, long long, SomeClass>;

    {
        // basic
        std::cout << numberTypes::Length << " " << numberTypes() << std::endl;
        std::cout << numberTypes::TTail() << std::endl;
        std::cout << TAddHead<short int, numberTypes>::Result() << std::endl;
    }

    std::cout << std::endl;
    {
        // Get
        std:: cout << "{ test Get" << std::endl;
        using secondElem = numberTypes::TGet<2>;
        std::cout << "expect long long:" << std::endl;
        std::cout << "Get: " << GetNamePretty<secondElem>() << std::endl;
        static_assert(std::is_same<secondElem, long long>::value, "expected long long");
        std:: cout << "} end test Get" << std::endl;
    }
    std::cout << std::endl;

    {
        // Erase
        std::cout << "{ test Erase" << std::endl;
        std::cout << "char --> long long" << std::endl;

        using secondElem_1 = numberTypes::TGet<1>;
        std::cout << GetNamePretty<secondElem_1>() << std::endl;

        using numberTypesNew = Erase<1, numberTypes>::Result;
        using secondElem_2 = numberTypesNew::TGet<1>;
        std::cout << GetNamePretty<secondElem_2>() << std::endl;
        std::cout << "} end test Erase" << std::endl;


        // error: static assertion failed: TTypelist index out of range
        //using numberTypesNew = Erase<10, numberTypes>::TResult;

    }

    return 0;
}