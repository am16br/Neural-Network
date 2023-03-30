//https://dritchie.github.io/csci2240/assignments/eigen_tutorial.pdf
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
using namespace std;
using namespace Eigen;

//A vector in Eigen is nothing more than a matrix with a single column:
typedef Matrix <float , 3, 1> Vector3f;
typedef Matrix <double , 4, 1> Vector4d;
int main() {
  cout << "Eigen␣version:␣" << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION << endl;

  Matrix3f A;
  Matrix4d B;
  // 5x5 matrix of type short
  //Matrix <short , 5, 5> M1;
  // 20x75 matrix of type float
  //Matrix <float , 20, 75> M2;

  // Initialize A
  A << 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f;
  // Initialize B by accessing individual elements
  for(int i = 1; i<=4; i++) {
    for(int j = 1; j<=4; j++) {
      B(j, i) = 0.0;
    }
  }

  // Set each coefficient to a uniform random value in the range [-1, 1]
  A = Matrix3f::Random();
  // Set B to the identity matrix
  B = Matrix4d::Identity();
  // Set all elements to zero
  A = Matrix3f::Zero();
  // Set all elements to ones
  A = Matrix3f::Ones();

  // Set all elements to a constant value
  B = Matrix4d::Constant(4.5);

  Matrix4f M1 = Matrix4f::Random();
  Matrix4f M2 = Matrix4f::Constant(2.2);
  // Addition
  // The size and the coefficient-types of the matrices must match
  cout << M1 + M2 << endl;
  // Matrix multiplication
  // The inner dimensions and the coefficient-types must match
  cout << M1 * M2 << endl;
  // Scalar multiplication , and subtraction // What do you expect the output to be?
  cout << M2 - Matrix4f::Ones() * 2.2 << endl;

  //Equality (==) and inequality (!=) are the only relational operators that work with matrices.
  //Two matrices are considered equal if all corresponding coefficients are equal.
  cout << ((M2 - Matrix4f::Ones() * 2.2 == Matrix4f::Zero())) << endl;

  // Transposition
  cout << M1.transpose() << endl;
  // Inversion ( #include <Eigen/Dense > )
  // Generates NaNs if the matrix is not invertible
  cout << M1.inverse() << endl;

  // Square each element of the matrix
  cout << M1.array().square() << endl;
  // Multiply two matrices element -wise
  cout << M1.array() * Matrix4f::Identity().array() << endl;
  // All relational operators can be applied element-wise
  cout << (M1.array() <= M2.array()) << endl << endl;
  cout << (M1.array() > M2.array()) << endl;


  Vector3f v;
  // Comma initialization
  v << 1.0f, 2.0f, 3.0f;
  // Coefficient access
  cout << v(2) << endl;
  // Vectors of length up to four can be initialized in the constructor
  Vector3f w(1.0f, 2.0f, 3.0f);
  // Utility functions
  Vector3f v1 = Vector3f::Ones();
  Vector3f v2 = Vector3f::Zero();
  Vector4d v3 = Vector4d::Random();
  Vector4d v4 = Vector4d::Constant(1.8);
  // Arithmetic operations
  cout << v1 + v2 << endl << endl;
  cout << v4 - v3 << endl;
  // Scalar multiplication
  cout << v4 * 2 << endl;
  // Equality
  // Again, equality and inequality are the only relational
  // operators that work with vectors
  cout << (Vector2f::Ones() * 3 == Vector2f::Constant(3)) << endl;

  Vector4f v5 = Vector4f(1.0f, 2.0f, 3.0f, 4.0f);
  // 4x4 * 4x1 - Works!
  cout << Matrix4f::Random() * v5 << endl;
  // 4x1 * 4x4 - Compiler Error!
  cout << v5 * Matrix4f::Random() << endl;

  // Transposition converts the column vector to a row vector
  // This makes the inner dimensions match, allowing matrixmultiplication
  v1 = Vector3f::Random();
  v2 = Vector3f::Random();
  cout << v1 * v2.transpose() << endl;

  cout << v1.dot(v2) << endl << endl;
  cout << v1.normalized() << endl << endl;
  cout << v1.cross(v2) << endl;
  // Convert a vector to and from homogenous coordinates
  Vector3f s = Vector3f::Random();
  Vector4f q = s.homogeneous();
  cout << (s == q.hnormalized()) << endl;

  cout << v1.array() * v2.array() << endl << endl;
  cout << v1.array().sin() << endl;


  return 0;
}
