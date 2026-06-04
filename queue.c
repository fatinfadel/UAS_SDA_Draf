#include <stdio.h>
#include "Produk.h"

/* ===== INIT QUEUE ===== */
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

/* ===== ENQUEUE ===== */
void enqueue(Queue *q, Produk p)
{
    if(q->rear >= MAX)
    {
        printf("[QUEUE FULL]\n");
        return;
    }

    q->data[q->rear] = p;
    q->rear++;
}

/* ===== PRINT QUEUE ===== */
void printQueue(Queue *q)
{~

    if(q->front == q->rear)
    {
        printf("Queue kosong\n");
        return;
    }

    for(int i = q->front; i < q->rear; i++)
    {
        printf("%d. %s | Terjual: %d | Total: %.0f\n",
            i + 1,
            q->data[i].nama,
            q->data[i].jumlahTerjual,
            q->data[i].totalProfit);
    }
}
