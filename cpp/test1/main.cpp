//
// File: main.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "processamentoEMG.h"
#include "main.h"
#include "processamentoEMG_terminate.h"
#include "processamentoEMG_initialize.h"
#include <iostream>
using namespace std;
// Function Declarations
static void argInit_1x6071_real_T(double result[6071]);
static double argInit_real_T();
static void  main_processamentoEMG();

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
void Conect::main_processamentoEMG()
{
  static double data[6071];
  static double tempo[6071];
  static double ContagemEntrePicos_data[6070];
  int ContagemEntrePicos_size[2];
  static double TempoEntrePicos_data[6070];
  int TempoEntrePicos_size[2];
  double TempoMedioEntrePicos;
  static double NumeroDePicos;
  double DPTempo;

  // Initialize function 'processamentoEMG' input arguments.
  // Initialize function input argument 'data'.
  // Initialize function input argument 'time'.
  // Call the entry-point 'processamentoEMG'.
 // argInit_1x6071_real_T(dv1);
 // argInit_1x6071_real_T(dv2);
  
  processamentoEMG(data, tempo, ContagemEntrePicos_data, ContagemEntrePicos_size,
                   TempoEntrePicos_data, TempoEntrePicos_size,TempoMedioEntrePicos, NumeroDePicos, DPTempo);

  cout<<"TempoMedioEntrePicos: "<<TempoMedioEntrePicos<<endl;
  cout<<"Numero de Picos: "<<NumeroDePicos<<endl;
  cout<<"DPTempo: "<<DPTempo<<endl;
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
/*
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  processamentoEMG_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_processamentoEMG();

  // Terminate the application.
  // You do not need to do this more than one time.
  processamentoEMG_terminate();
  return 0;
}*/

//
// File trailer for main.cpp
//
// [EOF]
//
