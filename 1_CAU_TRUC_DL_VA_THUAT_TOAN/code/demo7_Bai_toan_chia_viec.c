#include <stdio.h>

int soCongViec;
int tongLoiNhuan;
int timeLine[1000000];
int thuTu[1000000];
typedef struct
{
    int id;
    int deadline;
    int loiNhuan;
    int daXep;
} CongViec;
CongViec congViec[1000000];
CongViec congViecSorted[1000000];

void sapXepGiamDan()
{
    for (int i = 0; i < soCongViec - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < soCongViec; j++)
        {
            if (congViec[j].loiNhuan > congViec[maxIndex].loiNhuan)
            {
                maxIndex = j; // Cập nhật chỉ số của phần tử lớn nhất
            }
        }
        // Hoán đổi phần tử lớn nhất với phần tử đầu tiên
        if (maxIndex != i)
        {
            CongViec temp = congViec[i];
            congViec[i] = congViec[maxIndex];
            congViec[maxIndex] = temp;
        }
    }
}

void xepViecThu(int viec)
{
    for (int j = congViec[viec].deadline; j > 0; --j)
    {
        if (timeLine[j] == -1)
        {
            timeLine[j] = congViec[viec].id;
            tongLoiNhuan += congViec[viec].loiNhuan;
            break;
        }
    }
}

void sapXepViec()
{
    sapXepGiamDan();
    for (int i = 0; i < soCongViec; i++)
    {
        xepViecThu(i);
    }
}

int main()
{
    tongLoiNhuan = 0;
    // nhap input
    scanf("%d", &soCongViec);
    for (int i = 0; i < 1000000; i++)
    {
        timeLine[i] = -1;
    }
    for (int i = 0; i < soCongViec; ++i)
    {
        congViec[i].id = i;
        congViec[i].daXep = 0;
        scanf("%d %d", &congViec[i].deadline, &congViec[i].loiNhuan);
    }
    sapXepViec();
    printf("%d", tongLoiNhuan);
    return 0;
}