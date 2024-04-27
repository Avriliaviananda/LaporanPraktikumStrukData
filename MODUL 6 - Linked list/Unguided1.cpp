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