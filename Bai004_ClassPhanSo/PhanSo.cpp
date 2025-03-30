#include "PhanSo.h"
#include <iostream>
using namespace std;
void PhanSo::Nhap()
{
	cout << "Nhap vao tu so va mau so" << endl;
	cin >> TuSo >> MauSo;
}
int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}
void PhanSo::RutGon()
{
	int UCLN = GCD(TuSo, MauSo);
	TuSo /= UCLN;
	MauSo /= UCLN;
	if (MauSo < 0)
	{
		TuSo = -TuSo;
		MauSo = -MauSo;
	}
}
void PhanSo::Xuat()
{
	if (TuSo == 0)
		cout << 0 << endl;
	else if (MauSo == 1)
		cout << TuSo << endl;
	cout << TuSo << "/" << MauSo << endl;
}
PhanSo PhanSo::Tong(PhanSo ps)
{
	PhanSo Tong;
	Tong.TuSo = TuSo * ps.MauSo + ps.TuSo * MauSo;
	Tong.MauSo = MauSo * ps.MauSo;
	Tong.RutGon();
	return Tong;
}
PhanSo PhanSo::Hieu(PhanSo ps)
{
	PhanSo Hieu;
	Hieu.TuSo = TuSo * ps.MauSo - ps.TuSo * MauSo;
	Hieu.MauSo = MauSo * ps.MauSo;
	Hieu.RutGon();
	return Hieu;
}
PhanSo PhanSo::Tich(PhanSo ps)
{
	PhanSo Tich;
	Tich.TuSo = TuSo * ps.TuSo;
	Tich.MauSo = MauSo * ps.MauSo;
	Tich.RutGon();
	return Tich;
}
PhanSo PhanSo::Thuong(PhanSo ps)
{
	PhanSo Thuong;
	Thuong.TuSo = TuSo * ps.MauSo;
	Thuong.MauSo = MauSo * ps.TuSo;
	Thuong.RutGon();
	return Thuong;
}
float PhanSo::DinhGiaTri()
{
	float GiaTri;
	GiaTri = float(TuSo) / MauSo;
	return GiaTri;
}