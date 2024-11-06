#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // bliblioteca respons�vel por cuidar das string�s

int registro() // Fun��o responsavel pelo cadrastro de usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/strings
	char arquivo[50]; //quantidade maxima de arquivos que irar ler 
	char cpf[50]; //quantidade maxima de numeros para o cpf
	char nome[50]; //quantidade maxima de letras para o nome
	char sobrenome[50]; //quantidade maxima de letras para o sobrenome
	char cargo[50]; //quantidade maxima de letras para o cargo
	//o numero que esta dentro dos[] � o maximo que sera lido/escrevido
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado:"); //escreve o que queremos
	scanf("%s", cpf); //%s Refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string�s
	
	FILE *file; // Criar o arquivo
	file = fopen(arquivo, "w"); //Criar o arquivo e o "W" significa escrever
	fprintf(file,cpf); // Salvo o valor da var�avel
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
	
	system("pause"); //Usado para pausar a tela e deixar o usu�rio ler 
	
	//o "a" � o arquivo que sera aberto
	
	
}

int consulta() //usado para consultar
{
	setlocale(LC_ALL, "Portuguese"); // Defini��o de linguagem 
	
    char cpf[50]; //quantidade maxima de numeros para o cpf
    char conteudo[200]; //quantidade maxima de letras para o conteudo apresentado
    
    printf("Digite o CPF a ser consultado: "); //escreve o que queremos 
    scanf("%s",cpf); //%s Refere-se a strings
    
    FILE *file; //arquivo
    file = fopen(cpf,"r"); //vai abrir o arquivo escolhido e ler
    //o "r" significa ler
    if(file == NULL) //se n�o encotrar nada ira mostrar a msg que a gente quiser
    //if significa SE
    
{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //escreve o que queremos
	
		
}
    while(fgets(conteudo, 200, file) != NULL) //quantidade de vezes que o contetudo sera rodado
    {
    	printf("\nEssas s�o as informa��es do usu�rio:  "); //escreve o que queremos
    	printf("%s", conteudo); //%s Refere-se a strings
    	printf("\n\n"); // pula linha
	}
		
	system("pause"); //Usado para pausar a tela e deixar o usu�rio ler 
	
	fclose(file); //fechar arquivo


}

int deletar()
{
	char cpf[50]; //quantidade maxima de numeros para o cpf
	
	printf("Digite o CPF do usu�rio a ser deletado(apenas n�meros):");
	scanf("%s",cpf); //%s Refere-se a strings
	
	
	FILE *file; //arquivo
	file = fopen(cpf, "r"); //abre o arquivo e l�
	
	if (file == NULL) //arquivo nulo 
	{
		fclose(file);
		printf("Usu�rio n�o encontrado no sistema!. \n"); // escreve o que queremos
		system("pause"); //Usado para pausar a tela e deixar o usu�rio ler 
	}
	
	else if (file != NULL)
	{
		fclose(file); //fecha o arquivo
		printf("Usu�rio deletado com sucesso!\n"); // escreve o que queremos 
		system("pause"); //Usado para pausar a tela e deixar o usu�rio ler 
		remove (cpf); //removera o que pedimos
	}
	
	
	
}

int main() //menu
{
	int opcao=0; //Defini��o de var�aveis 
	int x=1; //La�o/Agrupar
	
	for(x=1;x=1;) //determina quantas vezes ira rodar o programa 
	{
		
		system("cls"); //responsavel por limpar a tela 
	
	 setlocale(LC_ALL, "Portuguese"); //Defini��o de Linguagem 
	
	printf("### Cart�rio 2� Of�cio EBAC ###\n\n"); //Inicio do menu
	printf("Dentre as op��es no menu, escolha a desejada:\n\n");
	printf("\t1 - Registrar nomes de usu�rio  \n");
	printf("\t2 - Consultar nomes de usu�rio \n");
	printf("\t3 - Deletar nomes de usu�rio \n"); 
	printf("Op��o:"); //Fim do menu
	
	scanf("%d",&opcao); //Armazenamento de escolhas do usu�rio!
	
	system("cls"); //responsavel por limpar a tela 
		
	
	switch(opcao) //Inicio de sele��o para o menu 
	{
		case 1:
		registro(); //Chamada de fun��o
		break; //interromper repeti��o
		
		case 2: 
		consulta(); //Consulta de fun��o
		break; //interromper repeti��o
		
		case 3:
		deletar(); // Delatar consulta
		break; //interromper repeti��o
		
		default: //algo invalado/sem nome
		printf("Essa op��o n�o est� dispon�vel!\n"); //escreve o que queremos 
		system("pause"); //Usado para pausar a tela e deixar o usu�rio ler 
		break;	
		//fim da sele��o	
	}
	
	
}
}
