//
// File: processamentoEMG.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//
#ifndef PROCESSAMENTOEMG_H
#define PROCESSAMENTOEMG_H

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "processamentoEMG_types.h"

// Function Declarations
extern void processamentoEMG(const double data[6071], const double time[6071],
  double ContagemEntrePicos_data[], int ContagemEntrePicos_size[2], double
  TempoEntrePicos_data[], int TempoEntrePicos_size[2], double *TempoMedioEntrePicos, double *NumeroDePicos, double *DPTempo);

#endif

//
// File trailer for processamentoEMG.h
//
// [EOF]
//
