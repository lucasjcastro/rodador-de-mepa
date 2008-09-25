#include "hash.h"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
/// CELULA HASH

hashCell::hashCell(string id, string cat)
{
   identificador = id;
   categoria = cat;
   
   if(categoria == "variavel"){
      passagem = 0;
      rotulo = "NULO";
      n = 0;      
   }else if(categoria == "parametro"){
      rotulo = "NULL";
      n = 0;
   }else if(categoria == "procedimento"){
      tipo = "NULL";
      deslocamento = 0;
      passagem = 0;
   }
   next = NULL;
   
};

////////////////////////////////////////////////////////

string hashCell::getCategoria(){
   return categoria;
};

////////////////////////////////////////////////////////

string hashCell::getIdentificador(){
   return identificador;
};

////////////////////////////////////////////////////////

int hashCell::getNivel(){
  return nivel;
};

////////////////////////////////////////////////////////

string hashCell::getTipo(){
   return tipo;
};

////////////////////////////////////////////////////////

int hashCell::getDeslocamento(){
   return deslocamento;
};

////////////////////////////////////////////////////////

int hashCell::getPassagem(){
   return passagem;
};

////////////////////////////////////////////////////////

string hashCell::getRotulo(){
   return rotulo;
};

////////////////////////////////////////////////////////

int hashCell::getN(){
   return n;
};

////////////////////////////////////////////////////////

void hashCell::setNivel(int nivelValue){
   nivel = nivelValue;
};

////////////////////////////////////////////////////////

void hashCell::setTipo(string tipoValue){
   tipo = tipoValue;
};

////////////////////////////////////////////////////////

void hashCell::setDeslocamento(int deslocamentoValue){
   deslocamento = deslocamentoValue;
};

////////////////////////////////////////////////////////

void hashCell::setPassagem(int passagemValue){
   passagem = passagemValue;
};

////////////////////////////////////////////////////////

void hashCell::setRotulo(string rotuloValue){
   rotulo = rotuloValue;
};

////////////////////////////////////////////////////////

void hashCell::setN(int nValue){
   n = nValue;
};


////////////////////////////////////////////////////////////////////////////////
/// TABELA HASH

hash::hash()
{
   HASHBIAS=7;
   HASHMAX=211;
};

////////////////////////////////////////////////////////

int hash::getHashNumba(string palavra){
   int i=0,
       hashNumber=0;
   
   for(; i<palavra.length(); i++){
      hashNumber = hashNumber*HASHBIAS + palavra[i];
   }
   hashNumber = hashNumber%HASHMAX;  
   
   return hashNumber;
};

////////////////////////////////////////////////////////

void hash::setHash(string palavra, string categoria){
   hashCell *insert;
   int hashId=0;
       
   insert = new hashCell(palavra, categoria);
   
   // Conseguir id da Hash   
   hashId = getHashNumba(palavra);  
      
   insert->next = hashTable[hashId];
   hashTable[hashId] = insert;   
};

////////////////////////////////////////////////////////

int hash::checkHash(string palavra, string categoria){
   hashCell *check;
   int hashId=0;
      
   // Conseguir id da Hash   
   hashId = getHashNumba(palavra);  
      
   check = hashTable[hashId];
   while(check!=NULL){
      if (check->getIdentificador() == palavra && check->getCategoria() == categoria){return 1;}
      else{check = check->next;}
   }   
   return 0;      
};

////////////////////////////////////////////////////////

string hash::getCategoria(string palavra){
   hashCell *retrieve;
   int hashId;
   string result,
          error = "notFound";
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }
   if(retrieve == NULL){
     return error;
   }else{
     result = retrieve->getCategoria();
     return result;
   }
};
   
////////////////////////////////////////////////////////   
   
int hash::getNivel(string palavra){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }
   if(retrieve == NULL){
     return 0;
   }else{
     result = retrieve->getNivel();
     return result;
   }
};    

////////////////////////////////////////////////////////   
   
string hash::getTipo(string palavra){
   hashCell *retrieve;
   int hashId;
   string result,
          error = "notFound";
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }
   if(retrieve == NULL){
     return error;
   }else{
     result = retrieve->getTipo();
     return result;
   }
};

////////////////////////////////////////////////////////   
   
int hash::getDeslocamento(string palavra){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }
   if(retrieve == NULL){
     return 0;
   }else{
     result = retrieve->getDeslocamento();
     return result;
   }
};

////////////////////////////////////////////////////////   
   
int hash::getPassagem(string palavra){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }
   if(retrieve == NULL){
     return 0;
   }else{
     result = retrieve->getPassagem();
     return result;
   }
};
         
////////////////////////////////////////////////////////   
   
string hash::getRotulo(string palavra){
   hashCell *retrieve;
   int hashId;
   string result,
          error = "notFound";
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }
   if(retrieve == NULL){
     return error;
   }else{
     result = retrieve->getRotulo();
     return result;
   }
};
       
////////////////////////////////////////////////////////   
   
int hash::getN(string palavra){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }
   if(retrieve == NULL){
     return 0;
   }else{
     result = retrieve->getN();
     return result;
   }
};        

//////////////////////////////////////////////////////////

void hash::setNivel(string palavra, int nivel){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }   
   retrieve->setNivel(nivel);
   
};   
   
//////////////////////////////////////////////////////////

void hash::setTipo(string palavra, string tipo){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }   
   retrieve->setTipo(tipo);
   
};
   
//////////////////////////////////////////////////////////

void hash::setDeslocamento(string palavra, int deslocamento){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }   
   retrieve->setDeslocamento(deslocamento);
   
};

//////////////////////////////////////////////////////////

void hash::setPassagem(string palavra, int passagem){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }   
   retrieve->setPassagem(passagem);
   
};

//////////////////////////////////////////////////////////

void hash::setRotulo(string palavra, string rotulo){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }   
   retrieve->setRotulo(rotulo);
   
};  

///////////////////////////////////////////////////////////
         
void hash::setN(string palavra, int n){
   hashCell *retrieve;
   int hashId,
       result;
   
   hashId = getHashNumba(palavra);
   retrieve = hashTable[hashId];
   
   while (retrieve->getIdentificador() != palavra && retrieve != NULL){
      retrieve = retrieve->next;
   }   
   retrieve->setN(n);
   
};

       

