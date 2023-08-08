#ifndef CHEQUES_H_INCLUDED
#define CHEQUES_H_INCLUDED

#include "Pila.h"


using namespace std;

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
        void establecerNumero(int Numerox){Numero = Numerox;};
        void establecerCuentaADepositar(int CuentaADepositarx){CuentaADepositar = CuentaADepositarx;};
        void establecerBanco(string Bancox){strcpy(Banco, Bancox.c_str());};
        void establcerMonto(double Montox){Monto = Montox;};
        int obtenerNumero() const{return Numero;};
        int obtenerCuentaADepositar() const{return CuentaADepositar;};
        string obtenerBanco() const{return Banco;};
        double obtenerMonto() const{return Monto;};
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
        void establecerCargo(double Cargox){Cargo = Cargox;};
        double dameCargo(){return Cargo;};
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
    else{
        cout<<"\n\nNo hay cheques por procesar.\n\n";
        }


}


//faltacompletar
void Banco::ProcesarChequeR()
{
    ChequeRechazado ChequeCli;
    if (!ChequesRe.PilaVacia())
    {
        ChequesRe - &ChequeCli;
        cout<< "\n\nCheque rechazado procesado: ";
        ChequeCli.ImprimeDatos();
    }
    else{
        cout<<"\n\nNo hay cheques rechazados por procesar.\n\n";
        }
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



#endif // CHEQUES_H_INCLUDED
