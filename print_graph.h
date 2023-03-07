#include <iostream>
#include <utility>
#include <vector>
#include "graph.h"

/*
 * Функция, которая печатает (полу)степени графа,
 * используя его представление в виде списка смежности
 * (для ориентированного графа считаются степени исхода).
 */
template <typename T>
void PrintGraphDegreesCount(Graph& graph, T& stream_out);

/*
 * Функция, которая печатает число рёбер/дуг графа,
 * используя его представления в виде матрицы инцидентности и списка рёбер.
 */
template <typename T>
void PrintGraphEdgesCount(Graph& graph, T& stream_out);

/*
 * Функция, которая печатает граф в виде матрицы смежности.
 */
template <typename T>
void PrintGraphAsAdjacencyMatrix(Graph& graph, T& stream_out);

/*
 * Функция, которая печатает граф в виде матрицы инцидентности.
 */
template <typename T>
void PrintGraphAsIncidenceMatrix(Graph& graph, T& stream_out);

/*
 * Функция, которая печатает граф в виде списка смежности.
 */
template <typename T>
void PrintGraphAsAdjacencyList(Graph& graph, T& stream_out);

/*
 * Функция, которая печатает граф в виде списка рёбер.
 */
template <typename T>
void PrintGraphAsEdgesList(Graph& graph, T& stream_out);

/*
 * Функция, которая печатает порядок обхода вершин в глубину и ширину
 * (результаты рекурсивного и нерекурсивного дфс могут получаться разными,
 * но они оба по определению корректны).
 */
template <typename T>
void PrintDFSAndBFSWork(Graph& graph, T& stream_out);
