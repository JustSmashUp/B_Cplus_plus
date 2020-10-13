#include <iostream>

using namespace std;

//it will cache if any fib(number) that encounterd
int cache_fib[100];

int fib(int number)
{
    //if number is less than 2, for number = 1 , return 1;
    //for number = 0 return 1;
    // fib (2) = fib(1) + fib(0) = 1
    if (number < 2)
        return number;

    //if fib(number) is inside this array then simply return this
    if (cache_fib[number] != NULL)
        return cache_fib[number];

    //store a fib(number) value inside this array so that we can access this any time
    cache_fib[number] = fib(number - 1) + fib (number - 2);

    //return stored value
    return cache_fib [number];

}
int main(void)
{
    while(true)
    {
        int number;
        scanf("%d", &number);
        if(number == 0)
            break;
        cout << "Fibonacci of "<< number << " is :" <<fib(number) << endl;
    }
    return 0;
}
