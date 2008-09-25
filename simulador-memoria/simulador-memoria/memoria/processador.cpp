#include "processador.h"
#include "gerenciadorMemoria.h"
#include "coordenadas.h"
#include <iostream>

using namespace std;


processador::processador(memorias *alocar){   
   memorizu = alocar;   
   endereco = 0;
};                

void processador::run(){

     string instrucao = "finito!";     
     //int *enderecoFisico;
     pagina sidePagina;     
     coordenadas enderecoFisico;
              
     // Inicializa a paginação, recebendo o nome do primeiro processo a executar
     nomeProcesso = proManager.iniciarPaginas(memorizu, memManager);    
     
     do{        
        // Envia o endereço lógico, recebe o físico - ou um sinal de erro neste
        enderecoFisico = memManager.resolverEndereco(endereco, nomeProcesso);  
                   
        // Se a página não foi encontrada, carrega páginas para a memória física      
        if(enderecoFisico.coord1 == -1){
           cout << "Pretty bad actually." << endl;
           system("pause");
           
           proManager.carregarPaginas(memorizu, nomeProcesso, endereco, memManager);
           std::cout << "Troca de páginas concluida." << endl;
           enderecoFisico.coord1 = 0;
           system("pause");
           
        // Senão, carrega a instrução da memória física e "executa"
        }else{              
              
           //cout << "Pagina que chegou: " << enderecoFisico.coord1 << "  e linha: " << enderecoFisico.coord2 << endl << endl;
           //system("pause");
              
           sidePagina = memorizu->memoriaFisica[enderecoFisico.coord1];
           instrucao = sidePagina.comando[enderecoFisico.coord2];
           // "execução" de instrução
           std::cout << instrucao << endl << endl;               
           system("pause");
           endereco++;
        }
     }while(instrucao != "finito!");     
     cout << endl << endl << "I did it! I got the internets, darn it!!" << endl;
     system("pause");
};
