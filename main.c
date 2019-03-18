//
// Created by David Ceniceros on 3/17/2019
//

#include <stdio.h>
#include <stdlib.h>

// node structure for a singly-linked list, holding a single int value
struct Node
{
    int data;
    struct Node *next;
};

void list_delete(struct Node *n, int key)
{
    struct Node* temp = n, *prev;

    if (temp != NULL && temp->data == key)
    {
        n = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}


void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
}


int main() {
    printf("\nRunning linked list\n\n");

    // head and tail pointers
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;

    // Initialize the linked list
    head  = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third  = (struct Node*)malloc(sizeof(struct Node));
    fourth  = (struct Node*)malloc(sizeof(struct Node));
    fifth  = (struct Node*)malloc(sizeof(struct Node));

    // list's head pointer
    head->data = 12; //assign data in first node
    head->next = second; // Link first node with second

    second->data = 34; //assign data to second node
    second->next = third;

    third->data = 56; //assign data to second node
    third->next = fourth;

    fourth->data = 78; //assign data to second node
    fourth->next = fifth;

    fifth->data = 90; //assign data to third node
    // list's tail pointer
    fifth->next = NULL;

    printf("list before deletion\n");
    printList(head); // defore deletion

    printf("\n");

    printf("\nlist after deletion of fouth link\n");
    list_delete(&fourth, 78);

    printList(head);// after deletion

    printf("\n");

}

/* Extension: I choose this program because I worked with linked list in both Java and C. I know how to add links but have never worked on a function to remove a link from mthe list. I had fun lworking with linked list again and i feel that this program has helped me reached a better understanding as to how to worked with linked lists.
*/

/* Most of my program was already completed. I had to create a function that would delete a link from the list, of my choosing. My function consisted of three statements, the if, while, then another if statement. The if statement made sure that the link I wanted to erase didn't equal to NULL and was the value of the integer I wanted to remove. If the criteria matched the if statement. It would free up the space from that link.

if (temp != NULL && temp->data == key)
{
n = temp->next;
free(temp);
return;
}

The while statment sees that if the link does not have the value we wish to remove, it simply goes to the next link.

while (temp != NULL && temp->data != key)
{
prev = temp;
temp = temp->next;
}

The last if statement sees that once we reached the last link, it ends list_delete.

if (temp == NULL) return;

The line under the last if statement is the one that makes list_delete work. It makes sure to remove the link from the list.

prev->next = temp->next;
*/

