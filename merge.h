/**
 * merge.h
 *
 * This module contains a Merge Sort definition.
*/


#pragma once


#include "common.h"


class MergeSort : public Sort {

public:

    MergeSort (
        )
    {
        this->name = "Merge Sort";
    }

    void
    sort (
        int start,
        int end,
        std::vector<int>& nums
        )
    {
        if (start == end) {
            return;
        }

        int mid = (start + end) / 2;

        sort(start, mid, nums);
        sort(mid + 1, end, nums);

        std::vector<int> merged(end - start + 1, 0);

        int left  = start;
        int right = mid + 1;

        for (int index = 0; index < merged.size(); index++) {

            if (left  <= mid &&
                right <= end) {

                if (nums[left] < nums[right]) {
                    merged[index] = nums[left++];
                } else {
                    merged[index] = nums[right++];
                }
            } else
            if (left <= mid) {
                merged[index] = nums[left++];
            } else
            if (right <= end) {
                merged[index] = nums[right++];
            }
        }

        for (int index = start; index <= end; index++) {
            nums[index] = merged[index - start];
        }
    }

    virtual
    void
    sort (
        std::vector<int>& nums
        ) override
    {
        sort(0, nums.size() - 1, nums);
    }
};
