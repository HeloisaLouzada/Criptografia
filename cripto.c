#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define MAX 100

//FUNÇÕES
void codificar (char *stringMen){
    int i, tamanhoMen = strlen(stringMen);
    
	for(i=0; i < tamanhoMen; i++){     
        if (stringMen[i] == 'o'){
            stringMen[i] = '0';
        } else if(stringMen[i] == '0'){
            stringMen[i] = 'o';
        }
            
        if(stringMen[i] == 'a'){
            stringMen[i] = '@';
        } else if(stringMen[i] == '@'){
            stringMen[i] = 'a';
        }      
    }   
}

void separar(char *stringMen, char *stringI, char *stringAUX){
	int i, i_aux = 0, i_imp = 0, tamanhoMen = strlen(stringMen); 
	
	for(i=0; i<= tamanhoMen; i++){       
		if(i%2 == 0){
			stringAUX[i_aux] = stringMen[i];
			i_aux++;
				 			
		} else{
			stringI[i_imp] = stringMen[i];
			i_imp++;
		 } 
	}
	stringI[i_imp] = '\0';
	stringAUX[i_aux] = '\0';
}

void inverter (char *stringP, char *stringAUX){
	int i_par, i_aux = strlen(stringAUX), tamanhoAUX = strlen(stringAUX); 
    /*Foi necessário utilizar 2 variáveis com o mesmo valor inicial para evitar "worms", pois uma é referente ao índice dos elementos do vetor auxiliar, 
	sendo assim será modificada, e a outra referente ao tamanho desse mesmo vetor que delimita o "for", ou seja, não pode ter alteração*/

	for(i_par=0; i_par < tamanhoAUX; i_par++){
		   	i_aux--;   //começa no índice 2, por isso "--" para diminuir 1 no tamanho da string auxiliar
			stringP[i_par] = stringAUX[i_aux];				
		}
	stringP[i_par] = '\0'; 	
}

void intercalar (char *stringMen, char *stringImp, char *stringP){
    int i, i_par = 0, i_imp = 0, tamanhoMen = strlen(stringMen);
     
    for(i=1; i < tamanhoMen; i++){
        if (i%2 == 0){
            stringMen[i] = stringP[i_par];
            i_par++;
            
        }else{
			stringMen[i] = stringImp[i_imp];
            i_imp++;
		}	
	}	
	printf("%s\n\n", stringMen); 	
}

void criptografar(char *stringMen, char *stringImp, char *stringPar, char *stringAUX){
	codificar(stringMen);
    separar(stringMen, stringImp, stringAUX);
    inverter(stringPar,stringAUX);
	intercalar(stringMen, stringImp, stringPar);
}

void descriptografar(char *stringMen, char *stringImp, char *stringPar, char *stringAUX){
	char i;
	
	printf("Deseja descriptografar? S/N:");
	scanf(" %c",&i);
		
	//validação	
	while((toupper(i)!='S') && (toupper(i)!='N')){ 
	      printf("Resposta inválida. Digite novamente:");
	      scanf(" %c",&i);
	      
	}
		
	if(toupper(i) == 'S'){
		printf("Mensagem descriptografada:");
		criptografar(stringMen, stringImp, stringPar, stringAUX);
	}	
}


//FUNÇÃO PRINCIPAL
int main(){
	SetConsoleOutputCP(65001);
    char mensagem[MAX], stringMenAuxiliar[MAX], stringMenPar[MAX], stringMenImpar[MAX];
    
    printf("Digite sua mensagem:");
    fgets(mensagem,MAX,stdin);
    mensagem[(strlen(mensagem)-1)] = '\0'; //retirar o "enter"
	
	printf("Mensagem criptografada:");
	criptografar(mensagem, stringMenImpar, stringMenPar, stringMenAuxiliar);
	
	descriptografar(mensagem, stringMenImpar, stringMenPar, stringMenAuxiliar);    
   
	return 0;
  }