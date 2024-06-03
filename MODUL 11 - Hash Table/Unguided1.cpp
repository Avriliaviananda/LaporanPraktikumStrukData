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

