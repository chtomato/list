#include <stdio.h>  
#include <stdlib.h>  
#include "list.h"  

struct simple {
    int data;
    struct list_head list;
};

int main()
{
    int i = 0;
    struct simple * p;
    struct list_head * pos;
    LIST_HEAD(head);
    for (i = 0; i < 10; i++) {
        p = (struct simple*)malloc(sizeof(struct simple));
        p->data = i * 10;
        list_add_tail(&p->list, &head);
    }

    list_for_each_entry(p, &head, list) {
        printf("for %d\n", p->data);
    }

    while (!list_empty(&head)) {
        pos = head.next;
        p = (struct simple*)list_entry(pos,
                struct simple, list);
        list_del(pos);
        printf("del %d\n", p->data);
        free(p);
    }
    return 0;
}