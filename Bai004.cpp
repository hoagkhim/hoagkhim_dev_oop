#include <iostream>
using namespace std;
struct Time
{
    int hour, minute, second;
};
Time getNextTime(Time current, int h, int m, int s)
{
    current.second += s;
    if (current.second >= 60) {
        current.minute += current.second / 60;
        current.second %= 60;
    }
    current.minute += m;
    if (current.minute >= 60) {
        current.hour += current.minute / 60;
        current.minute %= 60;
    }
    current.hour = (current.hour + h) % 24;
    return current;
}
int main()
{
    Time now;
    int h, m, s;
    cout << "Nhap gio, phut, giay (hh mm ss): ";
    cin >> now.hour >> now.minute >> now.second;
    cout << "Nhap so gio, phut, giay can cong (hh mm ss): ";
    cin >> h >> m >> s;
    if (now.hour < 0 || now.hour >= 24 || now.minute < 0 || now.minute >= 60 || now.second < 0 || now.second >= 60) {
        cout << "Thoi gian khong hop le!" << endl;
        return 1;
    }
    Time newTime = getNextTime(now, h, m, s);
    cout << "Thoi gian moi la: "
         << (newTime.hour < 10 ? "0" : "") << newTime.hour << ":"
         << (newTime.minute < 10 ? "0" : "") << newTime.minute << ":"
         << (newTime.second < 10 ? "0" : "") << newTime.second << endl;
    return 0;
}
