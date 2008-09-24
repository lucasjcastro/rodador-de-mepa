#include "parser.h"
//#include <fstream>
//#include

void parser::printfile(std::string filename){
	std::ifstream file(filename.c_str());
	//file.open("input.txt", std::ifstream::in);
	if(file.is_open()){
		while(!file.eof()){
			getline(file,linha);
			std::cout << linha << std::endl;
		}
		file.close();
	}
	else
		std::cout << "fail at life" << std::endl;
}

std::vector<node> parser::parsefile(std::string filename){
	std::ifstream file(filename.c_str());
	std::vector<node> vetor;
	if(file.is_open()){
		while(!file.eof()){
			getline(file,linha);
			//std::cout << linha << std::endl;
			vetor.push_back(parseline(linha));
			//parseline(linha);
		}
		file.close();
	}
	else
		std::cout << "fail at life" << std::endl;
	return vetor;
}

node parser::parseline(std::string linha){
	int flag_label = 0; //se ja tiver setado como 1, ou é o comando ou é parametro
	int flag_comando = 0; //se ja tiver setado, primeiro parametro foi armazenado
	int flag_parametro = 0; //para indicar se o primeiro parametro ja existe
	std::string::iterator itr;
	std::string buffer;
	node return_node;
	if(linha == "") //retorna nó vazio se a linha for vazia
		return return_node;
	//itera toda a linha
	for(itr = linha.begin() ; itr != linha.end() ; itr++){
		//se caractere nao for espaço, armazena na palavra
		if((*itr) != ' ')
			buffer.push_back((*itr));
		/*
		 * se for espaço (final de palavra), verifica se é palavra chave.
		 * se for, armazena no atributo comando e seta flag comando para 1
		 * se nao for, armazena no atributo label, e seta label para 1
		 * se comando ja tiver setado em um, só pode ser parametro. seta parametro para 1
		 * se parametro ja tiver setado, só pode ser segundo parametro
		 */
		else{
			std::cout << "WORD = " << buffer << std::endl;
			if(iskeyword(buffer)){
				flag_comando = 1;
				return_node.comando = buffer;
				buffer.clear();
			}
			else{
				//se nao for keyword e label for zero, entao é label
				if(flag_label == 0){
					flag_label = 1;
					return_node.label = buffer;
					buffer.clear();
				}
				else{
					//se comando e label ja existirem, entao é o primeiro parametro
					if(flag_parametro == 0){
						flag_parametro = 1;
						return_node.parametro1 = buffer;
						buffer.clear();
					}
					//se comando, label e o primeiro parametro ja existirem,
					//entao é o segundo parametro
					else{
						return_node.parametro2 = buffer;
						buffer.clear();
					}
				}
			}
		}
			
	}
	return return_node;
}

int parser::iskeyword(std::string word){
	if(word == "CRCT" ||
	   word == "CRVL" ||
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
   	   word == "CREN"){
		return 1;
	}
	else
		return 0;

}
