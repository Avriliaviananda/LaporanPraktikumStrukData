#include <iostream>

using namespace std;
// Fungsi untuk menghitung berapa banyak angka 4 dalam data menggunakan sequential search
int countOccurrences(int data[], int length, int target) {
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (data[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int target = 4;
    int length = sizeof(data) / sizeof(data[0]);

    // Menghitung berapa banyak angka 4 dalam data menggunakan sequential search
    int jumlahAngka4 = countOccurrences(data, length, target);

    cout << "Banyaknya angka 4 dalam data adalah: " << jumlahAngka4 << endl;

    return 0;
}