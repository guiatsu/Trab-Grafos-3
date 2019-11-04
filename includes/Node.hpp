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
            bool aceitavel(Escola *node);
            Professor(int id);
            void print();
    };
    typedef struct Vaga{
        int hab;
        Professor *prof;
    }vaga;
    class Escola {
        public:
        int id;
        vector<vaga *> vagas; 
        Escola(int id);
        bool aceitavel(Professor *node);
        Professor* pref(Professor *node);
        bool vazia();
        void print();
    };

#endif