// Include Files
#include "rt_nonfinite.h"
#include "processamentoEMG.h"
#include "Conect.h"
#include "processamentoEMG_terminate.h"
#include "processamentoEMG_initialize.h"
#include <iostream>
#include <emscripten/bind.h>

using namespace std;
// Function Declarations
static void argInit_1x6071_real_T(double result[6071]);
static double argInit_real_T();

//Variables
int i = 0;
double data[6071], tempo[6071];

// Function Definitions

//
// Arguments    : double result[6071]
// Return Type  : void
//
static void argInit_1x6071_real_T(double result[6071])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 6071; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 2.5;
}

//
// Arguments    : void
// Return Type  : void
//


extern "C" char* main_processamentoEMG()
{
  char resultado[256];
  static double ContagemEntrePicos_data[6070];
  int ContagemEntrePicos_size[2];
  static double TempoEntrePicos_data[6070];
  int TempoEntrePicos_size[2];
  double TempoMedioEntrePicos;
  static double NumeroDePicos;
  double DPTempo;

  cout << "d1" << data[0] << endl;
  cout << "d2" << data[1] << endl;
  cout << "d3" << data[2] << endl;

  cout << "t1" << tempo[0] << endl;
  cout << "t2" << tempo[1] << endl;
  cout << "t3" << tempo[2] << endl;


  // Initialize function 'processamentoEMG' input arguments.
  // Initialize function input argument 'data'.
  // Initialize function input argument 'time'.
  // Call the entry-point 'processamentoEMG'.
 // argInit_1x6071_real_T(dv1);
 // argInit_1x6071_real_T(dv2);
 
 processamentoEMG(data, tempo, ContagemEntrePicos_data, ContagemEntrePicos_size,
                   TempoEntrePicos_data, TempoEntrePicos_size, &TempoMedioEntrePicos, &NumeroDePicos, &DPTempo);

  cout<<"TempoMedioEntrePicos: "<<TempoMedioEntrePicos<<endl;
  cout<<"Numero de Picos: "<<NumeroDePicos<<endl;
  cout<<"DPTempo: "<<DPTempo<<endl;

  sprintf(resultado, "%lf,%lf,%lf", TempoMedioEntrePicos, NumeroDePicos, DPTempo);

  return resultado;
}

extern "C" void addValue(double dataF, double tempoF){
  if(i==0){
    argInit_1x6071_real_T(data);
    argInit_1x6071_real_T(tempo);
  }

  data[i] = dataF;
  tempo[i] = tempoF;

  i++;
}

// [EOF]
//
