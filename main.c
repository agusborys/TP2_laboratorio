#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#define C 20




int main()
{
    char seguir='s';
    char auxopcion[5];
    EPersona personas[C];
    char auxedad[10];
    char auxdni[30];
    char auxnom[100];
    int flag, opcion, mined = 0, maxed = 100;
    char respuesta;
    int indice = 0;

    init(personas, C);
    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("\nElija una opcion<1-5>: ");
        fflush(stdin);
        gets(auxopcion);
        while(validar_cadena(auxopcion, 5)==1 || validar_entero(auxopcion)==1){
            printf("Error, ingrese opcion valida: ");
            fflush(stdin);
            gets(auxopcion);
        }
        opcion = atoi(auxopcion);


        switch(opcion)
        {
            case 1:         //Agregar persona
                flag = 0;
                for(int i =0; i<C; i++){
                        if(personas[i].estado==0){
                            printf("\nIngrese Nombre: ");
                            fflush(stdin);
                            gets(auxnom);
                            while(validar_cadena(auxnom, 50)==1 || validar_char(auxnom)==1){
                                printf("\nError, ingrese nombre menor a 50 caracteres y sin numeros: ");
                                fflush(stdin);
                                gets(auxnom);
                            }
                            pasaje_nombre(auxnom);
                            strcpy(personas[i].nombre, auxnom);
                            printf("\nIngrese edad: ");
                            fflush(stdin);
                            gets(auxedad);
                            while(validar_edad(auxedad,mined,maxed)==1 || validar_entero(auxedad)==1 || validar_cadena(auxedad, 10) ){
                                printf("\nError, la edad debe: estar entre %d y %d, no contener letras y ser menor a 10 caracteres.\nReingrese: ", mined, maxed);
                                fflush(stdin);
                                gets(auxedad);
                            }
                            personas[i].edad = atoi(auxedad);
                            printf("\nIngrese DNI: ");
                            fflush(stdin);
                            gets(auxdni);
                            while(validar_entero(auxdni)==1 || atoi(auxdni)<1 || validar_cadena(auxdni, 30) || coincidenciaDNI(personas, auxdni, C)==1){
                                printf("\nError, el DNI debe ser: unico, mayor a 0, sin letras y menor a 29 caracteres.\nReingrese:  ");
                                fflush(stdin);
                                gets(auxdni);
                            }
                            personas[i].dni = atoi(auxdni);
                            personas[i].estado = 1;
                            flag = 1;
                            break;
                        }
                }
                if(flag == 0){
                    printf("\nNo Hay espacio!\n");
                }
                funcion_pausa();
                break;
            case 2:         //Borrar persona
                printf("\nIngrese DNI a eliminar: ");
                fflush(stdin);
                gets(auxdni);
                while(validar_entero(auxdni)==1 || atoi(auxdni)<1){
                    printf("\nError, ingrese un DNI valido: ");
                    fflush(stdin);
                    gets(auxdni);
                }
                indice = buscarPorDni(personas, auxdni, C);
                if(indice!= -1){
                        printf("%d\t-\t%s\t-\t%d",personas[indice].dni,personas[indice].nombre,personas[indice].edad);
                        printf("\nEsta seguro que desea borrar esta persona? (s/n):");
                        respuesta = getche();
                        if(respuesta == 's'){
                            personas[indice].estado = 0;
                            printf("\nPersona eliminada!\n");

                        }
                        else{
                            printf("\nAccion cancelada!\n");
                        }
                        funcion_pausa();
                        break;
                    }
                else{
                    printf("\nDNI inexistente\n");
                }
                funcion_pausa();
                break;
            case 3:
                ordenarPorNombre(personas, C);
                listar(personas, C);
                funcion_pausa();
                break;
            case 4:
                GraficoHorizontal(personas, C);
                funcion_pausa();
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error. Ingrese opcion entre 1 y 5\n");
                system("pause");
                break;
        }
    }

    return 0;
}



