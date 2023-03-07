#include <iostream>
#include <string>
#include "graph.h"

/*
 * Функция, предлагающая пользователю
 * выбрать формат ввода графа.
 */
void PrintMenu();

/*
 * Из ответа пользователя (строки) получает целочисленный ответ
 * (для дальнейшего использования в switch-case).
 */
int GetAnswer(char options_number);

/*
 * Функция, предлагающая пользователю
 * выбрать способ ввода графа (консоль или файл).
 * Возвращает true, если выбран ввод через консоль.
 */
bool ConsoleInput();

/*
 * Функция, предлагающая пользователю
 * выбрать способ вывода графа (консоль или файл).
 * Возвращает true, если выбран вывод через консоль.
 */
bool ConsoleOutput();

/*
 * Функция, которая возвращает граф в представлении,
 * выбранном пользователем ранее.
 */
template <typename T>
Graph ReadGraph(T& stream_in);

/*
 * Функция, предлагающая пользователю вывести информацию о графе
 * (подсчет (полу)степеней вершин, рёбер/дуг графа,
 * вывод во всех представлениях, обход вершин в глубину и ширину).
 */
template <typename T>
void SelectGraphAction(Graph& graph, T& stream_out);

/*
 * Функция, предлагающая пользователю
 * продолжить работу с программой или завершить её.
 * Возвращает true, если выбран повтор решения.
 */
bool RepeatProgram();
