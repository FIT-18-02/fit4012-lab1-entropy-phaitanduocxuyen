#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Hàm tính Entropy (H(X))
double calculate_entropy(const string &text) {
    if (text.empty()) {
        return 0.0;
    }

    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    double entropy = 0.0;
    for (const auto &pair : freq) {
        double p = static_cast<double>(pair.second) / text.size();
        entropy -= p * log2(p);
    }
    return entropy;
}

// Hàm tính độ dư thừa (Redundancy)
double calculate_redundancy(const string &text, int alphabet_size = 256) {
    if (text.empty()) {
        return 0.0;
    }

    // 1. Tính Entropy của chuỗi hiện tại
    double H_X = calculate_entropy(text);

    // 2. Tính Entropy tối đa (Log2 của kích thước bảng chữ cái)
    // Nếu bảng chữ cái có N ký tự, Entropy max xảy ra khi xác suất các ký tự bằng nhau
    double max_entropy = log2(static_cast<double>(alphabet_size));

    // 3. Công thức: Redundancy = log2(N) - H(X)
    double redundancy = max_entropy - H_X;

    return redundancy;
}

int main() {
    string input;
    cout << "Enter a string of characters: ";
    if (!getline(cin, input)) return 0;

    double entropy = calculate_entropy(input);

    // Giả sử bảng chữ cái tiêu chuẩn là 256 ký tự (ASCII)
    double redundancy = calculate_redundancy(input, 256);

    cout << "--- Results ---" << endl;
    cout << "Input length: " << input.size() << endl;
    cout << "Entropy (H(X)): " << entropy << " bits/symbol" << endl;
    cout << "Redundancy:     " << redundancy << " bits/symbol" << endl;

    return 0;
}