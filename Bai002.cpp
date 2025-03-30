#include <iostream>
using namespace std;

// 1. Định nghĩa cấu trúc Date
struct Date {
	int day;
	int month;
	int year;
};

// 2. Kiểm tra năm nhuận
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 3. Hàm trả về số ngày trong một tháng
int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

// 4. Hàm trả về ngày tiếp theo
Date getNextDay(Date current, int x) {
    while (x > 0)
    {
        int daysleft = daysInMonth(current.month, current.year) - current.day;
        if (x > daysleft)
        {
            x -= (daysleft + 1);
            current.day = 1;
            current.month++;
            if (current.month > 12)
            {
                current.month = 1;
                current.year++;
            }
        }
            else
            {
                current.day += x;
                x = 0;
            }
    }
    return current;
}

int main() {
    Date today;
    int x;
    cout << "Nhap ngay (dd mm yyyy): "<<endl;
    cin >> today.day >> today.month >> today.year;
    cout << "Nhap vao so ngay muon biet: "<<endl;
    cin >> x;
    if (today.month < 1 || today.month > 12 || today.day < 1 || today.day > daysInMonth(today.month, today.year)) {
        cout << "Ngay khong hop le" << endl;
        return 1;
    }

    Date nextDay = getNextDay(today, x);

    cout << "Ngay thu "<<x<<" ke tiep la: " << nextDay.day << "/" << nextDay.month << "/" << nextDay.year << endl;

    return 0;
}
