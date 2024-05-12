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