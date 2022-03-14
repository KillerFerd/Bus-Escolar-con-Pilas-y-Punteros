/*	Desarrollador: 		KillerFerd
	Programa: 			Bus Escolar
	Curso:				Programación III */

/* PLANTEAMIENTO DEL PROBLEMA*/
/*El ejercicio consiste en realizar un programa para un bus escolar, este bus almacena a 
los pasajeros según suban al bus. Lo puede realizar de la siguiente manera:

- Implementar una pila y mediante las instrucciones push/pop se deben de ir actualizando los pasajeros, 
y los asientos disponibles. Se pueden recoger pasajeros push o sacar pasajeros en esta pila. Recordar 
que se debe de implementar una función que indique si la cola está vacía. */

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//Definiendo una estrucutra Nodo
struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Definiendo los prototipos
void agregarPila(Nodo *&,int); 
void sacarPila(Nodo *&,int &);

//Función Agregar Pila
void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<endl<<"El alumno ocupo el asiento "<<n<<endl;
}

//Función Sacar Pila
void sacarPila(Nodo *&pila,int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

//Función Principal
int main()
{
	//Variable Nodo
	Nodo *pila = NULL;
	//Variables Funcionales
   	int i,opcion;
   	//Variables Del Bus
   	int bus[20],  	
   		asiento;
   		
   	//Establecer todos los asientos en 0
   	for (i=0;i<21;i++)
   	bus[i]=0;
   	cout<<"Todos los asientos estan vacios ... ";
   	getch();
   
   	//Iteración para el Menú 
	do{
	   	system("cls");
	   	cout<<".:Menu de Acciones:."<<endl;
   		cout<<"1. Recoger Alumno"<<endl;
   		cout<<"2. Retirar Alumno"<<endl;
   		cout<<"3. Mostrar Disponibilidad de Asientos"<<endl;
   		cout<<"4. Salir"<<endl;
   		cin>>opcion;
   		switch(opcion){
   			
   			//Recoger Alumno
   			case 1:
   				system("cls");
   				cout<<".:Recogiendo Alumno:."<<endl;
   				
				//Iteración que valida datos entre los rangos establecidos
				do{
   					cout<<"Digite un numero de asiento [1-20]: ";
   					cin>>asiento;
   					if((asiento<1)||(asiento>20))
  					cout<<"El dato digitado no es valido ..."<<endl;
			   		}while((asiento<1)||(asiento>20));					
				
				//Iteración que valida asientos disponibles	   	
				if(bus[asiento]==0){
					bus[asiento]=1;
					agregarPila(pila,asiento);
				}
				else
				cout<<"El asiento no esta disponible ..."<<endl;
				
   				getch();
   				break;
   				
   			//Retirar Alumno	
   			case 2:
   				system("cls");
   				cout<<".:Retirando Alumno:."<<endl; 
   				
				//Llamar a la función para sacar pila
				sacarPila(pila,asiento);
				bus[asiento]=0;
				cout<<endl<<"El alumno desocupo el asiento "<<asiento<<endl;		
   				getch();
				break;
   			case 3:
   				system("cls");
   				
   				//Mostrando la disponibilidad de las Filas
   				cout<<".:Mostrando Disponibilidad de Asientos:."<<endl; 
   				cout<<"La Disponibilidad de los asientos es: "<<endl;
   				for(i=0;i<=20;i++){
   					if(bus[i]==1)
   					cout<<i<<"-";
				   }
				   
   				getch();
				break;	
		   }
   }while (opcion != 4);
   
   getch();
   return 0;
}
