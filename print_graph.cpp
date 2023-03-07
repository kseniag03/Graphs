#include "print_graph.h"

template <typename T>
void PrintGraphDegreesCount(Graph& graph, T& stream_out) {
    stream_out << (graph.isDirected ? "Half-degrees" : "Degrees") << " of vertices" << std::endl;
    int i = 1;
    for (auto& x : graph.adj_list) {
        stream_out << i << ' ' << x.size() << std::endl;
        ++i;
    }
}

template <typename T>
void PrintGraphEdgesCount(Graph& graph, T& stream_out) {
    stream_out << (graph.isDirected ? "Arcs" : "Edges") << " count: ";
    stream_out << (graph.isDirected ? (graph.inc_matrix[0].size()) : (graph.edges_list.size() / 2)) << std::endl;
}

template <typename T>
void PrintGraphAsAdjacencyMatrix(Graph& graph, T& stream_out) {
    stream_out << "Graph adjacency matrix:" << std::endl;
    for (auto& x : graph.adj_matrix) {
        for (auto y : x) {
            stream_out << y << ' ';
        }
        stream_out << std::endl;
    }
}

template <typename T>
void PrintGraphAsIncidenceMatrix(Graph& graph, T& stream_out) {
    stream_out << "Graph incidence matrix:" << std::endl;
    for (auto& x : graph.inc_matrix) {
        for (auto y : x) {
            stream_out << y << ' ';
        }
        stream_out << std::endl;
    }
}

template <typename T>
void PrintGraphAsAdjacencyList(Graph& graph, T& stream_out) {
    stream_out << "Graph adjacency list:" << std::endl;
    int i = 1;
    for (auto& x : graph.adj_list) {
        stream_out << i << ':';
        for (int y : x) {
            stream_out << ' ' << y + 1;
        }
        stream_out << std::endl;
        ++i;
    }
}

template <typename T>
void PrintGraphAsEdgesList(Graph& graph, T& stream_out) {
    stream_out << "Graph edges list:" << std::endl;
    for (auto x : graph.edges_list) {
        stream_out << x.first << ' ' << x.second << std::endl;
    }
}

template <typename T>
void PrintDFSAndBFSWork(Graph& graph, T& stream_out) {
    stream_out << "DFS (with recursion):" << std::endl;
    for (int v = 0; v < graph.vertices_number; ++v) {
        if (!graph.rec_dfs_used[v]) {
            graph.RecDFS(v, stream_out);
        }
    }
    stream_out << "DFS:" << std::endl;
    for (int v = 0; v < graph.vertices_number; ++v) {
        if (!graph.dfs_used[v]) {
            graph.DFS(v, stream_out);
        }
    }
    stream_out << "BFS:" << std::endl;
    for (int v = 0; v < graph.vertices_number; ++v) {
        if (!graph.bfs_used[v]) {
            graph.BFS(v, stream_out);
        }
    }
}
