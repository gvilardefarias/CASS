//
// File: sortIdx.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//

// Include Files
#include "rt_nonfinite.h"
#include "processamentoEMG.h"
#include "sortIdx.h"

// Function Declarations
static void merge_sort(int idx_data[], const double x_data[], const int x_size[1]);

// Function Definitions

//
// Arguments    : int idx_data[]
//                const double x_data[]
//                const int x_size[1]
// Return Type  : void
//
static void merge_sort(int idx_data[], const double x_data[], const int x_size[1])
{
  int n;
  int iwork_data[6072];
  int k;
  boolean_T p;
  int i;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  n = x_size[0] + 1;
  for (k = 1; k <= n - 2; k += 2) {
    if ((x_data[k - 1] <= x_data[k]) || rtIsNaN(x_data[k])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }

  if ((x_size[0] & 1) != 0) {
    idx_data[x_size[0] - 1] = x_size[0];
  }

  i = 2;
  while (i < n - 1) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
      b_p = j;
      q = pEnd - 1;
      qEnd = j + i2;
      if (qEnd > n) {
        qEnd = n;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if ((x_data[idx_data[b_p - 1] - 1] <= x_data[idx_data[q] - 1]) ||
            rtIsNaN(x_data[idx_data[q] - 1])) {
          p = true;
        } else {
          p = false;
        }

        if (p) {
          iwork_data[k] = idx_data[b_p - 1];
          b_p++;
          if (b_p == pEnd) {
            while (q + 1 < qEnd) {
              k++;
              iwork_data[k] = idx_data[q];
              q++;
            }
          }
        } else {
          iwork_data[k] = idx_data[q];
          q++;
          if (q + 1 == qEnd) {
            while (b_p < pEnd) {
              k++;
              iwork_data[k] = idx_data[b_p - 1];
              b_p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k + 1 <= kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }

      j = qEnd;
    }

    i = i2;
  }
}

//
// Arguments    : const double x_data[]
//                const int x_size[1]
//                int idx_data[]
//                int idx_size[1]
// Return Type  : void
//
void sortIdx(const double x_data[], const int x_size[1], int idx_data[], int
             idx_size[1])
{
  int loop_ub;
  int i4;
  idx_size[0] = (short)x_size[0];
  loop_ub = (short)x_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    idx_data[i4] = 0;
  }

  merge_sort(idx_data, x_data, x_size);
}

//
// File trailer for sortIdx.cpp
//
// [EOF]
//
