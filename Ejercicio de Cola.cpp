#include <iostream>
#include <conio.h>

using namespace std;

int Cola[10];
int Fin=0;
int Inicio=0;

void Imprimir()
{
	int i;
	
	if (Fin<10 && Fin>0)
	{
		cout<<"\n";
		for(i=0; i<Fin; i++)
		{
		cout<<"[ "<<Cola[i]<<" ]  ";
		}	
	}
	
	else if (Fin==10)
	{
		cout<<"\nLa pila esta llena\n";
		for(i=0; i<Fin; i++)
		{
		cout<<"[ "<<Cola[i]<<" ]  ";
		}
	}
	
	else if (Fin==0)
	{
		cout<<"\nLa pila esta vacia";
	}
}

void Push()
{
	int X;
	
	if (Fin<10)
	{
		cout<<"\nIngrese un valor: ";
		cin>>X;
		
		Cola[Fin]=X;
		Fin++;
	}
	Imprimir();
}

void Pop()
{
	if(Fin>0)
	{
		Cola[Inicio]=0;
		
		for(int i=0; i<Fin; i++)
		{
			Cola[i]=Cola[i+1];
		}
		
		Fin--;
	}
	Imprimir();

}

void Menu()
{
	int Opc;
	
	do
	{
	cout<<"MENU\n";
	cout<<"1.- Ingresar\n";
	cout<<"2.- Eliminar\n";
	cout<<"3.- Imprimir\n";
	cout<<"0.- Salir\n";
	cout<<"Elija su opcion: ";
	cin>>Opc;
	
	switch(Opc)
	{
		case 1:
			Push();
		break;
		
		case 2:
			Pop();
		break;
		
		case 3:
			Imprimir();
		break;
		
		case 0:
			cout<<"\nPrograma finalizado";
		break;
		
		default:
			cout<<"\nOpcion invalida";
		break;
	}
	getch();
	system("cls");
	}while(Opc!=0);
}

int main()
{
	Menu();
}

