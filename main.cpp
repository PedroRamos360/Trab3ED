#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<int> *adj;

    void DFSUtil(int v, bool visited[], vector<int> &preorder, vector<int> &postorder) {
        visited[v] = true;
        preorder.push_back(v);

        for (int i = 0; i < adj[v].size(); i++) {
            int n = adj[v][i];
            if (!visited[n]) {
                DFSUtil(n, visited, preorder, postorder);
            }
        }

        postorder.push_back(v);
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS(int v) {
        bool *visited = new bool[V];
        vector<int> preorder, postorder;

        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        DFSUtil(v, visited, preorder, postorder);

        cout << "Pre ordem: ";
        for (int i = 0; i < preorder.size(); i++) {
            cout << preorder[i] << " ";
        }
        cout << endl;

        cout << "Pos ordem: ";
        for (int i = 0; i < postorder.size(); i++) {
            cout << postorder[i] << " ";
        }
        cout << endl;
    }

    void BFS(int v) {
        bool *visited = new bool[V];
        vector<int> order;
        queue<int> q;

        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            int f = q.front();
            q.pop();
            order.push_back(f);

            for (int i = 0; i < adj[f].size(); i++) {
                int n = adj[f][i];
                if (!visited[n]) {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }

        cout << "Ordem: ";
        for (int i = 0; i < order.size(); i++) {
            cout << order[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    int start_node;
    cout << "Digite o no inicial para a busca em profundidade: ";
    cin >> start_node;
    g.DFS(start_node);

    cout << "Digite o no inicial para a busca em largura: ";
    cin >> start_node;
    g.BFS(start_node);

    return 0;
}
