#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
	int acertos = 0;
	FILE *arquivo;
	char letra;
	int espacosbrancos = 0;
	printf("******************\n");
	printf("* JOGO DA FORCA  *\n");
	printf("******************\n");
	gamestart:
	while(1){
		
		printf("\nDigite um tipo de palavras.\n 1 - Jogos\n 2 - Filmes\n 3 - Famosos\n 4 - Comidas\n 5 - Animais \n Escolha: ");
        scanf("%d", &opcao);  
		
		chooseword:
		printf("Digite um número de 1 a 100");
		scanf("%d",&indice);

		if (indice < 1 || indice>100) {
			printf("Número invalido! escolha um numero de 1 a 100");
			goto chooseword;
		}

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
			}
		}
		
		for(int i = 0; i<strlen(palavraEscolhida);i++){
			palavraEscolhida[i] = toupper(palavraEscolhida[i]);
		}

		while(1){
			cont = 0;
			acertos = 0;
			espacosbrancos = 0;
			for (int i = 0; i < strlen(palavraEscolhida); i++) {
					int encontrado   = 0; 
					int espacobranco = 0;
                if(palavraEscolhida[i] == ' ' || palavraEscolhida[i]=='\n'){
					espacobranco    = 1;
					espacosbrancos +=1;
				}
				for (int j = 0; j < strlen(letrasUsuarios); j++) {
					if (palavraEscolhida[i] == letrasUsuarios[j]) {
					    
						encontrado = 1;
						break; 
					}
				}
       
				if (encontrado) {
					printf("%c ", palavraEscolhida[i]);
					acertos+=1;
				}else if(espacobranco){
					printf(" ");
				} else {
					printf("_ ");
				}
			}
			
			printf("\nEspacos em branco %d",espacosbrancos);
			printf("\nAcertos: %d",acertos);
			if(acertos == strlen(palavraEscolhida)-espacosbrancos){
				gamewin:
				printf("Parabéns! Você ganhou. Deseja jogar novamente?\n 1 - Sim\n 2 - Nao\n");
				scanf("%d",&opcao);                
				if(opcao == 1){
					goto gamestart;
				}else if(opcao == 2){
					printf("***************");
					printf("* FIM DE JOGO *");
					printf("***************");
					chances           = 5;
					letrasUsuarios[0] = '\0';
					return 0;
				}else{
					goto gamewin;
				}
			}
				printf("\n%d",strlen(letrasUsuarios));
				printf("\nPalavras ja digitadas: %s", letrasUsuarios);
				printf("\nChances restantes: %d\n", chances);
				chooseletter:
				printf("%s","Digite uma letra: ");
				if(scanf("%c",&letra)!=1){
					printf("%s","Erro ao ler letra");
					return 0;
				}else{
					if(letrasUsuarios[0] != '\0'){
						for(int i = 0; i<strlen(letrasUsuarios);i++){
							if(letra == letrasUsuarios[i]){
								printf("\nLetra ja escolhida! Escolha outra\n");
								goto chooseletter;
							}
					}
				}
				}
				for(int i = 0; i < strlen(palavraEscolhida); i++){
					if(palavraEscolhida[i]==letra){
						printf("%s","ACERTOU!\n");
					}else{
						cont +=1;
					}
					
				}
				if(cont == strlen(palavraEscolhida)){
					chances -= 1;
				}
				
				strncat(letrasUsuarios,&letra,1);
				
				if(chances == 0){
					printf("QUE PENA! VOCE PERDEU!");
					printf("Deseja tentar novamente?\n 1 - Sim\n 2 - Nao\n");
					scanf("%d",&opcao);
					gameover:
					if(opcao == 1){
						chances = 5;
						letrasUsuarios[0] = '\0';
						goto gamestart;
					}else if(opcao == 2){
						printf("***************");
						printf("* FIM DE JOGO *");
						printf("***************");
						return 0;
					}else{
						printf("Opção Inválida!");
						goto gameover;
					}
				}	
			}	
		
		}
	return 0;
}
