#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Enter start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("Enter end size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold



    int result = start;
    //start + start/3 - start/4;
    //printf("start: %d\n", result);

    int count = 0;

    while (result < end)
    {
        result += (result/3) - (result/4);
        printf("Result: %d\n", result);
        count++;
    }


    // TODO: Print number of years

    printf("Years: %d\n ", count);

}
