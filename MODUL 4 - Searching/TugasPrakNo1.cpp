#include <iostream>

using namespace std;

int main() {
  string kalimat;
  char huruf;
  int low, high, mid;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Input huruf yang ingin dicari
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> huruf;

  // Mencari index huruf dengan binary search
  low = 0;
  high = kalimat.length() - 1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (kalimat[mid] == huruf) {
      break;
    } else if (kalimat[mid] < huruf) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  // Menampilkan hasil pencarian
  if (low <= high) {
    cout << "Huruf '" << huruf << "' ditemukan pada index " << mid << endl;
  } else {
    cout << "Huruf '" << huruf << "' tidak ditemukan pada kalimat" << endl;
  }

  return 0;
}
