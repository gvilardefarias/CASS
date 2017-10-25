//
// File: diff.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//
#ifndef DIFF_H
#define DIFF_H

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "processamentoEMG_types.h"

// Function Declarations
extern void b_diff(const double x_data[], const int x_size[2], double y_data[],
                   int y_size[2]);
extern void diff(const boolean_T x[6071], double y[6070]);

#endif

//
// File trailer for diff.h
//
// [EOF]
//
