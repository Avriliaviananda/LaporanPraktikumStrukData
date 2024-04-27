# <h1 align="center">Laporan Praktikum Modul Struct</h1>
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


Program pertama-tama mengubah kalimat menjadi huruf kecil untuk memudahkan pencarian. Kemudian, program menggunakan algoritma binary search untuk mencari huruf "a" dalam kalimat "aku cantik". Algoritma binary search membagi kalimat menjadi dua bagian dan terus membagi bagian yang lebih kecil hingga menemukan huruf yang dicari. Dalam hal ini, algoritma akan menemukan huruf "a" pada indeks ke-1 dalam kalimat "aku cantik".

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



Program ini menunjukkan contoh penerapan algoritma penghitungan dalam bahasa C++. Program ini dapat digunakan untuk menghitung banyaknya huruf vokal dalam sebuah kalimat. Program pertama-tama mengubah kalimat menjadi huruf kecil untuk memudahkan pengecekan. Kemudian, program menghitung banyaknya huruf vokal dalam kalimat "kamu jelek". Huruf vokal dalam kalimat tersebut adalah "a", "u", dan "e".



## Kesimpulan
Kesimpulan dari Pencarian (searching) pada struktur data adalah proses untuk menemukan elemen tertentu (target) dari kumpulan elemen lainnya. Kumpulan elemen ini bisa berupa array, list, linked list, tree, dan lain sebagainya. Ada dua algoritma pencarian utama yang umum digunakan: Pencarian Berurutan (Sequential Search) Sequential search adalah teknik pencarian data yang dilakukan dengan cara membandingkan setiap elemen data satu per satu, mulai dari elemen pertama hingga elemen yang dicari ditemukan, sedangkan Pencarian Bagi Dua (Binary Search) Binary Search merupakan sebuah teknik pencarian data dengancara berulang kali membagi separuh dari jumlah data yang dicari sampai sehingga memperkecil lokasi pencarian menjadi satu data. 

## Referensi
[1] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[2] Meidyan Permata Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung : Widina Bhakti Persada Bandung, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.
