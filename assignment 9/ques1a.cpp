#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define WHITE 0
#define GRAY  1
#define BLACK 2

class Graph {
    int V;
    vector<int> adj[100];

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int s) {
        int color[100];
        int d[100];
        int pi[100];

        for(int i = 0; i < V; i++) {
            color[i] = WHITE;
            d[i] = -1;
            pi[i] = -1;
        }

        queue<int> Q;

        color[s] = GRAY;
        d[s] = 0;
        pi[s] = -1;
        Q.push(s);

        cout << "BFS Order: ";

        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();

            cout << u << " ";

            for(int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if(color[v] == WHITE) {
                    color[v] = GRAY;
                    d[v] = d[u] + 1;
                    pi[v] = u;
                    Q.push(v);
                }
            }
            color[u] = BLACK;
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);

    g.BFS(0);
    return 0;
}
