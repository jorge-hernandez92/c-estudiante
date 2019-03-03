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
    int   promedio;
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
        int suma=0;
        printf("Ingresa el nombre del estudiante\n");
        fgets(estudianteArreglo[j].nombre, 50, stdin);
        printf("Ingresa la edad de %s\n", estudianteArreglo[j].nombre);
        scanf("%i",&estudianteArreglo[j].edad);
        limpia();
        printf("Ingresa el genero de  %s\n",estudianteArreglo[j].nombre);
        fgets(estudianteArreglo[j].genero, 50, stdin);
        for (int i = 0; i < MAX_CALIFICACIONES; i++) {
            printf("Ingresa la calificacion %i de %s\n", i, estudianteArreglo[j].nombre);
            scanf("%i", &estudianteArreglo[j].calificaciones[i]);
            limpia();
            suma = suma + estudianteArreglo[j].calificaciones[i];
        }
        estudianteArreglo[j].promedio = suma / MAX_CALIFICACIONES;
    }

    // variable para posision del promedio mas alto
    int posicionDelMasAlto = 0;
    for (int k = 0; k< numeroEstudiante; ++k) {
        if(estudianteArreglo[posicionDelMasAlto].promedio<estudianteArreglo[k].promedio) {
            posicionDelMasAlto = k;
        }
    }

    for (int j = 0; j < numeroEstudiante ; j++) {
        printf("\n");
        printf( "nombre  : %s\n", estudianteArreglo[j].nombre);
        printf( "genero  : %s\n", estudianteArreglo[j].genero);
        printf( "edad  : %i\n", estudianteArreglo[j].edad);
        for (int i = 0; i < MAX_CALIFICACIONES ; i++) {
            printf("calificacion : %i \n", estudianteArreglo[j].calificaciones[i]);
        }
        printf("PROMEDIO : %i\n", estudianteArreglo[j].promedio);
    }
    printf("ALUMNOS DEL PROMEMDIO MAS ALTO:\n");

    printf("Nombre: %s\n",estudianteArreglo[posicionDelMasAlto].nombre);
    printf("Edad: %i\n",estudianteArreglo[posicionDelMasAlto].edad);
    printf("Genero: %s\n",estudianteArreglo[posicionDelMasAlto].genero);
    printf("promedio: %i", estudianteArreglo[posicionDelMasAlto].promedio);


    return 0;
}