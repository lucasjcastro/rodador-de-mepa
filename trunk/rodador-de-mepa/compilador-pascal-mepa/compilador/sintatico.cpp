#include <iostream>
#include <list>
#include "sintatico.h"
#include "tokentype.h"
#include "arvore.h"

//using namespace std;

sintatico::sintatico()
{
   nivelLexico = 0;
   erro = 0;
   desloca = 0;
};

////////////////////////////////////////////////////////////////////////////////

sintatico::~sintatico()
{                      
};

////////////////////////////////////////////////////////////////////////////////

void sintatico::loadList(std::list<tokentype> loadUp){
   tokentype testim;
	
   testim.nome = "fim";
   testim.tipo = 0;
   testim.linha = 0;
   testim.erro = 0;   
   
   lista = loadUp;
   lista.push_back(testim);   
};

////////////////////////////////////////////////////////////////////////////////

void sintatico::pushPop(){       
  roller = lista.front();
  
  if(roller.nome != "fim"){
     lista.pop_front();  
  }
};

////////////////////////////////////////////////////////////////////////////////

string sintatico::comparaTipo(string compare){
      
   if(compare == "integer"){
      return "integer";
   }else if(compare == "char"){ 
       return "char";
   }else if(compare == "boolean"){
       return "boolean";
   }else if(compare == "real"){
       return "real";
   }else if(compare == "word"){
       return "word";
   }else if(compare == "longint"){
       return "longint";
   }else if(compare == "shortint"){
       return "shortint";
   }else if(compare == "byte"){
      return "byte";
   }else if(compare == "string"){
      return "string";
   }else{
      return "erro";
   }
};

////////////////////////////////////////////////////////////////////////////////

string sintatico::comparaRelacao(string compare){
      
   if(compare == "="){
      return "=";
   }else if(compare == "<>"){ 
       return "<>";
   }else if(compare == "<"){
       return "<";
   }else if(compare == "<="){
       return "<=";
   }else if(compare == ">"){
       return ">";
   }else if(compare == ">="){
       return ">=";
   }else{
      return "erro";
   }
};

////////////////////////////////////////////////////////////////////////////////

//  obs.: o comando "pushPop()" serve para passar para a próxima palavra 
// da lista recebida do léxico.

void sintatico::analisador_sintatico(){

   int inutil;     
   
   pushPop();      
   if(roller.nome == "program"){      
      pushPop();  
      //se token for identificador
      if(roller.tipo == 1){
         // [check] Analisar se essa linha é necessária, e completar a configuração hash:            
         tabelaHash.setHash(roller.nome, "procedimento");                  
         pushPop();
         if(roller.nome == "("){
            pushPop();
            carvalho.listaIdentificadores = ASlistaIdentificadores();
            if(erro){
               // [check] imprimir erro, interromper programa
            }else{
               if(roller.nome == ")"){                  
                  pushPop();                  
                  if(roller.nome == ";"){    
                     pushPop();              
                     carvalho.bloco = ASbloco();       
                  }else{
                     erro = 1;
                  }
               }else{
                  erro =1;      
               }
            }
         }else{
            erro = 1;
         }                 
      }else{
         erro = 1;
      }                
   }else{
      erro = 1;
   }
      
   if(erro){
      cout << "A palavra que deu treta foi '" << roller.nome << "', na linha " << roller.linha << ".";      
      cin >> inutil;
   }else{
      cout << "No errors, congratxus!";
      cin >> inutil;
   }
      
   //std::cout << "Under construction. Keep out, MO-FOS!" << std::endl << std::endl;
   //system("pause");	   
}

////////////////////////////////////////////////////////////////////////////////

listaIdentificadores* sintatico::ASlistaIdentificadores(){
  
  listaIdentificadores *listaTemp, *listaScroller;
  
  desloca = 1;
  if(roller.tipo == 1){
     // Configurando a entrada hash
     tabelaHash.setHash(roller.nome, "variavel");  
     tabelaHash.setNivel(roller.nome, nivelLexico);
     tabelaHash.setDeslocamento(roller.nome, desloca);
     
     // Configurando entrada da subárvore
     listaTemp->nome = roller.nome;
     listaTemp->next = listaScroller;
          
     pushPop();     
     while(roller.nome != ","){
        pushPop();
        desloca++;
        
        if(roller.tipo == 1){
           tabelaHash.setHash(roller.nome, "variavel");  
           tabelaHash.setNivel(roller.nome, nivelLexico);
           tabelaHash.setDeslocamento(roller.nome, desloca);
                      
           listaScroller->nome = roller.nome;
           listaScroller = listaScroller->next;
           
           pushPop();
        }else{
           erro = 1;
           break;
        }
     }
     listaScroller = NULL;
  }else{
     erro = 1;
  }
     
  return listaTemp;
}; 

////////////////////////////////////////////////////////////////////////////////

bloco* sintatico::ASbloco(){

   bloco *tempNode;

   //tempNode->rotulos = ASdeclaraRotulos();           // desnecessária
   //tempNode->defineTipos = ASdefineTipos();          // desnecessária
   tempNode->variaveis = ASdeclaraVariaveis();
   tempNode->subrotinas = ASdeclaraSubrotinas();
   if (!erro){
      tempNode->comandoComposto = AScomandoComposto();
   }   
      
   return tempNode;   
};

////////////////////////////////////////////////////////////////////////////////
/*  IGNORADO - NÃO EXIGIDO NO PRESENTE TRABALHO

declaraRotulos* sintatico::ASdeclaraRotulos(){
                
   declaraRotulos *tempNode, *listaScroller;
   int aux;
   
   if(roller.nome == "label"){
      pushPop();
      if(roller.tipo == 2){                     
         // [check] Consertar linha abaixo - converter string pra int            
         //tempNode->numero = roller.nome;
         tempNode->next = listaScroller;
         pushPop();
         while (roller.nome != ","){            
            pushPop();
            if(roller.tipo == 2){
               // [check] Consertar linha abaixo - converter string pra int
               //listaScroller->numero = roller.nome;
               listaScroller = listaScroller->next;               
            }else{
               erro = 1;
               break;
            }
            pushPop();
         }
         listaScroller = NULL;
         if(roller.nome != ";"){
            erro = 1;            
         }else{
            pushPop();
         }
      }else{
         erro = 1;
      }
   }else{
      tempNode = NULL;
   }   
   
   return tempNode;                
};
*/
////////////////////////////////////////////////////////////////////////////////
/* IGNORADO - NÃO EXIGIDO NO PRESENTE TRABALHO  
                              
defineTipos* sintatico::ASdefineTipos(){
             
   defineTipos *tempNode, *listaScroller;
   
   if(roller->nome == "type"){
      pushpop();
      tempNode->defineTipo = 
      
   else{
      tempNode == NULL;
   }
   
   return tempNode;   
};   
*/
////////////////////////////////////////////////////////////////////////////////
   
declaraVariaveis* sintatico::ASdeclaraVariaveis(){
  
   declaraVariaveis *tempNode, *listaScroller;
   listaIdentificadores *listaIDScroller;
   string holdType;      
      
   if(roller.nome == "var"){
      pushPop();
      tempNode->listaIdentificadores = ASlistaIdentificadores();
      if(erro){
         // [check] providencias de erro serão tomadas no método que chamou este.
         //break;
      }else{
         if(roller.nome == ":"){
            pushPop();
            holdType = comparaTipo(roller.nome);
            if(holdType == "erro"){
               erro = 1;
            }else{
               tempNode->tipoIdentificadores = holdType;
            }
         }else{
            erro = 1;
         }
         
         if(!erro){
            //alocar tipos aos identificadores na hash
            listaIDScroller = tempNode->listaIdentificadores;
            while(listaIDScroller != NULL){
               tabelaHash.setTipo(listaIDScroller->nome, holdType);
               listaIDScroller = listaIDScroller->next;
            }
            pushPop();
            if(roller.nome == ";"){
               
               // Desse ponto em diante, o programa começará a olhar por uma segunda,
               //terceira, n-ésima lista de declarações.
               pushPop();       
               tempNode->next = listaScroller;          
               while (roller.nome != "procedure" && roller.nome != "function" && roller.nome != "begin" && erro == 0){
                  listaScroller->listaIdentificadores = ASlistaIdentificadores();
                  if(erro){
                     // [check] providencias de erro serão tomadas no método que chamou este.
                      //break;
                  }else{
                     if(roller.nome == ":"){
                        pushPop();
                        if(roller.nome == "integer"){
                           listaScroller->tipoIdentificadores = "integer";
                           holdType = "integer";            
                        }else if(roller.nome == "char"){ 
                           listaScroller->tipoIdentificadores = "char";
                           holdType = "char";
                        }else if(roller.nome == "boolean"){
                           listaScroller->tipoIdentificadores = "boolean";
                           holdType = "boolean";
                        }else if(roller.nome == "real"){
                           listaScroller->tipoIdentificadores = "real";
                           holdType = "real";
                        }else if(roller.nome == "word"){
                           listaScroller->tipoIdentificadores = "word";
                           holdType = "word";
                        }else if(roller.nome == "longint"){
                           listaScroller->tipoIdentificadores = "longint";
                           holdType = "longint";
                        }else if(roller.nome == "shortint"){
                           listaScroller->tipoIdentificadores = "shortint";
                           holdType = "shortint";
                        }else if(roller.nome == "byte"){
                           listaScroller->tipoIdentificadores = "byte";
                           holdType = "byte";
                        }else if(roller.nome == "string"){
                           listaScroller->tipoIdentificadores = "string";
                           holdType = "string";
                        }else{
                           erro = 1;
                        }
                     }else{
                        erro = 1;
                     } 
                 
                     if(!erro){
                        //alocar tipos aos identificadores na hash
                        listaIDScroller = listaScroller->listaIdentificadores;
                        while(listaIDScroller != NULL){
                           tabelaHash.setTipo(listaIDScroller->nome, holdType);
                           listaIDScroller = listaIDScroller->next;
                        }
                        pushPop();
                        if(roller.nome == ";"){
                           pushPop();   
                        }else{
                           erro = 1;
                        }
                     }
                  }  
               }
            }else{
               erro = 1;
            }                       
         }                 
      }                        
   }else{
      tempNode = NULL;
   }
   listaScroller = NULL;
   
   return tempNode;
};
   
////////////////////////////////////////////////////////////////////////////////

declaraSubrotinas* sintatico::ASdeclaraSubrotinas(){
                   
   declaraSubrotinas *tempNode;
   declaraProcedimento *procScroller;
   declaraFuncao *funcScroller;
   
   tempNode->declaraProcedimento = procScroller;
   tempNode->declaraFuncao = funcScroller;
   
   nivelLexico++;
   while((roller.nome == "procedure" || roller.nome == "function") && erro == 0){
      
      // Verificação de procedimento
      if(roller.nome == "procedure"){
         pushPop();
         if(roller.tipo == 1){
            pushPop();
            
            // [check] Checar as informações necessárias para preencher a hash
            //de procedimento.
            tabelaHash.setHash(roller.nome, "procedimento");
            tabelaHash.setNivel(roller.nome, nivelLexico);
            procScroller->identificador = roller.nome;
            procScroller->parametrosFormais = ASparametrosFormais();
            if(!erro){
               if(roller.nome == ";"){
                  pushPop();
                  procScroller->bloco = ASbloco();
                  if(!erro){
                     procScroller = procScroller->next;
                  }else{
                     break;
                  }
               }else{
                  erro = 1;
                  break;
               }
            }else{
               break;
            }
         }else{
            erro = 1;
            break;
         }
      
      // Verificação de função
      }else if(roller.nome == "function"){
         pushPop();
         if(roller.tipo == 1){
            pushPop();
            
            // [check] Checar as informações necessárias para preencher a hash
            //de função.
            tabelaHash.setHash(roller.nome, "funcao");
            tabelaHash.setNivel(roller.nome, nivelLexico);
            funcScroller->identificadorFuncao = roller.nome;
            funcScroller->parametrosFormais = ASparametrosFormais();
            if(!erro){
               if(roller.nome == ":"){
                  pushPop();
                  if(roller.tipo == 1){
                     // [check] Checar as informações desse identificador bizarro
                     tabelaHash.setHash(roller.nome, "???");
                     tabelaHash.setNivel(roller.nome, nivelLexico);
                     funcScroller->identificador = roller.nome;
                     funcScroller->bloco = ASbloco();
                     if(!erro){
                        funcScroller = funcScroller->next;
                     }else{
                        break;
                     }                                 
                  }else{
                     erro = 1;
                     break;
                  }
               }else{
                  erro = 1;
                  break;
               }
            }else{
               break;
            }
         }else{
            erro = 1;
            break;
         }
      }      
   }
   nivelLexico--;
   procScroller = NULL;
   funcScroller = NULL;   
   
   return tempNode;
};

////////////////////////////////////////////////////////////////////////////////

parametrosFormais* sintatico::ASparametrosFormais(){
                   
   parametrosFormais *tempNode, *listaScroller;
   listaIdentificadores *listaIDScroller;
   int deslocamentoAux=0;
   string holdTipo;
   
   tempNode = listaScroller;
   if(roller.nome == "("){
      pushPop();
      do{
         if(roller.nome == "var"){
            pushPop();
            listaScroller->listaIdentificadores = ASlistaIdentificadores();
            if(!erro){
                      
               // Inserindo valores de deslocamento nos identificadores coletados 
               //anteriormente.                      
               listaIDScroller = listaScroller->listaIdentificadores;
               deslocamentoAux = (desloca*-1)-3;
               for(; deslocamentoAux <= -3; deslocamentoAux++){
                  tabelaHash.setDeslocamento(listaIDScroller->nome, deslocamentoAux);
                  listaIDScroller = listaIDScroller->next;
               }
               if(roller.nome == ":"){
                  pushPop();
                  
                  // [check] Checar que diabo é esse identificador 
                  //meu palpite na prática: id de variável
                  holdTipo = comparaTipo(roller.nome);
                  if(holdTipo != "erro"){                     
                     /*tabelaHash.setHash(roller.nome, "identificador");
                     tabelaHash.setNivel(roller.nome, nivel); 
                     */
                     
                     listaScroller->identificador12 = roller.nome;
                     pushPop();                
                     listaScroller = listaScroller->next;  
                  }else{
                     erro = 1;
                     break;
                  }               
               }else{
                  erro = 1;
                  break;
               }
            }else{
               break;
            }         
         }else{
            erro = 1;
         }
      }while(roller.nome == ";");
      if(roller.nome == ")"){
         pushPop();      
      }else{
         erro = 1;
      }      
   }else{
      erro = 1;
   }       
   listaScroller = NULL;                
                   
   return tempNode;   
};
   
////////////////////////////////////////////////////////////////////////////////

comandoComposto* sintatico::AScomandoComposto(){
	
	comandoComposto *tempNode;
	comandoComposto *listaScroller;
	comandoComposto *listaScroller2;

	int exec = 0;
	
	if(roller.nome == "begin"){
		pushPop();
		(*tempNode).comando = AScomando();
		//(*tempNode).next == NULL;                      // AQUI,OH!
		listaScroller = tempNode->next;
		if(!erro){
			pushPop();
			//if(roller.nome == ";"){
			while(roller.nome == ";"){
			   pushPop();
			   (*listaScroller).comando = AScomando();
			   if(!erro){
			      //(*listaScroller2).next = NULL;
				  //(*listaScroller).next = listaScroller2;
				  listaScroller = listaScroller->next;
               }else{
			      break;
			   }
			   pushPop();
			   //listaScroller = listaScroller2;
			}
			/*}
			else{
			if(roller.nome == "end"){
			   return tempNode;
			}else{
			   erro = 1;
			}
			}*/
			if(roller.nome != "end"){
               erro = 1;
            }
            listaScroller = NULL;
		}
	}
	else{
	   erro == 1;
	}
}

////////////////////////////////////////////////////////////////////////////////   
   
comando* sintatico::AScomando(){
   comando *tempNode;
   
   tempNode->comandoSemrotulo = AScomandoSemrotulo();
            
   return tempNode;      
};

////////////////////////////////////////////////////////////////////////////////

atribuicao* sintatico::ASatribuicao(){
   
   atribuicao *tempNode;
   string checkCat;
   
   checkCat = tabelaHash.getCategoria(roller.nome);
   if(checkCat == "variavel"){
      tempNode->variavel = ASvariavel();
      if(roller.nome == ":"){
         pushPop();
         if(roller.nome == "="){
            tempNode->expressao = ASexpressao();         
         }else{
            erro = 1;            
         }
      }else{
         erro = 1;
      }
   }
   
   return tempNode;
   
};

////////////////////////////////////////////////////////////////////////////////

variavel* sintatico::ASvariavel(){
   variavel *tempNode;
   string checkCat;
   
   tempNode->listaExpressoes = NULL;
      
   checkCat = tabelaHash.getCategoria(roller.nome);
   if(checkCat == "variavel"){
      tempNode->identificador = roller.nome;
      pushPop();
      
      // [check] Necessária?
      /*
      tempNode->listaExpressoes = new listaExpressoes();
      tempNode->listaExpressoes = ASlistaExpressoes();
      if(erro){
         // [check] Providencias de parada
      }
      
      */
   } 
   
   return tempNode;        
};

////////////////////////////////////////////////////////////////////////////////

listaExpressoes* sintatico::ASlistaExpressoes(){
   listaExpressoes *tempNode, *listaScroller;                 
   
   tempNode->expressao = ASexpressao();
   if(!vazio){      
      listaScroller = tempNode->next;
      pushPop();
      while(roller.nome == ","){
         listaScroller->expressao = ASexpressao();
         if(vazio){
            break;            
         }else{
            pushPop();
         }
         listaScroller = listaScroller->next;
      }
   }
   listaScroller = NULL;
   
   return tempNode;                
}; 
   
////////////////////////////////////////////////////////////////////////////////

expressao* sintatico::ASexpressao(){
   expressao *tempNode;
   
   tempNode->primeiraSimples = ASexpressaoSimples();
   if(!vazio){                                             // Se a primeira expressão tiver erro, o método simplesmente se encerrará                      
      if(comparaRelacao(roller.nome) != "erro"){          // Sair do método sem a segunda parte da expressão é aceitável, por isso não propaga erro
         tempNode->relacao = roller.nome;
         pushPop();
         tempNode->segundaSimples = ASexpressaoSimples();
      }
   }else{
      erro = 1;
   }
   
   return tempNode;
};

////////////////////////////////////////////////////////////////////////////////

expressaoSimples* sintatico::ASexpressaoSimples(){
   expressaoSimples *tempNode, *listaScroller;
   
   tempNode = listaScroller;   
   if(roller.nome == "+" || roller.nome == "-"){
      listaScroller->operador = roller.nome;
      pushPop();
   }else{
      listaScroller->operador = "nulo";
   }   
   listaScroller->termo = AStermo();
   if(!erro){
      listaScroller = listaScroller->next;
      while(roller.nome == "+" || roller.nome == "-" || roller.nome == "or"){
         listaScroller->operador = roller.nome;
         pushPop();
         listaScroller->termo = AStermo();
         if(erro){
            break;
         }else{
            listaScroller = listaScroller->next;
            pushPop();
         }
      }   
   }
   
   return tempNode;
};
   
////////////////////////////////////////////////////////////////////////////////

termo* sintatico::AStermo(){
   termo *tempNode, *listaScroller;          
   
   tempNode = listaScroller;   
   listaScroller->fator = ASfator();
   if(!vazio){
      while(!erro && (roller.nome == "*" || roller.nome == "div" || roller.nome == "and")){
         pushPop();
         listaScroller->conector = roller.nome;
         listaScroller = listaScroller->next;
         listaScroller->fator = ASfator();                     
      }
      listaScroller->next = NULL;      
   }
   
   return tempNode;      
};   

////////////////////////////////////////////////////////////////////////////////

// Fator trabalha de maneira especial com o erro, devido à sua complexidade. Ao invés
//de receber o erro e cair fora, ele o zera e continua testando as outras possibilidades. 
//Isso acontece devido a testes quase ambíguos existentes dentro da estrutura de <fator>.

fator* sintatico::ASfator(){
   fator *tempNode;
   string holdCat;
   
   tempNode->negacao = "nulo";   
   tempNode->numero = "nulo";
   tempNode->abreChave = "nulo";
   tempNode->fechaChave = "nulo";
   
   tempNode->expressao = NULL;
   tempNode->fator = NULL;
   tempNode->variavel = NULL;
   tempNode->chamadaFuncao = NULL;
   
   if(roller.nome == "not"){
      tempNode->fator = new fator();
      
      tempNode->negacao = "not";
      pushPop();
      tempNode->fator = ASfator();
      
   }else if(roller.tipo == 2){                     //CHECK   
      tempNode->numero = roller.nome;
      pushPop();
      
   }else if(roller.nome == "("){                   //CHECK
      tempNode->expressao = new expressao();
                  
      tempNode->abreChave = roller.nome;
      pushPop();
      tempNode->expressao = ASexpressao();
      if(!erro && roller.nome == ")"){
        tempNode->fechaChave = roller.nome;
        pushPop();
      }         
      
   }else{
      holdCat = tabelaHash.getCategoria(roller.nome);
      if(holdCat == "variavel"){
         tempNode->variavel = new variavel();      
         tempNode->variavel = ASvariavel();
      }else if(holdCat == "funcao"){
         tempNode->chamadaFuncao = new chamadaFuncao();      
         tempNode->chamadaFuncao = ASchamadaFuncao();           
      }else{
         erro = 1;
      }
   }   
   return tempNode;    
};

////////////////////////////////////////////////////////////////////////////////

chamadaFuncao* sintatico::ASchamadaFuncao(){
   chamadaFuncao *tempNode;
   string checkCat;
   
   checkCat = tabelaHash.getCategoria(roller.nome);
   if(checkCat == "funcao"){
      tempNode->identificador = roller.nome;
      pushPop();
      if(roller.nome == "("){
         pushPop();
         tempNode->listaExpressoes = ASlistaExpressoes();
      }   
   }else{
      erro = 1;
   }
   
   return tempNode;               
};

////////////////////////////////////////////////////////////////////////////////

comandoRepetitivo* sintatico::AScomandoRepetitivo(){
   comandoRepetitivo *tempNode;
   
   if(roller.nome == "while"){
      pushPop();
      tempNode->expressao = ASexpressao();
      if(!erro && roller.nome == "do"){
         pushPop();
         tempNode->comandoSemrotulo = AScomandoSemrotulo();         
      }
   }else{
      erro = 1;
   }
      
   return tempNode;   
};

////////////////////////////////////////////////////////////////////////////////

comandoCondicional* sintatico::AScomandoCondicional(){
   comandoCondicional *tempNode;
   
   if(roller.nome == "if"){
      pushPop();
      tempNode->expressao = ASexpressao();
      if(!erro && roller.nome == "then"){
         pushPop();
         tempNode->entao = AScomandoSemrotulo();
         if(!erro && roller.nome == "else"){
            pushPop();
            tempNode->senao = AScomandoSemrotulo();
         }            
      }
   }
   
   return tempNode;
};

////////////////////////////////////////////////////////////////////////////////
     
chamadaProcedimento* sintatico::ASchamadaProcedimento(){
   chamadaProcedimento *tempNode;
   string checkCat;
   
   tempNode->identificador = roller.nome;
   pushPop();
   if(roller.nome == "("){
      pushPop();
      tempNode->listaExpressoes = ASlistaExpressoes();
      if (roller.nome != ")"){
         erro = 1;
      }        
   }   
   
   return tempNode;                     
};
                          
////////////////////////////////////////////////////////////////////////////////

comandoSemrotulo* sintatico::AScomandoSemrotulo(){
   comandoSemrotulo *tempNode;
   string checkCat;
   
   tempNode->atribuicao = NULL;
   tempNode->chamadaProcedimento = NULL;
   tempNode->comandoComposto = NULL;
   tempNode->comandoCondicional = NULL;
   tempNode->comandoRepetitivo = NULL;
      
   checkCat = tabelaHash.getCategoria(roller.nome);               
   if(checkCat == "variavel"){
      tempNode->atribuicao = new atribuicao();
      tempNode->atribuicao = ASatribuicao();               
   }else if(checkCat == "procedimento"){
      tempNode->chamadaProcedimento = new chamadaProcedimento;
      tempNode->chamadaProcedimento = ASchamadaProcedimento();         
   }else if(roller.nome == "begin"){
      tempNode->comandoComposto = new comandoComposto();
      tempNode->comandoComposto = AScomandoComposto();         
   }else if(roller.nome == "if"){
      tempNode->comandoCondicional = new comandoCondicional();
      tempNode->comandoCondicional = AScomandoCondicional();         
   }else if(roller.nome == "while"){
      tempNode->comandoRepetitivo = new comandoRepetitivo();      
      tempNode->comandoRepetitivo = AScomandoRepetitivo();      
   }else{
      erro = 1;
   }
                  
   return tempNode;               
};
