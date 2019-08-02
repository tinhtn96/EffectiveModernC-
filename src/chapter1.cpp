#include <iostream>
#include <deque>
#include <vector>

// Template type
template<typename T>
void func(const T& param)
{
    std::cout << "Test for template type !!" << param << std::endl;
}

// return size of an array as a compile-time constant.
// The array parameter has no name, because we care only about the number of element in contains
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}

// Function Arguments
void someFunc(int a, double b)
{
    std::cout << "someFunc " << a << b << std::endl;
}

template<typename T>
void f1(T param)
{
    param(1, 1.0);
}

template<typename T>
void f2(T& param)
{
    param(2, 22.1);
}

// Decltype
template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i) -> decltype(c[i])
{
    return c[i];
}

int main()
{
    int a = 10;
    std::string str = "abc";
    func(a);
    func(str);
    /*************************/
    int keyVals[] = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "Size of keyVals " << sizeof(keyVals)/sizeof(int) << std::endl;
    std::cout << arraySize(keyVals) << std::endl;
    int mappedVals[arraySize(keyVals)];
    /*************************/
    f1(someFunc);
    f2(someFunc);
    /*************************/
    std::deque<int> d;
    authAndAccess(d, 5) = 100;
    std::cout << d[5] << std::endl;
}
