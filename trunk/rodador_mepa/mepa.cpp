#include <iostream>
#include <fstream>
#include <string>
#include "mepa.h"
#include "node.h"

using namespace std;

mepa::mepa(){
   s = -1;
   i = 0;
};


void mepa::traducao(std::vector<node> comandos){   
	while(comandos[i].comando != "PARA"){
		if(comandos[i].comando == "CRCT"){
			crct(comandos[i]);
		}else if(comandos[i].comando == "CRVL"){
			crvl(comandos[i]);
		}else if(comandos[i].comando == "SOMA"){
			soma();
		}else if(comandos[i].comando == "SUBT"){
			subt();
		}else if(comandos[i].comando == "MULT"){
			mult();
		}else if(comandos[i].comando == "DIVI"){
			divi();
		}else if(comandos[i].comando == "CMIG"){
			cmig();
		}else if(comandos[i].comando == "CMMA"){
			cmma();
		}else if(comandos[i].comando == "CMME"){
			cmme();
		}else if(comandos[i].comando == "CMDG"){
			cmdg();
		}else if(comandos[i].comando == "CONJ"){
			conj();
		}else if(comandos[i].comando == "DISJ"){
			disj();
		}else if(comandos[i].comando == "NEGA"){
			nega();
		}else if(comandos[i].comando == "INVR"){
			invr();
		}else if(comandos[i].comando == "ARMZ"){
			armz(comandos[i]);
		}else if(comandos[i].comando == "LEIT"){
			leit();
		}else if(comandos[i].comando == "IMPR"){
			impr();
		}else if(comandos[i].comando == "NADA"){
			nada();
		}else if(comandos[i].comando == "DSVS"){
			dsvs();
		}else if(comandos[i].comando == "DSVF"){
			dsvf();
		}else if(comandos[i].comando == "INPP"){
			inpp();
		}else if(comandos[i].comando == "AMEM"){
			amem(comandos[i]);
		}else if(comandos[i].comando == "DMEM"){
			dmem(comandos[i]);
		}else if(comandos[i].comando == "CREN"){
			cren(comandos[i]);
		}else if(comandos[i].comando == "CHPR"){
			chpr(comandos[i]);
		}else if(comandos[i].comando == "ENPR"){
			enpr(comandos[i]);
		}else if(comandos[i].comando == "RTPR"){
			rtpr(comandos[i]);
		}else if(comandos[i].comando == "CRVI"){
			crvi(comandos[i]);
		}else if(comandos[i].comando == "ARMI"){
			armi(comandos[i]);
		}
		/*else if(comandos[i].comando == "PARA"){
			break;
		}*/
	}
};


void mepa::crct(node comando){
   s = s + 1;
   //M[s] = comando.parametro1;
   i = i + 1;
};

void mepa::crvl(node comando){
	s = s + 1;   
	M[s] = M[comando.parametro1];
	i = i + 1;
}

void mepa::soma(){
	M[s-1] = M[s-1] + M[s];
	s = s-1;
	i = i+1;
}

void mepa::subt(){
	M[s-1] = M[s-1] - M[s];
	s = s-1;
	i = i+1;
}

void mepa::mult(){
	M[s-1] = M[s-1] * M[s];
	s = s-1;
	i = i+1;
}

void mepa::divi(){
	if(M[s] == 0)
		return;
	M[s-1] = M[s-1]/M[s];     
	s = s-1;
	i = i+1;
}

void mepa::cmig(){
	
}

void mepa::cmma(){
	
}

void mepa::cmme(){
	
}

void mepa::cmag(){
	
}

void mepa::cmeg(){
	
}

void mepa::cmdg(){
	
}

void mepa::conj(){
	
}

void mepa::disj(){
	
}

void mepa::nega(){
	
}

void mepa::invr(){
	
}

void mepa::armz(node comando){
	
}

void mepa::leit(){
	
}

void mepa::impr(){
	
}

void mepa::nada(){
	
}

void mepa::dsvs(){
	
}

void mepa::dsvf(){
	
}

void mepa::inpp(){
	
}

void mepa::amem(node comando){
	
}

void mepa::dmem(node comando){
	
}

void mepa::para(){
	
}

void mepa::chpr(node comando){
	
}

void mepa::enpr(node comando){
	
}

void mepa::rtpr(node comando){
	
}

void mepa::crvi(node comando){
	
}

void mepa::armi(node comando){
	
}

void mepa::cren(node comando){
	
}


////////////////////////////////////////////////////////////////////////////////
     
   /*else if
	   word == "SOMA" ||
	   word == "SUBT" ||
	   word == "MULT" ||
	   word == "DIVI" ||
	   word == "CMIG" ||
	   word == "CMMA" ||
   	   word == "CMME" ||
   	   word == "CMEG" ||
   	   word == "CMDG" ||
   	   word == "CONJ" ||
	   word == "DISJ" ||
	   word == "NEGA" ||
	   word == "INVR" ||
	   word == "ARMZ" ||
	   word == "LEIT" ||
   	   word == "IMPR" ||
   	   word == "NADA" ||
   	   word == "DSVS" ||
   	   word == "DSVF" ||
   	   word == "INPP" ||
   	   word == "AMEM" ||
   	   word == "DMEM" ||
	   word == "PARA" ||
	   word == "CHPR" ||
	   word == "ENPR" ||
	   word == "RTPR" ||
	   word == "CRVI" ||
   	   word == "ARMI" ||
   	   word == "CREN")
     
  */
