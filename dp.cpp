#include <iostream>

using namespace std;

int divide(int number ,int startValue, int endValue, int arr[])
{
    //when startValue > endValue , it's mean that we check every number and did not find any matching value with the number
    //we return -1 , that's mean there is no value to match with this number
    if(startValue > endValue)
        return -1;

    int mid = (startValue + endValue) / 2;

    //
    if(arr[mid] == number)
        return mid + 1;

    //if arr[mid] value is less than the number
    //it's mean that we have to find the number with higher value
    //that's why we reinitialize the startValue to mid + 1
    //it will search mid+1 to previous end
    else if (arr[mid] < number)
         startValue = mid + 1;


    //if arr[mid] is grater than the number
    //it's mean we have to find the number with lower value
    //that's why we reinitialize the endValue to mid - 1
    //it will search previous startValue to mid - 1
    else if (arr[mid] > number)
         endValue = mid - 1;

    // if arr[mid] do not matches the number, call the function again with new value
    divide(number, startValue, endValue, arr);
}

int searchValue(int number, int s, int arr[])
{
    int startValue = 0;

    //last index of any array is size - 1
    int endValue = s - 1;
    return divide( number , startValue,  endValue,  arr);

}

int main(void)
{
    int arr[10] = {1,2,3,4,5,6};
    cout << searchValue(6,6,arr);
}
