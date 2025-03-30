#pragma once
#include <iostream>
using namespace std;
class PhanSo
{
private:
	int TuSo;
	int MauSo;
public:
	void Nhap();
	void Xuat();
	void RutGon();
	PhanSo Tong(PhanSo ps);
	PhanSo Hieu(PhanSo ps);
	PhanSo Tich(PhanSo ps);
	PhanSo Thuong(PhanSo ps);
	float DinhGiaTri();
};