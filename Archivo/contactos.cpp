#include <iostream>
using namespace std;
#include <fstream>

string nombrearchivo;
void escribirArchivo();
void leerArchivo();

int main()
{
  int op;
  do{
    cout<<"Opciones"<<endl;
    cout<<"1. Ingresar datos"<<endl;
    cout<<"2. Mostrar datos"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"Ingrese el numero de su opcion: ";
    cin>>op;
    switch(op){
      case 1:
      cin.ignore();
      escribirArchivo();
      break;
      case 2:
      leerArchivo();
      break;
    }
  }while(op!=0);
  cout<<"\nGracias por su colaboracion!"<<endl;
}


void escribirArchivo()
{
  string nombre;
  string apellido;
  string carrera;
  int edad;
  char r;
  ofstream archivoprueba;
  cout<<"Ingrese el nombre del archivo: ";
  getline(cin,nombrearchivo);
  archivoprueba.open(nombrearchivo.c_str(),ios::out);
  do
  {
    cout<<"\t Ingrese el nombre: ";
    getline(cin,nombre);
    cout<<"\t Ingrese el apellido: ";
    getline(cin,apellido);
    cout<<"\t Ingrese la carrera: ";
    getline(cin,carrera);
    cout<<"\t Ingrese la edad: ";
    cin>>edad;
    archivoprueba<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
    cout<<"Desea ingresar otro contacto (s/n): ";
    cin>>r;
    cin.ignore();

  }while(r=='S' || r=='s');
  archivoprueba.close();
}


void leerArchivo()
{
  string nombre;
  string apellido;
  string carrera;
  int edad;
  ifstream archivolectura(nombrearchivo,ios::in);
  if (archivolectura.fail())
  {
    cout<<"EL ARCHIVO NO SE PUDO LEER, O EL MISMO NO SE ENCUENTRA CREADO";
  }
  else
  {
    while(!archivolectura.eof())
    {

    archivolectura>>nombre>>apellido>>carrera>>edad;

      if(!archivolectura.eof())
            {
              cout<<"********************************\n";
              cout<<"-> Nombre:\t"<<nombre<<endl;
              cout<<"-> Apellido:\t"<<apellido<<endl;
              cout<<"-> Carrera:\t"<<carrera<<endl;
              cout<<"-> Edad:\t"<<edad<<endl;
              cout<<"********************************\n";
            }

    }

  }
    archivolectura.close();
}
