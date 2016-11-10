#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main (void)
{
/*Constantes*/
  float T;
  float d;
  float L;
  float c;
  float t;
  float dt;
  float dl;
  int nx;
  int nt;
  float dx;
  float w;
  int i;
  int j;
  char cuerda[100] = "cuerda.csv";
  FILE *in;
  T = 40.0;
  d = 10.0;
  L = 100;
  c = sqrt(T/d);
  nx = 10;
  nt = 10;
  dx = L/(nx-1);
  t = 200.0;
  dt = pow((t/nt),2);
  dl = pow((L/nx),2);
  w = pow(c,2)*dt/dl;
    
  /*Arreglos (x = i * dx)*/
  float matriz [nt][nx];
   for (i = 0;  i < nt; i++){
    for ( j = 0; j < nx; j++){
      matriz[i][j] = 0.0;
    }
   }
  /*Primera Linea*/
  for (j = 1; j < nx-1; j++){
    if (j*dx <= 0.8 * L){
      matriz[j][0] = 1.25 *j*dx/L;
    }
    else {
      matriz [j][0] = 5 - (5*j*dx/L);
    }
  }

  /*Segunda Linea*/
  for (j = 1; j < nx-1; j++){
    matriz[j][1] = (w * (matriz[j-1][0]-2*matriz[j][0]+matriz[j+1][0]))+2*matriz[j][0];
  }
  /*El resto de la Matriz*/
  for (j = 2;  j < nt; j++){
    for ( i = 1; i < nx-1; i++){
     matriz[i][j] = (w * (matriz[i-1][j-1]-2*matriz[i-1][j]+matriz[i-1][j+1]))+2*matriz[i-1][j]+matriz[i-2][j];
    }
   }
   in = fopen(cuerda,"w");
   for (i = 0;  i < nt; i++){
     for ( j = 0; j < nx; j++){
       fprintf (in, "%f, ", matriz[j][i]);
     }
     fprintf(in, "\n");
   }
  return (0);
}

