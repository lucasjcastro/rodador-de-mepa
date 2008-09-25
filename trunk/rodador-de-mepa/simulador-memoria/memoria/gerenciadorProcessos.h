#ifndef GERENCIADORPROCESSOS_H_
#define GERENCIADORPROCESSOS_H_

#include <iostream>
#include "memorias.h"
#include "gerenciadorMemoria.h"

using namespace std;

class gerenciadorProcessos{
      public:
             string iniciarPaginas(memorias *memIniciadas, gerenciadorMemoria tabela);      
             void carregarPaginas(memorias *realocar, string nomeProcesso, int endereco, gerenciadorMemoria tabela);          // não inclui endereço pelo fato dessa 'demo' usar apenas um processo            
      
      private:
              memorias tabela;
      
};
#endif
