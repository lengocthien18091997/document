#include <stdio.h>
#include <math.h>

int n;
int a[100];

int maxleft(int l, int r)
{
    int s = 0;
    int max = -10e6;
    for (int i = r; i >= l; --i)
    {
        s = s + a[i];
        if (s > max)
            max = s;
    }
    return max;
}

int maxright(int l, int r)
{
    int s = 0;
    int max = -10e6;
    for (int i = l; i <= r; ++i)
    {
        s = s + a[i];
        if (s > max)
            max = s;
    }
    return max;
}

int hmax(int a, int b)
{
    int max = b;
    if (a > b)
    {
        max = a;
    }
    return max;
}

// hàm chính, truyền vào left và right
int DC(int l, int r)
{
    // nếu left = right thì trả về
    if (l == r)
    {
        return a[l];
    }
    int mid = (l + r) / 2;
    int s1 = DC(l, mid);
    int s2 = DC(mid + 1, r);
    int s3 = maxleft(l, mid) + maxright(mid + 1, r);
    int max1 = hmax(s1, s2);
    int max = hmax(max1, s3);
    return max;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    int maxsum = DC(0, n - 1);
    printf("%d", maxsum);

    return 0;
}