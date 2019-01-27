// Digital images, particularly those radioed back from spacecraft, may have glitches. Add a de-glitching function to programming exercise 12. It should compare each value to its immediate neighbors to the left and right, above and below. If the value differ by more than 1 from each of its neighbors, replace the value with the average of the neighboring values. You should round the average to the nearest integer value. Note that the points along the boundaries have fewer than four neighbors, so they require special handling.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ROWS 20
#define COLS 30

void de_glitching(int ar[][COLS], int ROWSs);

int main(int argc, char const *argv[])
{
    FILE * fp;
    int data[ROWS][COLS];
    int image[ROWS][COLS + 1];
    char ch;
    
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

    // read ints from file
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (fscanf(fp, "%d", *(data + i) + j) != 1)
            {
                fprintf(stderr, "Invalid or corrupted data file.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(fp);

    de_glitching(data, ROWS);

    // convert ints to char
    for (int i = 0; i < ROWS; i++)
    {
        int j;
        for (j = 0; j < COLS; j++)
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
    for (int i = 0; i < ROWS; i++)
    {
        puts(image[i]);
        fprintf(fp, "%s\n", image[i]);
    }
    fclose(fp);

    return 0;
}

void de_glitching(int ar[][COLS], int ROWSs)
{
    double sum;
    int count;
    for (int i = 0; i < ROWSs; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum = 0;
            count = 0;
            if (j - 1 >= 0)
            {
                if (fabs(ar[i][j] - ar[i][j - 1]) <= 1.0)
                    continue;
                sum += ar[i][j - 1];
                count++;
            }
            if (j + 1 < COLS)
            {
                if (fabs(ar[i][j] - ar[i][j + 1]) <= 1.0)
                    continue;
                sum += ar[i][j + 1];
                count++;
            }
            if (i - 1 >= 0)
            {
                if (fabs(ar[i][j] - ar[i - 1][j]) <= 1.0)
                    continue;
                sum += ar[i - 1][j];
                count++;
            }
            if (i + 1 < ROWS)
            {
                if (fabs(ar[i][j] - ar[i + 1][j]) <= 1.0)
                    continue;
                sum += ar[i + 1][j];
                count;
            }
            ar[i][j] = (int) (sum / count);
        }
    }
}
