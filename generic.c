#include <stdio.h>
#include <stdbool.h>

#define TYPEOF(x) _Generic((x), \
    bool: BOOL, \
    char: CHAR, \
    int: INT, \
    long: LONG, \
    float: FLOAT, \
    double: DOUBLE, \
    void*: VOIDPTR, \
    default: OTHER)

#define SUM(a, b) generic_sum(&(a), TYPEOF(a), &(b), TYPEOF(b))

enum Type {
    OTHER,
    INT,
    SHORT,
    LONG,
    CHAR,
    BOOL,
    FLOAT,
    DOUBLE,
    VOIDPTR
};

double generic_sum(void *a, enum Type a_t, void *b, enum Type b_t);

int main(void)
{
    int a = 5;
    char b = '9';
    bool c = true;
    float d = 3.14f;
    double e = 3.14;
    char *f = "145";

    /* Example calls: */
    /* printf("res = %lf\n", SUM(a, b)); */
    printf("res = %lf\n", SUM(c, d));
    printf("res = %lf\n", SUM(b, e));
    /* printf("str = %s", f); */

    return 0;
}

double generic_sum(void *a, enum Type a_t, void *b, enum Type b_t)
{
    double x = 0.0, y = 0.0;

    switch (a_t) {
    case BOOL:
        x = *(bool *)a ? 1.0 : 0.0;
        break;
    case CHAR:
        if ((*(char *)a >= '0') && (*(char *)a <= '9')) {
            x = (double)(*(char *)a - '0');
        }
        break;
    case INT:
        x = (double)(*(int *)a);
        break;
    case LONG:
        x = (double)(*(long *)a);
        break;
    case FLOAT:
        x = (double)(*(float *)a);
        break;
    case DOUBLE:
        x = *(double *)a;
        break;
    default:
        break;
    }

    switch (b_t) {
    case BOOL:
        y = *(bool *)b ? 1.0 : 0.0;
        break;
    case CHAR:
        if ((*(char *)b >= '0') && (*(char *)b <= '9')) {
            y = (double)(*(char *)b - '0');
        }
        break;
    case INT:
        y = (double)(*(int *)b);
        break;
    case LONG:
        y = (double)(*(long *)b);
        break;
    case FLOAT:
        y = (double)(*(float *)b);
        break;
    case DOUBLE:
        y = *(double *)b;
        break;
    default:
        break;
    }

    return x + y;
}

