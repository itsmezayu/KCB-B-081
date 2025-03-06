#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// Struktur graf menggunakan adjacency list
map<string, vector<string>> romania_map = {
    {"Arad", {"Zerind", "Timisoara", "Sibiu"}},
    {"Zerind", {"Oradea", "Arad"}},
    {"Oradea", {"Zerind", "Sibiu"}},
    {"Timisoara", {"Arad", "Lugoj"}},
    {"Lugoj", {"Timisoara", "Mehadia"}},
    {"Mehadia", {"Lugoj", "Drobeta"}},
    {"Drobeta", {"Mehadia", "Craiova"}},
    {"Craiova", {"Drobeta", "Rimnicu Vilcea", "Pitesti"}},
    {"Rimnicu Vilcea", {"Sibiu", "Craiova", "Pitesti"}},
    {"Sibiu", {"Arad", "Oradea", "Fagaras", "Rimnicu Vilcea"}},
    {"Fagaras", {"Sibiu", "Bucharest"}},
    {"Pitesti", {"Rimnicu Vilcea", "Craiova", "Bucharest"}},
    {"Bucharest", {"Fagaras", "Pitesti", "Urziceni", "Giurgiu"}},
    {"Urziceni", {"Bucharest", "Vaslui", "Hirsova"}},
    {"Hirsova", {"Urziceni", "Eforie"}},
    {"Eforie", {"Hirsova"}},
    {"Vaslui", {"Urziceni", "Iasi"}},
    {"Iasi", {"Vaslui", "Neamt"}},
    {"Neamt", {"Iasi"}},
    {"Giurgiu", {"Bucharest"}}
};

// Fungsi BFS
vector<string> bfs(string start, string goal) {
    queue<pair<string, vector<string>>> q;
    q.push({start, {start}});
    map<string, bool> visited;
    visited[start] = true;

    while (!q.empty()) {
        string node = q.front().first;
        vector<string> path = q.front().second;
        q.pop();

        if (node == goal) {
            return path; // Mengembalikan path saat tujuan ditemukan
        }

        for (const string &neighbor : romania_map[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                vector<string> new_path = path;
                new_path.push_back(neighbor);
                q.push({neighbor, new_path});
            }
        }
    }

    return {}; // Jika tidak ada jalur ditemukan
}

// Fungsi DFS
vector<string> dfs(string start, string goal, map<string, bool> &visited, vector<string> path) {
    if (start == goal) {
        path.push_back(start);
        return path; // Mengembalikan path saat tujuan ditemukan
    }

    visited[start] = true;
    path.push_back(start);

    for (const string &neighbor : romania_map[start]) {
        if (!visited[neighbor]) {
            vector<string> result = dfs(neighbor, goal, visited, path);
            if (!result.empty()) {
                return result;
            }
        }
    }

    return {}; // Jika tidak ada jalur ditemukan
}

void printRouteWithArrows(const vector<string>& route) {
    for (size_t i = 0; i < route.size(); ++i) {
        cout << route[i];
        if (i != route.size() - 1) {
            cout << " → "; // Menambahkan panah antara kota
        }
    }
    cout << endl;
}

int main() {
    string startCity = "Arad";
    string goalCity;
    string method;

    cout << "Masukkan kota tujuan: ";
    cin >> goalCity;
    cout << "Pilih metode pencarian (BFS/DFS): ";
    cin >> method;

    if (method == "BFS") {
        vector<string> result = bfs(startCity, goalCity);
        if (!result.empty()) {
            cout << "Rute ditemukan (BFS): ";
            printRouteWithArrows(result);
        } else {
            cout << "Tidak ada rute yang ditemukan dengan BFS." << endl;
        }
    } else if (method == "DFS") {
        map<string, bool> visited;
        vector<string> path;
        vector<string> result = dfs(startCity, goalCity, visited, path);
        if (!result.empty()) {
            cout << "Rute ditemukan (DFS): ";
            printRouteWithArrows(result);
        } else {
            cout << "Tidak ada rute yang ditemukan dengan DFS." << endl;
        }
    } else {
        cout << "Metode tidak valid! Pilih BFS atau DFS." << endl;
    }

    return 0;
}