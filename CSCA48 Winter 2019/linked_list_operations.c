#include <stdio.h>
#include <stdlib.h>


typedef struct __node__ Node; // don't worry about this, this is called
                              // prototyping. It's so we can use the
                              // typedef keyword `Node` in our Node struct
                              // before we've actually defined it.

typedef struct __node__ {
    int v;
    Node * next; 
} Node;
/**
 * Inserts the Node k into the beginning linked list head.
 */ 
void insertBeginning (Node** head, Node* k) { 

    if (!head) return;
    k->next = *head;
    *head = k;
}

/**
 * Inserts the Node k into the end of linked list head.
 */
void insertEnd (Node** head, Node* k) {

    if (!head) return;

    Node * curr = *head;

    // if this is the first node in the list, overwrite head.
    if (!curr) *head = k; return;

    // find last node in list
    while (curr->next != NULL) curr = curr->next;
    // set the next to our new node.
    curr->next = k;
}   
/**
 * Deletes Node with value v from linked list head
 * Returns 0 if node with value v is not found, 1 otherwise
 */
int delete (Node** head, int v) {
    
    if (!head) return 0;
    
    Node * curr = *head;
    Node * prev = NULL;
    
    // look for the node with value v.
    while (curr->v != v) { 
        // keep track of previous node, we will need it later
        prev = curr;
        curr = curr->next;
        // if we reach end of list prematurely, just return
        if (!curr) return 0; 
    }

    // it helps to consider the exit condition of this loop
    // exit condition: negation of while loop condition
    // -> curr->v == v
    // this means the loop will exit with curr->v == v

    if (!prev) { // if the node we want to delete is the head node.
        
        *head = curr->next; // overwrite the head node pointer to the next one.

    } else { // otherwise it occurs at the end of the list or the middle
        
        // if it's in the middle, this sets the previous node pointer
        // to the one after curr (curr being the one we want to delete).
        // if it's at the end, curr->next == NULL, hence still correct
        // as the prev node will now have prev->next = NULL. 
        // (i.e the new end  of the list)
        prev->next = curr->next; 
    }
    // free up the memory for curr (the deleted node)
    free(curr);
    return 1;
}
int main (int argc, char ** argv) {



}