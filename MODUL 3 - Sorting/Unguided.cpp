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