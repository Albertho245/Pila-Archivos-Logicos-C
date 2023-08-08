#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <string>
#include <string.h>
#define MAX 10

using namespace std;


/* Se define la plantilla de la clase Pila con todos sus atributos y m�todos.
Ademas se incluye una peque�a aplicaci�n de la misma. */
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

/* Declaraci�n del m�todo constructor por omisi�n. Asigna el valor -1
al Tope, indicando que la pila est� vacia. */
template <class T>
Pila<T>::Pila():Tope(-1)
{}

/* M�todo que evalua si la pila est� llena. Regresa 1 si
todos los espacios est�n ocupados y 0 en caso contrario. */
template <class T>
int Pila<T>::PilaLlena()
{
     if(Tope==MAX-1)
      return 1;
     else
      return 0;
}


/* M�todo que eval�a si la pila est� vac�a, regresando 1 si
lo est� y 0 en caso contrario. */
template <class T>
int Pila<T>::PilaVacia()
{
     if(Tope==-1)
      return 1;
     else
      return 0;
}


/* El operador +, que normalmente indica la operaci�n aritmetica de
suma, se sobrecarga utilizandose para insertar un elemento en la pila.
Por lo tanto, el operador +, en este programa, tendr� asociadas dos
operaciones: suma de n�meros e inserci�n de elementos en una pila. Se
verifica si la pila tiene espacio antes de invocar el m�todo. Se
recibe como par�metro el dato a insetar. */
template <class T>
void Pila<T>::operator + (T Valor)
{
    Tope++;
    EspacioPila[Tope] = Valor;
}

/* El operador -, que normalmente indica la operaci�n aritmetica de
resta, se sobrecarga utilizandose para eliminar un elemento en la pila.
Por lo tanto, el operador -, en este programa, tendr� asociadas dos
operaciones: resta de n�meros e eliminaci�n de elementos en una pila. El
valor eliminado se pasa como par�metro por referencia. */
template <class T>
void Pila<T>::operator - (T *Valor)
{
    *Valor=EspacioPila[Tope];
    Tope--;
}


#endif // PILA_H_INCLUDED
