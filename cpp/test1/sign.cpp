//
// File: sign.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//

// Include Files
#include "rt_nonfinite.h"
#include "processamentoEMG.h"
#include "sign.h"

// Function Definitions

//
// Arguments    : double x[6071]
// Return Type  : void
//
void b_sign(double x[6071])
{
  int k;
  for (k = 0; k < 6071; k++) {
    if (x[k] < 0.0) {
      x[k] = -1.0;
    } else if (x[k] > 0.0) {
      x[k] = 1.0;
    } else {
      if (x[k] == 0.0) {
        x[k] = 0.0;
      }
    }
  }
}

//
// File trailer for sign.cpp
//
// [EOF]
//
