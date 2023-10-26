#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int expo;
    int coef;
    struct node *next;
    struct node *prev;
} Node;

Node *createNode(Node *head, int expo, int coef)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->expo = expo;
    new_node->coef = coef;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
        return new_node;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        return head;
    }
}

Node *searchExpo(Node *head, int expo)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->expo == expo)
            return temp;
        else
            temp = temp->next;
    }
    return NULL;
}

Node *sumPoly(Node *poly1, Node *poly2)
{
    Node *polySum = NULL;
    Node *temp = poly1;
    while (temp != NULL)
    {
        Node *p2pos = searchExpo(poly2, temp->expo);
        if (p2pos != NULL)
            polySum = createNode(polySum, temp->expo, temp->coef + p2pos->coef);
        else
            polySum = createNode(polySum, temp->expo, temp->coef);
        temp = temp->next;
    }
    temp = poly2;
    while (temp != NULL)
    {
        if (searchExpo(poly1, temp->expo) == NULL)
            polySum = createNode(polySum, temp->expo, temp->coef);
        temp = temp->next;
    }
    return polySum;
}

int main()
{
    Node *poly1 = NULL;
    poly1 = createNode(poly1, 2, 2);
    poly1 = createNode(poly1, 1, 3);
    poly1 = createNode(poly1, 0, 5);

    Node *poly2 = NULL;
    poly2 = createNode(poly2, 3, 3);
    poly2 = createNode(poly2, 2, 4);
    poly2 = createNode(poly2, 0, 1);

    Node *resultPoly = sumPoly(poly1, poly2);

    printf("\n\n\nThe first polynomial is: \n");
    Node *temp = poly1;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coef, temp->expo);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }

    printf("\nThe second polynomial is: \n");
    temp = poly2;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coef, temp->expo);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }

    temp = resultPoly;
    printf("\n\nThe sum of the two polynomials is: \n");
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coef, temp->expo);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n\n\n");
}