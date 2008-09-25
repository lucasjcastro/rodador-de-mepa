#include "gerenciadorMemoria.h"
#include "pagina.h"
#include "coordenadas.h"

//lance da divisao
//retorna -1 na posição 0 da struct caso o endereço nao esteja mapeado
//exemplo insercao no mapa:
//tabela.insert(std::pair<int,int>(2,7));
coordenadas gerenciadorMemoria::resolverEndereco(int endereco, string processoAtivo){
	int paginaCorrente, linhaCorrente;	
	coordenadas resultado;
	
	pagina obj;	
	paginaCorrente = endereco/obj.tamanhoPagina;	
	linhaCorrente =  endereco%obj.tamanhoPagina;
	
	// Imprime página e linha
	cout << "Numero da pagina: " << tabela[paginaCorrente] << endl << "Numero da linha: " << linhaCorrente << endl << endl;	
	
	std::map<int,int>::iterator itr = tabela.lower_bound(paginaCorrente);
	std::map<int,int>::key_compare cmp = tabela.key_comp();
	
	
	cout << "pagina eh " << tabela[paginaCorrente] << endl;
	
        
    //verifica se o endereço esta mapeado na memoria fisica
    //existe:   
    if(tabela.end() != itr && !cmp(paginaCorrente,(*itr).first)){
    	//quociente da divisao
    	//cout << "Encontraram-me" << endl;
        //system("pause");
    	
    	resultado.coord1 = tabela[(endereco/obj.tamanhoPagina)];
    //nao existe:
}    else
    	resultado.coord1 = -1;
    	
    //resto da divisao
    resultado.coord2 = (endereco%obj.tamanhoPagina);
    
    return resultado;
};


void gerenciadorMemoria::atualizaTabela(int pagina_saiu, int pagina_colocada, int endereco){
	//itr - é atribuida a ela o par cuja chave é a pagina que saiu da memoria principal
	std::map<int,int>::iterator itr = tabela.lower_bound(pagina_saiu);
     cout << "actually.1" << endl;
           system("pause");
     
	//apaga par que itr aponta
	tabela.erase(itr);
	
	cout << "actually.2" << endl;
           system("pause");
     
	//insere novo par no mapa
	tabela.insert(std::pair<int,int>(pagina_colocada,endereco));
	
	cout << "Pagina colocada: " << pagina_colocada << "   e onde: " << tabela[pagina_colocada] << endl;
    system("pause");
	
	
	
};


void gerenciadorMemoria::iniciaTabela(int pagina_colocada, int endereco){
	//insere novo par no mapa
	tabela.insert(std::pair<int,int>(pagina_colocada,endereco));
};
