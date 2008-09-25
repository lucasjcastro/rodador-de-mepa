#ifndef MEMORIAS_H_
#define MEMORIAS_H_

#include <list>
#include <iostream>
#include <vector>
#include "pagina.h"

using namespace std;

class memorias{       
	public:
           memorias(){
              limiteFisica = 16;
              estadoFisica = 0;
           };           
           
           vector<pagina> memoriaVirtual;
           vector<pagina> memoriaFisica;
		   
		   int limiteFisica,
               estadoFisica,
               finalVirtual; 
};
#endif
