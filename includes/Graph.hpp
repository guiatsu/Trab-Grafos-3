#ifndef GRAPH_HPP
#define GRAPH_HPP

    #include <stack>
    #include <vector>
    #include <string>
    #include <sstream>
    #include <iostream>
    #include <queue>
    #include <cstring>
    #include <fstream>
    #include <regex>

    #include "node_professor.hpp"
    #include "node_escola.hpp"

    class Professor;
    class Escola;

    class Graph {

        public:
        std::vector<Escola *> escolas;
        std::vector<Professor *> professores;
        Graph();
        void add_prof(int id);
        void add_escol(int id);
        void empar();
    };

    std::vector<std::string> normalize( std::string line);

#endif //GRAPH_HPP