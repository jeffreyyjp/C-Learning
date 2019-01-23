// Write a file-copy program that takes the original filename and the copy file from the command line. Use standard I/O and the binary mode, if possible.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SLEN 81
#define BUFSIZE 4096

void copy(FILE *, FILE *);

int main(int argc, char const *argv[])
{
    FILE * fs, * fd;
    int ch;

    if (argc != 3)
    {
        printf("Usage: %s filename filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fs = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create input buffer.\n", stderr);
        exit(EXIT_FAILURE);
    }

    if ((fd = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fd, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer.\n", stderr);
        exit(EXIT_FAILURE);
    }

    copy(fs, fd);
    printf("Done copying.\n");
    fclose(fs);
    fclose(fd);
    return 0;
}

void copy(FILE * src, FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZ];
    while ((bytes = fread(temp, sizeof(char), BUFSIZ, src)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}