#include<stdio.h>
#define CSIZE 4
#define GRADE_SIZE 3
#define MAXNAME 20

#define EATLINE while (getchar() != '\n') continue

struct name {
    char first[MAXNAME];
    char second[MAXNAME];
};

struct student {
    struct name handle;
    double grade[GRADE_SIZE];
    double average;
};

void get_score(struct student *, int);
void get_avergae(struct student *, int);
void print_info(struct student *, int);


int main(void)
{
    struct student students[CSIZE] = {
        {{"Marvin", "Martian"}},
        {{"Scrooge", "Duck"}},
        {{"Mantis", "Tobogan"}},
        {{"Night", "Man"}}
    };

    get_score(&students[0], CSIZE);
    get_avergae(&students[0], CSIZE);
    print_info(&students[0], CSIZE);
    double sum = 0;
    for (int i = 0; i < CSIZE; i++)
        sum += students[i].average;
    printf("Average of class scores is %.2lf.\n", sum / CSIZE);
    return 0;
}

void get_score(struct student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < GRADE_SIZE; j++)
        {
            printf("Please enter %s's score: ", students[i].handle.first);
            scanf("%lf", &students[i].grade[j]);
            EATLINE;
        }
    }
}

void get_avergae(struct student *students, int n)
{
    double sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < GRADE_SIZE; j++)
        {
            sum += students[i].grade[j];
        }
        students[i].average = sum / GRADE_SIZE;
    }
}

void print_info(struct student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s, %s's score is: ", students[i].handle.first, students[i].handle.second);
        for (int j = 0; j < GRADE_SIZE; j++)
            printf("%.2lf ", students[i].grade[j]);
        printf("\nAverage is %.2lf.\n", students[i].average);
    }
}