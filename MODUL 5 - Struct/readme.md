# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

struktur (struct)

Struktur adalah tipe data terdefinisi pengguna yang digunakan untuk menggabungkan beberapa tipe data dasar menjadi satu unit. Struktur dapat digunakan untuk mewakili berbagai hal, seperti:
Data dari suatu objek, seperti data dari suatu buku, yaitu judul, pengarang, penerbit, dan tahun terbit. [1]
Data dari suatu transaksi, seperti data dari suatu pembelian, yaitu tanggal, jumlah barang, dan total harga.
Data dari suatu permainan, seperti data dari suatu pemain, yaitu nama, usia, dan tingkat kesulitan.
Struktur dapat digunakan untuk membuat kode yang lebih ringkas dan mudah dibaca. Misalnya, jika kita ingin menyimpan data dari suatu buku, kita dapat menggunakan struktur sebagai berikut: [2]
![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/85e9fc34-d9c5-4fc3-b9b5-2094f0d51f65)

Struktur ini memiliki empat anggota, yaitu:
1. judul: tipe data std::string untuk menyimpan judul buku.

2. pengarang: tipe data std::string untuk menyimpan nama pengarang buku.

3. penerbit: tipe data std::string untuk menyimpan nama penerbit buku.

4. tahun_terbit: tipe data int untuk menyimpan tahun terbit buku. [2]

Struktur adalah tipe data terdefinisi pengguna yang digunakan untuk menggabungkan beberapa tipe data dasar menjadi satu unit. Struktur dapat digunakan untuk membuat kode yang lebih ringkas dan mudah dibaca. [3]




## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```cpp
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```
#### Output:
![Screenshot 2024-04-24 204638](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/33a01db9-42a0-4322-8ea1-0dbe113787a1)


#### Full code Screenshot:
![Screenshot (296)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/75311596-e4c0-4001-b91b-318b37ebc0b2)

Kode di atas adalah sebuah program C++ yang menggunakan struktur (struct) untuk mendefinisikan sebuah tipe data baru bernama buku, yang merepresentasikan informasi mengenai sebuah buku. Program kemudian membuat variabel favorit dengan tipe data buku untuk menyimpan informasi tentang buku favorit pengguna. Setelah itu, data-data buku favorit diisi ke dalam variabel favorit.

Output dari program ini akan menampilkan informasi mengenai buku favorit dalam format yang telah ditentukan, seperti judul buku, pengarang, penerbit, tebal halaman, dan harga buku.

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.

```cpp
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-04-24 205726](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/7371d43f-1feb-4be4-8ab8-09e828bbf0b3)



#### Full code Screenshot:
![Screenshot (292)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/d70964f8-2aa6-437a-a1fe-f4dc7a8c685b)


Kode di atas adalah program C++ yang mendefinisikan beberapa struktur (struct) untuk merepresentasikan informasi mengenai hewan, hewan darat, dan hewan laut. Program kemudian membuat beberapa variabel menggunakan struktur-struktur tersebut dan menginisialisasi nilai-nilai di dalamnya.

Output dari program ini akan menampilkan informasi tentang hewan, hewan darat, dan hewan laut yang telah diinisialisasi sebelumnya.

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.


```cpp
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int jumlahHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel data buku dengan tipe buku
    buku dataBuku;

    // Mengisi data ke dalam variabel buku
    for(int i = 0; i < 5; ++i) {
        dataBuku.judulBuku[i] = "Is it Bad or Good" + to_string(i+1); 
        dataBuku.pengarang[i] = "Sabrina Ara";
        dataBuku.penerbit[i] = "Syalmahat";
        dataBuku.jumlahHalaman[i] = 205;
        dataBuku.hargaBuku[i] = 85000;
    }

    // Menampilkan informasi data buku
    cout << "\tData Buku" << endl;
    for (int i = 0; i < 5; ++i) {
    cout << "\tData Buku Saya" << endl;
    cout << "\tJudul Buku : " << dataBuku.judulBuku[i] << endl;
    cout << "\tPengarang : " << dataBuku.pengarang[i] << endl;
    cout << "\tPenerbit : " << dataBuku.penerbit[i] << endl;
    cout << "\tJumlah Halaman: " << dataBuku.jumlahHalaman[i] << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << dataBuku.hargaBuku[i] << endl;
    cout << endl;
    } 
    return 0;
}

```
#### Output:
![Screenshot 2024-04-27 003659](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/78ff36b4-fc7b-442e-85f8-55ad712bc866)

#### Full code Screenshot:
![Screenshot (301)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/83a18eda-3c84-4c1b-bdd2-6cc5d35e7730)

Program tersebut adalah program C++ yang menggunakan struktur (struct) untuk merepresentasikan data buku. Di dalamnya, terdapat sebuah struktur bernama "buku" yang memiliki beberapa atribut seperti judul buku, pengarang, penerbit, jumlah halaman, dan harga buku. Program ini kemudian menginisialisasi variabel dataBuku dengan tipe struct buku. program tersebut sama seperti guided pertama, tetapi pada soal dimita untuk memodifikasi supaya setiap item yang terdapat pada struct buku berupa array yang berukuran 5. program ini akan menampilkan informasi lima buku yang memiliki judul "Is it Bad or Good1" sampai "Is it Bad or Good5", dengan pengarang, penerbit, jumlah halaman, dan harga buku yang sama untuk setiap buku.

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

```cpp
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct Buku {
  string judulBuku[5];
  string pengarang[5];
  string penerbit[5];
  int jumlahHalaman[5];
  int hargaBuku[5];
};

int main() {
  // Mendeklarasikan variabel dataBuku dengan tipe Buku
  Buku dataBuku;

  // Mengisi data ke dalam array dalam variabel dataBuku
  for (int i = 0; i < 5; ++i) {
    cout << "Masukkan data buku ke-" << i + 1 << endl;
    cout << "Judul Buku: ";
    cin.ignore(); // Mengabaikan input baris sebelumnya
    getline(cin, dataBuku.judulBuku[i]);

    cout << "Pengarang: ";
    getline(cin, dataBuku.pengarang[i]);

    cout << "Penerbit: ";
    getline(cin, dataBuku.penerbit[i]);

    cout << "jumlah Halaman: ";
    cin >> dataBuku.jumlahHalaman[i];

    cout << "Harga Buku: ";
    cin >> dataBuku.hargaBuku[i];

    cin.ignore(); // Mengabaikan input baris sebelumnya
    cout << endl;
  }

  // Menampilkan informasi buku
  cout << "\tData Buku" << endl;
  for (int i = 0; i < 5; ++i) {
    cout << "\nBuku ke-" << i + 1 << endl;
    cout << "Judul Buku : " << dataBuku.judulBuku[i] << endl;
    cout << "Pengarang : " << dataBuku.pengarang[i] << endl;
    cout << "Penerbit : " << dataBuku.penerbit[i] << endl;
    cout << "Jumlah Halaman: " << dataBuku.jumlahHalaman[i] << " halaman" << endl;
    cout << "Harga Buku : Rp " << dataBuku.hargaBuku[i] << endl;
  }

  return 0;
}
```
#### Output:
![Screenshot 2024-04-27 004151](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/a5032623-8e5d-4bbe-a85c-78875c448abe)


#### Full code Screenshot:
![Screenshot (302)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/e2b5b904-4dc9-42fa-9304-e605b538f720)



Program ini meminta pengguna untuk memasukkan data untuk lima buku. Setiap entri data termasuk judul buku, pengarang, penerbit, jumlah halaman, dan harga buku. Pengguna diminta untuk memasukkan data satu per satu untuk setiap buku.
Setelah pengguna memasukkan data untuk semua lima buku, program akan menampilkan informasi yang dimasukkan oleh pengguna untuk setiap buku.



## Kesimpulan
Kesimpulan dari Struct dalam bahasa C++ adalah tipe data bentukan yang terdiri dari kumpulan tipe data lain. Mirip dengan array, struct memungkinkan pengelompokan variabel dengan tipe data yang berbeda. Dalam struct, kita dapat mendefinisikan komponen-komponen data yang berbeda tipe dalam satu struktur. Struct digunakan untuk membuat tipe data baru yang dapat menampung informasi atau data dengan format tertentu. Dalam C++, struktur dideklarasikan menggunakan keyword struct diikuti dengan nama struktur, di mana variabel-variabel struktur dideklarasikan dalam kurung kurawal {}. 

## Referensi
[1] Windha Mega Pradnya Dhuhita., Struktur Data C++, Jakarta: Wlex Media Komputindo, 2020.

[2] Reva Ragam, Algoritma dan Struktur Data 1, Jakarta : Esa Unggul, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.
