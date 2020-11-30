#include <iostream>
#include "videogame.h"

using namespace std;

int main() {
    VideoGame vg;
    string tempString;
    int op, tempInt, subMenu;
    float tempFloat;

    do{
        cout << "Usuario: " <<vg.getUsuario() << endl;
        cout << "______________________________________________" << endl;
        cout << "1.- Nombre de usuario          " << endl;
        cout << "2.- Agregar Civilizacion       " << endl;
        cout << "3.- Insertar                   " << endl;
        cout << "4.- Inicializar                " << endl;
        cout << "5.- Primera Civilizacion       " << endl;
        cout << "6.- Ultima Civilizacion        " << endl;
        cout << "7.- Ordenar por Nombre         " << endl;
        cout << "8.- Ordenar por Ubicacion en X " << endl;
        cout << "9.- Ordenar por Ubicacion en Y " << endl;
        cout << "10.- Ordenar por Puntuacion    " << endl;
        cout << "11.- Eliminar                  " << endl;
        cout << "12.- Buscar                    " << endl;
        cout << "13.- Modificar                 " << endl;
        cout << "14.- Mostrar                   " << endl;
        cout << "0.- Salir                      " << endl;
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        if(op == 1){
            cout << "Nombre de Usuario: ";
            getline(cin ,tempString);
            vg.setUsuario(tempString);
        }

        else if(op == 2){
            Civilizacion c;
            cin >> c;
            vg.agregarCivilizacion(c);
        }

        else if(op == 3){
            size_t pos;
            Civilizacion c;
            cin >> c;
            cout << "Dime la posicion: ";
            cin >> pos;

            if(pos >= vg.size()){
                cout << "Posicion invalida..." << endl;
            }
            else{
                vg.insertar(c, pos);
            }
        }

        else if(op == 4){
            size_t pos;
            Civilizacion c;
            cin >> c;
            cout << "Dime la cantidad: ";
            cin >> pos;
            vg.inicializar(c, pos);
        }

        else if(op == 5){
            vg.primeraCivilizacion();
        }

        else if(op == 6){
            vg.ultimaCivilizacion();
        }

        else if(op == 7){
            vg.ordenarNombre();
        }

        else if(op == 8){
            vg.ordenarUbicacionX();
        }

        else if(op == 9){
            vg.ordenarUbicacionY();
        }

        else if(op == 10){
            vg.ordenarPuntuacion();
        }

        else if(op == 11){
            Civilizacion c;
            cin >> c;
            vg.eliminar(c);
        }

        else if(op == 12){
            Civilizacion c;
            cin >> c;
            Civilizacion *ptr = vg.buscar(c);
            
            if(ptr == nullptr){
                cout << "No existe tal dato..." << endl;
            }
            else{
                cout << *ptr << endl;
            }
        }

        else if(op == 13){
            Civilizacion c;
            cin >> c;
            Civilizacion *ptr = vg.buscar(c);
            
            if(ptr == nullptr){
                cout << "No existe tal dato..." << endl;
            }
            else{
                cout << *ptr << endl;
                cout << "Que deseas modificar?" << endl;
                cout << "1.- Nombre           " << endl;
                cout << "2.- Ubicacion en X   " << endl;
                cout << "3.- Ubicacion en Y   " << endl;
                cout << "4.- Puntuacion       " << endl;
                cout << "5.- Nada             " << endl; 
                cin >> subMenu;
                cin.ignore();

                if(subMenu == 1){
                    cout << "Nombre: ";
                    getline(cin, tempString);
                    ptr->setnombre(tempString);
                }

                else if(subMenu == 2){
                    cout << "Ubicacion en X: ";
                    cin >> tempInt;
                    ptr->setUbicacionEnX(tempInt);
                }

                else if(subMenu == 3){
                    cout << "Ubicacion en Y: ";
                    cin >> tempInt;
                    ptr->setUbicacionEnY(tempInt);
                }

                else if(subMenu == 4){
                    cout << "Puntuacion: ";
                    cin >> tempFloat;
                    ptr->setPuntuacion(tempFloat);
                }

                else if(subMenu == 5){
                    cout << "Volviendo al menu..." << endl;
                }

                else {
                    cout << "No existe tal opcion" << endl;
                }
                cin.ignore();
            }
        }

        else if(op == 14){
            vg.mostrar();
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