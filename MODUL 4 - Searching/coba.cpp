# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

searching

Searching (pencarian) pada struktur data mengacu pada proses 
algoritmik untuk memeriksa, menemukan, mengambil posisi elemen tertentu (target) dari kumpulan elemen di dalam struktur data. Kumpulan elemen dapat berupa array, list, linked list, tree, dan lain sebagainya. Berdasarkan jenis operasinya, dua algoritma pencarian yang dibahas pada subbab ini yaitu Sequential Search dan Binary Search pada data array.

1. Sequential Search

Sequential Search (pencarian berurutan) dikenal juga sebagai 
pencarian linier. Sequential Search merupakan algoritma pencarian paling dasar dan paling sederhana yang bekerja menggunakan pendekatan brute force, mencoba segala kemungkinan yang ada hingga target yang diinginkan ditemukan. Sebagai contoh, mencari nilai 36 dari data array {12, 
7, 30, 28, 2, 19, 36, 21, 16, 9}. Sequential Search dimulai dengan membandingkan/mencocokkan 36 dengan elemen pertama/index[0] yaitu 12, karena 12 tidak sesuai dengan kriteria pencarian (12 != 36) maka dilanjutkan dengan membandingkan 36 dengan elemen berikutnya hingga ditemukan elemen yang cocok, yaitu pada index[6] dimana 36 == 36. 

![Screenshot 2024-04-06 131806](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/9ce25adb-d968-4ed6-aeb3-a867bf50d770)

Sequential Search dideskripsikan pada class Sequential Search (baris 6) sedangkan proses pencarian data dilakukan didalam method search (baris 7). Method search menerima kunci pencarian dari pengguna (baris 12) kemudian menggunakan perulangan (baris 13) untuk membandingkan kunci pencarian dengan semua elemen pada array (baris 15). Program berhenti ketika elemen telah ditemukan (baris 16) atau ketika semua 
elemen telah selesai dibandingkan (baris 20). Output program dapat dilihat pada Gambar, pada output dijabarkan tahapan proses pencarian dan hasil pencarian apabila elemen ditemukan dan tidak ditemukan.

2. Binary Search

Pencarian bagidua (binary search) adalah proses 
pencarian dengan membagi dua bagian data kemudian 
membandingkan isi data bagian pertama atau bagian kedua 
dengan data yang akan dicari. Pada metode ini membutuhkan 
nilai indeks terkecil dan terbesar untuk dijumlahkan kemudian 
dibagi dua. Pencarian bagi dua (binary search) hanya bisa 
dilakukan pada data yang sudah urut. Metode ini lebih efisien 
dibandingkan dengan metode pencarian sequential search atau 
pencarian beruntun. Pencarian Biner sebagai algoritma pencarian yang digunakan dalam array yang diurutkan dengan berulang kali membagi interval pencarian menjadi dua. Ide pencarian biner adalah menggunakan informasi bahwa array diurutkan dan mengurangi kompleksitas waktu ke O (log N).

![Screenshot 2024-04-06 132307](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/ea20f49d-d8ec-4fb7-b5af-25b4e948c053)


## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```cpp
#include <iostream>
using namespace std;
int main(){
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    //algoritma sequential search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    cout << "\t program sequential seacrh sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-04-06 132847](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/05220940-f3f4-4bf5-9619-4160ed40ccb4)



#### Full code Screenshot:
![Screenshot (289)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/54c5f75f-00e9-4521-95ca-24008fee9604)


program diatas unutk mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort. dan dihasilkan urutan sebelum dan setelah sorting secara ascending(dari yang terkecil ke yang terbesar). Kompleksitas waktu pada code di atas adalah O(n^2), dimana n adalah jumlah elemen dalam array a. Hal ini disebabkan karena penggunaan algoritma Bubble Sort, yang membutuhkan waktu yang lama dengan jumlah elemen dalam array. Dalam hal ini, waktu yang dibutuhkan untuk menyortir bilangan akan meningkat dengan kubiknya jumlah bilangan.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```cpp
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int Data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (Data[j] < Data[min]) {
                min = j;
            }
        }
        temp = Data[i];
        Data[i] = Data[min];
        Data[min] = temp;
    }
}

void binarysearch() {
    // searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (Data[tengah] == cari) {
            b_flag = 1;
            break;
        }
        else if (Data[tengah] < cari) {
            awal = tengah + 1;
        }
        else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    }
    else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main () {
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";

    //tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";

    // urutkan data dengan selection sort
    selection_sort();

    // tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    binarysearch();

    _getche();
    return EXIT_SUCCESS;
}
```
#### Output:
![Screenshot 2024-04-06 132933](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/ffd7228d-b9c2-4b42-aa3f-f0fe563cfd08)


#### Full code Screenshot:
![Screenshot (290)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/5fa25f46-63ca-479a-b9ba-8ad3557a74aa)

program diatas untuk mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort. dan dihasilkan urutan karakter sesuai dengan dari yang terbesar ke yang terkecil. Kompleksitas waktu pada code di atas adalah O(n^2), dimana n adalah jumlah elemen dalam array a. Hal ini disebabkan karena penggunaan algoritma Insertion Sort, yang membutuhkan waktu yang lama dengan jumlah elemen dalam array. Dalam hal ini, waktu yang dibutuhkan untuk menyortir karakter akan meningkat dengan kubiknya jumlah karakter.

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!


```cpp
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

```
#### Output:
![Screenshot 2024-03-30 123900](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/ec94de51-9190-45b9-9ba4-fb77dcdde1cd)

#### Full code Screenshot:
![Screenshot (269)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/b428c07e-d21b-43a1-822f-c619e579b648)

Program diatas merupakan program untuk mengurutkan IPS mahasiswa dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort. dan dihasilkan array ips_mhs berisi nilai IPK mahasiswa menggunakan algoritma Selection Sort. Algoritma ini memiliki kompleksitas waktu O(n^2). Hal ini dikarenakan Selection Sort mengulangi seluruh array ips_mhs n - 1 kali. Dalam setiap iterasi, ia menghitung indeks elemen minimum dari elemen i hingga akhir array. Dalam setiap iterasi, Selection Sort melakukan n - i - 1 menukar. Jumlah pertukaran yang dibutuhkan adalah n - 1, karena elemen terakhir tidak perlu diubah. Jumlah pertukaran yang dibutuhkan adalah O(n - 1), yang menjadi O(n) dalam kasus paling buruk. Karena Selection Sort membutuhkan waktu yang lama dengan jumlah pertukaran, kompleksitas waktu pada code di atas adalah O(n^2).

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```cpp
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
```
#### Output:
![Screenshot 2024-03-30 124001](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/cbb05460-b5e0-4e4a-97af-2357d7b9363d)


#### Full code Screenshot:
![Screenshot (270)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/a64bf305-c695-4de6-a9b5-c72089b82946)


Program ini akan melakukan sorting secara menaik (ascending) dan menurun (descending) menggunakan algoritma Bubble Sort. Algoritma ini berfungsi dengan cara menyusun elemen dalam array dari yang terkecil ke yang terbesar. Setelah proses sorting selesai, program akan menampilkan hasil sorting nama warga RT Pak RT. Kompleksitas waktu dari program ini adalah O(n^2), karena, Bubble Sort mengulangi seluruh array nama n - 1 kali. Dalam setiap iterasi, ia membandingkan setiap elemen dengan elemen berikutnya dan melakukan pertukaran jika elemen lebih besar. Dalam setiap iterasi, Bubble Sort melakukan n - i - 1 menukar. Jumlah pertukaran yang dibutuhkan adalah n - 1, karena elemen terakhir tidak perlu diubah. Jumlah pertukaran yang dibutuhkan adalah O(n - 1), yang menjadi O(n) dalam kasus paling buruk. Karena Bubble Sort membutuhkan waktu yang lama dengan jumlah pertukaran, kompleksitas waktu pada code di atas adalah O(n^2).

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```cpp
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
  cout << "Urutan karakter setelah ascending sort: ";
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
  cout << "Urutan karakter setelah descending sort: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }
  cout << endl;

  return 0;
}
```
#### Output:
![Screenshot 2024-04-01 112531](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/2ed4aca9-c281-4b46-8ba6-e66c8f0f0c67)



#### Full code Screenshot:
![Screenshot (281)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/5da27b51-2437-40cd-a5f6-347a292b3ac4)



Program ini menginputkan jumlah karakter dan karakter tersebut dari user, lalu melakukan sorting secara menaik (ascending) dan menurun (descending) menggunakan algoritma sorting yang sederhana. Kompleksitas waktu dari program ini adalah O(n^2), karena Bubble Sort mengulangi seluruh array karakter n - 1 kali. Dalam setiap iterasi, ia membandingkan setiap elemen dengan elemen berikutnya dan melakukan pertukaran jika elemen lebih besar. Dalam setiap iterasi, Bubble Sort melakukan n - i - 1 menukar. Jumlah pertukaran yang dibutuhkan adalah n - 1, karena elemen terakhir tidak perlu diubah. Jumlah pertukaran yang dibutuhkan adalah O(n - 1), yang menjadi O(n) dalam kasus paling buruk. Karena Bubble Sort membutuhkan waktu yang lama dengan jumlah pertukaran, kompleksitas waktu pada code di atas adalah O(n^2).

## Kesimpulan
Kesimpulan dari sorting adalah proses mengurutkan data, baik dari yang kecil ke yang besar (ascending) maupun dari yang besar ke yang kecil (descending). ada beberapa macam dari sorting yaitu insertion sort, bubble sort, selection sort. meskipun insertion sort, bubble sort, dan selection sort adalah algoritma sorting yang relatif sederhana, memahami dan menguasai konsep-konsep dasar dalam ketiganya penting. 

## Referensi
[1] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[2] Meidyan Permata Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung : Widina Bhakti Persada Bandung, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.
