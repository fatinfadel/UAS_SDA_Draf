#include <stdio.h>
#include <string.h>
#include "Produk.h"

/* ================= INPUT ================= */
void tambahProduk(Produk data[], int *n)
{
    if(*n >= MAX)
    {
        printf("\n[ERROR] Data sudah penuh!\n");
        return;
    }

    printf("\n[INPUT PRODUK]\n");

    printf("Nama Produk        : ");
    scanf(" %[^\n]", data[*n].nama);

    printf("Harga              : ");
    scanf("%f", &data[*n].harga);

    printf("Jumlah Terjual     : ");
    scanf("%d", &data[*n].jumlahTerjual);

    printf("Profit per barang  : ");
    scanf("%f", &data[*n].profit);

    data[*n].totalProfit = data[*n].profit * data[*n].jumlahTerjual;
    enqueue(&q, data[*n]);
    (*n)++;

    printf("\nProduk berhasil ditambahkan\n");
}
/* ================= TAMPIL ================= */
void tampilkanProduk(Produk data[], int n)
{
    if(n == 0)
    {
        printf("\n Data kosong!\n");
        return;
    }

    printf("\n+================================================================================+\n");
    printf("|                               DATA PRODUK                                     |\n");
    printf("+--------------------------------------------------------------------------------+\n");
    printf("| No | Nama Produk           | Harga   | Terjual | Profit  | Total Profit       |\n");
    printf("+--------------------------------------------------------------------------------+\n");

    for(int i = 0; i < n; i++)
    {
        printf("| %-2d | %-20.20s | %-7.0f | %-7d | %-7.0f | %-18.0f |\n",
            i+1,
            data[i].nama,
            data[i].harga,
            data[i].jumlahTerjual,
            data[i].profit,
            data[i].totalProfit);
    }

    printf("+--------------------------------------------------------------------------------+\n");
}

/* ================= SIMPAN FILE ================= */
void simpanData(Produk data[], int n)
{
    if(n <= 0)
        return;

    FILE *fp = fopen("produk.txt", "w");

    if(fp == NULL)
    {
        printf("\nError Gagal membuka file!\n");
        return;
    }

    for(int i = 0; i < n; i++)
    {
        fprintf(fp, "%s;%f;%d;%f;%f\n",
                data[i].nama,
                data[i].harga,
                data[i].jumlahTerjual,
                data[i].profit,
                data[i].totalProfit);
    }

    fclose(fp);

    printf("\nYEAY!!! Data berhasil disimpan ke produk.txt\n");
}

/* ================= LOAD FILE ================= */
int muatData(Produk data[])
{
    FILE *fp = fopen("produk.txt", "r");

    int n = 0;

    if(fp == NULL)
        return 0;

    while(fscanf(fp,
                 " %49[^;];%f;%d;%f;%f",
                 data[n].nama,
                 &data[n].harga,
                 &data[n].jumlahTerjual,
                 &data[n].profit,
                 &data[n].totalProfit) == 5)
    {
        n++;
    }

    fclose(fp);

    return n;
}

/* ================= HAPUS ================= */
void hapusProduk(Produk data[], int *n)
{
    if(*n == 0)
    {
        printf("\n[INFO] Data kosong!\n");
        return;
    }

    int index;

    printf("\nMasukkan nomor produk yang ingin dihapus: ");
    scanf("%d", &index);

    if(index < 1 || index > *n)
    {
        printf("\n[ERROR] Nomor tidak valid!\n");
        return;
    }

    index--;

    for(int i = index; i < *n - 1; i++)
    {
        data[i] = data[i + 1];
    }

    (*n)--;

    printf("\nYEAY!!! Produk berhasil dihapus\n");
}
