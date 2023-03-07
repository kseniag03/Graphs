#include "graph.h"

Graph::Graph (int vertices_number_, bool isDirected_, std::vector<std::pair<int, int>>& edges) {
    vertices_number = vertices_number_;
    isDirected = isDirected_;
    edges_list = edges;
    adj_matrix.resize(vertices_number, std::vector<int>(vertices_number, 0));
    adj_list.resize(vertices_number);
    int cnt = 0;
    for (int i = 0; i < static_cast<int>(edges_list.size()); ++i) {
        if (edges_number.contains(edges_list[i])) continue;
        edges_number[edges_list[i]] = i - cnt;
        auto p = std::make_pair(edges_list[i].second, edges_list[i].first);
        if (edges_number.contains(p)) {
            edges_number[edges_list[i]] = edges_number[p];
            ++cnt;
        }
    }
    int edges_num = 0;
    for (auto& pair : edges_number) {
        if (pair.second > edges_num) {
            edges_num = pair.second;
        }
    }
    inc_matrix.resize(vertices_number, std::vector<int>(edges_num + 1, 0));
    rec_dfs_used.resize(vertices_number, 0);
    dfs_used.resize(vertices_number, 0);
    bfs_used.resize(vertices_number, 0);
}

void Graph::Add(int v, int u) {
    adj_matrix[v][u] = 1;
    adj_list[v].push_back(u);
    auto p = std::make_pair(v + 1, u + 1);
    auto q = std::make_pair(u + 1, v + 1);
    // Вывод номера ребра в графе (debug output).
    //std::cout << "Number of edge (" << v + 1 << ',' << u + 1 << ") = " << edges_number[p] << std::endl;
    if (edges_number.contains(p) && edges_number.contains(q)) {
        inc_matrix[v][edges_number[p]] = 1;
        inc_matrix[u][edges_number[p]] = 1;
    } else if (edges_number.contains(p)) {
        inc_matrix[v][edges_number[p]] = 1;
        inc_matrix[u][edges_number[p]] = -1;
    }
}

template <typename T>
void Graph::RecDFS(int v, T& stream_out) {
    rec_dfs_used[v] = true;
    stream_out << v + 1 << std::endl;
    for (auto u : adj_list[v]) {
        if (!rec_dfs_used[u]) {
            RecDFS(u, stream_out);
        }
    }
}

template <typename T>
void Graph::DFS(int w, T& stream_out) {
    std::stack<int> stack;
    stack.push(w);
    dfs_used[w] = 1;
    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();
        stream_out << v + 1 << std::endl;
        for (auto u : adj_list[v]) {
            if (dfs_used[u]) {
                continue;
            }
            stack.push(u);
            dfs_used[u] = 1;
        }
    }
}

template <typename T>
void Graph::BFS(int w, T& stream_out) {
    std::queue<int> queue;
    queue.push(w);
    bfs_used[w] = 1;
    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        stream_out << v + 1 << std::endl;
        for (auto u : adj_list[v]) {
            if (bfs_used[u]) {
                continue;
            }
            queue.push(u);
            bfs_used[u] = 1;
        }
    }
}
