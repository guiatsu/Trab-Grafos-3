#include "../includes/Graph.hpp"

int main(){
    Graph *grafo = new Graph();
    grafo -> empar();
    for(auto i : grafo -> professores){
        i ->print();
    }
    for(auto i : grafo -> escolas){
        i ->print();
    }



    return 1;
}