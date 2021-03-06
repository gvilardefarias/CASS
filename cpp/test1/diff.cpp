//
// File: diff.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//

// Include Files
#include "rt_nonfinite.h"
#include "processamentoEMG.h"
#include "diff.h"

// Function Definitions

//
// Arguments    : const double x_data[]
//                const int x_size[2]
//                double y_data[]
//                int y_size[2]
// Return Type  : void
//
void b_diff(const double x_data[], const int x_size[2], double y_data[], int
            y_size[2])
{
  int b_x_size;
  int ixLead;
  int iyLead;
  double work_data_idx_0;
  int m;
  double tmp2;
  if (x_size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    if (x_size[1] - 1 <= 1) {
      b_x_size = x_size[1] - 1;
    } else {
      b_x_size = 1;
    }

    if (b_x_size < 1) {
      y_size[0] = 1;
      y_size[1] = 0;
    } else {
      y_size[0] = 1;
      y_size[1] = (short)(x_size[1] - 1);
      if (!((short)(x_size[1] - 1) == 0)) {
        ixLead = 1;
        iyLead = 0;
        work_data_idx_0 = x_data[0];
        for (m = 2; m <= x_size[1]; m++) {
          tmp2 = work_data_idx_0;
          work_data_idx_0 = x_data[ixLead];
          tmp2 = x_data[ixLead] - tmp2;
          ixLead++;
          y_data[iyLead] = tmp2;
          iyLead++;
        }
      }
    }
  }
}

//
// Arguments    : const boolean_T x[6071]
//                double y[6070]
// Return Type  : void
//
void diff(const boolean_T x[6071], double y[6070])
{
  int ixLead;
  int iyLead;
  int work;
  int m;
  int tmp2;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 6070; m++) {
    tmp2 = work;
    work = x[ixLead];
    tmp2 = x[ixLead] - tmp2;
    ixLead++;
    y[iyLead] = tmp2;
    iyLead++;
  }
}

//
// File trailer for diff.cpp
//
// [EOF]
//
