#ifndef VAGA_HPP
#define VAGA_HPP

#include "node_professor.hpp"

// Struct que representa a vaga de emprego.
// Possui um campo inteiro para a quantidade de habilitacoes minimas requeridas
// Possui um campo do tipo Professor* para o professor que a ocupa

    class Professor;

    typedef struct Vaga{
        int hab;
        Professor *prof;
    } vaga;

#endif //VAGA_HPP