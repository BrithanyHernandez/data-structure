#include<iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *der;
	nodo *izq;
	
};

void crearArbol(nodo*);
void preOrden(nodo*);
void inOrden(nodo*);
void postOrden(nodo*);

int main(){
	nodo *raiz=NULL;
	raiz=new(nodo);
	
	crearArbol(raiz);
	cout<<"\n\nRecorrido pre-orden\n";
	preOrden(raiz);	//raiz->RI-RD
	
	cout<<"\n\nRecorrido in-Orden\n";
	inOrden(raiz);	//RI-Raiz-RD
	
	cout<<"\n\nRecorrido post-Orden\n";
	postOrden(raiz);		//RI-RD-Raiz
	
}

void crearArbol(nodo *raiz){
	int resp;
	nodo *nuevo;
	
	cout<<"Ingresa el valor del nodo: ";
	cin>>raiz->dato;
	
	cout<<raiz->dato<< "\ntiene hijo a la izquierda? (1.si 0.No)";
	cin>>resp;
	
	if(resp==1){
		nuevo=new(nodo);
		raiz->izq=nuevo;
		crearArbol(nuevo);
	}
	else{
		raiz->izq=NULL;
		
	}
	
	cout<<raiz->dato<<"	\ntiene hijo a la derecha? (1.si 0.No) ";
	cin>>resp;
	
	if(resp==1){
		nuevo=new(nodo);
		raiz->der=nuevo;
		crearArbol(nuevo);
	}
	else{
		raiz->der=NULL;
		
	}	
}

void preOrden(nodo *raiz){
	
	if(raiz!=NULL){
		cout<<raiz->dato<<"  ";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
	
}
void inOrden(nodo *raiz){
	
	if(raiz!=NULL){
		inOrden(raiz->izq);
		cout<<raiz->dato<<"  ";
		inOrden(raiz->der);
	}
	
}

void postOrden(nodo *raiz){
	
	if(raiz!=NULL){
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout<<raiz->dato<<"  ";
	}
	
}

