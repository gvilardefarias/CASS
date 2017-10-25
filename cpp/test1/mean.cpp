//
// File: mean.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//

// Include Files
#include "rt_nonfinite.h"
#include "processamentoEMG.h"
#include "mean.h"

// Function Definitions

//
// Arguments    : const double x_data[]
//                const int x_size[2]
// Return Type  : double
//
double mean(const double x_data[], const int x_size[2])
{
  double y;
  int k;
  if (x_size[1] == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= x_size[1]; k++) {
      y += x_data[k - 1];
    }
  }

  y /= (double)x_size[1];
  return y;
}

//
// File trailer for mean.cpp
//
// [EOF]
//
