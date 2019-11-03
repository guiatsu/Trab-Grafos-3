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
bool Graph::tem_esc_vazia(){
    for(auto i : escolas){
        if(i -> vazia()){
            return true;
        }
    }
    return false;
}
Escola *Graph::primeira_esc_vazia(){
    for(auto i : escolas){
        if(i -> vazia()){
            return i ;
        }
    }
}
void Graph::empar(){
    vector<Professor *> profs;
    
    while(tem_esc_vazia()){
        Escola *escola = primeira_esc_vazia();
        Habilitacao *aux = escola -> vagas[0] -> hab;
        for(auto i : professores){
            if(i -> hab -> hab >= aux -> hab){
                profs.push_back(i);
            }
        }
        for(auto i : profs){
            if(i -> quer_esc(escola)){
                escola -> vagas[0] -> prof = i;
                i -> quer_prof.push_back(escola);
                break;
            }
        }
        if(escola -> vagas[0] ->prof -> quer_prof.size() > 1){
            escola -> vagas[0] -> prof -> pior_escola();
        }
        if(escola -> vagas[0] -> prof -> quer_prof.size() == 1){
            escola -> vagas[0] -> prof -> delete_suc(escola);
        }
        cout << escola -> id << endl;


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
    vector<Habilitacao *> hab;
    hab.push_back(new Habilitacao(1));
    hab.push_back(new Habilitacao(2));
    hab.push_back(new Habilitacao(3));
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
                int id = stoi(words[0].substr(1,words[0].length())) - 1;
                int qualif = stoi(words[1]);
                hab[qualif-1] -> professores.push_back(professores[id]);
                professores[id] -> hab = hab[qualif-1];
                for(int i = 2; i < words.size();i++){
                    int esc_id = stoi(words[i].substr(1,words[i].length()-1));
                    professores[id] -> esc_pref.push_back(esc_id);
                }
            }
            if(words[0][0] == 'E'){
                int id = stoi(words[0].substr(1,words[0].length()))-1;
                for(int i = 1; i < words.size();i++){
                    vaga *aux = new vaga;
                    aux ->hab = hab[stoi(words[i]) - 1];
                    aux -> prof = NULL;
                    escolas[id] -> vagas.push_back(aux);
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