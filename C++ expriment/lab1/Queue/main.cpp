#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Queue {
    int* const  elems;	   	//elems申请内存用于存放队列的元素
    const  int  max;	  	//elems申请的最大元素个数max
    int   head, tail;	 	//队列头head和尾tail，队空head=tail;初始head=tail=0
};
void initQueue(Queue* const p, int m) { //初始化p指队列：最多申请m个元素
    *(int**)&p->elems= (int*)malloc(sizeof(int) * m);
    if (p->elems == NULL) {
        throw("malloc failed");
    }
    *(int*)&p->max = m;
    p->head = p->tail = 0;
}
void initQueue(Queue* const p, const Queue& q) {
    *(int**)&p->elems = (int*)malloc(sizeof(int) * q.max);
    if (p->elems == NULL) {
        throw("malloc failed");
    }
    *(int*)&p->max = q.max;
    p->head = q.head;
    p->tail = q.tail;
    for (int i = 0; i < q.max; i++) {
        (*(int**)&p->elems)[i] = q.elems[i];
    }
}
void initQueue(Queue* const p, Queue&& q) {
    *(int**)&p->elems = q.elems;
    *(int*)&p->max = q.max;
    p->head = q.head;
    p->tail = q.tail;
   
    *(int**)&q.elems = NULL;
    *(int*)&q.max = 0;
    q.head = q.tail = 0;
}
int  number(const Queue* const p) {
    if (p->tail >= p->head) {
        return p->tail - p->head;
    }
    else return p->tail - p->head + p->max;
}
int  size(const Queue* const p) {
    return p->max;
}
Queue* const enter(Queue* const p, int e) {
    if ((p->tail + 1) % p->max == p->head) {
        throw"Queue is full!";
    }
    (*(int**)&p->elems)[p->tail] = e;
    p->tail = (p->tail + 1) % p->max;
    return p;
}
Queue* const leave(Queue* const p, int& e) {
    if (p->head == p->tail) {
        throw"Queue is empty!";
    }
    e = p->elems[p->head];
    p->head = (p->head + 1) % p->max;
    return p;
}
Queue* const assign(Queue* const p, const Queue& q) {
    if (p == &q)
    {
        return p;
    }
    if (p->elems != NULL) {
        free(p->elems);

    }
    *(int**)&p->elems = (int*)malloc(sizeof(int) * q.max);
    if (p->elems == NULL) {
        throw("malloc failed");
    }
    *(int*)&p->max = q.max;
    p->head = q.head;
    p->tail = q.tail;
    for (int i = 0; i < q.max; i++) {
        (*(int**)&p->elems)[i] = q.elems[i];
    }
    return p;
}
Queue* const assign(Queue* const p, Queue&& q) {
    if (p == &q)
    {
        return p;
    }
    if (p->elems != NULL) {
        free(p->elems);
    }
     *(int**)&p->elems = q.elems;
        *(int*)&p->max = q.max;
        p->head = q.head;
        p->tail = q.tail;
        *(int*)&q.max = 0;
        q.head = q.tail = 0;
        *(int**)&q.elems = NULL;
        return p;
}
char* print(const Queue* const p, char* s) {
    int i = p->head;
    int x = 0;
    while (i != p->tail)
    {
        x = x + sprintf(s + x, ",%d", p->elems[i]);
        i = (i + 1) % p->max;
    }
    strcpy(s, s + 1);
    return s;
}
void destroyQueue(Queue* const p) {
    if (p->elems)
    {free(p->elems);
    *(int**)&p->elems = NULL;
    *(int*)&p->max = 0;
    p->head = 0;
    p->tail = 0; }

}
extern const char* TestQueue(int& s);
int main() {
    struct Queue* const p = (struct Queue*)malloc(sizeof(struct Queue));
    int s = 0;
    const char* e = TestQueue(s);
    printf("%s", e);
    printf("\n%d", s);
}