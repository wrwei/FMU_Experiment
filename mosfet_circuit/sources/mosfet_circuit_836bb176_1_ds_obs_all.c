#include "mosfet_circuit_macros.h"
/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'mosfet_circuit/Solver'.
 */

#include "ne_ds.h"
#include "mosfet_circuit_836bb176_1_ds_sys_struct.h"
#include "mosfet_circuit_836bb176_1_ds_obs_all.h"
#include "mosfet_circuit_836bb176_1_ds.h"
#include "mosfet_circuit_836bb176_1_ds_externals.h"
#include "mosfet_circuit_836bb176_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T mosfet_circuit_836bb176_1_ds_obs_all(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t2, NeDsMethodOutput *t3)
{
  PmRealVector out;
  real_T Controlled_Voltage_Source_i;
  real_T R1_Resistor_n_v;
  real_T U_idx_0;
  U_idx_0 = t2->mU.mX[0];
  out = t3->mOBS_ALL;
  Controlled_Voltage_Source_i = U_idx_0 * -8.3333333333333331E-5;
  R1_Resistor_n_v = U_idx_0 * 0.16666666666666666;
  out.mX[0] = Controlled_Voltage_Source_i;
  out.mX[1] = 0.0;
  out.mX[2] = U_idx_0;
  out.mX[3] = U_idx_0;
  out.mX[4] = U_idx_0;
  out.mX[5] = 0.0;
  out.mX[6] = 0.0;
  out.mX[7] = R1_Resistor_n_v;
  out.mX[8] = U_idx_0;
  out.mX[9] = -Controlled_Voltage_Source_i;
  out.mX[10] = R1_Resistor_n_v;
  out.mX[11] = U_idx_0;
  out.mX[12] = Controlled_Voltage_Source_i * -10000.0;
  out.mX[13] = 0.0;
  out.mX[14] = 0.0;
  out.mX[15] = R1_Resistor_n_v;
  out.mX[16] = -Controlled_Voltage_Source_i;
  out.mX[17] = 0.0;
  out.mX[18] = R1_Resistor_n_v;
  out.mX[19] = Controlled_Voltage_Source_i * -2000.0;
  out.mX[20] = U_idx_0;
  out.mX[21] = R1_Resistor_n_v;
  out.mX[22] = 0.0;
  out.mX[23] = R1_Resistor_n_v;
  out.mX[24] = R1_Resistor_n_v;
  (void)sys;
  (void)t3;
  return 0;
}
