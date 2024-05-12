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


Kodingan di atas adalah implementasi dari antrian (queue) menggunakan array statis di bahasa C++. Di dalam kodingan tersebut, terdapat sebuah array queueTeller dengan ukuran maksimal 5 elemen. Array ini digunakan untuk menyimpan elemen antrian.

Fungsi isFull() digunakan untuk memeriksa apakah antrian sudah penuh atau belum. Jika back sama dengan maksimalQueue, maka antrian sudah penuh dan fungsi akan mengembalikan nilai true. Jika tidak, fungsi akan mengembalikan nilai false.

Fungsi isEmpty() digunakan untuk memeriksa apakah antrian kosong atau tidak. Jika back sama dengan 0, maka antrian kosong dan fungsi akan mengembalikan nilai true. Jika tidak, fungsi akan mengembalikan nilai false.

Fungsi enqueueAntrian(string data) digunakan untuk menambahkan elemen ke antrian. Elemen baru akan ditambahkan ke posisi back dari array queueTeller. Jika antrian sudah penuh, fungsi akan mencetak pesan "Antrian Penuh". Jika antrian kosong, elemen baru akan ditambahkan ke posisi 0 dari array queueTeller.

Fungsi dequeueAntrian() digunakan untuk menghapus elemen pertama dari antrian. Jika antrian kosong, fungsi akan mencetak pesan "Antrian kosong". Jika antrian tidak kosong, elemen pertama akan dihapus dan semua elemen lainnya akan digeser ke posisi sebelumnya.

Fungsi countQueue() digunakan untuk menghitung jumlah elemen yang ada di antrian. Fungsi clearQueue() digunakan untuk menghapus semua elemen dari antrian. Jika antrian kosong, fungsi akan mencetak pesan "Antrian kosong". Jika antrian tidak kosong, semua elemen akan dihapus dan di-set ke string kosong.

Fungsi viewQueue() digunakan untuk menampilkan semua elemen yang ada di antrian. Jika antrian kosong, fungsi akan mencetak pesan "Antrian kosong". Jika antrian tidak kosong, semua elemen akan ditampilkan dengan nomor urut.

Di dalam fungsi main(), terdapat beberapa contoh penggunaan fungsi-fungsi yang telah dijelaskan sebelumnya. Elemen "Andi" dan "Maya" ditambahkan ke antrian, kemudian antrian ditampilkan dan dihitung jumlahnya. Elemen pertama dihapus dari antrian, kemudian antrian ditampilkan dan dihitung jumlahnya lagi. Semua elemen dihapus dari antrian, kemudian antrian ditampilkan dan dihitung jumlahnya lagi.

## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list


```cpp
#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = NULL;
Node* back = NULL;

bool isFull() {
    return false;
}

bool isEmpty() {
    if (front == NULL && back == NULL) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* current = front;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        front = NULL;
        back = NULL;
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Data antrian teller: " << endl;
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Data antrian teller: " << endl;
        Node* current = front;
        int i = 1;
        while (current != NULL) {
            cout << i << ". " << current->data << endl;
            current = current->next;
            i++;
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
![Screenshot 2024-05-12 201028](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/c5bf10ba-632b-4ede-8901-7e6555ef84b3)



#### Full code Screenshot:
![Screenshot (316)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/8a48fd8b-51b7-438a-b3ca-0edc54c42c26)


Kodingan di atas adalah implementasi dari antrian (queue) menggunakan linked list di bahasa C++. Di dalam kodingan tersebut, terdapat sebuah struktur data Node yang digunakan untuk menyimpan elemen antrian. Setiap elemen antrian terdiri dari data (string) dan pointer ke elemen berikutnya. hampir sama seperti guided tetapi disini menggunakan linked list, Linked List adalah sebuah struktur data yang terdiri dari elemen-elemen yang disimpan dalam memori secara tidak berurutan. Setiap elemen memiliki pointer ke elemen berikutnya, sehingga elemen-elemen dapat diakses melalui pointer. Pada linked list, terdapat struct, struct digunakan untuk mendefinisikan tipe data yang akan digunakan untuk menyimpan data dan pointer ke elemen berikutnya. Struct memungkinkan kita untuk menggabungkan beberapa tipe data dalam satu tipe data baru.

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