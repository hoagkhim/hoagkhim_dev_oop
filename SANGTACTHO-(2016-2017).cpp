#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class BaiTho {
protected:
    int SoCau;
    string Cau[100][100];
public:
    BaiTho();
    ~BaiTho();
    int GetSoCau();
    void SangTac();
    virtual bool KiemTra() = 0;
};
BaiTho::BaiTho()
{
    SoCau = 0;
}
BaiTho::~BaiTho()
{
    return;
}
bool ktgieovan(string s1, string s2)
{
    return true;
}
int BaiTho::GetSoCau()
{
    return SoCau;
}
void BaiTho::SangTac()
{
    cout << "Nhap vao so cau: " << endl;
    cin >> SoCau;
    cin.ignore();
    int i = 1;
    cout << "Nhap vao bai tho: " << endl;
    while (i <= SoCau)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        int j = 1;
        while (ss >> word)
        {
            Cau[i][j] = word;
            j++;
        }
        i++;
    }
}
class LucBat : public BaiTho {
public:
    bool KiemTra();
};
bool LucBat::KiemTra()
{
    if (SoCau % 2 != 0)
        return false;
    for (int i = 1; i <= SoCau; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= 100; j++)
        {
            if (Cau[i][j] == "")
                break;
            cnt++;
        }
        if (i % 2 != 0)
        {
            if (cnt != 6)
                return false;
            if (i + 1 <= SoCau)
            {
                if (!ktgieovan(Cau[i][6], Cau[i + 1][6]))
                    return false;
            }
        }
        else
        {
            if (cnt != 8)
                return false;
            if (i + 1 <= SoCau)
            {
                if (!ktgieovan(Cau[i][8], Cau[i + 1][6]))
                    return false;
            }
        }
    }
    return true;
}
class SongThatLucBat : public BaiTho {
public:
    bool KiemTra();
};
bool SongThatLucBat::KiemTra()
{
    if (SoCau % 4 != 0)
        return false;
    int i = 1;
    while (i <= SoCau - 3)
    {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (int j = 1; j <= 100 && !Cau[i][j].empty(); j++) cnt1++;
        for (int j = 1; j <= 100 && !Cau[i + 1][j].empty(); j++) cnt2++;
        for (int j = 1; j <= 100 && !Cau[i + 2][j].empty(); j++) cnt3++;
        for (int j = 1; j <= 100 && !Cau[i + 3][j].empty(); j++) cnt4++;
        if (cnt1 != 7 || cnt2 != 7 || cnt3 != 6 || cnt4 != 8)
            return false;
        if (!ktgieovan(Cau[i][7], Cau[i + 1][5]))
            return false;
        if (!ktgieovan(Cau[i + 1][7], Cau[i + 2][6]))
            return false;
        if (!ktgieovan(Cau[i + 2][6], Cau[i + 3][6]))
            return false;
        i += 4;
    }
    return true;
}
class DuongLuatThatNgonBatCu : public BaiTho {
public:
    bool KiemTra();
};
bool DuongLuatThatNgonBatCu::KiemTra()
{
    if (SoCau != 8)
        return false;
    for (int i = 1; i <= SoCau; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= 100; j++)
        {
            if (Cau[i][j] == "")
                break;
            cnt++;
        }
        if (cnt != 7)
            return false;
    }
    if (!ktgieovan(Cau[1][7], Cau[2][7]))
        return false;
    if (!ktgieovan(Cau[2][7], Cau[4][7]))
        return false;
    if (!ktgieovan(Cau[4][7], Cau[6][7]))
        return false;
    if (!ktgieovan(Cau[6][7], Cau[8][7]))
        return false;
    return true;
}
int main()
{
    int SoBaiTho;
    cout << "Nhap vao so bai tho: " << endl;
    cin >> SoBaiTho;
    BaiTho* dsBaiTho[100];
    for (int i = 1; i <= SoBaiTho; i++)
    {
        int Loai;
        cout << "1. Luc Bat, 2. Song That Luc Bat, 3. Duong Luat That Ngon Bat Cu. " << endl;
        cout << "Chon loai muon nhap: " << endl;
        cin >> Loai;
        switch (Loai)
        {
        case 1:
            dsBaiTho[i] = new LucBat();
            break;
        case 2:
            dsBaiTho[i] = new SongThatLucBat();
            break;
        case 3:
            dsBaiTho[i] = new DuongLuatThatNgonBatCu();
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            i--;
            continue;
        }
        dsBaiTho[i]->SangTac();
    }
    int Max = 0;
    for (int i = 1; i <= SoBaiTho; i++)
    {
        Max = max(Max, dsBaiTho[i]->GetSoCau());
    }
    cout << "Cac bai tho co so cau nhieu nhat (" << Max << ") la: ";
    for (int i = 1; i <= SoBaiTho; i++)
    {
        if (dsBaiTho[i]->GetSoCau() == Max)
            cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i <= SoBaiTho; i++)
    {
        if (dsBaiTho[i]->KiemTra())
            cout << "Bai tho thu " << i << " thoa cach gieo van!" << endl;
        else cout << "Bai tho thu " << i << " khong thoa cach gieo van!" << endl;
    }
    return 0;
}

