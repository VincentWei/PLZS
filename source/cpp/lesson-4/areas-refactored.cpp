/*
 * The answer key for Problem 5 of CPP Lesson 4:
 * <https://courses.fmsoft.cn/plzs/cpp-data-types-more.html#/9/4>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

enum shape_type {
    st_none,
    st_circle,
    st_square,
    st_rectangle,
    st_triangle,
};

struct shape {
    enum shape_type type;
    union {
        double one;
        double two[2];
        double three[3];
    };
};

bool isclose(double a, double b)
{
    double max_val = fabs(a) > fabs(b) ? fabs(a) : fabs(b);
    return (fabs(a - b) <= max_val * DBL_EPSILON);
}

bool isclosef(float a, float b)
{
    float max_val = fabsf(a) > fabsf(b) ? fabsf(a) : fabsf(b);
    return (fabs(a - b) <= max_val * FLT_EPSILON);
}

bool isclosel(long double a, long double b)
{
    long double max_val = fabsl(a) > fabsl(b) ? fabsl(a) : fabsl(b);
    return (fabsl(a - b) <= max_val * LDBL_EPSILON);
}

bool can_make_a_triangle(double d1, double d2, double d3)
{
    if (d1 < 0 or d2 < 0 or d3 < 0) {
        return false;
    }
    else if (
            (!isclose(d1 + d2, d3) && ((d1 + d2) > d3)) and
            (!isclose(d1 + d3, d2) && ((d1 + d3) > d2)) and
            (!isclose(d2 + d3, d1) && ((d2 + d3) > d1))) {
        return true;
    }

    return false;
}

bool prompt_for_triangle(struct shape &shape)
{
    cout << "Please input the lengths for three sides of a triangle:";
    cin >> shape.three[0] >> shape.three[1] >> shape.three[2];

    if (can_make_a_triangle(shape.three[0], shape.three[1], shape.three[2])) {
        shape.type = st_triangle;
    }
    else {
        shape.type = st_none;
    }

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

    if (shape.one < 0) {
        shape.type = st_none;
        return false;
    }

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
    cout << "Please input the length of the side of a square:";
    cin >> shape.one;

    if (shape.one < 0) {
        shape.type = st_none;
        return false;
    }

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
    cout << "Please input the lengths of width and height of a rectangle:";
    cin >> shape.two[0] >> shape.two[1];

    if (shape.two[0] < 0 || shape.two[1] < 0) {
        shape.type = st_none;
        return false;
    }

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
    size_t nr_formulas = sizeof(formulas)/sizeof(formulas[0]);

    unsigned selected;
    while (true) {
        // 显示菜单
        cout << "To calculate the area, please choose a geometrical shape:" << endl;
        for (size_t i = 0; i < nr_formulas; i++) {
            cout << (i + 1) << ". " << formulas[i].name << endl;
        }
        cout << "0. Exit" << endl;

        cin >> selected;

        if (selected == 0) {
            break;
        } else if (selected > nr_formulas) {
            continue;
        }
        else {
            selected--;
        }

        struct shape shape;
        struct formula &formula = formulas[selected];

        formula.prompt_f(shape);
        if (shape.type == st_none)
            continue;

        cout << "The area of your " << formula.name << " is: " << formula.calc_area_f(shape) << endl;
    }
}

