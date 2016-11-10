#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
/*constantes*/
  float L;
  float l;
  float d;
  float h;
  float V;
  float N;
  FILE *in;
  int i;
  int j;
  int z;
  char placas[100] = "placas.csv";
  /*char Ex[100] = "Ex.csv";
    char Ey[100] = "Ey.csv";*/
  int n;
  L = 5.0;
  l = 2.0;
  d = 1.0;
  h = 0.02;
  V = 100.0;
  N = 2 * pow((L/h),2);
  n = L/h;

  /*Arreglos(i,j)*/
  float matriz [n][n];
  for (i = 0;  i < n; i++){
    for ( j = 0; j < n; j++){
      matriz[i][j] = 0.0;
      if (j * h == (L-d)/2){
	if (i*h >= (L-l)/2 && i*h <= (L+l)/2){
	  matriz [i][j] = V/2;	  
	}
      }
      if (j * h == (L+d)/2){
	if (i * h >= (L-l)/2 && i * h <= (L+l)/2){
	  matriz [i][j] = -V/2;	  
	}
      } 
    }
  }
  
  /*Se necesitan dos arreglos para solucionar (Viejo y Nuuevo)*/
  float nueva [n][n];
  for (i = 0;  i < n; i++){
    for ( j = 0; j < n; j++){
      nueva[i][j] = matriz[i][j];
    }
  }
  for (z = 1; z = N; z++){
    for (i = 1; i < n-1; i++){
      for (j = 1; j <= n-1; j++){
	if (matriz [i][j] < V/2 && matriz [i][j] > -V/2){ 
	  nueva [i][j] = (matriz[i-1][j]+matriz[i+1][j]+matriz[i][j-1]+matriz[i][j+1])/4;
	  matriz[i][j] = nueva [i][j];
	}
      }
    }
  }
 
      

  in = fopen(placas,"w");
  for (i = 0;  i < n; i++){
    for ( j = 0; j < n; j++){
      fprintf (in, "%f, ", matriz[j][i]);
    }
    fprintf(in, "\n");
  }
  /*Calculo del Campo Electrico,  Ex y Ey
  float Ex[n-1][n-1];
  float Ey[n-1][n-1];
  for (i = 0;  i < n-1; i++){
    for ( j = 0; j < n-1; j++){
      Ex[i][j] = (matriz [i+1][j]-matriz[i][j])/n;
    }
  }
   for (j = 0;  j < n-1; j++){
    for ( i = 0; i < n-1; i++){
      Ey[i][j] = (matriz [i][j+1]-matriz[i][j])/n;
    }
  }
   in = fopen(Ex,"w");
   for (i = 0;  i < n; i++){
     for ( j = 0; j < n; j++){
       fprintf (in, "%f, ", Ex[j][i]);
     }
     fprintf(in, "\n");
   }
   in = fopen(Ey,"w");
  for (i = 0;  i < n; i++){
    for ( j = 0; j < n; j++){
      fprintf (in, "%f, ", Ey[j][i]);
    }
    fprintf(in, "\n");
    }*/
  return 0;
}
