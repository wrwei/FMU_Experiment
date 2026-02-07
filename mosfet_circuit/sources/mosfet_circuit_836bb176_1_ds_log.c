#include "mosfet_circuit_macros.h"
/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'mosfet_circuit/Solver'.
 */

#include "ne_ds.h"
#include "mosfet_circuit_836bb176_1_ds_sys_struct.h"
#include "mosfet_circuit_836bb176_1_ds_log.h"
#include "mosfet_circuit_836bb176_1_ds.h"
#include "mosfet_circuit_836bb176_1_ds_externals.h"
#include "mosfet_circuit_836bb176_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T mosfet_circuit_836bb176_1_ds_log(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t2, NeDsMethodOutput *t3)
{
  PmRealVector out;
  real_T Controlled_Voltage_Source_i;
  real_T R1_Resistor_n_v;
  real_T U_idx_0;
  U_idx_0 = t2->mU.mX[0];
  out = t3->mLOG;
  Controlled_Voltage_Source_i = U_idx_0 * -8.3333333333333331E-5;
  R1_Resistor_n_v = U_idx_0 * 0.16666666666666666;
  out.mX[0] = Controlled_Voltage_Source_i;
  out.mX[1] = U_idx_0;
  out.mX[2] = U_idx_0;
  out.mX[3] = U_idx_0;
  out.mX[4] = R1_Resistor_n_v;
  out.mX[5] = U_idx_0;
  out.mX[6] = -Controlled_Voltage_Source_i;
  out.mX[7] = R1_Resistor_n_v;
  out.mX[8] = U_idx_0;
  out.mX[9] = Controlled_Voltage_Source_i * -10000.0;
  out.mX[10] = Controlled_Voltage_Source_i * Controlled_Voltage_Source_i *
    10000.0;
  out.mX[11] = R1_Resistor_n_v;
  out.mX[12] = -Controlled_Voltage_Source_i;
  out.mX[13] = R1_Resistor_n_v;
  out.mX[14] = Controlled_Voltage_Source_i * -2000.0;
  out.mX[15] = Controlled_Voltage_Source_i * Controlled_Voltage_Source_i *
    2000.0;
  out.mX[16] = U_idx_0;
  out.mX[17] = R1_Resistor_n_v;
  out.mX[18] = R1_Resistor_n_v;
  out.mX[19] = R1_Resistor_n_v;
  (void)sys;
  (void)t3;
  return 0;
}
