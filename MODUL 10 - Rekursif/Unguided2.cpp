#include <iostream>
using namespace std;

int functionA(int num, int hasil) {
  if (num == 1) {
    return hasil;
  } else {
    return functionA(num - 1, num * hasil);
  }
}

int functionB(int num) {
  return functionA(num, 1);
}

int main() {
  int input;
  cout << "Masukkan bilangan bulat positif: ";
  cin >> input;
  cout << "Faktorial dari " << input << " adalah " << functionB(input) << endl;
  return 0;
}
