#include <stdio.h>
#include <string.h>
#include "Produk.h"

void cariProduk(Produk data[], int n)
{
    char key[50];

    printf("\nMasukkan nama produk: ");
    scanf(" %[^\n]", key);

    for(int i = 0; i < n; i++)
    {
        if(strcmp(data[i].nama, key) == 0)
        {
            printf("\n================ PRODUK DITEMUKAN ================\n");
            printf("Nama Produk   : %s\n", data[i].nama);
            printf("Harga         : %.0f\n", data[i].harga);
            printf("Terjual       : %d\n", data[i].jumlahTerjual);
            printf("Profit/item   : %.0f\n", data[i].profit);
            printf("Total Profit  : %.0f\n", data[i].totalProfit);
            printf("==================================================\n");
            return;
        }
    }

    printf("\nProduk tidak ditemukan!\n");
}
