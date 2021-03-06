float** forwardKin(float* Q) {
  // Q = [theta1, theta2, theta3, theta4, theta5]
  // ANGLES ARE IN RADIANS
  float T0_1[4][4], T1_2[4][4], T2_3[4][4], T3_4[4][4], T4_5[4][4];
  float T0_2[4][4], T0_3[4][4], T0_4[4][4], T0_5[4][4];
  
  /* transformation matrices */
  T0_1 = multiply(RotX(0), multiply(TransX(0), multiply(TransZ(D1), RotZ(Q[0]))));
  T1_2 = multiply(RotX(-PI/2), multiply(TransX(-A1), multiply(TransZ(0), RotZ(Q[1]-PI/2))));
  T2_3 = multiply(RotX(0), multiply(TransX(A2), multiply(TransZ(0), RotZ(Q[2]))));
  T3_4 = multiply(RotX(0), multiply(TransX(A3), multiply(TransZ(0), RotZ(Q[3]))));
  T4_5 = multiply(RotX(PI/2), multiply(TransX(A4), multiply(TransZ(D5), RotZ(Q[4]))));
  
  T0_2 = multiply(T0_1, T1_2);
  T0_3 = multiply(T0_2, T2_3);
  T0_4 = multiply(T0_3, T3_4);
  T0_5 = multiply(T0_4, T4_5);
  
  return T0_5;
  // T0_5 = [X0_5; Y0_5; Z0_5; r0E]
  //        [   0;    0;    0;   1]
}
    
float* RotX(float theta) {
  float rot[4][4];
  
  // Initializing all elements of result matrix to 0
  for(i=0; i<4; ++i) {
    for(j=0; j<4; ++j) {
      rot[i][j] = 0;
    }
  }
  
  rot[0][0] = 1;
  rot[1][1] = cos(theta);
  rot[1][2] = -sin(theta);
  rot[2][1] = sin(theta);
  rot[2][2] = cos(theta);
  rot[3][3] = 1;
  
  return rot;
}
    
float* RotZ(float theta) {
  float rot[4][4];
  
  // Initializing all elements of result matrix to 0
  for(i=0; i<4; ++i) {
    for(j=0; j<4; ++j) {
      rot[i][j] = 0;
    }
  }
  
  rot[0][0] = cos(theta);
  rot[0][1] = -sin(theta);
  rot[1][0] = sin(theta);
  rot[1][1] = cos(theta);
  rot[2][2] = 1;
  rot[3][3] = 1;
  
  return rot;
}
    
float TransX(float a) {
  float trans[4][4];
  
  // Initializing all elements of result matrix to 0
  for(i=0; i<4; ++i) {
    for(j=0; j<4; ++j) {
      trans[i][j] = 0;
    }
  }
  
  // set displacement
  trans[0][3] = a;
  
  trans[0][0] = 1;
  trans[1][1] = 1;
  trans[2][2] = 1;
  trans[3][3] = 1;
  
  return trans;
}
    
float TransZ(float a) {
  float trans[4][4];
  
  // Initializing all elements of result matrix to 0
  for(i=0; i<4; ++i) {
    for(j=0; j<4; ++j) {
      trans[i][j] = 0;
    }
  }
  
  trans[2][3] = a;
  
  trans[0][0] = 1;
  trans[1][1] = 1;
  trans[2][2] = 1;
  trans[3][3] = 1;
  
  return trans;
}

// assumes input matrices are 4x4
float* multiply(float* m1, float* m2) {
  float out[4][4];
  
  // Initializing all elements of result matrix to 0
  for(i=0; i<4; ++i) {
    for(j=0; j<4; ++j) {
      out[i][j] = 0;
    }
  }
  
  // multiply matrices
  for(i=0; i<4; ++i) {
    for(j=0; j<4; ++j) {
      for(k=0; k<4; ++k) {
        out[i][j]+=m1[i][k]*m2[k][j];
      }
    }
  }
  
  return out;
}
