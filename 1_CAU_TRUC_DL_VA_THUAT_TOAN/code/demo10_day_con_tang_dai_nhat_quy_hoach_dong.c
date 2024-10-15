// #include <stdio.h>
// #include <math.h>

// int n;
// int a[1000];
// int con[1000];
// int s[100][100];

// void timDayCon()
// {
//     s[0][0] = a[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (a[i] > a[i - 1])
//         {
//             s[i] = s[i - 1]
//         }
//     }
// }

// int main()
// {
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     timDayCon();
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\n", s[i]);
//     }
// }

//===========================
#include <stdio.h>

int main()
{
    int s[100][100] = {{0}};     // Khởi tạo mảng hai chiều s với tất cả phần tử là 0
    int a[100];                  // Mảng a chứa các phần tử đầu vào
    int column_sizes[100] = {0}; // Mảng lưu số lượng phần tử ở mỗi hàng

    // Khởi tạo dữ liệu cho mảng a
    for (int i = 0; i < 100; i = i + 2)
    {
        a[i] = i + 4; // Ví dụ, gán giá trị từ 1 đến 100 cho mảng a
        a[i + 1] = i - 3;
    }

    // Gán giá trị cho hàng đầu tiên
    s[0][0] = a[0];
    column_sizes[0] = 1;

    // Duyệt qua mảng a để tạo các hàng tiếp theo trong s
    for (int i = 1; i < 100; i++)
    {
        // Sao chép phần tử từ hàng trước sang hàng hiện tại
        int k = 0;
        for (int j = 0; j < column_sizes[i - 1]; j++)
        {
            s[i][k++] = s[i - 1][j];
        }

        int last_element = s[i - 1][column_sizes[i - 1] - 1];

        // Áp dụng các điều kiện cho phần tử a[i]
        if (a[i] > last_element)
        {
            s[i][k++] = a[i];
        }
        else if (a[i] < last_element && i >= 2 && a[i] > a[i - 2])
        {
            s[i][k - 1] = a[i];
        }

        // Cập nhật số lượng phần tử của hàng hiện tại
        column_sizes[i] = k;
    }

    // In kết quả để kiểm tra từng hàng của s
    for (int i = 0; i < 100; i++)
    {
        printf("Hàng %d: ", i);
        for (int j = 0; j < column_sizes[i]; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}
