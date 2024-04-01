#include <iostream>

using namespace std;

int main() {
  // Deklarasi array
  float ips_mhs[] = {3.8, 2.9, 3.3, 4.0, 2.4};
  
  // Menghitung jumlah elemen dalam array
  int n = sizeof(ips_mhs) / sizeof(ips_mhs[0]);

  // Melakukan Selection Sort
  for (int i = 0; i < n - 1; i++) {
    // Mencari indeks elemen minimum dari elemen i hingga akhir array
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (ips_mhs[min_index] < ips_mhs[j]) {
        min_index = j;
      }
    }

    // Menukar elemen minimum dengan elemen di awal
    float tmp = ips_mhs[i];
    ips_mhs[i] = ips_mhs[min_index];
    ips_mhs[min_index] = tmp;
  }

  // Mencetak daftar IPS yang sudah diurutkan
  cout << "Urutan mahasiswa IPS yang benar:" << endl;
  for (int i = 0; i < n; i++) {
    cout << ips_mhs[i] << " ";
  }

  cout << endl;

  return 0;
}
