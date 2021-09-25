/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesActividad04.h
 * Author: jhenn
 *
 * Created on 25 de septiembre de 2021, 11:16 AM
 */

#ifndef FUNCIONESACTIVIDAD04_H
#define FUNCIONESACTIVIDAD04_H

#include <iostream>        
#include <fstream>
#define MAX 200
using namespace std;

void imprimirLinea(ofstream &, char, int);
void leerAlumnos(int * &, char ** &);
void imprimirAlumnos(int *, char **);
void guardarAlumnos(int*&, char **&, int, char[MAX][MAX], int*);
void leerCursos(int *codigos, char ***&cursos);

int buscarPosAlumno(int *, int );
void guardarCursos(char *** &, char [][MAX][7], int [], int );

void imprimirReporte(int * , char ** , char ***);

#endif /* FUNCIONESACTIVIDAD04_H */
