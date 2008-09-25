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
   
   
   while(1){   
      if(comandos[i].comando == "CRCT"){
         crct(comandos[i]);          
           
      }else if(comandos[i].comando == "CRVL"){
         //crvl(comandos[i]);         
         
      }else if(comandos[i].comando == "PARA"){
         break;         
      }      
   }     
};


void mepa::crct(node comando){
   s = s + 1;
   //M[s] = comando.parametro1;
   i = i + 1;     
};


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
