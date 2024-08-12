#include <iostream>
#include <time.h>
#include <stdlib.h> 

using namespace std; 

void Imprimir(int [], int);
int IniManual(int [], int);
int IniAleatorio(int [], int );
void IniConN(int [], int , int);
void IniDe1aN(int [], int);
int Sumatoria (int [], int);
int ValorMaximo(int [], int);
int ValorMinimo(int [], int);
float Promedio (int [], int);
void MayoresPromedio (int [], int);
int Buscar(int [], int, int);
void BuscarYModificar(int [], int , int);
int InsertarPosCero(int [], int);
int InsertarBloqueI(int [], int, int);
int InsertarBloqueF(int [], int, int);
int InsertarBloqueM(int [], int, int, int);
void EliminarValorI(int [], int);
void EliminarValorF(int [], int);
void MetodoBurbuja(int [], int);
void SeleccionDirecta(int [], int);
void InsercionDirecta(int [], int);
void InsercionBinaria(int [], int);
void Shakersort (int [], int);
void AnosBisiestos(int [], int);

int main()
{
int Arreglo [20]={0}, Opc, N=0, S, Valor ,Cant, B, C, Up=-1;
do
{
cout<<"\t OPERADORES CON ARREGLOS \n";
cout<<"0.- Imprimir\n";
cout<<"1.- Inicializacion manual\n";
cout<<"2.- Inicializacion aleatoria\n";
cout<<"3.- Inicializacion con N\n";
cout<<"4.- Inicializacion de 1 a N\n";
cout<<"5.- Sumatoria\n";
cout<<"6.- Valor maximo\n";
cout<<"7.- Valor minimo\n";
cout<<"8.- Promedio\n";
cout<<"9.- Mayores al promedio\n";
cout<<"10.- Busqueda\n";
cout<<"11.- Busqueda y Modificacion\n";
cout<<"12.- Insertar en Posicion 0\n";
cout<<"13.- Insertar un Bloque al inicio\n";
cout<<"14.- Insertar un Bloque al final\n";
cout<<"15.- Insertar un Bloque de 3 entre 2 vectores\n";
cout<<"16.- Eliminar el valor inicial\n";
cout<<"17.- Eliminar el valor final\n\n";
cout<<"METODOS\n";
cout<<"18.- Metodo Burbuja\n";
cout<<"19.- Metodo Seleccion Directa\n";
cout<<"20.- Metodo Insercion Binaria\n";
cout<<"21.- Metodo Insercion Directa\n";
cout<<"22.- Shakersort\n";
cout<<"99.- Salir\n";
cout<<"Selecciona la opcion: ";
cin>>Opc;
cout<<"\n"; 

switch (Opc)
{
case 0:
Imprimir(Arreglo,N);
break; 

case 1:
cout<<"Cuantos datos quieres ingresar: "; cin>>N;
IniManual(Arreglo,N);
Imprimir(Arreglo,N);
break; 

case 2:
cout<<"Cuantos datos quieres ingresar: "; cin>>N;
IniAleatorio(Arreglo,N);
Imprimir(Arreglo,N);
break; 

case 3:
cout<<"Cuantos datos quieres ingresar: "; cin>>N;
cout<<"Ingresa el valor: "; cin>>Valor;
IniConN(Arreglo,N,Valor);
Imprimir(Arreglo,N);
break; 

case 4:
cout<<"Cuantos datos quieres inicializar: "; cin>>N;
IniDe1aN(Arreglo,N);
Imprimir(Arreglo,N);
break; 

case 5:
S = Sumatoria(Arreglo,N);
cout<<"La sumatoria es: "<<S<<"\n\n";
break; 

case 6:
Imprimir(Arreglo,N);
cout<<"El valor maximo es: "<<ValorMaximo(Arreglo,N)<<"\n\n";
break; 

case 7:
Imprimir(Arreglo,N);
cout<<"El valor minimo es: "<<ValorMinimo(Arreglo,N)<<"\n\n";
break; 

case 8:
cout<<"\nEl promedio es: "<<Promedio(Arreglo,N)<<"\n\n";
break; 

case 9:
cout<<"\nLos numeros mayores al promedio son: ";
MayoresPromedio(Arreglo,N);
cout<<"\n\n";
break; 

case 10:
int Valor,P;
cout<<"Que dato desea buscar: ";
cin>>Valor;
P=Buscar(Arreglo,N,Valor);
break; 

case 11:
cout<<"Dato a buscar: ";
cin>>Valor;
BuscarYModificar(Arreglo,N,Valor);
break; 

case 12:
if(N<=19)
{
N++;
InsertarPosCero(Arreglo,N);
Imprimir(Arreglo,N);
} 

else 
{
cout<<"No hay espacio suficiente\n\n";
}
break; 

case 13:
if(N<=19)
{
cout<<"Ingrese la cantidad del bloque: ";
cin>>Cant;
if (N+Cant<=20)
{
N=N+Cant;
InsertarBloqueI(Arreglo,N,Cant);
Imprimir(Arreglo,N);
} 

else 
{
cout<<"\nNo hay espacio suficiente\n\n";
}
} 

else 
{
cout<<"No hay espacio suficiente\n\n";
}
break; 

case 14:
if(N<=19)
{
cout<<"Ingrese la cantidad del bloque: ";
cin>>Cant;
if (N+Cant<=20)
{
N=N+Cant;
InsertarBloqueF(Arreglo,N,Cant);
Imprimir(Arreglo,N);
} 

else 
{
cout<<"\nNo hay espacio suficiente\n\n";
}
} 

else 
{
cout<<"No hay espacio suficiente\n\n";
}
break; 

case 15:
if(N<=19)
{
if (N+3<=20)
{
Imprimir(Arreglo,N);
cout<<"Ingrese entre que valores: ";
cin>>B>>C;
N=N+3;
InsertarBloqueM(Arreglo,N,B,C); 
Imprimir(Arreglo,N);
} 

else 
{
cout<<"No hay espacio suficiente\n\n";
}
} 

else 
{
cout<<"No hay espacio suficiente\n\n";
}
break; 

case 16:
	N--;
EliminarValorI(Arreglo,N);
Imprimir(Arreglo,N);
break; 

case 17:
N--;
EliminarValorF(Arreglo,N);
Imprimir(Arreglo,N);
break; 

case 18:
MetodoBurbuja(Arreglo,N);
break; 

case 19:
SeleccionDirecta(Arreglo,N);
break; 

case 20:
InsercionBinaria(Arreglo,N);
break; 

case 21:
InsercionDirecta(Arreglo,N);
break; 

case 22:
Shakersort(Arreglo,N);
break;

case 99:
cout<<"Hasta Pronto\n\n";
break; 

default:
cout<<"Opcion Invalida\n\n";
break;
}
system("pause");
system("cls");
}while(Opc!=99);
} 

void Imprimir(int A[], int N)
{
int i;
cout<<"\t  Contenido del Arreglo\n\n";
cout<<"Subindice \t Valores\n";
for (i=0; i<N; i++)
{
cout<<"    "<<i<<"\t\t   "<<A[i]<<"\n";
}
cout<<"\n";
} 

int IniManual(int A[],int N)
{
int i,Up;
for (i=0; i<N; i++)
{
cout<<"Arreglo [ "<<i<<" ] = ";
cin>>A[i];
}
cout<<"\n"; 

Up=N+1; 

return Up;
} 

int IniAleatorio(int A[], int N)
{
int i,Up,Num;

srand(time(NULL));
for (i=0; i<N; i++)
{
Num=1+rand()%100;
A[i]=Num;
}
cout<<"\n"; 

Up=N+1; 

return Up;
} 

void IniConN(int A[], int N , int Valor)
{
int i;
for (i=0; i<N; i++)
{
A[i]=Valor;
}
cout<<"\n";
} 

void IniDe1aN(int A[], int N)
{
int i;
for (i=0; i<N; i++)
{
A[i]=i+1;
}
cout<<"\n";
} 

int Sumatoria(int A[], int N)
{
int i, Sum=0;
for (i=0; i<N; i++)
{
Sum+=A[i];
} 

return Sum;
} 

int ValorMaximo(int A[], int N)
{
int i,Max=A[0];
for (i=0; i<N; i++)
{
if (A[i]>Max)
{
Max=A[i];
}
}
return Max;
} 

int ValorMinimo(int A[], int N)
{
int i,Min=A[0];
for (i=0; i<N; i++)
{
if (A[i]<Min)
{
Min=A[i];
}
}
return Min;
} 

float Promedio(int A[], int N)
{
int i; 
float Sum=0;
for (i=0; i<N; i++)
{
Sum+=A[i];
}
return Sum/N;
} 

void MayoresPromedio(int A[], int N)
{
int i;
for (i=0; i<N; i++)
{
if(A[i]>Promedio(A,N))
{
cout<<A[i]<<" ";
}
}
} 

int Buscar(int A[], int N, int Valor){
int i,Bandera=0,Pos=-1;
for (i=0; i<N; i++)
{
if (Valor==A[i])
{
Bandera=1;
Pos=i;
break;
}
} 

if (Bandera==1)
{
cout<<"\nDato Encontrado\n\n";
} 

else
{
cout<<"\nDato no Encontrado\n\n";
} 

return Pos;
} 

void BuscarYModificar(int A[], int N, int Valor)
{
int P=-1;
P=Buscar(A,N,Valor); 

if (P!=-1)
{
cout<<"Ingrese el nuevo valor: ";
cin>>A[P];
cout<<"\n\n";
}
} 

int InsertarPosCero(int A[], int N)
{
int i;
if (N<=20)
{
for (i=N; i>0; i--)
{
A[i]=A[i-1];
}
cout<<"Ingresa A[0]: ";
cin>>A[0];
cout<<"\n";
}
} 

int InsertarBloqueI(int A[], int N, int Cant)
{
int i;
if (N<=20)
{
for (i=N; i>=3; i--)
{
A[i]=A[i-Cant];
} 

cout<<"Ingrese los valores: \n";
for (i=0; i<Cant; i++)
{
cin>>A[i];
}
}
cout<<"\n";
} 

int InsertarBloqueF(int A[], int N, int Cant)
{
int i;
if (N<=20)
{
cout<<"Ingrese los valores: \n";
for (i=N-Cant; i<N; i++)
{
cin>>A[i];
}
}
cout<<"\n";
} 

int InsertarBloqueM(int A[], int N, int B, int C)
{
int i,b,c;
if (N<=20)
{
for (i=0; i<=N; i++)
{
if (A[i]==B)
{
b=i;
} 

if (A[i]==C)
{
c=i;
}
} 

if (c-b==1)
{
for (i=b+4; i<N; i++)
{
A[i]=A[i-3];
} 

cout<<"Ingrese los valores:\n";
for (i=b+1; i<=b+3; i++)
{
cin>>A[i];
}
cout<<"\n";
}
else
{
cout<<"\nNo cumple la condicion\n\n";
}
}
} 

void EliminarValorI(int A[], int N)
{
int i;
for (i=0; i<N; i++)
{
A[i]=A[i+1];
}
A[19]=0;
} 

void EliminarValorF(int A[], int N)
{
int i;
A[N]=0;
} 

void MetodoBurbuja(int A[], int N){
	int i,j,Aux,P=0,V=0;
	
		for (i=0; i<N; i++){
			P++;
			cout<<"\t   Pasada "<<P<<"\n";
			for (j=0; j<N-1; j++){
		
				cout<<A[j]<<" > "<<A[j+1];
				
					if (A[j]>A[j+1]){
						swap(A[j],A[j+1]);
						cout<<" V    ";
					}
				
					else{
						cout<<" F    ";
					}
				
					for(int k=0; k<N; k++){
						cout<<A[k]<<"  ";
					}
					cout<<"\n";
			}
			cout<<"\n";
		}
} 

void SeleccionDirecta(int A[], int N)
{
int i,j,k,PosMa,PosMe,May,Aux;
for (i=0; i<N-1; i++)
{
May=i;
for (j=i+1; j<N; j++)
{
if (A[j]<A[May])
{
May=j;
}
}
Aux=A[i];
A[i]=A[May];
A[May]=Aux; 

cout<<"Menor: "<<A[May]<<"\n";

for (k=0; k<N; k++)
{
cout<<" "<<A[k]<<" ";
}
cout<<"\n\n";
}
} 

void InsercionBinaria(int A[], int N){
	int i, j, Val,pm;
	
	for(int i=0; i<N;i++){	 //imprime arreglo original
		cout<<A[i]<<"  ";
	}
	cout<<"\n\n";

	for (int i=1; i<N; i++){
		Val = A[i];
		j = i-1;
	
	cout<<"\t   Pasada "<<i<<"\n";
	
	pm=(i+1)/(2);
	cout<<"\t  Pm="<<i+1<<"/2="<<pm<<"\n\n";
	
		while (j>=0 && A[j]>Val){
			A[j+1] = A[j];
			j--;
		
			cout<<Val<<" < "<<A[j+1]<<" V	";
		
			A[j+1]=Val;
		
			for (int i=0; i<N; i++){
			cout<<A[i]<<"  ";
			}
			cout<<"\n\n";
		}
		
		
		
	}
} 

void InsercionDirecta(int A[], int N){
int i, j, Val, Pas=1;
bool cambio=false;

	for(int i=0; i<N;i++){	 //imprime arreglo original
		cout<<A[i]<<"  ";
	}
	cout<<"\n\n";

	for (int i=1; i<N; i++){	
		Val = A[i];			 //guarda posicion
		j = i-1;			//guarda numero alado(izquierda)
		
	
		if (j>=0 && A[j]>Val){
			cout<<"\t   Pasada "<<Pas<<"\n";
			Pas++;
		}
	
		while(j>=0 && A[j]>Val){
			A[j+1] = A[j];
			j--;
		
			cout<<Val<<" < "<<A[j+1]<<" V    ";
		   A[j+1]=Val;
			
			for (int i=0; i<N; i++){
				cout<<A[i]<<"  ";
			}
			cout<<"\n\n";
			
			}
		}	
		
	}


void Shakersort(int A[],int N) {
	int Left = 0;
	int Right = N-1;
	int Pos=1;
	bool Swapped=false;
	
	while (Left < Right)
	{
		cout<<"\t   Pasada "<<Pos<<"\n";
		cout<<"\t	Derecha a izquierda\n";
		for (int i = Right; i > Left; i--)
		{
			cout<<A[i]<<" < "<<A[i-1]<<" ";
			if (A[i] < A[i-1]){
				swap(A[i],A[i-1]);
				Swapped=true;
				cout<<"V   ";
			}
			
			
			else
			{
				cout<<"F   ";
			}
			
			for (int i=0; i<N; i++)
			{
				cout<<A[i]<<"  ";
			}
			cout<<"\n";
		}
		Pos++;
		Left++;
		
		cout<<"\n";
		cout<<"\t	Izquierda a Derecha\n";
		for (int i=Left; i < Right; i++)
		{  
			cout<<A[i]<<" > "<<A[i+1]<<" ";
			if (A[i] > A[i+1])
			{
				swap(A[i],A[i+1]);
				Swapped=true;
				cout<<"V   ";
			}
			
			else
			{
				cout<<"F   ";
			}

			for (int i=0; i<N; i++)
			{
				cout<<A[i]<<"  ";
			}
			cout<<"\n";
		}
		Right--;
		
		cout<<"\n";
		
		if(!Swapped)
		{
			break;
		}
		else
		{
			Swapped=false;
		}
	}
}
