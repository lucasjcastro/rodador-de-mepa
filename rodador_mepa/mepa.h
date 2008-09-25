/* 
 * A função dessa classe é executar a traducao propriamente dita da MEPA
 *
 */
#ifndef MEPA_H_
#define MEPA_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "node.h"

class mepa{
	public:
		//construtor
		mepa();
		
		//inicia analise da lista MEPA
		void traducao(std::vector<node> comandos);      
		
		//metodo para a instrucao CRCT
		void crct(node comando);             

	private:
		int s, i;
		//??? M, P;
             
};
#endif /*MEPA_H_*/
