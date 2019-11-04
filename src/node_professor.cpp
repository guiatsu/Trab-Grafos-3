#include "../includes/node_professor.hpp"
#include "../includes/node_escola.hpp"
#include "../includes/vaga.hpp"

using std::cout;
using std::endl;

// Verifica se o professor deseja trabalhar na escola
bool Professor::aceitavel(Escola *node){
    for(auto i : esc_pref){
        if(node -> id == i)
            return true;
    }
    return false;
}

// Constructor da classe professor
Professor::Professor(int id){
    this -> id = id;
    esc_escolhida = NULL;
    excl = 0;
}

// Metodo que printa os dados de um objeto do tipo professor
void Professor::print() {

    cout << "Professor " << id << ":" << endl;
    cout << "Escolas de Preferencia " << esc_pref.size() << endl;
    int cont = 1;

    for(auto i : esc_pref){
        cout << "Escola[" <<cont<<"]: "<< i << endl;
        cont++;
    }

    cout << "Habilitacoes: " << qualif << endl;

    if(this -> esc_escolhida != NULL){
        cout << "escola escolhida: " << endl;
        cout << esc_escolhida -> id << endl;
    }
    else{
        cout << "DESEMPREGADO" << endl;
    }
}