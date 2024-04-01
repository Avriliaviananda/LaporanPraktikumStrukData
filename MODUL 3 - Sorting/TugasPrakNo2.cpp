#include <iostream>

using namespace std;

int main() {
  string nama[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
  int n = sizeof(nama) / sizeof(nama[0]);

  // Mengurutkan nama dengan Bubble Sort
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (nama[j] > nama[j + 1]) {
        string tmp = nama[j];
        nama[j] = nama[j + 1];
        nama[j + 1] = tmp;
      }
    }
  }

  // Menampilkan hasil
  cout << "Daftar nama warga : " << endl;
  for (int i = 0; i < n; i++) {
    cout << nama[i] << " ";
  }
  cout << endl;

  return 0;
}