#include <MatrixMath.h>

float* PolySolve(float x0, float xdot0, float xf, float xdotf,float tf){
  float coef[4], invA[4][4], result[4][1];
  
  float A[4][4] = {{1, 0, 0, 0},
       {0, 1, 0, 0},
       {1, tf, pow(tf,2), pow(tf,3)},
       {0, 1, 2*tf, 3*pow(tf,2)}};
  float B[4][1] = {{x0},
       {xdot0},
       {xf},
       {xdotf}};
  
  Matrix.Copy((float*)A,4,4,(float*)invA);
  Matrix.Invert((float*)invA,4);
  Matrix.Multiply((float*)invA,(float*)B,4,4,1,(float*)result);
  return (float*)result;
}
//
//void setup(){
//  Serial.begin(115200);
//  float* result = PolySolve(0,0,10,0,10);
//  Matrix.Print(result,4,1,"");
//}
//
//void loop(){
//  
//}

