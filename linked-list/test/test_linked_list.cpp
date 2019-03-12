#include <iostream>
#include "../linked_list.h"

/* Helper function to construct linked list for test. */
SingleNode* construct_linked_list(int count, int step = 1)
{
    std::cout << "The linked list is ";
    if (count <= 0) {
        print_linked_list(NULL);
        return NULL;
    }

    SingleNode* head = new SingleNode();
    head->data = 1;

    SingleNode* p = head;
    for (int i = 2; i <= count; i++) {
        p->next = new SingleNode();
        p->next->data = i * step;
        p = p->next;
    }

    print_linked_list(head);
    return head;
}

SingleNode* construct_linked_list_with_circle(int none_circle_length, int circle_length)
{
    std::cout << "The linked list is ";
    if ((none_circle_length + circle_length) <= 0) {
        print_linked_list(NULL);
        return NULL;
    }

    SingleNode* guard_pointer = new SingleNode();
    SingleNode* pre_joint_node = guard_pointer;
    SingleNode* p = guard_pointer;
    for (int i = 1; i <= none_circle_length; i++) {
        p->next = new SingleNode();
        p->next->data = i;
        p = p->next;
    }
    pre_joint_node = p;
    for (int i = none_circle_length + 1; i <= (none_circle_length + circle_length); i++) {
        p->next = new SingleNode();
        p->next->data = i;
        p = p->next;
    }
    if (circle_length > 0) {
        p->next = pre_joint_node->next;
    }

    /* Forawrd the head Node, and delete the guard Node. */
    SingleNode* head = guard_pointer->next;
    delete guard_pointer;

    print_linked_list(head);
    return head;
}

/*
    Test functions.
*/

void test_reverse()
{
    SingleNode* head = NULL;

    // Test NULL linked list.
    head = construct_linked_list(0);
    reverse(head);

    // Test 1 node linked list.
    head = construct_linked_list(1);
    reverse(head);

    // Test 2 node linked list.
    head = construct_linked_list(2);
    reverse(head);

    // Test 7 node linked list.
    head = construct_linked_list(7);
    reverse(head);
}

void test_find_mid_point()
{
    SingleNode* head = NULL;

    // Test NULL linked list.
    head = construct_linked_list(0);
    find_midpoint(head);

    // Test 1 node linked list.
    head = construct_linked_list(1);
    find_midpoint(head);

    // Test 2 node linked list.
    head = construct_linked_list(2);
    find_midpoint(head);

    // Test 7 node linked list.
    head = construct_linked_list(7);
    find_midpoint(head);
}

void test_find_circle()
{
    SingleNode* head = NULL;

    // Test NULL linked list.
    head = construct_linked_list_with_circle(0, 0);
    find_circle(head);

    // Test 1 node linked list.
    head = construct_linked_list_with_circle(1, 0);
    find_circle(head);

    // Test 2 node linked list.
    head = construct_linked_list_with_circle(0, 1);
    find_circle(head);

    // Test 7 node linked list.
    head = construct_linked_list_with_circle(1, 2);
    find_circle(head);

    // Test 7 node linked list.
    head = construct_linked_list_with_circle(4, 3);
    find_circle(head);
}

void test_combine_two_sorted_list()
{
    // Test NULL linked list.
    combine_two_sorted_list(construct_linked_list(0), construct_linked_list(0));

    // Test 1 node linked list.
    combine_two_sorted_list(construct_linked_list(0), construct_linked_list(1));

    // Test 2 node linked list.
    combine_two_sorted_list(construct_linked_list(1), construct_linked_list(3));

    // Test 7 node linked list.
    combine_two_sorted_list(construct_linked_list(4, 2), construct_linked_list(3));
}

void test_delete_last_n_node()
{
    SingleNode* head = NULL;

    // Test NULL linked list.
    head = construct_linked_list(0);
    delete_last_n_node(head, 1);

    // Test 1 node linked list.
    head = construct_linked_list(1);
    delete_last_n_node(head, 1);

    // Test 3 node linked list.
    head = construct_linked_list(3);
    delete_last_n_node(head, 3);

    // Test 4 node linked list.
    head = construct_linked_list(4);
    delete_last_n_node(head, 2);

    // Test 5 node linked list.
    head = construct_linked_list(5);
    delete_last_n_node(head, 6);
}


int main()
{
    std::cout << "hello boy!" << std::endl;

    std::cout << std::endl;
    test_reverse();
    std::cout << std::endl;
    test_find_mid_point();
    std::cout << std::endl;
    test_combine_two_sorted_list();
    std::cout << std::endl;
    test_delete_last_n_node();
    std::cout << std::endl;
    test_find_circle();

    return 0;
}