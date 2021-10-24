/**
 * heap.h
 *
 * This module contains a Heap Sort definition.
*/


#pragma once


#include "common.h"


class HeapSort : public Sort {

public:

    HeapSort (
        )
    {
        this->name = "Heap Sort";
    }

    void
    heapify (
        int index,
        int size,
        std::vector<int>& nums
        )
    {
        int largest = index;
        int left    = 2 * index + 1;
        int right   = 2 * index + 2;

        if (left < size && nums[largest] < nums[left]) {
            largest = left;
        }

        if (right < size && nums[largest] < nums[right]) {
            largest = right;
        }

        if (largest != index) {

            std::swap(nums[largest], nums[index]);
            heapify(largest, size, nums);
        }
    }

    virtual
    void
    sort (
        std::vector<int>& nums
        ) override final
    {
        for (int index = nums.size() / 2 - 1; index >= 0; index--) {
            heapify(index, nums.size(), nums);
        }

        for (int index = nums.size() - 1; index > 0; index--) {

            std::swap(nums[0], nums[index]);
            heapify(0, index, nums);
        }
    }
};