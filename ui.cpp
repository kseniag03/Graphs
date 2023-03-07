#include "ui.h"

void PrintMenu() {
    system("cls");
    printf("\nIn what format do you want to enter the graph?\n");
    printf("1. Adjacency matrix\n");
    printf("2. Incidence matrix\n");
    printf("3. Adjacency list\n");
    printf("4. Edges list\n");
    printf("5. End program\n\n");
    printf("answer: ");
}

int GetAnswer(char options_number) {
    std::string input;
    std::getline(std::cin, input);
    while (static_cast<int>(input.size()) != 1 || !('1' <= input[0] && input[0] <= options_number)) {
        printf("Incorrect input. Try again: ");
        std::cout << input << std::endl;
        std::getline(std::cin, input);
    }
    return std::stoi(input);
}

bool ConsoleInput() {
    printf("\nHow do you want to enter the graph?\n");
    printf("1. Console input\n");
    printf("2. File input\n\n");
    printf("answer: ");
    int option = GetAnswer('2');
    switch (option) {
        case 1:
            return true;
        case 2:
            return false;
        default:
            return true;
    }
}

bool ConsoleOutput() {
    printf("\nHow do you want to display the information?\n");
    printf("1. Console output\n");
    printf("2. File output\n\n");
    printf("answer: ");
    int option = GetAnswer('2');
    switch (option) {
        case 1:
            return true;
        case 2:
            return false;
        default:
            return true;
    }
}

template <typename T>
Graph ReadGraph(T& stream_in) {
    int option;
    do {
        PrintMenu();
        option = GetAnswer('5');
        switch (option) {
            case 1:
                return GetAdjacencyMatrix(stream_in);
            case 2:
                return GetIncidenceMatrix(stream_in);
            case 3:
                return GetAdjacencyList(stream_in);
            case 4:
                return GetEdgesList(stream_in);
            case 5:
                return {};
            default:
                break;
        }
    } while (true);
}

template <typename T>
void SelectGraphAction(Graph& graph, T& stream_out) {
    printf("\nWhat do you want to do with the graph?\n");
    printf("1. Count degrees or half-degrees of vertices\n");
    printf("2. Count the number of edges or arcs\n");
    printf("3. Output in all 4 representations\n");
    printf("4. Show DFS and BFS work\n\n");
    printf("answer: ");
    int option = GetAnswer('4');
    switch (option) {
        case 1:
            PrintGraphDegreesCount(graph, stream_out);
            break;
        case 2:
            PrintGraphEdgesCount(graph, stream_out);
            break;
        case 3:
            PrintGraphAsAdjacencyMatrix(graph, stream_out);
            PrintGraphAsIncidenceMatrix(graph, stream_out);
            PrintGraphAsAdjacencyList(graph, stream_out);
            PrintGraphAsEdgesList(graph, stream_out);
            break;
        case 4:
            PrintDFSAndBFSWork(graph, stream_out);
            break;
        default:
            break;
    }
}

bool RepeatProgram() {
    printf("\nDo you want to continue working with the program?\n");
    printf("1. Yes\n");
    printf("2. No\n\n");
    printf("answer: ");
    int option = GetAnswer('2');
    switch (option) {
        case 1:
            return true;
        case 2:
            return false;
        default:
            return true;
    }
}
