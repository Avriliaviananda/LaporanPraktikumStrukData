#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = NULL;
Node* back = NULL;

bool isFull() {
    return false;
}

bool isEmpty() {
    if (front == NULL && back == NULL) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* current = front;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        front = NULL;
        back = NULL;
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Data antrian teller: " << endl;
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Data antrian teller: " << endl;
        Node* current = front;
        int i = 1;
        while (current != NULL) {
            cout << i << ". " << current->data << endl;
            current = current->next;
            i++;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}