/**
 * Thuật toán phân chia danh sách lớp làm đề cương môn động vật có xương sống
 * Lớp có 21 người, động vật có xương có 9 nhóm, mỗi nhóm chỉ nên có tối thiểu 2 người và tối đa 3 người
 * Giải HPT ra được có 6 nhóm 2 người và 3 nhóm 3 người
 * Ta đầu tiên đi hóan vi danh sách 21 người trong lớp
 * sau đó merge với danh sách nhóm đã biết sẵn số người trong nhóm đó
 * */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;
#define MAX 21
bool kiemTraTrungThuTu(int a[], int count, int key);
void xuatMang(int a[], int count);
void ghiVaXuatDanhSachLop(int a[], int &count);
void ghiMang(int a[], int count);

int main()
{
    int a[MAX], count{0};
    int b[MAX], number{0};
    // ghiVaXuatDanhSachLop(a, count);
    ghiVaXuatDanhSachLop(a, count);
    return 0;
}

bool kiemTraTrungThuTu(int a[], int count, int key)
{
    bool KT = false;
    for (int i = 0; i < count; i++)
    {
        if (a[i] == key)
            KT = true;
    }
    return KT;
}
void xuatMang(int a[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void ghiVaXuatDanhSachLop(int a[], int &count)
{
    srand(time(NULL));
    int key;
    while (true)
    {
        key = rand() % 23 + 1;
        if ((key == 14 || key == 19) == false)
            break;
    }
    a[count++] = key;
    while (count != 21)
    {
        do
        {
            while (true)
            {
                key = rand() % 23 + 1;
                if ((key == 14 || key == 19) == false)
                    break;
            }
        } while (kiemTraTrungThuTu(a, count, key));
        a[count++] = key;
    }
    cout << "So phan tu cua mang: " << count << endl;
    xuatMang(a, count);
    ghiMang(a, count);
}

void ghiMang(int a[], int count)
{
    ofstream fileout;
    fileout.open("dslop.txt", ios_base::out);
    for (int i = 0; i < count; i++)
    {
        if (i != count)
            fileout << a[i] << " ";
        else
            fileout << a[i];
    }
    fileout.close();
}

