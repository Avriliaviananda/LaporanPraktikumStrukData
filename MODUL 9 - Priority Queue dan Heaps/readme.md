# <h1 align="center">Laporan Praktikum Modul priority queue dan heaps</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

Queue

Priority Queue adalah struktur data khusus yang mirip dengan antrian biasa, namun dengan penambahan konsep prioritas. Setiap elemen dalam Priority Queue memiliki nilai prioritas yang menentukan urutan pengambilannya. Elemen dengan prioritas tertinggi akan selalu diambil terlebih dahulu, tanpa memandang kapan ia dimasukkan ke dalam antrian. Priority Queue adalah suatu bentuk struktur data yang berbasiskan struktur Queue pada umumnya.Pada priority Queue, terdapat salah satu bentuk implementasi yaitu implementasi menggunakan struktur data heaps. Dalam implementasi ini ada 3
pokok atribut yaitu heaps, comparator, dan last. [2]

Struktur Priority Queue :

![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/adef656c-cd7e-4c3f-b84f-4c73ee8e9cca)

Heap menunjuk pada akar, last menunjuk pada
elemen akhir, dan comparator menunjukan
pembanding untuk menipulasi posisi. 

Heap adalah struktur data berbasis pohon yang memiliki sifat khusus.  Heap dapat dikategorikan menjadi dua jenis: Max Heap dan Min Heap. [1]

Max Heap: Nilai pada setiap node (simpul) selalu lebih besar atau sama dengan nilai pada anak-anaknya. Akibatnya, elemen dengan nilai terbesar akan selalu berada di node akar (root).
Min Heap: Sebaliknya, nilai pada setiap node selalu lebih kecil atau sama dengan nilai pada anak-anaknya. Elemen dengan nilai terkecil menempati posisi root.
Operasi dasar pada Heap seperti penyisipan dan penghapusan elemen dapat dilakukan dalam waktu logaritmik (log n), yang tergolong efisien untuk ukuran data yang besar. [3]


## Guided 

### 1. Guided

```cpp
#include <iostream>
#include <algorithm>

int H[50];
int heapsize = -1;

int parent(int i) {
    return(i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) +1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while(i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]) ;
        i = parent(i);
    }
}


void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapsize && H[l] > H [maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapsize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftUp(heapsize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <=heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}

```
#### Output:
![Screenshot 2024-05-17 120617](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/5941841f-aaae-4ffb-8b76-f667b747a80a)


#### Full code Screenshot:
![Screenshot (319)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/d1ef812d-5558-431b-8008-ec6d1f9cbea6)


Penjelasan output:

- Memasukkan Elemen: Kode ini langsung memasukkan elemen-elemen 45, 31, 14, 13, 20, 7, 11, 12, dan 7 ke dalam antrian prioritas menggunakan fungsi insert.

- Antrian Prioritas Awal: Setelah semua elemen dimasukkan, kode mencetak isi awal dari antrian prioritas. Perlu diingat bahwa antrian prioritas ini menggunakan struktur tumpukan maksimum, sehingga elemen dengan nilai terbesar akan berada di posisi teratas (indeks 0). Dalam output, terlihat 45 sebagai elemen dengan prioritas tertinggi.

- Ekstrak Elemen Maksimum: Fungsi extractMax digunakan untuk mengekstrak elemen dengan prioritas tertinggi (45) dan kemudian mencetaknya. Elemen yang terambil akan dihapus dari tumpukan dan struktur tumpukan maksimum diperbaiki dengan fungsi shiftDown.

- Ubah Prioritas: Prioritas elemen pada indeks 2 (yang awalnya mungkin memiliki nilai selain 49) diubah menjadi 49 menggunakan fungsi changePriority. Perubahan ini membuat elemen tersebut menjadi yang teratas karena memiliki prioritas tertinggi dalam tumpukan. Output menunjukkan perubahan tersebut pada antrian prioritas.

- Hapus Elemen: Elemen pada indeks 3 dihapus menggunakan fungsi remove. Proses penghapusan ini menggunakan teknik untuk menaikkan prioritas elemen yang akan dihapus menjadi nilai tertinggi, kemudian memindahkannya ke posisi teratas, dan terakhir mengeluarkan elemen teratas tersebut (yang sebenarnya adalah elemen yang ingin dihapus). Output menunjukkan antrian prioritas setelah elemen pada indeks 3 dihapus. elemen setelah dihapus pada index 3 menjadi 49 20 31 12 7 7 11.

## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.


```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int H[50]; // Array untuk menyimpan elemen heap
int heapsize = -1; // Ukuran heap saat ini (awalnya kosong)

int parent(int i) {
    return(i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) +1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while(i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]) ;
        i = parent(i);
    }
}


void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapsize && H[l] > H [maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapsize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i!= maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftUp(heapsize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;

    // Dapatkan jumlah elemen dari pengguna
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    // Masukkan elemen ke dalam heap
    for (int i = 0; i < n; ++i) {
        int x;
        cout << "Masukkan elemen " << i + 1 << ": ";
        cin >> x;
        insert(x);
    }

    // Cetak antrian prioritas awal
    cout << "Antrian Prioritas : ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // Ekstrak elemen dengan prioritas tertinggi
    cout << "Elemen dengan prioritas teratas : " << extractMax() << "\n";

    // Cetak antrian prioritas setelah ekstraksi
    cout << "Antrian prioritas setelah elemen teratas diambil : ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // Ubah prioritas elemen pada indeks 2
    changePriority(2, 49);

    // Cetak antrian prioritas setelah perubahan prioritas
    cout << "Antrian prioritas setelah perubahan prioritas: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // Hapus elemen pada indeks 3
    remove(3);

    // Cetak antrian prioritas setelah penghapusan
    cout << "Antrian prioritas setelah elemen dihapus: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}

```
#### Output:
![Screenshot 2024-05-17 113842](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/a6b47719-3c66-4375-9943-6056b1187cc4)


#### Full code Screenshot:
![Screenshot (317)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/194d7995-14fd-467c-8700-38b5a90ebc0e)

Kode tersebut mengimplementasikan sebuah antrian prioritas menggunakan struktur data tumpukan maksimum (max heap). 

1. Array dan Variabel:

H[50]: Array untuk menyimpan elemen-elemen dalam tumpukan. Maksimal 50 elemen dapat disimpan.

heapsize: Variabel yang mencatat ukuran tumpukan saat ini (awalnya -1 karena kosong).

2. Fungsi Penunjang Tumpukan:

parent(int i): Fungsi ini menghitung indeks elemen induk dari elemen pada indeks i.

leftChild(int i): Fungsi ini menghitung indeks elemen anak kiri dari elemen pada indeks i.

rightChild(int i): Fungsi ini menghitung indeks elemen anak kanan dari elemen pada indeks i.

3. Fungsi untuk Menjaga Struktur Tumpukan Maksimum:

shiftUp(int i): Fungsi ini menaikkan elemen pada indeks i ke atas tumpukan jika nilainya lebih besar dari elemen induknya. Ini dilakukan berulang kali hingga elemen mencapai posisi yang tepat dalam tumpukan maksimum.

shiftDown(int i): Fungsi ini menurunkan elemen pada indeks i ke bawah tumpukan jika nilainya lebih kecil dari salah satu anaknya. Ini dilakukan berulang kali hingga elemen mencapai posisi yang tepat dalam tumpukan maksimum.

4. Fungsi Operasi pada Antrian Prioritas:

insert(int p): Fungsi ini memasukkan elemen p ke dalam tumpukan. Elemen baru akan disisipkan pada posisi terakhir dan kemudian dinaikkan ke atas tumpukan menggunakan shiftUp untuk memastikan struktur tumpukan maksimum terjaga.

extractMax(): Fungsi ini mengekstrak elemen dengan prioritas tertinggi (nilai terbesar) dari tumpukan. Elemen teratas (indeks 0) akan diambil dan dikembalikan. Elemen terakhir dari tumpukan kemudian dipindahkan ke indeks 0 dan fungsi shiftDown digunakan untuk mengembalikan struktur tumpukan maksimum.

changePriority(int i, int p): Fungsi ini mengubah prioritas elemen pada indeks i menjadi nilai p. Jika nilai p lebih besar dari prioritas sebelumnya, fungsi shiftUp digunakan untuk menaikkan elemen tersebut. Sebaliknya, jika nilai p lebih kecil, fungsi shiftDown digunakan untuk menurunkan elemen tersebut dalam tumpukan.

getMax(): Fungsi ini mengembalikan nilai elemen dengan prioritas tertinggi (nilai terbesar) pada tumpukan tanpa mengeluarkannya.

remove(int i): Fungsi ini menghapus elemen pada indeks i dari tumpukan. Untuk melakukan penghapusan, prioritas elemen pada indeks i dinaikkan menjadi nilai yang lebih besar dari semua elemen lain (menggunakan nilai maksimum yang ditambah 1). Kemudian fungsi shiftUp digunakan untuk menaikkan elemen tersebut ke posisi teratas. 

fungsi extractMax digunakan untuk mengeluarkan elemen teratas yang sebenarnya adalah elemen yang ingin dihapus.

Penjelasan output:

- Input: Anda memasukkan 5 sebagai jumlah elemen dan kemudian memberikan elemen 20, 35, 40, 25, dan 30.

- Antrian Prioritas Awal: Kode memasukkan elemen-elemen ini ke dalam tumpukan maksimum (max heap), menghasilkan 40 30 35 20 25. Elemen 40 memiliki prioritas tertinggi (nilai terbesar).

- Ekstrak Maksimum: Kode mengekstrak elemen dengan prioritas tertinggi (40) dan mencetaknya.

- Antrian Prioritas Setelah Ekstraksi: Elemen yang tersisa dalam tumpukan adalah 35 30 25 20.

- Ubah Prioritas: Kode mengubah prioritas elemen pada indeks 2 (yang nilainya 25) menjadi 49. Ini secara efektif memindahkan 49 ke atas tumpukan karena sekarang memiliki prioritas tertinggi.

- Antrian Prioritas Setelah Perubahan: Tumpukan sekarang menjadi 49 30 35 20.

- Hapus Elemen: Kode menghapus elemen pada indeks 3 (yang nilainya 20).

- Antrian Prioritas Setelah Penghapusan: Tumpukan terakhir adalah 49 30 35.


## Kesimpulan
Kesimpulan dari Priority Queue adalah struktur data khusus yang memungkinkan kita menyimpan elemen-elemen dengan nilai prioritas tertentu. Konsep dasar Priority Queue mirip dengan antrian biasa, namun perbedaannya adalah setiap elemen dalam Priority Queue memiliki nilai prioritas yang menentukan urutan elemen saat diambil. Elemen dengan nilai prioritas tertinggi akan diambil terlebih dahulu, bukan elemen yang paling lama berada dalam antrian. Priority Queue adalah konsep penting dalam algoritma yang membantu kita mengelola dan mengatur data dengan nilai prioritas tertentu. Implementasinya dalam struktur data seperti heap atau binary search tree memungkinkan operasi penyisipan dan penghapusan elemen dalam waktu logaritmik, yang sangat berguna dalam berbagai algoritma. Dengan pemahaman tentang Priority Queue, kita dapat meningkatkan efisiensi dan efektivitas algoritma yang kita gunakan dalam menyelesaikan masalah.

## Referensi
[1] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.

[2]  T. Cormen, C. Leiserson, R. Rivest, and C. Stein. Introduction to Algorithms, 2nd edition. MIT Press
and McGraw-Hill Book Company, 2001.

[3] Goodrich, Tamassia, Mount. Data Structure
and Algorithms in C++, Wiley, 2020.