//Rosenbrock, Rastrigin, Ackley, Schwefel, Schaffer, Weierstrass
//
//
//==ROSENBROCK==
//
//f(x,y) = SUM [ 100 * ( x[i+1] - x[i]^2 )^2 + ( x[i] - 1 )^2 ]
//
//UB = 10, LB = -5, DIM = d
//
//SUM --> de (i=1) a (d-1)
//
//Solution: f(x*) = 0 --> x* = ( 1, ... , 1 )
//
//----EN C++----
//
//Solution s;
//
//double sum = 0;
//
//vector<double> x = s.solution();
// int d = s.Problem().dimension();
//
//for (int i = 0; i < d - 1 ; ++i)
//{ sum += 100 * pow(( x[i+1] - pow( x[i],2)),2) + pow(( x[i] - 1),2); }
//
//return sum;
//
//==RASTRIGIN==
//
//f(x,y) = 10*d + SUM [ x[i]^2 - 10 cos(2*M_PI*x[i]) ]
//
//UB = 5.12, LB = -5.12, DIM = d
//
//SUM --> de (i=1) a d
//
//Solution: f(x*) = 0 --> x* = ( 0, ... , 0 )
//
//----EN C++----
//
//Solution s;
//
//double sum = 0;
//
//vector<double> x = s.solution();
// int d = s.Problem().dimension();
//
//for (int i = 0; i < d ; ++i)
//{ sum += 100 * pow( x[i],2) - 10*cos(2*M_PI*x[i]); }
//
//return 10*d + sum;
//
//==ACKLEY==
//
//f(x) = f( x1, ... , xn) = -20 * exp ( -0.2 * sqrt( (1/d) * SUM [ x[i]^2 ] )) - exp ( (1/d) * SUM [ cos(2*M_PI*x[i] ] ) + 20 + exp(1)
//
//UB = 32, LB = -32, DIM = d
//
//SUM --> de (i=1) a d
//
//Solution: f(x*) = 0 --> x* = ( 0, ... , 0 )
//
//----EN C++----
//
//Solution s;
//
//double sum1 = 0;
//double sum2 = 0;
//
//vector<double> x = s.solution();
// int d = s.Problem().dimension();
//
//for (int i = 0; i < d; ++i)
//{ sum1 += pow( x[i],2); sum2 += cos(2.0*M_PI*x[i]); }
//
//return - (20.0 * exp ((-0.2) * sqrt(sum1/d))) - exp(sum2/d) + 20.0 + exp(1.0);
//
//==SCWEFEL==
//
//f(x) = 418.9829*d - SUM ( x[i]*sin( sqrt( abs(x[i]) ) )
//
//UB = 500, LB = -500, DIM = d
//
//SUM --> de (i=1) a d
//
//Solution: f(x*) = 0 --> x* = ( 420.9687, ... , 420.9687 )
//
//----EN C++----
//
//Solution s;
//
//double sum = 0;
//
//vector<double> x = s.solution();
// int d = s.Problem().dimension();
//
//for (int i = 0; i < d; ++i)
//{ sum +=  x[i]*sin( sqrt( abs(x[i]) )); }
//
//return 418.9829*d - sum;
//
//==SCHAFFER==
//
//-Version 2-
//
//f(x,y) = 0.5 + ( (sin(x^2 - y^2)^2) - 0.5 ) / (1 + 0.001*( x^2 + y^2 )^2
//
//UB = 100, LB = -100, DIM = 2 (i=1, i=2)
//
//Solution: f(x*) = 0 --> x* = ( 0, 0 )
//
//----EN C++----
//
//double x = 0; double y = 0;
//
//return 0.5 + ( sin((pow(pow(x,2) - pow(y,2),2))) - 0.5 ) / ( 1 + 0.001*pow((pow(x,2) + pow(y,2)),2));
//
//==WEIERSTRASS==
//
//f(x) = SUM1 ( SUM2 ( 0.5^k * cos(2 * M_PI * 3^k * (X[i] + 0.5)))) - d * SUM2( 0.5^k * cos(2 * M_PI * 3^k * 0.5))
//
//
//SUM1 --> de (i=1) a d
//SUM2 --> de (k=0) a kmax
//
//kmax = 20, d = 30
//
//----EN C++----
//
//Solution s;
//
//double sum1 = 0;
//double sum2 = 0;
//double sum3 = 0;
//
//vector<double> x = s.solution();
// int d = s.Problem().dimension();
//
//for (int i = 0; i < d; ++i)
//  {
//    for (int k = 0; k < 20; ++k)
//    {
//        sum2 += pow(0.5,k) * cos(2.0 * M_PI * pow(3,k) * (x[i] + 0.5));
//    }
//
//    sum1 += sum2;
//    sum2 = 0;
//  }
//
//  for (int k = 0; k < 20; ++k)
//    {
//        sum3 += pow(0.5,k) * cos(2.0 * M_PI * pow(3,k) * 0.5);
//    }
//
//  return sum1 - d*sum3;
