# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

LINKED LIST

Linked List
Linked list adalah salah satu struktur data dasar paling dasar di bidang 
ilmu komputer. Dengan menggunakan linked list, programmer dapat 
menyimpan data saat dibutuhkan. Linked listmirip dengan larik, kecuali bahwa 
data yang akan disimpan dalam Linked listdapat dialokasikan secara dinamis 
selama operasi program (waktu proses). Linked lista dalam struktur data yang 
berisi objek data yang dihubungkan oleh tautan. Setiap Linked listterdiri dari 
node yang memiliki bidang data dan referensi ke node berikutnya dalam daftar 
tertaut [1]

Jenis-Jenis Linked List

a. Single linked list

b. Double linked list

c. Circular Linked List

1. Single linked list

Single linked list atau biasa disebut linked list terdiri dari 
elemen-elemen individu, dimana masing masing 
dihubungkan dengan pointer tunggal. Masing-masing 
elemen terdiri dari dua bagian, yaitu sebuah data dan 
sebuah pointer yang disebut dengan pointer next. Dengan 
menggunakan struktur two-member seperti ini, linked list 
dibentuk dengan cara menunjuk pointer next suatu 
elemen ke elemen yang mengikutinya. Pointer next pada 
elemen terakhir merupakan NULL, yang menunjukkan 
akhir dari suatu list. Elemen pada awal suatu list disebut 
head, dan elemen terakhir dari suatu list disebut tail. [3]

![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/650f77b3-3034-4306-92a9-08bb96f2185b)

Untuk mengakses elemen dalam linked list, dimulai 
dari head dan menggunakan pointer next dari elemen 
selanjutnya untuk berpindah dari elemen ke elemen 
berikutnya sampai elemen yang diminta dicapai. Dengan 
single linke list, list dapat dilintasi hanya satu arah dari head ke tail karena masing-masing elemen tidak terdapat link 
dengan elemen sebelumnya.  [2]

2. Double linked list

Elemen-elemen dihubungkan dengan dua pointer 
dalam satu elemen. Struktur ini menyebabkan list melintas 
baik ke depan maupun ke belakang. Masing-masing elemen 
pada double linked list terdiri dari tiga bagian, disamping 
data dan pointer next, masing-masing elemen dilengkapi 
dengan pointer prev yang menunjuk ke elemen sebelumnya. 
Double linked list dibentuk dengan menyusun sejumlah 
elemen sehingga pointer next menunjuk ke elemen yang 
mengikutinya dan pointer prev menunjuk ke elemen yang 
mendahuluinya. Untuk menunjukkan head dari double linked 
list, maka pointer prev dari elemen pertama menunjuk 
NULL. Untuk menunjukkan tail dari double linked list 
tersebut, maka pointer next dari elemen terakhir menunjuk 
NULL. [3]

![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/a24ca089-fed3-4eb5-9c56-3e158f94d103)


3. Circular Linked List 

Circular list adalah bentuk lain dari linked list yang 
memberikan fleksibilitas dalam melewatkan elemen. 
Circular list bisa berupa single linked list atau double linked 
list, tetapi tidak mempunyai tail. Pada circular list, pointer 
next dari elemen terakhir menunjuk ke elemen pertama dan 
bukan menunjuk NULL. Pada double linked circular list, 
pointer prev dari elemen pertama menunjuk ke elemen 
terakhir. susunan dari single linked circular list, hanya 
menangani link dari elemen terakhir kembali ke elemen 
pertama. [3]

![Screenshot 2024-04-26 210748](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/3add8f9e-e6a5-40b8-951d-42cd80abab0c)


## Guided 

### 1. Latihan Single Linked List
```cpp
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```
#### Output:
![Screenshot 2024-04-26 211247](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/346d7d3d-1228-472b-b8be-37fd01f1fc1d)

#### Full code Screenshot:
![Screenshot (298)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/cca4dafe-5ac0-40eb-b383-fe714b6082cb)


Dalam program di atas, dapat dijelaskan output kodingan diatas adalah
1. insertDepan(3); tampil();

Output: 3

Menambahkan node dengan nilai 3 di depan list.

2. insertBelakang(5); tampil();

Output: 3 5

Menambahkan node dengan nilai 5 di belakang list.

3. insertDepan(2); tampil();

Output: 2 3 5

Menambahkan node dengan nilai 2 di depan list.

4. insertDepan(1); tampil();

Output: 1 2 3 5

Menambahkan node dengan nilai 1 di depan list.

5. hapusDepan(); tampil();

Output: 2 3 5

Menghapus node pertama dari list.

6. hapusBelakang(); tampil();

Output: 2 3

Menghapus node terakhir dari list.

7. insertTengah(7, 2); tampil();

Output: 2 7 3

Menambahkan node dengan nilai 7 di posisi tengah.

8. hapusTengah(2); tampil();

Output: 2 3

Menghapus node di posisi tengah.

9. ubahDepan(1); tampil();

Output: 1 3

Mengubah nilai node pertama.

10. ubahBelakang(8); tampil();

Output: 1 8

Mengubah nilai node terakhir.

11. ubahTengah(11, 2); tampil();

Output: 1 11

Mengubah nilai node di posisi tengah.

12. clearList();

Output: List berhasil terhapus!

Menghapus semua node dalam list.

### 2. Latihan Double Linked List

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-04-26 212052](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/e1d82364-f49e-436b-99c6-19bce3ff3189)

#### Full code Screenshot:
![Screenshot (299)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/cd0c9a63-d82f-4482-ad77-5bcf03f72d9c)


program tersebut mengimplementasikan operasi dasar pada double linked list, yaitu menambahkan, menghapus, memperbarui, dan menghapus semua data dalam list. seperti pada output kita bisa menambahkan data 10 lalu enter, kemudian bisa memilih update data atau memperbarui data dari yang tadinya 10 menjadi 25, kemudian bisa pilih menampilkan data, maka akan ditampilkan data yang sudah diupdate.

### 3. Linked List Circular 
```cpp
#include <iostream>
using namespace std;

///Program Single Linked List Circular

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init(){
    head = NULL;
    tail = head;
}

//Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; //true
    else
        return 0; //false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL){
        jumlah++;
        bantu = bantu -> next;
    }

    return jumlah;
}

// Tambah depan
void insertDepan(string data) {
    //Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah belakang
void insertBelakang(string data) {
    //Buat Node Baru
    buatNode(data);

    if(isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        //transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if(hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }
            
            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong !" << endl;
    }
}

//Hapus tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transvering 
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor ++;
        } 

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong! " << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil dihapus !" << endl; 
}

// Tampilkan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head) ;

        cout << endl;
    } else {
        cout << "List masih kosong !" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
#### Output:
![Screenshot 2024-04-26 212137](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/dab201e5-b574-4471-bc8e-a219d0eb7d88)

#### Full code Screenshot:
![Screenshot (300)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/b9411e46-5bee-48dd-822a-d5826e18d5fe)


program ini menghasilkan urutan operasi yang dilakukan yaitu dengan, Menambahkan "Ayam" ke depan.
Menambahkan "Bebek" ke depan, Menambahkan "Cicak" ke belakang, Menambahkan "Domba" ke belakang, Menghapus "Domba" dari belakang, Menghapus "Bebek" dari depan, Menambahkan "Sapi" di tengah, Menghapus "Sapi" dari tengah. dan dihasilkan output seperti diatas


## Unguided 

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 


```cpp
#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* head = NULL;

void createList(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;
    head = newNode;
}

void addDepan(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = head;
    head = newNode;
}

void addBelakang(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addTengah(string nama, string nim, int posisi) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;

    if (posisi == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void ubahDepan(string nama, string nim) {
    if (head != NULL) {
        head->nama = nama;
        head->nim = nim;
    } else {
        cout << "List masih kosong" << endl;
    }
}

void ubahBelakang(string nama, string nim, int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            temp->nama = nama;
            temp->nim = nim;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

void ubahTengah(string nama, string nim, int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            temp->nama = nama;
            temp->nim = nim;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

void hapusDepan() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        cout << "Data Berhasil dihapus " << endl;
    }
}

void hapusBelakang() {
    if (head != NULL) {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    } else {
        cout << "Data Berhasil dihapus " << endl;
            }
}

void hapusTengah(int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "Data Berhasil dihapus " << endl;
    }
}

void hapusList() {
    if (head != NULL) {
        Node* temp = head;
        while (temp != NULL) {
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        head = NULL;
    } else {
        cout << "List masih kosong" << endl;
    }
}

void tampilkan() {
    if (head != NULL) {
        Node* temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        while (temp != NULL) {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

int main() {
    int pilih, posisi;
    string nama, nim;

    while (true) {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                addDepan(nama, nim);
                cout << "Data telah ditambahkan " << endl;
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                addBelakang(nama, nim);
                cout << "Data telah ditambahkan " << endl;
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                addTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan " << endl;
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahDepan(nama, nim);
                cout << "Data berhasil diubah " << endl;
                break;
            case 5:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                ubahBelakang(nama, nim, posisi);
                cout << "Data berhasil diubah " << endl;
                break;
            case 6:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                ubahTengah(nama, nim, posisi);
                cout << "Data Telah diubah ";
                break;
            case 7:
                hapusDepan();
                break;
            case 8:
                hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                hapusTengah(posisi);
                cout << "Data Berhasil dihapus ";
                break;
            case 10:
                hapusList();
                break;
            case 11:
                tampilkan();
                break;
            case 0:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}

```
#### Output:

1. Tampilan menu
![Screenshot 2024-04-27 183831](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/16353933-db08-4d72-a26e-4cb7835cc868)

2. Tampilan operasi tambah

   tambah depan
![Screenshot 2024-04-27 184021](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/4c2438f8-214e-43dc-9240-c50176b2c3dd)

    tambah tengah
![Screenshot 2024-04-27 184406](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/eca43048-c8ae-45ea-befa-e64b80fcef99)


3. Tampilan operasi hapus
![Screenshot 2024-04-27 192357](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/b910a9be-22b4-4dd5-a35b-7a66e2088b01)

     ![Screenshot 2024-04-27 192419](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/5ee268ea-eb6e-454f-8829-8a6f48dee0dc)

4. Tampilan operasi ubah
![Screenshot 2024-04-27 192846](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/48bb3d67-37f1-463f-9423-b285be3527fd)

5. Tampilan Data Mahasiswa
![Screenshot 2024-04-27 192902](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/eab69e73-49e8-4dd8-97be-d10cb5f059b7)


#### Full code Screenshot:
![Screenshot (303)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/07566ff2-16ba-4145-af96-f3db2ee8732c)



Program ini merupakan implementasi dari single linked list non-circular dalam bahasa C++. Program ini memiliki menu operasi untuk mengelola data mahasiswa, seperti tambah depan, tambah belakang, tambah tengah, ubah depan, ubah belakang, ubah tengah, hapus depan, hapus belakang, hapus tengah, hapus semua list, tampilkan data mahasiswa, dan keluar. 

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 
![Screenshot 2024-04-27 202933](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/376c087d-36c6-4ab0-ae18-d58b325911e2)


```cpp
#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* head = NULL;

void createList(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;
    head = newNode;
}

void addDepan(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = head;
    head = newNode;
}

void addBelakang(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addTengah(string nama, string nim, int posisi) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;

    if (posisi == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void ubahDepan(string nama, string nim) {
    if (head != NULL) {
        head->nama = nama;
        head->nim = nim;
    } else {
        cout << "List masih kosong" << endl;
    }
}

void ubahBelakang(string nama, string nim, int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            temp->nama = nama;
            temp->nim = nim;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

void ubahTengah(string nama, string nim, int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            temp->nama = nama;
            temp->nim = nim;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

void hapusDepan() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        cout << "Data Berhasil dihapus " << endl;
    }
}

void hapusBelakang() {
    if (head != NULL) {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    } else {
        cout << "Data Berhasil dihapus " << endl;
            }
}

void hapusTengah(int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "Data Berhasil dihapus " << endl;
    }
}

void hapusList() {
    if (head != NULL) {
        Node* temp = head;
        while (temp != NULL) {
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        head = NULL;
    } else {
        cout << "List masih kosong" << endl;
    }
}

void tampilkan() {
    if (head != NULL) {
        Node* temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        while (temp != NULL) {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

int main() {
    int pilih, posisi;
    string nama, nim;

    while (true) {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                addDepan(nama, nim);
                cout << "Data telah ditambahkan " << endl;
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                addBelakang(nama, nim);
                cout << "Data telah ditambahkan " << endl;
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                addTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan " << endl;
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahDepan(nama, nim);
                cout << "Data berhasil diubah " << endl;
                break;
            case 5:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                ubahBelakang(nama, nim, posisi);
                cout << "Data berhasil diubah " << endl;
                break;
            case 6:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                ubahTengah(nama, nim, posisi);
                cout << "Data Telah diubah ";
                break;
            case 7:
                hapusDepan();
                break;
            case 8:
                hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                hapusTengah(posisi);
                cout << "Data Berhasil dihapus ";
                break;
            case 10:
                hapusList();
                break;
            case 11:
                tampilkan();
                break;
            case 0:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}
```
#### Output:

1. Tambah Data dengan tambah depan
![Screenshot 2024-04-27 194502](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/0b59d30d-acaa-403f-acd9-0da92d4b0b3d)

2. Tambah Data dengan tambah belakang
![Screenshot 2024-04-27 194516](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/f1635510-d2bb-4448-ac1b-0f1fec817d8b)

3. Tambah Data dengan tambah tengah
![Screenshot 2024-04-27 194559](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/12040947-fb37-458c-8b31-df338d8737c8)


4. Tampilan Data Mahasiswa

   ![Screenshot 2024-04-27 194618](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/e33cfea9-f2af-4898-8aff-8877f7a04449)


#### Full code Screenshot:
![Screenshot (304)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/21573ddf-9262-49ca-be38-ccf1092e81db)


Setelah membuat menu tersebut, masukkan data sesuai urutan data diatas, lalu  tampilkan data yang telah dimasukkan. disini menggunakan insert depan, belakang dan tengah bisa dilihat pada screenshort outputnya.


### 3. Lakukan perintah berikut: 
a. Tambahkan data berikut diantara Farrel dan Denis: 
Wati 2330004 

#### Output:
![Screenshot 2024-04-27 195832](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/243e10d9-fb5c-4dbd-a126-55cc1cad5e00)


b. Hapus data Denis 
#### Output:
![Screenshot 2024-04-27 195903](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/37f0f40f-e3c4-4213-8520-2fd53ea9d223)


c. Tambahkan data berikut di awal: 
Owi 2330000
#### Output:
![Screenshot 2024-04-27 195943](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/dd04eaff-44b0-418e-a112-0bd30283d54e)


d. Tambahkan data berikut di akhir: 
David 23300100 
#### Output:
![Screenshot 2024-04-27 200028](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/95d777c1-7c2f-4f2a-ba1d-e3e606a1bfe9)



e. Ubah data Udin menjadi data berikut: 
Idin 23300045 
#### Output:
![Screenshot 2024-04-27 200130](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/64f1eebe-a894-4837-8567-939a020dedbd)


f. Ubah data terkahir menjadi berikut: 
Lucy 23300101 
#### Output:
![Screenshot 2024-04-27 200315](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/18ffa0fa-7fe7-4140-b3c6-c308cf78488e)


g. Hapus data awal 
#### Output:
![Screenshot 2024-04-27 200334](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/74d2543d-af30-4fec-9c4d-58494aad3601)


h. Ubah data awal menjadi berikut: 
Bagas 2330002 
#### Output:
![Screenshot 2024-04-27 200410](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/f443126c-4215-421e-a627-d2d0137d2234)


i. Hapus data akhir 
#### Output:
![Screenshot 2024-04-27 200439](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/e45d76b7-cb2d-4959-8bdc-0af41e4c883f)


j. Tampilkan seluruh data
#### Output:
![Screenshot (305)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/cbcab0ce-c6ea-4156-823b-0efbc33b1052)


#### Full code Screenshot:
![Screenshot (295)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/83847292-12d0-48f7-ba27-6f3bdb639993)

```cpp
#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

Node* head = NULL;

void createList(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;
    head = newNode;
}

void addDepan(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = head;
    head = newNode;
}

void addBelakang(string nama, string nim) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addTengah(string nama, string nim, int posisi) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nim = nim;

    if (posisi == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void ubahDepan(string nama, string nim) {
    if (head != NULL) {
        head->nama = nama;
        head->nim = nim;
    } else {
        cout << "List masih kosong" << endl;
    }
}

void ubahBelakang(string nama, string nim, int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            temp->nama = nama;
            temp->nim = nim;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

void ubahTengah(string nama, string nim, int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            temp->nama = nama;
            temp->nim = nim;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

void hapusDepan() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        cout << "Data Berhasil dihapus " << endl;
    }
}

void hapusBelakang() {
    if (head != NULL) {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    } else {
        cout << "Data Berhasil dihapus " << endl;
            }
}

void hapusTengah(int posisi) {
    if (head != NULL) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            if (temp == NULL) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "Data Berhasil dihapus " << endl;
    }
}

void hapusList() {
    if (head != NULL) {
        Node* temp = head;
        while (temp != NULL) {
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        head = NULL;
    } else {
        cout << "List masih kosong" << endl;
    }
}

void tampilkan() {
    if (head != NULL) {
        Node* temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        while (temp != NULL) {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        }
    } else {
        cout << "List masih kosong" << endl;
    }
}

int main() {
    int pilih, posisi;
    string nama, nim;

    while (true) {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                addDepan(nama, nim);
                cout << "Data telah ditambahkan " << endl;
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                addBelakang(nama, nim);
                cout << "Data telah ditambahkan " << endl;
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                addTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan " << endl;
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahDepan(nama, nim);
                cout << "Data berhasil diubah " << endl;
                break;
            case 5:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                ubahBelakang(nama, nim, posisi);
                cout << "Data berhasil diubah " << endl;
                break;
            case 6:
                cout << "Masukkan Nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                ubahTengah(nama, nim, posisi);
                cout << "Data Telah diubah ";
                break;
            case 7:
                hapusDepan();
                break;
            case 8:
                hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                hapusTengah(posisi);
                cout << "Data Berhasil dihapus ";
                break;
            case 10:
                hapusList();
                break;
            case 11:
                tampilkan();
                break;
            case 0:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}
```

output disini sama seperti nomer 2 tetapi 

## Kesimpulan
Kesimpulan dari Linked list dalam struktur data yang berisi objek data yang dihubungkan oleh tautan. Setiap Linked list terdiri dari node yang memiliki bidang data dan referensi ke node berikutnya dalam daftar tertaut. adapun jenis-jenis linked list yaitu single linked list terdiri dari elemen-elemen individu, dimana masing masing dihubungkan dengan pointer tunggal. double linked list yaitu elemen-elemen dihubungkan dengan dua pointer dalam satu elemen. Struktur ini menyebabkan list melintas baik ke depan maupun ke belakang. sedangkan circular linked list adalah bentuk lain dari linked list yang memberikan fleksibilitas dalam melewatkan elemen. Circular list bisa berupa single linked list atau double linked list, tetapi tidak mempunyai tail.

## Referensi
[1] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[2] Meidyan Permata Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung : Widina Bhakti Persada Bandung, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.
