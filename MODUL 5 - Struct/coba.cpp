#include <iostream>
#include <string> // Memasukkan library string

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5]; // Mengubah string menjadi array string dengan ukuran 5
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    for(int i = 0; i < 5; ++i) {
        favorit.judulBuku[i] = "The Alpha Girl's Guide " + to_string(i+1); // Mengisi judul buku dengan data dinamis
        favorit.pengarang[i] = "Henry Manampiring";
        favorit.penerbit[i] = "Gagas Media";
        favorit.tebalHalaman[i] = 253;
        favorit.hargaBuku[i] = 79000;
    }

    // Menampilkan informasi buku favorit
    cout << "\n\tBuku Favorit Saya" << endl;
    for(int i = 0; i < 5; ++i) {
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;
        cout << endl; // Memberi baris kosong antara setiap buku
    }

    return 0;
}
