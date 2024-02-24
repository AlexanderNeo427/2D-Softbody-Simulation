# 2D Softbody Simulation

Demo Video: https://www.youtube.com/watch?v=dbthJvaGqBU

Pressure soft-body model. 
Each of the circles represents a point-mass in space, and each of the white lines represents a spring that attempts to continuously resolve towards it's resting length.
Uses simple Euler integration for the physics, admittedly imperfect as it is susceptible to issues if the timestep gets too large (notice how it gets stuck in itself sometimes).

Reference material:
* https://www.youtube.com/watch?v=kyQP4t_wOGI&t=261s
* https://www.researchgate.net/publication/228574502_How_to_implement_a_pressure_soft_body_model
