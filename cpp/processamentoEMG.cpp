//
// File: processamentoEMG.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 23-Oct-2017 02:09:14
//

// Include Files
#include "rt_nonfinite.h"
#include "processamentoEMG.h"
#include "nullAssignment.h"
#include "median.h"
#include "std.h"
#include "mean.h"
#include "diff.h"
#include "sign.h"
#include "sum.h"

// Function Declarations
static void MovAvg(const double vetor[6071], double vetor_saida[6071]);
static void b_MovAvg(const double vetor[6071], double vetor_saida[6071]);

// Function Definitions

//
// Arguments    : const double vetor[6071]
//                double vetor_saida[6071]
// Return Type  : void
//
static void MovAvg(const double vetor[6071], double vetor_saida[6071])
{
  int mak;
  int i0;
  int i1;
  double vetor_data[6071];
  int vetor_size[1];
  int loop_ub;
  double x;
  for (mak = 0; mak < 5972; mak++) {
    if (1 + mak > 100 + mak) {
      i0 = 1;
      i1 = 0;
    } else {
      i0 = mak + 1;
      i1 = mak + 100;
    }

    vetor_size[0] = (i1 - i0) + 1;
    loop_ub = (i1 - i0) + 1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      vetor_data[i1] = vetor[(i0 + i1) - 1];
    }

    x = sum(vetor_data, vetor_size);
    vetor_saida[mak] = x / 100.0;
  }

  memset(&vetor_saida[5972], 0, 99U * sizeof(double));
}

//
// Arguments    : const double vetor[6071]
//                double vetor_saida[6071]
// Return Type  : void
//
static void b_MovAvg(const double vetor[6071], double vetor_saida[6071])
{
  int mak;
  int i2;
  int i3;
  double vetor_data[6071];
  int vetor_size[1];
  int loop_ub;
  double x;
  for (mak = 0; mak < 5872; mak++) {
    if (1 + mak > 200 + mak) {
      i2 = 1;
      i3 = 0;
    } else {
      i2 = mak + 1;
      i3 = mak + 200;
    }

    vetor_size[0] = (i3 - i2) + 1;
    loop_ub = (i3 - i2) + 1;
    for (i3 = 0; i3 < loop_ub; i3++) {
      vetor_data[i3] = vetor[(i2 + i3) - 1];
    }

    x = sum(vetor_data, vetor_size);
    vetor_saida[mak] = x / 200.0;
  }

  memset(&vetor_saida[5872], 0, 199U * sizeof(double));
}

//
// % ALGORITMO DE PROCESSAMENTO
//  Número de pontos a serem utilizados para o cálculo da média móvel (função
//  smooth) nos casos especificados:
//  Suavização do Sinal:
// Arguments    : const double data[6071]
//                const double time[6071]
//                double ContagemEntrePicos_data[]
//                int ContagemEntrePicos_size[2]
//                double TempoEntrePicos_data[]
//                int TempoEntrePicos_size[2]
//                double *TempoMedioEntrePicos
//                double *NumeroDePicos
//                double *DPTempo
// Return Type  : void
//
void processamentoEMG(const double data[6071], const double time[6071], double
                      ContagemEntrePicos_data[], int ContagemEntrePicos_size[2],
                      double TempoEntrePicos_data[], int TempoEntrePicos_size[2],
                      double *TempoMedioEntrePicos, double *NumeroDePicos,
                      double *DPTempo)
{
  static double EMGsmooth[6071];
  static double EMGlimiar[6071];
  int apnd;
  boolean_T b_EMGlimiar[6071];
  int idx;
  static double dv0[6070];
  double c_EMGlimiar;
  short ii_data[6071];
  int absb;
  boolean_T exitg4;
  boolean_T guard3 = false;
  int loop_ub;
  short PontosIniciais_data[6071];
  boolean_T exitg3;
  boolean_T guard2 = false;
  int PontosFinais_size[1];
  static double PontosFinais_data[6071];
  int k;
  static double PicosMovimento_data[6071];
  static double b_PontosFinais_data[6071];
  int ndbl;
  int n;
  double b_ndbl;
  double b_apnd;
  double cdiff;
  static double y_data[6072];
  double b_absb;
  double u0;
  static double Movimento_data[6072];
  int nm1d2;
  int time_size[2];
  boolean_T exitg2;
  boolean_T x_data[6072];
  int b_ii_data[6072];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int ii_size[1];

  //  Estabelecimento de Limiar para Multiplicação por zero dos valores que
  //  estiverem abaixo dele:
  //  Limpando as variáveis que são criadas com esses nomes quando os dados são
  //  carregados, liberando então o uso das funções max e min
  //  carregando os valores medidos do sinal na variável EMG
  //  Suavização do sinal
  MovAvg(data, EMGsmooth);

  // EMGtrue = smooth(EMG,PontosSuavizacao);
  //  Modificação do sinal (multiplicação por zero de valores abaixo de limiar móvel) 
  //  Multiplicando por zero os valores do sinal abaixo do limiar móvel
  b_MovAvg(data, EMGlimiar);
  for (apnd = 0; apnd < 6071; apnd++) {
    EMGlimiar[apnd] = EMGsmooth[apnd] - EMGlimiar[apnd];
  }

  b_sign(EMGlimiar);

  //  Determinação dos Tempos Estimados de Início de Término da Atividade Muscular 
  for (idx = 0; idx < 6071; idx++) {
    c_EMGlimiar = (EMGlimiar[idx] + 1.0) / 2.0 * EMGsmooth[idx];
    b_EMGlimiar[idx] = (c_EMGlimiar > 0.0);
    EMGlimiar[idx] = c_EMGlimiar;
  }

  diff(b_EMGlimiar, dv0);
  EMGsmooth[0] = 0.0;
  memcpy(&EMGsmooth[1], &dv0[0], 6070U * sizeof(double));
  idx = 0;
  absb = 1;
  exitg4 = false;
  while ((!exitg4) && (absb < 6072)) {
    guard3 = false;
    if (EMGsmooth[absb - 1] == 1.0) {
      idx++;
      ii_data[idx - 1] = (short)absb;
      if (idx >= 6071) {
        exitg4 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3) {
      absb++;
    }
  }

  if (1 > idx) {
    loop_ub = 0;
  } else {
    loop_ub = idx;
  }

  for (apnd = 0; apnd < loop_ub; apnd++) {
    PontosIniciais_data[apnd] = ii_data[apnd];
  }

  idx = 0;
  absb = 1;
  exitg3 = false;
  while ((!exitg3) && (absb < 6072)) {
    guard2 = false;
    if (EMGsmooth[absb - 1] == -1.0) {
      idx++;
      ii_data[idx - 1] = (short)absb;
      if (idx >= 6071) {
        exitg3 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      absb++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  PontosFinais_size[0] = idx;
  for (apnd = 0; apnd < idx; apnd++) {
    PontosFinais_data[apnd] = ii_data[apnd];
  }

  //  Correção para os casos em que falsos pontos iniciais ou finais são
  //  detectados
  while (PontosIniciais_data[0] > PontosFinais_data[0]) {
    nullAssignment(PontosFinais_data, PontosFinais_size);
  }

  if (loop_ub > PontosFinais_size[0]) {
    if (1 > PontosFinais_size[0]) {
      loop_ub = 0;
    } else {
      loop_ub = PontosFinais_size[0];
    }
  } else {
    if (loop_ub < PontosFinais_size[0]) {
      apnd = PontosFinais_size[0] - loop_ub;
      if (apnd > PontosFinais_size[0]) {
        apnd = 0;
        absb = 0;
      } else {
        apnd--;
        absb = PontosFinais_size[0];
      }

      idx = absb - apnd;
      for (ndbl = 0; ndbl < idx; ndbl++) {
        b_PontosFinais_data[ndbl] = PontosFinais_data[apnd + ndbl];
      }

      idx = absb - apnd;
      for (apnd = 0; apnd < idx; apnd++) {
        PontosFinais_data[apnd] = b_PontosFinais_data[apnd];
      }
    }
  }

  //  Determinação do tempo da ocorrência dos picos de amplitude
  for (apnd = 0; apnd < loop_ub; apnd++) {
    PicosMovimento_data[apnd] = 0.0;
  }

  for (k = 0; k < loop_ub; k++) {
    //  Criação de vetor com todos os pontos dos valores não-nulos e do valor final 
    if (PontosFinais_data[k] < PontosIniciais_data[k]) {
      n = 0;
      absb = PontosIniciais_data[k];
      b_apnd = PontosFinais_data[k];
    } else {
      absb = PontosIniciais_data[k];
      b_ndbl = floor((PontosFinais_data[k] - (double)PontosIniciais_data[k]) +
                     0.5);
      b_apnd = (double)PontosIniciais_data[k] + b_ndbl;
      cdiff = b_apnd - PontosFinais_data[k];
      idx = PontosIniciais_data[k];
      b_absb = fabs(PontosFinais_data[k]);
      u0 = idx;
      if ((u0 >= b_absb) || rtIsNaN(b_absb)) {
        b_absb = u0;
      }

      if (fabs(cdiff) < 4.4408920985006262E-16 * b_absb) {
        b_ndbl++;
        b_apnd = PontosFinais_data[k];
      } else if (cdiff > 0.0) {
        b_apnd = (double)PontosIniciais_data[k] + (b_ndbl - 1.0);
      } else {
        b_ndbl++;
      }

      if (b_ndbl >= 0.0) {
        n = (int)b_ndbl;
      } else {
        n = 0;
      }
    }

    if (n > 0) {
      y_data[0] = absb;
      if (n > 1) {
        y_data[n - 1] = b_apnd;
        nm1d2 = (n - 1) / 2;
        for (idx = 1; idx < nm1d2; idx++) {
          y_data[idx] = absb + idx;
          y_data[(n - idx) - 1] = b_apnd - (double)idx;
        }

        if (nm1d2 << 1 == n - 1) {
          y_data[nm1d2] = ((double)absb + b_apnd) / 2.0;
        } else {
          y_data[nm1d2] = absb + nm1d2;
          y_data[nm1d2 + 1] = b_apnd - (double)nm1d2;
        }
      }
    }

    for (apnd = 0; apnd < n; apnd++) {
      Movimento_data[apnd] = y_data[apnd];
    }

    //  Criação de vetor com todos os valores não-nulos e o valor final
    //  Estimativa do ponto onde ocorre o pico de amplitude pela mediana dos
    //  pontos, dentro do intervalo definido pelos pontos inicial e
    //  final, onde o valor do sinal da EMG suavizada é máximo.
    idx = 1;
    b_ndbl = EMGlimiar[(int)Movimento_data[0] - 1];
    if (n > 1) {
      if (rtIsNaN(EMGlimiar[(int)Movimento_data[0] - 1])) {
        ndbl = 2;
        exitg2 = false;
        while ((!exitg2) && (ndbl <= n)) {
          idx = ndbl;
          if (!rtIsNaN(EMGlimiar[(int)Movimento_data[ndbl - 1] - 1])) {
            b_ndbl = EMGlimiar[(int)Movimento_data[ndbl - 1] - 1];
            exitg2 = true;
          } else {
            ndbl++;
          }
        }
      }

      if (idx < n) {
        while (idx + 1 <= n) {
          if (EMGlimiar[(int)Movimento_data[idx] - 1] > b_ndbl) {
            b_ndbl = EMGlimiar[(int)Movimento_data[idx] - 1];
          }

          idx++;
        }
      }
    }

    for (apnd = 0; apnd < n; apnd++) {
      x_data[apnd] = (EMGlimiar[(int)Movimento_data[apnd] - 1] == b_ndbl);
    }

    idx = 0;
    absb = 1;
    exitg1 = false;
    while ((!exitg1) && (absb <= n)) {
      guard1 = false;
      if (x_data[absb - 1]) {
        idx++;
        b_ii_data[idx - 1] = absb;
        if (idx >= n) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        absb++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    ii_size[0] = n;
    for (apnd = 0; apnd < n; apnd++) {
      y_data[apnd] = b_ii_data[apnd];
    }

    b_ndbl = median(y_data, ii_size);
    b_ndbl = floor(b_ndbl);
    PicosMovimento_data[k] = Movimento_data[(int)b_ndbl - 1];
  }

  // %Funções a serem retornadas
  //  Preparação para Traçado do Gráficos
  *NumeroDePicos = loop_ub;
  if (loop_ub - 1 < 1) {
    ndbl = 0;
    apnd = loop_ub - 1;
  } else {
    ndbl = (int)floor((((double)loop_ub - 1.0) - 1.0) + 0.5);
    apnd = ndbl + 1;
    idx = (ndbl - loop_ub) + 2;
    absb = (int)fabs((double)loop_ub - 1.0);
    if (1 >= absb) {
      absb = 1;
    }

    if (fabs((double)idx) < 4.4408920985006262E-16 * (double)absb) {
      ndbl++;
      apnd = loop_ub - 1;
    } else if (idx > 0) {
      apnd = ndbl;
    } else {
      ndbl++;
    }
  }

  ContagemEntrePicos_size[0] = 1;
  ContagemEntrePicos_size[1] = ndbl;
  if (ndbl > 0) {
    ContagemEntrePicos_data[0] = 1.0;
    if (ndbl > 1) {
      ContagemEntrePicos_data[ndbl - 1] = apnd;
      nm1d2 = (ndbl - 1) / 2;
      for (k = 1; k < nm1d2; k++) {
        ContagemEntrePicos_data[k] = 1.0 + (double)k;
        ContagemEntrePicos_data[(ndbl - k) - 1] = apnd - k;
      }

      if (nm1d2 << 1 == ndbl - 1) {
        ContagemEntrePicos_data[nm1d2] = (1.0 + (double)apnd) / 2.0;
      } else {
        ContagemEntrePicos_data[nm1d2] = 1.0 + (double)nm1d2;
        ContagemEntrePicos_data[nm1d2 + 1] = apnd - nm1d2;
      }
    }
  }

  time_size[0] = 1;
  time_size[1] = loop_ub;
  for (apnd = 0; apnd < loop_ub; apnd++) {
    b_PontosFinais_data[apnd] = time[(int)PicosMovimento_data[apnd] - 1];
  }

  b_diff(b_PontosFinais_data, time_size, TempoEntrePicos_data,
         TempoEntrePicos_size);

  //  Gráfico do Tempo entre Picos de Amplitude (Contrações) com os respectivos Média e DP 
  *TempoMedioEntrePicos = mean(TempoEntrePicos_data, TempoEntrePicos_size);
  *DPTempo = b_std(TempoEntrePicos_data, TempoEntrePicos_size);
}

//
// File trailer for processamentoEMG.cpp
//
// [EOF]
//
