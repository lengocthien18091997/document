#include <stdio.h>
#include <string.h>

int n;
int c[10][10];
int x[10];
int visited[10];
int f = 0;
int fbest = 10e8;
int cmin = 10e8;
int xbest[10];

void solution()
{
    for (int i = 0; i < n; ++i)
    {
        printf("\n %d", xbest[i]);
    }
}

int check(int v, int k)
{
    if (visited[v] == 1)
    {
        return 0;
    }
    return 1;
}

void Try(int k)
{
    for (int v = 2; v <= n; ++v)
    {
        if (check(v, k))
        {
            x[k] = v;
            visited[v] = 1;
            f = f + c[x[k - 1]][x[k]];
            if (k == n)
            {
                int ftemp = f + c[x[n - 1]][x[1]];
                if (ftemp < fbest)
                {
                    fbest = ftemp;
                }
            }
            else
            {
                int g = f + (n - k + 1) * cmin;
                if (g < fbest)
                    Try(k + 1);
            }
        }
    }
}

int main()
{
    // nhap input
    scanf("%d", &n);
    for (int a = 0; a < n; ++a)
    {
        for (int b = 0; b < n; ++b)
        {
            scanf("%d", &c[a][b]);
        }
    }

    for (int i = 2; i <= n; ++i)
    {
        visited[i] = 0;
    }

    x[1] = 1;
    visited[1] = 1;
    Try(2);
    printf("Chi phi nho nhat: %d\n", fbest);
    solution();
    return 0;
}