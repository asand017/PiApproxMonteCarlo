#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstring>

using namespace std;

bool in_circle(double& x, double& y){
    if(((x*x) + (y*y)) < 1){
	return true;
    }

    return false;

}

double* pi_sequence(const int& n){

    double x = 0;
    double y = 0;

    double seq_x [n];
    double seq_y [n]; 

    double pi_est [n];

    for(unsigned int i = 0; i < n; i++){
	x = (double)rand() / (double)RAND_MAX;
   	y = (double)rand() / (double)RAND_MAX;

	seq_x[i] = x;
        seq_y[i] = y;

    }

    for(unsigned int i = 1; i < n + 1; i++){
	double inside = 0;
	for(unsigned int k = 0; k < i; k++){
	    if(in_circle(seq_x[k], seq_y[k])){
                inside++;
	    }
	}	
	pi_est[i-1] = 4.0*(inside / (double)i);
    }

    return pi_est;

}

int main(int argc, char* argv[] ){
    srand(time(NULL));


    ofstream ex2;
    ex2.open("ex2.csv");
    for(unsigned int j = 0; j < 6; j++){
        double pi_seq[2000];
        memcpy(pi_seq, pi_sequence(2000), sizeof(pi_seq));

        for(unsigned int i = 0; i < 2000; i++){
	    if(i != 1999){
	        ex2 << pi_seq[i] << ",";
	    }else{
		ex2 << pi_seq[i];
	    }	    
        }
	ex2 << endl;
    }

    ex2.close();

    return 0;
}
