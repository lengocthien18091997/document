#include <stdio.h>

int x[100];
int n;

void Try(int k) // Thêm kiểu dữ liệu cho tham số k
{
    printf("%d\n", k);
    // Lặp 0 và 1 là 2 khả năng
    for (int v = 0; v <= 1; ++v)
    {
        // gán x[tầng đệ quy ]
        x[k] = v;
        if (k == n)
        {
            for (int i = 1; i <= n; ++i)
            {
                printf("%d", x[i]);
            }
            printf("\n");
        }
        else
        {
            Try(k + 1);
        }
    }
}

int main()
{
    n = 3; // Gán giá trị cho n (ở đây là 2 phần tử nhị phân)
    Try(1);
    return 0;
}
