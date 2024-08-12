#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

struct nodo{
	int dato;
	nodo *sig, *ant;	
};

void ImprimirP_F( nodo*);
void ImprimirF_P( nodo*);
nodo *InsertarDerecha( nodo*, nodo* ); //p y f
nodo *InsertarIzquierda( nodo*, nodo*);
nodo *InsertarAleatoriosFin( nodo*, int);
nodo *InsertarAleatoriosInicio( nodo*, int);
nodo *InsertarAleatoriosX_Y( nodo*, int, int);
nodo *Buscar(nodo*, int);
nodo *Modificar(nodo*, int, int);
nodo *InsertarAleatoriosAntesRef(nodo*, int);
nodo *InsertarAleatoriosDespuesRef(nodo*, int);
nodo *EliminarInicio(nodo* );
nodo *EliminarFin(nodo* );
nodo *EliminarX_Y(nodo*, int, int);


//nodo *EliminarN_Referencia(nodo*, int, int);

int main(){
	nodo *p=NULL;
	nodo *f=NULL;
	int opc;
	
	while(1){
		
		cout<<"\t\nMenu\n";
		cout<<"1. Imprimir de P a F\n";
		cout<<"2. Imprimir de F a P\n";
		cout<<"3. Insertar nodo ala derecha\n";
		cout<<"4. Insertar nodo ala izquierda\n";
		cout<<"5. Insertar aleatorios al final\n";
		cout<<"6. Insertar aleatorios al inicio\n";
		cout<<"7. Insertar aleatorios entre X y Y\n";	//<3
		cout<<"8. Buscar\n";
		cout<<"9. Modificar\n";
		cout<<"10. Insertar aleatorios antes de referencia\n";	//<3
		cout<<"11. Insertar aleatorios despues de referencia\n";//<3
		cout<<"12. Eliminar inicio\n";	//:)
		cout<<"13. Eliminar final\n";
		cout<<"14. Eliminar entre X y Y\n";	//:)
		cout<<"15. Eliminar todos los primos\n";	//:)
		cout<<"16. Eliminar N despues de referencia\n";	//:)
		cout<<"Selecciona una opcion: ";
		cin>>opc;
		
		
		switch(opc){
			case 1:
				if (p==NULL){
					cout<<"\nLista vacia\n";
				}
				else{
					ImprimirP_F(p);
				}	
				
				break;
			
			case 2:
				
				if(f==NULL){
					cout<<"\nLista vacia\n";
				}
				else{
					ImprimirF_P(f);
				}
				break;
			
			case 3:
				
				if(p==NULL){
					p= new(nodo);
					cout<<"Ingresa el dato: ";
					cin>>p->dato;
					p->sig=NULL;
					p->ant=NULL;
					f=p;
				}
				else{
					f=InsertarDerecha(f,p);
				}
				
				break;
			
			case 4:
				
				if(p==NULL){	//LISTA VACIA
					p=new(nodo);
					cout<<"Ingresa el dato: ";
					cin>>p->dato;
					p->sig=NULL;
					p->ant=NULL;		
					f=p;
				}
				else
					p=InsertarIzquierda(p,f);
				
				break;
				
				case 5:
					int cant;
					
					cout<<"Cuantos datos aleatorios desea: ";
					cin>>cant;
					
					if(p==NULL){	//LISTA VACIA
						
						p=new(nodo);	//CREA UN SOLO DATO	
						p->dato= 1+rand()%100;
						p->ant=NULL;
						p->sig=NULL;
						f=p;					
						f=InsertarAleatoriosFin(f, cant);
					}
					else{
						f=InsertarAleatoriosFin(f,cant+1);
					}
					break;
				
				case 6:
						
					cout<<"Cuantos datos aleatorios desea: ";
					cin>>cant;
					
					if(p==NULL){	//LISTA VACIA
						
						p=new(nodo);	//CREA UN SOLO DATO	
						p->dato= 1+rand()%100;
						p->sig=NULL;
						p->ant=NULL;
						f=p;
											
						p=InsertarAleatoriosInicio(p, cant);
					}
					else{
						p=InsertarAleatoriosInicio(p,cant+1);
					}
					break;
					
				case 7:
					int x,y;
					
					cout<<"Ingresa el valor de X: ";
					cin>>x;
					cout<<"Ingresa el valor de Y: ";
					cin>>y;
					
					p= InsertarAleatoriosX_Y( p, x, y);
					
					break;
					
				case 8:
					int ValBuscar;
					
					cout<<"Ingrese el dato a buscar: ";
					cin>>ValBuscar;
					
					p=Buscar(p, ValBuscar);
					
					break;
					
				case 9: 
					int NuevoVal;
				
					cout<<"Ingresa el dato a modificar: ";
					cin>>ValBuscar;
					
					cout<<"Ingresa el nuevo valor: ";
					cin>>NuevoVal;
					
					p=Modificar(p, ValBuscar, NuevoVal);
				
					break;		
			
				case 10:
					int Ant_Ref;
					
					cout<<"Ingresa la referencia: ";
					cin>>Ant_Ref;
					
					p=InsertarAleatoriosAntesRef(p, Ant_Ref);
					
					break;
					
				case 11:
					int Desp_Ref;
					
					cout<<"Ingresa la referencia: ";
					cin>>Desp_Ref;
					
					p=InsertarAleatoriosDespuesRef(p, Desp_Ref);
					
					break;
					
				case 12:
					
					p=EliminarInicio(p);
					
					break;	
					
				case 13:
					EliminarFin(p);
					
					break;
					
				case 14:
					int X,Y;
					
					cout<<"Ingresa X: ";
					cin>>X;
					cout<<"Ingresa Y: ";
					cin>>X;
					
					p= EliminarX_Y( p, X,Y);
					
					break;
				
				case 15:
					break;
				
				case 16:
					int r,n;
					
					cout<<"Ingresa el valor de la referencia: ";
					cin>>r;
					cout<<"Ingresa la cantidad a eliminar: ";
					cin>>n;
					
				//	p=EliminarN_Referencia(p,r,n);
					
					break;			
						
		}
	}	
}

void ImprimirP_F(nodo *p){
	nodo *aux;
	aux=p;
	
	while(aux!=NULL){
		cout<<aux->dato<<" ";
		aux=aux->sig;
	}
	cout<<"\n";
}

void ImprimirF_P(nodo *f){
	nodo *aux;
	aux=f;
	
	while(aux!=NULL){
		cout<<aux->dato <<" ";
		aux=aux->ant;
	}
	cout<<"\n";
}

nodo *InsertarDerecha( nodo *f, nodo *p){
	nodo *aux;
	aux=new(nodo);
	cout<<"Ingresa el dato: ";
	cin>>aux->dato;			//guardando
	aux->ant=f; 			
	aux->sig=NULL;
	f->sig=aux;
	f=aux;
	return f;
}

nodo *InsertarIzquierda(nodo *p, nodo *f){
	nodo *aux;
	aux=new(nodo);
	cout<<"Ingresa el dato: ";
	cin>>aux->dato;
	aux->sig=p;
	aux->ant=NULL;
	p->ant=aux;
	p=aux;
	
	return p;
}

nodo *InsertarAleatoriosFin( nodo *f, int cant){
	nodo *aux;
	
	for(int i=2; i<=cant; i++){
		
		aux=new(nodo);
		aux->dato= 1+rand()%100;
		
		aux->ant=f;		 //Enlaza con el ultimo nodo que teniamos
		aux->sig=NULL;	//sera ultimo nodo
		f->sig=aux;	   //ultimo nodo que ya teniamos lo enlazamos con el nuevo
		f=aux;		  //el creado (AUX) sera el ultimo	
	}

	return f;
}

nodo *InsertarAleatoriosInicio(nodo *p, int cant){
	nodo *aux;
	
	for(int i=2; i<=cant; i++){
	
		aux=new(nodo);
		aux->dato= 1+rand()%100;
		aux->sig=p;			
		aux->ant=NULL;		//termina de enlazar el nuevo con el PrimerNodo
		p->ant=aux;			//termina de enlazar el PrimerNodo con el nuevo
		p=aux;
		
	}
	return p;
}

nodo *InsertarAleatoriosX_Y( nodo *p, int x, int y){
	
	nodo *aux, *nuevoNodo;	//donde crearemos nodos
	int cantidad;
	bool X_Encontrado=false;
	
	aux=p;
	
	while(aux!=NULL){
		
		if(aux->dato==x){
			
			X_Encontrado= true;
			break;				//Rompe while, deja de buscar
		}
		
		aux=aux->sig;	//enlaza al siguiente nodo
		
	}
	
	if( X_Encontrado && aux->sig!=NULL && aux->sig->dato==y ){ //:))
		
		cout<<"Cuantos datos aleatorios desea: ";
		cin>>cantidad;
		
		for(int i=0; i<cantidad; i++){
			
			nuevoNodo= new(nodo);
			nuevoNodo->dato= 1+rand()%100;
			nuevoNodo->sig= aux->sig;
			nuevoNodo->ant=aux;
			
			if(aux->sig!=NULL){
				aux->sig->ant = nuevoNodo;
			}
		aux->sig = nuevoNodo;	
		}	
	}
	else{
		cout<<"Los valores X-Y no se encuentran justos en la lista\n";
	}	
	
	return p;
}

nodo *Buscar(nodo *p, int ValBuscar){
	nodo *aux;
	aux=p;
	bool Buscar=false;
	
	while(aux!=NULL){
		
		if(aux->dato==ValBuscar){
			Buscar=true;
			break;
		}
		aux=aux->sig;	//para avanzar y hacer enlace
	}
	
	if(Buscar){
		cout<<"\nEl "<<ValBuscar<<" ha sido encontrado\n";
		
	}
	else{
		cout<<"\nEl "<<ValBuscar<<" no existe en la lista\n";
	}
	return p;
}

nodo *Modificar(nodo *p, int ValBuscar, int NuevoVal){
	nodo *aux;
	aux=p;
	bool Buscar=false;
	
	while(aux!=NULL){
		
		if(aux->dato==ValBuscar){
			Buscar=true;
			
			aux->dato=NuevoVal;
			
			return p;
		}

		aux=aux->sig;	//para avanzar y hacer enlace
	}
	
	if(Buscar){
		cout<<"El dato no existe\n";
	}
	return p;
}

nodo *InsertarAleatoriosAntesRef(nodo *p, int Ant_Ref){
	nodo *aux = p;
    nodo *anterior = NULL;
    nodo *nuevo;
    int cant;
    int contador = 0;
    
    while (aux != NULL){
    	
        if (aux->dato == Ant_Ref){
        	
        	cout<<"Ingresa la cantidad de valores aleatorios: ";
        	cin>> cant;
        	
            for (int i=0; i<cant; i++){
            	
                nuevo= new(nodo);
                nuevo->dato= 1+rand() % 100;
                nuevo->ant = anterior;		//:)
                nuevo->sig = aux;

                if (anterior != NULL){
                    anterior->sig = nuevo;
                }
                else{
                    p = nuevo; // Si la referencia está al principio de la lista, actualiza el puntero principal
                }
                aux->ant = nuevo;
                anterior = nuevo;
                contador++;
            }
            break;
        }
        anterior = aux;
        aux = aux->sig;
    }

    if (contador == 0){
        cout << "La referencia no se encontro en la lista." << endl;
    }
    
    else{
        cout<< endl;
    }

    return p;
}

nodo *InsertarAleatoriosDespuesRef(nodo *p, int Desp_Ref){
	nodo *aux = p;
    int contador = 0;
    int cant;
    
    while (aux != NULL){
    	
        if (aux->dato == Desp_Ref){
        	
        	cout<<"Cuantos datos aleatorios deseas: ";
        	cin>>cant;
        	
            for (int i = 0; i <cant; i++){
                nodo *nuevo = new(nodo);
                nuevo->dato = 1 + rand() % 100;
                nuevo->sig = aux->sig;
                nuevo->ant = aux;

                if (aux->sig != NULL){
                    aux->sig->ant = nuevo;
                }
                aux->sig = nuevo;
                aux = nuevo;
                contador++;
            }
            break;
        }
        aux = aux->sig;
    }

    if (contador == 0){
        cout << "No se encontro la referencia en la lista" << endl;
    }
    
    else{
        cout<< endl;
    }

    return p;
}

nodo *EliminarInicio( nodo *p){
	
	nodo *aux;
	aux=p;
	
	if(aux==NULL){
		cout<<"Lista vacia\n";
	}
	else{
		if(aux->sig==NULL){
			delete(aux);
			p=NULL;		//nodo vacio
		}
		else{
			p= p->sig;
			p= p->ant;
			aux ->sig =NULL;
			delete(aux);
			aux=aux->sig;
		}
	}
	
	return p;
}

nodo *EliminarFin( nodo *p){
	
	nodo*aux,*aux2;
	aux=p;
	
	if(aux==NULL)
		cout<<"Lista vacia \n";
		
	else if(aux->sig==NULL){
			delete (aux);
			p=NULL;
	}
	else{
		
		while(aux->sig!=NULL){
			aux2=aux;
			aux=aux->sig;
		}
		aux2->sig=NULL;
		delete(aux);
	}

	return p;
	
}

nodo *EliminarX_Y(nodo *p, int X, int Y){
	
	nodo *aux_X, *aux_Y;	
	bool X_Encontrado=false;
	bool Y_Encontrado= false;
	aux_X=p;
	aux_Y=p;
	
	if(p==NULL){
		cout<<"Lista vacia\n";
	}
	
	else{
		
		while( aux_X!=NULL && aux_X->dato!=X	){	//recorremos
		
			if(aux_X->dato==X){
			
			X_Encontrado= true;
			break;				//Rompe while, deja de buscar
			}
			
		aux_X=aux_X->sig;	//enlaza al siguiente nodo
		}
		
		while(	aux_Y!=NULL && aux_Y->dato!=Y){
			
			if(aux_Y->dato==Y){
				
				Y_Encontrado=true;
				break;
			}
			
		aux_Y= aux_Y->sig;	
		}
		
		
         while(aux_X->sig != aux_Y){
        nodo *aux = aux_X->sig;
        aux_X->sig = aux->sig;
        delete aux;
    }

    // reenlazar los Nodos
    aux_X->sig=aux_Y->ant;
    aux_Y->ant=aux_X->sig;
	}
	return p;
} 

//:) eliminar primos


		
		
		
		
		
		
		
		
	











