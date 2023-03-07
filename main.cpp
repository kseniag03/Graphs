#include <iostream>
#include <fstream>
#include <string>
#include "get_graph.h"
#include "graph.h"
#include "print_graph.h"
#include "ui.h"

/*
 * Точка входа в программу.
 */
int main() {
    std::ofstream fout("../output.txt");
    do {
        std::ifstream fin("../input.txt");
        Graph graph;
        if (ConsoleInput()) {
            graph = ReadGraph(std::cin);
        } else {
            graph = ReadGraph(fin);
        }
        if (graph.adj_list.empty()) {
            return 0;
        }
        if (ConsoleOutput()) {
            SelectGraphAction(graph, std::cout);
            std::cout << std::endl;
        } else {
            SelectGraphAction(graph, fout);
            fout << std::endl;
        }
    } while (RepeatProgram());
    return 0;
}