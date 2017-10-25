//
// File: nullAssignment.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//

// Include Files
#include "rt_nonfinite.h"
#include "processamentoEMG.h"
#include "nullAssignment.h"

// Function Definitions

//
// Arguments    : double x_data[]
//                int x_size[1]
// Return Type  : void
//
void nullAssignment(double x_data[], int x_size[1])
{
  int k;
  int i6;
  double b_x_data[6071];
  double c_x_data[6071];
  k = x_size[0];
  for (i6 = 0; i6 < k; i6++) {
    b_x_data[i6] = x_data[i6];
  }

  for (k = 1; k < x_size[0]; k++) {
    b_x_data[k - 1] = b_x_data[k];
  }

  if (1 > x_size[0] - 1) {
    k = 0;
  } else {
    k = x_size[0] - 1;
  }

  for (i6 = 0; i6 < k; i6++) {
    c_x_data[i6] = b_x_data[i6];
  }

  for (i6 = 0; i6 < k; i6++) {
    b_x_data[i6] = c_x_data[i6];
  }

  x_size[0] = k;
  for (i6 = 0; i6 < k; i6++) {
    x_data[i6] = b_x_data[i6];
  }
}

//
// File trailer for nullAssignment.cpp
//
// [EOF]
//
