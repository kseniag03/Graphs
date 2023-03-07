#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#ifndef graph_h
#define graph_h

/*
 * Структура объекта граф.
 */
struct Graph {
private:
    /*
     * Словарь, который для каждого ребра хранит его номер в графе.
     * Необходим для хранения графа в виде матрицы инцидентности.
     */
    std::map<std::pair<int, int>, int> edges_number;

public:
    /* Число вершин графа. */
    int vertices_number = 0;

    /*
     * Флаг, определяющий тип графа
     * (ориентированный или неориентированный).
     */
    bool isDirected = false;

    /* Вектор для "покраски" вершин в два цвета (для рекурсивного дфс). */
    std::vector<int> rec_dfs_used;

    /* Вектор для "покраски" вершин в два цвета (для нерекурсивного дфс). */
    std::vector<int> dfs_used;

    /* Вектор для "покраски" вершин в два цвета (для бфс). */
    std::vector<int> bfs_used;

    /* Контейнер для хранения графа в виде матрицы смежности. */
    std::vector<std::vector<int>> adj_matrix;

    /* Контейнер для хранения графа в виде матрицы инцидентности. */
    std::vector<std::vector<int>> inc_matrix;

    /* Контейнер для хранения графа в виде списка смежности. */
    std::vector<std::vector<int>> adj_list;

    /* Контейнер для хранения графа в виде списка рёбер. */
    std::vector<std::pair<int, int>> edges_list;

    /*
     * Конструктор графа по умолчанию.
     */
    Graph() = default;

    /*
     * Конструктор графа, определяющий число вершин, тип и задающий список рёбер
     * (на основе которого задаются остальные представления).
     */
    explicit Graph (int vertices_number_, bool isDirected_, std::vector<std::pair<int, int>>& edges);

    /*
     * Метод, добавляющий ребро (v, u) в граф
     * (заполняет матрицу и список смежности и матрицу инцидентности).
     */
    void Add(int v, int u);

    /*
     * Рекурсивный обход в глубину.
     */
    template <typename T>
    void RecDFS(int v, T& stream_out);

    /*
     * Обход в глубину, реализация через стек.
     */
    template <typename T>
    void DFS(int w, T& stream_out);

    /*
     * Обход в ширину, реализация через очередь.
     */
    template <typename T>
    void BFS(int w, T& stream_out);
};

#endif
