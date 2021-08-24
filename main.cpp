#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void RegistroContacto(void);
int BuscarPorId(int);
int BuscarPorNombre(char*);
void MostrarContacto(int);
void EditarContacto(int);
int EliminarContacto(int);
void Menu(void);

int index=1;

struct contactos{
   int id;
   char nombre[50];
   char direccion[50];
   char email[50];
}cts[5];

int main() {
   int opc=0;

   do{
      system("cls");
      Menu();
      cout<<"\n\tDesea Continuar?"
            "\n1- Si"
            "\n2- No "<<endl<<"\tRespuesta: ";
      cin>>opc;

   } while(opc==1);

   cout<<"\nHasta Pronto. . . "<<endl;

   return 0;
}

void Menu(){
   int opcion=0, id=0; char nombre[50];

   cout<<"\t\tMENU:"
         "\n1- Registrar un Contacto"
         "\n2- Buscar por ID"
         "\n3- Buscar por Nombre"
         "\n4- Editar Contacto"
         "\n5- Eliminar Contacto"<<endl;

   cout<<"\nIngrese una Opcion del Menu: ";
   cin>>opcion;

   switch(opcion){
      case 1:
            RegistroContacto();
            break;

      case 2:
            cout<<"\nIngrese el ID a Buscar: ";
            cin>>id;
            cout<<"\n";
            MostrarContacto(BuscarPorId(id));
            break;

      case 3:
            cout<<"\nIngrese el Nombre a Buscar: ";
            cin>>nombre;
            cout<<"\n";
            MostrarContacto(BuscarPorNombre(nombre));
            break;

      case 4:
            cout<<"Ingrese el ID del Contacto a Editar: ";
            cin>>nombre;
            break;

      case 5:
            cout<<"Ingrese el ID del Contacto a Eliminar: ";
            cin>>id;
            EliminarContacto(id);
            break;

      default:
            cout<<"Error: Ingrese una Opcion del Menu. . . "<<endl;
   }

}

void RegistroContacto(){
   cts[index].id=index;

   fflush(stdin);
   cout<<"\nIngrese el Nombre del Contacto: ";
   gets(cts[index].nombre);
   cout<<"Ingrese Direccion del Contacto: ";
   gets(cts[index].direccion);
   cout<<"Ingrese Email del Contacto: ";
   gets(cts[index].email); cout<<"\n";

   index++;
}

int BuscarPorId(int id){
   bool ban=false; int x=0,posicion=-1;
   while(x<index && ban==false){
   if(cts[x].id==id){
      ban=true;
      posicion=x;
   }
      x++;
   }
   return posicion;
}

int BuscarPorNombre(char* nombre){
   bool ban=false;
   int x=0,posicion=0;

   while(ban==false && x<index){
      if(strcmp(nombre,cts[x].nombre)==0){
         ban=true;
         posicion=x;
      }
      x++;
   }
   return posicion;
}

int EditarContacto(){

}

int EliminarContacto(int posicion){
   int cantidad=5;
   for(posicion ; posicion<cantidad ; posicion++){
      cts[posicion].id = cts[posicion+1].id;

      strcpy(cts[posicion].nombre,cts[posicion+1].nombre);
      strcpy(cts[posicion].direccion,cts[posicion+1].direccion);
      strcpy(cts[posicion].email,cts[posicion+1].email);
   }
   cantidad--;
   cout<<"\nContacto Eliminado con Exito. . ."<<endl;
}

void MostrarContacto(int posicion){

cout<<"Nombre del Contacto: "<<cts[posicion].nombre<<endl;
cout<<"Direccion del Contacto: "<<cts[posicion].direccion<<endl;
cout<<"Email del Contacto: "<<cts[posicion].email<<endl;

}
