#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char ch;
    struct Node *next;
} Node;

Node* createNode(char ch)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->next = NULL;

    return newNode;
}

void appendNode(Node **head, char ch)
{
    Node *newNode = createNode(ch);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *cur = *head;

    while (cur->next != NULL)
        cur = cur->next;

    cur->next = newNode;
}

void printList(Node *head)
{
    Node *cur = head;

    while (cur != NULL) {

        if (cur->next != NULL)
            printf("%c, ", cur->ch);
        else
            printf("%c", cur->ch);

        cur = cur->next;
    }

    printf("\n");
}

void freeList(Node *head)
{
    Node *cur = head;

    while (cur != NULL) {
        Node *temp = cur;
        cur = cur->next;
        free(temp);
    }
}

int main()
{
    FILE *fp;
    int c;

    Node *head = NULL;

    fp = fopen("main.c", "r");

    while ((c = fgetc(fp)) != EOF) {
        appendNode(&head, (char)c);
    }

    fclose(fp);

    printList(head);

    freeList(head);

    return 0;
}
