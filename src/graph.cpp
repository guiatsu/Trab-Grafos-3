#include "../includes/Graph.hpp"
vector<string> normalize( string line){
    vector<string> aux;
    regex reg(":|,");
    regex reg2(" ");
    line = regex_replace(line,reg2,"");
    
    regex reg1("|\\(|\\)|");
    line = regex_replace(line,reg1,"");
    line = regex_replace(line,reg," ");
    
    string pars = " ";
    int pos = 0;
    while((pos = line.find(pars)) != string::npos){
        aux.push_back(line.substr(0,pos));
        line.erase(0,pos+pars.length());
    }
    aux.push_back(line);
    

    return aux;


}
void Graph::empar(){
    queue<Professor *> professores;
    for(auto i : this -> professores){
        professores.push(i);
    }
    while(!professores.empty()){
        Professor *aux = professores.front();
        if(aux -> esc_escolhida == NULL){
            if(aux -> excl < aux ->esc_pref.size()){
                Professor *res_pref = escolas[aux -> esc_pref[aux -> excl]-1] ->pref(aux); 
                if( res_pref ==  NULL){
                    professores.pop();
                }
                else if(res_pref != aux){
                    professores.pop();
                    professores.push(res_pref);
                }
            }
            else{
                if(!professores.empty()){
                    professores.pop();
                }
            }
        }
    }
}
void Graph::add_prof(int id){
    Professor *aux = new Professor(id);
    professores.push_back(aux);
}
void Graph::add_escol(int id){
    Escola *aux = new Escola(id);
    escolas.push_back(aux);
}
Graph::Graph(){
    fstream nodes;
    nodes.open("../files/professores.txt");
    if( !nodes.is_open() ) {
        cout << "ERRO AO ABRIR ARQUIVO TEXTO" << endl;
    }
    else{

        for(int i = 0; i < 100; i++){
            add_prof(i+1);
        }
        for(int i = 0; i < 50; i++){
            add_escol(i+1);
        }
        string line;
        vector<string> words;
        
        while( !nodes.eof() ) {
            
            getline(nodes,line);
            words = normalize(line);
            if(words[0][0] == 'P'){
                int id = stoi(words[0].substr(1,words[0].length()))-1;
                int qualif = stoi(words[1]);
                professores[id] -> qualif = qualif;
                for(int i = 2; i < words.size();i++){
                    int esc_id = stoi(words[i].substr(1,words[i].length()-1));
                    professores[id] -> esc_pref.push_back(esc_id);
                }
            }
            if(words[0][0] == 'E'){
                int id = stoi(words[0].substr(1,words[0].length()))-1;
                for(int i = 1; i < words.size();i++){
                    escolas[id] -> vagas.push_back(stoi(words[i]));
                    escolas[id] -> professores.push_back(NULL);
                }
            }
        }
        nodes.close();
    }
}
// void Graph::make_dot() {

//     ofstream out;
//     out.open("Graph.dot");

//     out << "graph Initial_Graph{\n";
//     out << "rankdir=LR;\n";
//     out << "ranksep = 4\n";
//     out << "\t" << "Ciencia_da_Computacao\n";
//     out << "subgraph cluster_0{\n";
//     for(auto i : professores)
//         out << "Prof" << i ->id << ";";
//     out << "\n}\n";
//     out << "subgraph cluster_1{\n";
//     for(auto i : escolas)
//         out << "Esc" <<  i ->id << ";";
//     out << "\n}\n";
//     for(auto i : professores){
//             if(i -> esc_escolhida != NULL)
//                 out << "\t" << "Prof" <<i -> id << " -- " << "Esc"<<i->esc_escolhida -> id << " [label = " << i -> qualif <<", color=red, penwidth = 3.0 ];\n";

//             for(auto j : i -> esc_pref) {
//                 if(i -> esc_escolhida != NULL)
//                     if(j == i-> esc_escolhida->id){
//                     }else
//                         out << "\t" << "Prof" << i -> id << " -- " << "Esc" << escolas[j-1] -> id << " [label = " << i -> qualif << "];\n";
//                 else
//                     out << "\t" << "Prof" << i -> id << " -- " << "Esc" << escolas[j-1] -> id << " [label = " << i -> qualif << "];\n";
                 
//             }
//     }
//     out << "}\n";
//     out.close(); 
//     system("dot -Tpng Graph.dot -o graph.png");
// }