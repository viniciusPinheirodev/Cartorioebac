//o cliente deseja 3 telas;
//uma com a inclusao(adicao de novos alunos), outra com a consulta(ver quem sao os alunos adicionados), e outra que delete(remover os alunos);

//incrementos: fazer um looping para se quiser fazer ações repetidas, não tenha que voltar ao menu e abrir a função novamente;

//*Problemas: cpfs iguais se sobrepõe, se no menu voce por uma letra o progama trava tendo que fechar e reabri-lo, tem como colocar letra no cpf, numero no nome, nao tem como repetir a funcao sem ter que voltar ao menu...

#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string


int registro(){//funcao que registra os usuarios
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digita o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	//%s salva dentro de uma string
	
	strcpy(arquivo, cpf); //funcao que copia os valores das strings
	
	FILE *file; //funcao (FILE) que cria um arquivo
	file = fopen(arquivo, "w"); //funcao (fopen) que abre um arquivo; "w" para escrever um arquivo
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //"a" para atualizar um arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"),
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");//perguntar se quer voltar ao menu ou encerrar o programa depois...
	system("cls");
	
}

int consulta(){//funcao que consulta os usuarios
	
	setlocale(LC_ALL, "Portuguese");

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r e para ler um arquivo
	
	if(file == NULL){
		
		printf("Nao foi possivel abrir o arquivo, nao localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		
		printf("\nEssas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	fclose(file);
	system("pause");
	system("cls");
}

int deletar(){//funcao que deleta os usuarios

	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose;
	
	if(file == NULL){
		
		printf("O usuario nao se encontra no sistema!\n\n");
		system("pause");
		file = 0;
		
	}
	system("cls");
}


int main(){
	
	int opcao=0;//definindo as vars
	int laco=1;
	
	char senhaDigitada[10] = "a";
	int comparacao;
	
	printf("--- Cartorio da EBAC ---\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s", senhaDigitada);
	
	comparacao = strcmp(senhaDigitada, "admin");//funcao para comparar strings
	
	if(comparacao == 0){//comparacao tem que ser igual (por isso == a 0) para liberar o resto do codigo
		
		//se for true o codigo segue
		system("cls");
		
		for(laco=1;laco=1;){
	
			int resposta = 0;
		
			setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
			printf("--- Cartorio da EBAC ---\n\n");//inicio do menu
			printf("Escolha a opcao desejada no menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opcao: ");//fim do menu
	
			scanf("%d", &opcao);	//%d armazena uma var de tipo inteiro; & referencia a var

			system("cls");//cls comando para limpar o cmd
		
			switch(opcao){//inicio da selecao
				
				case 1:
				printf("deseja continuar? 1 para sim 2 para nao\nResposta: ");//sistema para confirmar continuidade
				scanf("%d", &resposta);
				
				if(resposta == 1){
				
					system("cls");
					registro();
					break;
				
				}
				else{
				
					system("cls");
					break;
				}
			
				case 2:
				printf("deseja continuar? 1 para sim 2 para nao\nResposta: ");
				scanf("%d", &resposta);
			
				if(resposta == 1){
				
					system("cls");
					consulta();
					break;
				
				}
				else{
					
					system("cls");
					break;
				}
			
				case 3:
				printf("deseja continuar? 1 para sim 2 para nao\nResposta: ");
				scanf("%d", &resposta);
			
				if(resposta == 1){
				
					system("cls");
					deletar();
					break;
				
				}
				else{
					
					system("cls");
					break;
				}
					
				case 4:
				printf("Obrigado por utilizar o sistema\n\n");
				return 0;
				break;
						
				default:
				printf("Escolha uma opcao valida!\n\n");
				system("pause");
				break;
				
			}
		}
	}//fim da selecao
		
		else//se for false aparece isso e o progama encerra
			system("cls");
			printf("senha incorreta");
	
}
