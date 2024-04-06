#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mencari huruf dalam string menggunakan binary search
bool binarySearch(const string& str, char target) {
    int left = 0;
    int right = str.length() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (str[mid] == target)
            return true;
        else if (str[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    string kalimat;
    char target;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Mengubah kalimat menjadi huruf kecil untuk memudahkan pencarian
    for (char &ch : kalimat) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 'a' - 'A';
        }
    }

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;
    cin.ignore();

    // Mencari huruf menggunakan binary search
    bool ditemukan = binarySearch(kalimat, target);

    if (ditemukan)
        cout << "Huruf '" << target << "' ditemukan dalam kalimat." << endl;
    else
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;

    return 0;
}