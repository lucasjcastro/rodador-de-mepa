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
	std::cout << "DEBUG LALALA" << std::endl;
	int index = 40;
	std::cout << "comando = " << vetor_resultado[index].comando << std::endl;
	std::cout << "label = " << vetor_resultado[index].label << std::endl;
	std::cout << "para1 = " << vetor_resultado[index].parametro1 << std::endl;
	std::cout << "para2 = " << vetor_resultado[index].parametro2 << std::endl;
}
