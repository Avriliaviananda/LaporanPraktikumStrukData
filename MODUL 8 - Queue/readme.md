# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

Queue

Queue atau antrian adalah suatu kumpulan data yang 
penambahan elemennya hanya bisa dilakukan pada suatu 
ujung (disebut dengan sisi belakang atau rear), dan 
penghapusan atau pengambilan elemen dilakukan lewat 
ujung yang lain (disebut dengan sisi depan atau front). 
Kalau tumpukan dikenal dengan menggunakan prinsip LIFO 
(Last In First Out), maka pada antrian prinsip yang 
digunakan adalah FIFO (First In First Out). [1]

Operasi / Prosedur Standar pada Queue / Antrian

QUEUE merupakan struktur data dinamis, ketika 
program dijalankan, jumlah elemennya dapat berubah secara 
dinamis sesuai keperluan. Berikut ini operasi-operasi standar 
pada queue : [1]

a. Inisialisasi, merupakan prosedur untuk membuat queue 
pada kondisi awal, yaitu queue yang masih kosong 
(belum mempunyai elemen). [1]

b. InQueue, Insert Queue merupakan prosedur untuk 
memasukkan sebuah elemen baru pada queue. Jumlah 
elemen Queue akan bertambah satu dan elemen tersebut 
merupakan elemen belakang. [1]
70 

c. DeQueue, Delete Queue merupakan prosedur untuk 
menghapus/mengambil sebuah elemen dari queue. 
Elemen yang diambil adalah elemen depan dan jumlah 
elemen queue akan berkurang satu.[1]

Operasi yang terkait dengan antrian adalah: [2]

a. Enqueue: Menambahkan item ke antrian. Jika antrian penuh, maka dikatakan sebagai kondisi Overflow – Kompleksitas Waktu: O (1) [2]

b. Dequeue: Menghapus item dari antrian. Item yang muncul dalam urutan yang sama di mana mereka didorong. Jika antrian kosong, maka dikatakan sebagai kondisi Underflow – Kompleksitas Waktu: O (1) [2]

c. Depan: Dapatkan item depan dari antrian – Kompleksitas Waktu: O (1)

d. Belakang: Dapatkan item terakhir dari antrian – Kompleksitas Waktu: O (1)

![image](https://github.com/Avriliaviananda/Struktur-Data-Teori/assets/161323061/e6665ddf-e8fb-488e-8ae7-e1b8d7b2397b)

Pada saat menempatkan elemen pada ujung (tail) dari queue disebut dengan enqueue . Pada saat memindahkan elemen dari kepala (head) ke dalam queue disebut dengan dequeue.. Karakteristik penting dari queue adalah: [3]

a. Element antrian yaitu item-item data yang terdapat di elemen antrian

b. Front (element terdepan di antrian)

c. Rear (element terakhir di antrian)

d. Jumlah elemen pada antrian (Count)

e. Status antrian


## Guided 

### 1. Guided

```cpp
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}

```
#### Output:
![Screenshot 2024-05-08 111226](https://github.com/Avriliaviananda/Struktur-Data-Teori/assets/161323061/fab80762-76bb-4d0a-9ba8-47de4328b2a4)


#### Full code Screenshot:
![Screenshot (313)](https://github.com/Avriliaviananda/Struktur-Data-Teori/assets/161323061/8045521b-34d7-4ddf-8b77-0d76f10264b1)


Program ini terdapat beberapa operasi seperti menambahkan data ke stack, menghapus data dari stack, melihat elemen teratas, menghitung jumlah elemen, mengubah nilai elemen pada posisi tertentu, dan menghapus stack.

penjelasan output:

-Data di stack: Program menampilkan semua judul buku yang telah ditambahkan ke stack, yaitu "Kalkulus", "Struktur Data", "Matematika Diskrit", "Dasar Multimedia", dan "Inggris".

-Pemeriksaan penuh dan kosong stack: Program memeriksa apakah stack penuh dan kosong. Pada awalnya, stack tidak penuh dan tidak kosong, sehingga outputnya adalah 1 untuk penuh dan 0 untuk kosong.

-Melihat elemen ke-2: Program menampilkan elemen ke-2 dari atas stack, yaitu "Matematika Diskrit".

-Menghapus elemen: Program mencoba menghapus elemen dari stack, tetapi karena stack tidak kosong, program mencetak pesan "Tidak ada data yang dihapus".

-Menghitung jumlah elemen: Program menghitung jumlah elemen di stack, yaitu 4.

-Mengubah nilai elemen ke-2: Program mengubah nilai elemen ke-2 dari "Matematika Diskrit" menjadi "Bahasa Jerman".

-Mencetak stack setelah perubahan: Program mencetak semua elemen di stack setelah perubahan, yaitu "Kalkulus", "Struktur Data", "Bahasa Jerman", "Dasar Multimedia".

-Menghapus stack: Program menghapus semua elemen dari stack dan mengembalikan indeks top ke nol.

-Mencetak stack setelah dihapus: Program mencetak stack setelah dihapus, tetapi karena stack kosong, program mencetak pesan "Tidak ada data yang dicetak".


## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.


```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome(string input) {
    stack<char> s;
    int len = input.length();

    for (int i = 0; i < len; i++) {
        s.push(input[i]);
    }

    for (int i = 0; i < len; i++) {
        if (s.top() != input[i]) {
            return false;
        }
        s.pop();
    }

    return true;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << input << " adalah palindrome." << endl;
    } else {
        cout << input << " bukan palindrome." << endl;
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-05-04 135231](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/5d0b36b3-b864-465e-9e3b-8a3e4d6ee049) 

![Screenshot 2024-05-04 135238](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/62e0b531-55f5-40cb-b6be-dc007e9e9a19)


#### Full code Screenshot:
![Screenshot (310)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/8b2824e1-0b52-45bc-a2d9-8f95a7a50c78)


Fungsi isPalindrome:

Parameter: 'input' adalah kalimat yang diinputkan.
Fungsi ini menggunakan stack s untuk menyimpan karakter-karakter dari input.
Setelah semua karakter input dimasukkan ke stack, program memeriksa apakah setiap karakter dari depan dan belakang sama atau tidak.
Jika ada karakter yang tidak sama, fungsi akan segera mengembalikan false dan program akan menyadari bahwa input bukan palindrom.
Jika semua karakter dari depan dan belakang sama, fungsi akan mengembalikan true dan program akan menyadari bahwa input adalah palindrom.

pada contoh output diatas masukkan kata 'aku' maka program akan mencetak kalimat bukan palindrom e karena karakter dari depan sampai belakang tidak ada yang memiliki karakter yang sama. sedangkan contoh kalimat kedua memasukkan kata 'ana' maka program akan mencetak kalimat tersebut adalah palindrome karena karakter dari depan sampai belakang ada karakter yang sama yaitu karakter 'a'.

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```cpp
#include <iostream>

using namespace std;

struct Node {
  string nama;  // Nama mahasiswa
  string nim;   // NIM mahasiswa
  Node* next;  // Penunjuk ke node selanjutnya
};

Node* front = NULL;  // Penunjuk node terdepan (awal) antrian
Node* back = NULL;   // Penunjuk node terakhir (akhir) antrian

bool isFull() {
    return false;
}

bool isEmpty() {
  // Memeriksa apakah antrian kosong (kedua penunjuk NULL)
  if (front == NULL && back == NULL) {
    return true;
  } else {
    return false;
  }
}

void enqueueAntrian(string nama, string nim) {
  // Buat node baru untuk mahasiswa
  Node* newNode = new Node();
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->next = NULL;

  // Periksa jika antrian penuh (kondisi ini tidak pernah terpenuhi)
  if (isFull()) {
    cout << "Antrian Penuh" << endl;
  } else {
    // Jika antrian kosong (kedua penunjuk sama dengan node baru)
    if (isEmpty()) {
      front = newNode;
      back = newNode;
    } else {
      // Tambahkan node baru ke akhir antrian (back->next)
      back->next = newNode;
      // Perbarui penunjuk back ke node baru (node terakhir)
      back = newNode;
    }
  }
}

void dequeueAntrian() {
  // Periksa jika antrian kosong
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    // Simpan node terdepan sementara
    Node* temp = front;
    // Geser front ke node selanjutnya
    front = front->next;
    // Hapus node terdepan yang sudah dikeluarkan
    delete temp;

    if (front == NULL) {
      back = NULL;
    }
  }
}

int countQueue() {
  int count = 0;
  Node* current = front;

  // Hitung jumlah node dengan menelusuri antrian
  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

void clearQueue() {
  // Periksa jika antrian kosong
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
  } else {
    // Hapus semua node satu per satu sambil menelusuri antrian
    Node* current = front;
    while (current != NULL) {
      Node* temp = current;
      current = current->next;
      delete temp;
    }
    // Setel kedua penunjuk ke NULL karena antrian sudah kosong
    front = NULL;
    back = NULL;
  }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Data antrian mahasiswa: " << endl;
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Data antrian mahasiswa: " << endl;
        Node* current = front;
        int i = 1;
        while (current != NULL) {
            cout << i << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            i++;
        }
    }
}

int main() {
    enqueueAntrian("Andi", "12345678");
    enqueueAntrian("Maya", "23456789");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
#### Output:
![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/1299daf7-a0bd-4474-af4a-2add9e4d33c3)


#### Full code Screenshot:
![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/9e67a13c-ff72-43b1-8df3-e46c5fe6d5fe)

Program ini menunjukkan antrian mahasiswa dengan menggunakan struktur data Node. 

Fungsi-fungsi yang diimplementasikan:

enqueueAntrian: Menambahkan mahasiswa baru ke antrian.

dequeueAntrian: Mengeluarkan mahasiswa terdepan dari antrian.

viewQueue: Menampilkan data semua mahasiswa dalam antrian.

countQueue: Menghitung jumlah mahasiswa dalam antrian.

clearQueue: Menghapus semua mahasiswa dari antrian.

Pada output, kita dapat melihat bagaimana mahasiswa ditambahkan, dikeluarkan, dan dihitung jumlahnya dalam antrian. Program ini menunjukkan cara sederhana untuk mengelola data mahasiswa dengan menggunakan struktur data antrian.

Penjelasan Output
1. Enqueue 2 Mahasiswa:

Andi dengan NIM 12345678 ditambahkan ke antrian.

Maya dengan NIM 23456789 ditambahkan ke antrian.

2. Menampilkan Antrian dan Menghitung Jumlah:

Data antrian mahasiswa ditampilkan:

Andi dengan NIM 12345678 pada urutan 1.

Maya dengan NIM 23456789 pada urutan 2.

Jumlah antrian adalah 2.

3. Dequeue 1 Mahasiswa:

Mahasiswa terdepan (Andi) dikeluarkan dari antrian.

4. Menampilkan Antrian dan Menghitung Jumlah:

Data antrian mahasiswa ditampilkan:

Maya dengan NIM 23456789 pada urutan 1.

Jumlah antrian adalah 1.

5. Clear Queue:

Semua node dalam antrian dihapus.

6. Menampilkan Antrian dan Menghitung Jumlah:

Data antrian mahasiswa ditampilkan:

Antrian kosong.

Jumlah antrian adalah 0.


## Kesimpulan
Kesimpulan dari Queue (antrian) adalah salah satu list linier dari struktur data yang beroperasi dengan cara First In First Out (FIFO) yaitu elemen pertama yang masuk merupakan elemen yang pertama keluar. Data-data di dalam antrian dapat bertipe integer, real, record dalam bentuk sederhana atau terstruktur. Queue dilakukan dengan cara penyisipan di satu ujung, sedang penghapusan di ujung lain. Ujung penyisipan biasa disebut rear/tail, sedang ujung penghapusa disebut front/head. 
Sebuah queue dalam program setidaknya harus mengandung tiga variabel, yakni: head untuk penanda bagian depan antrian, tail unttuk penanda bagian belakang antrian, dan array data untuk menyimpan data-data yang dimasukkan ke dalam queue tersebut.
Pada queue ada operasi – operasi dasar, yaitu: prosedur create untuk membuat queue baru yang kosog, fungsi IsEmpty untuk mengecek queue tersebut kosong atau tidak, fungsi IsFull untuk mengecek queue tersebut penuh atau tidak, prosedur EnQueue untuk memasukkan data kedalam queue, prosedur DeQueue untuk mengeluarkan sebuah elemen pada posisi head dari queue, fungsi clear untuk menghapus elemen queue, dan prosedur tampil untuk menampilakn elemen yang ada pada queue.

## Referensi
[1] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.

[2] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[3] Meidyan Permata Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung : Widina Bhakti Persada Bandung, 2022.
.