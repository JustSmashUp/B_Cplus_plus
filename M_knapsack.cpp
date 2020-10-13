#include <iostream>

using namespace std;

int matrix[100][100];

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack(int price[], int wt[], int W, int n)
{
    if (W == 0 || n == 0)
        return 0;

    if (matrix [n][W] != -1)
            return matrix[n][W];

    if (wt[n - 1] <= W)
        //max (a, b)
        //here a -> including n - 1 + other
        //her b -> excluding n - 1 and other
        return matrix[n][W] = max(price[n - 1] + knapsack(price, wt, W - wt[n - 1], n - 1), knapsack(price, wt, W, n - 1));

    return knapsack(price, wt, W, n - 1);
}

int main(void)
{
    int n, price[100], wt[100], W;

    //get the length of array
    printf("N: ");
    scanf("%d", &n);

    //get the price
    printf("Price : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &price[i]);
    }

    //get weight
    printf("Weight : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&wt[i]);
    }

    //get maximum weight of the knapsack
    printf("Maximum Capacity: ");
    scanf("%d", &W);

    //fill matrix with -1
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            matrix[i][j] = -1;


    printf("Maximum Profit : %d\n", knapsack(price, wt, W, n) );

    return 0;
}
