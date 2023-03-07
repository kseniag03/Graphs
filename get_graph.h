#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "graph.h"
#include "split.h"

/*
 * Функция, которая возвращает объект класса Graph
 * по переданному списку рёбер.
 */
Graph GetGraph(int vertices_number, bool isDirected, std::vector<std::pair<int, int>>& edges);

/*
 * Функция, которая считывает граф в формате матрицы смежности
 * и по этой матрице строит список рёбер.
 */
template <typename T>
Graph GetAdjacencyMatrix(T& stream_in);

/*
 * Функция, которая считывает граф в формате матрицы инцидентности
 * и по этой матрице строит список рёбер.
 */
template <typename T>
Graph GetIncidenceMatrix(T& stream_in);

/*
 * Функция, которая считывает граф в формате списка смежности
 * и по этому списку строит список рёбер.
 */
template <typename T>
Graph GetAdjacencyList(T& stream_in);

/*
 * Функция, которая считывает граф в формате списка рёбер
 * и по этому списку определяет кол-во вершин и тип графа
 * (ориентированный или неориентированный).
 */
template <typename T>
Graph GetEdgesList(T& stream_in);
