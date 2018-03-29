#include <cstdio>
#include <cmath>
#include <algorithm>
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
		for(long int j = i + 1; j < sizeOfStrip; j++){
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