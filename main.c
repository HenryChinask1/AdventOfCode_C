#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("Advent of Code Inputs/2015day1.txt", "r");
    int c;
    int floor = 0;

    while((c = fgetc(fp)) != EOF) {
        if ((char)c == '(') {
            floor += 1;
        } else {
            floor -= 1;
        }
    }
    fclose(fp);
    printf("Final floor is %d\n", floor);
}