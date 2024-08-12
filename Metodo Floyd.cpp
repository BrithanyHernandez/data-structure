#include <iostream>
#define INF 1e9
using namespace std;

int main() {
    int distance[100][100] , adj[100][100] , n;
	char adj2[100][100] , a , b;
	int opcion , opcion2;
	
	for (int c = 0; c < 100; c++) {
		for (int d = 0; d < 100; d++) {
			distance[c][d] = INF;
		}
	}
	
	do{
	cout << "Ingresa el tamanio de la matriz: ";
	cin >> n;
	cout << "\n";
	
	//Ciclo donde pregunta las distancias
	for (int c = 0 ; c < n ; c++){
		for ( int d = 0 ; d < n ; d++){
			cout << "Distancia de " << char(c + 'A') << " hacia " << char(d + 'A') << ": ";
			cin >> adj[c][d];
			if (adj[c][d] == -1){
			    adj[c][d] = INF;
			}
		}
	}
	cout << "\n";
	system("pause");
	system("cls");
	
	//Imprime la matriz de las distancias
	cout << "Matriz de Distancias\n";
	for (int c = 0 ; c < n ; c++){
	    for (int d = 0 ; d < n ; d++){
	        if (adj[c][d] == INF){
	            cout << "*  ";
	            continue;
	        }
	        cout << adj[c][d] << "  ";
	    }
	    cout << "\n";
	}
	cout << "\n";
	
	//Imprime la matriz de las letras
	cout << "\nMatriz de Letras\n";
	for (int c = 0 ; c < n ; c++){ //renglones
	    for (int d = 0 ; d < n ; d++){ //columnas
	        if (adj[c][d] == 0){
	            adj2[c][d] = 0;
	        }
	        else {
	            adj2[c][d] = (char(d + 'A'));
	        }
	        cout << ((!adj2[c][d]) ? '0' : adj2[c][d]) << "  ";
	    }
	    cout << '\n';
	}

	do{
    cout << "\nIngresa el nodo de inicio (letra): ";
    cin >> a;

    cout << "Ingresa el nodo final (letra): ";
    cin >> b;

    // Inicializa la matriz de 'distancias' con las distancias proporcionadas por el usuario
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        if (i == j) {
	            distance[i][j] = 0;
	        } else {
	            distance[i][j] = adj[i][j];
	        }
	    }
	}
	
	// Algoritmo de Floyd
	for (int k = 0; k < n; k++) {
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            if (distance[i][k] + distance[k][j] < distance[i][j]) {
	                distance[i][j] = distance[i][k] + distance[k][j];
	
	                // Actualiza la matriz de letras con los cambios realizados
	                adj2[i][j] = (char)(k + 'A');
	            }
	        }
	    }
	}

	
	//Imprime la matriz de distancias más cortas después de aplicar Floyd
    cout << "\nMatriz de Distancias mas cortas\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distance[i][j] == INF) {
                cout << "*  ";
            } else {
                cout << distance[i][j] << "  ";
            }
        }
        cout << "\n";
    }
    
    //Imprime la matriz de letras modificadas después de aplicar Floyd
	cout << "\nMatriz de Letras Modificadas\n";
	for (int c = 0; c < n; c++) {
	    for (int d = 0; d < n; d++) {
	        cout << ((!adj2[c][d]) ? '0' : adj2[c][d]) << "  ";
	    }
	    cout << '\n';
	}
    
    //Muestra el camino más corto entre los nodos seleccionados por el usuario
    cout << "\nEl camino mas corto entre " << a << " y " << b << " es: ";
    if (distance[a-'A'][b-'A'] == INF) {
        cout << "No hay camino.";
    } 
	else {
        cout << distance[a-'A'][b-'A'];
    }
    
    cout << "\n\nDeseas buscar otro camino (1.Si/2.No)? ";
    cin >> opcion;
    
	}while(opcion != 2);
	
	cout << "\nDeseas ingresar otra matriz? (1.Si/2.No)? ";
	cin >> opcion2;
	cout << "\n";
	system("pause");
	system("cls");
	
	}while(opcion2 != 2);
    
}