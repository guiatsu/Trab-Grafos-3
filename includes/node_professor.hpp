#ifndef NODE_PROFESSOR_HPP
#define NODE_PROFESSOR_HPP

#include <iostream>
#include <vector>

#include "node_escola.hpp"

    class Escola;

    class Professor {

        public:

            int id;
            int qualif;
            int excl;
            std::vector <int> esc_pref;
            Escola *esc_escolhida;

            Professor(int id);
            bool aceitavel(Escola *node);
            void print();
    };

#endif //NODE_PROFESSOR_HPP