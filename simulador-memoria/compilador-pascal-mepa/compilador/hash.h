/*
 * Esta biblioteca consta de:
 * 
 * - CLASSE HASHCELL -
 *  
 * hashCell(string id, string cat); -> Construtor que inicializa a célula da tabela Hash. Recebe como
 *                                  parâmetros o identificador e sua categoria. 
 * 
 * Funções 'get[atributo]';  -> Retornam o atributo em questão (formalismo de encapsulamento).
 * 
 * Funções 'set[atributo]';  -> Inserem um valor no atributo (formalismo de encapsulamento). 
 * 
 *
 * - Categorias de um identificador -
 *
 * # variavel
 * 
 * # parametro
 *
 * # procedimento
 *
 * # funcao
 *
 * ////////////////////////////////////////////////////////////////////////////////////////
 * 
 *  - CLASSE HASH -
 * 
 * int getHashNumba(string palavra);  -> É a função hash em si. Recebe o identificador e retorna o 
 *                                    número hash correspondente.  
 * 
 * void setHash(string palavra, string categoria);  -> Inicializa uma célula hash. Recebe o identificador
 *                                                  e a categoria. Cria-se uma célula hash e esta é alocada  
 *                                                  na tabela com os atributos já disponíveis.  
 * 
 * int checkHash(string palavra);  -> Retorna '1' caso o identificador em questão já esteja na tabela, e '0' no
 *                                 caso contrário.
 *
 * Funções 'get[atributo]';  -> Retornam o valor do atributo em questão.
 *
 * Funções 'set[atributo]';  -> Inserem um valor no atributo em questão.
 *
 */

#ifndef HASH_H_
#define HASH_H_
#include <iostream>
#include <map>

using namespace std;

class hashCell{
      public:
         hashCell(string id, string cat);
         
         string getIdentificador();
         string getCategoria();
         int getNivel();
         string getTipo();
         int getDeslocamento();
         int getPassagem();
         string getRotulo();
         int getN();
      
         void setNivel(int nivelValue);
         void setTipo(string tipoValue);
         void setDeslocamento(int deslocamentoValue);
         void setPassagem(int passagemValue);
         void setRotulo(string rotuloValue);
         void setN(int nValue);
                  
         hashCell *next;
                  
      private:
                  
         string identificador;
         string categoria;   
         int nivel;
          
         //CHECAR
         string tipo;
         int deslocamento;
         int passagem;
         string rotulo;
         int n;            

};


class hash{
      public:
         hash();
         
         void setHash(string palavra, string categoria);        // inserir identificador
         
         int getHashNumba(string palavra);
         int checkHash(string palavra, string categoria);
                  
         string getCategoria(string palavra);
         int getNivel(string palavra);
         string getTipo(string palavra);
         int getDeslocamento(string palavra);
         int getPassagem(string palavra);
         string getRotulo(string palavra);
         int getN(string palavra);
         
         void setNivel(string palavra, int nivel);
         void setTipo(string palavra, string tipo);
         void setDeslocamento(string palavra, int deslocamento);
         void setPassagem(string palavra, int passagem);
         void setRotulo(string palavra, string rotulo);
         void setN(string palavra, int n);
         
         
      private:
         map<int, hashCell *>  hashTable;
         
         int HASHBIAS,
             HASHMAX;
         
};
#endif
