#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;

ABB crearNodo(int x){
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

void insertar(ABB &arbol, int x, bool esRaiz = true){
    if(arbol==NULL){
    	arbol = crearNodo(x);
    }
    else if(x<arbol->nro)
        insertar(arbol->izq, x, false);
        
    else if(x > arbol->nro)
        insertar(arbol->der, x, false);

    if (esRaiz){
        // Si es la raiz, asegurate de que el nodo raiz sea el primer valor ingresado
        while (arbol->izq != NULL)
            arbol = arbol->izq;
    }
}

void preOrden(ABB arbol){
    if(arbol!=NULL){
        cout << arbol->nro <<" ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void enOrden(ABB arbol){
    if(arbol!=NULL){
        enOrden(arbol->izq);
        cout << arbol->nro << " ";
        enOrden(arbol->der);
    }
}

void postOrden(ABB arbol){
    if(arbol!=NULL){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}

void verArbol(ABB arbol, int espacio){
    // Caso base
    if (arbol == NULL)
        return;

    // Aumenta el espacio entre niveles
    espacio += 5;

    // Procesa el subArbol derecho primero
    verArbol(arbol->der, espacio);

    // Imprime el nodo actual despues de dejar suficiente espacio
    // para el subArbol derecho
    cout << endl;
    
    for (int i = 5; i < espacio; i++)
        cout << " ";
    cout << arbol->nro << "\n";

    // Procesa el subArbol izquierdo
    verArbol(arbol->izq, espacio);
}

void buscarNodo(ABB arbol, int numero_Buscar) {
	
    if (arbol == NULL) {
        cout << "El arbol esta vacio" << endl;
        return;
    }

    if (arbol->nro == numero_Buscar){
    	
        cout<<"El nodo "<< numero_Buscar<< " es la raiz principal" << endl;
        
    }else{
    	
        ABB temp=arbol;

        while (temp!= NULL) {
        	
            if(numero_Buscar < temp->nro){
            	
                if(temp->izq!= NULL&& temp->izq->nro == numero_Buscar) {
                	
                    cout << "El numero "<<numero_Buscar<< " esta en la raiz izquierda de " << temp->nro <<endl;
                  	return;
                }
                temp = temp->izq;	//recorre
                
            }else if( numero_Buscar>temp->nro){
            	
                if(temp->der != NULL && temp->der->nro == numero_Buscar){
                	
                    cout << "El numero " << numero_Buscar<< " esta en la raiz derecha de " << temp->nro <<endl;
                	return;
                }
                
                temp = temp->der;	//recorre ala derecha
                
            }else {
                
                cout << "El numero " << numero_Buscar<< " no se encuentra en la raiz izquierda ni derecha" << endl;
				return;
            }
        }
        cout << "El numero " << numero_Buscar << " no existe en el arbol" << endl;
        		
    }
}


int main(){
    ABB arbol = NULL;   // creado Arbol

    int n; // numero de nodos del arbol
    int x; // valor a insertar en cada nodo
	int sum=0;
	int opc_Buscar, numero_Buscar;
	
    cout << "\nARBOL BINARIO DE BUSQUEDA\n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

   for(int i=0; i<n; i++){
		cout << " Numero del nodo " << i+1 << ": ";
		cin >> x;
		sum+=x;
		
		insertar( arbol, x, i == 0);
	}
	
    cout << "\n Mostrando Arbol \n\n";
	verArbol(arbol, 0);

    cout << "\n Recorridos del Arbol";

    cout << "\n\n In orden   :  ";   enOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);
    
    cout<<"\n\nLa sumatoria de los nodos es: "<<sum;
    
    do {
    	
        cout << "\nIngrese el numero a buscar: ";
        cin >> numero_Buscar;
        
        buscarNodo(arbol, numero_Buscar);

        cout << "\n Desea buscar otro nodo? (1: Si, 0: No): ";
        cin>>opc_Buscar;
        
    } while (opc_Buscar == 1);
    

    cout << endl << endl;

    system("pause");
    return 0;
}
