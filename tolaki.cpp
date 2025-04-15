#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Fungsi untuk mengubah teks menjadi huruf kecil
string toLowerCase(const string& input) {
    string output = input;
    transform(output.begin(), output.end(), output.begin(), ::tolower);
    return output;
}

// Fungsi untuk menghapus tanda baca dari teks
string removePunctuation(const string& input) {
    string output;
    for (char c : input) {
        if (isalnum(c) || c == ' ') {
            output += c;
        }
    }
    return output;
}

// Fungsi untuk memisahkan kalimat menjadi kata-kata
vector<string> tokenize(const string& input) {
    vector<string> tokens;
    istringstream stream(input);
    string word;
    while (stream >> word) {
        tokens.push_back(word);
    }
    return tokens;
}

// Fungsi untuk menampilkan hasil tokenisasi
void displayTokens(const vector<string>& tokens) {
    for (const auto& token : tokens) {
        cout << token << endl;
    }
}

int main() {
    string text;

    // Mengambil input dari pengguna
    cout << "Masukkan teks untuk diproses: ";
    getline(cin, text);

    // Langkah 1: Normalisasi teks ke huruf kecil
    text = toLowerCase(text);

    // Langkah 2: Menghapus tanda baca
    text = removePunctuation(text);

    // Langkah 3: Tokenisasi kalimat menjadi kata-kata
    vector<string> tokens = tokenize(text);

    // Menampilkan hasil tokenisasi
    cout << "Tokens dari teks yang dimasukkan:" << endl;
    displayTokens(tokens);

    return 0;
}