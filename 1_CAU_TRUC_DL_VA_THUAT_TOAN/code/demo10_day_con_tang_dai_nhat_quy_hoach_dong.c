#include <stdio.h>
#include <math.h>

int n;
int a[1000];
int con[1000];
int s[100][100];

void timDayCon()
{
    s[0][0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            s[i] = s[i - 1]
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    timDayCon();
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d\n", s[i]);
    // }
}