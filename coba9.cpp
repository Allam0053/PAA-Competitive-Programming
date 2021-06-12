#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Struktur Node */

typedef struct pqueueNode_t {
    int data;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}
// Buat objek PriorityQueue
PriorityQueue antri;
PriorityQueue in_dokter;
    

int main() {
    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&antri);
    pqueue_init(&in_dokter);

    int dokter, in_d=0, jp=0, q,  p,d,m,f;
    char np[100][10];
    char penyakit[100][50];
    char pu[]="pusingkebanyakantugas";
    char di[]="diare";
    char ma[]="maag";
    char flu[]="flu";

    scanf("%d", &dokter);
    while(scanf("%d", &q)!=EOF){
        if(q==1){ //pasien masuk
            scanf("%s%s", np[jp], penyakit[jp]);
            jp++;
            
        }else { //pasien keluar

        }
        //penanganan antrian
        if( in_d < dokter ){ // langsung masuk
            
        }
    }
    return 0;
}