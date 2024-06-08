# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Avrilia Viananda Nagita</p>

## Dasar Teori

1. Graph 

Graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi). Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Representasi visual dari graph adalah dengan menyatakan objek sebagai noktah, bulatan atau titik (Vertex), sedangkan hubungan antara objek dinyatakan dengan garis (Edge).[1]

G = (V, E)

Dimana :

- G = Graph
- V = Simpul atau Vertex, atau Node, atau Titik
- E = Busur atau Edge, atau arc [1]

Graf merupakan suatu cabang ilmu yang memiliki banyak terapan. Banyak sekali struktur yang bisa direpresentasikan dengan graf, dan banyak masalah yang bisa diselesaikan dengan bantuan graf. Seringkali graf digunakan untuk merepresentasikan suaru jaringan. Misalkan jaringan jalan raya dimodelkan graf dengan kota sebagai simpul (vertex/node) dan jalan yang menghubungkan setiap kotanya sebagai sisi (edge) yang bobotnya (weight) adalah panjang dari jalan tersebut.[2]

![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/8078c7ee-2cf4-4389-a9e3-2db0f1bc49a1)

Jenis Graph  

a. Graph Berarah (Directed Graph) : jika sisi-sisi graph hanya 
berlaku satu arah. 
Misalnya : {x,y} yaitu arah x ke y, bukan dari y ke x; x 
disebut origin dan y disebut terminus. Secara notasi sisi 
digraph ditulis sebagai vektor (x, y).[3]

b.  Graph Tak Berarah (undirected graph atau undigraph): 
setiap sisi {x, y} berlaku pada kedua arah: baik x ke y 
maupun y ke x. Secara grafis sisi pada undigraph tidak 
memiliki 
mata panah dan secara notasional 
menggunakan kurung kurawal. [3]

c.    Graph Berbobot (Weighted Graph):
Jika setiap busur mempunyai nilai yang menyatakan hubungan antara 2 buah simpul, maka busur tersebut dinyatakan memiliki bobot. Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari 2 buah titik, jumlah rata-rata kendaraan perhari yang melalui sebuah jalan, dll. [3]

2. Tree

Tree merupakan salah satu bentuk struktur data tidak linear yang menggambarkan hubungan yang bersifat hirarkis (hubungan one to many) antara elemen-elemen. Tree bisa didefinisikan sebagai kumpulan simpul/node dengan satu elemen khusus yang disebut Root dan node lainnya. [2]

![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/8dabd091-49a1-4b60-a15c-3c519c362742)

Operasi penelusuran node-node dalam binary tree, 
Traversal dibagi 3, yaitu : [3]

a.  PreOrder

b.  InOrder 

c.  PostOrder 

- Tree (atau pohon) sejumlah node yang berhubungan 
secara hirarkis dimana suatu node pada suatu hirarki merupakan cabang dari node dengan hirarki yang lebih tinggi dan juga memiliki cabang ke beberapa node lainnya dengan hirarki yang lebih rendah. [3]
- Root (atau akar) 
Node dengan hirarki tertinggi dinamakan root. 
- Leaf (atau daun) 
Node yang tidak memiliki cabang. 
- Internal node (atau node dalam) 
Node yang bukan merupakan leaf. 
- Edge (atau sisi atau cabang) 
Menyatakan hubungan hirarkis antara kedua node yang 
terhubungkan, biasanya digambarkan berarah (berupa panah) untuk menunjukkan node asal edge lebih tinggi dari node tujuan dari edge. [3]

## Guided 

### 1. Guided 1

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph(){
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")"; 
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}


```
#### Output:
![Screenshot 2024-06-07 205146](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/54b2c63d-6efd-4e46-9c47-64589221b26f)


#### Full code Screenshot:
![Screenshot (330)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/154fc92b-5999-442b-95e3-6e400c383aaa)

Program di atas adalah sebuah program C++ yang menampilkan graf dalam bentuk matriks adjacency. Graf ini terdiri dari 7 simpul (node) yang dinamakan "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", dan "Yogyakarta". Matriks adjacency "busur" adalah sebuah matriks 2D yang menyimpan bobot (weight) dari setiap busur (edge) antar simpul. Nilai 0 pada matriks ini menunjukkan bahwa tidak ada busur antar simpul tersebut.

Penjelasan Output:

Output ini menunjukkan setiap simpul dan busur yang terkait dengan simpul tersebut, serta bobot dari setiap busur. Misalnya, simpul "Ciamis" memiliki busur ke simpul "Bandung" dengan bobot 7 dan busur ke simpul "Bekasi" dengan bobot 8.

### 2. Guided 2

```cpp
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main () {
    TNode *zero = new TNode(0);
    //0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    // /\
    // 1 9

    one->left = zero;
    // 7
    // /\
    // / \
    // 0 NULL

    one->right = five;
    // 7
    // /\
    // 1 9
    // / \
    // 0 5

    nine->left = eight;
    // 7 
    // /\
    // 1 9
    // / \ / \
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}

```
#### Output:
![Screenshot 2024-06-07 205210](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/bd631c40-64e4-40b7-9ea7-9f1b7d8c1dcb)


#### Full code Screenshot:
![Screenshot (331)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/fe766207-e924-48c9-9a77-c150a3d95823) 

Program di atas adalah sebuah program C++ yang mengimplementasikan pohon biner (binary tree) dan menampilkan isi pohon tersebut menggunakan tiga metode traversal: pre-order, in-order, dan post-order. 

Struktur Node

Struktur "TNode" merepresentasikan sebuah node dalam pohon biner. Setiap node memiliki tiga komponen:

- data: Nilai integer yang disimpan dalam node.
- left: Pointer ke node anak kiri.
- right: Pointer ke node anak kanan.

Konstruktor

Konstruktor TNode menginisialisasi node baru dengan nilai value dan mengatur pointer left dan right ke NULL.

Metode Traversal

Tiga metode traversal digunakan untuk menampilkan isi pohon biner:

"preOrder": Menampilkan nilai node saat ini, kemudian traversal ke anak kiri, dan akhirnya ke anak kanan.

"inOrder": Menampilkan nilai node anak kiri, kemudian nilai node saat ini, dan akhirnya nilai node anak kanan.

"postOrder": Menampilkan nilai node anak kiri, kemudian nilai node anak kanan, dan akhirnya nilai node saat ini.

Output ini menampilkan isi pohon biner menggunakan tiga metode traversal:

- Pre-order: 7 1 0 5 9 8
- In-order: 0 1 5 7 8 9
- Post-order: 0 5 1 8 9 7

Dalam setiap metode traversal, nilai node ditampilkan dalam urutan yang sesuai dengan metode tersebut.

## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Struktur Node untuk menyimpan nama node dan edge-nya
struct Node {
  string name;
  vector<pair<string, int>> edges; // (target node, weight)
};

int main() {
  int via_2311110010; // Variabel untuk mencantumkan NIM
  int numNodes;
  cout << "Silakan masukan jumlah simpul : "; // Input jumlah node
  cin >> numNodes;

  // Membuat vektor untuk menyimpan node-node
  vector<Node> graph(numNodes);

  // Input nama node
  for (int i = 0; i < numNodes; ++i) {
    cout << "Simpul " << i + 1 << " : "; // Input nama node ke-i
    cin >> graph[i].name;
  }

  // Input bobot edge
  cout << "Silakan masukkan bobot antar simpul\n"; // Input bobot edge
  for (int i = 0; i < numNodes; ++i) {
    for (int j = 0; j < numNodes; ++j) {
      int weight;
      cout << graph[i].name << "-->" << graph[j].name << " = "; // Input bobot edge dari node i ke node j
      cin >> weight;
      graph[i].edges.push_back(make_pair(graph[j].name, weight)); // Menyimpan edge ke dalam vektor
    }
  }

  // Print matriks adjacency
  cout << endl;
  for (int i = 0; i < numNodes; ++i) {
    cout << graph[i].name << "  "; // Print nama node
  }
  cout << endl;
  for (int i = 0; i < numNodes; ++i) {
    cout << graph[i].name << " "; // Print nama node
    for (int j = 0; j < numNodes; ++j) {
      bool found = false;
      for (auto edge : graph[i].edges) {
        if (edge.first == graph[j].name) {
          cout << edge.second << "  "; // Print bobot edge jika ditemukan
          found = true;
          break;
        }
      }
      if (!found) {
        cout << "0  "; // Print 0 jika tidak ditemukan
      }
    }
    cout << endl;
  }

  return 0;
}

```
#### Output:

![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/e992abc8-f7ab-404b-8354-1f656044f635)



#### Full code Screenshot:
![image](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/54e8e36e-ff80-4f7f-bd9f-c0562acad67d)

program untuk memvisualisasikan graf berbobot menggunakan representasi matriks adjasensi. Dengan memasukkan jumlah node, nama node, dan bobot antar node, Anda dapat melihat koneksi dan biayanya dalam format tabel.

- Baris dan Kolom Pertama: Baris dan kolom pertama menampilkan nama node, yaitu "Semarang" dan "Jakarta".
- Elemen Matriks: Setiap elemen dalam matriks mewakili bobot edge antara dua node.
- Elemen pada baris Semarang dan kolom Jakarta memiliki nilai 2. Ini menunjukkan bobot edge dari Semarang ke Jakarta adalah 2.
- Elemen pada baris Jakarta dan kolom Semarang memiliki nilai 5. Ini menunjukkan bobot edge dari Jakarta ke Semarang adalah 5 (perhatikan bahwa ini adalah graf berarah karena bobotnya berbeda untuk kedua arah).
- Elemen diagonal (baris dan kolom sama) memiliki nilai 0. Ini karena biasanya tidak ada edge yang menghubungkan sebuah node ke dirinya sendiri (disebut loop sendiri) dalam kebanyakan graf.






### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```cpp
#include <iostream>
using namespace std;

// Struktur Node untuk menyimpan data dan pointer ke node lain
struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // Konstruktor untuk membuat node baru
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Fungsi untuk mencetak node dalam urutan pre-order
void preOrder(TNode *node) {
    if (node!= NULL) {
        cout << node->data << " "; // Cetak data node
        preOrder(node->left); // Rekursif ke node kiri
        preOrder(node->right); // Rekursif ke node kanan
    }
}

// Fungsi untuk mencetak node dalam urutan in-order
void inOrder(TNode *node) {
    if (node!= NULL) {
        inOrder(node->left); // Rekursif ke node kiri
        cout << node->data << " "; // Cetak data node
        inOrder(node->right); // Rekursif ke node kanan
    }
}

// Fungsi untuk mencetak node dalam urutan post-order
void postOrder(TNode *node) {
    if (node!= NULL) {
        postOrder(node->left); // Rekursif ke node kiri
        postOrder(node->right); // Rekursif ke node kanan
        cout << node->data << " "; // Cetak data node
    }
}

// Fungsi untuk menambah node baru ke dalam tree
void tambahNode(TNode *&root, int value) {
    if (root == NULL) {
        root = new TNode(value); // Membuat node baru jika tree kosong
    } else {
        if (value < root->data) {
            tambahNode(root->left, value); // Rekursif ke node kiri jika value lebih kecil
        } else {
            tambahNode(root->right, value); // Rekursif ke node kanan jika value lebih besar
        }
    }
}

// Fungsi untuk mencetak node child dari node tertentu
void tampilkanNodeChild(TNode *node, int value) {
    if (node!= NULL) {
        if (node->data == value) {
            if (node->left!= NULL) {
                cout << "Node child kiri: " << node->left->data << endl;
            }
            if (node->right!= NULL) {
                cout << "Node child kanan: " << node->right->data << endl;
            }
        } else {
            tampilkanNodeChild(node->left, value); // Rekursif ke node kiri
            tampilkanNodeChild(node->right, value); // Rekursif ke node kanan
        }
    }
}

// Fungsi untuk mencetak node descendant dari node tertentu
void tampilkanNodeDescendant(TNode *node, int value) {
    if (node!= NULL) {
        if (node->data == value) {
            cout << "Node descendant: ";
            preOrder(node); // Cetak node descendant dalam urutan pre-order
            cout << endl;
        } else {
            tampilkanNodeDescendant(node->left, value); // Rekursif ke node kiri
            tampilkanNodeDescendant(node->right, value); // Rekursif ke node kanan
        }
    }
}

int main() {
    TNode *root = NULL; // Inisialisasi root tree

    int pilihan;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah Node" << endl;
        cout << "2. Tampilkan Pre-Order" << endl;
        cout << "3. Tampilkan In-Order" << endl;
        cout << "4. Tampilkan Post-Order" << endl;
        cout << "5. Tampilkan Node Child" << endl;
        cout << "6. Tampilkan Node Descendant" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int value;
                cout << "Masukkan nilai node: ";
                cin >> value;
                tambahNode(root, value); // Menambah node baru ke dalam tree
                break;
            }
            case 2: {
                preOrder(root); // Mencetak node dalam urutan pre-order
                cout << endl;
                break;
            }
            case 3: {
                inOrder(root); // Mencetak node dalam urutan in-order
                cout << endl;
                break;
            }
                        case 4: {
                postOrder(root); // Mencetak node dalam urutan post-order
                cout << endl;
                break;
            }
            case 5: {
                int value;
                cout << "Masukkan nilai node: ";
                cin >> value;
                tampilkanNodeChild(root, value); // Mencetak node child dari node tertentu
                break;
            }
            case 6: {
                int value;
                cout << "Masukkan nilai node: ";
                cin >> value;
                tampilkanNodeDescendant(root, value); // Mencetak node descendant dari node tertentu
                break;
            }
            case 7: {
                return 0; // Keluar dari program
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
            }
        }
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-06-08 173345](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/7458aec1-907b-49cf-ab2e-595e594ab8aa)

![Screenshot 2024-06-08 173400](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/26804bf8-03f7-4547-8a0b-399ef72dc6f6)

![Screenshot 2024-06-08 173408](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/33cd62b5-f023-42f0-8870-84d01db9b881)

![Screenshot 2024-06-08 173422](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/4399c76a-ad69-46d7-a9b6-c67a80644f1f)

![Screenshot 2024-06-08 173440](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/675249b1-dcaf-493c-aea9-a0bd0b77273e)

![Screenshot 2024-06-08 173458](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/8199f46d-4f89-4f50-bc10-668cc3aa16e1)


#### Full code Screenshot:
![Screenshot (333)](https://github.com/Avriliaviananda/Praktikum-Struktur-Data-Assignment/assets/161323061/bd8a6300-9328-49d2-bb04-064d3fd0cb67)

Program di atas adalah program C++ yang mengimplementasikan sebuah tree biner. Program ini memiliki beberapa fungsi utama, yaitu:

- tambahNode: Fungsi ini digunakan untuk menambah node baru ke dalam tree. Fungsi ini menerima parameter root yang merupakan pointer ke node root tree, dan value yang merupakan nilai node yang akan ditambahkan. Jika tree kosong, maka node baru akan dijadikan node root. Jika tree tidak kosong, maka node baru akan ditambahkan ke node yang sesuai dengan nilai value.

- preOrder, inOrder, postOrder: Fungsi-fungsi ini digunakan untuk mencetak node-node dalam tree dalam urutan tertentu. Fungsi preOrder akan mencetak node sebelum mencetak node child-nya, fungsi inOrder akan mencetak node child kiri terlebih dahulu sebelum mencetak node itu sendiri, dan fungsi postOrder akan mencetak node setelah mencetak node child-nya.

- tampilkanNodeChild: Fungsi ini digunakan untuk mencetak node child dari node tertentu. Fungsi ini menerima parameter root yang merupakan pointer ke node root tree, dan value yang merupakan nilai node yang akan dicari child-nya.

- tampilkanNodeDescendant: Fungsi ini digunakan untuk mencetak node descendant dari node tertentu. Fungsi ini menerima parameter root yang merupakan pointer ke node root tree, dan value yang merupakan nilai node yang akan dicari descendant-nya.

Program ini juga memiliki menu yang memungkinkan user untuk memilih fungsi yang ingin digunakan. User dapat memilih untuk menambah node baru, mencetak node dalam urutan tertentu, mencetak node child, atau mencetak node descendant dari node tertentu. Program akan terus berjalan sampai user memilih untuk keluar dari program.

Dalam contoh output yang diberikan, kita dapat melihat bahwa program dapat menambah node baru ke dalam tree, mencetak node dalam urutan pre-order, in-order, dan post-order, serta mencetak node child dan descendant dari node tertentu.

## Kesimpulan
Kesimpulan dari Graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi). Graph memiliki 3 jenis yaitu,  Graph Berarah (Directed Graph), Graph Tak Berarah (undirected graph atau undigraph), Graph Berbobot (Weighted Graph). Sedangkan Tree merupakan salah satu bentuk struktur data tidak linear yang menggambarkan hubungan yang bersifat hirarkis (hubungan one to many) antara elemen-elemen. Tree memiliki 3 operasi yaitu, PreOrder, Inoerder, dan PostOrder.

## Referensi
[1] Muhammad Taufik Dwi Putra. et.al., Pemprograman Lanjut dengan C++, Bandung : Widina Media Utama, 2023.

[2] Afrizal Zein and Emi Sita Eriana., Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[3] Anita Sindar., STRUKTUR DATA DAN ALGORITMA DENGAN C++, Banten : CV.AA.RIZKY, 2019.


