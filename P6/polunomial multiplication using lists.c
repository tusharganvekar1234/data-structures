#include <stdio.h>
#include <stdlib.h>

struct node
{
    int co, po;
    struct node *addr;
};
typedef struct node *NODE;

NODE insertend(NODE head, int co, int po)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;

    if (head == NULL)
        return temp;
    else
    {
        cur = head;
        while (cur->addr != NULL)
            cur = cur->addr;
        cur->addr = temp;
        return head;
    }
}

void display(NODE head)
{
    if (head == NULL)
    {
        printf("polynomial is empty.\n");
        return;
    }
    NODE cur = head;
    while (cur != NULL)
    {
        printf("%d*x^%d", cur->co, cur->po);
        cur = cur->addr;
        if (cur != NULL)
            printf(" + ");
    }
    printf("\n");
}

NODE addterm(NODE res, int co, int po)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;

    if (res == NULL)
        return temp;
    cur = res;
    while (cur != NULL)
    {
        if (cur->po == po)
        {
            cur->co += co;
            return res;
        }
        cur = cur->addr;
    }
    res = insertend(res, co, po);
    return res;
}

NODE multiply(NODE poly1, NODE poly2)
{
    NODE p1, p2, res = NULL;
    for (p1 = poly1; p1 != NULL; p1 = p1->addr)
    {
        for (p2 = poly2; p2 != NULL; p2 = p2->addr)
        {
            res = addterm(res, p1->co * p2->co, p1->po + p2->po);
        }
    }
    return res;
}

int main()
{
    NODE poly1 = NULL, poly2 = NULL, poly;
    int co, po, i, n;
    printf("Enter no of Terms of 1st Polynomial:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and power of term %d:\n",i + 1);
        scanf("%d%d", &co, &po);
        poly1 = insertend(poly1, co, po);
    }
    printf("First polynomial is:\n");
    display(poly1);

    printf("ENTER no of terms of 2nd polynomial:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and power of term %d:\n",i + 1);
        scanf("%d%d", &co, &po);
        poly2 = insertend(poly2, co, po);
    }
    printf("Second Polynomial is:\n");
    display(poly2);

    poly = multiply(poly1, poly2);
    printf("Resultant polynomial after multiplication is:\n");
    display(poly);
    return 0;
}










































