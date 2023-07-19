/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct datos_de_cama
{
  int anho, mes, dia, camas_tot, camas_ocup, camas_disp;
};

void
calcula_disponibilidad (datos_de_cama lista[], int cantidad)
{
  ofstream narchivo;
  narchivo.open ("camas disponibles.txt", ios::out);
  for (int cont = 0; cont < cantidad; cont++)
    {

      narchivo << "AC1o=" << lista[cont].anio << ";  ";
      narchivo << "Mes=" << lista[cont].mes << ";  ";
      narchivo << "Dia=" << lista[cont].dia << ";  ";
      narchivo << "Camas disponibles=" << lista[cont].camas_tot -
	lista[cont].camas_ocup << endl;
    }
  cout <<
    "\nAl finalizar el programa se creara archivo llamado 'camas disponibles.txt'\n";
}

void
mayor_ocupacion (int mes, int anho, datos_de_cama lista[], int cont)
{

  int cont2, dia = 0, camas = 0;

  cout << "___Fechas de mayor ocupacion de camas___";

  for (cont2 = 0; cont2 != cont; cont2++)
    {
      if (anho == lista[cont2].anho)
	{
	  if (mes == lista[cont2].mes)
	    {
	      if (camas < lista[cont2].camas_ocup)
		{
		  camas = lista[cont2].camas_ocup;
		  dia = cont2;
		}
	    }
	}
    }
  cout << "\nel dia con mas camas ocupadas fue el " << lista[dia].dia <<
    " del " << mes << " de " << anho << " con " << lista[dia].camas_ocup <<
    " camas ocupadas\n";
}

void
menor_ocupacion (int mes, int anho, datos_de_cama lista[], int cont)
{

  int cont2, dia = 0, camas = 0;

  cout << "___Fechas de menor ocupacion de camas___";

  for (cont2 = 0; cont2 != cont; cont2++)
    {
      if (anho == lista[cont2].anho)
	{
	  if (mes == lista[cont2].mes)
	    {
	      if (camas > lista[cont2].camas_ocup)
		{
		  camas = lista[cont2].camas_ocup;
		  dia = cont2;
		}
	    }
	}
    }
  cout << "\nel dia con menos camas ocupadas fue el " << lista[dia].dia <<
    " del " << mes << " de " << anho << " con " << lista[dia].camas_ocup <<
    " camas ocupadas\n";
}

void
promedio (int mes, int anho, datos_de_cama lista[], int cont)
{

  int cont2, dia, sum = 0, cont3 = 0;

  cout << "___Promedio de camas totales___";

  for (cont2 = 0; cont2 != cont; cont2++)
    {
      if (anho == lista[cont2].anho)
	{
	  if (mes == lista[cont2].mes)
	    {
	      sum = sum + lista[cont2].camas_tot;
	      cont3++;
	    }
	}
    }
  cout << "\nel promedio de camas totales es de " << (sum /
						      cont3) <<
    " en el mes de " << mes << " de " << anho;
}

void
comparativa_anual (datos_de_cama lista[], int cantidad)
{
  int cont, cont2, mes, porce = 0, elecc, total = 0, suma = 0, suma2 = 0;
  cout << "___Comparativa anual 2020-2019___\n";
  cout << "Indique mes a comparar(1/12)=";
  cin >> mes;
  cout << "Desea el porcentaje de:\n -camas totales(0)\n -camas ocupadas(1)";
  cin >> elecc;
  if (mes > 0 && mes < 13)
    {
      for (cont = 0; cont < cantidad; cont++)
	{
	  if (elecc == 0)
	    {
	      if (mes == lista[cont].mes && 2019 == lista[cont].anho)
		{
		  suma = (suma + lista[cont].camas_tot);
		  for (cont2 = 0; cont2 < cantidad; cont2++)
		    {
		      if (mes == lista[cont2].mes
			  && 2020 == lista[cont2].anho)
			{
			  suma2 = (suma2 + lista[cont2].camas_tot);

			}
		    }
		}
	      if (suma > suma2)
		{
		  total = suma - suma2;
		  porce = (total / suma) * 100;
		  cout << "El porcentaje variC3 un" << porce <<
		    "desde un aC1o a otro\n\n";
		}
	      else
		{
		  total = suma2 - suma;
		  porce = (total / suma) * 100;
		  cout << "El porcentaje variC3 un" << porce <<
		    "desde un aC1o a otro\n\n";
		}
	    }
	  else if (elecc == 1)
	    {
	      if (mes == lista[cont].mes && 2019 == lista[cont].anho)
		{
		  suma = (suma + lista[cont].camas_ocup);
		  for (cont2 = 0; cont2 < cantidad; cont2++)
		    {
		      if (mes == lista[cont2].mes
			  && 2020 == lista[cont2].anho)
			{
			  suma2 = (suma2 + lista[cont2].camas_ocup);

			}
		    }
		}
	      if (suma > suma2)
		{
		  total = suma - suma2;
		  porce = (total / suma) * 100;
		  cout << "El porcentaje variC3 un" << porce <<
		    "desde un aC1o a otro\n\n";
		}
	      else
		{
		  total = suma2 - suma;
		  porce = (total / suma) * 100;
		  cout << "El porcentaje variC3 un" << porce <<
		    "desde un aC1o a otro\n\n";
		}
	    }
	}
    }
}




datos_de_cama lista[10000];

int
main (void)
{
  int cont = -1, cont2, elecc;
  int mes, anho;
  ifstream archivo;
  archivo.open ("camas.txt", ios::in);
  if (archivo.fail ())
    {
      cout << "No se pudo abrir el archivo 'camas.txt' ";
    }
  else
    {
      string linea;
      while (getline (archivo, linea, '\n'))
	{
	  vector < int >dato;
	  stringstream lin (linea);
	  string solo;

	  while (getline (lin, solo, '|'))
	    {
	      dato.push_back (atoi (solo.c_str ()));
	      lista[cont].anho = dato[0];
	      lista[cont].mes = dato[1];
	      lista[cont].dia = dato[2];
	      lista[cont].camas_tot = dato[3];
	      lista[cont].camas_ocup = dato[4];
	    }
	  cont++;
	}
    }
  cout << "___MENU DE SELECCION___";
  do
    {
      cout <<
	"\n[1]Mayor ocupacion de camas segun dC-a\n[2]Menor ocupacion de camas segun dC-a\n[3]Promedio de camas disponibles totales del mes \n[4]Porcentaje comparativa anual\n";
      cout << "[0]Salir\n RESPUESTA=";
      cin >> elecc;
      switch (elecc)
	{
	case 1:
	  {
	    cout << "\n ingrese mes= ";
	    cin >> mes;
	    cout << "\n ingrese aC1o= ";
	    cin >> anho;
	    mayor_ocupacion (mes, anho, lista, cont);
	    break;
	  }
	case 2:
	  {
	    cout << "\n ingrese mes= ";
	    cin >> mes;
	    cout << "\n ingrese aC1o= ";
	    cin >> anho;
	    menor_ocupacion (mes, anho, lista, cont);
	    promedio (mes, anho, lista, cont);

	    break;
	  }
	case 3:
	  {
	    cout << "\n ingrese mes= ";
	    cin >> mes;
	    cout << "\n ingrese aC1o= ";
	    cin >> anho;
	    promedio (mes, anho, lista, cont);
	  }
	case 4:
	  {
	    comparativa_anual (lista, cont);
	    break;
	  }
	case 0:
	  {
	    calcula_disponibilidad (lista, cont);
	  }
	}
    }
  while (elecc == 0);
  return 0;
}
