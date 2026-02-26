model BuckConverter
  "36V to 24V Buck DC-DC Converter with PI control - translated from Simulink buck2slx.slx"

  // =====================
  // Power Circuit
  // =====================
  Modelica.Electrical.Analog.Sources.ConstantVoltage dcSource(V = 36)
    "36V DC input source"
    annotation(Placement(transformation(origin = {-160, 30}, extent = {{-10, -10}, {10, 10}}, rotation = -90)));

  Modelica.Electrical.Analog.Basic.Capacitor C_in(C = 1e-6, v(start = 36, fixed = true))
    "Input filter capacitor (1 uF)"
    annotation(Placement(transformation(origin = {-120, 30}, extent = {{-10, -10}, {10, 10}}, rotation = -90)));

  Modelica.Electrical.Analog.Ideal.IdealClosingSwitch mosfet(Ron = 0.01, Goff = 1e-6)
    "MOSFET as ideal closing switch"
    annotation(Placement(transformation(origin = {-70, 60}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Electrical.Analog.Ideal.IdealDiode diode(Ron = 0.3, Goff = 1e-5, Vknee = 0.6)
    "Freewheeling diode"
    annotation(Placement(transformation(origin = {-40, 30}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));

  Modelica.Electrical.Analog.Basic.Inductor inductor(L = 800e-6, i(start = 0, fixed = true))
    "Output inductor (800 uH)"
    annotation(Placement(transformation(origin = {0, 60}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor
    "Inductor current sensor"
    annotation(Placement(transformation(origin = {40, 60}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Electrical.Analog.Basic.Capacitor C_out(C = 300e-6, v(start = 0, fixed = true))
    "Output filter capacitor (300 uF)"
    annotation(Placement(transformation(origin = {80, 30}, extent = {{-10, -10}, {10, 10}}, rotation = -90)));

  Modelica.Electrical.Analog.Basic.Resistor R_load(R = 1)
    "Load resistor (1 Ohm)"
    annotation(Placement(transformation(origin = {110, 30}, extent = {{-10, -10}, {10, 10}}, rotation = -90)));

  Modelica.Electrical.Analog.Sensors.VoltageSensor voltageSensor
    "Output voltage sensor"
    annotation(Placement(transformation(origin = {140, 30}, extent = {{-10, -10}, {10, 10}}, rotation = -90)));

  Modelica.Electrical.Analog.Basic.Ground ground
    "Electrical ground reference"
    annotation(Placement(transformation(origin = {0, -10}, extent = {{-10, -10}, {10, 10}})));

  // =====================
  // Control Loop
  // =====================
  Modelica.Blocks.Sources.Constant vRef(k = 24)
    "Output voltage reference (24V)"
    annotation(Placement(transformation(origin = {-180, -40}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Blocks.Continuous.FirstOrder analogFilter(
    T = 1 / (2 * Modelica.Constants.pi * 100),
    k = 1,
    initType = Modelica.Blocks.Types.Init.InitialOutput,
    y_start = 24)
    "1st-order Butterworth lowpass filter (fc = 100 Hz)"
    annotation(Placement(transformation(origin = {-140, -40}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Blocks.Continuous.LimPID pid(
    controllerType = Modelica.Blocks.Types.SimpleController.PI,
    k = 0.01,
    Ti = 0.002,
    yMax = 1,
    yMin = 0,
    initType = Modelica.Blocks.Types.Init.InitialOutput,
    xi_start = 0,
    y_start = 0.333)
    "PI controller (P = 0.01, I = 5, output limited to [0, 1])"
    annotation(Placement(transformation(origin = {-90, -40}, extent = {{-10, -10}, {10, 10}})));

  // Feedforward path
  Modelica.Blocks.Sources.Constant vRefFF(k = 24)
    "Feedforward: output voltage reference"
    annotation(Placement(transformation(origin = {-180, -80}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Blocks.Sources.Constant vSrcFF(k = 36)
    "Feedforward: source voltage"
    annotation(Placement(transformation(origin = {-180, -110}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Blocks.Math.Division division
    "Feedforward duty cycle = Vref / Vsrc = 24/36"
    annotation(Placement(transformation(origin = {-130, -90}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Blocks.Math.Add add
    "Total duty cycle = PI output + feedforward"
    annotation(Placement(transformation(origin = {-40, -50}, extent = {{-10, -10}, {10, 10}})));

  // PWM generation
  Modelica.Blocks.Sources.SawTooth sawTooth(
    period = 1e-5,
    amplitude = 1)
    "100 kHz sawtooth carrier for PWM"
    annotation(Placement(transformation(origin = {-40, -90}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Blocks.Logical.Greater comparator
    "PWM comparator: duty cycle > carrier => switch ON"
    annotation(Placement(transformation(origin = {10, -60}, extent = {{-10, -10}, {10, 10}})));

equation
  // =====================
  // Power Circuit Connections
  // =====================

  // Input node: DC source positive, input capacitor, MOSFET drain
  connect(dcSource.p, C_in.p)
    annotation(Line(points = {{-160, 40}, {-160, 60}, {-120, 60}, {-120, 40}}, color = {0, 0, 255}));
  connect(dcSource.p, mosfet.p)
    annotation(Line(points = {{-160, 40}, {-160, 60}, {-80, 60}}, color = {0, 0, 255}));

  // Switching node: MOSFET source, diode cathode, inductor input
  connect(mosfet.n, diode.n)
    annotation(Line(points = {{-60, 60}, {-40, 60}, {-40, 40}}, color = {0, 0, 255}));
  connect(mosfet.n, inductor.p)
    annotation(Line(points = {{-60, 60}, {-10, 60}}, color = {0, 0, 255}));

  // Output path: inductor -> current sensor -> output node
  connect(inductor.n, currentSensor.p)
    annotation(Line(points = {{10, 60}, {30, 60}}, color = {0, 0, 255}));

  // Output node: current sensor output, output capacitor, load, voltage sensor
  connect(currentSensor.n, C_out.p)
    annotation(Line(points = {{50, 60}, {80, 60}, {80, 40}}, color = {0, 0, 255}));
  connect(currentSensor.n, R_load.p)
    annotation(Line(points = {{50, 60}, {110, 60}, {110, 40}}, color = {0, 0, 255}));
  connect(currentSensor.n, voltageSensor.p)
    annotation(Line(points = {{50, 60}, {140, 60}, {140, 40}}, color = {0, 0, 255}));

  // Ground connections
  connect(dcSource.n, ground.p)
    annotation(Line(points = {{-160, 20}, {-160, 0}, {0, 0}}, color = {0, 0, 255}));
  connect(C_in.n, ground.p)
    annotation(Line(points = {{-120, 20}, {-120, 0}, {0, 0}}, color = {0, 0, 255}));
  connect(diode.p, ground.p)
    annotation(Line(points = {{-40, 20}, {-40, 0}, {0, 0}}, color = {0, 0, 255}));
  connect(C_out.n, ground.p)
    annotation(Line(points = {{80, 20}, {80, 0}, {0, 0}}, color = {0, 0, 255}));
  connect(R_load.n, ground.p)
    annotation(Line(points = {{110, 20}, {110, 0}, {0, 0}}, color = {0, 0, 255}));
  connect(voltageSensor.n, ground.p)
    annotation(Line(points = {{140, 20}, {140, 0}, {0, 0}}, color = {0, 0, 255}));

  // =====================
  // Control Loop Connections
  // =====================

  // Reference voltage -> lowpass filter -> PID setpoint
  connect(vRef.y, analogFilter.u)
    annotation(Line(points = {{-169, -40}, {-152, -40}}, color = {0, 0, 127}));
  connect(analogFilter.y, pid.u_s)
    annotation(Line(points = {{-129, -40}, {-102, -40}}, color = {0, 0, 127}));

  // Voltage measurement feedback -> PID measurement input
  connect(voltageSensor.v, pid.u_m)
    annotation(Line(points = {{150, 30}, {160, 30}, {160, -120}, {-90, -120}, {-90, -52}}, color = {0, 0, 127}));

  // Feedforward: Vref / Vsrc = 24 / 36
  connect(vRefFF.y, division.u1)
    annotation(Line(points = {{-169, -80}, {-150, -80}, {-150, -84}, {-142, -84}}, color = {0, 0, 127}));
  connect(vSrcFF.y, division.u2)
    annotation(Line(points = {{-169, -110}, {-150, -110}, {-150, -96}, {-142, -96}}, color = {0, 0, 127}));

  // Total duty cycle = PI correction + feedforward
  connect(pid.y, add.u1)
    annotation(Line(points = {{-79, -40}, {-60, -40}, {-60, -44}, {-52, -44}}, color = {0, 0, 127}));
  connect(division.y, add.u2)
    annotation(Line(points = {{-119, -90}, {-60, -90}, {-60, -56}, {-52, -56}}, color = {0, 0, 127}));

  // PWM: compare total duty cycle with sawtooth carrier
  connect(add.y, comparator.u1)
    annotation(Line(points = {{-29, -50}, {-20, -50}, {-20, -54}, {-2, -54}}, color = {0, 0, 127}));
  connect(sawTooth.y, comparator.u2)
    annotation(Line(points = {{-29, -90}, {-20, -90}, {-20, -66}, {-2, -66}}, color = {0, 0, 127}));

  // PWM output -> MOSFET gate control
  connect(comparator.y, mosfet.control)
    annotation(Line(points = {{21, -60}, {30, -60}, {30, 30}, {-70, 30}, {-70, 49}}, color = {255, 0, 255}));

  annotation(
    experiment(
      StartTime = 0,
      StopTime = 0.5,
      Tolerance = 1e-6,
      Interval = 1e-5),
    Documentation(info = "<html>
      <p>Buck DC-DC converter model translated from Simulink (buck2slx.slx).</p>
      <h4>Specifications</h4>
      <ul>
        <li>Input voltage: 36V DC</li>
        <li>Output voltage: 24V (regulated)</li>
        <li>Switching frequency: 100 kHz (period = 10 &mu;s)</li>
        <li>Inductor: 800 &mu;H</li>
        <li>Output capacitor: 300 &mu;F</li>
        <li>Input capacitor: 1 &mu;F</li>
        <li>Load resistor: 1 &Omega;</li>
        <li>Freewheeling diode: Vf = 0.6V, Ron = 0.3 &Omega;</li>
        <li>MOSFET: Ron = 0.01 &Omega;</li>
      </ul>
      <h4>Control</h4>
      <ul>
        <li>PI controller: P = 0.01, I = 5, output limited to [0, 1]</li>
        <li>Feedforward duty cycle: Vref/Vsrc = 24/36 = 0.667</li>
        <li>Reference filter: 1st-order Butterworth, fc = 100 Hz</li>
      </ul>
    </html>"),
    Diagram(coordinateSystem(extent = {{-200, -140}, {180, 80}})));
end BuckConverter;
