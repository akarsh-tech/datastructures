#include <stdio.h>
#include <stdlib.h>

#define BADVAL -9999

struct linkedlist {
    int element;
    struct linkedlist *next;
};

typedef struct linkedlist node;
typedef node *nodeptr;

struct Queue {
    node *front, *rear;
};

typedef struct Queue queue;
typedef queue *queueptr;

nodeptr Element(int k) {
    nodeptr temp = (nodeptr)malloc(sizeof(node));
    temp->element = k;
    temp->next = NULL;
    return temp;
}

queueptr init() {
    queueptr q = (queueptr)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(queueptr q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

void enQueue(queueptr q, int element) {
    nodeptr el = Element(element);

    if (isEmpty(q) == 1) {
        q->front = el;
        q->rear = el;
    } else {
        (q->rear)->next = el;
        q->rear = el;
    }
}

int deQueue(queueptr q) {
    if (isEmpty(q) == 1) {
        return BADVAL;
    } else {
        int temp = q->front->element;
        if (q->front->next == NULL) {
            q->front = NULL;
            q->rear = NULL;
        } else {
            q->front = q->front->next;
        }
        return temp;
    }
}

void display(queueptr q) {
    if (isEmpty(q) == 1) {
        printf("Queue is empty\n");
    } else {
        nodeptr i = q->front;
        while (i != NULL) {
            printf("%d\n", i->element);
            i = i->next;
        }
    }
}

int main() {
    queueptr q = init();

    int menu, element;
    while (1) {
        printf("0. exit, 1. initialize, 2. delete, 3. insert, 4. print. Input Choice: ");
        scanf("%d", &menu);

        switch (menu) {
            case 0:
                return 0;
            case 1:
                q = init();
                break;
            case 2:
                {
                    int deletedElement = deQueue(q);
                    if (deletedElement == BADVAL) {
                        printf("The queue is empty.\n");
                    } else {
                        printf("The deleted element is %d\n", deletedElement);
                    }
                }
                break;
            case 3:
                printf("What element do you want to add? ");
                scanf("%d", &element);
                enQueue(q, element);
                break;
            case 4:
                display(q);
                break;
            default:
                printf("\nPlease reenter your choice\n");
        }
    }
}
