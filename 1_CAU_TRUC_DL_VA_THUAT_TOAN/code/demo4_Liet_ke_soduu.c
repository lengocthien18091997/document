#include <stdio.h>

int x[9][9];
int markR[9][10], markC[9][10], markS[3][3][10]; // Đánh dấu các số đã xuất hiện trong hàng, cột, và ô 3x3

// Hàm kiểm tra xem có thể điền số 'v' vào vị trí (r, c) không
int check(int v, int r, int c)
{
    if (markR[r][v] || markC[c][v] || markS[r / 3][c / 3][v])
    {
        return 0; // Không thể điền
    }
    return 1; // Có thể điền
}

// Hàm in ra lời giải Sudoku hiện tại
void solution()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}

// Hàm đệ quy quay lui để thử điền các số vào bảng Sudoku
int Try(int r, int c)
{
    if (r == 9)
    { // Nếu đã điền đến cuối bảng (hàng 9, cột 0)
        solution();
        return 1; // Đã tìm thấy một lời giải, trả về 1 để dừng lại
    }

    if (x[r][c] != 0)
    { // Nếu ô này đã có số (không phải ô trống)
        if (c == 8)
            return Try(r + 1, 0); // Chuyển sang hàng tiếp theo
        else
            return Try(r, c + 1); // Chuyển sang cột tiếp theo
    }
    else
    {
        for (int v = 1; v <= 9; ++v)
        { // Thử điền các số từ 1 đến 9
            if (check(v, r, c))
            { // Nếu số này hợp lệ
                // Đánh dấu và điền số vào ô
                x[r][c] = v;
                markR[r][v] = 1;
                markC[c][v] = 1;
                markS[r / 3][c / 3][v] = 1;

                // Đệ quy với ô tiếp theo
                if ((c == 8 && Try(r + 1, 0)) || (c < 8 && Try(r, c + 1)))
                {
                    return 1; // Nếu tìm thấy lời giải, trả về 1
                }

                // Quay lui: Xóa đánh dấu và bỏ số điền vào ô
                x[r][c] = 0;
                markR[r][v] = 0;
                markC[c][v] = 0;
                markS[r / 3][c / 3][v] = 0;
            }
        }
    }

    return 0; // Trả về 0 nếu không tìm thấy lời giải từ trạng thái hiện tại
}

int main()
{
    // Khởi tạo bảng Sudoku và các đánh dấu
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            x[i][j] = 0; // Mặc định các ô đều trống (0)
            for (int v = 1; v <= 9; v++)
            {
                markR[i][v] = markC[j][v] = markS[i / 3][j / 3][v] = 0; // Đánh dấu tất cả là chưa có số
            }
        }
    }

    // Khởi tạo một câu đố Sudoku
    // Thay giá trị của ô x[i][j] bằng các số cụ thể để tạo câu đố
    x[0][0] = 1;
    markR[0][5] = 1;
    markC[0][5] = 1;
    markS[0][0][5] = 1;
    // Tiếp tục điền thêm dữ liệu vào đây để tạo câu đố ban đầu

    // Bắt đầu giải Sudoku từ ô (0, 0)
    Try(0, 0);

    return 0;
}
