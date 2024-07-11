#include <iostream>
#include <cmath>

using namespace std;

enum shape_type {
    st_circle,
    st_square,
    st_rectangle,
    st_triangle,
};

struct shape {
    enum shape_type type;
    const char *name;
    union {
        double one;
        double two[2];
        double three[3];
    };
};

bool prompt_for_triangle(struct shape &shape)
{
    cout << "Please input length for three sides of a triangle:";
    cin >> shape.three[0] >> shape.three[1] >> shape.three[2];

    if (shape.three[0] < 0 || shape.three[1] < 0 || shape.three[2] < 0)
        return false;

    // TODO: do more check here.

    shape.type = st_triangle;
    return true;
}

double calc_perimeter_triangle(const struct shape &shape)
{
    return shape.three[0] + shape.three[1] + shape.three[2];
}

double calc_area_triangle(const struct shape &shape)
{
    double p = (shape.three[0] + shape.three[1] + shape.three[2]) * 0.5;

    return sqrt(p * (p - shape.three[0]) * (p - shape.three[1]) * (p - shape.three[2]));
}

bool prompt_for_circle(struct shape &shape)
{
    cout << "Please input the radius of a circle:";
    cin >> shape.one;

    if (shape.one < 0)
        return false;

    shape.type = st_circle;
    return true;
}

double calc_perimeter_circle(const struct shape &shape)
{
    return 2 * M_PI * shape.one;
}

double calc_area_circle(const struct shape &shape)
{
    return M_PI * shape.one * shape.one;
}

bool prompt_for_square(struct shape &shape)
{
    cout << "Please input the length of one side of a square:";
    cin >> shape.one;

    if (shape.one < 0)
        return false;

    shape.type = st_square;
    return true;
}

double calc_perimeter_square(const struct shape &shape)
{
    return shape.one * 4;
}

double calc_area_square(const struct shape &shape)
{
    return shape.one * shape.one;
}

bool prompt_for_rectangle(struct shape &shape)
{
    cout << "Please input the lengthes of width and height of a rectangle:";
    cin >> shape.two[0] >> shape.two[1];

    if (shape.two[0] < 0 || shape.two[1] < 0)
        return false;

    shape.type = st_rectangle;
    return true;
}

double calc_perimeter_rectangle(const struct shape &shape)
{
    return (shape.two[0] + shape.two[1]) * 2;
}

double calc_area_rectangle(const struct shape &shape)
{
    return shape.two[0] * shape.two[1];
}

static struct formula {
    const char *name;

    bool (*prompt_f)(struct shape &);
    double (*calc_perimeter_f)(const struct shape &);
    double (*calc_area_f)(const struct shape &);
} formulas[] = {
    { "Circle",     prompt_for_circle, calc_perimeter_circle, calc_area_circle },
    { "Square",     prompt_for_square, calc_perimeter_square, calc_area_square },
    { "Rectangle",  prompt_for_rectangle, calc_perimeter_rectangle, calc_area_rectangle },
    { "Triangle",   prompt_for_triangle, calc_perimeter_triangle, calc_area_triangle },
};

int main()
{
    struct shape shape;
    struct formula &formula = formulas[st_circle];

    formula.prompt_f(shape);
    cout << "Perimeter: " << formula.calc_perimeter_f(shape) << endl;
    cout << "Area: " << formula.calc_area_f(shape) << endl;
}

