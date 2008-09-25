#include <iostream>
#include <sstream>
#include "pagina.h"
#include "memorias.h"
#include "processador.h"

using namespace std;

int main(){
    int processos, linhas, j=0, i=0, h, sequencia=0;    
    string nomeProcesso, nomeInstrucao, buffer2;
    
    stringstream buffer;
    
    memorias *memorizu = new memorias();
    pagina alocada, troca;
            
	/*cout << "hello world" << endl;	
	cout << "Digite o número de processos a executar: ";
	cin >> processos;
	*/
	processos = 1;
	
    cout << "[Simulador de gerenciador de memoria.] " << endl << endl;
    cout << "- Memoria fisica de 16 paginas." << endl;
    cout << "- Paginas de 50 'linhas'." << endl;
    cout << "- Funcionando para apenas um processo." << endl;
    system("pause");	
	
	// Criando os programas
    for(; j< processos; j++){
          // Zerando variáveis          
          sequencia=0; 
          
          // Recolhendo dados sobre os programas/processos          
          //cout << endl << endl << "Digite o nome do processo: ";
          //cin >> nomeProcesso;
          nomeProcesso = "Processo default";
          
          cout << endl << "Digite o número de 'linhas' do processo: ";
          cin >> linhas;
          
          // Aloca o número total de linhas da memória virtual
          memorizu->finalVirtual = (linhas/alocada.tamanhoPagina) + 1;
                             
          // Lançando as páginas do programa na memória
          while(i < linhas){             
             alocada.processo = nomeProcesso;
             alocada.ordenacao = sequencia;             
             
             // Alocando instruções à página
             for(h=0; h < alocada.tamanhoPagina && i < linhas; h++, i++){                 
                 // Limpando valores                
                 
                 if(h+1 == linhas){
                   nomeInstrucao = "finito!";
                 }else{                        
                    nomeInstrucao = "Instrucao ";
                    buffer << i;
                    nomeInstrucao.append(buffer.str());
                    buffer.str("");
                 }
                 alocada.comando.push_back(nomeInstrucao); 
             }
             sequencia++;                
             memorizu->memoriaVirtual.push_back(alocada);      
             memorizu->memoriaFisica.push_back(alocada);           // Rever essa idéia...                         
             alocada.comando.clear();
          }                   
    }
    
    // Construindo processador, inserindo-lhe as memórias e rodando-o
    processador processar(memorizu);
    processar.run();
    
    return 0;	
};
