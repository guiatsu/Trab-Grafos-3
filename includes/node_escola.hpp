#ifndef NODE_ESCOLA_HPP
#define NODE_ESCOLA_HPP

#include <iostream>
#include <vector>

#include "node_professor.hpp"
#include "vaga.hpp"

 class Escola {

        public:

            int id;
            std::vector <vaga *> vagas;

            Escola(int id);
            bool aceitavel(Professor *node);
            Professor* pref(Professor *node);
            bool vazia();
            void print();
    };


#endif //NODE_ESCOLA_HPP