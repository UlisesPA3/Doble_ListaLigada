#include <iostream>

using namespace std;

//Clase cNodo que representa cada nodo de la lista
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
    //Método para imprimir el ID (dato) del nodo
    void imprimirID(){
        cout<< dato;
    }

    //Getters & Setters
    char getDato() { return dato;}
    void setDato(char d){ dato = d;}

    cNodo* getSig(){return sig;}
    void setSig(cNodo* s){sig = s;}

    cNodo* getAnt(){return ant;}
    void setAnt(cNodo* a){ant = a;}

};

//Clase para manejar la lista doblemente enlazada
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

    //Función para imprimir todos los IDs de la lista 
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

    //Función para imprimir la lista en reversa
    void imprimirDI(){
        if(tail == NULL){
            cout<<"La lista esta vacia"<< endl;
            return;
        }

        cout<<"Lista (reversa): ";
        cNodo* actual = tail;
        while(actual != NULL){
            actual->imprimirID();
            if(actual->getAnt() != NULL){
                cout << "<->";
            }
            actual = actual->getAnt();
        }
        cout<<endl;
    }

    //Función para verificar si la lista está vacia
    bool estaVacia(){
        return head == NULL;
    }

    //Función para borrar toda la lista
    void borrarLista(){
        cNodo* actual = head;
        while (actual != NULL){
            cNodo* siguiente = actual->getSig();
            delete actual;
            actual = siguiente;
        }
        head = NULL;
        tail = NULL;
        cout << "Lista borrada exitosamente." << endl;
    }

};
int main(){
    cDobleLigada lista;
    int opc;
    char car;

    do{
        cout<<"\n =MENU LISTA DOBLEMENTE ENLAZADA= " <<endl;
        cout<<"1. Insertar nodo"<< endl;
        cout<<"2. Imprimir lista (adelante)"<< endl;
        cout<<"3. Imprimir lista (reversa)"<< endl;
        cout<<"4. Borrar lista"<< endl;
        cout<<"5. Salir"<< endl;
        cout<<"Seleccione una opción: ";
        cin>>opc;

        switch(opc){
            case 1:
                cout<< "Ingresa el caracter a insertar: ";
                cin >> car;
                lista.insertarNodo(car);
                cout << "Nodo insertado exitosamente" << endl;
                break;
                
            case 2:
                lista.imprimirID();
                break;
            
            case 3:
                lista.imprimirDI();
                break;
            
            case 4: 
                if(!lista.estaVacia()){
                    lista.borrarLista();
                }else{
                    cout<<"La lista ya esta vacia. " << endl;
                }
                break;
            
            case 5:
                cout<<"Fin del programa, chau."<< endl;
                break;
            
            default:
                cout<< "Opcion invalida. Intente de nuevo. " << endl;

        }

    }while(opc != 5);

    return 0;

}