#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <string>
#include <string.h>
#define MAX 10

using namespace std;


/* Se define la plantilla de la clase Pila con todos sus atributos y métodos.
Ademas se incluye una pequeña aplicación de la misma. */
template<class T>
class Pila
{
    private:
        T EspacioPila[MAX];
        int Tope;
    public:
        Pila();
        void operator + (T);
        void operator - (T *);
        int PilaLlena();
        int PilaVacia();
};

/* Declaración del método constructor por omisión. Asigna el valor -1
al Tope, indicando que la pila está vacia. */
template <class T>
Pila<T>::Pila():Tope(-1)
{}

/* Método que evalua si la pila está llena. Regresa 1 si
todos los espacios están ocupados y 0 en caso contrario. */
template <class T>
int Pila<T>::PilaLlena()
{
     if(Tope==MAX-1)
      return 1;
     else
      return 0;
}


/* Método que evalúa si la pila está vacía, regresando 1 si
lo está y 0 en caso contrario. */
template <class T>
int Pila<T>::PilaVacia()
{
     if(Tope==-1)
      return 1;
     else
      return 0;
}


/* El operador +, que normalmente indica la operación aritmetica de
suma, se sobrecarga utilizandose para insertar un elemento en la pila.
Por lo tanto, el operador +, en este programa, tendrá asociadas dos
operaciones: suma de números e inserción de elementos en una pila. Se
verifica si la pila tiene espacio antes de invocar el método. Se
recibe como parámetro el dato a insetar. */
template <class T>
void Pila<T>::operator + (T Valor)
{
    Tope++;
    EspacioPila[Tope] = Valor;
}

/* El operador -, que normalmente indica la operación aritmetica de
resta, se sobrecarga utilizandose para eliminar un elemento en la pila.
Por lo tanto, el operador -, en este programa, tendrá asociadas dos
operaciones: resta de números e eliminación de elementos en una pila. El
valor eliminado se pasa como parámetro por referencia. */
template <class T>
void Pila<T>::operator - (T *Valor)
{
    *Valor=EspacioPila[Tope];
    Tope--;
}


#endif // PILA_H_INCLUDED
