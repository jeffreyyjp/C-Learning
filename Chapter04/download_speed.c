/* download_speed.c -- download speed calculation */
#include<stdio.h>
int main(void)
{
    float download_speed, file_size, speed_time;
    printf("Enter downlaod speed(Mbs) and file size(MB): ");
    scanf("%f%f", &download_speed, &file_size);
    speed_time = file_size * 8.0 / download_speed;
    printf("At %0.2f megabits per second, a file of %0.2f megabytes downloads in %0.2f seconds.\n", download_speed, file_size, speed_time);

    return 0;
}