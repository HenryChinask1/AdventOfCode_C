#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("../Advent of Code Inputs/2016day1.txt", "r");



    int factors[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };

    int currDir = 0;
    int location[1][2] = {0, 0};

    
}