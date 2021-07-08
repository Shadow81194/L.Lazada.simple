#include <iostream>//libreria de C++
#include <stdlib.h>//libreria de C++
using namespace std;

struct nodo{
    int dato; //Variable que va aser acinadad con un valor.
    struct nodo *enlace; //Estrutura nodo, declara un objeto puntero.
};
typedef struct nodo *lista_simple; //Estrutura nodo para Llamar a lista limple.


void menu1() //Funcion Menu.
{
    cout<<("|___________________________________________________\n");//Imprimir.
    cout<<("|____________---SIMPLE LINKED LIST---_______________|\n");//Delacracion del titulo del codigo.
    cout<<("|___________________________________________________|\n");//Imprimir.
    cout<<("|___________________________________________________|\n");//Imprimir.
    cout<<("|____________________ENTER OPTION___________________|\n");//Mensaje de ingreso de numero.
    cout<<("|___________________________________________________|\n");//Imprimir.
    cout<<("|___________________________________________________|\n");//Imprimir.
    cout<<("|_________1) INSERT_________________________________|\n");//Mensaje de ingresar.
    cout<<("|_________2) PRINT SIMPLE LIST______________________|\n");//Mensaje de impresion de lista.
    cout<<("|_________3) SEARCH ELEMENT_________________________|\n");//Mensaje de buscar numero de la lista.
    cout<<("|_________4) SALIR__________________________________|\n");// Mensaje de salidad.
    cout<<("|___________________________________________________|\n");//Imprimir.
}



void insertar(lista_simple &nuevo_nodo, int valor) //Funcion donde vamos a insertar los numero.
{
    lista_simple nodo1; //Creacion del nodo1.
    nodo1 = new(struct nodo); //Creacion de un nuevo nodo, a partir del nodo1.
    nodo1->dato = valor; //Igualacion del dato a valor.
    nodo1->enlace = nuevo_nodo; //El en elace nodo1 es igual a nuevo nodo.
    nuevo_nodo  = nodo1; // Nuevo nodo es igual a nodo1.
}

void imprimir(lista_simple lista) //Funcion de imprimer las listas.
{
    while(lista != NULL) //una condicion que dice que si es verdadera o falsa.
    {
        cout << lista->dato << endl; //mostra en pantalla los numero ingresado
        lista = lista->enlace; //Deplaza cada elemto de la lista.
    }
}

void buscarElemento(lista_simple lista, int valor)//Funcion donde buscamos el numero ingresado enla lista.
{
    lista_simple lista_buscar;//Creacion de un nuenvo lista de buqueda.
    lista_buscar = lista; //Igualamos lista busquedad es igual a lista.
    int i = 1, band = 0; //es una variable que indica si el dato a busca esta en la lista o no
    while(lista_buscar!=NULL)//una condicion que dice que si es verdadera o falsa.
    {
        if(lista_buscar->dato==valor) //Una condicion que se va a repetir asta que el resultado sea verdadero o falso.
        {
            cout<<endl<<" Found in position "<< i <<endl;//Imprimir mensajede busquedad.
            band = 1; //Igualosmo que band sea ugual a cero.
        }
        lista_buscar = lista_buscar->enlace;//I//Deplaza cada elemto de la lista.
        i++;//Igrementamos.
    }
    if(band==0)//Una condicion que se va a repetir asta que el resultado sea verdadero o falso.
        cout<<"\n\n Number not found..!"<< endl;//Imprimir mensajede busquedad del numero encotrado.
}

int main()//Funcion main.
{
    lista_simple lista = NULL;//Lista tiene que ser igual a cero.
    int opcion;   // para las opciones del menÃº
    int valor;  // elemenento a ingresar

    do //se utiliza para especificar un ciclo condicional que se ejecuta al menos una vez.
    {
        menu1();/*declaracion de  la funcion menu.*/  cin>> opcion;// permite guardar en una variable lo que el usuario ingrese.
        switch(opcion) //se utiliza para seleccionar una de entre múltiples alternativas.
        {
        case 1://una opción que se comparará con la expresión que recibe switch.
            cout<< "\n NUMBER TO INSERT: "; cin>> valor;//Imprime mensaje de insertar numero.
            insertar(lista, valor);//Declaaion de la funcion insertar.
            break;//usa para interrumpir (romper) la ejecución normal de un bucle.

        case 2://una opción que se comparará con la expresión que recibe switch.
            cout << "\n\n SIMPLE LIST ELEMENTS \n\n";//Imprime mensaje de lista.
            imprimir(lista);//Declaaion de la funcion Imprimir lista.
            break;//usa para interrumpir (romper) la ejecución normal de un bucle.

        case 3://una opción que se comparará con la expresión que recibe switch.
            cout<<"\n Value to look for: "; cin>> valor;//Declaaion de la funcion de busquedad.
            buscarElemento(lista, valor);//Declaaion de la funcion Busquedad.
            break;//usa para interrumpir (romper) la ejecución normal de un bucle.

        }
    }while(opcion!=4);//Igualamos que la opcion no sea igual a 4.
    system("pause");//Sirve para ejecutar subprocesos o comandos del sistema operativo.
    return 0;//fuerza una salida inmediata de la función en que se encuentra.
}
