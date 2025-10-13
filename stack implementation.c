#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct stack {
    int top;
    int data[SIZE];
} STACK;

void push(STACK *s, int item) {
    if (s->top == SIZE - 1) {
        printf("\nStack overflow");
    } else {
        s->top++;
        s->data[s->top] = item;
    }
}

void pop(STACK *s) {
    if (s->top == -1) {
        printf("\nStack underflow");
    } else {
        printf("\nElement popped is %d", s->data[s->top]);
        s->top--;
    }
}

void display(STACK s) {
    int i;
    if (s->top == -1) {
        printf("\nStack is empty");
    } else {
        printf("\nStack contents are:\n");
        for (i = s->top; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
}

int main() {
    int ch, item;
    STACK s;
    s.top = -1;

    while (1) {
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, try again.");
        }
    }

    return 0;
}


