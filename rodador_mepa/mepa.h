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
		
		void crvl(node comando);
		void soma();
		void subt();
		void mult();
		void divi();
		void cmig();
		void cmma();
		void cmme();
		void cmag();
		void cmeg();
		void cmdg();
		void conj();
		void disj();
		void nega();
		void invr();
		void armz(node comando);
		void leit();
		void impr();
		void nada();
		void dsvs();
		void dsvf();
		void inpp();
		void amem(node comando);
		void dmem(node comando);
		void para();
		void chpr(node comando);
		void enpr(node comando);
		void rtpr(node comando);
		void crvi(node comando);
		void armi(node comando);
		void cren(node comando);

	private:
		int s, i;
		//??? M, P;
             
};
#endif /*MEPA_H_*/
