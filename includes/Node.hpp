#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>

using namespace std;
    class Escola;
    class Professor {

        public:

            int id;
            int qualif;
            int excl;
            vector<int> esc_pref;
            Escola * esc_escolhida;

            Professor(int id);
            void print();
    };
    class Escola {
        public:
        int id;
        vector<int> vagas;
        vector<Professor *> professores;
        Escola(int id);
        Professor* pref(Professor *node);
        void print();
    };

#endif