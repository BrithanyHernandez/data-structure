#include <iostream>
#include <conio.h>

using namespace std;

int Pila[10];
int Tope=0;

void Imprimir(){
	int i;
	
	if (Tope<10 && Tope>0) {
		cout<<"\n";
		
		for(i=Tope; i>0; i--){
		cout<<"[ "<<Pila[i]<<" ]\n";
		}	
	}
	
	else if (Tope==10){
		cout<<"\nLa pila esta llena\n";
		for(i=Tope; i>0; i--){
		cout<<"[ "<<Pila[i]<<" ]\n";
		}
	}
	
	else if (Tope==0){
		cout<<"\nLa pila esta vacia";
	}
}

void Push(){
	int X;
	
	if (Tope<10){
		cout<<"\nIngrese un valor: ";
		cin>>X;
		
		Tope++;
		Pila[Tope]=X;
	}
	Imprimir();
}

void Pop()
{
	if(Tope>0){
		Tope--;
	}
	Imprimir();
}

void Menu(){
	int Opc;
	
	do{
	cout<<"MENU\n";
	cout<<"1.- Ingresar\n";
	cout<<"2.- Eliminar\n";
	cout<<"3.- Imprimir\n";
	cout<<"Elija su opcion: ";
	cin>>Opc;
	
	switch(Opc){
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

int main(){
	Menu();
}
