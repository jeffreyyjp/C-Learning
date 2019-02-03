/* Ploar coordinates describe a vector in terms of magnitude and the counterclosckwise angle from the x-axis to the vector. Rectangular coordinates describe the same vector in terms of x and y components(see Figure 16.3). Write a program that reads the magnitude and angle(in degrees) of a vector and then displays the x and y components. The relevant equations are these
x = r cos A y = r sin A
To do the conversion, use a function that takes a structure containing the polar coordinates and returns a structure containing the rectangular coordinates (or use pointers to such structures, if you prefer). */
#include<stdio.h>
#include<math.h>

#define DEG_TO_RAD (4 * atan(1) / 180)

typedef struct polar_v {
    double magnitude;
    double angle;
} Polar_V;

typedef struct rect_v {
    double x;
    double y;
} Rect_V;

Rect_V polar_to_rect(Polar_V);

int main()
{
    Polar_V input;
    Rect_V result;

    puts("Enter magnitude and angle(degrees); enter q to quit:");
    while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
    {
        result = polar_to_rect(input);
        printf("corrdinate x = %f, corrdinate y = %f.\n", result.x, result.y);

    }
    puts("Bye!");

    return 0;
}

Rect_V polar_to_rect(Polar_V pv)
{
    Rect_V rv;
    rv.x = pv.magnitude * cos(DEG_TO_RAD * pv.angle);
    rv.y = pv.magnitude * sin(DEG_TO_RAD * pv.angle);

    return rv;
}