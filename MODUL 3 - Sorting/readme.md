# <h1 align="center">Laporan Praktikum Modul  Array</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori
Array adalah objek yang menyimpan beberapa variabel dengan tipe yang sama (homogen) bertipe yang sama yang disimpan di lokasi memori yang berdekatan Untuk menemukan nilai nilai tersebut. Misalnya jika sebuah array bertipe “int", array hanya dapat menyimpan elemen integer dan tidak dapat elemen bertipe lain seperti double, float, char, dll. Namun, array itu sendiri adalah objek pada heap. Dan, jenis elemen yang dapat disimpan dalam bentuk array ditentukan oleh bahasa pemrograman. [3]

Array adalah salah satu tipe data terstruktur yang digunakan dalam Bahasa pemrograman. Penggunaan array dapat mempermudah penyimpan data karena array berisi komponen-komponen yang memiliki tipe data yang sama. Setiap anggota array dapat diakses melalui suatu indeks. Array mempunyai beberapa jenis seperti array 1 dimensi, array 2 dimensi dan array multidimensi, dimana masing-masing array tersebut memiliki fungsi yang berbeda dalam penggunaannya. Array 1 dimensi disebut dengan vektor, array 2 dimensi sering disebut sebagai matriks sedangkan array yang memiliki dimensi lebih dari 2(dua) yang disebut tensor. [2]

Struktur data array, yang menyimpan koleksi sekuensial berukuran tetap dari jenis yang sama. Sebuah array digunakan untuk menyimpan koleksi data, namun seringkali lebih berguna untuk memikirkan sebuah array sebagai kumpulan variabel dengan tipe yang sama. [3]

Array merupakan suatu variabel yang khas dan memiliki kemampuan dalam memberi tempat yang dapat memberi tampungan nilai lebih dari satudalam waktu bersamaan, apabila mempunya list item misalnya nama list sepeda motor, penyimpanan variabel biasa akan terdeklasi sebagai berikut: [1]

Sepedamotor1=”Ninja”
Sepedamotor1=”Mio” [1]


Karakteristik Array :
1. Mempunyai batasan dari pemesanan alokasi memory ( bersifat statis)
2. Mempunyai type data sama ( bersifat Homogen)
3. Dapat diakses secara acak.
4. Berurutan ( terstruktur ) [1]

berikut ini ada beberapa jenis array:

1. Array Satu Dimensi

Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan [2]
Deklarasi : Type_Data Nama_Variabel [index] 
Misalnya : int A[5]; 

2. Array Dua Dimensi

Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. [2]

Deklarasi : Type_Data Nama_Variabel [Index1] [index2]; 

Misal : int A[3][2];

3. Array Tiga Dimensi/ multidimensi

Array tiga dimensi digunakan untuk mengelola data dalam bentuk 3 dimensi atau tiga sisi. array tiga dimensi ini bisa disebut dengan array multidimensi karena lebih dari dua. array multidimensi adalah array yang nemiliki dimensi banyak dan biasanya lebih dari dua [2]

Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3]; 

Misal : int A [3][4][2];

## Guided 

### 1. Array Tiga Dimensi

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
![240302_00h00m06s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/61ec161a-ab6c-4ec1-8ca8-db61b16f826e)

![240302_00h00m06s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/84ec165b-ac3d-4f67-a67b-bedb8c8d9e6a)


#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/daea205b-7a04-496e-b265-1dc0353f77a9)

### 2. Nilai Maksimal pada Array
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
![240302_00h00m06s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/0002679d-9807-4553-83c7-2dd4134bca83)



#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/738108c9-bbb4-4d89-b24b-286cb6f0174d)

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! 

```cpp
#include <iostream>

using namespace std;

int main() {
  // Data IPS mahasiswa
  float ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};
  int n = sizeof(ips) / sizeof(ips[0]);

  // Mengurutkan IPS dengan Selection Sort
  for (int i = 0; i < n - 1; i++) {
    int max_index = i;
    for (int j = i + 1; j < n; j++) {
      if (ips[j] > ips[max_index]) {
        max_index = j;
      }
    }
    swap(ips[i], ips[max_index]);
  }

  // Menampilkan hasil
  cout << "IPS sebelum diurutkan: ";
  for (int i = 0; i < n; i++) {
    cout << ips[i] << " ";
  }
  cout << endl;

  cout << "IPS setelah diurutkan: ";
  for (int i = 0; i < n; i++) {
    cout << ips[i] << " ";
  }
  cout << endl;

  return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/277f2dec-03ec-455e-9e91-ddddede888b8)

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/3b435f3a-5ede-4d17-9a64-24a079079a90)

Program diatas merupakan program data array yang bertujuan untuk mencari nilai ganjil dan genapnya,untuk menampilkan data array kita hanya perlu menggunakan for kemudian panggil index arraynya,untuk mencari nomor genap dan ganjil menggunakan sisa bagi.

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```cpp
#include <iostream>

using namespace std;

int main() {
  // Nama-nama warga
  string nama[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
  int n = sizeof(nama) / sizeof(nama[0]);

  // Mengurutkan nama dengan Bubble Sort
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (nama[j] > nama[j + 1]) {
        // Menukar elemen yang berdekatan jika tidak terurut
        string temp = nama[j];
        nama[j] = nama[j + 1];
        nama[j + 1] = temp;
      }
    }
  }

  // Menampilkan hasil
  cout << "Daftar nama warga setelah diurutkan: " << endl;
  for (int i = 0; i < n; i++) {
    cout << nama[i] << " ";
  }
  cout << endl;

  return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/3d762723-c5bb-4903-87ed-ac3b7ad2b044)

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/3898e723-01a1-46ec-8c49-a706efae20a3)

Program diatas merupakan program array tiga dimensi yang dimana jumlah elemennya diinputkan oleh user sebelum memasukan inputan,masukan ukuran arraynya maka kita akan diminta masukan elemennya dan elemen muncul sesuai yang diinputkan.

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

void heapify(char *karakter, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && karakter[left] > karakter[largest]) {
    largest = left;
  }

  if (right < n && karakter[right] > karakter[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(karakter[i], karakter[largest]);
    heapify(karakter, n, largest);
  }
}

void heapSort(char *karakter, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(karakter, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    swap(karakter[0], karakter[i]);
    heapify(karakter, i, 0);
  }
}

int main() {
  // Mendapatkan jumlah karakter dari user
  int n;
  cout << "Masukkan jumlah karakter: ";
  cin >> n;

  // Deklarasi array untuk menyimpan karakter
  char karakter[n];

  // Meminta user untuk memasukkan karakter
  cout << "Masukkan " << n << " karakter: ";
  for (int i = 0; i < n; i++) {
    cin >> karakter[i];
  }

  // Mengurutkan karakter secara ascending
  heapSort(karakter, n);

  // Menampilkan hasil pengurutan ascending
  cout << "Karakter setelah diurutkan ascending: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }
  cout << endl;

  // Mengurutkan karakter secara descending
  heapSort(karakter, n);
  reverse(karakter, karakter + n);

  // Menampilkan hasil pengurutan descending
  cout << "Karakter setelah diurutkan descending: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }
  cout << endl;

  return 0;
}
```
#### Output:

### Nilai Maksimum
![240302_00h00m06s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/05a04837-6bd2-404c-af92-dc976a61f522)

### Nilai Minimum
![240302_00h00m06s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/81ab49ab-dd95-496f-9a9b-69aa82b8192f)

### Nilai Rata-Rata
![240302_00h00m06s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/38c756b7-3f8a-479e-b3db-d40d90c5d9ea)

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/37695d34-592b-4a05-91f3-4fc22db05fca)

Program diatas merupakan program untuk mencari nilai maksimum minimum dan rata rata dari sebuah data array yang diinputkan oleh user,user memasukan jumlah elemen array terlebih dahulu, kemudian 
user menginputkan angka yang dibutuhkan, setelah sudah diinputkan akan muncul menu yang menggunakan switch case pilihan menunnya yaitu, mencari nilai maksimum,minimum,dan rata-rata.

## Kesimpulan
Kesimpulan dari array adalah array memiliki array satu dimensi array dua dimensi dan array tiga dimensi, array satu dimensi menggunakan perulangan 
satu kali, dua dimensi menggunakan perulangan dua kali, dan tiga dimensi menggunakan perulangan tiga kali, array tiga dimensi biasa digunakan untuk 
matriks. Array satu dimensi penomoran indexnya menggunakan satu angka,array dua dimensi penomoran indeksnya menggunakan dua angka dan array tiga dimensi penomoran indeksnya menggunakan tiga angka.  

## Referensi
[1] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[2] Meidyan Permata Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung : Widina Bhakti Persada Bandung, 2022.

[3] Zayid Musiafa., Struktur Data dan Implementasi Algoritma, Jakarta : Balai Pustaka, 2022.
