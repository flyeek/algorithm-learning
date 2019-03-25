#include <iostream>
#include <stdio.h>
#include <time.h>
#include "../sort.h"

int *construct_array(u_int length)
{
    std::cout << "construct array : ";

    int *array = new int[length];
    srand(time(NULL));
    for (int i = 0; i < length; i++)
    {
        array[i] = (rand() % length) + 1;
    }

    print_array(array, length);

    return array;
}

void test_bubble_sort()
{
    std::cout << std::endl;
    std::cout << "Testing sort using BubbleSort ===========>" << std::endl;

    const u_int test_array_number = 4;
    u_int length_array[test_array_number] = {0, 1, 2, 6};
    int *array = NULL;
    for (int i = 0; i < test_array_number; i++)
    {
        array = construct_array(length_array[i]);
        bubble_sort(array, length_array[i]);
    }
}

void test_select_sort()
{
    std::cout << std::endl;
    std::cout << "Testing sort using SelectSort ===========>" << std::endl;

    const u_int test_array_number = 4;
    u_int length_array[test_array_number] = {0, 1, 2, 6};
    int *array = NULL;
    for (int i = 0; i < test_array_number; i++)
    {
        array = construct_array(length_array[i]);
        select_sort(array, length_array[i]);
    }
}

void test_insert_sort()
{
    std::cout << std::endl;
    std::cout << "Testing sort using InsertSort ===========>" << std::endl;

    const u_int test_array_number = 4;
    u_int length_array[test_array_number] = {0, 1, 2, 6};
    int *array = NULL;
    for (int i = 0; i < test_array_number; i++)
    {
        array = construct_array(length_array[i]);
        insert_sort(array, length_array[i]);
    }
}

int main()
{
    std::cout << "Begin test sort algorithm..." << std::endl;

    test_bubble_sort();
    test_select_sort();
    test_insert_sort();

    return 0;
}