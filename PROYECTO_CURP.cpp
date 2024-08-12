#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip> //Para imprimir números con decimales establecidos

using namespace std;

struct nodo{
	string Nombre;
	string Paterno;
	string Materno;
	string Nacimiento;
	char Sexo;
	string EntidadS;
	string EntidadL;
	float Cal1=0, Cal2=0, Cal3=0, Promedio=0;
	string Curp;
	nodo *ant, *sig;
};


string GenCurp(string, string, string, string, char, string);
string EntidadS(int);
string EntidadL(int);
void GenPromedio(nodo *);
nodo* AgregarAlumno(nodo *);
void BuscarPorNombre(nodo *, string);
void BuscarPorApellido(nodo *, string);
void BuscarPorCurp(nodo *, string);
void MostrarAlumno(nodo *);
int IngresarCalificaciones(nodo *);
void EliminarAlumno(nodo *&, nodo *&, string);

void ImprimirEntidades();
void PromedioTotal(nodo*);
void OrdenarPorPromedio(nodo*);
void MostrarTodos(nodo* );



int main(){
	int i, opc, entidad;
	string nombre, paterno, materno, nacimiento, curp, entidadC, apellido;
	char k, sexo;
	nodo *p=NULL, *f=NULL, *aux, *aux2;
	
	do{
		system("cls");
		cout<<"\n\n\tBIENVENIDO!\n";
		cout<<"\n\t[1] Generar Curp.";
		cout<<"\n\t[2] Obtener promedio.";
		cout<<"\n\t[3] Buscar por nombre.";
		cout<<"\n\t[4] Buscar por apellido.";
		cout<<"\n\t[5] Buscar por curp.";
		cout<<"\n\t[6] Agregar alumno.";
		cout<<"\n\t[7] Eliminar alumno.";
		cout<<"\n\t[8] Ordenar por promedio.";
		cout<<"\n\t[9] Mostrar registrados.";
		cout<<"\n\n\tTu opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				system("cls");
				cout<<"Ingresa nombre: ";
				cin>>nombre;
				for (i = 0; i < nombre.length(); i++) {
			    	nombre[i] = toupper(nombre[i]);
			  	}
				system("cls");
				cout<<"Ingresa apellido paterno: ";
				cin>>paterno;
				for (i = 0; i < paterno.length(); i++) {
			    	paterno[i] = toupper(paterno[i]);
			  	}
				system("cls");
				cout<<"Ingresa apellido materno: ";
				cin>>materno;
				for (i = 0; i < materno.length(); i++) {
			    	materno[i] = toupper(materno[i]);
			  	}
				system("cls");
				cout<<"Ingresa tu fecha de nacimiento (AAAAMMDD): ";
				cin>>nacimiento;
				system("cls");
				cout<<"Ingresa tu sexo (H/M): ";
				cin>>sexo;
				
				while ((sexo != 'h') && (sexo != 'H') && (sexo != 'm') && (sexo != 'M')){
					cout<<"Ingresa tu una opcion valida (H/M): ";
					cin>>sexo;
				}
				sexo = toupper(sexo);
				
				system("cls");
				cout<<"Ingresa tu entidad federativa de nacimiento: \n";
				ImprimirEntidades();
				cout<<"Tu seleccion: ";
				cin>>entidad;
				
				while ((entidad <= 0) || (entidad >= 33)){
					cout<<"Ingresa tu una opcion valida (1-32): ";
					cin>>entidad;
				}
				
				entidadC = EntidadS(entidad);
				curp=GenCurp(nombre, paterno, materno, nacimiento, sexo, entidadC);
				system("cls");
				cout<<"Curp: "<<curp<<"\n\n";
				system("pause");
				break;
			case 2:
				if(p==NULL){
					cout<<"\nNo hay Alumnos registrados.\n\n";
					system("pause");
				}
				else{
					PromedioTotal(p);
					system("pause");
				};break;
			case 3:
				if(p==NULL){
					cout<<"\nNo hay Alumnos registrados.\n\n";
					system("pause");
				}
				else{
					cout<<"\nIngresa tu nombre: ";
					cin>>nombre;
					for (i = 0; i < nombre.length(); i++) {
				    	nombre[i] = toupper(nombre[i]);
				  	}
					BuscarPorNombre(p, nombre);
				};break;
			case 4:
				if(p==NULL){
					cout<<"\nNo hay Alumnos registrados.\n\n";
					system("pause");
				}
				else{
					cout<<"\nIngresa tu apellido: ";
					cin>>apellido;
					for (i = 0; i < apellido.length(); i++) {
				    	apellido[i] = toupper(apellido[i]);
				  	}
					BuscarPorApellido(p, apellido);
				};break;
			case 5:
				if(p==NULL){
					cout<<"\nNo hay Alumnos registrados.\n\n";
					system("pause");
				}
				else{
					cout<<"\nIngresa tu curp: ";
					cin>>curp;
					for (i = 0; i < curp.length(); i++) {
				    	curp[i] = toupper(curp[i]);
				  	}
					BuscarPorCurp(p, curp);
				};break;
			case 6:
				if(p==NULL){
					p=new(nodo);
					system("cls");
					cout<<"\nIngresa tu nombre: ";
					cin>>p->Nombre;
					for (i = 0; i < p->Nombre.length(); i++) {
				    	p->Nombre[i] = toupper(p->Nombre[i]);
				  	}
					system("cls");
					cout<<"Ingresa tu apellido paterno: ";
					cin>>p->Paterno;
					for (i = 0; i < p->Paterno.length(); i++) {
				    	p->Paterno[i] = toupper(p->Paterno[i]);
				  	}
					system("cls");
					cout<<"Ingresa tu apellido materno: ";
					cin>>p->Materno;
					for (i = 0; i < p->Materno.length(); i++) {
				    	p->Materno[i] = toupper(p->Materno[i]);
				  	}
					system("cls");
					cout<<"Ingresa tu fecha de nacimiento (AAAAMMDD): ";
					cin>>p->Nacimiento;
					system("cls");
					cout<<"Ingresa tu sexo (H/M): ";
					cin>>p->Sexo;
					
					while ((p->Sexo != 'h') && (p->Sexo != 'H') && (p->Sexo != 'm') && (p->Sexo != 'M')){
						cout<<"Ingresa tu una opcion valida (H/M): ";
						cin>>p->Sexo;
					}
					
					p->Sexo = toupper(p->Sexo);
					
					system("cls");
					cout<<"Ingresa tu entidad federativa de nacimiento: \n";
					ImprimirEntidades();
					cout<<"Tu seleccion: ";
					cin>>entidad;
					
					while ((entidad <= 0) || (entidad >= 33)){
						cout<<"Ingresa tu una opcion valida (1-32): ";
						cin>>entidad;
					}
					
					system("cls");
					cout<<"Ingresa tu calificacion 1: ";
					cin>>p->Cal1;
					while ((p->Cal1 < 0) || (p->Cal1 > 10)){
						cout<<"Ingresa tu una calificacion valida (1-10): ";
						cin>>p->Cal1;
					}
					cout<<"Ingresa tu calificacion 2: ";
					cin>>p->Cal2;
					while ((p->Cal2 < 0) || (p->Cal2 > 10)){
						cout<<"Ingresa tu una calificacion valida (1-10): ";
						cin>>p->Cal2;
					}
					cout<<"Ingresa tu calificacion 3: ";
					cin>>p->Cal3;
					while ((p->Cal3 < 0) || (p->Cal3 > 10)){
						cout<<"Ingresa tu una calificacion valida (1-10): ";
						cin>>p->Cal3;
					}
					p->Promedio = ((p->Cal1) + (p->Cal2) + (p->Cal3))/3;
					
					p->EntidadS = EntidadS(entidad);
					p->EntidadL = EntidadL(entidad);
					p->Curp=GenCurp(p->Nombre, p->Paterno, p->Materno, p->Nacimiento, p->Sexo, p->EntidadS);
					
					system("cls");
					
					
					
					p->sig=NULL;
					p->ant=NULL;
					f=p;
					cout<<"\n\nAlumno registrado con exito!\n\n";
				}
				else{
					f=AgregarAlumno(f);
				};
				system("pause");
				break;
			case 7:
				if(p==NULL){
					cout<<"\nNo hay alumnos registrados.\n\n";
					system("pause");
				}
				else{
					cout<<"\nIngresa la curp del alumno: ";
					cin>>curp;
					for (i = 0; i < curp.length(); i++) {
				    	curp[i] = toupper(curp[i]);
				  	}
					EliminarAlumno(p, f, curp);break;
				};break;
				
			case 8:
				OrdenarPorPromedio(p);
				system("pause");
				
				break;
				
			case 9:
				MostrarTodos(p );
				system("pause");
				
			break;	
						
		}
	}while(opc >= 1);
}

string GenCurp(string nombre, string paterno, string materno, string nacimiento, char sexo, string entidad){
	int i;
	string curp;
	char letra, vocal, consonanteN, consonanteP, consonanteM;
	srand(time(NULL));
  	
  	//toupper(variable) sirve para hacer mayusculas todos los caracteres ingresados
  	//.length() sirve para obtener el largo de un string
  	//.substr(p, l) sirve para substraer partes de un string (posición, largo)
  	//Para buscar vocal o consonante de cada palabra
  	
  	for (i = 1; i < paterno.length(); i++) {
  		letra = paterno[i];
  		// ascii (A-a)
    	if (letra == 65 || letra == 97 || letra == 69 || letra == 101 || letra == 73 || letra == 105 || letra == 79 || letra == 111 || letra == 85 || letra == 117){
			vocal = letra;break;
		}
  	}
  	for (i = 1; i < paterno.length(); i++) { 		//verifica que no sea vocal
  		letra = paterno[i];
  		
    	if (letra != 65 && letra != 97 && letra != 69 && letra != 101 && letra != 73 && letra != 105 && letra != 79 && letra != 111 && letra != 85 && letra != 117){
			consonanteP = letra;break;
		}
  	}
  	for (i = 1; i < materno.length(); i++) {
  		letra = materno[i];
    	if (letra != 65 && letra != 97 && letra != 69 && letra != 101 && letra != 73 && letra != 105 && letra != 79 && letra != 111 && letra != 85 && letra != 117){
			consonanteM = letra;break;
		}
  	}
  	for (i = 1; i < nombre.length(); i++) {
  		letra = nombre[i];
    	if (letra != 65 && letra != 97 && letra != 69 && letra != 101 && letra != 73 && letra != 105 && letra != 79 && letra != 111 && letra != 85 && letra != 117){
			consonanteN = letra;break;
		}
  	}

  	curp = paterno.substr(0, 1) + vocal + materno.substr(0, 1) + nombre.substr(0, 1) + nacimiento.substr(2, 6) + sexo + entidad + consonanteP + consonanteM + consonanteN + "RL";
  	
  	return curp;
}

string EntidadS(int entidad){
	
	string EntidadP;
	
	switch(entidad){
		case 1:
			EntidadP = "AS";
			break;
		case 2:
			EntidadP = "BC";
			break;
		case 3:
			EntidadP = "BS";
			break;
		case 4:
			EntidadP = "CC";
			break;
		case 5:
			EntidadP = "CL";
			break;
		case 6:
			EntidadP = "CM";
			break;
		case 7:
			EntidadP = "CS";
			break;
		case 8:
			EntidadP = "CH";
			break;
		case 9:
			EntidadP = "DF";
			break;
		case 10:
			EntidadP = "DG";
			break;
		case 11:
			EntidadP = "GT";
			break;
		case 12:
			EntidadP = "GR";
			break;
		case 13:
			EntidadP = "HG";
			break;
		case 14:
			EntidadP = "JC";
			break;
		case 15:
			EntidadP = "MC";
			break;
		case 16:
			EntidadP = "MN";
			break;
		case 17:
			EntidadP = "MS";
			break;
		case 18:
			EntidadP = "NT";
			break;
		case 19:
			EntidadP = "NL";
			break;
		case 20:
			EntidadP = "OC";
			break;
		case 21:
			EntidadP = "PL";
			break;
		case 22:
			EntidadP = "QT";
			break;
		case 23:
			EntidadP = "QR";
			break;
		case 24:
			EntidadP = "SP";
			break;
		case 25:
			EntidadP = "SL";
			break;
		case 26:
			EntidadP = "SR";
			break;
		case 27:
			EntidadP = "TC";
			break;
		case 28:
			EntidadP = "TS";
			break;
		case 29:
			EntidadP = "TL";
			break;
		case 30:
			EntidadP = "VZ";
			break;
		case 31:
			EntidadP = "YN";
			break;
		case 32:
			EntidadP = "ZS";
			break;
	}
	
	return EntidadP;

}

string EntidadL(int entidad){
	
	string EntidadP;
	
	switch(entidad){
		case 1:
			EntidadP = "Aguascalientes";
			break;
		case 2:
			EntidadP = "Baja California";
			break;
		case 3:
			EntidadP = "Baja California Sur";
			break;
		case 4:
			EntidadP = "Campeche";
			break;
		case 5:
			EntidadP = "Coahuila";
			break;
		case 6:
			EntidadP = "Colima";
			break;
		case 7:
			EntidadP = "Chiapas";
			break;
		case 8:
			EntidadP = "Chihuahua";
			break;
		case 9:
			EntidadP = "Ciudad de Mexico";
			break;
		case 10:
			EntidadP = "Durango";
			break;
		case 11:
			EntidadP = "Guanajuato";
			break;
		case 12:
			EntidadP = "Guerrero";
			break;
		case 13:
			EntidadP = "Hidalgo";
			break;
		case 14:
			EntidadP = "Jalisco";
			break;
		case 15:
			EntidadP = "Mexico";
			break;
		case 16:
			EntidadP = "Michoacan";
			break;
		case 17:
			EntidadP = "Morelos";
			break;
		case 18:
			EntidadP = "Nayarit";
			break;
		case 19:
			EntidadP = "Nuevo Leon";
			break;
		case 20:
			EntidadP = "Oaxaca";
			break;
		case 21:
			EntidadP = "Puebla";
			break;
		case 22:
			EntidadP = "Queretaro";
			break;
		case 23:
			EntidadP = "Quintana Roo";
			break;
		case 24:
			EntidadP = "San Luis Potosi";
			break;
		case 25:
			EntidadP = "Sinaloa";
			break;
		case 26:
			EntidadP = "Sonora";
			break;
		case 27:
			EntidadP = "Tabasco";
			break;
		case 28:
			EntidadP = "Tamaulipas";
			break;
		case 29:
			EntidadP = "Tlaxcala";
			break;
		case 30:
			EntidadP = "Veracruz";
			break;
		case 31:
			EntidadP = "Yucatan";
			break;
		case 32:
			EntidadP = "Zacatecas";
			break;
	}
	
	return EntidadP;

}

void GenPromedio(nodo *p){
	nodo *aux;
	aux = p;
	float Promedio;
	Promedio = aux->Promedio;
	while(aux!=NULL){
		aux=aux->sig;
		Promedio = aux->Promedio;
	}
	
	cout<<"Promedio: "<<Promedio<<"\n";
}

nodo * AgregarAlumno(nodo *f){
	int i, entidad;
	nodo *aux;
	aux=new(nodo);
	system("cls");
	cout<<"\nIngresa tu nombre: ";
	cin>>aux->Nombre;
	for (i = 0; i < aux->Nombre.length(); i++) {
    	aux->Nombre[i] = toupper(aux->Nombre[i]);
  	}
	system("cls");
	cout<<"Ingresa tu apellido paterno: ";
	cin>>aux->Paterno;
	for (i = 0; i < aux->Paterno.length(); i++) {
    	aux->Paterno[i] = toupper(aux->Paterno[i]);
  	}
	system("cls");
	cout<<"Ingresa tu apellido materno: ";
	cin>>aux->Materno;
	for (i = 0; i < aux->Materno.length(); i++) {
    	aux->Materno[i] = toupper(aux->Materno[i]);
  	}
	system("cls");
	cout<<"Ingresa tu fecha de nacimiento (AAAAMMDD): ";
	cin>>aux->Nacimiento;
	system("cls");
	cout<<"Ingresa tu sexo (H/M): ";
	cin>>aux->Sexo;
	
	while ((aux->Sexo != 'h') && (aux->Sexo != 'H') && (aux->Sexo != 'm') && (aux->Sexo != 'M')){
		cout<<"Ingresa tu una opcion valida (H/M): ";
		cin>>aux->Sexo;
	}
	
	aux->Sexo = toupper(aux->Sexo);
	
	
	system("cls");
	cout<<"Ingresa tu entidad federativa de nacimiento: \n";
	ImprimirEntidades();
	cout<<"Tu seleccion: ";
	cin>>entidad;
	
	while ((entidad <= 0) || (entidad >= 33)){
		cout<<"Ingresa tu una opcion valida (1-32): ";
		cin>>entidad;
	}
	
	system("cls");
	cout<<"Ingresa tu calificacion 1: ";
	cin>>aux->Cal1;
	while ((aux->Cal1 < 0) || (aux->Cal1 > 10)){
		cout<<"Ingresa tu una calificacion valida (1-10): ";
		cin>>aux->Cal1;
	}
	cout<<"Ingresa tu calificacion 2: ";
	cin>>aux->Cal2;
	while ((aux->Cal2 < 0) || (aux->Cal2 > 10)){
		cout<<"Ingresa tu una calificacion valida (1-10): ";
		cin>>aux->Cal2;
	}
	cout<<"Ingresa tu calificacion 3: ";
	cin>>aux->Cal3;
	while ((aux->Cal3 < 0) || (aux->Cal3 > 10)){
		cout<<"Ingresa tu una calificacion valida (1-10): ";
		cin>>aux->Cal3;
	}
	aux->Promedio = ((aux->Cal1) + (aux->Cal2) + (aux->Cal3))/3;
	
	aux->EntidadS = EntidadS(entidad);
	aux->EntidadL = EntidadL(entidad);
	
	aux->Curp=GenCurp(aux->Nombre, aux->Paterno, aux->Materno, aux->Nacimiento, aux->Sexo, aux->EntidadS);
	system("cls");
	
	aux->sig=NULL;
	aux->ant=f;
	f->sig=aux;
	f=aux;
	cout<<"\n\nAlumno registrado con exito!\n\n";
	return f;
}

void BuscarPorNombre(nodo *p, string nombre){
	nodo *aux, *aux2=NULL;
	bool existe=false;
	aux=p;
	
	while(aux!=NULL){
		if(nombre == aux->Nombre){
			existe=true;
			aux2=aux;break;
		}
		aux=aux->sig;
	}
	if(existe){
		cout<<"\n\nAlumno encontrado!\n";
		system("pause");
		MostrarAlumno(aux2);
	}
	else{
		cout<<"\nEl alumno no esta registrado!\n";
	}
	system("pause");
}

void BuscarPorApellido(nodo *p, string apellido){
	nodo *aux, *aux2=NULL;
	bool existe=false;
	aux=p;
	while(aux!=NULL){
		if((apellido == aux->Paterno) || (apellido == aux->Materno)){
			existe=true;
			aux2=aux;break;
		}
		aux=aux->sig;
	}
	if(existe){
		cout<<"\n\nAlumno encontrado!\n";
		system("pause");
		MostrarAlumno(aux2);
	}
	else{
		cout<<"\nEl alumno no esta registrado!\n";
	}
	system("pause");
}

void BuscarPorCurp(nodo *p, string curp){
	nodo *aux, *aux2=NULL;
	bool existe=false;
	aux=p;
	while(aux!=NULL){
		if(curp == aux->Curp){
			existe=true;
			aux2=aux;break;
		}
		aux=aux->sig;
	}
	if(existe){
		cout<<"\n\nAlumno encontrado!\n";
		system("pause");
		MostrarAlumno(aux2);
	}
	else{
		cout<<"\nEl alumno no esta registrado!\n";
	}
	system("pause");
}

void MostrarAlumno(nodo *user){
	int opc;
	float promedio;
	bool existe=false;
	do{
		system("cls");
		cout<<"\n\tApellido paterno: "<<user->Paterno<<"\n";
		cout<<"\tApellido materno: "<<user->Materno<<"\n";
		cout<<"\tNombre: "<<user->Nombre<<"\n";
		cout<<"\tCalificacion 1: ";
		cout<<user->Cal1<<"\n";
		cout<<"\tCalificacion 2: ";
		cout<<user->Cal2<<"\n";
		cout<<"\tCalificacion 3: ";
		cout<<user->Cal3<<"\n";
		
		cout<<"\tPromedio: ";
		cout<<user->Promedio<<"\n";
		
		cout<<"\tAnio de Nacimiento: "<<user->Nacimiento.substr(0, 4)<<"\n";
		cout<<"\tMes de Nacimiento: "<<user->Nacimiento.substr(4, 2)<<"\n";
		cout<<"\tDia de Nacimiento: "<<user->Nacimiento.substr(6, 2)<<"\n";
		cout<<"\tSexo: ";
		if (user->Sexo == 'H'){
			cout<<"MASCULINO\n";
		}
		else{
			cout<<"FEMENINO\n";
		}
		cout<<"\tEntidad de nacimiento: "<<user->EntidadL<<"\n";
		cout<<"\tCurp: "<<user->Curp<<"\n\n";
		cout<<"\t\tMENU\n\n";
		cout<<"\t[1] Salir.\n";
		cout<<"\n\tTu opcion: ";
		cin>>opc;
	}while(opc != 1);
	cout<<"\nGracias por usar nuestro sistema!\n";
}

void ImprimirEntidades(){
	cout<<"[1] Aguascalientes\n";
	cout<<"[2] Baja California\n";
	cout<<"[3] Baja California Sur\n";
	cout<<"[4] Campeche\n";
	cout<<"[5] Coahuila\n";
	cout<<"[6] Colima\n";
	cout<<"[7] Chiapas\n";
	cout<<"[8] Chihuahua\n";
	cout<<"[9] Ciudad de Mexico\n";
	cout<<"[10] Durango\n";
	cout<<"[11] Guanajuato\n";
	cout<<"[12] Guerrero\n";
	cout<<"[13] Hidalgo\n";
	cout<<"[14] Jalisco\n";
	cout<<"[15] Mexico\n";
	cout<<"[16] Michoacan\n";
	cout<<"[17] Morelos\n";
	cout<<"[18] Nayarit\n";
	cout<<"[19] Nuevo Leon\n";
	cout<<"[20] Oaxaca\n";
	cout<<"[21] Puebla\n";
	cout<<"[22] Queretaro\n";
	cout<<"[23] Quintana Roo\n";
	cout<<"[24] San Luis Potosi\n";
	cout<<"[25] Sinaloa\n";
	cout<<"[26] Sonora\n";
	cout<<"[27] Tabasco\n";
	cout<<"[28] Tamaulipas\n";
	cout<<"[29] Tlaxcala\n";
	cout<<"[30] Veracruz\n";
	cout<<"[31] Yucatan\n";
	cout<<"[32] Zacatecas\n";
}

void EliminarAlumno(nodo *&p,nodo *&f, string curp){
	nodo *aux, *aux2;
	int e;
	bool existe=false;
	aux=p;
	while(aux!=NULL){
		if(curp == aux->Curp){
			existe=true;
			aux2=aux;break;
		}
		aux=aux->sig;
	}
	if(existe){
		if(aux2->sig==NULL){
			if(aux2->ant==NULL){ //Por si es el unico nodo
				p=NULL;
				delete(p);
				cout<<"\nAlumno eliminado con exito!\n";
				system("pause");
			}
			else{ //Por si hay mas nodos atras (es el ultimo nodo)
				aux=aux2->ant;
				aux->sig=NULL;
				aux2->ant=NULL;
				f=aux;
				delete(aux2);
				cout<<"\nAlumno eliminado con exito!\n";
				system("pause");
				return;
			}
		}
		else{ //Por si esta en medio
			if(aux2->ant==NULL){ //Por si es el primer nodo
				aux2=aux2->sig;
				p=aux2;
				aux=aux2->ant;
				aux2->ant=NULL;
				aux->sig=NULL;
				delete(aux);
				cout<<"\nAlumno eliminado con exito!\n";
				system("pause");
				return;
			}
			else{ //Por si esta en medio de dos nodos
				aux=aux2->ant;
				aux->sig=aux2->sig;
				aux2->ant=NULL;
				aux2->sig=NULL;
				delete(aux2);
				aux2=aux->sig;
				aux2->ant=aux;
				cout<<"\nAlumno eliminado con exito!\n";
				system("pause");
			}
		}
	}
	else{
		cout<<"\nNo existe este alumno o curp!\n";
	}
}


void PromedioTotal(nodo *user) {
    int cont = 0;
    float Prom = 0;
    float PromTotal = 0;

    while (user != NULL) {
        Prom += user->Promedio;
        cont++;
        user = user->sig;
    }

    if (cont > 0) {
        PromTotal = Prom / cont;
        cout << "Promedio General: " << PromTotal << " \n";
    } else {
        cout << "No hay alumnos registrados.\n";
    }
}

void OrdenarPorPromedio(nodo *p) {
    nodo *actual, *siguiente;
    string tempNombre;
    float tempPromedio;

    if(p==NULL){
		cout<<"\nNo hay Alumnos registrados.\n\n";
		return;
	}

    for (actual = p; actual->sig != NULL; actual = actual->sig) {
        for (siguiente = actual->sig; siguiente != NULL; siguiente = siguiente->sig) {
            if (actual->Promedio > siguiente->Promedio) {
                // Intercambiar nombres
                tempNombre = actual->Nombre;
                actual->Nombre = siguiente->Nombre;
                siguiente->Nombre = tempNombre;

                // Intercambiar promedios
                tempPromedio = actual->Promedio;
                actual->Promedio = siguiente->Promedio;
                siguiente->Promedio = tempPromedio;
            }
        }
    }

    cout << "Alumnos ordenados por promedio (menor a mayor):\n\n";
    while (p != NULL) {
        cout << "Nombre: " << p->Nombre << " - Promedio: " << p->Promedio << endl;
        p = p->sig;
    }
}


void MostrarTodos(nodo *p){
	float promedio;
	bool existe=false;
	nodo *aux;
	aux=p;
	
	
    while(aux != NULL){

		cout<<"\n\tApellido paterno: "<<aux->Paterno<<"\n";
		cout<<"\tApellido materno: "<<aux->Materno<<"\n";
		cout<<"\tNombre: "<<aux->Nombre<<"\n";
		cout<<"\tCalificacion 1: ";
		cout<<aux->Cal1<<"\n";
		cout<<"\tCalificacion 2: ";
		cout<<aux->Cal2<<"\n";
		cout<<"\tCalificacion 3: ";
		cout<<aux->Cal3<<"\n";
		
		cout<<"\tPromedio: ";
		cout<<aux->Promedio<<"\n";
		
		cout<<"\tAnio de Nacimiento: "<<aux->Nacimiento.substr(0, 4)<<"\n";
		cout<<"\tMes de Nacimiento: "<<aux->Nacimiento.substr(4, 2)<<"\n";
		cout<<"\tDia de Nacimiento: "<<aux->Nacimiento.substr(6, 2)<<"\n";
		cout<<"\tSexo: ";
		if (aux->Sexo == 'H'){
			cout<<"MASCULINO\n";
		}
		else{
			cout<<"FEMENINO\n";
		}
		cout<<"\tEntidad de nacimiento: "<<aux->EntidadL<<"\n";
		cout<<"\tCurp: "<<aux->Curp<<"\n\n";
  
        
        aux = aux->sig;
    }
    cout << "\n";
}