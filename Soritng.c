#include "Produk.h"

void selectionSortProfit(Produk data[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int max = i;

        for(int j = i + 1; j < n; j++)
        {
            if(data[j].totalProfit > data[max].totalProfit)
            {
                max = j;
            }
        }

        Produk temp = data[i];
        data[i] = data[max];
        data[max] = temp;
    }
}
