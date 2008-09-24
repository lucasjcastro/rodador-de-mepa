/*
 * A responsabilidade dessa classe é processar o arquivo de entrada e retornar
 * uma lista que conterá todos os comandos MEPA em sequência
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "node.h"

class parser{
public:
	std::string linha;
	std::ifstream file;
	std::vector<node> vetor;
	
	//imprime conteudo do arquivo, pra debug
	void printfile(std::string);
	
	//retorna um vetor com os comandos
	std::vector<node> parsefile(std::string);
	
	//utilizado pelo parsefile, processa a linha que for dada à ela como parametro
	node parseline(std::string);
	
	//verifica se parametro é uma palavra chave do MEPA
	int iskeyword(std::string);
};
