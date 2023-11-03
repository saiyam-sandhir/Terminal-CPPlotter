<h1>Terminal CPPlotter</h1>

<h2>Project Description</h2>
<p>The Terminal CPPlotter is a C++ program that creates a Cartesian coordinate system on the terminal and allows you to plot points on it. The program uses a class-based approach, with two main classes: Point and CartasianPlane. It also includes a custom distance operator (|) and a midpoint operator (^) for points.</p>

<h2>Features</h2>
<h5>1. Point Class</h5>
- The Point class represents a point in a Cartesian coordinate system with x and y coordinates.
- It provides constructors to initialize points with default or specified coordinates.
- The | operator overloading allows you to calculate the Euclidean distance between two points.
- The ^ operator overloading calculates the midpoint between two points and returns a new Point.

<h5>2. CartesianPlane Class</h5>
- The CartasianPlane class creates a Cartesian plane with user-defined dimensions in the terminal.
- It includes a constructor that allows you to set the length of the x and y axes.
- The plot function in this class can plot points on the Cartesian plane.
- It can plot the Cartesian axes, points, and custom symbols for the origin, positive and negative x and y axes.
- The overloaded plot function takes a Point object as input and plots it on the plane.

<h2>Usage</h2>
- STEP1: Compile the code using a C++ compiler:
- STEP2: Execute the compiled program
- STEP3: The program will display the Cartasian plan with the plotted points and their distances.
  
<h2>License</h2>
This project is licensed under the MIT License, granting you the freedom to use, modify, and distribute the code as per the MIT License terms.

For more details on the MIT License, please refer to the provided LICENSE file or visit the <a href="https://opensource.org/licenses/MIT">MIT License</a>website.
