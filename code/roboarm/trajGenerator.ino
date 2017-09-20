

float* PolySolve(x0, xdot0, xf, xdotf, tf) {
  float coef[4], A[4][4], B[4][1];
  
  A = {{1, 0, 0, 0},
       {0, 1, 0, 0},
       {1, tf, tf^2, tf^3},
       {0, 1, 2*tf, 3*tf^2}};
  B = {{x0},
       {xdot0},
       {xf},
       {xdotf}};
  
  //coef = inv(A)*B... shits fucked
}
