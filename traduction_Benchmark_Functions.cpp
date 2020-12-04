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
//
//
//==RASTRIGIN==
//
//f(x,y) = 10*n + SUM [ x[i]^2 - 10 cos(2*M_PI*x[i]) ]
//
//UB = 5.12, LB = -5.12, DIM = d
//
//SUM --> de (i=1) a d
//
//Solution: f(x*) = 0 --> x* = ( 0, ... , 0 )
//
//
//
//==ACKLEY==
//
//f(x) = f( x1, ... , xn) = -20 * exp ( -0.2 * sqrt( (1/d) * SUM [ x[i]^2 ] ) - exp ( (1/d) * SUM [ cos(2*M_PI*x[i] ] ) + 20 + exp(1)
//
//UB = 32, LB = -32, DIM = d
//
//SUM --> de (i=1) a d
//
//Solution: f(x*) = 0 --> x* = ( 0, ... , 0 )
//
//
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
//
//
//==SCHAFFER==
//
//-Version 1-
//
//f(x,y) = 0.5 + ( (sin(x^2 + y^2)^2)^2 - 0.5 ) / (1 + 0.001*( x^2 + y^2 )^2
//
//UB = 100, LB = -100, DIM = 2 (i=1, i=2)
//
//Solution: f(x*) = 0 --> x* = ( 0, 0 )
//
//-Version 2-
//
//f(x,y) = 0.5 + ( (sin(x^2 - y^2)^2) - 0.5 ) / (1 + 0.001*( x^2 + y^2 )^2
//
//UB = 100, LB = -100, DIM = 2 (i=1, i=2)
//
//Solution: f(x*) = 0 --> x* = ( 0, 0 )
//
//-Version 3-
//
//f(x,y) = 0.5 + ( (sin(cos( abs(x^2 - y^2) ))^2 - 0.5 ) / (1 + 0.001*( x^2 + y^2 )^2
//
//UB = 100, LB = -100, DIM = 2 (i=1, i=2)
//
//Solution: f(x*) = 0.00156685 --> x* = ( 0, 1.253115 )
//
//
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
//
