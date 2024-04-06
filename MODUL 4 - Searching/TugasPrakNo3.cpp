#include <iostream>

using namespace std;

int main() {
  int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int n = sizeof(data) / sizeof(data[0]);
  int jumlahAngka4 = 0;

  // Mencari jumlah angka 4
  for (int i = 0; i < n; i++) {
    if (data[i] == 4) {
      jumlahAngka4++;
    }
  }

  // Menampilkan hasil
  cout << "Jumlah angka 4 dalam data: " << jumlahAngka4 << endl;

  return 0;
}
