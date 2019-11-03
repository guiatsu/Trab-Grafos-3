#include "../includes/Graph.hpp"
Escola::Escola(int id){
    this -> id = id;
}
bool Escola::vazia(){
    for(auto i : vagas){
        if(i -> prof != NULL){
            return false;
        }
    }
    return true;
}
void Escola::print(){
    cout << "Escola " << id << ":" << endl;
    cout << "Vagas-Requisitos: " << vagas.size() << endl;
    int cont = 1;
    for(auto i : vagas){
        cout << "Vaga[" <<cont<<"]: " << i -> hab -> hab << " Habilitacoes" << endl;
        cont++;
    }
    for(auto i : vagas){
        if(i -> prof != NULL)
            cout <<"Professor contratado: " <<  i -> prof -> id << endl;
    }
}

Professor::Professor(int id){
    this -> id = id;
    esc_escolhida = NULL;
    excl = 0;
}
void Professor::pior_escola(){
    Escola *aux = quer_prof[0];
    int index = -5;
    int pref = -5;
    for(int i = 0; i<quer_prof.size(); i++){
        for(int j = 0; j< esc_pref.size(); j++){
            if(quer_prof[i] -> id == esc_pref[j]){
                if(j > pref){
                    index = i;
                    pref = j;
                }
            }
        }
    }
    for(auto i : quer_prof[index] ->vagas){
        if(i -> prof == this){
            i -> prof = NULL;
        }
    }
    quer_prof.erase(quer_prof.begin()+index);
}
void Professor::delete_suc(Escola *esc){
    int index = 0;
    for(int i = 0;i < esc_pref.size(); i++){
        if(esc_pref[i] == esc -> id){
            index = i;
        }
        for(auto j = 0;j < esc_pref.size(); j++){
            if(j > index){
                esc_pref.erase(esc_pref.begin()+j);
            }
        }
    }
}

bool Professor::quer_esc(Escola *esc){
    for(auto i : esc_pref){
        if(esc -> id == i){
            return true;
        }
    }
    return false;
}
void Professor::print(){
    cout << "Professor " << id << ":" << endl;
    cout << "Escolas de Preferencia " << esc_pref.size() << endl;
    int cont = 1;
    for(auto i : esc_pref){
        cout << "Escola[" <<cont<<"]: "<< i << endl;
        cont++;
    }
    cout << "Habilitacoes: " << hab -> hab << endl;
    if(this -> esc_escolhida != NULL){
        cout << "escola escolhida: " << endl;
        cout << esc_escolhida -> id << endl;
    }
}
Habilitacao::Habilitacao(int hab){
    this -> hab = hab;
}