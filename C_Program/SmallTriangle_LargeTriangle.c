/*      Problem:find which one is small triangle and print this triangle in sorting form.
        p = (a+b+c)/2
        s = sqrt(p*(p-a)*(p-b)*(p-c));
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle *tr, int n)
{
    double p, a[n];
    for (int i = 0; i < n; i++)
    {
        p = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        a[i] = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                triangle temp = tr[j];
                tr[j] = tr[i];
                tr[i] = temp;
                float temp1 = a[j];
                a[j] = a[i];
                a[i] = temp1;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}
/*

Input:
3
7 24 25
5 12 13
3 4 5

Output:
3 4 5
5 12 13
7 24 25

*/