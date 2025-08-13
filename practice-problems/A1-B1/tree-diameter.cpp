#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<int> dist;
vector<int> res;
int endNode = -1;
int maxDist = 0;

void BFS(int start, int n) {
    queue<int> q;
    q.push(start);
    endNode = -1;
    maxDist = 0;

    parent.assign(n, -1);
    dist.assign(n, -1);
    dist[start] = 0;

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for (int neighbor : adj[current]) {
            if (dist[neighbor] == -1) {
                q.push(neighbor);
                dist[neighbor] = dist[current] + 1;
                parent[neighbor] = current;
                if (dist[neighbor] > maxDist) {
                    maxDist = dist[neighbor];
                    endNode = neighbor;
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    adj.resize(n);
    int u, v;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(0, n);
    BFS(endNode, n);
    cout << "Diameter of the tree: " << maxDist << endl;
    cout << "Path: ";
    int current = endNode;
    while(current != -1) {
        cout << current << " ";
        current = parent[current];
    }
    cout << endl;
    return 0;
}