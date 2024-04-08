# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

Searching

Searching (pencarian) pada struktur data mengacu pada proses 
algoritmik untuk memeriksa, menemukan, mengambil posisi elemen tertentu (target) dari kumpulan elemen di dalam struktur data. Kumpulan elemen dapat berupa array, list, linked list, tree, dan lain sebagainya. Berdasarkan jenis operasinya, dua algoritma pencarian yang dibahas pada subbab ini yaitu Sequential Search dan Binary Search pada data array. [2]

1. Sequential Search

Sequential Search (pencarian berurutan) dikenal juga sebagai 
pencarian linier. Sequential Search merupakan algoritma pencarian paling dasar dan paling sederhana yang bekerja menggunakan pendekatan brute force, mencoba segala kemungkinan yang ada hingga target yang diinginkan ditemukan. Sebagai contoh, mencari nilai 36 dari data array {12, 
7, 30, 28, 2, 19, 36, 21, 16, 9}. Sequential Search dimulai dengan membandingkan/mencocokkan 36 dengan elemen pertama/index[0] yaitu 12, karena 12 tidak sesuai dengan kriteria pencarian (12 != 36) maka dilanjutkan dengan membandingkan 36 dengan elemen berikutnya hingga ditemukan elemen yang cocok, yaitu pada index[6] dimana 36 == 36. [2]

![Screenshot 2024-04-06 131806](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/9ce25adb-d968-4ed6-aeb3-a867bf50d770)

Sequential Search dideskripsikan pada class Sequential Search (baris 6) sedangkan proses pencarian data dilakukan didalam method search (baris 7). Method search menerima kunci pencarian dari pengguna (baris 12) kemudian menggunakan perulangan (baris 13) untuk membandingkan kunci pencarian dengan semua elemen pada array (baris 15). Program berhenti ketika elemen telah ditemukan (baris 16) atau ketika semua 
elemen telah selesai dibandingkan (baris 20). Output program dapat dilihat pada Gambar, pada output dijabarkan tahapan proses pencarian dan hasil pencarian apabila elemen ditemukan dan tidak ditemukan. [2]

2. Binary Search

Pencarian bagidua (binary search) adalah proses 
pencarian dengan membagi dua bagian data kemudian 
membandingkan isi data bagian pertama atau bagian kedua 
dengan data yang akan dicari. Pada metode ini membutuhkan 
nilai indeks terkecil dan terbesar untuk dijumlahkan kemudian 
dibagi dua.[3] Pencarian bagi dua (binary search) hanya bisa 
dilakukan pada data yang sudah urut. Metode ini lebih efisien 
dibandingkan dengan metode pencarian sequential search atau 
pencarian beruntun. Pencarian Biner sebagai algoritma pencarian yang digunakan dalam array yang diurutkan dengan berulang kali membagi interval pencarian menjadi dua. Ide pencarian biner adalah menggunakan informasi bahwa array diurutkan dan mengurangi kompleksitas waktu ke O (log N). [1]

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
![Screenshot 2024-04-06 141330](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/1df35483-cd4c-4950-9b4d-1c31e574e400)




#### Full code Screenshot:
![Screenshot (291)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/da803026-f87a-40c3-9c07-cbb3a7486944)

Program sequential search diatas berhasil menemukan angka yang dicari (10) pada indeks ke-9 dalam array data. Algoritma sequential search bekerja dengan cara membandingkan nilai yang dicari dengan setiap elemen array secara berurutan, dimulai dari elemen pertama. Ketika nilai yang dicari ditemukan, program akan berhenti dan menampilkan indeks elemen tersebut.

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
![Screenshot 2024-04-06 141838](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/dc9cd03e-eb3f-4271-9ce6-e68a9bb7d5c7)



#### Full code Screenshot:
![Screenshot (292)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/d70964f8-2aa6-437a-a1fe-f4dc7a8c685b)


program binary search berhasil menemukan angka 7 pada indeks ke-4 dalam array data. dan dihasilkan data yang terurut dari 1, 8, 2, 5, 4, 9, 7 menjadi 1, 2, 4, 5, 7, 8, 9

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!


```cpp
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mencari huruf dalam string menggunakan binary search
bool binarySearch(const string& str, char target) {
    int left = 0;
    int right = str.length() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (str[mid] == target)
            return true;
        else if (str[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    string kalimat;
    char target;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Mengubah kalimat menjadi huruf kecil untuk memudahkan pencarian
    for (char &ch : kalimat) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 'a' - 'A';
        }
    }

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;
    cin.ignore();

    // Mencari huruf menggunakan binary search
    bool ditemukan = binarySearch(kalimat, target);

    if (ditemukan)
        cout << "Huruf '" << target << "' ditemukan dalam kalimat." << endl;
    else
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;

    return 0;
}

```
#### Output:
![Screenshot 2024-04-06 151402](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/8e46c4e3-5db7-4c8c-b2b1-92f0fe1347b6)


#### Full code Screenshot:
![Screenshot (293)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/6c30901e-1d2c-4bb0-aad3-5847dad5eb8f)


Program pertama-tama mengubah kalimat menjadi huruf kecil untuk memudahkan pencarian. Kemudian, program menggunakan algoritma binary search untuk mencari huruf "a" dalam kalimat "aku cantik". Algoritma binary search membagi kalimat menjadi dua bagian dan terus membagi bagian yang lebih kecil hingga menemukan huruf yang dicari. Dalam hal ini, algoritma akan menemukan huruf "a" pada indeks ke-1 dalam kalimat "aku cantik".

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```cpp
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mengecek apakah sebuah karakter adalah huruf vokal
bool isVowel(char ch) {
    ch = tolower(ch); // Konversi huruf menjadi huruf kecil untuk memudahkan pengecekan
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Fungsi untuk menghitung banyaknya huruf vokal dalam sebuah kalimat
int countVowels(const string& sentence) {
    int count = 0;
    for (char ch : sentence) {
        if (isVowel(ch)) {
            count++;
        }
    }
    return count;
}

int main() {
   string kalimat;

   cout << "Masukkan kalimat: ";
   getline(cin, kalimat);

    // Menghitung banyaknya huruf vokal dalam kalimat
    int jumlahVokal = countVowels(kalimat);

   cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahVokal <<endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-04-06 151609](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/9c6c7416-ce38-43d9-9e15-8e5e15c7df67)


#### Full code Screenshot:
![Screenshot (294)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/f540c95e-81db-495c-90f5-7488a2253d07)



Program ini menunjukkan contoh penerapan algoritma penghitungan dalam bahasa C++. Program ini dapat digunakan untuk menghitung banyaknya huruf vokal dalam sebuah kalimat. Program pertama-tama mengubah kalimat menjadi huruf kecil untuk memudahkan pengecekan. Kemudian, program menghitung banyaknya huruf vokal dalam kalimat "kamu jelek". Huruf vokal dalam kalimat tersebut adalah "a", "u", dan "e".

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```cpp
#include <iostream>

using namespace std;
// Fungsi untuk menghitung berapa banyak angka 4 dalam data menggunakan sequential search
int countOccurrences(int data[], int length, int target) {
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (data[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int target = 4;
    int length = sizeof(data) / sizeof(data[0]);

    // Menghitung berapa banyak angka 4 dalam data menggunakan sequential search
    int jumlahAngka4 = countOccurrences(data, length, target);

    cout << "Banyaknya angka 4 dalam data adalah: " << jumlahAngka4 << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-04-06 151644](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/4952b5a0-2315-4018-aeaa-1626b985329e)


#### Full code Screenshot:
![Screenshot (295)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/83847292-12d0-48f7-ba27-6f3bdb639993)



Program ini menunjukkan contoh penerapan algoritma sequential search dalam bahasa C++. Program ini dapat digunakan untuk menghitung banyaknya nilai tertentu dalam sebuah array. Program pertama-tama menginisialisasi array data yang berisi angka-angka dan target yang ingin dicari (angka 4). Kemudian, program menghitung banyaknya angka 4 dalam array data menggunakan algoritma sequential search. Algoritma sequential search mencari nilai target dalam array data dengan cara membandingkan nilai target dengan setiap elemen array.

## Kesimpulan
Kesimpulan dari Pencarian (searching) pada struktur data adalah proses untuk menemukan elemen tertentu (target) dari kumpulan elemen lainnya. Kumpulan elemen ini bisa berupa array, list, linked list, tree, dan lain sebagainya. Ada dua algoritma pencarian utama yang umum digunakan: Pencarian Berurutan (Sequential Search) Sequential search adalah teknik pencarian data yang dilakukan dengan cara membandingkan setiap elemen data satu per satu, mulai dari elemen pertama hingga elemen yang dicari ditemukan, sedangkan Pencarian Bagi Dua (Binary Search) Binary Search merupakan sebuah teknik pencarian data dengancara berulang kali membagi separuh dari jumlah data yang dicari sampai sehingga memperkecil lokasi pencarian menjadi satu data. 

## Referensi
[1] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[2] Meidyan Permata Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung : Widina Bhakti Persada Bandung, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.
