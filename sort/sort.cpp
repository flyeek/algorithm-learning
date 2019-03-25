#include <iostream>
#include "sort.h"

void print_array(int *array, u_int length)
{
    if (length == 0)
    {
        std::cout << "NULL array";
    }

    for (int i = 0; i < length; i++)
    {
        std::cout << array[i] << "-";
    }
    std::cout << std::endl;
}

void bubble_sort(int *array, u_int length)
{
    for (int i = 0; i < length; i++)
    {
        bool has_swapped = false;
        int index_max_bubble = 0;
        for (int j = 1; j < length - i; j++)
        {
            if (array[index_max_bubble] > array[j])
            {
                // make max bubble rise up.
                int tmp = array[index_max_bubble];
                array[index_max_bubble] = array[j];
                array[j] = tmp;

                has_swapped = true;
            }
            index_max_bubble++;
        }

        // if no swap happen, it means the array is already ordered.
        if (!has_swapped)
        {
            break;
        }
    }

    std::cout << "the sorted array is : ";
    print_array(array, length);
}

void select_sort(int *array, u_int length)
{
    for (int i = 0; i < length; i++)
    {
        u_int min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[min_index] > array[j])
            {
                min_index = j;
            }
        }

        // Swap the min_index element with the first unsorted element, which is indexed by i.
        if (min_index != i) {
            int tmp = array[i];
            array[i] = array[min_index];
            array[min_index] = tmp; 
        }
    }

    std::cout << "the sorted array is : ";
    print_array(array, length);
}

void insert_sort(int *array, u_int length)
{
    for (int i = 0; i < length; i++)
    {
        u_int target_index = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[target_index] < array[j])
            {
                // Swap to make these two sorted.
                int tmp = array[target_index];
                array[target_index] = array[j];
                array[j] = tmp;

                target_index = j;
            } else {
                break;
            }
        }
    }

    std::cout << "the sorted array is : ";
    print_array(array, length);
}