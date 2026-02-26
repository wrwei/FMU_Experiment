# FMU_Experiment

## Project Overview
FMU (Functional Mock-up Unit) simulation experiments — translating Simulink models to OpenModelica and running them via FMPy.

## Models

### mosfet_circuit.fmu
- Simulink (R2023a), FMI 2.0 Co-Simulation
- Input: `In1`, Output: `output` (Volts)
- 12V input -> 2V steady output
- No tunable parameters exposed

### BuckConverter.mo / BuckConverter.fmu
- Translated from `buck2slx.slx` (Simulink) to OpenModelica
- 36V -> 24V buck DC-DC converter with PI control + feedforward
- Components: MOSFET switch, freewheeling diode, 800uH inductor, 300uF output cap, 1uF input cap, 1 Ohm load
- Control: PI (P=0.01, I=5) + feedforward (24/36), 100kHz PWM
- **Must use Model Exchange + CVode solver** — Co-Simulation DASSL diverges

## Tools & Environment
- **Python**: 3.12 with `fmpy`, `openpyxl`
- **OpenModelica**: v1.26.2 at `C:/Program Files/OpenModelica1.26.2-64bit/bin/omc.exe`
- **FMPy**: `fmpy.simulate_fmu()` for running FMUs from Python
- **OMEdit**: Graphical editing of .mo files

## Key Patterns

### Running FMUs with FMPy
```python
# Simple constant input
input_signal = np.array([(t, val) for t in times], dtype=[('time', 'f8'), ('In1', 'f8')])
result = fmpy.simulate_fmu('model.fmu', input=input_signal)

# Switching circuits — use Model Exchange + CVode
result = fmpy.simulate_fmu('model.fmu', fmi_type='ModelExchange', solver='CVode')
```

### OpenModelica Initialization for Switching Circuits
- Use `InitialOutput` or `NoInit` — never `SteadyState` (no steady state exists)
- Match capacitor initial voltage to parallel voltage source: `v(start=36, fixed=true)`
- Set explicit initial conditions on all state variables
- Use `Goff >= 1e-5` on IdealDiode to avoid singular matrices

### OMEdit Graphical Wiring
- Connect statements need `annotation(Line(points=..., color=...))` for wires to render
- Electrical: `color={0,0,255}`, Signal: `color={0,0,127}`, Boolean: `color={255,0,255}`

### OpenModelica CLI
```bash
# Check model
omc script.mos  # with loadModel(Modelica); loadFile("model.mo"); checkModel(Model);

# Simulate
simulate(Model, startTime=0, stopTime=0.5, method="dassl");
```
