#include <stdio.h>
#include <iostream>
#include<string.h>
#include <conio.h>
#include<dos.h>
#include <stdlib.h>
using namespace std;
float sal = 8000, sq, dep, lmt = 10.000;
char senha[16], login[10];
void cad_acesso()
{
	char cs[16], clogin[10];
	do
	{
		system("cls");
		cout << "Digite seu login: ";
		gets(login);
		cout << "\nConfirme seu login: ";
		gets(clogin);
	}
	while(strcmp(login, clogin) != 0);
	do
	{
		system("cls");
		cout << "Digite sua senha (8 caracteres ou mais): ";
		gets(senha);
	}
	while(strlen(senha) < 8);
	cout << "\nConfirme sua senha: ";
	gets(cs);
	while(strcmp(senha, cs) != 0)
	{
		do
		{
			system("cls");
			cout << "Digite sua senha (8 caracteres ou mais): ";
			gets(senha);
		}
		while(strlen(senha) < 8);
		cout << "\nConfirme sua senha: ";
		gets(cs);
	}

}
int acesso()
{
	int x = 1;
	char vs[16], vlogin[10];
	if(strlen(senha) < 8)
		x = 4;
	for(; x <= 3; x++)
	{
		system("cls");
		cout << "\t***** Validaçao de usuario *****";
		cout << "\nDigite seu login: ";
		gets(vlogin);
		cout << "\nDigite sua senha: ";
		gets(vs);
		if(strcmp(vs, senha) == 0 & strcmp(vlogin, login) == 0)
		{
			break;
		}
		else
			cout << "\nSenha ou Usuario invalido";
	}

}
void saldo()
{
	system("cls");
	cout << "Seu saldo atual e: " << "R$" << sal;
	cout << "\nSeu limite e : " << "R$" << lmt;
	cout << "\nDisponivel para movimentaçao: " << "R$" << sal + lmt;


}
void saque()
{

	system("cls");
	cout << "Quanto quer sacar: ";
	cin >> sq;
	if(sq > sal + lmt)
	{
		cout << "\nSaldo Indisponível";
	}
	else
	{
		sal -= sq;
		saldo();
	}


}
void deposito()
{
	system("cls");
	cout << "Quanto quer depositar: ";
	cin >> dep;
	sal+=dep;
	saldo();
	
}
int main()
{
	int op;
	char r[3], rc[3], resp[3];
	system("cls");
	cout << "E seu primeiro acesso?";
	gets(rc);
	strupr(rc);
	if (strcmp(rc, "SIM") == 0)
		cad_acesso();
	if(acesso() <= 3);
	{

		do
		{
			system("cls");
			cout << "\t######## Menu Inicial ########\n\n";
			cout << " 1 - Saldo \n 2 - Saque \n 3 - Deposito\n\n";
			cout << " O que deseja fazer? -> ";
			cin >> op;
			switch(op)
			{
			case 1:
				saldo();
				break;
			case 2:
				saque();
				break;
			case 3:
				deposito();
				break;
			default:
				cout << "\nOpção Inválida !!!";
			}
			cout << "\nDeseja Realizar nova ação? ";
			cin >> resp;
			strupr(resp);
		}
		while(strcmp(r, "SIM") == 0);
	}

}
