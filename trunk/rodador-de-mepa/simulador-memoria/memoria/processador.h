#ifndef PROCESSADOR_H_
#define PROCESSADOR_H_

#include "gerenciadorMemoria.h"
#include "gerenciadorProcessos.h"
#include <list>

class processador{
      
      public:
             processador(memorias *alocar);
             void run();      
             
             void carregarEstado(int endereco);             
             string carregarInstrucao(int endereco);
             int carregarPaginas(string processo);             
             
      private:
              int endereco;
              string nomeProcesso;             
              
              gerenciadorMemoria memManager;
              gerenciadorProcessos proManager;
              
              memorias *memorizu;
};
#endif
