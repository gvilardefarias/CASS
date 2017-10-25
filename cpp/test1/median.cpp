//
// File: median.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//

// Include Files
#include "rt_nonfinite.h"
#include "processamentoEMG.h"
#include "median.h"
#include "sortIdx.h"

// Function Declarations
static double vectormedian(const double v_data[], const int v_size[1]);

// Function Definitions

//
// Arguments    : const double v_data[]
//                const int v_size[1]
// Return Type  : double
//
static double vectormedian(const double v_data[], const int v_size[1])
{
  double m;
  int idx_data[6072];
  int idx_size[1];
  int midm1;
  sortIdx(v_data, v_size, idx_data, idx_size);
  midm1 = v_size[0] >> 1;
  if (rtIsNaN(v_data[idx_data[v_size[0] - 1] - 1])) {
    m = rtNaN;
  } else if ((v_size[0] & 1) == 0) {
    m = v_data[idx_data[midm1 - 1] - 1] + (v_data[idx_data[midm1] - 1] -
      v_data[idx_data[midm1 - 1] - 1]) / 2.0;
  } else {
    m = v_data[idx_data[midm1] - 1];
  }

  return m;
}

//
// Arguments    : const double x_data[]
//                const int x_size[1]
// Return Type  : double
//
double median(const double x_data[], const int x_size[1])
{
  double y;
  if (x_size[0] == 0) {
    y = rtNaN;
  } else {
    y = vectormedian(x_data, x_size);
  }

  return y;
}

//
// File trailer for median.cpp
//
// [EOF]
//
