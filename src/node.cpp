#include "../includes/Graph.hpp"
Escola::Escola(int id){
    this -> id = id;
}
void Escola::print(){
    cout << "Escola " << id << ":" << endl;
    cout << "Vagas-Requisitos: " << vagas.size() << endl;
    int cont = 1;
    for(auto i : vagas){
        cout << "Vaga[" <<cont<<"]: " << i << " Qualificacoes" << endl;
        cont++;
    }
    if(!this ->professores.empty()){
        cout << "professores contratados" << endl;
        for(auto i : professores){
            if(i != NULL)
            cout << i ->id << endl;
        }
    }
}
Professor* Escola::pref(Professor *node){
    int id = node ->id;
    for(int i = 0; i < vagas.size();i++){
        if(professores[i] == NULL){
            if(((node ->qualif - vagas[i])+1) > 0){
                professores[i] = node;
                node ->esc_escolhida = this;
                node -> excl +=1;
                return NULL; 
            }
        }
        else{
            if(((node ->qualif - vagas[i] +1)> 0) && ((node ->qualif - vagas[i] +1) < (professores[i] -> qualif - vagas[i] + 1))){
                professores[i] -> esc_escolhida = NULL;
                Professor *aux = professores[i]; 
                professores[i] = node;
                node -> excl += 1;
                node -> esc_escolhida = this;
                return aux;
            }
        }
    } 
    node -> excl+=1;
    return node;
}
Professor::Professor(int id){
    this -> id = id;
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
    cout << "Qualificacoes: " << qualif << endl;
    if(this -> esc_escolhida != NULL){
        cout << "escola escolhida" << endl;
        cout << esc_escolhida << endl;
    }
}