/**
 * main.cpp
 *
 * This module contains the program entry point.
*/


#include "common.h"
#include "radix.h"


int
main (
    )
{
    std::vector<int> input = {11397, 29, 8, 4, 2100000, 1, 3, 6, 7, 1023};

    {
        RadixSort sort;

        auto output = input;
        sort.sort(output);

        sort.validate(input, output);
    }

    return 0;
}
