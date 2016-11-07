#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");

struct point{
    int x, y;
}A1, A2, A3, A4;

void lineEquation(point A, point B, int &a, int &b, int &c){//a, b, c are the coefficients of the equation for line determined by A and B
    a = A.y - B.y;
    b = B.x - A.x;
    c = A.x*B.y - B.x*A.y;
}

bool isOnSegm(point A, point B, point P){//we check if point P is on segment [AB]
    //we already know P is on the line A and B determine
    if (((A.x <= P.x && P.x <= B.x) || (A.y >= P.y && P.y >= B.y)) && ((A.y <= P.y && P.y <= B.y) || (A.y >= P.y && P.y >= B.y))) return true;
    return false;
}

void calc(){
    int a1, b1, c1, a2, b2, c2;
    lineEquation(A1, A2, a1, b1, c1);//coefficients of equation for line A1A2
    lineEquation(A3, A4, a2, b2, c2);//coefficients of equation for line A2A3

    //we have a system of two equations and we calculate the determinant
    int delta = a1*b2 - a2*b1;
    if (delta != 0) {
        float x = (-c1*b2 + b1*c2)/delta;
        float y = (-a1*c2 + a2*c1)/delta;

        point intersection;
        intersection.x = x;
        intersection.y = y;
        if (isOnSegm(A1, A2, intersection) && isOnSegm(A2, A3, intersection)) cout << "Point of intersection: (" << x << ", " << y << ")";
            else cout << "Segments do not intersect";
    }
    else {
        int mRank = 1; //rank of matrix
        if ((a1*b2 - a2*b1 != 0) || (b1*c2 - c1*b2 != 0)) mRank = 2;
        if (mRank == 2) cout << "Segments do not intersect";
            else { //in this case we have segments on the same line: A1A2 = A3A4
                //we order A1 and A2 by their x values (if they are not equal) in order to minimize the number of cases
                if (A1.x == A2.x) {
                    //x coordinates are equal so we order by the y values; the solution depends on the order of the points
                    if (A1.y > A2.y) swap(A1.y, A2.y);
                    if (A3.y > A4.y) swap(A3.y, A4.y);
                    if (A2.y < A3.y) cout << "Segments do not intersect"; //order is A1 A2 A3 A4
                    else
                     if (A4.y < A1.y) cout << "Segments do not intersect"; //order is A3 A4 A1 A2
                     else
                      if (A1.y < A3.y && A4.y < A2.y) cout << "Segment from (" << A3.x << ", " << A3.y << ") to (" << A4.x << ", " << A4.y << ")"; //order is A1 A3 A4 A2
                      else
                       if ((A3.y < A1.y && A2.y < A4.y)) cout << "Segment from (" << A1.x << ", " << A1.y << ") to (" << A2.x << ", " << A2.y << ")"; //order is A3 A1 A2 A4
                       else
                        if (A1.y < A3.y && A3.y < A2.y && A2.y < A4.y) cout << "Segment from (" << A3.x << ", " <<A3.y << ") to (" << A2.x << ", " << A2.y << ")"; //order is A1 A3 A2 A4
                        else
                         if (A3.y < A1.y && A1.y < A4.y && A4.y < A2.y) cout << "Segment from (" << A1.x << ", " << A1.y << ") to (" << A4.x << ", " << A4.y << ")"; //order is A3 A1 A4 A2
                }
                else {
                    if (A1.x > A2.x) swap(A1, A2);
                    if (A3.x > A4.x) swap(A3, A4);
                    if (A2.x < A3.x) cout << "Segments do not intersect"; //order is A1 A2 A3 A4
                    else
                     if (A4.x < A1.x) cout << "Segments do not intersect"; //order is A3 A4 A1 A2
                     else
                      if (A1.x < A3.x && A4.x < A2.x) cout << "Segment from (" << A3.x << ", " << A3.y << ") to (" << A4.x << ", " << A4.y << ")"; //order is A1 A3 A4 A2
                      else
                       if ((A3.x < A1.x && A2.x < A4.x)) cout << "Segment from (" << A1.x << ", " << A1.y << ") to (" << A2.x << ", " << A2.y << ")"; //order is A3 A1 A2 A4
                       else
                        if (A1.x < A3.x && A3.x < A2.x && A2.x < A4.x) cout << "Segment from (" << A3.x << ", " << A3.y << ") to (" << A2.x << ", " << A2.y << ")"; //order is A1 A3 A2 A4
                        else
                         if (A3.x < A1.x && A1.x < A4.x && A4.x < A2.x) cout << "Segment from (" << A1.x << ", " << A1.y << ") to (" << A4.x << ", " << A4.y << ")"; //order is A3 A1 A4 A2
                }

            }
    }
}

int main()
{
    f >> A1.x >> A1.y >> A2.x >> A2.y >> A3.x >> A3.y >> A4.x >> A4.y;
    calc();
    return 0;
}
