# Robotic Finger Control System

An experimental robotics project combining Arduino programming, physical prototyping, dynamic modeling, and digital signal processing.

## Overview

This project investigates how unwanted signal fluctuations affect the control of a robotic finger and how digital filtering can reduce their impact.

I fabricated and assembled the finger prototype myself, integrated its servo-driven actuation, and studied the control system through experimental observations and mathematical modeling.

The central engineering question was:

**How can a robotic finger follow an input command smoothly while remaining responsive to changes?**

The work connects embedded implementation with control theory: observe the signal, characterize the disturbances, implement a filter, and evaluate the resulting trade-off.

## My Contribution

- Fabricated and assembled the physical finger prototype.
- Integrated the mechanical structure, servo actuation, and Arduino-based electronics.
- Programmed analog input acquisition and servo angle control.
- Implemented a first-order digital low-pass filter.
- Compared signal behavior before and after filtering.
- Analyzed system dynamics using transfer functions, time responses, and Bode diagrams.
- Documented the experimental observations and technical conclusions.

## System Architecture

The prototype uses an Arduino board, potentiometer inputs, an SM-S2309S servo motor, and a cable-driven finger mechanism.

The processing chain is:

**Analog input → Arduino acquisition → Digital filtering → Angle command → Servo motor → Finger movement**

The servo motor drives the finger through a fishing-line transmission. Angle commands are also sent through the serial interface for visualization and analysis.

The experimental scope is a robotic finger, studied within the broader context of human-controlled robotic hands.

## Engineering Approach

### 1. Characterizing the Disturbances

I first examined the unfiltered signal to identify unwanted oscillations.

With a sampling interval of **50 ms**, the observed oscillation period was approximately **0.6 s**, corresponding to a disturbance frequency of approximately **1.66 Hz**.

This step provided a quantitative basis for investigating the filtering solution.

### 2. Modeling the System

The study included a simplified first-order transfer-function model of the initial system.

Time-domain responses and Bode diagrams were used to examine:

- The system’s response to changing inputs.
- The influence of disturbances.
- The effect of adding a low-pass filter.
- The relationship between attenuation and response delay.

### 3. Implementing Digital Filtering

A first-order recursive low-pass filter was implemented on the Arduino:

$$
y[n] = \alpha x[n] + (1-\alpha)y[n-1]
$$

Where:

- `x[n]` is the raw input.
- `y[n]` is the filtered output.
- `α` determines the balance between smoothing and responsiveness.

The filtered input is then converted into a servo angle command.

The presentation compares coefficients of **0.5, 0.3, and 0.1**. Smaller coefficients provide stronger smoothing but introduce a slower response. The illustrated filtered result uses **α = 0.1**.

## Results and Interpretation

| Observation | Without filtering | With filtering |
|---|---|---|
| Reported oscillation amplitude | Approximately 10° | Approximately 3° |
| Signal behavior | Pronounced fluctuations | Smoother variations |
| Response to input changes | Faster | Slower |

The amplitudes reported in the project correspond to an approximate **70% reduction in signal oscillation amplitude**.

These values describe the illustrated signal traces; they do not establish a 70% improvement in physical positioning accuracy.

The main engineering finding is the **trade-off between disturbance attenuation and responsiveness**. Stronger filtering reduces rapid fluctuations, while the additional delay limits how quickly the command follows input changes.

## Technical Skills Applied

| Area | Practical application |
|---|---|
| Embedded programming | Arduino input acquisition, filtering, and servo commands |
| Electronics | Potentiometer interfacing and breadboard prototyping |
| Signal processing | Sampling, oscillation analysis, and recursive filtering |
| Control engineering | Transfer functions, time responses, and Bode analysis |
| Robotics | Mechanical assembly and cable-driven actuation |
| Experimental analysis | Parameter comparison and interpretation of results |

## Further Investigation

A useful next step would be to measure the actual finger angle with an independent sensor and compare it against the commanded position.

This would allow a more complete evaluation using tracking error, response time, and repeated tests under identical conditions. Further work could also examine the influence of cable tension, mechanical play, and friction.
## Prototype & Hardware Setup

The experimental setup includes an Arduino Uno, potentiometer-based finger movement sensing, servomotor actuation, and a robotic finger fabricated using 3D printing.

### Complete Experimental Setup

![Complete Arduino and robotic finger setup](images/complete_setup.jpg)

### Robotic Finger Prototype

![Robotic finger prototype](images/robotic_finger.jpg)

### Sensor and Control Setup

![Sensor and Arduino control setup](images/sensor_control_setup.jpg)

### System Flowchart

The following flowchart illustrates the main stages of the control process, from sensor acquisition to robotic finger actuation.

![Robotic finger control flowchart](images/system_flowchart.png)


## Arduino Implementation

The robotic finger is controlled using an Arduino Uno,
two potentiometer inputs, and two servomotors.

Two versions of the control program were developed to
evaluate the effect of digital filtering on motion stability.

### Before Filtering

The initial program directly converts potentiometer
readings into servo motor commands.

[View Arduino Code — Before Filtering](arduino/before_filtering.ino)

### After Filtering

The improved version implements a first-order digital
low-pass filter with a coefficient of alpha = 0.1.

The filter smooths the sensor readings before converting
them into servo motor commands.

[View Arduino Code — After Filtering](arduino/after_filtering.ino)



