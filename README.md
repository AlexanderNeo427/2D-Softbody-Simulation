# Softbody Physics Simulation

### Description
Pressure soft-body model. 
Each of the circles represents a point-mass in space, and each of the white lines represents a spring that attempts to continuously resolve towards it's resting length.
Uses simple Euler integration for the physics, admittedly imperfect as it is susceptible to issues if the timestep gets too large (notice how it gets stuck in itself sometimes).\
Demo video can be found [here](https://youtu.be/dbthJvaGqBU?si=vR_S9XdlmDYluNIY)

Reference material:
* [Gonkee - Soft Body Physics Explained](https://www.youtube.com/watch?v=kyQP4t_wOGI&t=261s)
* [Maciej Matyka - How to implement a pressure soft body model](https://www.researchgate.net/publication/228574502_How_to_implement_a_pressure_soft_body_model)
