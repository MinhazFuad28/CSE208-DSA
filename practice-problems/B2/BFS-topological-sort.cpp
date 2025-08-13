// This is based on Kahn's Algorithm for topological sorting using BFS.

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    int n, m;
    fin >> n >> m;
    // Build adjacency list and calculate in-degrees
    vector<vector<int>> prereq(n);
    vector<int> indegree(n, 0);
    for(int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        prereq[u].push_back(v);
        indegree[v]++;
    }
    fin.close();

    queue<int> q;
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    if (q.empty()) cerr << "There exists a cycle in the graph." << endl;

    while(!q.empty()) {
        int course = q.front();
        q.pop();
        res.push_back(course);
        for(int neighbor : prereq[course]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) q.push(neighbor);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        fout << res[i] << " ";
    }
    fout << endl;
    fout.close();
    return 0;
}