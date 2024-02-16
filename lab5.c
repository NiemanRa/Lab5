#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Should I delete this?

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int l = 0; 

    while (head != NULL)
        l += 1;  

    return l;
}

// Parses the string in the linkedList
// If the linked list is head -> |a|->|b|->|c|, then toCString function wil return "abc".
char* toCString(node* head)
{
    char* string = (char *) malloc(sizeof(char*));
    string = "abcdef"; // Filler
    int i = length(head);

    /* Incomplete
    if (head != NULL)
    {
        strcat(string[i], head->letter);
        head = head->next;
    }
    */
    
    return string;
}

// Inserts character to the linkedlist
// If the linked list is head -> |a|->|b|->|c|, then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) // Just adds another character to the linked list.
{
    if (&c == NULL)
        return;

    node* newStruct = (node*) malloc(sizeof(node*));
    (*newStruct).letter = c;
    *pHead = newStruct;
    // printf("%c\n", (**pHead).letter); <---- You can see that the letters successfully copied over.

}

// Deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    *pHead = NULL;
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    
    fclose(inFile);
}