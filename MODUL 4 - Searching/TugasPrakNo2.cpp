#include <iostream>

using namespace std;

int main() {
  string kalimat;
  int jumlahVocal = 0;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Menghitung banyaknya huruf vocal
  for (char c : kalimat) {
    switch (c) {
      case 'a':
      case 'i':
      case 'u':
      case 'e':
      case 'o':
        jumlahVocal++;
        break;
    }
  }

  // Menampilkan hasil
  cout << "Jumlah huruf vocal dalam kalimat: " << jumlahVocal << endl;

  return 0;
}
