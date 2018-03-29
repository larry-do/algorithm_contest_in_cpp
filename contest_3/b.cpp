/*
* Find the distance of closest pair of points
* 1. Sort the points array by X coordinate
* 2. Divide and conquer!!!!!!
*    Note: if the size of array is small(n <= 3) should uses bruteforce method
*    - Divide the sorted point array into 2 part: left part and right part by 
*    a mid element. This element is the vertical line
*    - Conquer the left part and right part as a subproblem. The recursion will
*    be stopped when n <= 3 as the above note
* 3. We have leftMinDist of the left part and rightMinDist of the rest part
*    minDist is the minium of 2 above value
* 4. Now, gather all points which has abs(point.x - midPoint.x) < minDist
* 	 into an array and sort by Y coordinate. Find the tmpMinDist of pair points in this array.
* 5. The result is mininum of minDist and tmpMinDist
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
// this method O(n*logn*logn) time, uses less memory
struct Point{
	long int x, y;
};
bool compareXCoordinate(Point a, Point b){
	return a.x < b.x;
}
bool compareYCoordinate(Point a, Point b){
	return a.y < b.y;
}
double calDistance(Point a, Point b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double bruteForce(Point p[], long int n){
	double tmpMin = 1000000000;
	for(long int i = 0; i < n; i++){
		for(long int j = i + 1; j < n; j++){
			tmpMin = std::min(tmpMin, calDistance(p[i], p[j]));
		}
	}
	return tmpMin;
}
double stripClosest(Point strip[], long int sizeOfStrip){
	std::sort(strip, strip + sizeOfStrip, compareYCoordinate);
	double tmpMin = 1000000000;
	for(long int i = 0; i < sizeOfStrip; i++){
		for(long int j = i + 1; j < sizeOfStrip && (strip[j].y - strip[i].y) < tmpMin; j++){
			tmpMin = std::min(tmpMin, calDistance(strip[i], strip[j]));
		}
	}
	return tmpMin;
}
double findTheClosestPairOfPoints(Point p[], long int n){
	if(n <= 3) return bruteForce(p, n);
	long int mid = n / 2;
	Point midPoint = p[mid];
	double leftDist =  findTheClosestPairOfPoints(p, mid);
	double rightDist = findTheClosestPairOfPoints(p + mid, n - mid);
	double minDist = std::min(leftDist, rightDist);
	Point strip[n];
	long int j = 0;
	for(long int i = 0; i < n; i++){
		if(abs(p[i].x - midPoint.x) < minDist) strip[j++] = p[i];
	}
	return std::min(minDist, stripClosest(strip, j));
}
int main(){
	int t; scanf("%d", &t);
	for(int e = 1; e <= t; e++){
		long int n; scanf("%ld", &n);
		Point p[n];
		for(int i = 0; i < n; i++){
			scanf("%ld%ld", &p[i].x, &p[i].y);
		}
		std::sort(p, p+n, compareXCoordinate);
		printf("%.6f\n", findTheClosestPairOfPoints(p, n));
	}
	return 0;
}
/*
// this approach consumes O(nlogn) time, but uses more memory.
struct Point{
	long int x, y;
};
bool compareXCoordinate(Point a, Point b){
	return a.x < b.x;
}
bool compareYCoordinate(Point a, Point b){
	return a.y < b.y;
}
double calDistance(Point a, Point b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double bruteForce(Point p[], long int n){
	double tmpMin = 1000000000;
	for(long int i = 0; i < n; i++){
		for(long int j = i + 1; j < n; j++){
			tmpMin = std::min(tmpMin, calDistance(p[i], p[j]));
		}
	}
	return tmpMin;
}
double stripClosest(Point strip[], long int sizeOfStrip){
	double tmpMin = 1000000000;
	for(long int i = 0; i < sizeOfStrip; i++){
		for(long int j = i + 1; j < sizeOfStrip && (strip[j].y - strip[i].y) < tmpMin; j++){
			tmpMin = std::min(tmpMin, calDistance(strip[i], strip[j]));
		}
	}
	return tmpMin;
}
double findTheClosestPairOfPoints(Point p[], Point q[], long int n){
	if(n <= 3) return bruteForce(p, n);
	long int mid = n / 2;
	Point midPoint = p[mid];
	Point ql[mid + 1];
	Point qr[n - mid - 1];
	long int l = 0, r = 0;
	for(long int i = 0; i < n; i++){
		if(q[i].x < midPoint.x) ql[l++] = q[i];
		else qr[r++] = q[i];
	}
	double leftDist =  findTheClosestPairOfPoints(p, ql, mid);
	double rightDist = findTheClosestPairOfPoints(p + mid, qr, n - mid);
	double minDist = std::min(leftDist, rightDist);
	Point strip[n];
	long int j = 0;
	for(long int i = 0; i < n; i++){
		if(abs(q[i].x - midPoint.x) < minDist) strip[j++] = q[i];
	}
	return std::min(minDist, stripClosest(strip, j));
}
int main(){
	int t; scanf("%d", &t);
	for(int e = 1; e <= t; e++){
		long int n; scanf("%ld", &n);
		Point p[n], q[n];
		for(int i = 0; i < n; i++){
			scanf("%ld%ld", &p[i].x, &p[i].y);
			q[i] = p[i];
		}
		std::sort(p, p+n, compareXCoordinate);
		std::sort(q, q+n, compareYCoordinate);
		printf("%.6f\n", findTheClosestPairOfPoints(p, q, n));
	}
	return 0;
}
*/