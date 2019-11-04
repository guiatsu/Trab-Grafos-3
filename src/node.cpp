#include "../includes/Graph.hpp"
Escola::Escola(int id){
    this -> id = id;
}
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
bool Escola::aceitavel(Professor *node){
    for(auto i : vagas){
        if(node -> qualif >= i -> hab)
            return true;
    }
    return false;
}
bool Escola::vazia(){
    for(auto i : vagas){
        if(i -> prof != NULL)
            return false;
    }
    return true;
}
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
bool Professor::aceitavel(Escola *node){
    for(auto i : esc_pref){
        if(node -> id == i)
            return true;
    }
    return false;
}
Professor::Professor(int id){
    this -> id = id;
    esc_escolhida = NULL;
    excl = 0;
}
void Professor::print(){
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