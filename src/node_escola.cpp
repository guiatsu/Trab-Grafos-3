#include "../includes/node_escola.hpp"
#include "../includes/node_professor.hpp"
#include "../includes/vaga.hpp"

using std::cout;
using std::endl;

// Constructor da classe Escola
Escola::Escola(int id){
    this -> id = id;
}

// Metodo que printa os dados de um objeto do tipo Escola
void Escola::print(){
    cout << "Escola " << id << ": ";
    cout << "Vagas-Requisitos: " << vagas.size() << endl;
    int cont = 1;
    for(auto i : vagas){
        cout << "Vaga[" <<cont<<"]: " << i ->hab << " Habilitacoes" << endl;
        cont++;
    }
    if(!vazia()){

        cout << "professores contratados" << endl;
        for(auto i : vagas){
            if(i ->prof != NULL)
                cout << i ->prof -> id << endl;
        }
    }
    else{
        cout << "Nao Foram Contratados" << endl;
    }
}
// Verifica se um professor pode ocupar a vaga aberta na escola. Isto e, tem a quantidade minima de habilitacoes
bool Escola::aceitavel(Professor *node){
    for(auto i : vagas){
        if(node -> qualif >= i -> hab)
            return true;
    }
    return false;
}

// Retorna se a escola ainda nao tem um professor ocupando uma vaga
bool Escola::vazia(){
    for(auto i : vagas){
        if(i -> prof != NULL)
            return false;
    }
    return true;
}

// Metodo que associa o professor a uma escola
// Substitui um professor por outro caso seja melhor
Professor* Escola::pref(Professor *node){
    int id = node ->id;
    for(int i = 0; i < vagas.size();i++){
        if(vagas[i] -> prof == NULL){
            if(((node ->qualif - vagas[i] -> hab)+1) > 0){
                vagas[i] -> prof = node;
                node ->esc_escolhida = this;
                node -> excl +=1;
                return NULL; 
            }
        }
        else{
            if(((node ->qualif - vagas[i] -> hab +1)> 0) && ((node ->qualif - vagas[i] -> hab +1) < (vagas[i] -> prof -> qualif - vagas[i] -> hab + 1))){
                vagas[i] -> prof -> esc_escolhida = NULL;
                Professor *aux = vagas[i] -> prof; 
                vagas[i] -> prof = node;
                node -> excl += 1;
                node -> esc_escolhida = this;
                return aux;
            }
        }
    } 
    node -> excl+=1;
    return node;
}
