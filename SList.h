#include <stdlib.h>
#include <stdbool.h>

//Sinlgy LinkedList
#ifndef SLIST_H
#define SLIST_H

//ADT of type record.
typedef struct record
{
    char name[30];
    char symptom[30];
    int serialNo,cabin,phone,age;
    struct record *next;
}Slist;

//Check if node is NULL/Empty
bool is_empty(Slist *head) {
  return head == NULL;
}

/*
Assigning memory to ptr node and returning to main
the returned ptr is used to assign values to field
*/
Slist *CreateNode(Slist *ptr){
    ptr = (Slist *)malloc(sizeof(Slist));
    return ptr;
}

/*
To link between nodes
*/
void Insert(Slist** head_ref, Slist *ptr){
    Slist *last = *head_ref;
    ptr->next = NULL;
 
    if (*head_ref == NULL){
       *head_ref = ptr;
       return;
    } 
      
    while (last->next != NULL)
        last = last->next;
  
    last->next = ptr;
    return;   
}

/*
Deleting the node on the given key
*/
void deleteNode(Slist** head_ref, int key){
    Slist *temp = *head_ref, *prev;
    if (temp != NULL && temp->serialNo == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->serialNo != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

/*
Macro function
For traversal of nodes using for loop
*/

#define LIST_FOREACH(var, head)					\
	for((var) = head;				        \
	    (var)!= NULL;				        \
	    (var) = var->next)                                  

#endif
