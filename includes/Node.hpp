#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>

using namespace std;
    class Escola;
    class Habilitacao;
    class Professor {

        public:

            int id;
            Habilitacao *hab;
            int excl;
            vector<int> esc_pref;
            vector<Escola *> quer_prof;
            Escola * esc_escolhida;
            bool quer_esc(Escola *esc);
            void pior_escola();
            void delete_suc(Escola *esc);
            Professor(int id);
            void print();
    };

    class Habilitacao{

        public:
            vector<Professor*> professores;
            int hab;
            Habilitacao(int hab);
    };

    typedef struct Vaga{
        Habilitacao *hab;
        Professor *prof;
    }vaga;
    
    class Escola {
        public:
        int id;
        vector<vaga *> vagas;
        Escola(int id);
        bool vazia();
        Professor* pref(Professor *node);
        void print();
    };

#endif