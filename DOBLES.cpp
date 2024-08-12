#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
    int dato;
    nodo *sig, *ant; 
};

void imprimirPaF(nodo *);
void imprimirFaP(nodo *);
nodo* insertarDer(nodo *, nodo *);
nodo* insertarIzq(nodo *, nodo *);
nodo* insertaralefin(nodo *, int);
nodo* insertaraleini(nodo *, int);
nodo* insertarEntreXY(nodo *, int, int);
nodo* Buscar(nodo *, int);
nodo* Modificar(nodo *, int,int);
nodo* insertarAleAntesRef(nodo *, int, int);
nodo* insertarAleDesRef(nodo *, int, int);

int main(){
    nodo *p = NULL, *f = NULL;
    int opc;
    while(1){

        cout << "\nMenu\n"; 
        cout << "0. Imprimir de P a F\n";
        cout << "1.Imprimir de F a P\n";
        cout << "2. Insertar a la derecha\n";
        cout << "3. Insertar a la izquierda\n";
        cout << "4. Aleatorios al final\n";
        cout << "5. Aleatorios al inicio\n";
        cout << "6. Insertar aleatorios entre X y Y\n";
        cout << "7. Buscar\n";
        cout << "8. Modificar\n";
        cout << "9. Insertar aleatorios antes de la referencia\n";
        cout << "10. Insertar aleatorios despues de la referencia\n";
        cout << "Selecciona una opcion: ";
        cin >> opc;
        
        switch(opc){
        	
            case 0: // Impresión de p a f
                if(p == NULL)
                    cout << "Lista vacia\n";
                else
                    imprimirPaF(p);
                break;
                
            case 1: // Impresión de f a p
                if(f == NULL)
                    cout << "Lista vacia\n";
                else
                    imprimirFaP(f);
                break;
                
            case 2: // Insertar a la derecha
                if(p == NULL)
                {
                    p = new(nodo);
                    cout << "Ingresa el dato: ";
                    cin >> p->dato;
                    p->sig = NULL;
                    p->ant = NULL;
                    f = p;
                }
                else
                    f = insertarDer(f, p);
                break;
                
            case 3: // Insertar a la izquierda
                if(p == NULL)
                {
                    p = new(nodo);
                    cout << "Ingresa el dato: ";
                    cin >> p->dato;
                    p->sig = NULL;
                    p->ant = NULL;
                    f = p;
                }
                else
                    p = insertarIzq(p, f);
                break;

            case 4:
                int n;
                cout << "Cuantos datos aleatorios desea:";
                cin >> n;
                
                if(p == NULL){
                    p = new(nodo);
                    p->dato = 1 + rand() % 100;
                    cout << endl;
                    p->sig = NULL;
                    p->ant = NULL;
                    f = p;
                    f = insertaralefin(f, n);
                }
                else
                    f = insertaralefin(f, n+1);
                break;

            case 5:
                cout << "Cuantos datos aleatorios desea:";
                cin >> n;
                if(p == NULL){
                    p = new(nodo);
                    p->dato = 1 + rand() % 100;
                    cout << endl;
                    p->sig = NULL;
                    p->ant = NULL;
                    f = p;
                    p = insertaraleini(p, n);
                }
                else
                    p = insertaraleini(p, n + 1);
                break;
                
            case 6:
                int x, y;
                cout<<"Ingresa el valor de x: ";
                cin>>x;
                cout<<"Ingresa el valor de y: ";
                cin>>y;
                p=insertarEntreXY(p, x, y);
                break;
                
            case 7: 
			    int valorB;
				cout<<"Ingresa el valor que deseas buscar: ";
				cin>>valorB;
				p=Buscar(p, valorB);
				break;
				
			case 8:
			    int nuevoVa;
				cout<<"Ingresa el valor que desee modificar: ";
				cin>>valorB;
				
				cout<<"Ingresa el nuevo valor: ";
				cin>>nuevoVa;	
				p=Modificar(p,valorB,nuevoVa);
				break;
				
			case 9:
				int r;
				cout << "Ingresa el valor de la referencia: ";
				cin>>r;
				cout<<"Ingresa la cantidad de valores aleatorios a insertar: ";
				cin>>n;
				p =insertarAleAntesRef(p,r, n);
				break;
					
			case 10:
				cout << "Ingresa el valor de la referencia: ";
				cin >> r;
				cout << "Ingresa la cantidad de valores aleatorios a insertar: ";
				cin >> n;
				p =insertarAleDesRef(p,r, n);
				break;		
        }
       //system("pause");
       //system("cls");
    }
}

void imprimirPaF(nodo *p){
	
    nodo *aux;
    aux = p;
    while(aux != NULL){
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << "\n";
}

void imprimirFaP(nodo *f){
    nodo *aux;
    aux = f;
    while(aux != NULL){
        cout << aux->dato << " ";
        aux = aux->ant;
    }
    cout << "\n";
}

nodo* insertarDer(nodo *f, nodo *p){
    nodo *aux;
    aux = new(nodo);
    cout << "Ingresa el dato: ";
    cin >> aux->dato;
    aux->ant = f;
    aux->sig = NULL;
    f->sig = aux;
    f = aux;
    return f;
}

nodo* insertarIzq(nodo *p, nodo *f){
    nodo *aux;
    aux = new(nodo);
    cout << "Ingresa el dato: ";
    cin >> aux->dato;
    aux->sig = p;
    aux->ant = NULL;
    p->ant = aux;
    p = aux;
    return p;
}

nodo* insertaralefin(nodo *f, int N){
    nodo *aux;
    for(int i = 2; i <= N; i++){
        aux = new(nodo);
        aux->dato = 1 + rand() % 100;
        aux->ant = f;
        aux->sig = NULL;
        f->sig = aux;
        f = aux;
    }
    return f;
}

nodo* insertaraleini(nodo *p, int N){
    nodo *aux;
    for(int i = 2; i <= N; i++){
        aux = new(nodo);
        aux->dato = 1 + rand() % 100;
        aux->sig = p;
        aux->ant = NULL;
        p->ant = aux;
        p = aux;
    }
    return p;
}
nodo* insertarEntreXY(nodo *p, int x, int y){
    nodo *aux, *nuevo;
    aux = p;
    int canVal;
    bool xEncontrado = false;
    while (aux != NULL){
        if (aux->dato == x){
            xEncontrado = true;
            break;
        }
        aux = aux->sig;
    }

    if(xEncontrado && aux->sig!=NULL && aux->sig->dato == y){

        cout<<"Inserta la cantidad de valores: ";
        cin>>canVal;
        
        for(int i=0; i<canVal; i++){
        	nuevo = new(nodo);
        	nuevo->dato = 1 + rand() % 100;
	        nuevo->sig = aux->sig;
    	    nuevo->ant = aux;
    	    
        	if (aux->sig != NULL){
            aux->sig->ant = nuevo;
       		}
        aux->sig = nuevo;
		}
        
    }
    else{
        cout << "Los valores X e Y no se encuentran juntos en la lista." << endl;
    }
    return p;
}

nodo* Buscar(nodo *p, int valorB){
    nodo *aux = p;
    bool encontrado = false;
    while (aux != NULL){
        if (aux->dato == valorB){
            encontrado = true;
        }
        aux = aux->sig;
    }
    if (encontrado){
        cout << "El dato " << valorB<< " ha sido encontrado en la lista." << endl;
    }
    else{
        cout << "El dato " << valorB << " no se encuentra en la lista." << endl;
    }
    return p;
}

nodo* Modificar(nodo *p,int valorB, int nuevoVa){
    nodo *aux = p;
     bool encontrado = false;
	while (aux != NULL){
        if (aux->dato == valorB){
        	
            encontrado = true;
            aux->dato= nuevoVa;
            cout << "Valor modificado exitosamente." << endl;
            return p;
        }
		aux = aux->sig;
    }
    if (encontrado){
        cout <<"Valor no encontrado en la lista." << endl;	
    }
}

nodo* insertarAleAntesRef(nodo *p, int r, int n){
    nodo *aux = p;
    nodo *anterior = NULL;
    int contador = 0;
    while (aux != NULL){
        if (aux->dato == r){
            for (int i = 0; i < n; i++){
                nodo *nuevo = new(nodo);
                nuevo->dato = 1 + rand() % 100;
                nuevo->ant = anterior;
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
        cout << "Se insertaron " << n << " valores aleatorios antes de la referencia." << endl;
    }

    return p;
}

nodo* insertarAleDesRef(nodo *p, int r, int n){
    nodo *aux = p;
    int contador = 0;
    while (aux != NULL){
        if (aux->dato == r){
            for (int i = 0; i < n; i++){
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
        cout << "Se insertaron " << n << " valores aleatorios despues de la referencia." << endl;
    }
    return p;
}	
