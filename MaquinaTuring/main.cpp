#include <iostream>
#include <map>
using namespace std;
//cinta
map<int, char>cinta;
int mL=0, mR=0, cabezal,j ,k, i,x=0, z=0;
char B=' ', aux;

//validacion
bool sigma (char c){
    if((c >= 'a' && c <='z') || (c >= 'A' && c <='Z') || (c >= '0' && c <='9')){return true;}
    return false;
    }

    //escribir en cinta
void escribe( char c){

    cinta[cabezal]=c;
}

//leer cinta
char leer(){

    return cinta[cabezal];
}
//desplazar a la derecha
void R(){
    cabezal+=1;
}
//Maquina R si es primera ve que se visita  agrega un Blanco
void R_()
{
    R();

    if(cabezal>=mR)
    {
            escribe(B);
            mR++;
    }
}
//maquina L
void L()
{
    cabezal-=1;
    if(cabezal+1==mL)
    {
        escribe(B);
        mL--;
    }
}
//se mueve a la derecha asa la posicion
bool Rn(int p)
{
    int i=1;
    while(i<=p)
    {
        R_();
        i++;
        j++;
    }

    return true;
}
// semueve a la izquierda hasta laposicion
bool Ln(int p)
{
    int i=1;
    while(i<=p)
    {
        L();
        i++;
        k--;
    }
    return true;
}
// acomoda el cabezal a x punto
void acomoda(int n){
    cabezal=n;
}
// imprime el contenido de la cinta para encolar
void imprime(int n)
{
    map<int, char>::iterator it;
    for(it=cinta.begin(); it!=cinta.end(); it++)
    {
        if(it->first!=n)
            cout<<it->second;
        else if(it->first ==0)
            cout<<"."<<it->second;
        else
            cout<<it->second<<".";


    }
    cout<<endl;

}
//imprime el contenido de la cinta para desencolar
void imprime2()
{
    map<int, char>::iterator it;


    for(it=cinta.begin(); it!=cinta.end(); it++)
    {
        if(it->first > 0 && it->second==B )
            cout<<"."<<it->second;
         else
            cout<<it->second;
    }
    cout<<endl;

}
//menu de opciones
void menu(){

    cout<<" -------------------------"<<endl;
    cout<<"|                         |"<<endl;
    cout<<"| Selecciona una opcion   |"<<endl;
    cout<<"| 1. Ingresar Dato        |"<<endl;
    cout<<"| 2. Extraer Dato         |"<<endl;
    cout<<"| 3. Terminar Corrida     |"<<endl;
    cout<<"|                         |"<<endl;
    cout<<" -------------------------"<<endl;
    cout <<endl<<endl;

}
//metodo que encola
void dequeue(char c)
{
    acomoda(mL);
    Ln(1);
    if(leer() == B)
        escribe(c);
        x--;
}
//desencola primer elemento de la cinta
char saca(){
    char c;
    c=cinta[1];
    return c;
}

// agrega un blanco  en el lugar que desencolo
void blanco(){
    cinta[1] = ' ';
}

//encolar
void enqueue(char c)
{
    acomoda(x);
    Rn(1);
    if(leer() == B)
        escribe(c);
}
//maquina shift a la derecha
void recorre(){

    char a1,a2;
    int n=mR;

    for (i=1;i<n;i++){
        acomoda(i);
        a1=leer();
        R();
        a2 =leer();
        if(a1==B && a2!=B){
            L();
            escribe(a2);
            R();
            escribe(B);
        imprime2();
        }

    }
 imprime(0);
}

int main()
{
    cinta[0]='@';

    char caracter, opcion;
    int stop;


     do{

        menu();
        cout<<"opcion$ ";
        cin>>opcion;
        if (!(opcion >= '0' && opcion <='3'))
            cout<<"Opcion Invalida"<<endl;
        else{
            switch(opcion){
            case '1': {
                cout<< "dato$ ";
                cin>> caracter;
                cout<<endl;

                imprime(x);
                if(sigma(caracter)){
                    enqueue(caracter);
                    x++;
                    imprime(0);
                }
                else{
                    cout<<caracter<<" no pertenece al alfabeto ";
                }
                cout<<endl;
            }break;
            case '2': {
                cout<<endl;
                acomoda(0);
                aux=saca();
                if(sigma(aux)){
                    blanco();
                    dequeue(aux);
                    imprime2();
                    recorre();
                    cout<<endl;
                }
                else
                    cout<<"cinta vacia "<<endl<<endl;
            }break;
            case '3': {
                cout<<endl;
                cout<<"Corrida Finalizada"<<endl;
                stop = 3;
            }break;
            default : {

                cout<<"Opcion Invalida!!"<<endl;
            }break;
            }
        }
    }while(stop!=3);

    return 0;
}
