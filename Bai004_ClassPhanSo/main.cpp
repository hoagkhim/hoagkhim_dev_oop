#include "PhanSo.h"
using namespace std;
int main()
{
	PhanSo a, b;
	a.Nhap();
	b.Nhap();
	PhanSo Tong = a.Tong(b);
	PhanSo Hieu = a.Hieu(b);
	PhanSo Tich = a.Tich(b);
	PhanSo Thuong = a.Thuong(b);
	a.Xuat();
	b.Xuat();
	cout << "Tong la: ";
	Tong.Xuat();
	cout << "Hieu la: ";
	Hieu.Xuat();
	cout << "Tich la: ";
	Tich.Xuat();
	cout << "Thuong la: ";
	Thuong.Xuat()
	cout << "Dinh gia tri cua phan so thu nhat la: " << a.DinhGiaTri() << endl;
	cout << "Dinh gia tri cua phan so thu hai la: " << b.DinhGiaTri() << endl;
	return 0;
}