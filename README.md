<h1>Terminal CPPlotter</h1>

<h2>Project Description</h2>
<p>The Terminal CPPlotter is a C++ program that creates a Cartesian coordinate system on the terminal, allowing users to plot both points and lines. The project is authored by Saiyam Jain and is distributed under the MIT License.</p>

<h2>Preview</h2>

![Screenshot 2023-11-04 084631](https://github.com/saiyam-sandhir/Terminal-CPPlotter/assets/86138251/4d0a5b07-47fa-4e83-a536-0f08e51d73d3)

![Screenshot 2023-11-04 084452](https://github.com/saiyam-sandhir/Terminal-CPPlotter/assets/86138251/7f67e56b-9e06-40b5-81f4-d2da295f4260)

![Screenshot 2023-11-04 084543](https://github.com/saiyam-sandhir/Terminal-CPPlotter/assets/86138251/2df39ec4-9c39-4e1a-bb0f-18341fcb254a)

![Screenshot 2023-11-09 092654](https://github.com/saiyam-sandhir/Terminal-CPPlotter/assets/86138251/b6a9f13b-f9c7-47cc-b0af-e965024f3a59)

![Screenshot 2023-11-09 092754](https://github.com/saiyam-sandhir/Terminal-CPPlotter/assets/86138251/fa2a2c3e-1432-4dc0-b7ee-b116599784f1)

<h2>Features</h2>
<h5>1. Point Class</h5>
- The Point class represents a point in a Cartesian coordinate system with x and y coordinates.
- It provides constructors to initialize points with default or specified coordinates.
- The | operator overloading allows you to calculate the Euclidean distance between two points.
- The ^ operator overloading calculates the midpoint between two points and returns a new Point.

<h5>2. Line Class</h5> 
- The 'Line' class, enables users to define and work with lines in the Cartesian plane.
- Constructors allow the creation of lines using two points.
- The 'check_for_point' method determines if a given point lies on the line.

<h5>3. CartesianPlane Class</h5>
- The CartasianPlane class creates a Cartesian plane with user-defined dimensions in the terminal.
- It includes a constructor that allows you to set the length of the x and y axes.
- The plot function in this class can plot points on the Cartesian plane.
- It can plot the Cartesian axes, points, and custom symbols for the origin, positive and negative x and y axes.
- The overloaded plot function takes a Point object as input and plots it on the plane.

<h2>Usage</h2>
- Compile the code using a C++ compiler.</br>
- Execute the compiled program.</br>
- Create 'Point' and 'Line' objects with desired coordinates.
- Uitlize the 'plot' functions to visualize points and lines on the cartesian plane.
  
<h2>License</h2>
This project is licensed under the MIT License, granting you the freedom to use, modify, and distribute the code as per the MIT License terms.

For more details on the MIT License, please refer to the provided LICENSE file or visit the <a href="https://opensource.org/licenses/MIT">MIT License</a> website.
