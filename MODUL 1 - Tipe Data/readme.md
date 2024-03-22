# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

Tipe data merupakan bagian program yang paling
penting karena tipe data mempengaruhi setiap instruksi yang
akan dilaksanakan oleh computer. berikut jenis tipe data: 
1. Tipe data Primitif
Macam tipe data primitif diantaranya :

-Integer (Bilangan bulat)
Integer merupakan tipe data numerik yang digunakan untuk 
mendefinisikan bilangan bulat. Tipe data numeric yang termasuk integer diantaranya byte, short, int, long

-floating ( Bilangan pecahan)
Floating point digunakan untuk menangani bilangan desimal 

-char (karakter)
Char adalah karakter tunggal yang pendefinisiannya di awal dan akhir menggunakan tanda petik tunggal ( ‘ ).

-boolean
Tipe data Boolean terdiri dari dua nilai saja, yaitu true dan false. [1]

2. Tipe data Abstrak
Tipe data abstrak adalah kelas/ tipe untuk objek yang perilakunya ditentukan oleh satu set nilai dan satu set operasi. Tipe data abstrak (ADT) adalah model matematika dari objek data yang meningkatkan tipe data dengan mengaitkan tipe data dengan fungsi yang beroperasi pada data terkait. [3]

3. Tipe data Koleksi
Tipe data koleksi adalah jenis tipe data yang digunakan untuk menyimpan kumpulan data yang berjumlah lebih dari satu. Tipe data koleksi terdiri dari tipe data yang berbeda, seperti array, vector, dan map. 

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream> 
using namespace std;
// Main Program
main()
{
    char op;
    int num1, num2;
    //It allows users to enter operator i.e. +, -, *, /
    cout << "Masukan operator: "; 
    cin >> op;
    //It allows user to enter operands
    cout << "Masukan angka 1 dan 2: ";
    cin >> num1 >> num2;
    //switch statement begins
    
    switch(op)
    {
  //if user enter +
  case '+':
    cout << num1 + num2;    
    break;
  // if user enter -
  case '-':
    cout << num1 - num2;
    break;
  //if user enter *
  case '*':
    cout << num1 * num2;
    break;
  // if user enter /
  case '/':
    cout << num1 / num2;
    break;
  // If the operator is other than +, -, *, /
  //error message will display
  default:
    cout << "Error! operator is nor correct";
  } // switch statements end
  return 0;
}
```

#### Output:
![Screenshot (244)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/716fd0c7-192e-4323-a4ac-a8bbf24e8ebf)

Kode tersebut digunakan untuk membuat kalkulator sederhana yang dapat melakukan operasi penjumlahan, pengurangan, perkalian, dan pembagian. 


### 2. Tipe Data Abstrak
```C++
#include <stdio.h>

// struct
struct Mahasiswa
{
  const char *name;
  const char *addres;
  int age;
};

int main()
{

  // menggunakan struct
  struct Mahasiswa mhs1, mhs2;
  // mengisi nilai ke struct
  mhs1.name = "Dian";
  mhs1.addres = "Mataram";
  mhs1.age = 22;
  mhs2.name = "Bambang";
  mhs2.addres = "Surabaya";
  mhs2.age = 23;

  // mencetak list struct
  printf("## Mahasiswa 1 ##\n");
  printf("Name: %s\n", mhs1.name);
  printf("Alamat: %s\n", mhs1.addres);
  printf("Umur: %d\n", mhs1.age);
  printf("## Mahasiswa 2 ##\n");
  printf("Nama: %s\n", mhs2.name);
  printf("Alamat: %s\n", mhs2.addres);
  printf("Umur: %d\n", mhs2.age);
  return 0;
}
```

#### Output:
![Screenshot (242)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/094078b5-447f-4c7a-a2ef-5b6af0cc9691)

Kode tersebut menggunakan struct (struktur). Struktur adalah koleksi dari variabel yang dinyatakan dengan sebuah nama, dengan sifat setiap variabel dapat memiliki tipe yang berlainan. Struktur biasa dipakai untuk mengelompokkan beberapa informasi yang berkaitan 
menjadi sebuah satu kesatuan. [2]

### 3. Tipe Data Koleksi
```C++
#include <iostream>
using namespace std;
int main()
{
    // deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```

#### Output:
![Screenshot (241)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/29942179-3d66-4653-aeae-86c6345d1eed)

Kode di atas digunakan untuk mendeklarasikan, menginisialisasi, dan mencetak elemen array. Kode ini mendeklarasikan array nilai dengan 5 elemen dan menginisialisasi setiap elemennya dengan nilai yang berbeda. nilai array diisi dengan nilai 23, 50, 34, 78, dan 90. Kemudian, kode tersebut mencetak nilai setiap elemen array satu per satu.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;
   
// fungsi untuk menghitung luas persegi panjang
int hitungLuasPersegiPanjang(int panjang, int lebar)
{
return panjang * lebar;
}

// fungsi untuk menampilkan pesan
void tampilkanPesan(string pesan) { 
    cout << "Pesan: " << pesan << endl;
}

int main() {
    int panjang = 5;
    int lebar = 5;
    int luas = hitungLuasPersegiPanjang(panjang, lebar);

tampilkanPesan("Luas persegi panjang adalah " + to_string(luas));

return 0;
}
```

#### Output:
![Screenshot (249)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/f460f0e6-72f1-40bc-b58d-e6ea1251dc19)

kode diatas menggunakan tipe data primitif. 
Kode ini menghitung luas persegi panjang dengan panjang dan lebar 5, dan kemudian menampilkan pesan "Luas persegi panjang adalah 25". Kesimpulan dari kodingan diatas adalah pembuatan fungsi untuk menghitung luas persegi panjang dan menampilkan pesan. Fungsi hitungLuasPersegiPanjang menerima dua parameter panjang dan lebar, dan mengembalikan nilai luas persegi panjang yang dihitung dengan rumus panjang * lebar. variabel panjang dan lebar dimasukkan dengan nilai 5, luas persegi panjang dihitung dengan fungsi hitungLuasPersegiPanjang, dan hasilnya ditampilkan dengan fungsi tampilkanPesan.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

### class

```C++
#include <iostream>
using namespace std;

class buku {
    public:
    string jenis;
    int tahun_pembuatan;

// fungsi anggota untuk menampilkan data buku
    void tampilkan_data() {
        cout << "jenis buku: " << jenis << endl;
        cout << "tahun pembuatan: " << tahun_pembuatan << endl;
    }
};

int main() {
    buku bukupaket1;           
    bukupaket1.jenis = "erlangga";   
    bukupaket1.tahun_pembuatan = 2017; 
    bukupaket1.tampilkan_data(); 

    buku bukupaket2;           
    bukupaket2.jenis = "biografi"; 
    bukupaket2.tahun_pembuatan = 2015; 
    bukupaket2.tampilkan_data(); 

    return 0;


}
```
Class mendefinisikan sebuah tipe dari objek. Di dalam class kita dapat mendeklarasikan variabel dan menciptakan objek (instansiasi). Sebuah class mempunyai anggota yang terdiri
dari atribut dan method. Atribut adalah semua field identitas yang kita berikan pada suatu class.


#### Output:
![Screenshot (250)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/7e3786c1-d002-42e6-ad5f-ad5ca482a625)

Kode di atas digunakan untuk mendefinisikan kelas dengan atribut dan fungsi anggota, serta cara membuat dan menggunakan objek dari kelas tersebut. Kode ini membuat dua objek bukupaket1 dan bukupaket2 dengan atribut jenis dan tahun_pembuatan yang berbeda, dan kemudian mencetak informasi dari kedua objek tersebut.


### struct 

```C++
#include <iostream>
using namespace std;

// mendefinisikan struktur
struct saham{
    string nama_saham;
    int nilai_saham;
};

// deklarasi variabel
int main()
{

    saham A;
    saham B;

    string pilih;
    int lot, uang, saham, jumlah;
    saham = 5000;
    jumlah = 0;

// Meminta Input dari Pengguna
    cout << "masukan nama saham A => ";
    cin >> A.nama_saham;

    cout << "masukkan nilai saham A =>  ";
    cin >> A.nilai_saham;

    cout << "masukkan nama saham B => ";
    cin >> B.nama_saham;

    cout << "masukkan nilai saham B => ";
    cin >> B.nilai_saham;


//Menampilkan Informasi Saham
    cout << "nama saham A: " << A.nama_saham << endl;
    cout << "nama harga A: " << A.nilai_saham << endl;

    cout << "nama saham B: " << B.nama_saham << endl;
    cout << "nama harga B: " << B.nilai_saham << endl; 

}
```
Struktur adalah koleksi dari variabel yang dinyatakan 
dengan sebuah nama, dengan sifat setiap variabel dapat 
memiliki tipe yang berlainan. Struktur biasa dipakai untuk 
mengelompokkan beberapa informasi yang berkaitan 
menjadi sebuah satu kesatuan. [2]

#### Output:
![Screenshot (251)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/ce1059ad-82c8-4a3f-8db2-ed35b228713b)

Kodingan diatas digunakan untuk menginput dan menampilkan data saham. Setelah deklarasi dan inisialisasi struct saham, dua objek saham dibuat. Kemudian, kode menginput nama saham dan nilai saham menggunakan cin, agar bisa memasukkan nama saham dan jumlah saham. Setelah itu, kode menampilkan data saham menggunakan cout.


### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.
```C++
#include <iostream>
#include <map>
using namespace std;

int main() {
    // membuat objek map
    map < string, int> umur;

    // memasukkan data ke dalam map
    umur["Via"] = 19;
    umur["Tata"] = 18;
    umur["Eva"] = 17;

    // mencetak data dari map
    cout << "umur Via: " << umur ["Via"] << endl;
    cout << "umur Tata: " << umur ["Tata"] << endl;
    cout << "umur Eva: " << umur ["Eva"] << endl;

    // mengubah data di dalam map
    umur["Via"] = 20;

    // mencetak data yang sudah diubah
    cout << "umur Via setelah diubah: " << umur["Via"] << endl;

    //menghapus data dari map
    umur.erase("Tata");

    // mencetak data setelah dihapus
    cout << "jumlah data di dalam map: " << umur.size() << endl;

    return 0;

}
```
perbedaan antara array dan map. Array dapat menyimpan tipe data yang sama, array untuk menyimpan elemen secara berurutan berdasarkan indeks (posisi). sedangkan map dapat menyimpan tipe data berbeda, map untuk menyimpan elemen sebagai pasangan key-value (kunci-nilai). [3]
   

#### Output:
![Screenshot (252)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/ea840b0f-ea79-4c91-a441-63c10d7336bb)

Kodingan diatas digunakan untuk membuat objek map, memasukkan data ke dalam map, mencetak data dari map, mengubah data di dalam map, dan menghapus data dari map. kode memasukkan data ke dalam map menggunakan umur["Via"] = 19. Setelah itu, kode mencetak data dari map menggunakan cout. Setelah itu, kode mengubah data di dalam map menggunakan umur["Via"] = 20. kemudian, kode menghapus data dari map menggunakan umur.erase("Tata"). dan terakhir, kode mencetak data setelah dihapus menggunakan cout.

## Kesimpulan
Kesimpulan dari tiga tipe data diatas adalah Tipe Data Primitive adalah tipe data dasar yang tersedia di bahasa pemrograman dan umumnya disediakan oleh sistem komputer. Tipe data ini termasuk integer, float, double, char, boolean. Tipe Data Abstrak adalah tipe data yang terdiri dari nilai-nilai atau elemen-elemen yang lebih kompleks, dibuat dengan mengelompokkan beberapa nilai atau elemen. Tipe Data Koleksi dalam pemrograman C++ merupakan tipe data yang digunakan untuk menyimpan sejumlah elemen atau objek

## Referensi
[1] Meidyan Permata Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung : Widina Bhakti Persada Bandung, 2022.

[2] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.

[3] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data. Tangerang Selatan: Unpam Press, 2022.
