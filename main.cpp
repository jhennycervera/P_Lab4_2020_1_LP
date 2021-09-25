/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 25 de septiembre de 2021, 10:58 AM
 */


#include "FuncionesActividad04.h"

int main(int argc, char** argv) {
    
    char **nombres, ***cursos;
    int *codigos;
    
    leerAlumnos(codigos, nombres);
    imprimirAlumnos(codigos, nombres);
    leerCursos(codigos, cursos);
    imprimirReporte(codigos, nombres, cursos);
    
    return 0;
}

