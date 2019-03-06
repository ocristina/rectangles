# rectangles
This repro contains a VS2017 solution.

The solution contains three projects
 - RectIntersect, a library with the classes needed
 - Rectangles, the program executable that uses the library to compute intersections
 - Unit Tests, a project that verifies that the classes work correctly
 
To build the solution, it is enough to open it into VS and build the rectangles project as it has its dependencies correctly set.
Also, the IDE will find the unit tests if the test explorer window is open. Clickin on the "Run All" link will cause it to run all of them

Finally, on the "examples" folder there are a couple of example files with 1, 4 and 32 rectangles.
