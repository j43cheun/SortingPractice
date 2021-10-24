/**
 * quick.h
 *
 * This module contains a Quick Sort definition.
*/


#pragma once


#include "common.h"


class QuickSort : public Sort {

public:

    QuickSort (
        )
    {
        this->name = "Quick Sort";
    }

    int
    partition (
        int low,
        int high,
        std::vector<int>& nums
        )
    {
        int i     = low - 1;
        int pivot = nums[high];

        for (int j = low; j < high; j++) {

            if (nums[j] < pivot) {

                i++;
                std::swap(nums[i], nums[j]);
            }
        }

        std::swap(nums[i + 1], nums[high]);

        return i + 1;
    }

    void
    sort (
        int low,
        int high,
        std::vector<int>& nums
        )
    {
        if (low < high) {

            int partitionIndex = partition(low, high, nums);

            sort(low,
                 partitionIndex - 1,
                 nums);

            sort(partitionIndex + 1,
                 high,
                 nums);
        }

        return;
    }

    virtual
    void
    sort (
        std::vector<int>& nums
        ) override final
    {
        sort(0,
             nums.size() - 1,
             nums);

        return;
    }
};