/*
 * Esta classe possui os seguintes métodos:
 * 
 * analisadorSintatico(); o cerne desta classe, realiza toda a lógica de análise
 * 
 * void pushPop(); -> atribui o valor mais à esquerda da lista do léxico à variável 'roller' da class,
 * em seguida exclui este valor da lista 
 *
 * void loadList(std::list<tokentype> loadUp); -> carrega a lista do léxico
 * 
 *
 * // Daqui em diante, as funções visam a análise de blocos específicos do código, 
 *    retornando ponteiros da subárvore montada. 
 *
 *
 * listaIdentificadores* ASlistaIdentificadores(); -> Análise sintática de lista de identificadores
 * 
 * bloco* ASbloco(); -> Análise sintática de bloco
 * 
 * declaraRotulos* ASdeclaraRotulos(); -> Análise sintática de declaração de rótulos
 * 
 * void addtolist(string,line); -> 
 * 
 * 
 *
 *
 *
 *
 *
 *
 * 
 * void printlist(); -> 
 * 
 * void printerror(); -> 
 */
 
 
#ifndef SINTATICO_H_
#define SINTATICO_H_
#include <list>
#include "tokentype.h"
#include "hash.h"
#include "arvore.h"

class sintatico
{
public:
	sintatico();
	virtual ~sintatico();
	
	string comparaTipo(string compare);
	string comparaRelacao(string compare);
	void pushPop();                          
	void loadList(std::list<tokentype> loadUp);
	void analisador_sintatico();
	
	
	listaIdentificadores* ASlistaIdentificadores();
	bloco* ASbloco();
	//declaraRotulos* ASdeclaraRotulos();
    //defineTipos* ASdefineTipos();
    declaraVariaveis* ASdeclaraVariaveis();
    declaraSubrotinas* ASdeclaraSubrotinas();
    comandoComposto* AScomandoComposto(); 
    comando* AScomando();
    comandoSemrotulo* AScomandoSemrotulo();
    
    parametrosFormais* ASparametrosFormais();
    atribuicao* ASatribuicao();
    variavel* ASvariavel();
    listaExpressoes* ASlistaExpressoes();
    expressao* ASexpressao();
    expressaoSimples* ASexpressaoSimples();
    termo* AStermo();
    fator* ASfator();
    chamadaFuncao* ASchamadaFuncao();
    comandoRepetitivo* AScomandoRepetitivo();
    comandoCondicional* AScomandoCondicional();
    chamadaProcedimento* ASchamadaProcedimento();
    
		
private:
    hash tabelaHash;    
    std::list<tokentype> lista;
    raiz carvalho;
    
    int nivelLexico,      // Variável guardando o nível léxico
        erro,             // Variável setada quando qualquer erro for encontrado no programa, encerrando sua execução   
	    vazio,            // Quando uma expressão não foi encontrada, mas pode não ser essencial para a que vem logo acima
        desloca;
    tokentype roller;     // tokentype que receberá o token mais à esquerda na lista para análise
};

#endif /*SINTATICO_H_*/
