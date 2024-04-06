#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mengecek apakah sebuah karakter adalah huruf vokal
bool isVowel(char ch) {
    ch = tolower(ch); // Konversi huruf menjadi huruf kecil untuk memudahkan pengecekan
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Fungsi untuk menghitung banyaknya huruf vokal dalam sebuah kalimat
int countVowels(const string& sentence) {
    int count = 0;
    for (char ch : sentence) {
        if (isVowel(ch)) {
            count++;
        }
    }
    return count;
}

int main() {
   string kalimat;

   cout << "Masukkan kalimat: ";
   getline(cin, kalimat);

    // Menghitung banyaknya huruf vokal dalam kalimat
    int jumlahVokal = countVowels(kalimat);

   cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahVokal <<endl;

    return 0;
}