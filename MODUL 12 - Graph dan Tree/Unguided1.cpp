#include <iostream>
#include <vector>

using namespace std;

// Struktur Node untuk menyimpan nama node dan edge-nya
struct Node {
  string name;
  vector<pair<string, int>> edges; // (target node, weight)
};

int main() {
  int nama_22102003; // Variabel untuk mencantumkan NIM
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