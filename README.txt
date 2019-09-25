Course: 	COMP 5421 - Advanced Programming, Summer 2019
Assignment:	04
Student: 	Vladislav Melnikov
ID:			40077621
Professor:	Sadegh Ghaderpanah
TA:			Yanal Alahmad

IMPORTANT:
*	The project is compiled and tested using Visual Studio 19 without forced-include "stdafx.h".
*	On a different machine, it may be necessary to include "stdafx.h" in each of the .cpp files of the project.


PROJECT PURPOSE:
Model a slot machine by manipulating shapes with a hierarchy of shape classes, making ample use of polymorphism.

RELEASE NOTES:
* As operator<< for Grid is overloaded in the driver provided as a part of the assignment, its functionality is not used anywhere outside of the driver .cpp file.
* Similar functionality is implemented in SlotMachine.cpp, but without <<operator overloaded.
* The code is written and tested in accordance with the description and the testing listings provided in the assignment.

PROGRAM STRUCTURE and EXECUTION:
- The code for Shapes is provided in the hierarchy of classes: Shape, Rhombus, Rectangle, Triangle, AcuteTriangle and RightTriangle, with .h and .cpp files for all classes.
- Classes Shape and Triangle are virtual.
- The driver called "shape_slotmachine_driver.cpp" that was a part of the assignment is also submitted in the package.