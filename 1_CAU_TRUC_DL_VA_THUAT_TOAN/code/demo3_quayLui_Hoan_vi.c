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
    // số có 3 số thì lặp từ 1 đến 3
    for (int v = 1; v <= n; ++v)
    {
        // nếu kiểm tra các số trước mà thấy k trùng (VD 1 & 2 => ko trùng)
        if (check(v, k))
        {
            // thì số tiếp theo sau 1 sẽ là số 2
            x[k] = v;
            used[v] = 1;
            // nếu k = 3 tức đây là số cuối rồi thì in luôn kết quả
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
