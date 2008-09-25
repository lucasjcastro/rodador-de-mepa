#include "gerenciadorProcessos.h"
#include "gerenciadorMemoria.h"
#include "memorias.h"
#include "pagina.h"
#include <vector>

string gerenciadorProcessos::iniciarPaginas(memorias *memIniciadas, gerenciadorMemoria tabela){
       int estado = memIniciadas->estadoFisica;       
       string primeiroProcesso, processoCorrente;
       pagina sidePagina;
       
       vector<pagina> holding;
       
              
       // retira-se a primeira página da lista da memória virtual
       sidePagina = memIniciadas->memoriaVirtual[0];
       
       // retira-se o nome do processo dessa página, que será o primeiro a executar
       primeiroProcesso = sidePagina.processo;
       
       // adquiri-se o nome do processo corrente (útil se houvesse mais de um...)
       processoCorrente = primeiroProcesso;       
       
       // alocação de páginas da memória virtual para a física       
       while(estado < memIniciadas->limiteFisica  &&  estado < memIniciadas->memoriaVirtual.size()){
          sidePagina = memIniciadas->memoriaVirtual[estado];
          
          // checa se a página em questão ainda pertence ao mesmo processo
          if(sidePagina.processo != processoCorrente){
             break;                                 
          }else{     
             // insere página da memória virtual na física
             memIniciadas->memoriaFisica[estado] = memIniciadas->memoriaVirtual[estado];
             
             // Atualizar o estado da tabela de tradução do gerenciador de memória
             tabela.iniciaTabela(estado, estado);
             estado++;             
          }
       }       
       memIniciadas->estadoFisica = estado;       
       
       return primeiroProcesso;       
};

void gerenciadorProcessos::carregarPaginas(memorias *realocar, string nomeProcesso, int endereco, gerenciadorMemoria tabela){
     pagina sidePagina;
     
     int j=0, ultimaPagina, paginaSai, paginaEntra;
     
     // definindo a última página desse processo disponível na memória física
     ultimaPagina = endereco / sidePagina.tamanhoPagina;
     
     for (; j < realocar->limiteFisica && ultimaPagina < realocar->finalVirtual; j++, ultimaPagina++){
          sidePagina = realocar->memoriaVirtual[ultimaPagina];
          
          cout << "Roll mr ultima:" << ultimaPagina << "  e final Virtual: " << realocar->finalVirtual << endl;
           system("pause");
          
          // checa se a página em questão ainda pertence ao mesmo processo
          if(sidePagina.processo != nomeProcesso){
             break;                                 
          }else{
             // insere página da memória virtual na física
             paginaSai = realocar->memoriaFisica[j].ordenacao;
             paginaEntra = realocar->memoriaVirtual[ultimaPagina].ordenacao;
             
             realocar->memoriaFisica[j] = realocar->memoriaVirtual[ultimaPagina];
             
             cout << "Sai: " << paginaSai << "  e entra: " << paginaEntra << endl;
           system("pause");
             
             
             // Atualizar o estado da tabela de tradução do gerenciador de memória            
             tabela.atualizaTabela(paginaSai, paginaEntra, j);
             cout << "Roll mr." << endl;
           system("pause");
          }          
     }       
};
