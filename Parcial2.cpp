#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define reservar_memoria (Cliente*)malloc(sizeof(Cliente))
typedef struct Cliente{
    char Nombre[50];
    char Tramite[50];
    char F_Nac[20];
    Cliente *siguiente;
}Cliente;
typedef struct Dia{
    char NombreDia[50];
    char TramiteDia[50];
    char AsesorDia[50];
    Dia *siguiente;
};
typedef struct Banco{

};

Cliente *primero=NULL;
Cliente *ultimo=NULL;

void InsertarClientes();
void EditarClientes();
void EliminarClientes();
void ListarClientes();
void menu();
int main(){
    menu();
    return 0;
}
void menu(){
    int opc;
    do{
        printf("\n*****\tMenu\t*****\n\n");
        printf("1. Insertar Clientes\n");
        printf("2. Editar Clientes\n");
        printf("3. Eliminar Clientes\n");
        printf("4. Listar Clientes\n");
        printf("0.Salir");
        printf("\nIngrese un opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                printf("\nInsertar Cliente\n");
                InsertarClientes();
                break;
            case 2:
                printf("\nEditar Cliente \n");
                EditarClientes();
                break;
            case 3:
                printf("\nEliminar Cliente\n");
                EliminarClientes();
                break;
            case 4:
                printf("\nListar Clientes \n");
                ListarClientes();
             case 0:
                printf("\n\nPrograma finalizado con exito \n\n");
                exit(0);
                break;
            default:
               printf("\n\nOpcion no valida \n\n");
               break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }while(opc!=0);
}
void InsertarClientes(){
    Cliente *aux=reservar_memoria;
    printf("\nIngrese Nombre: ");
    scanf("%s",aux->Nombre);
    printf("\nIngrese Tramite: ");
    scanf("%s",aux->Tramite);
    printf("\nIngrese Fecha Nacimiento: ");
    scanf("%s",aux->F_Nac);
    if(primero==NULL){
        primero=aux;
        primero->siguiente=NULL;
        ultimo=aux;
    }else{
        ultimo->siguiente=aux;
        aux->siguiente=NULL;
        ultimo=aux;
    }
    printf("\nDato ingresado con exito\n");
}
void EditarClientes(){
    Cliente *aux=reservar_memoria;
    aux=primero;
    char buscar[50];
    int encontrado=0;
    printf("\nIngrese el dato a modificar: ");
    scanf("%s",buscar);
    if(primero!=NULL){
        while(aux!=NULL){
            if(aux->Nombre==buscar){
                printf("\nEl dato ( %s ) fue encontrado",buscar);
                printf("\nIIngrese el nuevo dato: ");
                scanf("%s",aux->Nombre);
                scanf("%s",aux->Tramite);
                scanf("%s",aux->F_Nac);
                printf("\nDato modificado\n");
                encontrado=1;
            }
            aux=aux->siguiente;
        }
        if(encontrado==0){
            printf("\nEl dato no fue encontrado\n");
        }
    }else{
        printf("\nCola vacia\n");
    }
}
void EliminarClientes(){
    Cliente *aux=reservar_memoria;
    aux=primero;
    Cliente *anterior=reservar_memoria;
    anterior=NULL;
    char buscar[50];
    int encontrado=0;
    printf("\nIngrese el dato a eliminar: ");
    scanf("%s",buscar);
    if(primero!=NULL){
        while(aux!=NULL && encontrado!=1){
            if(aux->Nombre==buscar){
                if(aux==primero){
                    primero=primero->siguiente;
                }else{
                    anterior->siguiente=aux->siguiente;
                }
                printf("\nDato eliminado\n");
                encontrado=1;
            }
            anterior=aux;
            aux=aux->siguiente;
        }
        if(encontrado==0){
            printf("\nDato no encontrado\n");
        }else{
            free(anterior);
        }
    }else{
        printf("\nCola vacia\n");
    }
}
void ListarClientes(){
    Cliente *aux=reservar_memoria;
    aux=primero;
    if(primero!=NULL){
        while(aux!=NULL){
            printf("\n %s",aux->Nombre);
            printf("\n %s",aux->Tramite);
            printf("\n %s",aux->F_Nac);
            aux=aux->siguiente;
        }
    }else{
        printf("\n\nCola vacia");
    }
}
