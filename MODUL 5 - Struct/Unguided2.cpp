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