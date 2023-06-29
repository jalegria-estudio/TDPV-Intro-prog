/**
 * Introducción a C++.
 * Practica Unidad 4.1 - Actividad 11
 * Consigna: Genere un arreglo con 20 valores todos en 0 (cero). Pida por consola 4 valores y 4 posiciones.
 *  Inserte los valores en sus respectivas posiciones (tener en cuenta que estén dentro del rango).
 * Autor: Juan P. Alegria
 * Fecha: 2023/06/17
 */

#include <iostream>
#include <limits>
#include "../libs/libtools.hpp" //biblioteca propia, ver carpeta: /libs/

using namespace std;

constexpr auto MAX_SIZE = std::numeric_limits<std::streamsize>::max(); //- max_size =>fue obtenido del ejemplo de la doc c++ =>std::basic_istream<CharT,Traits>::ignore => necesita la biblioteca <limits>


void readValue(int &var, string name){
    cout<<"Enter a "<<name<<" >";
    cin>>var;

    if(!cin || cin.fail()){ //Verifica que no haya fallado el insert y deje al cin en estado fail. En caso de error, retorna -1;
        cin.clear();
        var = -1;
    }

    cin.ignore(MAX_SIZE, '\n');//Limpia el buffer stream in porque queda '\n' y salta la funcion; Ojo! con llamar está función sin haber llamado previamente a cin>>XX, queda a la espera.
}

void showArray(int *arr, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    
    cout<<endl;
}

int main()
{
    const size_t SIZE = 20;
    int arr[SIZE]{0};

    //pedir e insertar los valores
    for(size_t i = 0; i < 4; i++)
    {
        int var{};
        int index{};

        while (true)
        {
            readValue(var, "unsigned int value");
            readValue(index, "index between 0 and 19 included");

            if(var >= 0 and index >= 0 and index <20)  break;
            else cout<<endl<<"Value or Index is wrong! Enter data again."<<endl;
        }

        arr[index] = var;
    }
    
    showArray(arr, SIZE);
}
