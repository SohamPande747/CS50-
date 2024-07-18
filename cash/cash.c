#include <cs50.h>
#include <stdio.h>

int main()
{

    int cent, i = 0, j = 0, k = 0, l = 0, count2, count3, count4, count5;
    do
    {
        cent = get_int("Enter the required change: ");
    }
    while (cent < 0);
    if (cent > 0)
    {
        while (cent - i * 25 >= 0)
        {
            count2 = cent - i * 25;
            i++;
        }

        while (count2 - j * 10 >= 0)
        {
            count3 = count2 - j * 10;
            j++;
        }

        while (count3 - k * 5 >= 0)
        {
            count4 = count3 - k * 5;
            k++;
        }

        while (count4 - l * 1 >= 0)
        {
            count5 = count4 - l * 1;
            l++;
        }

        int final = i + j + k + l - 4;

        printf("Number of Coins required is: %d\n", final);
    }
}