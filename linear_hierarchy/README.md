**install**

```
mkdir build
cd build
cmake ..
make
```

**launch**
```
./linear_hierarchy
```

**description**

***Задание***
> Есть typelist  
> Необходимо сгенерировать следующую иерархию.
> Корневой класс должен наследовать одновременно несколько классов (веток). Классы- ветки нумеруются, начиная с нуля. 
> Каждый класс-ветка должен, в свою очередь последовательно наследовать (линейно) n_i классов, где i - номер ветки, n_i - итое число фиббоначи 
> Порядок "выбора" типов из typelist следующий: нулевой класс-ветка, его "дети', следующий класс-ветка, все его "дети" и т.д

There are some test cases in file ut.cpp

They are just for me, but `test final` contains generating of hierarchy from homework

***Как делал:***

Я беру список классов (в моем случае это классы вида TInt<i>)

Делаю из них список списков, каждый из которых длины число фиббоначи: [[1], [2, 3], [3, 4, 5], [6, 7, 8, 9, 10], ...] (класс TSplitTypeListWithFibonaccyImpl)

Беру от каждого из списков внутрии LiearHierarcy (класс TMapLinearHierarchy)

И от всего этого ScatterHierarchy

**Файлы**
https://github.com/ulyanin/mipt-metaprogramming/blob/master/linear_hierarchy/lib/generate_fibonaccy_hierarchy.h -- основной
https://github.com/ulyanin/mipt-metaprogramming/blob/master/linear_hierarchy/lib/generate_scatter_hierarchy.h -- scatter иерархия
https://github.com/ulyanin/mipt-metaprogramming/blob/master/linear_hierarchy/lib/generate_linear_hierarchy.h -- линейная
https://github.com/ulyanin/mipt-metaprogramming/blob/master/linear_hierarchy/lib/fibonaccy.h -- фиббоначи constexpr
