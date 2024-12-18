#include <stdio.h>
#include <math.h>

double length(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double area(double a, double b, double c)
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int pointInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
    double a = length(x1, y1, x2, y2);
    double b = length(x2, y2, x3, y3);
    double c = length(x3, y3, x1, y1);
    double totalArea = area(a, b, c);
    double sub1 = area(length(x, y, x1, y1), length(x, y, x2, y2), a);
    double sub2 = area(length(x, y, x2, y2), length(x, y, x3, y3), b);
    double sub3 = area(length(x, y, x3, y3), length(x, y, x1, y1), c);

    double epsilon = 1e-6;
    return fabs(totalArea - (sub1 + sub2 + sub3)) < epsilon;
}

int main()
{
    int x[3], y[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter coordinates of point %d (x y): ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    double s[3] = {length(x[0], y[0], x[1], y[1]), length(x[1], y[1], x[2], y[2]), length(x[2], y[2], x[0], y[0])};

    if (s[0] + s[1] > s[2] && s[1] + s[2] > s[0] && s[2] + s[0] > s[1])
    {
        double triangleArea = area(s[0], s[1], s[2]);
        printf("Area of the triangle: %lf\n", triangleArea);

        int newX, newY;
        printf("Enter coordinates of a new point (x y): ");
        scanf("%d %d", &newX, &newY);

        if (pointInsideTriangle(x[0], y[0], x[1], y[1], x[2], y[2], newX, newY))
        {
            printf("The new point is inside the triangle.\n");
        }
        else
        {
            printf("The new point is outside the triangle.\n");
        }
    }
    else
    {
        printf("A triangle cannot be formed with the given points.\n");
    }

    return 0;
}
