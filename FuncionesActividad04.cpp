/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



/* 
 * File:   FuncionesActividad04.cpp
 * Author: jhenn
 * Codigo: 20182841
 * Created on 25 de septiembre de 2021, 11:16 AM
 */

#include "FuncionesActividad04.h"
#include <iostream>        
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define MAX 200

void imprimirLinea(ofstream &Rep, char c, int cant) {
    Rep.fill(c);
    Rep << setw(cant) << c << endl;
    Rep.fill(' ');
}

void leerAlumnos(int * &codigos, char ** &nombres) { //no olvidar por Referencia para modificar hacia donde apunta

    ifstream archAlum("Alumnos.csv", ios::in);
    if (!archAlum) {
        cout << "No se puede abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    int numAlum = 0, buffCod[MAX];
    char buffNombres[MAX][MAX], tipo, espe[MAX], facultad[4]; // 200 nombres    
    while (1) {
        archAlum>>tipo;
        if (archAlum.eof()) break;
        archAlum.get(); //coma
        archAlum >> buffCod[numAlum]; //CODIGO
        archAlum.get(); //coma
        archAlum.getline(buffNombres[numAlum], MAX, ','); //NOMBRE  
        archAlum.getline(espe, MAX, ',');
        archAlum.getline(facultad, MAX);
        numAlum++;
    }

    guardarAlumnos(codigos, nombres, numAlum, buffNombres, buffCod);

}

void guardarAlumnos(int*&codigos, char **&nombres, int numAlum, char buffNombres[MAX][MAX], int * buffCod) { //PREG: porq no se puede char *buffNombres[MAX] o char** buff

    buffCod[numAlum] = -1; //flag 
    numAlum++;

    codigos = new int[numAlum];
    nombres = new char*[numAlum];

    for (int i = 0; i < numAlum; i++) {
        codigos[i] = buffCod[i];
        nombres[i] = new char[ strlen(buffNombres[i]) + 1 ];
        strcpy(nombres[i], buffNombres[i]);
    }
}

void imprimirAlumnos(int * codigos, char **nombres) {

    for (int i = 0; codigos[i] != -1; i++) {
        cout << left << setw(20) << codigos[i] << nombres[i] << endl;
    }

}

void leerCursos(int *codigos, char ***&cursos) {
    int numAlum;
    for (numAlum = 0; codigos[numAlum] != -1; numAlum++);

    ifstream archCursos("Cursos.csv", ios::in);
    if (!archCursos) {
        cout << "No se puede abrir el archivo Cursos.csv" << endl;
        exit(1);
    }

    int cantCursAlum[numAlum];  //arreglo que guarda la cantidad de cuersos por alumno; //incializar con 0
    for(int i=0;i<numAlum;i++){
        cantCursAlum[i]=0;
    }
    
    char buffCursos[numAlum][MAX][7]; //cada alumno tiene MAX cantidad de cursos y cada curso 7 caracteres

    int codAlum, nota, num=0;
    char codCurso[7], aux[20], c;

    while (1) {
        archCursos>>codAlum;
        if (archCursos.eof()) break;
        c=archCursos.get(); //Coma
        archCursos.getline(codCurso, 7, ','); //CODIGO CURSO
        archCursos>>nota;
        c=archCursos.get(); //Coma
        archCursos.getline(aux, 20, ',');
        archCursos.getline(aux, 20, ',');
        archCursos>>c;
        cout<<"-----"<<num++<<endl<<endl;
        if (nota > 10) {
            int pos = buscarPosAlumno(codigos, codAlum);
            if (pos != -1) {
                strcpy(buffCursos[pos][cantCursAlum[pos]], codCurso);
                cout<<pos<<" "<<cantCursAlum[pos]<<endl;
                cantCursAlum[pos]++;
                
            }
        }

    }
    guardarCursos(cursos, buffCursos, cantCursAlum, numAlum);
}

int buscarPosAlumno(int *codigos, int codAlum) {

    for (int i = 0; codigos[i] != -1; i++) {
        if (codAlum == codigos[i]) return i;
    }

    return -1;
}

void guardarCursos(char *** &cursos, char buffCursos[][MAX][7], int cantCursAlum[], int numAlum) {

    cursos = new char**[numAlum];

    for (int i = 0; i < numAlum; i++) { //crear memoria para cd alumno
        cursos[i] = new char* [cantCursAlum[i] + 1]; // cantCursos + 1 porq voy a apuntar a null como flag de terminacion para cd cursos

        for (int j = 0; i < cantCursAlum[i]; j++) { //Recorrer para cada curso
            //int tam = strlen( buffCursos[i][j]);   //no es necesario si sabemos que es 7 
            cursos[i][j] = new char[7];
            strcpy(cursos[i][j], buffCursos[i][j]);

        }
    }
    //agregar el nullptro al final de cada curso  
    for (int i = 0; i < numAlum; i++) {
        cursos[i][cantCursAlum[i]] = nullptr;
    }





}

void imprimirReporte(int * codigos,char **  nombres, char ***cursos){
    
    for(int i=0; codigos[i]!= -1; i++){  //cada alumno
        
        cout<<left<<setw(10)<<"Codigo:"<<setw(10)<<codigos[i]<<setw(10)<<"Nombre:"<<nombres[i]<<endl;
        cout<<setw(20)<<"Cursos Aprobados:";
        
        for(int j=0; cursos[i][j]!=nullptr; j++){
            cout<<setw(15)<<cursos[i][j];              
        }
        cout<<endl;
        
    }
    
}