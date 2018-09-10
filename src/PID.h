#ifndef PID_H
#define PID_H

#include <vector>

using namespace std;

class PID {




public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double prev_error;
  int i;

  vector<double> sum_cte ;
  double sum_of_elements;
  double average_error;
  double previous_av_error;
  double dd;
  bool increase;
  /*
  * Coefficients
  */ 
  
  
  struct Coeffs {

	double Kp = 0.22;
	double Ki = 0.0005;
	double Kd = 4.5;

  } coeffs;
  
  
  
  double Kp_ ;
  double Ki_ ;
  double Kd_ ;
  
  
   
  
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
   ~PID() {};

  /*
  * Initialize PID.
  */
  void Init(Coeffs coeffs);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  
  /*
  * Update the PID Coefficients.
  */
  void UpdateCoeff(double cte, Coeffs coeffs);

  
 };

#endif /*PID_H */
