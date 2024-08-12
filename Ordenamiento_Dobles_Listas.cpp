#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

struct nodo{
	int dato;
	nodo *sig,*ant;
};

void ImprimirIzqDer(nodo *);
void ImprimirDerIzq(nodo *);
nodo *InsertarDerecha(nodo *);
nodo *InsertarIzquierda(nodo *);
nodo *InsAleatDerecha(nodo *,int);
nodo *InsAleatIzquierda(nodo *,int);
nodo *InsertarNodoX(nodo *, int,int);
void Burbuja(nodo *);
void ShakerSort(nodo *);
nodo *seleDirecta(nodo*,int);
void InsercionBinaria(nodo*);	//punto medio
void insercionDirecta(nodo *);

int main(){
	int opc,aleat,n,x;
	nodo *p=NULL, *f=NULL;

	while (1){
		cout << "\tMENU\n";
		cout << "0. Imprimir de Izquierda a Derecha \n";
		cout << "1. Imprimir de Derecha a Izquierda \n";
		cout << "2. Insertar a la derecha \n";
		cout << "3. Insertar a la izquierda \n";
		cout << "4. Insertar aleatorios a la derecha \n";
		cout << "5. Insertar aleatorios a la izquierda \n";
		cout << "6. Insertar cada N nodos el valor...\n";
		cout <<"METODOS\n";
		cout << "7. Metodo burbuja\n";  //<3
		cout << "8. Metodo Shaker Sort\n";	//:) incrementar y disminuir extremos                   
		cout << "9. Metodo Seleccion directa <3\n";  //<3         
		cout << "10. Metodo Insercion binaria\n";	//:)           
		cout << "11. Metodo Insercion directa\n";            
		cout << "12. Salir \n";

		cout << "\nSeleccionar una opcion: ";
		cin >> opc;
		cout <<"\n";

		switch (opc){
			
		case 0:
			if (p == NULL){
				cout << "Lista vacia\n\n";
			}
			else{
				ImprimirIzqDer(p);
			}
			break;
			
		case 1:
			if (f == NULL){
				cout << "Lista vacia\n\n";
			}
			else{
				ImprimirDerIzq(f);
			}
			break;
			
		case 2:
			if(p==NULL){
				p=new(nodo);
				cout<<"Ingresar el dato: ";
				cin>>p->dato;
				cout<<"\n";
				p->sig=NULL;
				p->ant=NULL;
				f=p;
			}
			else{
				f=InsertarDerecha(f);
			}
			break;
			
		case 3:
			if(p==NULL){
				p=new(nodo);
				cout<<"Ingresar el dato: ";
				cin>>p->dato;
				p->sig=NULL;
				p->ant=NULL;
				f=p;
			}
			else{
				f=InsertarIzquierda(p);
			}
			
			break;

		case 4:
			srand(time(NULL));
			cout<<"¿Cuantos datos aleatorios quieres? ";
			cin>>aleat;
			cout<<"\n";
			if(p==NULL){
				p=new(nodo);
				p->dato=1+rand()%100;
				p->sig=NULL;
				p->ant=NULL;
				f=p;
				f=InsAleatDerecha(f,aleat);
			}
			else{
				f=InsAleatDerecha(f,aleat+1);
			}
			break;

		case 5:
			srand(time(NULL));
			cout<<"¿Cuantos datos aleatorios quieres? ";
			cin>>aleat;
			cout<<"\n";
			if(p==NULL){
				p=new(nodo);
				p->dato=1+rand()%100;
				p->sig=NULL;
				p->ant=NULL;
				f=p;
				p=InsAleatIzquierda(p,aleat);
			}
			else{
				p=InsAleatIzquierda(p,aleat+1);
			}
			break;

		case 6:
			if(p==NULL)
			cout<<"Lista vacia\n\n";
			else {
				cout <<"¿Cuantos dato quieres ingresar? ";
				cin>>n;
				cout <<"\n\n";
				cout <<"¿Cada cuantas posiciones deseas insertar el valor?";
				cin>>x;
				cout << "\n\n";
				p=InsertarNodoX(p,x,n);
			}
			break;
			
		case 7:
			if (p == NULL) {
				cout<<"Lista vacia\n\n";
			}
			else{
				Burbuja(p);
			}
			break;	
			
		case 8:
			ShakerSort(p);
			break;	
			
		case 9:
			int total;
			seleDirecta(p,total);
			break;	
			
		case 10:
			
			InsercionBinaria(p);
			break;
			
		case 11:
			insercionDirecta(p);
			break;			

		case 12:
			cout << "Cerrando...\n\n";
			exit(-1);
			break;

		default:
			cout << "Opcion invalida\n\n";
			break;
		}
	}
}

void ImprimirIzqDer(nodo *p){
	nodo *aux;
	aux = p;
	while (aux != NULL){
		cout<<aux->dato<<" ";
		aux=aux->sig;
	}
	cout << "\n\n";
	cout << "-----------------------------------\n";
}

void ImprimirDerIzq(nodo *f){
	nodo *aux;
	aux = f;
	while (aux != NULL){
		cout<<aux->dato<<" ";
		aux=aux->ant;
	}
	cout << "\n\n";
	cout << "-----------------------------------\n";
}

nodo *InsertarDerecha(nodo *f){
	nodo *aux;
	aux=new(nodo);
	cout<<"Ingresar el dato: ";
	cin>>aux->dato;
	cout<<"\n";
	aux->sig=NULL;
	aux->ant=f;
	f->sig=aux;
	f=aux;
	return f;
}

nodo *InsertarIzquierda(nodo *p){
	nodo *aux;
	aux = new (nodo);
	cout << "\nIngresa el dato: ";
	cin >> aux->dato;
	cout << "\n";
	aux->sig=p;
	aux->ant = NULL;
	p->ant = aux;
	p = aux;
	return p;
}


nodo *InsAleatDerecha(nodo *f, int aleat){
	nodo *aux;
	for(int i=2;i<=aleat;i++){
		aux=new(nodo);
		aux->dato=1+rand()%100;
		aux->ant=f;
		aux->sig=NULL;
		f->sig=aux;
		f=aux;
	}
	return f;
}


nodo *InsAleatIzquierda(nodo *p,int aleat){
	nodo *aux;
	for(int i=2;i<=aleat;i++){
		aux=new(nodo);
		aux->dato=1+rand()%100;
		aux->ant=NULL;
		aux->sig=p;
		p->ant=aux;
		p=aux;
	}
	return p;
}

nodo* InsertarNodoX(nodo* p, int x, int n) {
    nodo* aux=p;
    nodo* aux2=NULL;
    nodo* aux3=NULL;
    int c=0;
    while (aux!=NULL){
        c++;
        aux2=aux;
        aux=aux->sig;
        if (c==n){
            if (n>c){
                cout<<"Numero excedido"<< endl;
                return p;
            }
            aux3=new(nodo);
            aux3->dato = x;
            aux3->sig = aux;
            aux3->ant = aux2;
            if(aux2!=NULL){
                aux2->sig = aux3;
            } 
			else{
                p = aux3;
            }
            if(aux != NULL) {
                aux->ant = aux3;
            }
            c=0;
        }
    }

    return p;
}

void Burbuja(nodo *p){
	
	int total=0,i,j,temp;
	nodo *aux,*aux2;
	aux=p;
	
	while(aux!=NULL){
		total++;
		aux=aux->sig;
	}
	for(i=1;i<total;i++){	//comienzan ciclo para comparar
		aux=p;
		aux2=aux->sig;
		
		for(j=1;j<total;j++){
			
			if(aux->dato > aux2->dato){
				temp=aux->dato;	//guarda el primer num
				aux->dato=aux2->dato;	//pone el 2do como primer num
				aux2->dato=temp;
			}
			aux=aux2; 
			aux2=aux2->sig;	
		}
	}
}

void ShakerSort(nodo*p){
		nodo *aux, *aux2;
		int total=0;
		int i, j;
		int temp;
		char comp;
		int caux=0;
		int caux2=0;
		aux=p;
		
		if(p==NULL){
			cout<<"Lista vacia,Favor de llenarlo\n";
		}
		else{		
		while(aux!=NULL){ 
			total++;		//cuenta el total de nodos
			aux2=aux;
			caux2=caux;
			aux=aux->sig;	//enlaza al otro nodo
			caux++;			//incrementa su valor=nodos
		}					//como se recorrio, ahora aux, se encuentra en F
		
			aux = aux2;		//aux=aux2=f
			caux=caux-1;
			aux2= aux2->ant;	//compara con el de la iz
			caux2--;
			
			for(i=1;i<total;i++){	
			
				cout<<"\nPasada "<<i<<"\n";
				cout<<"derecha a izquierda:\n";
				
				for(j=0;j<total-1;j++){
					if( aux->dato < aux2->dato ){		
						cout<<"\n";
						comp='V';	
						cout<<aux->dato<<" < "<<aux2->dato<<"["<<comp<<"]	";
						temp=aux2->dato;	
						aux2->dato=aux->dato;
						aux->dato=temp;		//termina de cambiar posiciones
						
						ImprimirIzqDer(p);
						cout<<"\n";
						aux=aux2;
						caux=caux-1; //disminuye
						aux2=aux2->ant;
						caux2=caux2-1;
					}
					else{	
					cout<<"\n";
						comp='F';
					cout<<aux->dato<<" < "<<aux2->dato<<"["<<comp<<"]	";
					ImprimirIzqDer(p);
					
						aux=aux2;	//quedan en las misma posiciones k se encontraban
						caux=caux-1;
						aux2=aux2->ant;
						caux2=caux2-1;
					}
				}
			cout<<"\n";
			cout<<"Izquierda a derecha: \n\n";
			
				aux2=p;
				caux2=0;
				aux=aux2->sig;
				caux=caux2+1;
				
				for(j=1;j<total-1;j++){
					if( aux2->dato > aux->dato ){
						cout<<"\n";
						comp='V';
						cout<<aux2->dato<<" > "<<aux->dato<<"["<<comp<<"]	";
						temp=aux->dato;
						aux->dato=aux2->dato;
						aux2->dato=temp;
					ImprimirIzqDer(p);
					cout<<"\n";
						aux2=aux2->sig;
						aux=aux->sig;
						
						
					}
	
					else{
					cout<<"\n";
					comp='F';
					cout<<aux2->dato<<" > "<<aux->dato<<"["<<comp<<"]	";
					ImprimirIzqDer(p);
						aux2=aux2->sig;
						aux=aux->sig;	
						
					}
				}
			}		
	}
}


nodo *seleDirecta(nodo *p,int total){ //seleccion directa
	nodo*aux,*aux2,*aux3,*aux4;
	int menor=0;
	if(p==NULL)
	{
		cout<<"Lista vacia,Favor de llenarlo\n";
	}
	else
	{	
		total=0;
		aux=p;
		while(aux!=NULL)
		{
			total++;
			aux=aux->sig;
		}
        aux=p;
		for (int i=1;i<total;i++)
        {
            cout << "\nPasada " <<i;
            aux2=aux->sig;
            menor=aux->dato;
            cout << "\nDato: ["<<menor<<"]";
            while (aux2!=NULL){
                if(menor>aux2->dato)
                {
                    aux3=aux2;
                    menor=aux2->dato;
                }
                aux2=aux2->sig;
            }
            	cout << "\tMenor: ["<<menor<<"]\n\n";
                aux3->dato=aux->dato;
                aux->dato=menor;
                aux4=p;
                while (aux4!=NULL)
            {
                cout <<" "<< aux4->dato << " ";
                aux4=aux4->sig;
            }
            
            aux=aux->sig;
        }	
	}
	return p;
}

void InsercionBinaria(nodo *p){

	nodo*aux,*aux2,*aux3,*aux4;
	int total;
	int con=0,ultcon=0;
	
    if(p==NULL){
        cout << "Lista vacia";
    }
        else{
            total=0;
            aux=p;
            while (aux!=NULL){
            		total++;
                    aux=aux->sig;
            }
                
                aux=p;
                
                for (int i=1;i<total;i++){
                	
                    cout << "\nPasada "<<i<<"\n";
                    
                    int pm=(i+1)/(2);
                    
					cout<<"\t  Pm="<<i+1<<"/2="<<pm<<"\n\n";
                    
                    aux2=aux->sig;
                    aux3=aux2;
                   	con=0;	
                    while((aux!=NULL)&&(con==0))
                    {
                        if (aux2->dato < aux->dato)
                        {
                            cout << aux2->dato << " < " << aux->dato;
                            cout << "\t[V]\t";                      
                            int temp=aux->dato;
                            aux->dato=aux2->dato;
                            aux2->dato=temp;
                            
                            	if(aux==p)
                           {							
								aux4=p;
                           		while (aux4!=NULL)
                            {
                                cout<<"["<< aux4->dato<<"]";
                                aux4=aux4->sig;
                            }
            
            	        	}
            	        	 cout << "\n";
                        }
                        else
                        {
                        
                            cout << aux2->dato << " < " << aux->dato;
                            cout << "\t[F]\t";
                            
                            
                            aux4=p;
                            while (aux4!=NULL)
                            {
                                cout<<"["<< aux4->dato<<"]";
                                aux4=aux4->sig;
                            }
                            cout << "\n";
                           	con=+1;
                        }
                        aux2=aux2->ant;
                        aux=aux->ant;
                    }
                    aux=aux3;
                }
		}		
}

void insercionDirecta(nodo *p)//DOCE
{
	nodo*aux,*aux2,*aux3,*aux4;
	int total;
	int con=0 ;
    if (p==NULL)
            {
                cout << "Lista vacia";
            }
            else
            {
                total=0;
                aux=p;
                while (aux!=NULL)
                {
                    total++;
                    aux=aux->sig;
                }
                aux=p;
                for (int i=1;i<total;i++)
                {
                    cout << "\nPasada Numero "<<i<<"\n";
                    aux2=aux->sig;
                    aux3=aux2;
                	con=0;	
                    while((aux!=NULL)&&(con==0))
                    {
                        if (aux2->dato < aux->dato)
                        {
                            cout << aux2->dato << " < " << aux->dato;
                            cout << "\t[V]\t";
                            int temp=aux->dato;
                            aux->dato=aux2->dato;
                            aux2->dato=temp;
                            aux4=p;
                            while (aux4!=NULL)
                            {
                                cout<<"["<< aux4->dato<<"]";
                                aux4=aux4->sig;
                            }
                            cout << "\n";
                        }
                        else
                        {
                        
                            cout << aux2->dato << " < " << aux->dato;
                            cout << "\t[F]\t";
                            
                            
                            aux4=p;
                            while (aux4!=NULL)
                            {
                                cout<<"["<< aux4->dato<<"]";
                                aux4=aux4->sig;
                            }
                            cout << "\n";
                           	con=+1;
                        }
                        aux2=aux2->ant;
                        aux=aux->ant;
                    }
                    aux=aux3;
            	}
    }
}


