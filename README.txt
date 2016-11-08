Task
-----

Given 4 distinct points, Ai(xi, yi), i=1,4, find the intersection of segments [A1A2] and [A3A4].


Implemented solution
---------------------

We find the equations for lines A1A2 and A3A4.  
A1A2 : a1*x + b1*y + c1 = 0  
A3A4 : a2*x + b2*y + c2 = 0  
  
We calculate the determinant of the matrix of the system. 
 
         |a1   b1|  
D  =  |           | = a1*b2 - b1*a1    
         |a2   b2|  

We have 2 cases:  
  
**1) D != 0** 
In this case, the intersection of the lines is a point, for which we calculate the x and y coordinates.
  
    |-c1  b1|  
    |           |  
    |-c2  b2|	
x = ---------
          D  

     |a1  -c1|  
     |           |  
     |a2  -c2|	
y = ---------
          D  
  
We check if the point is also inside the [A1A2] and [A3A4] segments.  
  
**2) D = 0** 
We calculate the rank of the matrix.
-If rank = 2 we have no solution for the system and the segments do not intersect.  
-If rank = 1 then lines A1A2 and A3A4 are equal.
Now we have to figure the position of the points and of the segments to determine their intersection.
We consider A1 before A2 and A3 before A4 to minimize the number of possible cases (we use a swap function in implementation).  
We narrow it down to 6 cases:
A1 A2 A3 A4  => segments do not intersect  
A3 A4 A1 A2  => segments do not intersect  
A1 A3 A4 A2  => intersection is segment [A3A4]  
A3 A1 A2 A4  => intersection is segment [A1A2]  
A1 A3 A2 A4  => intersection is segment [A3A2]  
A3 A1 A4 A2  => intersection is segment [A1A4]
  

Use of variables/functions
-------------------------

-point -> structure used for points, holding their x and y coordinates  
-lineEquation(point A, point B, int &a, int &b, int &c) -> in a, b, c we calculate the coefficients of the equation for line determined by A and B   
-isOnSegm(point A, point B, point P) -> checks if point P is on segment [AB]  
-calc() -> determines and prints the intersection of the segments [A1A2] and [A3A4] 