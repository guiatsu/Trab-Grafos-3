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
    #include "Node.hpp"
    
    using namespace std;

    class Graph {

        public:
        vector<Escola *> escolas;
        vector<Professor *> professores;
        Graph();
        void add_prof(int id);
        void add_escol(int id);
        bool tem_esc_vazia();
        void empar();
        Escola *primeira_esc_vazia();

        // void make_dot();
    };
    vector<string> normalize( string line);
#endif