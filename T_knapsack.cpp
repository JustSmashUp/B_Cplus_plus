#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack(int price[], int wt[], int W, int n)
{
    int matrix[100][100];
    //initialize matrix
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (i == 0 || j == 0)
                matrix[i][j] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < W; j++){
            if (wt[j - 1] <= W)
                matrix[i][j] = max(price[n - 1] + matrix[n - 1][W - wt[n - 1]], matrix[n - 1][W]);
            else
                matrix[i][j] =  matrix[n - 1][W];
        }
    }

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < W; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
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

    printf("Maximum profit is : %d", knapsack(price,wt, W, n));
}
