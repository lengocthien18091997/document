#include <stdio.h>

int main()
{
    int a[] = {1, 4, 8, 12, 5, 1, 3}; // Khởi tạo mảng hợp lệ
    int n = sizeof(a) / sizeof(a[0]); // Xác định kích thước mảng
    int maxSum = a[0];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
                count++;
            }
            if (sum > maxSum)
                maxSum = sum;
        }
    }

    printf("Max Sum: %d\n", maxSum); // Đảm bảo dùng đúng định dạng cho printf
    printf("Count: %d\n", count);
    return 0;
}
