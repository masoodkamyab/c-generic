#include <stdio.h>
#include <stdbool.h>

#define typeof(x) _Generic(x, bool: BOOL, char: CHAR, int: INT, long: LONG, float: FLOAT, double: DOUBLE, void*: VOIDPTR, default: OTHER)
#define sum(a, b) genericSum(&a, typeof(a), &b, typeof(b))

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

double genericSum(void* a, enum Type a_t, void* b, enum Type b_t);

void main()
{
	int a = 5;
	char b = '9';
	bool c = true;
	float d = 3.14;
	double e = 3.14;
	char* f = "145";

	//printf("res = %lf\n", sum(a, b));
	printf("res = %lf\n", sum(c, d));
	printf("res = %lf\n", sum(b, e));
	//printf("str = %s", f);
	
	return;
}

double genericSum(void* a, enum Type a_t, void* b, enum Type b_t)
{
	double x = 0, y = 0;
	
	switch(a_t)
	{
		case BOOL:
			x = *(bool*)a;
			break;
		case CHAR:
			if (*(char*)a >= 48 && *(char*)a <= 57)
				x = *(char*)a - 48;
			break;
		case INT:
			x = *(int*)a;
		case LONG:
			x = *(long*)a;
			break;
		case FLOAT:
			x = *(float*)a;
			break;
		case DOUBLE:
			x = *(double*)a;
			break;
	}
	
	switch(b_t)
	{
		case BOOL:
			y = *(bool*)b;
		case CHAR:
			if (*(char*)b >= 48 && *(char*)b <= 57)
				y = *(char*)b - 48;
			break;
		case INT:
			y = *(int*)b;
		case LONG:
			y = *(long*)b;
			break;
		case FLOAT:
			y = *(float*)b;
			break;
		case DOUBLE:
			y = *(double*)b;
			break;
	}
	
	return x + y;
}

// add string numbers
// add toInt function