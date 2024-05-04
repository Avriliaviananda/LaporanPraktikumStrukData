# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

Stack

Stack (tumpukan) adalah struktur data yang 
memungkinkan penyisipan dan pengambilan data dilakukan 
dari satu ujung yang disebut puncak. Sesuai namanya, 
struktur data ini digambarkan seperti keadaan tumpukan 
piring atau tumpukan buku. Cara yang paling mudah untuk 
meletakkan piring ke dalam tumpukan yakni dengan 
menaruhnya dibagian puncak. Begitu juga kalau ingin 
mengambil piring. Piring diambil dari data yangberada di 
puncak tumpukan. Penyimpanan data/item dimana data/item 
yang diakses adalah paling akhir yang disebut top of stack. 
Item ditempatkan membentuk tumpukan. [1]

Tumpukan memiliki sifat Last In First Out (LIFO). 
Artinya, data yang terakhir kali dimasukkan/disisipkan akan 
menjadi data yang pertama kali keluar. Pada contoh di atas, 
yang berisi tumpukan A, B, dan C jelas terlihat bahwa C 
adalah data yang terakhir kali ditumpukkan. Jika terjadi 
operasi pengambilan data maka C adalah data yang akan 
keluar terlebih dulu. [1]


![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/05ed8b4a-1ed0-4f12-bdae-f1786e49f1bb)


Operasi-operasi/fungsi Stack :

• Push : digunakan untuk menambah item pada stack pada
tumpukan paling atas

• Pop : digunakan untuk mengambil item pada stack pada 
tumpukan paling atas

• Clear : digunakan untuk mengosongkan stack

• IsEmpty : fungsi yang digunakan untuk mengecek 
apakah stack sudah kosong

• IsFull : fungsi yang digunakan untuk mengecek apakah 
stack sudah penuh [2]

Operasi dasar pada tumpukan adalah PUSH dan POP.

a. PUSH adalah operasi untuk memasukkan data ke dalam 
tumpukan. Operasi ini biasa dinyatakan dengan 
push(T,d). T menyatakan tumpukan dan d menyatakan 
item data yang disisipkan ke dalam tumpukan T.[3]

b. POP adalah operasi untuk mengambil data dari 
tumpukan. Operasi ini biasa dinyatakan dengan pop(T). 
Dalam hal ini data teratas dari tumpukan T akan 
dikeluarkan dan menjadi nilai balik pop. Itulah sebabnya penggunaan pop sering dituangkan dalam bentuk 
pernyataan : data = pop (T);[3]


## Guided 

### 1. Guided

```cpp
#include <iostream>

using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    }
    
    else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] == "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dihapus" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }

        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countstack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top; i > 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang 70 dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh?" << isFull() << endl;
    cout << "Apakah data stack kosong?" << isEmpty << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data = " << countstack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus:" << top << endl;
    cetakArrayBuku();
    return 0;
}


```
#### Output:
![Screenshot 2024-05-03 215517](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/bdb17217-bec4-41d3-978a-dbc336ae59e4)


#### Full code Screenshot:
![Screenshot (307)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/b88f0b21-9279-43be-b76b-ac9f2995fd9e)


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

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```cpp
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {
  // Deklarasi variabel untuk menyimpan kalimat
  string kalimat;

  // input kalimat
  cout << "Masukkan kalimat minimal 3: ";
  getline(cin, kalimat);

  // Deklarasi stack untuk menyimpan kata-kata
  stack<string> s;

  // Memisahkan kata-kata dalam kalimat dan menambahkannya ke stack
  stringstream ss(kalimat);
  string kata;
  while (getline(ss, kata, ' ')) {
    // Membalikkan huruf dalam kata
    stack<char> s_kata;
    for (char c : kata) {
      s_kata.push(c);
    }
    string kata_terbalik;
    while (!s_kata.empty()) {
      kata_terbalik += s_kata.top();
      s_kata.pop();
    }
    // Menambahkan kata yang telah dibalik ke stack kata-kata
    s.push(kata_terbalik);
  }

  // Membalikkan kalimat dengan mengeluarkan kata dari stack
  string kalimat_terbalik;
  while (!s.empty()) {
    kalimat_terbalik += s.top() + " ";
    s.pop();
  }

  // Memotong spasi di akhir kalimat yang dibalik
  kalimat_terbalik.erase(kalimat_terbalik.size() - 1);

  // Menampilkan kalimat yang telah dibalik
  cout << "Kalimat yang dibalik: " << kalimat_terbalik << endl;

  return 0;
}

```
#### Output:
![Screenshot 2024-05-03 215717](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/4f8c872d-69cf-4ed3-bc53-1ac2d0adbbd7)


#### Full code Screenshot:
![Screenshot (309)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/068a87af-d74c-41cf-9ac3-e8a82b3acbc5)




Program ini untuk memasukkan kalimat minimal 3 kata. Kemudian, program akan membalikkan urutan kata dalam kalimat tersebut dan menampilkan kalimat yang telah dibalik. Setelah semua karakter kalimat dimasukkan ke dalam stack, program akan mengeluarkan karakter dari stack satu per satu dan membangun kalimat terbalik. Kalimat terbalik ini kemudian ditampilkan kepada pengguna.
Penjelasan Source Code:

1. Deklarasi Variabel:

string kalimat;: Deklarasi variabel string kalimat untuk menyimpan kalimat yang dimasukkan oleh pengguna.
stack<string> s;: Deklarasi stack s untuk menyimpan kata-kata yang akan dibalik.

2. Meminta Input Kalimat:

cout << "Masukkan kalimat minimal 3: ";: Menampilkan pesan di konsol untuk meminta pengguna memasukkan kalimat minimal 3 kata.
getline(cin, kalimat);: Membaca input dari konsol dan menyimpannya dalam variabel kalimat.

3. Memisahkan Kata-kata dan Membalikkan Huruf:

stringstream ss(kalimat);: Membuat objek stringstream dari variabel kalimat.

string kata;: Deklarasi variabel string kata untuk menyimpan kata yang sedang diproses.

while (getline(ss, kata, ' ')): Perulangan untuk membaca setiap kata dalam kalimat.

getline(ss, kata, ' '): Membaca kata dari stringstream dan menyimpannya dalam variabel kata.
' ': Karakter spasi digunakan sebagai delimiter untuk memisahkan kata-kata.

stack<char> s_kata;: Deklarasi stack s_kata untuk menyimpan huruf-huruf dalam kata yang sedang diproses.

for (char c : kata) { s_kata.push(c); }: Perulangan untuk memasukkan setiap huruf dalam kata ke dalam stack s_kata.

string kata_terbalik;: Deklarasi variabel string kata_terbalik untuk menyimpan kata yang telah dibalik.

while (!s_kata.empty()) { kata_terbalik += s_kata.top(); s_kata.pop(); }: Perulangan untuk mengeluarkan huruf dari stack s_kata dan membangun kata yang dibalik.

!s_kata.empty(): Memeriksa apakah stack s_kata kosong.

kata_terbalik += s_kata.top();: Menambahkan huruf di atas stack s_kata ke string kata_terbalik.

s_kata.pop();: Mengeluarkan huruf di atas stack s_kata.

s.push(kata_terbalik);: Menambahkan kata yang telah dibalik ke stack s.

4. Membalikkan Kalimat:

string kalimat_terbalik;: Deklarasi variabel string kalimat_terbalik untuk menyimpan kalimat yang telah dibalik.

while (!s.empty()) { kalimat_terbalik += s.top() + " "; s.pop(); }: Perulangan untuk mengeluarkan kata dari stack s dan membangun kalimat yang dibalik.

!s.empty(): Memeriksa apakah stack s kosong.

kalimat_terbalik += s.top() + " ";: Menambahkan kata di atas stack s ke string kalimat_terbalik dengan menambahkan spasi di antara kata-kata.

s.pop();: Mengeluarkan kata di atas stack s.

5. Memotong Spasi di Akhir Kalimat:

kalimat_terbalik.erase(kalimat_terbalik.size() - 1);: Menghapus spasi di akhir kalimat yang dibalik.

6. Menampilkan Kalimat yang Telah Dibalik:

cout << "Kalimat yang dibalik: " << kalimat_terbalik << endl;: Menampilkan kalimat yang telah dibalik di konsol.

Operasi/Fungsi yang Digunakan:

push(x): Menambahkan elemen x ke atas stack.
pop(): Menghapus dan mengembalikan elemen dari atas stack.
empty(): Memeriksa apakah stack kosong.
size(): Mengembalikan jumlah elemen dalam stack.
getline(cin, s): Membaca input dari konsol ke dalam string s.
getline(ss, s, d): Membaca kata dari


## Kesimpulan
Kesimpulan dari Stack adalah suatu koleksi atau kumpulan item data yang terorganisasi dalam bentuk urutan linier, yang operasi pemasukan dan penghapusan datanya dilakukan pada salah satu sisinya. Pada stack, jarang dilakukan traversal, karena keunikan stack justru pada operasi yang hanya menyangkut elemen TOP. Namun dibutuhkan traversal misalnya untuk mencetak isi stack. Pada stack, elemen yang diproses hanya elemen pada TOP. Maka hampir tidak pernah dilakukan search atau bersifat LIFO (Last In First Out). 

Operasi-operasi pada Stack :
Create(Stack)Operasi Create(Stack) digunakan untuk membuat suatu stack baru dengan nama stack, yang nilai elemen saat stack tersebut dibuat adalah NOEL(S) = 0, TOP(S) = NULL (tidak terdefinisikan).IsEmpty(Stack)Operasi ini merupakan operasi untuk mencek isi dari suatu stack dalam keadaan kosong atau berisi.
Operasi ini memiliki kondisi boolean yaitu :
True jika stack tersebut kosong atau dapat dikatakan NOEL(S) = 0.
False jika stack tersebut tidak dalam kondisi kosong atau dapat dikatakan NOEL(S)
Push(Stack, Elemen)

## Referensi
[1] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.

[2] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[3] Meidyan Permata Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung : Widina Bhakti Persada Bandung, 2022.
Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.