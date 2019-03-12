#include <iostream>
#include "linked_list.h"


void print_linked_list(SingleNode* head) {
    if (head == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }

    const int max_length = 100;
    int visit_mark[max_length] = {0};
    int print_count = 0;
    SingleNode* p = head;
    while (p != NULL && print_count < max_length) {
        if (visit_mark[p->data] != 0) {
            std::cout << p->data << "(circle joint)";
            break;
        }

        visit_mark[p->data] = 1;
        std::cout << p->data;
        std::cout << "->";
        p = p->next;
        print_count++;
    }
    if (p == NULL) {
        std::cout << "NULL";
    }
    
    std::cout << std::endl;
}

void reverse(SingleNode* head)
{
    std::cout << "reversed linked list is ";

    if (head == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }

    SingleNode* slow_pointer = NULL;
    SingleNode* fast_pointer = head;
    while (head != NULL) {
        fast_pointer = head->next;
        head->next = slow_pointer;
        slow_pointer = head;
        head = fast_pointer;
    }
    head = slow_pointer;

    print_linked_list(head);
}

void find_midpoint(SingleNode* head)
{
    std::cout << "midpoint is ";

    if (head == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }

    SingleNode* slow_pointer = head;
    SingleNode* fast_pointer = head;
    while (fast_pointer->next != NULL && fast_pointer->next->next != NULL) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
    }
    std::cout << slow_pointer->data << std::endl;
}

void find_circle(SingleNode* head)
{
    std::cout << "find circle list : ";

    if (head == NULL || head->next == NULL) {
        std::cout << "no. " << std::endl;
        return;
    }

    SingleNode* slow_pointer = head;
    SingleNode* fast_pointer = head->next;
    while (fast_pointer->next != NULL && fast_pointer->next->next != NULL && fast_pointer != slow_pointer) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
    }
    if (fast_pointer != slow_pointer) {
        // No circle.
        std::cout << "no. " << std::endl;
        return;
    }
    std::cout << "yes. ";

    // Find circle length.
    int circle_length = 1;
    slow_pointer = slow_pointer->next;
    while (slow_pointer != fast_pointer) {
        slow_pointer = slow_pointer->next;
        circle_length ++;
    }
    std::cout << "Circle length is " << circle_length << ". ";

    // Find none circle length.
    SingleNode* slow_head_pointer = head;
    slow_pointer = slow_pointer->next;
    int none_circle_length = 0;
    while (slow_head_pointer != slow_pointer) {
        slow_head_pointer = slow_head_pointer->next;
        slow_pointer = slow_pointer->next;
        none_circle_length ++;
    }
    std::cout << "None circle length is " << none_circle_length << ". ";

    std::cout << std::endl;
}

void combine_two_sorted_list(SingleNode* first_head, SingleNode* second_head)
{
    std::cout << "combined list is ";

    if (first_head == NULL) {
        print_linked_list(second_head);
        return;
    } else if (second_head == NULL) {
        print_linked_list(first_head);
        return;
    }
    
    /* 增加一个哨兵头结点，便于直接构建初始指针队形. */
    SingleNode* pre_pointer = new Node();
    SingleNode* combined_head = pre_pointer;

    while (first_head != NULL && second_head != NULL) {
        if (first_head->data < second_head->data) {
            pre_pointer->next = first_head;
            first_head = first_head->next;
        } else {
            pre_pointer->next = second_head;
            second_head = second_head->next;
        }
        pre_pointer = pre_pointer->next;
    }

    pre_pointer->next = first_head == NULL ? second_head : first_head;
    /* Forawrd the head Node, and delete the guard Node. */
    SingleNode* guard_pointer = combined_head;
    combined_head = combined_head->next;
    delete guard_pointer;

    print_linked_list(combined_head);
}

void delete_last_n_node(SingleNode* head, int n = 1)
{
    std::cout << "delete last " << n << " list is ";

    if (head == NULL || n <= 0) {
        print_linked_list(head);
        return;
    }

    SingleNode* pre_delay_n_pointer = new Node();
    pre_delay_n_pointer->next = head;
    head = pre_delay_n_pointer;
    SingleNode* delay_n_pointer = head;
    SingleNode* forward_pointer = head;
    
    int steps = 0;
    while (forward_pointer != NULL) {
        steps ++;
        forward_pointer = forward_pointer->next;
        if (steps > n) {
            delay_n_pointer = delay_n_pointer->next;
        }
        if (steps > n + 1) {
            pre_delay_n_pointer = pre_delay_n_pointer->next;
        }
    }

    if (steps > n) {
        pre_delay_n_pointer->next = delay_n_pointer->next;
        /* release the deleted Node */
        delete delay_n_pointer;
    }
    /* Forawrd the head Node, and delete the guard Node. */
    SingleNode* guard_pointer = head;
    head = head->next;
    delete guard_pointer;

    print_linked_list(head);
}