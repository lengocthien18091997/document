#include <stdio.h>

int soThanhPho;
int chuTrinh[10];
int visited[10];
int quangDuong[10][10];
int chiPhi;
int MIN_COST = 10e8;

int timTpGanNhat(int tpDau)
{
    int min = MIN_COST;
    int tpNext = -1;
    for (int i = 0; i < soThanhPho; ++i)
    {
        if (min > quangDuong[tpDau][i] && tpDau != i && !visited[i])
        {
            min = quangDuong[tpDau][i];
            tpNext = i;
        }
    }
    return tpNext;
}

// hàm chính
void Greedy()
{
    // bat dau tu TP dau tien
    chuTrinh[0] = 0;
    visited[0] = 1;
    int tpDau = 0;
    // tim lien tuc
    for (int i = 0; i < soThanhPho; ++i)
    {
        int next = timTpGanNhat(tpDau);
        chuTrinh[i + 1] = next;
        visited[next] = 1;
        chiPhi += quangDuong[tpDau][next];
        tpDau = next;
    }
}

int main()
{
    // Nhap input
    printf("Nhap so thanh pho: ");
    scanf("%d", &soThanhPho);
    printf("Nhap ma tran quang duong: \n");
    for (int i = 0; i < soThanhPho; ++i)
    {
        visited[i] = 0;
        chuTrinh[i] = 0;
        for (int j = 0; j < soThanhPho; ++j)
        {
            scanf("%d", &quangDuong[i][j]);
        }
    }
    Greedy();
    // in KQ
    for (int i = 0; i < soThanhPho; ++i)
    {
        printf(" - %d", chuTrinh[i] + 1);
    }
    printf("\nChi phi %d", chiPhi);
}