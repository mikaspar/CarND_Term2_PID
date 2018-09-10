# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Desription

Project includes an implementation PID Controller in C++ keeeping the simulated vehicle on the track by means of controlling the steering angle with constant throttle.

P - Proportional part attempts to minimize the current measured misalignment between the trajectory and vehicle position.
I - Integral part integrates the measured misalignment attemtps to minimize it. (Corrects the bias caused e.q. by construction misalignment of the steered wheels.)
D - Calculates the gradient of the misaligment and attempts to minimize it.

## Parameter tuning

There are several possibilities of tuning the parameters. It this project I used the manual tuning combined with an primitive algorithm to to tune the D - parameter (inspired with twiddle algorithm). A model based control will be much useful and stable way of constructing the controller for this use case.






