#include <stdio.h>

//2015 day 2 solution.
int main(void)
{
    int l, w, h = 0;
    int total = 0;
    FILE *fp = fopen("../Advent of Code Inputs/2015day2.txt", "r");
    char lines[20];

    while (fgets(lines, 20, fp) != '\0') {
        sscanf(lines, "%dx%dx%d", &l, &w, &h);
        total += ((l * w * 2) + (w * h * 2) + (l * h * 2));
        int min_val = (l * w);
        if ((w * h) < min_val)
            min_val = (w * h);
        if ((h * l) < min_val)
            min_val = (h * l);
        total += min_val;
    }
    printf("Part One: %d", total);
    fclose(fp);
}