#include <stdio.h>
#include "Produk.h"

void top3ProdukTerbaik(Produk data[], int n)
{
    if(n == 0)
    {
        printf("\n[INFO] Data kosong!\n");
        return;
    }

    selectionSortProfit(data, n);

    int batas = (n < 3) ? n : 3;

    printf("\n+================================================+\n");
    printf("| RANK | NAMA PRODUK        | TOTAL PROFIT      |\n");
    printf("+================================================+\n");

    for(int i = 0; i < batas; i++)
    {
        printf("| %-4d | %-18.18s | %-17.0f |\n",
            i+1,
            data[i].nama,
            data[i].totalProfit);
    }

    printf("+================================================+\n");
}
