#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CALIFICACIONES 5

void limpia(){
    while ((getchar()) != '\n' ) { }
}


struct Estudiante {
    char  nombre[50];
    int   edad;
    char  genero[20];
    int   calificaciones[MAX_CALIFICACIONES];
};


int main( ) {


    int numeroEstudiante;
    printf("Ingresa el numero de estudiantes");
    printf("\n");
    scanf("%i",&numeroEstudiante);
    printf( "Numero de estudiantes : %d\n", numeroEstudiante);

    limpia();

    struct Estudiante estudianteArreglo[numeroEstudiante];

    for (int j = 0; j < numeroEstudiante ; j++) {
        printf("Ingresa el nombre del estudiante\n");
        fgets(estudianteArreglo[j].nombre, 50, stdin);
        printf("Ingresa la edad de %s\n", estudianteArreglo[j].nombre);
        scanf("%i",&estudianteArreglo[j].edad);
        limpia();
        printf("Ingresa el genero de  %s\n",estudianteArreglo[j].nombre);
        fgets(estudianteArreglo[j].genero, 50, stdin);
        for (int i = 0; i < MAX_CALIFICACIONES; ++i) {
            printf("Ingresa la calificacion %i de %s\n",i, estudianteArreglo[j].nombre);
            scanf("%i",&estudianteArreglo[j].calificaciones[i]);
            limpia();
        }
    }


    for (int j = 0; j < numeroEstudiante ; j++) {
        printf("\n");
        printf( "nombre  : %s\n", estudianteArreglo[j].nombre);
        printf( "genero  : %s\n", estudianteArreglo[j].genero);
        printf( "edad  : %i\n", estudianteArreglo[j].edad);
        for (int i = 0; i < MAX_CALIFICACIONES ; ++i) {
            printf("calificacion : %i \n", estudianteArreglo[j].calificaciones[i]);

        }

    }


    return 0;
}