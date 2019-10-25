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
                Professor *res_pref = escolas[aux -> esc_pref[aux -> excl]] ->pref(aux); 
                if( res_pref ==  NULL){
                    cout << "ola" << endl;
                    professores.pop();
                }
                else if(res_pref != aux){
                    cout << "alo" << endl;
                    professores.push(res_pref);
                }
            }
            else{
                cout << "loa" << endl;
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
                professores[id] -> print();
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