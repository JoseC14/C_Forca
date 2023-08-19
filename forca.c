#include <stdio.h>
#include <string.h>

// JOGO DA FORCA
int main(){
	
	char palavras[255];
	int quebra = 0;
	int opcao;
    int cont;
	int tamanhoPalavraEscolhida;
	int chances = 5;
	char palavraEscolhida[255];
	char palavrasUsuarios[255];
	char letrasUsuarios[26];
	int indice;
	FILE *arquivo;
	char letra;
	
	printf("******************\n");
	printf("* JOGO DA FORCA  *\n");
	printf("******************\n");
	while(1){
		
		printf("\nDigite um tipo de palavras.\n 1 - Jogos\n 2 - Filmes\n 3 - Famosos\n 4 - Comidas\n 5 - Animais \n Escolha: ");
        scanf("%d", &opcao);  
		
		printf("Digite um indice da lista: ");
		scanf("%d",&indice);
        
		getchar();
		if(opcao == 1){
		   arquivo  = fopen("jogos.txt","r");
		   
		}else if(opcao == 2){
		   arquivo  = fopen("filmes.txt","r");
		}else if(opcao == 3){
		   arquivo  = fopen("famosos.txt","r");
		}else if(opcao == 4){
		   arquivo  = fopen("comidas.txt","r");
		}else if(opcao == 5){
		   arquivo  = fopen("animais.txt","r");
		}
		
		while (fgets(palavras, 255, arquivo) != NULL) {
			quebra +=1;
			if(quebra==indice){
				strcpy(palavraEscolhida,palavras);
				fseek(arquivo, 0, SEEK_SET);
				fclose(arquivo);
				//printf("%i",*arquivo);
			}
		}

		while(1){
		
			cont = 0;
			printf("%s\n",palavraEscolhida);
			for(int i = 0; i < strlen(palavraEscolhida); i++){
				for(int j = 0; j<strlen(letrasUsuarios);j++){
					if(palavraEscolhida[i] == letrasUsuarios[j]){
						printf("%c ",letrasUsuarios[i]);
					}else{
						printf("%s","_ ");
					}
				}
				
				
			}
			printf("Chances restantes %d\n", chances);
			printf("%s","Digite uma letra: ");
			if(scanf("%c",&letra)!=1){
				printf("%s","Erro ao ler letra");
				return 0;
			};
			getchar();
			for(int i = 0; i < strlen(palavraEscolhida); i++){
				if(palavraEscolhida[i]==letra){
					printf("%s","ACERTOU!\n");
					getchar();
				}else{
					cont +=1;
				}
				
			}
			if(cont == strlen(palavraEscolhida)){
				chances -= 1;
			}
			
			strncat(letrasUsuarios,&letra,1);
		}
		
	}
	
	return 0;
	
	
}