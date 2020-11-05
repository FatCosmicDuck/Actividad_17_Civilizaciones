#include <iostream>
#include "laboratorio.h"

using namespace std;

int main() {
    Laboratorio lb;
    int op;

    do{
        cout << "1.- Agregar Computadora" << endl;
        cout << "2.- Mostrar            " << endl;
        cout << "3.- Respaldar          " << endl;
        cout << "4.- Recuperar          " << endl;
        cout << "5.- Insertar           " << endl;
        cout << "6.- Inicializar        " << endl;
        cout << "7.- Eliminar           " << endl;
        cout << "8.- Ordenar            " << endl;
        cout << "9.- Buscar             " << endl;
        cout << "10.-Borrar ultimo      " << endl;
        cout << "0.- Salir              " << endl;
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        if(op == 1){
            Computadora c;
            cin >> c;
            lb.agregarComputadora(c);
        }

        else if(op == 2){
            lb.mostrar();
        }

        else if(op == 3){
            lb.respaldar();
        }
        
        else if(op == 4){
            lb.recuperar();
        }
        
        else if(op == 5){
            size_t pos;
            Computadora c;
            cin >> c;
            cout << "Dime la posicion: ";
            cin >> pos;

            if(pos >= lb.size()){
                cout << "Posicion invalida..." << endl;
            }
            else{
                lb.insertar(c, pos);
            }
        }

        else if(op == 6){
            size_t pos;
            Computadora c;
            cin >> c;
            cout << "Dime la cantidad: ";
            cin >> pos;
            lb.inicializar(c, pos);
        }

        else if(op == 7){
            size_t pos;
            cout << "Dime la posicion: ";
            cin >> pos;

            if(pos >= lb.size()){
                cout << "Posicion invalida..." << endl;
            }
            else{
                lb.eliminar(pos);
            }
        }

        else if(op == 8){
            lb.ordenar();
        }

        else if(op == 9){
            Computadora c;
            cin >> c;
            Computadora *ptr = lb.buscar(c);
            
            if(ptr == nullptr){
                cout << "No existe tal dato..." << endl;
            }
            else{
                cout << *ptr << endl;
            }
        }

        else if(op == 10){
            lb.borrar_ultimo();
        }

        else if(op == 0){
            cout << "Programa finalizado..." << endl;
            cin.get();
        }

        else{
        cout << "Opcion invalida..." << endl;
        }
    }while(op != 0);

    return 0;
}