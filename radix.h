/**
 * This module contains a Radix Sort definition.
*/


#pragma once


#include "common.h"


#define ARRAYSIZE(a)    (sizeof(a) / sizeof(a[0]))


class RadixSort : public Sort {

public:

    RadixSort (
        )
    {
        this->name = "Radix Sort";
    }

    void
    countSort (
        int exp,
        std::vector<int>& nums
        )
    {
        int              count[10] = {0};
        std::vector<int> sorted(nums.size(), 0);

        for (int index = 0; index < nums.size(); index++) {

            int digit = (nums[index] / exp) % 10;
            count[digit]++;
        }

        for (int index = 1; index < ARRAYSIZE(count); index++) {
            count[index] += count[index - 1];
        }

        for (int index = nums.size() - 1; index >= 0; index--) {

            int digit = (nums[index] / exp) % 10;

            sorted[count[digit] - 1] = nums[index];
            count[digit]--;
        }

        for (int index = 0; index < nums.size(); index++) {
            nums[index] = sorted[index];
        }

        return;
    }

    virtual
    void
    sort (
        std::vector<int>& nums
        ) override final
    {
        int maxNum = INT_MIN;

        for (int index = 0; index < nums.size(); index++) {
            maxNum = std::max(maxNum, nums[index]);
        }

        for (int exp = 1; maxNum / exp != 0; exp *= 10) {
            countSort(exp, nums);
        }

        return;
    }
};