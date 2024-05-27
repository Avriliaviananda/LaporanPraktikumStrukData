# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

Rekursif

Rekursif adalah suatu proses dari fungsi yang memanggil dirinya sendiri. Fungsi yang seperti ini disebut 
fungsi rekursif (recursive function). Dalam sebuah fungsi rekursif pemanggilan dapat terjadi berulang kali. [1] Karena 
ada proses yang berulang-ulang maka harus ada suatu kondisi yang mengakhiri prosesnya. Jika tidak, maka 
proses tidak akan pernah berhenti sampai memori yang digunakan tidak dapat menampung lagi. 
Pemecahan masalah dengan pendekatan rekursif dapat dilakukan jika masalah tersebut dapat 
didefinisikan secara rekursif, yaitu masalah dapat diuraikan menjadi masalah sejenis yang lebih sederhana. [1]

![Screenshot 2024-05-27 134250](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/f25844a5-ebb8-457b-abaf-e0cb01d5068e)

Di sini, n==0 adalah kasus dasar yang akan menghentikan iterasi fungsi ketika n sama dengan nol. 

return(n-1) adalah fungsi rekursif yang akan membantu pengulangan kode. [2]

Bentuk penulisan fungsi rekursif 

![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/ff2c91f7-301b-4144-8bc6-43b9f6a0c13f) [3]

Program rekursif  harus dinyatakan dalam prosedur atau fungsi, karena 
hanya prosedur dan fungsi yang dapat dipanggil dalam sebuah program. 
Fungsi atau Prosedur Rekursif disusun oleh dua komponen : [3]

a. Basis (komponen basis) fungsi : Menghentikan rekursif dan memberi nilai 
yang terdefinisi 

b. Aturan rekursif (komponen induksi) fungsi : mendefinisikan dengan dirinya 
sendiri

## Guided 

### 1. Rekursif Langsung (Direct Recursion)

```cpp
#include <iostream>
using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursi Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}

```
#### Output:
![Screenshot 2024-05-25 191629](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/e51784f1-b5f5-4fd3-b50a-f411ad553715)


#### Full code Screenshot:
![Screenshot (323)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/45350458-6cf9-4eb1-9297-ba9cae0fee3b)

penjelasan fungsi 

Fungsi countdown adalah fungsi rekursif yang menerima parameter n dan akan mencetak angka n sebelum memanggil dirinya sendiri dengan argumen n-1 hingga n sama dengan 0. Ketika n sama dengan 0, fungsi akan kembali tanpa melakukan apa-apa. pada program diatas kita memanggil fungsi countdown dengan argumen 5, dan program akan mencetak angka-angka dari 5 hingga 1.

penjelasan output 

Output menunjukkan hitungan mundur dimulai dari 5 hingga 1, dicetak dengan spasi di antara setiap angka. Ini mendemonstrasikan konsep rekursi langsung, di mana fungsi countdown memanggil dirinya sendiri secara berulang hingga mencapai kondisi dasar (n = 0).

### 2. Rekursif Tidak Langsung (Indirect Recursion)

```cpp
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}

```
#### Output:
![Screenshot 2024-05-25 191657](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/43330ab6-ed98-48b7-a4cd-ebab6ca49ae5)


#### Full code Screenshot:
![Screenshot (324)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/9ac31bb3-18ec-462c-8133-b54b62cbf0b9) 

Dalam program di atas, kita memanggil fungsi functionA dengan argumen 5, dan program akan mencetak angka-angka dari 5 hingga 1 dengan menggunakan rekursi tidak langsung. functionA dan functionB saling memanggil secara tidak langsung. functionA memanggil functionB, yang kemudian memanggil functionA lagi dengan nilai yang diubah. Ini berbeda dari rekursi langsung di mana fungsi memanggil dirinya sendiri secara langsung.

## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!


```cpp
#include <iostream>
using namespace std;

// Fungsi untuk menghitung faktorial menggunakan rekursi
int faktorial(int n) {
    if(n > 1)
        return n * faktorial(n - 1);
    else
        return 1;
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;
    cout << "Faktorial dari " << num << " adalah: " << faktorial(num) << endl;
    return 0;
}
```
#### Output:
![Screenshot 2024-05-27 132736](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/aacc6d31-9a2f-4ad5-99d0-7d56ca47ba12)



#### Full code Screenshot:
![Screenshot (325)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/3e7ee984-24d7-42f2-aae3-489d9a7d1f49)

Program di atas menunjukkan cara menghitung faktorial suatu bilangan menggunakan metode rekursi dalam bahasa C++. Program ini bekerja dengan memanggil fungsi faktorial() secara berulang hingga mencapai nilai dasar (1).

Penjelasan Output:

- Program meminta pengguna untuk memasukkan bilangan bulat positif.
- Pengguna memasukkan nilai 4.
- Fungsi faktorial(4) dihitung:
- n (4) > 1, maka program masuk ke dalam kondisi pertama.
- Hitung faktorial(4 - 1), yaitu faktorial(3).
- 3 > 1, maka program masuk ke dalam kondisi pertama.
- Hitung faktorial(3 - 1), yaitu faktorial(2).
- 2 > 1, maka program masuk ke dalam kondisi pertama.
- Hitung faktorial(2 - 1), yaitu faktorial(1).
- 1 <= 1, maka program masuk ke dalam kondisi kedua.
- Kembalikan nilai 1.
- Hitung 2 * faktorial(1), yaitu 2 * 1.
- Kembalikan nilai 2.
- Hitung 3 * faktorial(2), yaitu 3 * 2.
- Kembalikan nilai 6.
- Hitung 4 * faktorial(3), yaitu 4 * 6.
- Kembalikan nilai 24.
- Program mencetak faktorial dari 4, yaitu 24.

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```cpp
#include <iostream>
using namespace std;

int functionA(int num, int hasil) {
    if (num == 1) {
        return hasil;
    } else {
        return functionA(num - 1, num * hasil);
    }
}

int functionB(int num) {
    return functionA(num, 1);
}

int main() {
    int input;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> input;
    cout << "Faktorial dari " << input << " adalah " << functionB(input) << endl;
    return 0;
}
```
#### Output:
![Screenshot 2024-05-27 132805](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/49d33d79-ed67-4c17-8a7b-3dde1965d686)


#### Full code Screenshot:
![Screenshot (326)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/84449cf1-a121-4aaf-8bbb-377d4350df07)

Program di atas akan menghitung faktorial dari sebuah bilangan bulat positif yang dimasukkan oleh pengguna menggunakan metode rekursi. Jika kita memasukkan nilai 3, maka program akan menghitung faktorial dari 3 menggunakan fungsi functionB dan functionA.

penjelaskan output 
- Pengguna memasukkan nilai 3.
- Program memanggil fungsi functionB dengan argumen input yang bernilai 3.
- Fungsi functionB memanggil fungsi functionA dengan argumen num yang bernilai 3 dan hasil yang bernilai 1.
- Fungsi functionA memeriksa apakah num sama dengan 1. Karena num tidak sama dengan 1, maka fungsi functionA akan memanggil dirinya sendiri dengan argumen num - 1 dan num * hasil.
- Fungsi functionA akan terus memanggil dirinya sendiri hingga num sama dengan 1.
- Setelah num sama dengan 1, fungsi functionA akan mengembalikan nilai hasil yang telah dihitung.
- Fungsi functionB akan mengembalikan nilai yang dikembalikan oleh fungsi functionA.
- Hasil dari fungsi functionB akan ditampilkan pada output yaitu 6


## Kesimpulan
Kesimpulan dari Fungsi rekursif adalah salah satu teknik pemrograman yang cukup penting, dimana dalam beberapa kasus menggunakan fungsi rekursif akan jauh lebih mudah. Selain itu proses yang berjalan akan jauh lebih cepat dan efisien, hanya saja akan membutuhkan space memori yang cukup banyak karena proses iterasi dari bagian fungsi tersebut akan dipanggil secara terus menerus sehingga memerlukan ruang penyimpanan yang cukup besar jika dibandingkan dengan proses lainnya.Rekursif adalah suatu proses dari sebuah fungsi yang dapat memanggil dirinya sendiri secara berulang-ulang. Berbeda dengan fungsi atau prosedur yang mana keduanya hanya bisa dilakukan pemanggilan dari fungsi atau prosedur lain, sementara rekursif dapat memanggil fungsinya sendiri. Jadi fungsi rekursif c++ ini akan berjalan dengan melakukan proses sampai sebuah kondisi yang ditetapkan pada fungsi tersebut terpenuhi.

## Referensi
[1] Muhammad Taufik Dwi Putra. et.al., Pemprograman Lanjut dengan C++, Bandung : Widina Media Utama, 2023.

[2] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.
