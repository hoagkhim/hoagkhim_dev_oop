#include <iostream>
using namespace std;
struct DaThuc
{
    double a, b, c;
};
DaThuc Nhap()
{
    DaThuc dt;
    cout << "Nhap he so a, b, c: ";
    cin >> dt.a >> dt.b >> dt.c;
    return dt;
}
void Xuat(DaThuc dt)
{
    if (dt.a != 0) {
        if (dt.a == 1) cout << "x^2 ";
        else if (dt.a == -1) cout << "- x^2 ";
        else cout << dt.a << "x^2 ";
    }
    if (dt.b != 0) {
        if (dt.b == 1) cout << "+ x ";
        else if (dt.b == -1) cout << " - x";
        else if (dt.b > 0) cout << "+ " << dt.b << "x ";
        else cout << dt.b << "x ";
    }
    if (dt.c != 0 || (dt.a == 0 && dt.b == 0)) {
        if (dt.c > 0 && dt.a != 0 && dt.b != 0) cout << "+ " << dt.c;
        else cout << dt.c;
    }
    cout << endl;
}
DaThuc Tong(DaThuc &dt1, DaThuc &dt2)
{
    return {dt1.a + dt2.a, dt1.b + dt2.b, dt1.c + dt2.c};
}
DaThuc Hieu(DaThuc &dt1, DaThuc &dt2)
{
    return {dt1.a - dt2.a, dt1.b - dt2.b, dt1.c - dt2.c};
}
void TichDaThuc(DaThuc dt1, DaThuc dt2, double &a, double &b, double &c, double &d, double &e)
{
    a = dt1.a * dt2.a;
    b = dt1.a * dt2.b + dt1.b * dt2.a;
    c = dt1.a * dt2.c + dt1.b * dt2.b + dt1.c * dt2.a;
    d = dt1.b * dt2.c + dt1.c * dt2.b;
    e = dt1.c * dt2.c;
    cout << "Tich hai da thuc: "<<endl;
    if (a != 0) {
        if (a == 1) cout << "x^4 ";
        else if (a == -1) cout << "- x^4 ";
        else cout << a << "x^4 ";
    }
    if (b != 0) {
        if (b == 1) cout << "+ x^3 ";
        else if (b == -1) cout << " - x^3";
        else if (b > 0) cout << "+ " << b << "x^3 ";
        else cout << b << "x^3 ";
    }
    if (c != 0) {
        if (c == 1) cout << "+ x^2 ";
        else if (c == -1) cout << " - x^2";
        else if (c > 0) cout << "+ " << c << "x ";
        else cout << c << "x^2 ";
    }
    if (d != 0) {
        if (d == 1) cout << "+ x ";
        else if (d == -1) cout << " - x";
        else if (d > 0) cout << "+ " << d << "x ";
        else cout << d << "x ";
    }
    if (e != 0 || (a == 0 && b == 0 && c == 0 && d == 0)) {
        if (e > 0 && a != 0 && b != 0 && c != 0 && d != 0) cout << "+ " << e;
        else cout << e;
    }
    cout<<endl;
}
double GiaTriF0(DaThuc &dt)
{
    return dt.c;
}
int main()
{
    DaThuc A = Nhap();
    DaThuc B = Nhap();
    cout << "Da thuc A: ";
    Xuat(A);
    cout << "Da thuc B: ";
    Xuat(B);
    DaThuc TongDT = Tong(A, B);
    DaThuc HieuDT = Hieu(A, B);
    cout << "Tong hai da thuc: "<<endl;
    Xuat(TongDT);
    cout << "Hieu hai da thuc: "<<endl;
    Xuat(HieuDT);
    double a, b, c, d, e;
    TichDaThuc(A, B, a, b, c, d, e);
    cout << "Gia tri A tai F(0): " << GiaTriF0(A) << endl;
    cout << "Gia tri B tai F(0): " << GiaTriF0(B) << endl;
    return 0;
}
