#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstring>

using namespace std;

bool in_triangle(double& x, double& y){
    if((x + y > 1) && (x < 1) && (y < 1)){ 
	return true;
    }
    return false;
}

bool in_lens(double& x, double& y){
    if((x + y > 1) && (x < 1) && (y < 1) && (((x*x) + (y*y)) < 1)){
	return true;
    }
    return false;
}

double* new_pi_sequence(const int& n){

    double x = 0; // x coordinate
    double y = 0; // y coordinate

    double seq_x [n];
    double seq_y [n];

    double pi_est [n];

    for(unsigned int i = 0; i < n; i++){
	x = (double)rand() / (double)RAND_MAX;
	y = (double)rand() / (double)RAND_MAX;

	seq_x[i] = x;
	seq_y[i] = y;
    }

    for(unsigned int i = 0; i < n; i++){
	double in_tri = 0;
	double in_l = 0;
	
	for(unsigned int p = 0; p < i; p++){
	    if(in_triangle(seq_x[p], seq_y[p])){
		in_tri++;
	    }
	
	    if(in_lens(seq_x[p], seq_y[p])){
		in_l++;
	    }
	}
	 pi_est[i] = (2.0*(in_l / in_tri)) + 2;

    }
   
    return pi_est; 
}

int main(){
    srand(time(NULL));

    ofstream ex3;
    ex3.open("ex3.csv");
    for(unsigned int j = 0; j < 6; j++){
	double pi_seq[2000];
	memcpy(pi_seq, new_pi_sequence(2000), sizeof(pi_seq));	
	
	for(unsigned int i = 0; i < 2000; i++){
	    if(i != 1999){
		ex3 << pi_seq[i] << ",";
	    }else{
		ex3 << pi_seq[i];
	    }
	}
	ex3 << endl;
    }
	
    ex3.close();
    
    return 0;
}
