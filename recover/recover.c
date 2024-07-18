#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    int byteRead, count = 0;
    char *filename = (char *) malloc(8 * sizeof(char));
    BYTE buffer[512];
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outImg = NULL;

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    if (inputFile == NULL)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    for (;;)
    {
        byteRead = fread(buffer, sizeof(BYTE), 512, inputFile);

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count == 0)
            {
                sprintf(filename, "%03i.jpg", count);
                outImg = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), byteRead, outImg);
                count++;
            }
            else
            {
                fclose(outImg);
                sprintf(filename, "%03i.jpg", count);
                outImg = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), byteRead, outImg);
                count++;
            }
        }
        else if (count != 0)
        {
            fwrite(buffer, sizeof(BYTE), byteRead, outImg);

            if (byteRead == 0)
            {
                fclose(outImg);
                fclose(inputFile);
                break;
            }
        }
    }
    free(filename);

    return 0;
}
