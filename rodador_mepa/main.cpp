#include <iostream>
#include <fstream>
#include <string>

void printfile(std::ifstream* file){
	std::string linha;
	if((*file).is_open()){
		while(!(*file).eof()){
			getline((*file),linha);
			std::cout << linha << std::endl;
		}
		(*file).close();
	}
	else
		std::cout << "fail at life" << std::endl;
}

int main(int argc, char* argv[]){
	std::cout << "hello world" << std::endl;
	std::ifstream file(argv[1]);
	//std::string linha;
	printfile(&file);
}