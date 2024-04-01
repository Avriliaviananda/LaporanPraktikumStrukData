# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori
konsep dasar sorting

Sorting adalah salah satu teknik yang penting dalam algoritma. Sorting adalah proses mengurutkan data, baik dari yang kecil ke yang besar (ascending) maupun dari yang besar ke yang kecil (descending). [1]
Ada dua jenis pengurutan :
a. Ascending (besar)
b. Descending (kecil)

contoh: 
![Screenshot 2024-03-30 095753](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/c4119158-29ec-4e76-83c7-ed9c03ad2328)


1. insertion sort

Insertion Sort merupakan algoritma yang efisien untuk mengurutkan angka yang mempunyai jumlah elemen sedikit. Dimana Input : deretan angka sejumlah n buah dan Output ialah permutasi (pengurutan) sejumlah n angka dari input yang sudah terurut secara ascending maupun descending. Metode penyisipan (Insertion sort) bertujuan untuk menjadikan bagian sisi kiri array terurutkan sampai dengan seluruh array berhasil diurutkan. [1]

2. bubble sort

Bubble Sort merupakan algoritma sorting sederhana yang bekerja dengan cara bergerak berulang dari awal hingga akhir data untuk membandingkan semua elemen yang saling bersebelahan. Selama melakukan perbandingan jika ditemukan urutan elemen data yang tidak sesuai berdasarkan kondisi tertentu maka tukar ke dua posisi elemen data tersebut. [2]

3. selection sort 

Selection Sort termasuk algoritma sorting sederhana yang bekerja dengan cara membandingkan semua elemen data untuk mencari nilai terkecil/terbesar disetiap perulangan, kemudian menempatkan nilai terkecil/terbesar diposisi yang tepat hingga semua elemen terurut. [2]

langkah pertama dicari data terkecil dari data pertama sampai data terakhir. Kemudian data terkecil ditukar dengan data pertama. Dengan demikian, data pertama sekarang mempunyai nilai paling kecil dibanding data yang lain. Langkah kedua, data terkecil. [3]


## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```cpp
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0; 
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[1] > arr[i + 1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }// end of for loop
    }// end of while loop
}// end of bubble_sort

void print_array(double a[], int length) {

    for(int i = 0; i < length; i++) {
        cout << a [i] << "\t";
    }
    cout << endl;
}

int main(){

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);

}
```
#### Output:
![Screenshot 2024-03-30 104608](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/a1b8a432-5eff-4304-bd54-e62440434e83)


#### Full code Screenshot:
![Screenshot (267)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/da9ffdc6-432f-4125-9da9-6a96417e575d)

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort
```cpp
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }// end of while loop
    }// end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main () {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);

 
}
```
#### Output:
![Screenshot 2024-03-30 104730](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/6789169f-16b6-416e-a655-144afa3fe776)

#### Full code Screenshot:
![Screenshot (268)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/47c868b6-9929-44d8-83be-1347afa480ee)

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! 

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

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

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

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

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
```
#### Output:
![Screenshot 2024-03-30 124128](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/9d9188e0-1db5-4001-a9f1-7fc103bf7fd8)


#### Full code Screenshot:
![Screenshot (271)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/4da575f2-3ae1-4898-a14c-671112e880ca)

Program ini menginputkan jumlah karakter dan karakter tersebut dari user, lalu melakukan sorting secara menaik (ascending) dan menurun (descending) menggunakan algoritma sorting yang sederhana. Kompleksitas waktu dari program ini adalah O(n^2), karena Bubble Sort mengulangi seluruh array karakter n - 1 kali. Dalam setiap iterasi, ia membandingkan setiap elemen dengan elemen berikutnya dan melakukan pertukaran jika elemen lebih besar. Dalam setiap iterasi, Bubble Sort melakukan n - i - 1 menukar. Jumlah pertukaran yang dibutuhkan adalah n - 1, karena elemen terakhir tidak perlu diubah. Jumlah pertukaran yang dibutuhkan adalah O(n - 1), yang menjadi O(n) dalam kasus paling buruk. Karena Bubble Sort membutuhkan waktu yang lama dengan jumlah pertukaran, kompleksitas waktu pada code di atas adalah O(n^2).

## Kesimpulan
Kesimpulan dari sorting adalah proses mengurutkan data, baik dari yang kecil ke yang besar (ascending) maupun dari yang besar ke yang kecil (descending). ada beberapa macam dari sorting yaitu insertion sort, bubble sort, selection sort. meskipun insertion sort, bubble sort, dan selection sort adalah algoritma sorting yang relatif sederhana, memahami dan menguasai konsep-konsep dasar dalam ketiganya penting. 

## Referensi
[1] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[2] Meidyan Permata Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung : Widina Bhakti Persada Bandung, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.
