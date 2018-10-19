#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct GSeidel
{
   float A[10][10], b[10], xo[10], x[10];
   int n,i,j,k,I,dom;

   float restbr[10],resmult[10],res[10], multAx[10], Ax[10], aux, B;

void Valores() //1. Ingresa los vlaores de los elementos de A,b, y xo
{
  cout << "\nIngresa la dimensión N de la matriz cuadrada A: "<< endl; //Pide la dimension tanto de la matriz, como de los vectores
  cin>>n;

  cout <<  "\nIngresa la matriz A: " << endl; //Pide los elementos de la matriz A.
   for(i=0;i<n;i++){
       for (j=0;j<n;j++){
           cout << "Ingresa el elemento a" << i+1 << j+1 << " de la matriz A: " << endl;
           cin >> A[i][j];
       }
   }

cout << "\nIngresa los elementos de b: " << endl; //Elementos del arreglo b
for(i=0;i<n;i++){
        cout << "Ingresa el elemento b" << i+1 << " de la matriz b: " << endl;
        cin >> b[i];
}

cout << "\nIngresa los elementos de xo: " << endl; //Elementos del arreglo xo
for(i=0;i<n;i++){
        cout << "Ingresa el elemento x" << i+1 << " de la matriz xo: " << endl;
        cin >> xo[i];
      }
}

void Dominante () //Convierte la matriz en diagonal dominante
{
  float suma, suma2,aux;
  int r=0,m;

  //Combirtiendola en diagonal Dominante
  for(i=0;i<n;i++)
  {
    suma=0;
    for(j=0;j<n;j++)
    {
      if (i!=j)
      {
        suma= suma + abs(A[i][j]);
      }
    }

    m=0;
    r=i;
    if(suma>abs(A[i][i]))//El renglon no cumple así que se cambia orden
    {
      for(int l=0;l<n;l++)//Este for solo es para que se repitan las lineas la n cantidad de veces.
      {//Aquí se hacen todas las posibles combinaciones para ver cual digito es el que iria en la diagonal
        suma2=0;
        aux=0;
        for(int k=0;k<n;k++)
        {
          if(k!=m)
            suma2= suma2 + abs(A[i][k]);
        }

        if(abs(A[i][m])>suma2)
        {
          for(i=0;i<n;i++)
          {
             aux=A[i][r];
             A[i][r]=A[i][m];
             A[i][m]=aux;
          }
        }
        m++;

      }

    }

  }
}

void Revisar (int op) //Funcion que revisa si una matriz es dominante
{
  float suma;
  int contador=0;

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      suma=0;
      if (i!=j)
      {
        suma = suma + abs(A[i][j]);
      }
    }

    if(suma>abs(A[i][i]))
    {
    //cout<<"\nRenglon " << i+1 << ": DOMINANTE"<< endl;
    contador ++;

    if(op==1)
    {
      cout<< "\nLa matriz NO es dominante." << endl;
      Dominante();
      cout<<"\nLa Matriz despues del cambio es:"<<endl;
      Imprimir(A);
    }
    else
    {
      cout<<"\nLa matriz NO se puede convertir en dominante."<<endl;
      cout<<"\nNo se puede aplicar el metodo."<<endl;
      dom=0;
    }
  }
}


if (contador==3)
{
  cout <<"\nLa Matriz es DOMINANTE." << endl;
  dom=1;
  if (op==2)
  {
    Imprimir(A);
  }
}

}

void Imprimir (float M[][10]) //Imprime matrices cuadradas
{
  for(i=0;i<n;i++){
       cout << "|";
       for (j=0;j<n;j++){
           cout << " " << M[i][j] << " ";
       }
       cout << "|" << endl;
   }

}

void Imprimir2 (float M[10]) //Imprime arreglos de [1][n]
{
   for(i=0;i<n;i++){
           cout << "| " << M[i]<< " |" <<endl;
     }
   }

void Iteraciones() //Pide el numero de iteraciones, y realiza las operaciones para obtener x1,x2,x3,...xn
{
  int contador=0;
  float Xo=100, X=0;

  while (abs(Xo-X)>0.00001)
  {
    contador ++;
    for (i=0; i<n;i++)
    {
      xo[i]= x[i];
      x[i]=(b[i]/A[i][i]);  //despejar las x1,x2,x3, .... xn

      for (j=0; j<n; j++)
      {
        if (j!=i)
        {
          x[i]= x[i] - ((A[i][j]/A[i][i])*xo[j]);
        }
      }
    }

  Xo=0;
  X=0;

  for(i=0;i<n;i++)
  {
    Xo= Xo + xo[i];
    X= X + x[i];
  }

 }


  cout << "Tu solución es: "<< endl;
  for (i=0; i<n; i++)
  {
  cout<< "x"<<i+1<<"="<<x[i]<<endl;
  }

  cout << "Se hicieron " << contador << " iteraciones." << endl;
}


};

int main (void)
{
  GSeidel gs;

  gs.Valores();

  cout << "La Matriz A es: " << endl;
  gs.Imprimir(gs.A);

  cout << "b es : " << endl;
  gs.Imprimir2(gs.b);

  gs.Revisar(1);
  if(gs.dom!=0)
  {
    gs.Revisar(2);
  }

//if (gs.dom==1)
//{
  gs.Iteraciones();
//}

/*else
{
cout<<"\nNo se puede aplicar el metodo. No tiene convergencia."<<endl;
}*/

  return 0;
}

//http://executecodes.blogspot.com/2017/11/c-program-to-implement-gauss-seidel.html
