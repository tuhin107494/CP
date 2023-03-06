#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool isInsidePolygon(Point point, vector<Point> polygon) {
    int n = polygon.size();
    int intersectCount = 0;
    
    for (int i = 0; i < n; i++) {
        Point currVertex = polygon[i];
        Point nextVertex = polygon[(i + 1) % n];
        
        // check if point is on the polygon boundary
        if ((point.x == currVertex.x && point.y == currVertex.y) ||
            (point.x == nextVertex.x && point.y == nextVertex.y)) {
            return true;
        }
        
        // check if line from point to infinity intersects with edge
        if ((point.y > currVertex.y && point.y <= nextVertex.y) ||
            (point.y > nextVertex.y && point.y <= currVertex.y)) {
            int xIntersection = (point.y - currVertex.y) * (nextVertex.x - currVertex.x) / (nextVertex.y - currVertex.y) + currVertex.x;
            
            if (xIntersection == point.x) {
                return true;
            }
            
            if (xIntersection > point.x) {
                intersectCount++;
            }
        }
    }
    
    return intersectCount % 2 != 0;
}

int main() {
    vector<Point> polygon = {{0, 0}, {0, 4}, {4, 4}, {4, 0}}; // square with side length 4
    Point point1 = {2, 2}; // inside the square
    Point point2 = {5, 5}; // outside the square
    
    if (isInsidePolygon(point1, polygon)) {
        cout << "Point 1 is inside the polygon." << endl;
    } else {
        cout << "Point 1 is outside the polygon." << endl;
    }
    
    if (isInsidePolygon(point2, polygon)) {
        cout << "Point 2 is inside the polygon." << endl;
    } else {
        cout << "Point 2 is outside the polygon." << endl;
    }
    
    return 0;
}
