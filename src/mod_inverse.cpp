#include <iostream>

using namespace std;

// Hàm tính GCD cơ bản
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm Euclid mở rộng tìm x, y sao cho ax + by = gcd(a, b)
int extended_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1 = 0, y1 = 0;
    int g = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Hàm tìm nghịch đảo Modulo
int mod_inverse(int a, int m) {
    int x = 0, y = 0;
    int g = extended_euclid(a, m, x, y);

    int result;
    if (g != 1) {
        result = -1; // Không tồn tại nghịch đảo
    } else {
        // Đưa x về số dư dương trong khoảng [0, m-1]
        result = (x % m + m) % m;
    }

    return result;
}

int main() {
    int a = 0, m = 0;
    cout << "Nhap a va m: ";
    if (!(cin >> a >> m)) return 0;

    // Kiểm tra điều kiện tồn tại trước khi gọi hàm
    if (gcd(a, m) != 1) {
        cout << "Khong ton tai nghich dao modulo vi gcd(a, m) != 1.\n";
    } else {
        int inv = mod_inverse(a, m);
        cout << "Nghich dao cua " << a << " mod " << m << " la: " << inv << '\n';
        cout << "Kiem tra: (" << a << " * " << inv << ") % " << m
             << " = " << (1LL * a * inv % m) << '\n';
    }

    return 0;
}