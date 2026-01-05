#include <stdio.h>

//2015 day 2 solution.
int main(void)
{
    int l, w, h = 0;
    int part_one = 0;
    int part_two = 0;
    FILE *fp = fopen("../Advent of Code Inputs/2015day2.txt", "r");
    char lines[10];

    while (fgets(lines, 10, fp) != '\0') {
        sscanf(lines, "%dx%dx%d", &l, &w, &h);
        part_one += ((l * w * 2) + (w * h * 2) + (l * h * 2));
        part_two += l * w * h;
        int min_val = (l * w);
        if ((w * h) < min_val)
            min_val = (w * h);
        if ((h * l) < min_val)
            min_val = (h * l);
        part_one += min_val;
        int min_two = ((l * 2) + (w * 2));
        if (((w * 2) + (h * 2)) < min_two)
            min_two = ((w * 2) + (h * 2));
        if (((l * 2) + (h * 2)) < min_two)
            min_two = ((l * 2) + (h * 2));
        part_two += min_two;
    }
    printf("Part One: %d\n", part_one);
    printf("Part Two: %d\n", part_two);
    fclose(fp);
}