// Do Programming Exercise 12, but use variable-length array(VLAs) instead of standard arrays.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
// #include<stdbool.h>

int main(int argc, char const *argv[])
{
    FILE * fp;
    int rows = 0, cols = 0;
    int ch;
    
    if (argc != 3)
    {
        printf("Usage: %s [data file] [image file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        if (isdigit(ch))
            cols++;
        if (ch == '\n')
            break;
    }
    rewind(fp);

    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
            rows++;
    }

    int data[rows][cols];
    int image[rows][cols + 1];
    fclose(fp);

    // convert ints to char
    for (int i = 0; i < rows; i++)
    {
        int j;
        for (j = 0; j < cols; j++)
        {
            switch (data[i][j])
            {
                case 0:
                    ch = ' ';
                    break;
                case 1:
                    ch = '.';
                    break;
                case 2:
                    ch = '\'';
                    break;
                case 3:
                    ch = ':';
                    break;
                case 4:
                    ch = '~';
                    break;
                case 5:
                    ch = '*';
                    break;
                case 6:
                    ch = '=';
                    break;
                case 7:
                    ch = '}';
                    break;
                case 8:
                    ch = '%';
                    break;
                case 9:
                    ch = '#';
                    break;
                default:
                    fprintf(stderr, "Error: int out of bounds.\n");
                    exit(EXIT_FAILURE);
            }
            image[i][j] = ch;
        }
        image[i][j] = '\0';
    }

    // open iamge file
    if ((fp = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++)
    {
        puts(image[i]);
        fprintf(fp, "%s\n", image[i]);
    }
    fclose(fp);

    return 0;
}
