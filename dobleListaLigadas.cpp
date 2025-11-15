#include <iostream>

using namespace std;

class cNodo{
private:
    char dato;
    cNodo* sig;
    cNodo* ant;
    ;
public:
    cNodo(char d){
    dato = d;
    sig = NULL;
    ant = NULL;
}
void imprimirID(){
    cout<< dato;
}

char getDato() { return dato;}
void setDato(char d){ dato = d;}

cNodo* getSig(){return sig;}
void setSig(cNodo* s){sig = s;}

cNodo* getAnt(){return ant;}
void setAnt(cNodo* a){ant = a;}

};

class cDobleLigada{
private:
    cNodo* head;
    cNodo* tail;

public:
    cDobleLigada(){
    head = NULL;
    tail= NULL;
    }

    //Destructor para liberar memoria
    ~cDobleLigada(){
    cNodo* actual = head;
    while(actual != NULL){
        cNodo* siguiente = actual -> getSig();
        delete actual;
        actual = siguiente;
    }
}

//Funcion para insertar un nodo al final de la lista
void insertarNodo(char dato){
    cNodo* nuevo = new cNodo(dato);

    if(head == NULL){

        head = nuevo;
        tail = nuevo;
    }else{
        tail-> setSig(nuevo);
        nuevo->setAnt(tail);
        tail = nuevo;
    }
}

void imprimirID(){
    if(head == NULL){
        cout << "La lista esta vacia" << endl;
        return ;
    }
    cout << "Lista (adelante): ";
    cNodo* actual = head;
    while(actual != NULL){
        actual -> imprimirID();
        if(actual -> getSig() != NULL){
            cout <<"<-> ";
        }
        actual = actual -> getSig();
    }
    cout << endl;
}

bool estaVacia(){
    return head == NULL;
}

};
int main()
{
    cDobleLigada lista;

    cout << "Insertar nodos: A, B, C, D, E" << endl;
    lista.insertarNodo('A');
    lista.insertarNodo('B');
    lista.insertarNodo('C');
    lista.insertarNodo('D');
    lista.insertarNodo('E');
    lista.insertarNodo('F');



    cout << endl;

    lista.imprimirID();

    cout << "Fin del programa" << endl;

    return 0;

}