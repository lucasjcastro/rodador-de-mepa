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
	void printfile(std::string);
	std::vector<node> parsefile(std::string);
	node parseline(std::string);
	int iskeyword(std::string);
};
