#include <vector>
#include <algorithm>
using namespace std;
struct Point2D {
    int x;
    int y;
};
// Helper to count points in rectangle (ox, oy) to (ox+w, oy+h)
int countPoints(const vector<Point2D>& points, int ox, int oy, int w, int h) {
    int count = 0;
    for (const auto& pt : points) {
        if (pt.x >= ox && pt.x <= ox + w && pt.y >= oy && pt.y <= oy + h)
            count++;
    }
    return count;
}
int solution(vector<Point2D> &points, int perimeter) {
    int maxCount = 0;
    // Try every possible rectangle size: a and b such that 2*(a+b) == perimeter
    for (int a = 1; a < perimeter / 2; ++a) {
        int b = perimeter / 2 - a;
        if (b < 1) 
          continue;
        // Try every possible placement
        for (const auto& p1 : points) {
            for (const auto& p2 : points) {
                int ox = min(p1.x, p2.x);
                int oy = min(p1.y, p2.y);
                int count = countPoints(points, ox, oy, a, b);
                maxCount = max(maxCount, count);
            }
        }
    }
    return maxCount;
}
