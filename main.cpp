#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <string>
#include <string.h>

#define MAX 2

using namespace std;

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


class Cheque
{
    private:
        int Numero, CuentaADepositar;
        char Banco[10];
        double Monto;
    public:
        Cheque();
        Cheque(int, char[], int, double);
        ~Cheque();
        void ImprimeDatos();
};

Cheque::Cheque()
{}

Cheque::Cheque(int NumCta, char *NomBco, int Cta, double Mon)
{
    Numero= NumCta;
    CuentaADepositar= Cta;
    Monto= Mon;
    strcpy(Banco, NomBco);
}

Cheque::~Cheque()
{}

void Cheque::ImprimeDatos()
{
    cout << "\nNumero de Cheque: " << Numero;
    cout << "\nDel banco: " << Banco;
    cout << "\nDepositado en la cuenta: " << CuentaADepositar;
    cout << "\nMonto: " << Monto<< endl;
}

class ChequeRechazado: public Cheque
{
    private:
        double Cargo;
    public:
        ChequeRechazado();
        ChequeRechazado(int, char[], int, double);
        ~ChequeRechazado();
        void ImprimeDatos();
};

ChequeRechazado::ChequeRechazado()
{}

ChequeRechazado::ChequeRechazado(int NumCta, char *NomBco, int Cta, double Mon): Cheque(NumCta, NomBco, Cta, Mon)
{
    Cargo= Mon*0.10;
}

ChequeRechazado::~ChequeRechazado()
{}

void ChequeRechazado::ImprimeDatos()
{
    Cheque::ImprimeDatos();
    cout<<"\nCargo por rechazo: " << Cargo<<endl;
}

class Banco
{
    private:
        Pila<Cheque> Cheques;
        Pila<ChequeRechazado> ChequesRe;
    public:
        Banco();
        ~Banco();
        void ProcesarCheque();
        void ProcesarChequeR();
        void RegistroCheque(Cheque);
        void RegistroChequeR(ChequeRechazado);
};

Banco::Banco()
{}

Banco::~Banco()
{}

void Banco::ProcesarCheque()
{
    Cheque ChequeCli;
    if (!Cheques.PilaVacia())
    {
        Cheques - &ChequeCli;
        cout << "\n\nNo hay cheques por procesar. \n\n ";
    }
    else
        cout<<"\n\nNo hay cheques por procesar.\n\n";
}

void Banco::ProcesarChequeR()
{
    ChequeRechazado ChequeCli;
    if (!ChequesRe.PilaVacia())
    {
        ChequesRe - &ChequeCli;
        cout<< "\n\nCheque rechazado procesado: ";
        ChequeCli.ImprimeDatos();
    }
    else
        cout<<"\n\nNo hay cheques rechazados por procesar.\n\n";
}

void Banco::RegistroCheque(Cheque ChequeCli)
{
    if(!Cheques.PilaLlena())
    {
        cout<< "\n\nRegistrando el cheque: ";
        ChequeCli.ImprimeDatos();
        Cheques + ChequeCli;
    }
    else
        cout<< "\n\nNo se pudo registrar el cheque por falta de espacio. \n\n";
}

void Banco::RegistroChequeR(ChequeRechazado ChequeCli)
{
    if (!ChequesRe.PilaLlena())
    {
        cout<< "\n\nRegistrando el cheque rechazado: ";
        ChequeCli.ImprimeDatos();
        ChequesRe + ChequeCli;
    }
    else
        cout<<"\n\nNo se pudo registrar el cheque rechazado por falta de espacio. \n\n ";
}


int menu();
void registrarCheque();
void procesarCheque();
void registrarChequeRechazado();
void procesarChequeRechazado();


int main()
{
    bool programaContinua = true;


    Banco MiBanco;

    do
    {
        switch(menu())
        {
            case 1: {
                system("cls");

                Cheque Uno (21321, "Bancomer", 21321, 231.23);
                MiBanco.RegistroCheque(Uno);
                system("pause");
                break;
                }
            case 2: {
                system("cls");
                MiBanco.ProcesarCheque();
                system("pause");
                break;
                }
            case 3:{
                system("cls");
                ChequeRechazado Dos (212321, "Banamex", 2561, 234.23);

                MiBanco.RegistroCheque(Dos);
                system("pause");
                break;
                }
            case 4: {
                system("cls");
                MiBanco.ProcesarChequeR();
                system("pause");
                break;
                }
            case 5:{
                system("cls");
                programaContinua = 0;
                break;
                }

            default: {
                system("cls");
                cout << "La opción seleccionada no existe\n\n";
                system("pause");
                break;
                }
        }
    }while(programaContinua);


    return 0;
}


int menu()
{
    int opcion;
    system("cls");
    cout << "Menu - Administracion de cheques" << endl;
    cout << "1. Registrar Cheque - (insertar)" << endl;
    cout << "2. Procesar Cheque - (eliminar)" << endl;
    cout << "3. Registrar Cheque Rechazado - (insertar)" << endl;
    cout << "4. Procesar Cheque Rechazado - (eliminar)" << endl;
    cout << "5. Salir" << endl;
    cout << "Elige tu opcion: ";
    cin >>opcion;
    return opcion;
}


