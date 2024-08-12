#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>

using namespace std;

struct nodo {
  int dato;
  nodo *sig;
  nodo *ant;
};

nodo *p = NULL;
nodo *f = NULL;

void Imprimir() {
	nodo *aux = p;
	
	cout << "\n\tContenido de la Lista\n";
	while (aux != NULL) {
    	cout << aux->dato << "  ";
    	aux = aux->sig;
 	}
  cout << "\n\n";
}

void ImprimirPaF() {
	nodo *aux = p;
  
  	if(aux == NULL){
  		cout << "\nLista vacia\n\n";
  	}
  
  	else{
  		cout << "\n\tContenido de la Lista\n";
  		while (aux != NULL) {
    		cout << aux->dato << "  ";
    		aux = aux->sig;
  		}
  		cout << "\n\n";
  	}
}

void ImprimirFaP() {
	nodo *aux = f;
  
  	if(aux == NULL){
  		cout<<"\nLista vacia\n\n";
  	}
  
 	else{
  		cout << "\n\tContenido de la Lista\n";
  		while (aux != NULL) {
    	cout << aux->dato << "  ";
    	aux = aux->ant;
  		}
  		cout << "\n\n";
  	}
}

void InsertarDer(int valor) {
	nodo *aux = new (nodo);
  	aux->dato = valor;
  	aux->sig = NULL;
  	aux->ant = f;
  	
	if (f != NULL)
    	f->sig = aux;
  		f = aux;
  		
  	if (p == NULL)
    	p = aux;
}

void InsertarIzq(int valor) {
	nodo *aux = new (nodo);
  	aux->dato = valor;
 	aux->sig = p;
 	aux->ant = NULL;
  
  	if (p != NULL)
    	p->ant = aux;
 		p = aux;
 		
  	if (f == NULL)
    	f = aux;
}

void AleatoriosDerecha(int n) {
	srand(time(NULL));
	
  	for (int i=0 ; i<n ; i++)
    	InsertarDer(rand()%100);
}

void AleatoriosIzquierda(int n) {
 	srand(time(NULL));
 	
   	for (int i=0 ; i<n ; i++)
    	InsertarIzq(rand()%100);
}

void AgregarValoresEntreXyY(int x, int y, int val){
	int Contx=0 ,Conty=0;
	int Valor;
	nodo *Valx = p;
	nodo *Valy = p;
	
	while (Valx != NULL){
		if(Valx->dato == x){
			break;
		}
		Contx++;
		Valx = Valx->sig;
	}
	
	while (Valy != NULL){
		if(Valy->dato == y){
			break;
		}
		Conty++;
		Valy = Valy->sig;
	}
	
	if(Conty - Contx == 1){
		cout << "Ingresa la cantidad: ";
		cin >> Valor;
		
		srand(time(NULL));
        for(int i=0 ; i<Valor ; i++){
        	val = 1+rand()%100;
        
        	nodo *newNode = new (nodo);
        	newNode->dato = val;
        
        	newNode->sig = Valx->sig;
        	newNode->ant = Valx;
        
        	if (Valx->sig != NULL){
            	Valx->sig->ant = newNode;
        	} 
        
        	else{
            	f = newNode;
    		}
        
        	Valx->sig = newNode;
        }
        cout << "\n";
        Imprimir();
	}
	
	else{
		cout << "Error de parametros\n\n";
	}
}

nodo *Buscar(int valor){
	nodo *aux = p;
	
	while(aux != NULL){
		if(aux->dato == valor){
			break;
		}
		aux = aux->sig;
	}
	return aux;
}

void Modificar(int val , int valor){
	nodo *aux = Buscar(valor);
	
	if(aux != NULL){
		cout << "\nIngrese el valor: ";
    	cin >> val;
		aux->dato = val;
		cout << "\n";
		Imprimir();
	}
	
	else if(aux == NULL){
		cout << "\nNo se puede realizar la operacion\n\n";
	}
}

void AgregarAntesDeReferencia(int x , int valor , int val){
    nodo *current = p;
    
    while (current != NULL && current->dato != x) {
        current = current->sig;
    }
            
    if (current == NULL) {
        cout << "\nEl valor no existe\n\n";
        return;
    } 
            
    else if (current != NULL){   
        cout << "\nIngrese la cantidad de valores: ";
        cin >> valor;
        
        srand(time(NULL));
        for(int i=0 ; i<valor ; i++){
        	val = 1+rand()%100;
        
        	nodo *newNode = new (nodo);
	    	newNode->dato = val;
 	    
        	newNode->ant = current->ant;
        	newNode->sig = current;
                
            if (current->ant != NULL) {
                current->ant->sig = newNode;
            } 
                
            else {
                p = newNode;
            }
            current->ant = newNode;
        }
        cout << "\n";
        Imprimir();
    }
}

void AgregarDespuesDeReferencia(int x , int valor , int val){
    nodo *current = p;
        
    while (current != NULL && current->dato != x) {
        current = current->sig;
    }
        
    if (current == NULL) {
        cout << "\nEl valor no existe\n" << endl;
        return;
    }
        
    else if (current != NULL){
       	cout << "\nIngrese la cantidad de valores: ";
        cin >> valor;
        
        srand(time(NULL));
        for(int i=0 ; i<valor ; i++){
        	val = 1+rand()%100;
        
        	nodo *newNode = new (nodo);
        	newNode->dato = val;
        
        	newNode->sig = current->sig;
        	newNode->ant = current;
        
        	if (current->sig != NULL){
            	current->sig->ant = newNode;
        	} 
        
        	else{
            	f = newNode;
        	}
        
        	current->sig = newNode;
        }
        cout << "\n";
        Imprimir();
    }
}

void EliminarPrimerNodo() {
    nodo *aux;

    if (p == NULL) {
        cout << "\nLista vacia\n\n";
    } else {
        aux = p;
        if (aux->sig == NULL && aux->ant == NULL) {
            delete (aux);
            p = NULL;
        } else {
            p = aux->sig;
            aux->sig = NULL;
            p->ant = NULL;
            delete (aux);
        }
        Imprimir();
    }
}

void EliminarUltimoNodo() {
    nodo *aux;

    if (p == NULL) {
        cout << "\nLista vacia\n\n";
    } else {
        aux = f;
        if (aux->sig == NULL && aux->ant == NULL) {
            delete (aux);
            p = NULL;
        } else {
            f = aux->ant;
            aux->ant = NULL;
            f->sig = NULL;
            delete (aux);
        }
        Imprimir();
    }
}

void EliminarValoresEntreXY(int x, int y) {
    nodo *aux = p;
    nodo *aux1 = NULL;
    nodo *aux2 = NULL;

    if (aux == NULL) {
        cout << "\nLista vacia\n\n";
    } 
	else {
        while (aux != NULL) {
            if (aux->dato == x) {
                aux1 = aux;
            } else if (aux1 != NULL && aux->dato == y) {
                aux2 = aux;
                break;
            }
            aux = aux->sig;
        }

        if (aux1 != NULL && aux2 != NULL) {
            aux = aux1->sig;
            aux1->sig = aux2;

            while (aux != aux2) {
                nodo *siguiente = aux->sig;
                delete aux;
                aux = siguiente;
            }
            Imprimir();
        } else {
            cout << "\nEsos valores no existen\n\n";
        }
    }
}

bool Primo(int num) {
    if (num < 2) {
        return false;
    }
    for (int i=2 ; i*i<=num ; i++) {
        if (num%i == 0) {
            return false;
        }
    }
    return true;
}
void EliminarPrimos() {
    nodo *aux = p;
    
    if (aux == NULL) {
        cout << "\nLista vacia\n\n";
    }
    
    while (aux != NULL) {
        if (Primo(aux->dato)) {
            nodo *Eliminar = aux;
            if (aux == p) {
                p = aux->sig;
                if (p != NULL) {
                    p->ant = NULL;
                }
            } 
			else if (aux == f) {
                f = aux->ant;
                if (f != NULL) {
                    f->sig = NULL;
                }
            } 
			else {
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
            }
            aux = aux->sig;
            delete(Eliminar);
        } 
		else {
            aux = aux->sig;
        }
    }
    Imprimir();
}

void EliminarValoresDespuesDeReferencia(int x, int n) {
    nodo *aux = p;
    nodo *aux1 = NULL;

    // Busca la referencia
    while (aux != NULL) {
        if (aux->dato == x) {
            aux1 = aux;
            break;
        }
        aux = aux->sig;
    }

    if (aux1 != NULL) {
        aux = aux1->sig;

        // Comprobar si la referencia es el último nodo
        if (aux != NULL) {
            // Elimina los nodos
            for (int i = 0; i < n && aux != NULL ; i++) {
                nodo *siguiente = aux->sig;
                if (siguiente != NULL) {
                    siguiente->ant = aux1;
                }
                aux1->sig = siguiente;
                delete aux;
                aux = siguiente;
            }
            Imprimir();
        } 
		else {
            cout << "No hay mas valores despues de la referencia\n\n";
            Imprimir();
        }
    } 
    else {
        cout << "Referencia no encontrada en la lista";
    }
}


int main() {
	int opcion , valor , x , y , n , val;
	
  	while (true) {
  		cout << "\tMENU LISTAS DOBLES\n\n";
    	cout << "1. Imprimir del Primero al Ultimo\n";
		cout << "2. Imprimir del Ultimo al Primero\n";
    	cout << "3. Insertar a la derecha\n";
    	cout << "4. Insertar a la izquierda\n";
    	cout << "5. Insertar numeros aleatorios al final\n";
    	cout << "6. Insertar numeros aleatorios al principio\n";
    	cout << "7. Ingresar aleatorios entre x - y\n";
    	cout << "8. Buscar\n";
    	cout << "9. Modificar\n";
    	cout << "10. Insertar numeros aletorios antes de referencia\n";
    	cout << "11. Insertar numeros aleatorios despues de referencia\n";
    	cout << "12. Eliminar primer nodo\n";
        cout << "13. Eliminar ultimo nodo\n";
        cout << "14. Eliminar entre x - y\n";
        cout << "15. Eliminar primos\n";
        cout << "16. Eliminar N numeros despues de la referencia\n";
    	//cout << "-1. Salir\n";
    	cout << "\nSelecciona la opcion: ";
    	cin >> opcion;
    	
    	switch (opcion) {
      		case 1:
    			ImprimirPaF();
      		break;
        
      		case 2:
      			ImprimirFaP();
      		break;
        
      		case 3:
        		cout << "\nIntroduzca el valor: ";
        		cin >> valor;
        		cout << "\n";
        		InsertarDer(valor);
        	break;
        
      		case 4:
        		cout << "\nIntroduzca el valor: ";
        		cin >> valor;
        		cout << "\n";
        		InsertarIzq(valor);
        	break;
        
        	case 5:
        		cout << "\nCuantos valores desea: ";
        		cin >> n;
        		cout << "\n";
        		AleatoriosDerecha(n);
        	break;
        
        	case 6:
        		cout << "\nCuantos valores desea: ";
        		cin >> n;
        		cout << "\n";
        		AleatoriosIzquierda(n);
        	break;
        
        	case 7:
        		Imprimir();
        		cout << "Ingresa x: ";
        		cin >> x;
        		cout << "\nIngrese y: ";
        		cin >> y;
        		cout << "\n";
        		AgregarValoresEntreXyY(x , y , val);
        	break;
        
        	case 8:
        		cout << "\nIngrese el valor a buscar: ";
        		cin >> valor;
        		
        		if (Buscar(valor) != NULL){
        			cout << "\nValor encontrado\n\n";
        		}
        
        		else{
        			cout << "\nValor no encontrado\n\n";
        		}
        	break;
        
        	case 9:
        		Modificar(val,valor);
        	break;
        
        	case 10:
        		Imprimir();
        		cout << "Ingrese la referencia: ";
        		cin >> x;
        		AgregarAntesDeReferencia(x , valor , val);
        	break;
        
        	case 11:
        		Imprimir();
       			cout << "Ingrese la referencia: ";
        		cin >> x;
        		AgregarDespuesDeReferencia(x , valor , val);
        	break;      
        	
        	case 12:
                EliminarPrimerNodo();
            break;

            case 13:
                EliminarUltimoNodo();
            break;

            case 14:
                Imprimir();
                cout << "Ingresa x: ";
                cin >> x;
                cout << "\nIngrese y: ";
                cin >> y;
                cout << "\n";
                EliminarValoresEntreXY(x, y);
            break;

            case 15:
                EliminarPrimos();
            break;
                
            case 16:
            	Imprimir();
        		cout << "Ingresa la referencia: ";
        		cin >> x;
        		cout << "\nIngresa cuantos valores desea eliminar despues de la referencia: ";
       			cin >> n;
        		cout << "\n";
        		EliminarValoresDespuesDeReferencia(x , n);
        	break;
        	
        	case -1:
        		exit(0);
        	break;
    	}
    	system("pause");
    	system("cls");
	}
}