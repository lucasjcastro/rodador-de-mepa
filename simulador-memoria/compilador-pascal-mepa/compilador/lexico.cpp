 /*
  * 0 = nada, buffer vazio
  * 1 = identificador
  * 2 = numero
  * 3 = char especial
  * 4 = char especial composto
  */

#include "lexico.h"
#include <fstream>
#include <string>
#include <iostream>
#include <list>
#include "tokentype.h"

using namespace std;

lexico::lexico()
{
}

lexico::~lexico()
{
}

void lexico::analisador_lexico(std::string filename){
	std::string token;
	char buffer;
	int linha = 1;
	int tipo = 0;
	int erro = 0;
	int comment = 0;
	int cont = 0;
		
	std::ifstream source(filename.c_str());
	while(cont < filename.length()){
		buffer = source.get();
		if(comment == 1){ //BLOCO PARA IGNORAR COMENTÁRIOS
			if(token.empty()){
				if(buffer == '*'){
					if(source.get() == ')'){
						token.push_back(buffer);
						source.unget();
						tipo = 4;
					}
				}
			}
			else{
				token.push_back(buffer);
				comment = 0;
				addtolist(token,tipo,linha,erro);
				token.clear();
				tipo = 0;
				erro = 0;
			}
		}		
        else{
			cout << "Checkpoint" << cont << endl;
     	system("pause");
            if(ischar(buffer)){ //TESTE SE BUFFER É CARACTERE
				if(token.empty()){
					tipo = 1;
					token.push_back(buffer);
				}
				else{
					if(tipo == 2){
						erro = 1; //ERRO: caractere presente em declaracao de numero
					}
					if(tipo == 3){
						addtolist(token,tipo,linha,erro);
						tipo = 1;
						erro = 0;
						token.clear();
					}
					token.push_back(buffer);
				}
			}
			if(isuline(buffer)){ //TESTE SE BUFFER É UNDERLINE
				if(token.empty()){
					erro = 2; //ERRO: identificador nao pode começar por underline
					tipo = 1;
					token.push_back(buffer);
				}
				else{
					if(tipo == 2){
						erro = 1; //ERRO: caractere presente em declaracao de numero
						token.push_back(buffer);
					}
					else{
						if(tipo == 1){
							token.push_back(buffer);
						}
						else{
							addtolist(token,tipo,linha,erro);
							tipo = 0;
							erro = 2; //ERRO: identificador nao pode começar por underline
							token.clear();
						}
					}
				}
			}
			if(isnum(buffer)){ //TESTE SE BUFFER É NÚMERO
				if(token.empty()){
					tipo = 2;
					token.push_back(buffer);
				}
				else{
					if(tipo == 3){
						addtolist(token,tipo,linha,erro);
						tipo = 2;
						erro = 0;
						token.clear();
					}
					token.push_back(buffer);
				}
			}
			if(isspecchar(buffer)){ //TESTE SE BUFFER É CARACTERE ESPECIAL. tratamento de comentario
				if(token.empty()){
					tipo = 3;
					token.push_back(buffer);
				}
				else{
					if(tipo == 3){
						if(iscomposto(buffer)){
							tipo = 4;
							token.push_back(buffer);
							addtolist(token,tipo,linha,erro);
							tipo = 0;
							erro = 0;
							if(token == "(*"){
								comment = 1;
							}
							token.clear();
						}
						else{
							addtolist(token,tipo,linha,erro);
							tipo = 3;
							erro = 0;
							token.clear();
							token.push_back(buffer);
						}
					}
					else{
						addtolist(token,tipo,linha,erro);
						tipo = 3;
						erro = 0;
						token.clear();
						token.push_back(buffer);
					}
				}
			}
			if(buffer == '\n'){ //TESTE SE BUFFER É CARRIAGE RETURN
				if(!token.empty()){
					addtolist(token,tipo,linha,erro);
					tipo = 0;
					erro = 0;
					token.clear();
				}
				linha++;
			}
			if(buffer == ' ' || buffer == '\t'){ //TESTE SE BUFFER É ESPAÇO EM BRANCO
				if(!token.empty()){
					addtolist(token,tipo,linha,erro);
					tipo = 0;
					erro = 0;
					token.clear();
				}
			}
			if(isinvalid(buffer)){ //TESTE SE BUFFER É CARACTERE INVÁLIDO
				token.push_back(buffer);
				erro = 3; //ERRO: caractere invalido
			}
			if(tipo == 1 && buffer == '_' && erro == 0){
				token.push_back(buffer);
			}
		}
		cont++;
	}
}

int lexico::ischar(char caractere){
	if(caractere >= 65 && caractere <= 90) //UPPERCASE
		return 1;
	if(caractere >= 97 && caractere <= 122) //LOWERCASE
		return 1;
	return 0;
}

int lexico::isuline(char caractere){
	if(caractere == '_'){
		return 1;
	}
	return 0;
}

int lexico::isnum(char caractere){
	if(caractere >= 48 && caractere <= 57){
		return 1;
	}
	return 0;
}

int lexico::isspecchar(char caractere){
	if(caractere == '.' ||
       caractere == ';' ||
       caractere == ',' ||
       caractere == '(' ||
       caractere == ')' ||
       caractere == ':' ||
       caractere == '=' ||
       caractere == '<' ||
       caractere == '>' ||
       caractere == '+' ||
       caractere == '-' ||
       caractere == '*' ||
       caractere == '/' ||
       caractere == '{' ||
       caractere == '}'){
       return 1;
	}
	return 0;
}

int lexico::iscomposto(char caractere){
	if(caractere == '=' ||
       caractere == '*' ||
       caractere == ')' ||
       caractere == '>'){
		return 1;
	}
	return 0;
}

int lexico::isinvalid(char caractere){
	if(caractere == '@' ||
       caractere == '#' ||
       caractere == '$' ||
       caractere == '%' ||
       caractere == '¨' ||
       caractere == '&' ||
       caractere == '/' ||
       caractere == '?' ||
       caractere == '!' ||
       caractere == '^' ||
       caractere == '~' ||
       caractere == '\\'){
		return 1;
	}
	return 0;
}

void lexico::addtolist(std::string token, int tipo, int linha, int erro){
	tokentype novo;
	novo.nome = token;
	novo.tipo = tipo;
	novo.linha = linha;
	novo.erro = erro;
	
	if(token == "(*" || token == "*)"){
		return;
	}
	
	if(token == "program" ||
	   token == "label" ||
	   token == "type" ||
	   token == "array" ||
	   token == "of" ||
	   token == "var" ||
	   token == "procedure" ||
	   token == "function" ||
	   token == "begin" ||
	   token == "end" ||
	   token == "if" ||
	   token == "then" ||
	   token == "else" ||
	   token == "while" ||
	   token == "do" ||
	   token == "or" ||
	   token == "and" ||
	   token == "div" ||
	   token == "not"){
		novo.tipo = 5;
	}

	lista.push_back(novo);
}

void lexico::printlist(){
	std::list<tokentype>::iterator itr;
	itr = lista.begin();
	while(itr!=lista.end()){
		std::cout << (*itr).nome << " erro: " << (*itr).erro << " linha: " << (*itr).linha << " tipo: " << (*itr).tipo << std::endl;
		itr++;
	}
}

void lexico::printerror(){
	std::list<tokentype>::iterator itr;
	itr = lista.begin();
	while(itr!=lista.end()){
			if((*itr).erro == 1){
				std::cout << "ERRO: linha " << (*itr).linha << ": ";
				std::cout << "caractere presente em numero; " << (*itr).nome << std::endl;
			}
			if((*itr).erro == 2){
				std::cout << "ERRO: linha " << (*itr).linha << ": ";
				std::cout << "identificador nao pode comecar por underline; " << (*itr).nome << std::endl;
			}
			if((*itr).erro == 3){
				std::cout << "ERRO: linha " << (*itr).linha << ": ";
				std::cout << "caractere invalido presente; " << (*itr).nome << std::endl;
			}
			itr++;
	}
}

void lexico::printtype(){
	std::list<tokentype>::iterator itr;
	itr = lista.begin();
	while(itr!=lista.end()){
		if((*itr).erro == 0){
			std::cout << (*itr).nome << " -> ";
		}
		if((*itr).tipo == 1 && (*itr).erro == 0){
			std::cout << "identificador" << std::endl;
		}
		if((*itr).tipo == 2 && (*itr).erro == 0){
			std::cout << "numero" << std::endl;
		}
		if((*itr).tipo == 3 && (*itr).erro == 0){
			std::cout << "caractere especial" << std::endl;
		}
		if((*itr).tipo == 4 && (*itr).erro == 0){
			std::cout << "caractere especial composto" << std::endl;
		}
		if((*itr).tipo == 5 && (*itr).erro == 0){
			std::cout << "palavra reservada" << std::endl;
		}
		itr++;
	}
}


std::list<tokentype> lexico::getLista(){
   return lista;
}
