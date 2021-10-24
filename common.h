/**
 * common.h
 *
 * This module contains base Sort class.
*/


#pragma once


#include <string>
#include <vector>
#include <iostream>


class Sort {

public:

    std::string name;

public:

    virtual
    void
    sort (
        std::vector<int>& nums
        ) = 0; // base

    void
    validate (
        std::vector<int>& input,
        std::vector<int>& output
        )
    {
        std::vector<int> expected = input;
        std::sort(expected.begin(), expected.end());

        bool noMatch = false;

        if (input.size() != output.size()) {
            noMatch = true;
        } else {

            for (int index = 0; index < output.size(); index++) {

                if (output[index] != expected[index]) {

                    noMatch = true;
                    break;
                }
            }
        }

        std::cout << this->name << ": ";

        if (noMatch) {

            std::cout << "FAILED" << std::endl;

            std::cout << "EXPECTED: " << std::endl;
            print(expected);

            std::cout << "ACTUAL: " << std::endl;
            print(output);

        } else {
            std::cout << "PASSED" << std::endl;
        }

        return;
    }

    void
    print (
        std::vector<int>& nums
        )
    {
        std::cout << "{ ";

        for (int index = 0; index < nums.size(); index++) {

            std::cout << nums[index];

            if (index < nums.size() - 1) {
                std::cout << ", ";
            }
        }

        std::cout << " }" << std::endl;
    }
};