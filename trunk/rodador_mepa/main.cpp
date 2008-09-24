#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"

int main(int argc, char* argv[]){
	std::cout << "hello world" << std::endl;
	std::ifstream file(argv[1]);
	std::vector<node> vetor_resultado;
	//std::string linha;
	parser lalala;
	//lalala.printfile(argv[1]);
	vetor_resultado = lalala.parsefile(argv[1]);
	std::cout << vetor_resultado[0].comando << std::endl;
}
