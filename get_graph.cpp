#include "get_graph.h"

/*
 * Функция, которая возвращает объект класса Graph
 * по переданному списку рёбер.
 */
Graph GetGraph(int vertices_number, bool isDirected, std::vector<std::pair<int, int>>& edges) {
    Graph graph = Graph(vertices_number, isDirected, edges);
    for (auto & edge : edges) {
        graph.Add(edge.first - 1, edge.second - 1);
    }
    return graph;
}

/*
 * Функция, которая считывает граф в формате матрицы смежности
 * и по этой матрице строит список рёбер.
 */
template <typename T>
Graph GetAdjacencyMatrix(T& stream_in) {
    std::vector<std::vector<std::string>> matrix;
    std::string line;
    while(std::getline(stream_in, line)) {
        if (line == "stop") break;
        auto matrix_row = Split(line, ' ');
        matrix.push_back(matrix_row);
    }
    int vertices_number = static_cast<int>(matrix.size());
    bool isDirected = false;
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < vertices_number; ++i) {
        for (int j = 0; j < vertices_number; ++j) {
            if (matrix[i][j] == "1") {
                edges.emplace_back(i + 1, j + 1);
            }
            if (matrix[i][j] != matrix[j][i]) {
                isDirected = true;
            }
        }
    }
    return GetGraph(vertices_number, isDirected, edges);
}

/*
 * Функция, которая считывает граф в формате матрицы инцидентности
 * и по этой матрице строит список рёбер.
 */
template <typename T>
Graph GetIncidenceMatrix(T& stream_in) {
    std::vector<std::vector<std::string>> matrix;
    std::string line;
    while(std::getline(stream_in, line)) {
        if (line == "stop") break;
        auto matrix_row = Split(line, ' ');
        matrix.push_back(matrix_row);
    }
    int vertices_number = static_cast<int>(matrix.size());
    bool isDirected = false;
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < static_cast<int>(matrix[0].size()); ++i) {
        // по св-ву матрицы инцидентности неориентированного графа
        // сумма элементов матрицы по i-му столбцу равна 2.
        int sum = 0;
        for (int j = 0; j < vertices_number; ++j) {
            if (matrix[j][i].empty()) continue;
            sum += std::stoi(matrix[j][i]);
        }
        if (sum != 2) {
            isDirected = true;
        }
        for (int j = 0; j < vertices_number - 1; ++j) {
            for (int k = j + 1; k < vertices_number; ++k) {
                if (matrix[j][i] == "1" && matrix[k][i] == "1") {
                    edges.emplace_back(j + 1, k + 1);
                    edges.emplace_back(k + 1, j + 1);
                } else if (matrix[j][i] == "1" && matrix[k][i] == "-1") {
                    edges.emplace_back(j + 1, k + 1);
                } else if (matrix[j][i] == "-1" && matrix[k][i] == "1") {
                    edges.emplace_back(k + 1, j + 1);
                } else {
                    continue;
                }
            }
        }
    }
    return GetGraph(vertices_number, isDirected, edges);
}

/*
 * Функция, которая считывает граф в формате списка смежности
 * и по этому списку строит список рёбер.
 */
template <typename T>
Graph GetAdjacencyList(T& stream_in) {
    std::vector<std::pair<int, int>> edges;
    std::string line;
    while(std::getline(stream_in, line)) {
        if (line == "stop") break;
        auto list_row = Split(line, ' ');
        for (int i = 1; i < static_cast<int>(list_row.size()); ++i) {
            edges.emplace_back(std::stoi(list_row[0]), std::stoi(list_row[i]));
        }
    }
    int vertices_number = 0;
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> edges_pairs;
    for (auto& x : edges) {
        if (x.first > vertices_number) {
            vertices_number = x.first;
        }
        if (x.second > vertices_number) {
            vertices_number = x.second;
        }
        for (auto& y : edges) {
            if (x.first == y.second && x.second == y.first) {
                edges_pairs.emplace_back(x, y);
            }
        }
    }
    bool isDirected = edges_pairs.size() != edges.size();
    return GetGraph(vertices_number, isDirected, edges);
}

/*
 * Функция, которая считывает граф в формате списка рёбер
 * и по этому списку определяет кол-во вершин и тип графа
 * (ориентированный или неориентированный).
 */
template <typename T>
Graph GetEdgesList(T& stream_in) {
    std::vector<std::pair<int, int>> edges;
    std::string line;
    while(std::getline(stream_in, line)) {
        if (line == "stop") break;
        auto pair = Split(line, ' ');
        edges.emplace_back(std::stoi(pair[0]), std::stoi(pair[1]));
    }
    int vertices_number = 0;
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> edges_pairs;
    for (auto& x : edges) {
        if (x.first > vertices_number) {
            vertices_number = x.first;
        }
        if (x.second > vertices_number) {
            vertices_number = x.second;
        }
        for (auto& y : edges) {
            if (x.first == y.second && x.second == y.first) {
                edges_pairs.emplace_back(x, y);
            }
        }
    }
    bool isDirected = edges_pairs.size() != edges.size();
    return GetGraph(vertices_number, isDirected, edges);
}
