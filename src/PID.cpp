#include "PID.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <math.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

//PID::~PID() {}

void PID::Init(Coeffs coeffs) {
	
	Kp_ = coeffs.Kp;
	Ki_ = coeffs.Ki;
	Kd_ = coeffs.Kd;
	
	p_error =0;
	i_error =0;
	d_error =0;
	
	prev_error =0;
	i = 0;
	
	sum_of_elements =0;
	average_error = 0;
	previous_av_error = 1000;
	dd = 0.001;
	
}

void PID::UpdateError(double cte) {
	
	
	p_error = cte;
	
	i_error += cte;
	
	d_error = (cte - prev_error);  
	
	prev_error = cte;
	
	sum_cte.push_back(cte);
	
	increase = false;
	//cout << "cte_vector_size = "<< sum_cte.size() << endl;
}	
	
void PID::UpdateCoeff(double cte, Coeffs coeffs) {
	 
	 
	Kp_ = coeffs.Kp;
	Ki_ = coeffs.Ki;
	//Kd_ = coeffs.Kd;
	 
	//Tuning algorithm 
	if (fabs(dd) > 0.0001) {
		
		if (sum_cte.size()>=1000) {
			cout << "aktuell Kd_ =" << Kd_ << endl;
			sum_of_elements = accumulate(sum_cte.begin(),sum_cte.end(), 0.0);
			average_error = fabs(sum_of_elements/sum_cte.size());
			cout << "average_error =" << average_error << endl;
				
			if (average_error < previous_av_error && i>2) {
					
				
				dd *= 0.6;
				increase = true;
				
			}else{  	
					
				if (increase ==true){
					dd *= -0.3*dd;
					increase = false;
					
				}else{ 
					dd = -1*dd;
					increase = false;
				}
				
			}
			
			previous_av_error = average_error;
			
			if (i>0){
				Kd_ += dd;
				cout << " neu Kd_ =" << Kd_ << endl; 
				cout << "dd  = " << dd << endl;
			}
			sum_cte.clear();
			i++;
			
		} 	
	} 
	
}

double PID::TotalError() {
	
	return -Kp_ * p_error - Ki_ * i_error - Kd_ * d_error;
}

