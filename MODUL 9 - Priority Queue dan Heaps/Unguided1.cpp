#include <iostream>
#include <algorithm>

using namespace std;

int H[50]; // Array untuk menyimpan elemen heap
int heapsize = -1; // Ukuran heap saat ini (awalnya kosong)

int parent(int i) {
    return(i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) +1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while(i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]) ;
        i = parent(i);
    }
}


void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapsize && H[l] > H [maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapsize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i!= maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftUp(heapsize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;

    // Dapatkan jumlah elemen dari pengguna
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    // Masukkan elemen ke dalam heap
    for (int i = 0; i < n; ++i) {
        int x;
        cout << "Masukkan elemen " << i + 1 << ": ";
        cin >> x;
        insert(x);
    }

    // Cetak antrian prioritas awal
    cout << "Antrian Prioritas : ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // Ekstrak elemen dengan prioritas tertinggi
    cout << "Elemen dengan prioritas teratas : " << extractMax() << "\n";

    // Cetak antrian prioritas setelah ekstraksi
    cout << "Antrian prioritas setelah elemen teratas diambil : ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // Ubah prioritas elemen pada indeks 2
    changePriority(2, 49);

    // Cetak antrian prioritas setelah perubahan prioritas
    cout << "Antrian prioritas setelah perubahan prioritas: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // Hapus elemen pada indeks 3
    remove(3);

    // Cetak antrian prioritas setelah penghapusan
    cout << "Antrian prioritas setelah elemen dihapus: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}