# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

Hash Table

Hash Table adalah sebuah struktur data yang terdiri atas sebuah tabel dan fungsi yang bertujuan untuk memetakan nilai kunci yang unik untuk setiap record (baris) menjadi angka (hash) lokasi record tersebut dalam sebuah tabel. Keunggulan dari struktur hash [1]

table ini adalah waktu aksesnya yang cukup cepat, jika record yang dicari langsung berada pada angka hash lokasi penyimpanannya. Akan tetapi pada kenyataannya sering sekali ditemukan hash table yang record-recordnya mempunyai angka hash yang sama (bertabrakan). Karena pemetaan hash function yang digunakan bukanlah pemetaan satusatu, (antara dua record yang tidak sama dapat dibangkitkan angka hash yang sama) maka dapat terjadi bentrokan (collision) dalam penempatan suatu data record. Untuk mengatasi hal ini, maka perlu diterapkan kebijakan resolusi bentrokan (collision resolution policy) untuk menentukan lokasi record dalam tabel. Umumnya kebijakan resolusi bentrokan adalah dengan mencari lokasi tabel yang masih kosong pada lokasi setelah lokasi yang berbentrokan. [1]

Fungsi hash adalah fungsi yang memetakan kunci ke salah satu nilai dalam tabel hash. Fungsi hash mengembalikan lokasi/alamat dimana kita dapat menyimpan kunci tertentu. Kami memasukkan kunci ke fungsi hash dan outputnya adalah alamat. Diagram berikut menggambarkan cara fungsi hash beroperasi:

Misalnya, fungsi hash yang mungkin bisa jadi

h(k) = k mod m

Dimana h(k) menunjukkan fungsi hash, m menunjukkan ukuran tabel hash dan k menunjukkan kunci atau nilai.[3]

![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/9443bc05-0d04-4671-8bb2-766bff460dac)

Tabel hash adalah struktur data yang menggunakan pasangan nilai kunci untuk menyimpan data secara asosiatif. Kunci dipetakan ke indeks masing-masing dalam array menggunakan fungsi hash, dan nilainya kemudian ditempatkan dalam array. Fungsi hash menerima kunci sebagai masukan dan mengembalikan indeks dalam array tempat nilainya dapat ditemukan. Tabel hash sering digunakan untuk membuat tabel pencarian, array asosiatif, dan kumpulan dinamis karena tabel ini menawarkan operasi pencarian, penyisipan, dan penghapusan kasus rata-rata dengan waktu konstan. [4]

Operasi dasar pada fungsi hash:
Operasi dasar yang dapat kita lakukan pada fungsi hash adalah:
1. Search: Operasi ini membantu mencari elemen dari tabel hash.
2. Insert: Operasi penyisipan digunakan untuk memasukkan nilai ke dalam tabel hash.
3. Delete: Digunakan untuk menghapus nilai dari tabel hash. [2]



## Guided 

### 1. Guided 1

```cpp
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}

```
#### Output:
![Screenshot 2024-06-01 104352](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/43ce554c-6a2d-43db-aa31-90dc83b84d37)


#### Full code Screenshot:
![Screenshot (327)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/b19d48ba-953e-44da-a75d-838745675a5f)

program ini adalah untuk memberikan pemahaman tentang cara kerja hash table dengan chaining serta menunjukkan bagaimana operasi-operasi dasar pada hash table dapat dilakukan menggunakan implementasi sederhana seperti yang ditunjukkan dalam program tersebut.

Penjelasan Output:

- Pertama, tiga elemen dimasukkan ke dalam tabel hash dengan insert: (1, 10), (2, 20), dan (3, 30).
- Kemudian, nilai yang dikembalikan untuk kunci 1 dan 4 dicetak menggunakan get. Karena hanya kunci 1 yang ada dalam tabel, nilai yang dikembalikan untuk kunci 4 akan -1.
- Selanjutnya, elemen dengan kunci 4 dihapus menggunakan remove. Namun, karena kunci 4 tidak ada dalam tabel, tidak ada yang dihapus.
- Terakhir, seluruh isi tabel hash dicetak menggunakan traverse.

### 2. Guided 2

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}

```
#### Output:
![Screenshot 2024-06-01 104424](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/0f01dd3c-3740-43ed-b098-ad767dca2655)


#### Full code Screenshot:
![Screenshot (328)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/7c99f4f6-829b-4585-b35b-d61cc6965755) 

Dalam program di atas, kita memanggil fungsi functionA dengan argumen 5, dan program akan mencetak angka-angka dari 5 hingga 1 dengan menggunakan rekursi tidak langsung. functionA dan functionB saling memanggil secara tidak langsung. functionA memanggil functionB, yang kemudian memanggil functionA lagi dengan nilai yang diubah. Ini berbeda dari rekursi langsung di mana fungsi memanggil dirinya sendiri secara langsung.

## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : (a) Setiap mahasiswa memiliki NIM dan nilai. (b)	Program memiliki tampilan pilihan menu berisi poin C. (c)	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

//menyimpan data mahasiswa
struct Mahasiswa {
  string NIM;
  int nilai;
};

//untuk mengelola hash table
class HashTable {
private:
  int size;
  vector<list<Mahasiswa>> table;

public:
  HashTable(int size) : size(size) {
    table.resize(size);
  }

  //menghitung hash value untuk string NIM yang diberikan
  int hashFunction(string NIM) {
    int sum = 0;
    for (char c : NIM) {
      sum += c;
    }
    return sum % size;
  }
  
  //menambahkan objek Mahasiswa baru ke hash table
  void insertMahasiswa(Mahasiswa mahasiswa) {
    int index = hashFunction(mahasiswa.NIM);
    table[index].push_back(mahasiswa);
  }
  
  //menghapus objek Mahasiswa dari hash table berdasarkan NIM
  void deleteMahasiswa(string NIM) {
    int index = hashFunction(NIM);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
      if (it->NIM == NIM) {
        table[index].erase(it);
        cout << "Data mahasiswa dengan NIM " << NIM << " telah dihapus." << endl;
        return;
      }
    }
    cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
  }
  
  //mencari objek Mahasiswa dalam hash table berdasarkan NIM
  Mahasiswa* findMahasiswaByNIM(string NIM) {
    int index = hashFunction(NIM);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
      if (it->NIM == NIM) {
        return &(*it);
      }
    }
    return nullptr;
  }

  //mencari objek Mahasiswa dalam hash table berdasarkan rentang nilai
  void findMahasiswaByNilai(int nilaiAwal, int nilaiAkhir) {
    for (int i = 0; i < size; ++i) {
      for (auto it = table[i].begin(); it != table[i].end(); ++it) {
        if (it->nilai >= nilaiAwal && it->nilai <= nilaiAkhir) {
          cout << "NIM: " << it->NIM << ", Nilai: " << it->nilai << endl;
        }
      }
    }
  }
  
  //menampilkan semua data mahasiswa dalam hash table
  void display() {
    for (int i = 0; i < size; ++i) {
      cout << "Index " << i << ":" << endl;
      for (auto it = table[i].begin(); it != table[i].end(); ++it) {
        cout << "NIM: " << it->NIM << ", Nilai: " << it->nilai << endl;
      }
    }
  }
};

int main() {
  HashTable hashTable(10);

  int pilihan;
  do {
    cout << "Menu:" << endl;
    cout << "1. Tambahkan data mahasiswa" << endl;
    cout << "2. Hapus data mahasiswa" << endl;
    cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai " << endl;
    cout << "5. Tampilkan semua data" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1: {
        Mahasiswa mahasiswa;
        cout << "Masukkan NIM: ";
        cin >> mahasiswa.NIM;
        cout << "Masukkan nilai: ";
        cin >> mahasiswa.nilai;
        hashTable.insertMahasiswa(mahasiswa);
        break;
      }
      case 2: {
        string NIM;
        cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
        cin >> NIM;
        hashTable.deleteMahasiswa(NIM);
        break;
      }
      case 3: {
        string NIM;
        cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
        cin >> NIM;
        Mahasiswa* mahasiswa = hashTable.findMahasiswaByNIM(NIM);
        if (mahasiswa != nullptr) {
          cout << "NIM: " << mahasiswa->NIM << ", Nilai: " << mahasiswa->nilai << endl;
        } else {
          cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
        }
        break;
      }
      case 4: {
        int nilaiAwal, nilaiAkhir;
        cout << "Masukkan rentang nilai: ";
        cin >> nilaiAwal >> nilaiAkhir;
        hashTable.findMahasiswaByNilai(nilaiAwal, nilaiAkhir);
        break;
      }
      case 5: {
        hashTable.display();
        break;
      }
      case 6: {
        cout << "Keluar dari program." << endl;
        break;
      }
      default: {
        cout << "Pilihan tidak valid." << endl;
        break;
      }
    }
  } while (pilihan != 6);

  return 0;
}


```
#### Output:

![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/61faabbc-d17f-40ba-bbe0-6cbe0aa4cd59)


![Screenshot 2024-06-03 194844](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/074cebca-b54c-4011-a6b1-d59b72de2205)

![Screenshot 2024-06-03 194916](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/71a7dc90-dad9-48f0-a197-8fd468f98d7d)

![Screenshot 2024-06-03 194949](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/ab3d6979-7423-4bab-88d9-1adeac02d4cd)

![Screenshot 2024-06-03 195021](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/90f4ffad-b29a-4b84-a508-0daabe3c3390)


#### Full code Screenshot:
![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/e7aa288a-7a99-4b96-b471-6062a56234e5)

penjelasan fungsi:

- Struktur data Mahasiswa: Menyimpan informasi tentang seorang mahasiswa, termasuk NIM dan nilainya.
- Kelas HashTable: Mengelola hash table, termasuk menambahkan, menghapus, mencari, dan menampilkan data mahasiswa.
- hashFunction(NIM): Menghitung nilai hash untuk NIM yang diberikan.
- insertMahasiswa(mahasiswa): Menambahkan objek Mahasiswa baru ke hash table.
- deleteMahasiswa(NIM): Menghapus objek Mahasiswa dari hash table berdasarkan NIM.
- findMahasiswaByNIM(NIM): Mencari objek Mahasiswa dalam hash table berdasarkan NIM.
- findMahasiswaByNilai(nilaiAwal, nilaiAkhir): Mencari objek Mahasiswa dalam hash table berdasarkan rentang nilai.
- display(): Menampilkan semua data mahasiswa dalam hash table.

Penjelasan Output:

Program C++ di atas adalah implementasi hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Output menampilkan data untuk setiap mahasiswa di dalam hash table, yang diurutkan berdasarkan indeks. Untuk setiap indeks, program menampilkan NIM dan nilai mahasiswa yang tersimpan di linked list tersebut.


## Kesimpulan
Kesimpulan dari hash table adalah transformasi aritmatik sebuah string dari karakter menjadi nilai yang merepresentasikan string aslinya. Menurut bahasanya, hash berarti memenggal dan kemudian menggabungkan. Hash table digunakan sebagai metode untuk menyimpan data dalam sebuah array agar penyimpanan data, pencarian data, penambahan data, dan penghapusan data dapat dilakukan dengan cepat. Ide dasarnya adalah menghitung posisi record yang dicari dalam array, bukan membandingkan record dengan isi pada array. Fungsi yang mengembalikan nilai atau kunci disebut fungsi hash (hash function) dan array yang digunakan disebut tabel hash (hash table). Hash table menggunakan struktur data array asosiatif yang mengasosiasikan record dengan sebuah field kunci unik berupa bilangan (hash) yang merupakan representasi dari record tersebut.

## Referensi
[1] Muhammad Taufik Dwi Putra. et.al., Pemprograman Lanjut dengan C++, Bandung : Widina Media Utama, 2023.

[2] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.

[4] Wikipedia (http://www.wikipedia.org/)
entry on Hash table
(http://en.wikipedia.org/wiki/Hash_table)
