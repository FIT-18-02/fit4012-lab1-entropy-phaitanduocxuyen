#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

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

double calculate_redundancy(const string &text, int alphabet_size = 256) {
    if (text.empty()) {
        return 0.0;
    }

    double H_X = calculate_entropy(text);
    double max_entropy = log2(static_cast<double>(alphabet_size));

    // Tính toán độ dư thừa thực tế dựa trên công thức R = log2(N) - H(X)
    double redundancy = max_entropy - H_X;

    return redundancy;
}

int main() {
    string input;
    cout << "Enter a string of characters: ";
    if (!getline(cin, input)) return 0;

    double entropy = calculate_entropy(input);
    double redundancy = calculate_redundancy(input, 256);

    cout << "Entropy: " << entropy << '\n';
    cout << "Redundancy: " << redundancy << '\n';
    return 0;
}