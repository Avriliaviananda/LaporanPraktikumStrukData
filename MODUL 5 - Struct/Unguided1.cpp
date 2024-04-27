#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int jumlahHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel data buku dengan tipe buku
    buku dataBuku;

    // Mengisi data ke dalam variabel buku
    for(int i = 0; i < 5; ++i) {
        dataBuku.judulBuku[i] = "Is it Bad or Good" + to_string(i+1); 
        dataBuku.pengarang[i] = "Sabrina Ara";
        dataBuku.penerbit[i] = "Syalmahat";
        dataBuku.jumlahHalaman[i] = 205;
        dataBuku.hargaBuku[i] = 85000;
    }

    // Menampilkan informasi data buku
    cout << "\tData Buku" << endl;
    for (int i = 0; i < 5; ++i) {
    cout << "\tData Buku Saya" << endl;
    cout << "\tJudul Buku : " << dataBuku.judulBuku[i] << endl;
    cout << "\tPengarang : " << dataBuku.pengarang[i] << endl;
    cout << "\tPenerbit : " << dataBuku.penerbit[i] << endl;
    cout << "\tJumlah Halaman: " << dataBuku.jumlahHalaman[i] << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << dataBuku.hargaBuku[i] << endl;
    cout << endl;
    } 
    return 0;
}