#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
    int valor;
    int altura;
    Nodo* izq;
    Nodo* der;
};

int maximo(int a, int b) {
    return (a > b) ? a : b;	//a>b retorna a 
}

int obtenerAltura(Nodo* nodo){ //longitud del nodo hasta una de sus hojas mas distantes

    if (nodo == NULL){	//si el nodo es nulo
        return 0;
    }
    return nodo->altura;
}

int obtenerFactorEquilibrio(Nodo* nodo){ //altura del subárbolIzquierdo-altura del subárbol derecho
	
    if (nodo == NULL) {
        return 0;
    }
    return obtenerAltura(nodo->izq) - obtenerAltura(nodo->der);
}

Nodo* rotacionDerecha(Nodo* y){ //toma al nodo Y,representa el nodo desequilibrado
	
    Nodo* x = y->izq;	//X apunta al hijo izquierdo de y,X se convierte en el nuevo nodo raíz del subarbol
    Nodo* T2 = x->der;	//apunta al subarbol derecho del nodo X

    x->der = y;	// rotación hacia la derecha. 
    y->izq = T2;	

    y->altura = maximo(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    x->altura = maximo(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;

    return x;
}

Nodo* rotacionIzquierda(Nodo* x) {
	
    Nodo* y = x->der;	//rotación ala izquierda, y es el nuevo nodo raíz del subarbol
    Nodo* T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = maximo(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    y->altura = maximo(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;

    return y;
}

Nodo* insertarNodo(Nodo* nodo, int valor) {
    if (nodo == NULL) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->valor = valor;
        nuevoNodo->altura = 1;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        return nuevoNodo;
    }

    if (valor < nodo->valor){	// valor es menor,se coloca en el subárbol izquierdo 
        nodo->izq = insertarNodo(nodo->izq, valor);
    } else if (valor > nodo->valor) {
        nodo->der = insertarNodo(nodo->der, valor);
    } else {
        // El valor ya existe en el árbol
        return nodo;
    }

    nodo->altura = 1 + maximo(obtenerAltura(nodo->izq), obtenerAltura(nodo->der));

    int factorEquilibrio = obtenerFactorEquilibrio(nodo);

    // Caso de rotación izquierda-izquierda
    if (factorEquilibrio > 1 && valor < nodo->izq->valor) {
        cout << "Rotacion: LL (izquierda-izquierda)." << endl;
        return rotacionDerecha(nodo);
    }

    // Caso de rotación derecha-derecha
    if (factorEquilibrio < -1 && valor > nodo->der->valor) {
        cout << "Rotacion: RR (derecha-derecha)." << endl;
        return rotacionIzquierda(nodo);
    }

    // Caso de rotación izquierda-derecha
    if (factorEquilibrio > 1 && valor > nodo->izq->valor) {
        cout << "Rotacion: LR (izquierda-derecha)." << endl;
        nodo->izq = rotacionIzquierda(nodo->izq);
        return rotacionDerecha(nodo);
    }

    // Caso de rotación derecha-izquierda
    if (factorEquilibrio < -1 && valor < nodo->der->valor) {
        cout << "Rotacion: RL (derecha-izquierda)." << endl;
        nodo->der = rotacionDerecha(nodo->der);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

/*void preorden(Nodo* nodo) {
    if (nodo != nullptr) {
        cout << nodo->valor << " ";
        preorden(nodo->izq);
        preorden(nodo->der);
    }
} */

void imprimirArbol(Nodo* raiz, int espacio) {
    if (raiz == NULL) {
        return;
    }

    espacio += 10;

    imprimirArbol(raiz->der, espacio);

    cout << endl;
    
    for (int i = 10; i < espacio; i++) {
        cout << " ";
    }
    cout << raiz->valor << " (FE: " << obtenerFactorEquilibrio(raiz) << ")" << endl;

    imprimirArbol(raiz->izq, espacio);
}

int main() {
    Nodo* raiz = NULL;

    int opc, n;
    while (true) {
        cout << "\n\n1.-Insertar\n";
        //cout << "2.-Pre-Orden\n";
        cout << "2.-Imprimir arbol\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingresa el valor a insertar: ";
                cin >> n;
                raiz = insertarNodo(raiz, n);
                cout << "Arbol AVL despues de insertar: ";
                //preorden(raiz);
                cout << endl;
                break;

            /*case 2:
                cout << "Recorrido Pre-Orden: ";
                preorden(raiz);
                cout << endl;
                break; */

            case 2:
                cout << "Arbol AVL:" << endl;
                imprimirArbol(raiz, 0);
                break;
        }
    }

    return 0;
}
