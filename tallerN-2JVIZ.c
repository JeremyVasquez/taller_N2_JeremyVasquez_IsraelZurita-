#include <stdio.h>
 
#define ESTUDIANTES 5
#define ASIGNATURAS 3
 
int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    int i, j;
    float sumaEst, sumaAsig;
    float promedioEst[ESTUDIANTES], promedioAsig[ASIGNATURAS];
    float maxEst[ESTUDIANTES], minEst[ESTUDIANTES];
    float maxAsig[ASIGNATURAS], minAsig[ASIGNATURAS];
    int aprobados[ASIGNATURAS] = {0};
    int reprobados[ASIGNATURAS] = {0};
 
    for(i = 0; i < ESTUDIANTES; i++) {
        printf("Ingresar calificaciones para estudiante %d:\n", i+1);
        for(j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("  Asignatura %d (0-10): ", j+1);
                scanf("%f", &calificaciones[i][j]);
                if(calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("  Nota inválida, debe estar entre 0 y 10.\n");
                }
            } while(calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }
 
    for(i = 0; i < ESTUDIANTES; i++) {
        maxEst[i] = calificaciones[i][0];
        minEst[i] = calificaciones[i][0];
    }
    for(j = 0; j < ASIGNATURAS; j++) {
        maxAsig[j] = calificaciones[0][j];
        minAsig[j] = calificaciones[0][j];
    }
 
    for(i = 0; i < ESTUDIANTES; i++) {
        sumaEst = 0;
        for(j = 0; j < ASIGNATURAS; j++) {
            float nota = calificaciones[i][j];
            sumaEst += nota;
            if(nota > maxEst[i]) maxEst[i] = nota;
            if(nota < minEst[i]) minEst[i] = nota;
        }
        promedioEst[i] = sumaEst / ASIGNATURAS;
    }
 
    for(j = 0; j < ASIGNATURAS; j++) {
        sumaAsig = 0;
        for(i = 0; i < ESTUDIANTES; i++) {
            float nota = calificaciones[i][j];
            sumaAsig += nota;
            if(nota > maxAsig[j]) maxAsig[j] = nota;
            if(nota < minAsig[j]) minAsig[j] = nota;
            if(nota >= 6) aprobados[j]++;
            else reprobados[j]++;
        }
        promedioAsig[j] = sumaAsig / ESTUDIANTES;
    }
 
    printf("\n--- Resultados ---\n");
 
    for(i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d - Promedio: %.2f, Max: %.2f, Min: %.2f\n", i+1, promedioEst[i], maxEst[i], minEst[i]);
    }
 
    printf("\nPor Asignatura:\n");
    for(j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d - Promedio: %.2f, Max: %.2f, Min: %.2f, Aprobados: %d, Reprobados: %d\n",
            j+1, promedioAsig[j], maxAsig[j], minAsig[j], aprobados[j], reprobados[j]);
    }
 
    return 0;
}