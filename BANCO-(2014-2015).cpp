#include <bits/stdc++.h>
using namespace std;
class QuanCo {
protected:
    string mau;
    int x, y;
public:
    QuanCo(string mau, int x, int y) {
        this->mau = mau;
        this->x = x;
        this->y = y;
    }
    virtual void DiChuyen() = 0;
    virtual ~QuanCo() {}
};
class TuongVua : public QuanCo {
public:
    TuongVua(string mau, int x, int y) : QuanCo(mau, x, y) {}
    void DiChuyen() {
        cout << "Di tung o mot, di ngang hoac doc. Tuong luon luon phai o trong pham vi cung va khong duoc ra ngoai. Cung tuc la hinh vuong 2X2 duoc danh dau bang duong cheo hinh chu X." << endl;
    }
};
class Si : public QuanCo {
public:
    Si(string mau, int x, int y) : QuanCo(mau, x, y) {}
    void DiChuyen() {
        cout << "Di cheo 1 o moi nuoc. Si luon luon phai o trong cung." << endl;
    }
};
class Tuong : public QuanCo {
public:
    Tuong(string mau, int x, int y) : QuanCo(mau, x, y) {}
    void DiChuyen() {
        cout << "Di cheo 2 o (ngang 2 va doc 2) cho moi buoc di. Tuong chi duoc phep di mot ben cua ban co khong duoc di chuyen sang nua ban co doi phuong. Nuoc di cua tuong se khong hop le khi co mot quan nam giua duong di." << endl;
    }
};
class Ma : public QuanCo {
public:
    Ma(string mau, int x, int y) : QuanCo(mau, x, y) {}
    void DiChuyen() {
        cout << "Di ngang 2 o va doc 1 (hay doc 2 o va ngang 1) cho moi nuoc di. Neu co quan nam ngay ben canh ma va can duong ngang 2 (hay duong doc 2), ma bi can khong duoc di duong do." << endl;
    }
};
class Xe : public QuanCo {
public:
    Xe(string mau, int x, int y) : QuanCo(mau, x, y) {}
    void DiChuyen() {
        cout << "Di ngang hay doc tren ban co mien la dung bi quan khac can duong tu diem di den diem den." << endl;
    }
};
class Phao : public QuanCo {
public:
    Phao(string mau, int x, int y) : QuanCo(mau, x, y) {}
    void DiChuyen() {
        cout << "Di ngang va di doc giong nhu xe diem khac biet la neu phao muon an quan phao phai nhay qua dung 1 quan nao do khi khong an quan tat ca nhung diem tu cho di den cho den phai khong co quan can." << endl;
    }
};
class Tot : public QuanCo {
public:
    Tot(string mau, int x, int y) : QuanCo(mau, x, y) {}
    void DiChuyen() {
        cout << "Di mot o moi nuoc neu tot chua vuot qua song no chi co the di thang tien khi da vuot song roi tot co the di ngang 1 nuoc hay di thang tien 1 buoc moi nuoc." << endl;
    }
};
int main()
{
    QuanCo *a[32];
    string trang = "trang";
    string den = "den";
    cout << "Tao ban co " << endl;
    a [0] = new TuongVua (trang, 1, 5);
    a [1] = new TuongVua (den, 10, 5);
    a [2] = new Si (trang, 1, 4);
    a [3] = new Si (trang, 1, 6);
    a [4] = new Si (den, 10, 4);
    a [5] = new Si (den, 10, 6);
    a [6] = new Ma (trang, 1, 2);
    a [7] = new Ma (trang, 1, 8);
    a [8] = new Ma (den, 10, 2);
    a [9] = new Ma (den, 10, 8);
    a [10] = new Xe (trang, 1, 1);
    a [11] = new Xe (trang, 1, 9);
    a [12] = new Xe (den, 10, 1);
    a [13] = new Xe (den, 10, 9);
    a [14] = new Phao (trang, 3, 2);
    a [15] = new Phao (trang, 3, 8);
    a [16] = new Phao (den, 8, 2);
    a [17] = new Phao (den, 8, 8);
    a [18] = new Tot (trang, 4, 1);
    a [19] = new Tot (trang, 4, 3);
    a [20] = new Tot (trang, 4, 5);
    a [21] = new Tot (trang, 4, 7);
    a [22] = new Tot (trang, 4, 9);
    a [23] = new Tot (den, 7, 1);
    a [24] = new Tot (den, 7, 3);
    a [25] = new Tot (den, 7, 5);
    a [26] = new Tot (den, 7, 7);
    a [27] = new Tot (den, 7, 9);
    a [28] = new Tuong (trang,1, 3);
    a [29] = new Tuong (trang, 1, 7);
    a [30] = new Tuong (den, 10, 3);
    a [31] = new Tuong (den, 10, 7);
    cout << "Nhap quan co muon di chuyen tu 0 -> 31 " << endl;
    int co;
    cin >> co;
    a[co]->DiChuyen();
    return 0;
}
