#ifndef PRODUK_H
#define PRODUK_H

#define MAX 100

/* ================= STRUCT PRODUK ================= */
typedef struct
{
    char nama[50];
    float harga;
    int jumlahTerjual;
    float profit;
    float totalProfit;
} Produk;

/* ================= STACK (RIWAYAT HAPUS) ================= */
typedef struct {
    Produk data[MAX];
    int top;
} Stack;

/* ================= QUEUE (ANTRIAN PRODUK) ================= */
typedef struct {
    Produk data[MAX];
    int front;
    int rear;
} Queue;

/* ================= FITUR PRODUK ================= */
void tambahProduk(Produk data[], int *n);
void tampilkanProduk(Produk data[], int n);
void selectionSortProfit(Produk data[], int n);
void cariProduk(Produk data[], int n);
void top3ProdukTerbaik(Produk data[], int n);
void simpanData(Produk data[], int n);
int muatData(Produk data[]);
void hapusProduk(Produk data[], int *n);

/* ================= STACK ================= */
void initStack(Stack *s);
void pushStack(Stack *s, Produk p);
void printStack(Stack *s);

/* ================= QUEUE ================= */
void initQueue(Queue *q);
void enqueue(Queue *q, Produk p);
void printQueue(Queue *q);

#endif
