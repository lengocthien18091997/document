#include <stdio.h>

int main()
{
    // đây là kiểu point
    int *p;
    int a = 5;
    p = &a;
    printf("%d\n", p);  // 6356404
    printf("%d\n", *p); // 5
    printf("%d\n", &a); // 6356404

    // đây là kiểu struct
    typedef struct
    {
        char ten;
        int tuoi;
    } HocSinh;
    HocSinh hocSinh1;
    hocSinh1.ten = 'a';
    hocSinh1.tuoi = 2;
    printf("%d   %d", hocSinh1.ten, hocSinh1.tuoi);

    return 0;
}

// ============DANH SÁCH LIÊN KẾT ĐƠN==============================
