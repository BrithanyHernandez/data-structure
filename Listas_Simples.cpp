#include<iostream>
#include<conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

struct nodo{
	int dato;
	nodo *enlace;	
};

void imprimir(nodo*);
void InsertarDerecha(nodo*);
nodo *InsertarIzquierda(nodo*);
nodo *AleatorioDerecha(nodo*, int);
nodo *AleatorioIzquierda(nodo*, int);
int  Sumatoria(nodo*);
void Buscar(nodo*, int);
void BuscarModificar(nodo*, int, int);
void InsertarAntesX(nodo*, int, int);
void InsertarDespuesX(nodo*, int, int);
void InsertarAntes101Pares(nodo*);
void InsertarDespues101Pares(nodo*);
nodo *EliminarPrimerNodo(nodo*);
nodo *EliminarUltimoNodo(nodo*);
nodo *EliminarNodoX(nodo*, int);
nodo *EliminarEntreXY(nodo*, int, int);
nodo *EliminarAntesX(nodo*, int);
nodo *EliminarDespuesX(nodo*, int);


int main(){
	nodo *p=NULL;
	int opc;
	//p primer nodo de la lista
	//f ultimo nodo de la lista
	
	while(1){
		cout<<"\n\n0. Imprimir\n";
		cout<<"1. Insertar a la derecha\n";
		cout<<"2. Insertar a la izquierda\n";
		cout<<"3. Insertar aleatorios a la derecha\n";
		cout<<"4. Insertar aleatorios a la izquierda\n";
		cout<<"5. Sumatoria\n";
		cout<<"6. Buscar\n";
		cout<<"7. Buscar y modificar\n";
		cout<<"8. Insertar antes de X\n";
		cout<<"9. Insertar despues de X\n";
		cout<<"10.Insertar antes de todos los pares 101\n";
		cout<<"11.Insertar despues de todos los pares 101\n";
		cout<<"12.Eliminar primer nodo\n";
		cout<<"13.Eliminar ultimo nodo\n";
		cout<<"14.Eliminar nodo X\n";
		cout<<"15.Eliminar entre nodo X y Y\n";
		cout<<"16.Eliminar antes de X\n";
		cout<<"17.Eliminar despues de X\n";

		cout<<"Seleccione una opcion: ";
		cin>>opc;
		
		switch(opc){
			case 0:
				if(p==NULL){
					cout<<"Lista vacia\n";
				}
				else{
					imprimir(p);
				}
				break;
		
			case 1:
				if(p==NULL){	//lista vacia
					p=new(nodo);
					cout<<"Ingrese el valor: ";
					cin>>p->dato;	//guardamos nuetro valor
					p->enlace=NULL;	//para formar enlace con otro nodo
				
				}
				else{
					InsertarDerecha(p);
				}
				
				break;
				
			case 2:
				if(p==NULL){
					p=new(nodo);
					cout<<"Ingrese el valor: ";
					cin>>p->dato;
					p->enlace=NULL;
				}
				else{
					p=InsertarIzquierda(p);
				}
				break;
			case 3:
				int cant;
				
				cout<<"Ingresa la cantidad de valores: ";
				cin>>cant;
				p=AleatorioDerecha(p,cant);
				imprimir(p);
				
				break;
			
			case 4:
				
				cout<<"Ingresa la cantidad de valores: ";
				cin>>cant;
				p=AleatorioIzquierda(p,cant);
				imprimir(p);
				
				break;
				
			case 5:
				cout<<"La sumatoria es: "<<Sumatoria(p);
				break;
				
			case 6:
				int valor;
				
				cout<<"Ingrese el dato a buscar: ";
				cin>> valor;
				Buscar(p, valor);
				
				break;
			
			case 7:
				int nuevoVal;
				
				cout<<"Ingresa el dato a buscar: ";
				cin>>valor;
				
				cout<<"Ingresa el nuevo valor: ";
				cin>>nuevoVal;
				
				BuscarModificar(p,valor,nuevoVal);
				imprimir(p);
				
				break;
			
			case 8:
				int X, inserVal;
				
				cout<<"Ingrese el valor de X: ";
				cin>>X;
				cout<<"Ingresa el nuevo valor: ";
				cin>>inserVal;
				
				InsertarAntesX(p,X,inserVal);
					
				break;	
			
			case 9:
				cout<<"Ingresa el valor de X: ";
				cin>>X;
				cout<<"Ingresa el nuevo valor: ";
				cin>>inserVal;
				
				InsertarDespuesX(p,X,inserVal);
				
				break;
			
			case 10:
				InsertarAntes101Pares(p);
			
				break;
			
			case 11:
				InsertarDespues101Pares(p);
				break;
				
			case 12:
				EliminarPrimerNodo(p);
				
				break;
				
			case 13:
				EliminarUltimoNodo(p);
				break;
			
			case 14:
				int nodoX;
				
				cout<<"Ingresa el nodoX: ";
				cin>>nodoX;
				
				EliminarNodoX(p, nodoX);
				
				break;	
				
			case 15:
				int x,y;
				
				cout<<"Ingresa nodo X: ";
				cin>>x;
				cout<<"\nIngresa nodo Y: ";
				cin>>y;
				
				EliminarEntreXY(p, x, y);
				
				break;
				
			case 16:
				
				cout<<"Ingresa nodo X: ";
				cin>>x;
				
				EliminarAntesX(p, x);
				
				break;		
			
			case 17:
				cout<<"Ingresa nodo X: ";
				cin>>x;
				
				EliminarDespuesX(p, x);
				
				break;
							
		}	
	}	
	return 0;
	getch();
}

void imprimir(struct nodo *aux){
	cout<<"\n\nContenido de la lista: \n";
	
	while(aux!=NULL){
		cout<<aux->dato<<" ";
		aux=aux->enlace;
	}	
}

void InsertarDerecha(struct nodo *p){
	struct nodo *f, *aux;
	//aux=nodo nuevo
	
	f=p;
	while(f->enlace=NULL){
		f=f->enlace;	
	}
	aux=new(nodo);
		cout<<"Ingrese el dato: ";
		cin>>aux->dato;
		aux->enlace=NULL;
		f->enlace=aux;
		f=aux;
}

nodo *InsertarIzquierda(struct nodo *p){
	struct nodo *aux;
	
	aux=new(nodo);
	cout<<"Ingresa el dato: ";
	cin>>aux->dato;
	aux->enlace=p;
	p=aux;
	
}

nodo *AleatorioDerecha(struct nodo *p, int cant){
	struct nodo *aux, *f;
	srand(time(NULL));
	
	if(p==NULL){
		p=new(nodo);
		p->dato= 1+rand()%100;
		p->enlace=NULL;
		f=p;
		
		for(int i=2; i<=cant; i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=NULL;
			f->enlace=aux;
			f=aux;
		}
	}
	else{
		f=p;
		
		while(f->enlace!=NULL){
			f=f->enlace;
		}
		for(int i=1; i<=cant; i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=NULL;
			f->enlace=aux;
			f=aux;
		}	
	}
	return p;	
}

nodo *AleatorioIzquierda(struct nodo *p, int cant){
	struct nodo *aux, *f;
	srand(time(NULL));
	
	if(p==NULL){
		p=new(nodo);
		p->dato= 1+rand()%100;
		p->enlace=NULL;
		
		for(int i=2; i<=cant; i++){
			
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=p; 
			p=aux;
		}
	}
	
	else{
		for(int i=1; i<=cant; i++){
			
			aux=new(nodo);
			aux->dato= 1+rand()%100;
			aux->enlace=p;
			p=aux;
		}
	}			
	return p;
}

int Sumatoria(struct nodo *p){
	int suma=0;
	struct nodo *aux;
	
	aux=p;
	
	while(aux!=NULL){
		suma+=aux->dato;
		aux=aux->enlace;
	}
	return suma;
}

void Buscar(struct nodo *p, int valor){
	struct nodo *aux;
	int band=0;
	
	aux=p;
	
	if(aux==NULL){
		cout<<"Lista vacia\n";
	}
	else{
		while(aux!=NULL){
			if(valor==aux->dato){
				
				band=1;
				break;//rompe con el ciclo while
			}
			aux=aux->enlace;
		}
		
		if(band=1)
			cout<<"Dato encontrado\n";
		else
			cout<<"Dato no encontrado\n";
		
	}
}

void BuscarModificar(struct nodo *p, int valor, int nuevoVal){
	struct nodo *aux;
	int band=0;
	
	aux=p;
	
	while(aux->dato!= NULL){
		
		if(valor==aux->dato){
			band=1;
			aux->dato=nuevoVal;
			break;	//salimos de funcion
		}
		
		aux=aux->enlace;
	}
	
	if(band=0){
		cout<<"Dato no encontrado\n";
	}	
}

void InsertarAntesX(struct nodo *p, int X, int inserVal){
	struct nodo *aux, *aux2, *nuevo;
	int band=0;
	
	aux=p;
	
	if(aux==NULL){
		cout<<"Lista vacia\n";
	}
	
	else{
		while(aux!=NULL){
			if(aux->dato==X){
				band=1;
				
				if(aux==p){
					
					nuevo=new(nodo);
					
					nuevo->dato=inserVal;	//no hay datos antes
					
					nuevo->enlace=p;
					p=nuevo;
				}
				
				else{	
					nuevo=new(nodo);	//creamos nuevo nodo
					
					nuevo->dato=inserVal;
					
					aux2->enlace=nuevo;	//datos anterio lo enlazamo con el nuevo
					nuevo->enlace=aux;		
				}
				imprimir(p);
			}
			aux2=aux;
			aux=aux->enlace;
		}	
	}
}

void InsertarDespuesX(struct nodo *p, int X, int inserVal){
	struct nodo *aux, *nuevo;
	int band=0;
	
	aux=p;
	
	if(aux==NULL){
		cout<<"Lista vacia\n";
	}
	else{
		while(aux!=NULL){
			if(aux->dato==X){
	
					nuevo=new(nodo);
					
					nuevo->dato=inserVal;
					nuevo->enlace=aux->enlace;
					aux->enlace=nuevo;
					
					band=1;				
			}				
		aux=aux->enlace;	
		}
		
		if(band==1){
			imprimir(p);
		}
		else{
			cout<<"El valor no existe\n";
		}	
	}	
}

void InsertarAntes101Pares(struct nodo *p){
	struct nodo *aux, *aux2, *nuevo;
	int band=0;
	aux=p;
	if(aux==NULL){
		cout<<"Lista vacia\n";
	}
	
	else{
		while(aux!=NULL){
			if(aux->dato%2==0){
				band=1;
				
				if(aux==p){
					
					nuevo=new(nodo);
					nuevo->dato=101;	//no hay datos antes	
					nuevo->enlace=p;
					p=nuevo;
				}
				
				else{	
					nuevo=new(nodo);	//creamos nuevo nodo
					
					nuevo->dato=101;
					aux2->enlace=nuevo;	//datos anterio lo enlazamo con el nuevo
					nuevo->enlace=aux;		
				}
			}
			aux2=aux;
			aux=aux->enlace;
		}	
	}
	imprimir(p);
}

void InsertarDespues101Pares(struct nodo*p){
	struct nodo *aux, *nuevo;
	int band=0;
	
	aux=p;
	
	if(aux==NULL){
		cout<<"Lista vacia\n";
	}
	else{
		while(aux!=NULL){
			if(aux->dato%2==0){
	
					nuevo=new(nodo);
					
					nuevo->dato=101;
					nuevo->enlace=aux->enlace;
					aux->enlace=nuevo;
					band=1;				
			}				
		aux=aux->enlace;	
		}
		
		if(band==1){
			imprimir(p);
		}	
	}	
}

nodo *EliminarPrimerNodo(struct nodo *p){
	nodo *aux;
	aux = p;
	
	if(aux ==NULL)
		cout<<"Lista vacia.\n";
		
	else{
		if(aux->enlace ==NULL){
			delete(aux);
			p=NULL;
		}
		else{
			p= p->enlace;
			aux ->enlace =NULL;
			delete(aux);
		}
		
		imprimir(p);
	}
	
	return p;
}

nodo *EliminarUltimoNodo(nodo *p){

	nodo*aux,*aux2;
	aux=p;
	
	if(aux==NULL)
		cout<<"Lista vacia \n";
		
	else if(aux->enlace==NULL){
			delete (aux);
			p=NULL;
	}
	else{
		
		while(aux->enlace!=NULL){
			aux2=aux;
			aux=aux->enlace;
		}
		aux2->enlace=NULL;
		delete(aux);
	}
	imprimir(p);
	return p;
}

nodo *EliminarNodoX(nodo *p, int nodoX){
	nodo*aux,*aux2;
	
	aux=p;
	
	if(aux==NULL)
	cout<<"Lista vacia \n";
	else{
		
		if(aux->enlace==NULL){
			delete(aux);
			p=NULL;
		}
		else{
			while((aux!=NULL)&&(aux->dato!=nodoX)){
				
				aux2=aux;
				aux=aux->enlace;
			}
			if(aux==p){	//Elimina el primer Dato
				p=aux->enlace;
				aux->enlace=NULL;
				delete(aux);
			}
				else if(aux==NULL){
					cout<<"No se ha encontrado el elemento\n";
				}
				else if(aux2==NULL){
					
					p=p->enlace;
					delete(aux);
				//
					cout<<"El Dato se ha borrado bien\n";
				}
				else{
					
					aux2->enlace=aux->enlace;
					delete(aux);
					//cout<<"El Dato se ha borrado bien\n";
				}		
		}	
	}
	imprimir(p);
	
	return p;
}

nodo *EliminarEntreXY(nodo *p, int x, int y){
	nodo *aux_x = p, *aux_y = p;
	
	if(p==NULL){
				cout<<"Lista vacia\n";
			}
			else
    while(aux_x != NULL && aux_x->dato != x)
	{
        aux_x = aux_x->enlace;
    }

    if(aux_x == NULL)
	{
        cout << "Dato en (x) no identificado\n";
        return p;
    }

    while(aux_y != NULL && aux_y->dato != y){
        aux_y = aux_y->enlace;
    }

    if(aux_y == NULL)
	{
        cout << "Dato en (y) no identificado\n" ;
		nodo *EliminarEntreXY(nodo *p,int x,int y);
		{
        	return p;
			nodo *aux_x = p, *aux_y = p;
    		while(aux_x != NULL && aux_x->dato != x)
			{
    		}
        	aux_x = aux_x->enlace;
    	}
    // Aqui se elimina los Nodos entre x e y

    // aux_x apunta al Nodo x
    if(aux_x == NULL){
    // aux_y apunta al Nodo y
        cout << "El Dato (x) no ha sido encontrado";

        return p;
    while(aux_x->enlace!= aux_y){
    	
    }
        nodo *aux = aux_x->enlace;

        aux_x->enlace = aux->enlace;
   		 while(aux_y != NULL && aux_y->dato != y){
        delete aux;
        aux_y = aux_y->enlace;
    }
    }


    // reenlazar los Nodos
    if(aux_y == NULL){
    aux_x->enlace = aux_y;
        cout << "El Dato (y) no ha sido encontrado";
        return p;
    return p;
    }
}
    // Aqui se elimina los Nodos entre x e y
    // aux_x apunta al Nodo x
    // aux_y apunta al Nodo y

    while(aux_x->enlace != aux_y){
        nodo *aux = aux_x->enlace;
        aux_x->enlace = aux->enlace;
        delete aux;
    }

    // reenlazar los Nodos
    aux_x->enlace = aux_y;
    
    imprimir(p);
    
	
	return p;
}
 
 
nodo *EliminarAntesX(nodo *p, int x){

	int cont=0;
	nodo*aux,*aux2,*aux3;
	int band=0;
	aux=p;
	if(aux==NULL)
	cout<<"Lista vacia\n";
	else
	{
		while(aux!=NULL)
		{
			cont++;
			if(aux->dato==x)
			{
				band=1;
				if(aux==p)
				cout<<"No hay un Dato antes de:"<<x<<"\n";
				else
				{
					if(aux2==p)
					{
						p=aux;
						aux2->enlace=NULL;
						delete (aux2);
					}
					else
					{
						aux3->enlace=aux;
						aux2->enlace=NULL;
						delete(aux2);
					}
				}
			}
			if(cont>=2)
			aux3=aux2;
			aux2=aux;
			aux=aux->enlace;	
		}
		imprimir(p);	
	}
	if(band==0)
	cout<<"Dato NO encontrado\n";	
	
	return p;
}
nodo *EliminarDespuesX(nodo *p, int x){
	
	nodo* actual = p;
    nodo* anterior = NULL;
	if(p==NULL)
	cout<<"Lista vacia\n";
	else
    // Buscar Nodo con valor x
    while (actual != NULL && actual->dato != x) {
        anterior = actual;
        actual = actual->enlace;
    }

    if (actual == NULL) {
        cout << "Dato NO encontrado\n";
        return p;
    }

    if (actual->enlace == NULL) {
        cout << "No hay Dato despues de:"<< x <<"\n";
        return p;
    }

    // Eliminar Nodo siguiente a x
    nodo* temp = actual->enlace;
    actual->enlace = temp->enlace;
    delete temp;
	
	imprimir(p);
	
	
	
	return p;
}


	
	















