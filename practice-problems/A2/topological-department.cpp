#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main() {
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    vector<int> rank(n, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            rank[i] = 0;
        }
    }
    int iteration = q.size();
    // vector<vector<pair<int, int>>> result;
    queue<int> temp;
    for(int i = 0; i < iteration; i++) {
        int gm = q.front();
        q.pop();
        temp.push(gm);
        int subordinateCount = 0;
        vector<int> subordinate;
        while(!temp.empty()) {
            int current = temp.front();
            temp.pop();
            for(int neighbor : adj[current]) {
                rank[neighbor] = rank[current] + 1;
                temp.push(neighbor);
                subordinateCount++;
                subordinate.push_back(neighbor);
            }
        }
        // result[i].push_back(make_pair(gm, subordinateCount));
        cout << gm << " " << subordinateCount << endl;
        for(int j = 0; j < subordinateCount; j++) {
            // result[i].push_back(make_pair(subordinate[j], rank[subordinate[j]]));
            cout << subordinate[j] << " " << rank[subordinate[j]] << endl;
        }
        cout << endl;
    }
    return 0;
}