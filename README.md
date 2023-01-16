# Assignment_3_build
### Test assignment for CadExchanger

A programm that implements classes of lines and ellipses and calculates their points and derivates at the parameter t.  
These curves are implemented inheriting an abstract supercalss ACurve2D. 
The programm populates a vector of curves interchangeably between ellipses and lines with generated random parameters (I decided against initializing a random() with a time seed for the sake of reproducibility of the values).

Note: I had a bit of trouble with understanding of the assignment's wording (I couldn't understand if the task conditions applied to 2D-curves or 3D-curves or both). Eventually, I settled on the implementation of 2D-curves in a way that they can be inherited by the 3D ones. I'm not sure if I got it right, but I still want to attach the solution because I'm going to finish and update it in a couple of days even if it's no longer neccesary for the test assignment. 

## Usage
The compilation is done with a Unix Makefile.  
To build run in the root directory of the assignment: 
```
make
./curves [number of curves to calculate] [max value of the curves' parameters]
```
