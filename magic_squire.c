#include <stdio.h>

int indexOf(int arr[],int t, int n)
{
    for (int i = 0; i < n; i++)
    {

        if(arr[i] == t)
            return i;
    }
    return -1;
}
int diff(int a, int b)
{
    return a > b ? a - b  : b - a;
}
int main()
{
    int cost = 0;
    int arr[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int d[4] = {8,4,2,6};
    int id[4] ={arr[0][0], arr[0][2], arr[2][2], arr[2][0]};
    int index = -1;
    int counter;
    for ( counter = 0; counter < 4; counter++)
    {
        index = indexOf(id,d[counter],4) ;

        if(index != -1)
            break;
        if( counter == 3 && index == -1)
        {
            counter = 0;
            index = 0;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (counter > 3)
                counter = 0;
            if (index > 3)
                index = 0;
            if(d[counter] != id [index])
            {
                id[index] = d[counter];
            }
            counter ++;
            index ++;
        }
    }


    //cost
    cost += diff(arr[0][0], id[0]);
    arr[0][0] = id[0];
    cost += diff(arr[0][2], id[1]);
    arr[0][2] = id[1];
    cost += diff(arr[2][2], id[2]);
    arr[2][2] = id[2];
    cost += diff(arr[2][0], id[3]);
    arr[2][0] = id[3];


    if (arr[1][1] != 5)
    {
        cost += diff(arr[1][1],5);
        arr[1][1] = 5;
    }
    if(arr[0][0] + arr[0][1] + arr[0][2] != 15)
    {
        cost += diff(arr[0][1], 15 - (arr[0][0] + arr[0][2]));
        arr[0][1] = 15 - (arr[0][0] + arr[0][2]);
    }

    if(arr[2][0] + arr[2][1] + arr[2][2] != 15)
    {
        cost += diff(arr[2][1], 15 - (arr[2][0] + arr[2][2]));
        arr[2][1] = 15 - (arr[2][0] + arr[2][2]);
    }

    if(arr[0][0] + arr[1][0] + arr[2][0] != 15)
    {
        cost += diff(arr[1][0], 15 - (arr[0][0]+ arr[2][0]));
        arr[1][0] = 15 - (arr[0][0]+ arr[2][0]);
    }
    printf("%d\n", arr[2][0]);
    if(arr[0][2] + arr[1][2] + arr[2][2] != 15)
    {
        cost += diff(arr[1][2], 15 - (arr[2][0] + arr[2][2]));
        arr[1][2] =  15 - (arr[0][2] + arr[2][2]);
    }

    for(int i = 0; i < 3; i++)
    {
          for (int j = 0; j < 3; j++)
          {
                printf("%d ", arr[i][j]);
          }
          printf("\n");
    }

    printf("\n %d",cost);
}
