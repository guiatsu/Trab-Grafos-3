#include "../includes/Graph.hpp"

int main(){
    Graph *grafo = new Graph();
    grafo -> empar();
    for(auto i : grafo -> professores){
        if(i -> esc_escolhida == NULL)
        i ->print();
    }
    


    return 1;
}