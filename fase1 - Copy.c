#include <stdio.h>
#include "meio.h"
#include "clientes.h"
#include "gestor.h"



//Menu de opções
int menu()
{
	int op;
	printf("M E N U\n");
	printf("1 Inserir Meio\n");
	printf("2 Listar Meios\n");
	printf("3 Remover Meio\n");
	printf("4 Guardar Meios\n");
	printf("5 Ler Meios\n");
	printf("6 Inserir Cliente\n");
	printf("7 Guardar Cliente\n");
	printf("8 Listar Cliente\n");
	printf("9 Remover Cliente\n");
	printf("10 Ler Cliente\n");
	printf("11 Inserir Gestor\n");
	printf("12 Guardar Gestor\n");
	printf("13 Listar Gestor\n");
	printf("14 Remover Gestor\n");
	printf("15 Ler Gestor\n");
	printf("0 Sair\n");
	printf("Opcao:\n");
	scanf("%d", &op);
	return(op);
}


//Seleção de opções, entrada de dados
int main()
{
	Meio* meios = NULL;
	Clientes* clientes = NULL;
	Gestores* gestores = NULL;
	int op, cod, nif;
	float bat, aut, sal, alu;
	char tipo[50];
	char nom[50];
	char mor[50];
	meios = lerMeios();
	clientes = lerClientes();
	gestores = lerGestores();
	do
	{
		op = menu();
		switch (op)
		{
		case 1: printf("Codigo?\n");
			scanf("%d", &cod);
			printf("Tipo?\n");
			scanf("%s", tipo);
			printf("Nivel da bateria?\n");
			scanf("%f", &bat);
			printf("Autonomia?\n");
			scanf("%f", &aut);
			printf("Aluguer?\n");
			scanf("%f", &alu);
			meios = inserirMeio(meios, cod, tipo, bat, aut, alu);
			break;
		case 2: listarMeios(&meios); break;
		case 3: printf("Codigo do meio de mobilidade a remover?\n");
			scanf("%d", &cod);
			meios = removerMeio(meios, cod);
			break;
		case 4: guardarMeios(meios); break;
		case 5: meios = lerMeios(); break;
		case 6:printf("Codigo?\n");
			scanf("%d", &cod);
			printf("Morada?\n");
			scanf("%s", mor);
			printf("Nome?\n");
			scanf("%s", nom);
			printf("Saldo?\n");
			scanf("%f", &sal);
			printf("Nif?\n");
			scanf("%d", &nif);
			clientes = inserirClientes(clientes, cod, nif, nom, mor, sal);
			break;
		case 7: guardarClientes(clientes); break;
		case 8: listarClientes(&clientes); break;
		case 9: printf("Codigo do cliente a remover?\n");
			scanf("%d", &cod);
			clientes = removerClientes(clientes, cod);
			break;
		case 10: clientes = lerClientes(); break;
		case 11: printf("Codigo?\n");
			scanf("%d", &cod);
			printf("Nome?\n");
			scanf("%s", nom);
			gestores = inserirGestores(gestores, cod, nom);
			break;
		case 12: guardarGestores(gestores); break;
		case 13: listarGestores(&gestores); break;
		case 14: printf("Codigo do Gestor a remover?\n");
			scanf("%d", &cod);
			gestores = removerGestores(gestores, cod);
			break;
		case 15: gestores = lerGestores(); break;

		}
	} while (op != 0);


	return(0);
}