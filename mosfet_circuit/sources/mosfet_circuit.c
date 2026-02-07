#include "mosfet_circuit_macros.h"
#include "mosfet_circuit.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <string.h>

B_mosfet_circuit_T mosfet_circuit_B;
DW_mosfet_circuit_T mosfet_circuit_DW;
ExtU_mosfet_circuit_T mosfet_circuit_U;
ExtY_mosfet_circuit_T mosfet_circuit_Y;
static RT_MODEL_mosfet_circuit_T mosfet_circuit_M_;
RT_MODEL_mosfet_circuit_T *const mosfet_circuit_M = &mosfet_circuit_M_;
void mosfet_circuit_step(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  char *msg;
  char *msg_0;
  char *msg_1;
  real_T tmp_0[4];
  real_T tmp_3[4];
  real_T tmp_5[4];
  real_T rtb_OUTPUT_1_0;
  real_T time;
  real_T time_0;
  real_T time_1;
  real_T time_2;
  real_T time_3;
  real_T time_tmp;
  real_T time_tmp_0;
  int32_T isHit;
  int32_T isHit_0;
  int32_T tmp_2;
  int_T tmp_1[2];
  int_T tmp_4[2];
  int_T tmp_6[2];
  boolean_T tmp;
  mosfet_circuit_B.INPUT_1_1_1[0] = mosfet_circuit_U.In1;
  mosfet_circuit_B.INPUT_1_1_1[1] = 0.0;
  mosfet_circuit_B.INPUT_1_1_1[2] = 0.0;
  mosfet_circuit_DW.INPUT_1_1_1_Discrete[0] = !(mosfet_circuit_B.INPUT_1_1_1[0] ==
    mosfet_circuit_DW.INPUT_1_1_1_Discrete[1]);
  mosfet_circuit_DW.INPUT_1_1_1_Discrete[1] = mosfet_circuit_B.INPUT_1_1_1[0];
  mosfet_circuit_B.INPUT_1_1_1[0] = mosfet_circuit_DW.INPUT_1_1_1_Discrete[1];
  mosfet_circuit_B.INPUT_1_1_1[3] = mosfet_circuit_DW.INPUT_1_1_1_Discrete[0];
  simulationData = (NeslSimulationData *)mosfet_circuit_DW.OUTPUT_1_0_SimData;
  time_tmp = (((mosfet_circuit_M->Timing.clockTick0+
                mosfet_circuit_M->Timing.clockTickH0* 4294967296.0)) * 0.001);
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &mosfet_circuit_DW.OUTPUT_1_0_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &mosfet_circuit_DW.OUTPUT_1_0_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_1[0] = 0;
  tmp_0[0] = mosfet_circuit_B.INPUT_1_1_1[0];
  tmp_0[1] = mosfet_circuit_B.INPUT_1_1_1[1];
  tmp_0[2] = mosfet_circuit_B.INPUT_1_1_1[2];
  tmp_0[3] = mosfet_circuit_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mOutputs.mN = 1;
  simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_0;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_tmp_0 = (((mosfet_circuit_M->Timing.clockTick0+
                  mosfet_circuit_M->Timing.clockTickH0* 4294967296.0)) * 0.001);
  time_0 = time_tmp_0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  isHit = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)
    mosfet_circuit_DW.OUTPUT_1_0_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    mosfet_circuit_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(mosfet_circuit_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(mosfet_circuit_M, msg);
    }
  }

  mosfet_circuit_Y.Vout = rtb_OUTPUT_1_0;
  simulationData = (NeslSimulationData *)mosfet_circuit_DW.STATE_1_SimData;
  time_1 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &mosfet_circuit_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &mosfet_circuit_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_4[0] = 0;
  tmp_3[0] = mosfet_circuit_B.INPUT_1_1_1[0];
  tmp_3[1] = mosfet_circuit_B.INPUT_1_1_1[1];
  tmp_3[2] = mosfet_circuit_B.INPUT_1_1_1[2];
  tmp_3[3] = mosfet_circuit_B.INPUT_1_1_1[3];
  tmp_4[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_3[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_4[0];
  simulationData->mData->mOutputs.mN = 0;
  simulationData->mData->mOutputs.mX = NULL;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_2 = time_tmp_0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_2;
  isHit_0 = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit_0;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)mosfet_circuit_DW.STATE_1_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    mosfet_circuit_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(mosfet_circuit_M));
    if (tmp) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(mosfet_circuit_M, msg_0);
    }
  }

  simulationData = (NeslSimulationData *)mosfet_circuit_DW.STATE_1_SimData;
  time_3 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_3;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &mosfet_circuit_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &mosfet_circuit_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_6[0] = 0;
  tmp_5[0] = mosfet_circuit_B.INPUT_1_1_1[0];
  tmp_5[1] = mosfet_circuit_B.INPUT_1_1_1[1];
  tmp_5[2] = mosfet_circuit_B.INPUT_1_1_1[2];
  tmp_5[3] = mosfet_circuit_B.INPUT_1_1_1[3];
  tmp_6[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_5[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_6[0];
  diagnosticManager = (NeuDiagnosticManager *)mosfet_circuit_DW.STATE_1_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    mosfet_circuit_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(mosfet_circuit_M));
    if (tmp) {
      msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
      rtmSetErrorStatus(mosfet_circuit_M, msg_1);
    }
  }

  fmu_LogOutput();
  mosfet_circuit_M->Timing.clockTick0++;
  if (!mosfet_circuit_M->Timing.clockTick0) {
    mosfet_circuit_M->Timing.clockTickH0++;
  }
}

void mosfet_circuit_initialize(void)
{
  (void) memset((void *)mosfet_circuit_M, 0,
                sizeof(RT_MODEL_mosfet_circuit_T));
  (void) memset(((void *) &mosfet_circuit_B), 0,
                sizeof(B_mosfet_circuit_T));
  (void) memset((void *)&mosfet_circuit_DW, 0,
                sizeof(DW_mosfet_circuit_T));
  mosfet_circuit_U.In1 = 0.0;
  mosfet_circuit_Y.Vout = 0.0;

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp_0;
    tmp = nesl_lease_simulator("mosfet_circuit/Solver_1", 1, 0);
    mosfet_circuit_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(mosfet_circuit_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      mosfet_circuit_836bb176_1_gateway();
      tmp = nesl_lease_simulator("mosfet_circuit/Solver_1", 1, 0);
      mosfet_circuit_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    mosfet_circuit_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    mosfet_circuit_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters.mRTWModifiedTimeStamp = 6.92270573E+8;
    modelParameters.mUseModelRefSolver = false;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
    modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters.mIsUsingODEN = tmp_0;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      mosfet_circuit_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      mosfet_circuit_DW.OUTPUT_1_0_Simulator, &modelParameters,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(mosfet_circuit_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(mosfet_circuit_M, msg);
      }
    }

    tmp = nesl_lease_simulator("mosfet_circuit/Solver_1", 0, 0);
    mosfet_circuit_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(mosfet_circuit_DW.STATE_1_Simulator);
    if (tmp_0) {
      mosfet_circuit_836bb176_1_gateway();
      tmp = nesl_lease_simulator("mosfet_circuit/Solver_1", 0, 0);
      mosfet_circuit_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    mosfet_circuit_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    mosfet_circuit_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_0.mRTWModifiedTimeStamp = 6.92270573E+8;
    modelParameters_0.mUseModelRefSolver = false;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_0.mIsUsingODEN = tmp_0;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      mosfet_circuit_DW.STATE_1_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      mosfet_circuit_DW.STATE_1_Simulator, &modelParameters_0, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(mosfet_circuit_M));
      if (tmp_0) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(mosfet_circuit_M, msg_0);
      }
    }
  }
}

void mosfet_circuit_terminate(void)
{
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    mosfet_circuit_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    mosfet_circuit_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("mosfet_circuit/Solver_1");
  nesl_destroy_registry();
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    mosfet_circuit_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    mosfet_circuit_DW.STATE_1_SimData);
  nesl_erase_simulator("mosfet_circuit/Solver_1");
  nesl_destroy_registry();
}
