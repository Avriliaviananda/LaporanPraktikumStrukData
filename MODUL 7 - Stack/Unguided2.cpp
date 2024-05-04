#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {
  // Deklarasi variabel untuk menyimpan kalimat
  string kalimat;

  // input kalimat
  cout << "Masukkan kalimat minimal 3: ";
  getline(cin, kalimat);

  // Deklarasi stack untuk menyimpan kata-kata
  stack<string> s;

  // Memisahkan kata-kata dalam kalimat dan menambahkannya ke stack
  stringstream ss(kalimat);
  string kata;
  while (getline(ss, kata, ' ')) {
    // Membalikkan huruf dalam kata
    stack<char> s_kata;
    for (char c : kata) {
      s_kata.push(c);
    }
    string kata_terbalik;
    while (!s_kata.empty()) {
      kata_terbalik += s_kata.top();
      s_kata.pop();
    }
    // Menambahkan kata yang telah dibalik ke stack kata-kata
    s.push(kata_terbalik);
  }

  // Membalikkan kalimat dengan mengeluarkan kata dari stack
  string kalimat_terbalik;
  while (!s.empty()) {
    kalimat_terbalik += s.top() + " ";
    s.pop();
  }

  // Memotong spasi di akhir kalimat yang dibalik
  kalimat_terbalik.erase(kalimat_terbalik.size() - 1);

  // Menampilkan kalimat yang telah dibalik
  cout << "Kalimat yang dibalik: " << kalimat_terbalik << endl;

  return 0;
}
