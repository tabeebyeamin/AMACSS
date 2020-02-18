#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(int a, int *b, int *c) {
    a += 5;
    *b += a;
    c = b;
return a;
}
struct Point {
    int x;
    int y;
};


int main(){
    int a[4] = {0, 1, 2, 3};
    int b = 1;
    int *p = a;
    p = p + b;
    b++;
    *p += b;
    p = p + b;
    *p += 2;
    p--;
    *p *= 4;
    p = p - b;
    *p = p - a;

    printf("%d %d %d %d\n",a[0], a[1], a[2], a[3]);


    int x = 5, y = 8, z = 3, t = 0;
    t = func(x, &y, &z);
    printf("x:%d    y:%d    z:%d    t:%d\n", x, y, z, t);


    struct Point p1, p2;
    struct Point *q1, *q2;
    p1.x = 5;
    p2.x = 1;
    q1 = &p2;
    q2 = &p1;
    q1->x += 2;
    q2->x += 4;
    p1.y = 10;
    p2.y = 10;
    q1->y += 7;
    q2->y += 3;
    printf("P1(X,Y) = (%d, %d)\n", p1.x, p1.y);
    printf("P2(X,Y) = (%d, %d)\n", p2.x, p2.y);
}