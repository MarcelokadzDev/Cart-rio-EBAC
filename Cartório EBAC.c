#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // bliblioteca responsável por cuidar das string´s

int registro() // Função responsavel pelo cadrastro de usuários no sistema
{
	//Inicio da criação de variáveis/strings
	char arquivo[50]; //quantidade maxima de arquivos que irar ler 
	char cpf[50]; //quantidade maxima de numeros para o cpf
	char nome[50]; //quantidade maxima de letras para o nome
	char sobrenome[50]; //quantidade maxima de letras para o sobrenome
	char cargo[50]; //quantidade maxima de letras para o cargo
	//o numero que esta dentro dos[] é o maximo que sera lido/escrevido
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado:"); //escreve o que queremos
	scanf("%s", cpf); //%s Refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string´s
	
	FILE *file; // Criar o arquivo
	file = fopen(arquivo, "w"); //Criar o arquivo e o "W" significa escrever
	fprintf(file,cpf); // Salvo o valor da varíavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); //Criar o arquivo
	fprintf(file, ","); //Criar o arquivo
	fclose(file); //fechar o arquivo
	
	printf("Digite o nome a ser cadastrado:"); //escreve o que queremos 
	scanf("%s",nome); //%s Refere-se a strings
	
	file = fopen(arquivo, "a"); //Criar o arquivo
	fprintf(file,nome);//Criar o arquivo
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //Criar o arquivo
	fprintf(file, ","); //Criar o arquivo
	fclose(file); //fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:"); //escreve o que queremos 
	scanf("%s" ,sobrenome);  //%s Refere-se a strings
	
	file = fopen(arquivo, "a"); //Criar o arquivo
	fprintf(file,sobrenome); //Criar o arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //Criar o arquivo
	fprintf(file, ","); //Criar o arquivo
	fclose(file); //fechar arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //escreve o que queremos
	scanf("%s" ,cargo); //%s Refere-se a strings
	
	file = fopen(arquivo, "a"); //Criar o arquivo
	fprintf(file,cargo); //Criar o arquivo
	fclose(file); //fechar arquivo
	
	system("pause"); //Usado para pausar a tela e deixar o usuário ler 
	
	//o "a" é o arquivo que sera aberto
	
	
}

int consulta() //usado para consultar
{
	setlocale(LC_ALL, "Portuguese"); // Definição de linguagem 
	
    char cpf[50]; //quantidade maxima de numeros para o cpf
    char conteudo[200]; //quantidade maxima de letras para o conteudo apresentado
    
    printf("Digite o CPF a ser consultado: "); //escreve o que queremos 
    scanf("%s",cpf); //%s Refere-se a strings
    
    FILE *file; //arquivo
    file = fopen(cpf,"r"); //vai abrir o arquivo escolhido e ler
    //o "r" significa ler
    if(file == NULL) //se não encotrar nada ira mostrar a msg que a gente quiser
    //if significa SE
    
{
	printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //escreve o que queremos
	
		
}
    while(fgets(conteudo, 200, file) != NULL) //quantidade de vezes que o contetudo sera rodado
    {
    	printf("\nEssas são as informações do usuário:  "); //escreve o que queremos
    	printf("%s", conteudo); //%s Refere-se a strings
    	printf("\n\n"); // pula linha
	}
		
	system("pause"); //Usado para pausar a tela e deixar o usuário ler 
	
	fclose(file); //fechar arquivo


}

int deletar()
{
	char cpf[50]; //quantidade maxima de numeros para o cpf
	
	printf("Digite o CPF do usuário a ser deletado(apenas números):");
	scanf("%s",cpf); //%s Refere-se a strings
	
	
	FILE *file; //arquivo
	file = fopen(cpf, "r"); //abre o arquivo e lê
	
	if (file == NULL) //arquivo nulo 
	{
		fclose(file);
		printf("Usuário não encontrado no sistema!. \n"); // escreve o que queremos
		system("pause"); //Usado para pausar a tela e deixar o usuário ler 
	}
	
	else if (file != NULL)
	{
		fclose(file); //fecha o arquivo
		printf("Usuário deletado com sucesso!\n"); // escreve o que queremos 
		system("pause"); //Usado para pausar a tela e deixar o usuário ler 
		remove (cpf); //removera o que pedimos
	}
	
	
	
}

int main() //menu
{
	int opcao=0; //Definição de varíaveis 
	int x=1; //Laço/Agrupar
	
	for(x=1;x=1;) //determina quantas vezes ira rodar o programa 
	{
		
		system("cls"); //responsavel por limpar a tela 
	
	 setlocale(LC_ALL, "Portuguese"); //Definição de Linguagem 
	
	printf("### Cartório 2° Ofício EBAC ###\n\n"); //Inicio do menu
	printf("Dentre as opções no menu, escolha a desejada:\n\n");
	printf("\t1 - Registrar nomes de usuário  \n");
	printf("\t2 - Consultar nomes de usuário \n");
	printf("\t3 - Deletar nomes de usuário \n"); 
	printf("Opção:"); //Fim do menu
	
	scanf("%d",&opcao); //Armazenamento de escolhas do usuário!
	
	system("cls"); //responsavel por limpar a tela 
		
	
	switch(opcao) //Inicio de seleção para o menu 
	{
		case 1:
		registro(); //Chamada de função
		break; //interromper repetição
		
		case 2: 
		consulta(); //Consulta de função
		break; //interromper repetição
		
		case 3:
		deletar(); // Delatar consulta
		break; //interromper repetição
		
		default: //algo invalado/sem nome
		printf("Essa opção não está disponível!\n"); //escreve o que queremos 
		system("pause"); //Usado para pausar a tela e deixar o usuário ler 
		break;	
		//fim da seleção	
	}
	
	
}
}
