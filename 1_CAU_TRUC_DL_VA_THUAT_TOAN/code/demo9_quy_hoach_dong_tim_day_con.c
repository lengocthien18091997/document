#include <stdio.h>
#include <math.h>

int n;
int dayBanDau[1000];
int ketQuaThu[100];

void timDayCon()
{
    ketQuaThu[0] = dayBanDau[0];
    // chạy
    for (int i = 1; i < n; i++)
    {
        if (ketQuaThu[i - 1] > 0)
        {
            ketQuaThu[i] = ketQuaThu[i - 1] + dayBanDau[i];
        }
        else
        {
            ketQuaThu[i] = dayBanDau[i];
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dayBanDau[i]);
    }
    timDayCon();
    printf("%d - ", ketQuaThu[n - 1]);
}