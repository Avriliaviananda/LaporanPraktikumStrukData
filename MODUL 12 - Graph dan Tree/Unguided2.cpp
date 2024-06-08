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