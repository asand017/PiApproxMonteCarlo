#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

bool in_circle(double& x, double& y){
 
    if(((x*x) + (y*y)) < 1){
	return true;
    }

    return false;
}

double estimate_pi(const int& n){

    double x = 0; // x coordinate
    double y = 0; // y coordinate

    double inside = 0;

    for(unsigned int i = 0; i < n; i++){
	x = (double)rand() / (double)RAND_MAX;
        y = (double)rand() / (double)RAND_MAX;


	if(in_circle(x,y)){
	    inside++;
	}
    }

    double pi = 4.0 * (inside / (double)n); 

    return pi;
}


int main(){
    srand(time(NULL));

 
    cout << left << setw(11) << "N" << setw(11) << "Estimate" << setw(20) << "Difference" << endl;

    double est = 0;  
    unsigned int n = 1;
    while(n < 10000001){
	est = estimate_pi(n);
	cout << setw(11) << n << setw(11) << est << setw(20) << abs(est - M_PI) << endl;
	n *= 10;
    }


    return 0;
}
