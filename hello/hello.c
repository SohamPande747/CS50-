#include <cs50.h>
#include <stdio.h>

int main()
{
    string name = get_string("What is your name: ");
    printf("%s", name);

    return 0;
}