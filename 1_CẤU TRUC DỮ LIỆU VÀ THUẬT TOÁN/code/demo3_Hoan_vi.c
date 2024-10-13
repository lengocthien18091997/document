#include <stdio.h>

int x[100];
int n = 3;
int used[100];

int check(int v, int k)
{
    for (int i = 1; i <= k - 1; ++i) // Sửa i và điều kiện vòng lặp
    {
        if (x[i] == v)
        {
            return 0; // Không chấp nhận vì trùng
        }
    }
    return 1; // Chấp nhận vì không trùng
}

void Try(int k)
{
    for (int v = 1; v <= n; ++v) // Vòng lặp từ 1 đến n để tạo hoán vị từ 1 đến n
    {
        if (check(v, k))
        {
            x[k] = v;
            used[v] = 1;
            if (k == n)
            {
                // in kết quả
                for (int i = 1; i <= n; ++i)
                {
                    printf("%d ", x[i]);
                }
                printf("\n");
            }
            else
            {
                Try(k + 1);
            }
            used[v] = 0;
        }
    }
}

int main()
{
    for (int i = 1; i <= n; ++i)
    {
        used[i] = 0;
    }
    n = 3; // Đặt số phần tử của hoán vị
    Try(1);
    return 0;
}
