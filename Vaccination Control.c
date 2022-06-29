#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

//Criei struct primaria
struct paciente{
	char nome[100];
	char cpf[17];
	char vacina[20];
	int dia, mes, ano;
	int numeroDoLote;
};
//Struct que serve como banco de dados global do algoritmo.
struct paciente banco[99999];
//Limpando buffers do banco.
void limparBufferDoBanco(void){
	int i=0;
	for(i=0;i<99999;i++){
		banco[i].dia = 0;
		banco[i].mes = 0;
		banco[i].ano = 0;
		banco[i].numeroDoLote = 0;
	}
}
//Função pra limpar tela. Obs: clear linux, cls em windows.
void limparTela(void){
	system("cls");
}
//Função limpar buffer
void limparbuffer(void){
	fflush(stdin);
}
//Função limpar buffer em linux. Obs: Se for rodar o codigo em linux, (comentar esse comando __fpurge) que está dentro da função.
void limparbufferlinux(void){
	//__fpurge(stdin);
}

//Menu para controle do algoritmo
int criandoMenu(int x){
	printf("1 - Cadastrar Vacina\n");
	printf("2 - Listar Aplicações\n");
	printf("3 - Consultar por CPF\n");
	printf("4 - Sair\n");
	scanf("%d", &x);
	fflush(stdin);
	return x;
}
//Rotina 1 do menu do algoritmo responsável por realizar os cadastros e alocar todos no vetor de structs global que está servindo como banco. 
struct paciente cadastro(struct paciente x){
	int i;
	char compare[17]="123.123.123-12";
	bool valid = true, valid2 = true, valid3 = true;
	printf("Digite o nome do paciente completo:\n");
  limparbufferlinux();
	gets(x.nome);
	limparbuffer();
	printf("\n");
	printf("Digite seu cpf:\n");
  limparbufferlinux();
	gets(x.cpf);
	limparbuffer();
	printf("\n");
	//Daqui até o final da estrutura de repitição for irei criar varias validações para minimizar riscos de bugs que o algoritmo possa criar em contato com o usuario.
	while(x.cpf[3]!=compare[3] || strlen(x.cpf)>14){
		printf("Escreva o cpf com os pontos corretos, modelo aceito pelo sistema(###.###.###-##)\n");
		printf("Digite seu cpf:\n");
    limparbufferlinux();
		gets(x.cpf);
		limparbuffer();
		limparTela();
	}
	while(x.cpf[7]!=compare[7] || strlen(x.cpf)>14){
		printf("Escreva o cpf com os pontos corretos, modelo aceito pelo sistema(###.###.###-##)\n");
		printf("Digite seu cpf:\n");
    limparbufferlinux();
		gets(x.cpf);
		limparbuffer();
		limparTela();
	}
	while(x.cpf[11]!=compare[11] || strlen(x.cpf)>14){
		printf("Escreva o cpf com os pontos corretos, modelo aceito pelo sistema(###.###.###-##)\n");
		printf("Digite seu cpf:\n");
    limparbufferlinux();
		gets(x.cpf);
		limparbuffer();
		limparTela();
	}
	for(i=0;i<99999;i++){
		if((strlen(x.cpf)>14 || strcmp(banco[i].cpf, x.cpf)==0 || x.cpf[3]!=compare[3]) && valid==true){
			while((strlen(x.cpf)>14 || strcmp(banco[i].cpf, x.cpf)==0 || x.cpf[3]!=compare[3]) && valid==true){
				printf("CPF JÁ CADASTRADO OU ESTÁ NO FORMATO INCORRETO SEM AS PONTUAÇÕES. FORMATO ACEITO PELO SISTEMA(###.###.###-##)\n");
				printf("Digite seu cpf:\n");
        limparbufferlinux();
				gets(x.cpf);
				limparbuffer();
				valid = false;
				limparTela();
			}	
		}else{
			if((strlen(x.cpf)>14 || strcmp(banco[i].cpf, x.cpf)==0 || x.cpf[7]!=compare[7]) && valid2==true){
				while((strlen(x.cpf)>14 || strcmp(banco[i].cpf, x.cpf)==0 || x.cpf[7]!=compare[7]) && valid2==true){
					printf("CPF JÁ CADASTRADO OU ESTÁ NO FORMATO INCORRETO SEM AS PONTUAÇÕES. FORMATO ACEITO PELO SISTEMA(###.###.###-##)\n");
					printf("Digite seu cpf:\n");
          limparbufferlinux();
					gets(x.cpf);
					limparbuffer();
					valid2 = false;
					limparTela();
				}		
			}else{
				if((strlen(x.cpf)>14 || strcmp(banco[i].cpf, x.cpf)==0 || x.cpf[11]!=compare[11]) && valid3==true){
					while((strlen(x.cpf)>14 || strcmp(banco[i].cpf, x.cpf)==0 || x.cpf[11]!=compare[11]) && valid3==true){
						printf("CPF JÁ CADASTRADO OU ESTÁ NO FORMATO INCORRETO SEM AS PONTUAÇÕES. FORMATO ACEITO PELO SISTEMA(###.###.###-##)\n");
						printf("Digite seu cpf:\n");
            limparbufferlinux();
						gets(x.cpf);
						limparbuffer();
						valid3 = false;
						limparTela();
					}
				}
			}
		}
	}
	printf("Digite o nome da Vacina:\n");
  limparbufferlinux();
	scanf("%s", x.vacina);
	limparbuffer();
	printf("\n");
	//Informei ao sistema que queria receber as datas e após receber, já armazenar elas com as barras.
	printf("Digite a data atual(Em formato MM/DD/AAAA):\n");
  limparbufferlinux();
	scanf("%d/%d/%d", &x.dia, &x.mes, &x.ano);
	limparbuffer();
	while(x.mes>12 || x.mes==0 || x.dia>31 || x.dia==0 || x.ano==0){
		printf("Data invalida!!\n");
		printf("Digite a data atual(Em formato DD/MM/AAAA):\n");
    limparbufferlinux();
		scanf("%d/%d/%d", &x.dia, &x.mes, &x.ano);
		limparTela();
	}
	printf("\n");
	printf("Digite o numero do lote:\n");
  limparbufferlinux();
	scanf("%d", &x.numeroDoLote);
	limparbuffer();
	printf("\n");
	limparTela();
  
	return x;
}
//Rotina 2 do menu do algoritmo responsavel por informar todos os cadastro já incluidos no sistema por ordem de cadastro.
void listarAplicacao(void){
	int i=0;
	if(banco[i].numeroDoLote != 0){
		do{
			printf("Código: %d\n", i+1);
			printf("Nome: %s\n", banco[i].nome);
			printf("CPF: %s\n", banco[i].cpf);
			printf("Vacina: %s\n", banco[i].vacina);
			printf("Data de Cadastro: %d/%d/%d\n", banco[i].dia, banco[i].mes, banco[i].ano);
			printf("Numero do Lote: %d\n", banco[i].numeroDoLote);
			printf(" ==================================\n");
			i++;
		}while(strlen(banco[i].nome)!=0 );
  	}else{
    	printf("Ainda não possue aplicações de vacinas cadastradas\n");
		}
	}
//Rotina 3 do menu do algoritmo responsável por fazer uma consulta no banco do código usando o cpf, caso tenha cadastrado o cpf de entrada. Se não tiver, informarei ao usuario.
void consultaCpf(void){
	int i=0;
	char compar[15], compare[17]="123.123.123-12";
	bool valid1 = true, valid2 = true;
	printf("Digite o CPF de busca:\n");
  limparbufferlinux();
	gets(compar);
	limparbuffer();
	//Daqui até o fim da terceira estrutura de repetição while, tentei minimizar possiveis bugs que o algoritmo cometesse.
	while(compar[3]!=compare[3] || strlen(compar)>14){
		printf("Escreva o cpf com os pontos corretos, modelo aceito pelo sistema(###.###.###-##)\n");
		printf("Digite o CPF de busca:\n");
    limparbufferlinux();
		gets(compar);
		limparbuffer();
		limparTela();
	}
	while(compar[7]!=compare[7] || strlen(compar)>14){
		printf("Escreva o cpf com os pontos corretos, modelo aceito pelo sistema(###.###.###-##)\n");
		printf("Digite o CPF de busca:\n");
    limparbufferlinux();
		gets(compar);
		limparbuffer();
		limparTela();
	}
	while(compar[11]!=compare[11] || strlen(compar)>14){
		printf("Escreva o cpf com os pontos corretos, modelo aceito pelo sistema(###.###.###-##)\n");
		printf("Digite o CPF de busca:\n");
    limparbufferlinux();
		gets(compar);
		limparbuffer();
		limparTela();
	}
	//Daqui até o final da função, vou vasculhar o vetor de struct global usado como banco e ver se o cpf de entrada do usuario já foi cadastrado.
	for(i=0;i<99999 && valid1 == true;i++){
		if(strcmp(compar, banco[i].cpf)==0 && valid1 == true){
			printf("+++++++++++++++++++++++++++++\n");
			printf("CPF JÁ CADASTRADO!\n");
			printf("+++++++++++++++++++++++++++++\n");
			printf("Código: %d\n", i);
			printf("Nome: %s\n", banco[i].nome);
			printf("CPF: %s\n", banco[i].cpf);
			printf("Vacina: %s\n", banco[i].vacina);
			printf("Data de Cadastro: %d/%d/%d\n", banco[i].dia, banco[i].mes, banco[i].ano);
			printf("Numero do Lote: %d\n", banco[i].numeroDoLote);
			valid1= false;		
		}
	}
	if(valid1 == true){
		printf("+++++++++++++++++++++++++++++\n");
		printf("CPF NÃO ENCONTRADO!\n");
		printf("+++++++++++++++++++++++++++++\n");
	}
}
void main(){
	setlocale(LC_ALL, "Portuguese");
	struct paciente pacientes;
	int valid=0, i=0;
	bool valid2 = true, valid3 = true;
	limparBufferDoBanco();
  limparTela();
	printf("========================CONTROLE DA VACINAÇÃO========================\n");
	do{
		if(valid2 == false){
			printf("\n");
			printf("\n");
		}
		valid = criandoMenu(valid);
		switch(valid){
			case 1:
				limparTela();
				banco[i] = cadastro(pacientes);
				i++;
			break;
			case 2:
				limparTela();
				listarAplicacao();
			break;
			case 3:
				limparTela();
				consultaCpf();
			break;
			default:
				limparTela();
				printf("Os comandos validos no menu são apenas (1)(2)(3)(4)\n");
				valid3 = false;
    	}
		valid2 = false;
	//Condição criada para que o usuario não digite outras telas sem ser o 1,2,3,4 no menu do algoritmo.
	}while(valid!=4 || valid3 == true);
	if(valid==4){
		limparTela();
		printf("========================SISTEMA ENCERRADO!========================\n");
	}
}
