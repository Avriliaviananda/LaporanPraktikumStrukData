#include <iostream>
using namespace std;
int main(){
    int n = 5;
    int data[n] = {1, 2, 3, 4, 5, 5};
    int ada = false;
    int i;

    for (i = 0; i < n; ++i) {
        if(data[i] == n) {
            ada = true;
            break;
        }
    }

    if (ada){
        cout << " angka ditemukan di indeks ke-" << i << endl;
    } else {
        cout << " angka tidak ditemukan." << endl;
    }
    return 0;
}