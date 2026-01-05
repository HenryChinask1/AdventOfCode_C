#include <stdio.h>

// 2015 day one solution..
// TODO: Figure out how to separate the projects and puzzle days.
int main(void)
{
    // Part One.

    FILE *fp;
    fp = fopen("../Advent of Code Inputs/2015day1.txt", "r");
    int c;
    int floor = 0;

    while((c = fgetc(fp)) != EOF) {
        if ((char)c == '(') {
            floor += 1;
        } else {
            floor -= 1;
        }
    }
    printf("2015 Part One: %d\n", floor);
    
    // Part 2.
    
    c = fseek(fp, 0, SEEK_SET);
    floor = 0;
    int step = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (floor == -1) {
            printf("2015 Part Two: %d\n", step);
            break;
        } else if ((char)c == '(') {
            floor += 1;
            step += 1;
        } else {
            floor -= 1;
            step += 1;
        }    
    }

    fclose(fp);
}