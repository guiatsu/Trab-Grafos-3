#include "../includes/Graph.hpp"

int main(){
    Graph *grafo = new Graph();
    grafo -> empar();
    int cont = 0;
    for(auto i : grafo -> professores){
        i ->print();
        cout << endl;
        if(i ->esc_escolhida == NULL)
            cont++;
    }
    for(auto i : grafo -> escolas){
        i -> print();
        cout << endl;
    }
    cout << 100 - cont << " Professores foram contratados sem desestabilizar o emparelhamento" << endl;
    
    


    return 1;
}