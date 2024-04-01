#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int n;
  char karakter[100];

  // Membaca nilai n
  cout << "Masukkan jumlah karakter : ";
  cin >> n;

  // Membaca karakter
  cout << "Masukkan karakter: ";
  cin.ignore();
  for (int i = 0; i < n; i++) {
    cin >> karakter[i];
  }

  // Sorting ascending
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (karakter[i] > karakter[j]) {
        char tmp = karakter[i];
        karakter[i] = karakter[j];
        karakter[j] = tmp;
      }
    }
  }

  // Menampilkan hasil sorting ascending
  cout << "Karakter (Ascending): ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }
  cout << endl;

  // Sorting descending
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (karakter[i] < karakter[j]) {
        char tmp = karakter[i];
        karakter[i] = karakter[j];
        karakter[j] = tmp;
      }
    }
  }

  // Menampilkan hasil sorting descending
  cout << "Karakter (Descending): ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }
  cout << endl;

  return 0;
}