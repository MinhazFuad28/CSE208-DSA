// This is a DFS based approach to solve the topological sort
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

class TopologicalSort {
public:
    vector<vector<int>> prereq;
    vector<int> color;
    stack<int> res;
    bool hasCycle = false;
    TopologicalSort(int n, int m) {
        prereq.resize(n);
        color.resize(n, 0);
    }
    void DFS(int node) {
        color[node] = 1;
        for(int neighbor : prereq[node]) {
            if(color[neighbor] == 1) {
                hasCycle = true;
                return;
            }
            if(color[neighbor] == 0) DFS(neighbor);
        }
        color[node] = 2;
        res.push(node);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    TopologicalSort obj(n, m);
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        obj.prereq[u].push_back(v);
    }
    for(int i = 0; i < n; i++) {
        if(obj.color[i] == 0) {
            obj.DFS(i);
            if(obj.hasCycle) break;
        }
    }
    if(obj.hasCycle) {
        cerr << "There exists a cycle in the graph" << endl;
        return 1;
    }
    while(!obj.res.empty()) {
        cout << obj.res.top() << " ";
        obj.res.pop();
    }
    cout << endl;
    return 0;
}