/*
 * Esta classe define o tipo utilizado para armazenar os tokens na lista.
 * 
 * Atributos:
 * 
 * string nome -> o token em si
 * int tipo -> a que tipo ele pertence (identificador, numero, etc...)
 * int linha -> a que linha ela pertence
 * int erro -> identifica se o token é ou não inválido. usado para emitir mensagem de erro
 */

#ifndef TOKENTYPE_H_
#define TOKENTYPE_H_

#include <string>

class tokentype
{
public:
	tokentype();
	virtual ~tokentype();
	
	std::string nome;
	int tipo;
	int linha;
	int erro;
};

#endif /*TOKENTYPE_H_*/
