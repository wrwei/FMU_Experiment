#ifndef RTW_HEADER_mosfet_circuit_h_
#define RTW_HEADER_mosfet_circuit_h_
#ifndef mosfet_circuit_COMMON_INCLUDES_
#define mosfet_circuit_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw.h"
#include "mosfet_circuit_836bb176_1_gateway.h"
#endif

#include "mosfet_circuit_types.h"
#include <string.h>

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  real_T INPUT_1_1_1[4];
} B_mosfet_circuit_T;

typedef struct {
  real_T INPUT_1_1_1_Discrete[2];
  real_T OUTPUT_1_0_Discrete;
  real_T STATE_1_Discrete;
  void* OUTPUT_1_0_Simulator;
  void* OUTPUT_1_0_SimData;
  void* OUTPUT_1_0_DiagMgr;
  void* OUTPUT_1_0_ZcLogger;
  void* OUTPUT_1_0_TsInfo;
  void* STATE_1_Simulator;
  void* STATE_1_SimData;
  void* STATE_1_DiagMgr;
  void* STATE_1_ZcLogger;
  void* STATE_1_TsInfo;
  int_T OUTPUT_1_0_Modes;
  int_T STATE_1_Modes;
  boolean_T OUTPUT_1_0_FirstOutput;
  boolean_T STATE_1_FirstOutput;
} DW_mosfet_circuit_T;

typedef struct {
  real_T In1;
} ExtU_mosfet_circuit_T;

typedef struct {
  real_T Vout;
} ExtY_mosfet_circuit_T;

struct tag_RTM_mosfet_circuit_T {
  const char_T *errorStatus;
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
  } Timing;
};

extern B_mosfet_circuit_T mosfet_circuit_B;
extern DW_mosfet_circuit_T mosfet_circuit_DW;
extern ExtU_mosfet_circuit_T mosfet_circuit_U;
extern ExtY_mosfet_circuit_T mosfet_circuit_Y;
extern void mosfet_circuit_initialize(void);
extern void mosfet_circuit_step(void);
extern void mosfet_circuit_terminate(void);
extern RT_MODEL_mosfet_circuit_T *const mosfet_circuit_M;
extern void fmu_LogOutput();

#endif
