#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct Node
{
    /* data */
    int data;
    Node* next;
} SingleNode;

void print_linked_list(SingleNode*);

void reverse(SingleNode*);

void find_midpoint(SingleNode*);

void find_circle(SingleNode*);

void combine_two_sorted_list(SingleNode*, SingleNode*);

void delete_last_n_node(SingleNode*, int);

#endif