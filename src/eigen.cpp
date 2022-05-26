#include <algorithm>
#include <chrono>
#include <iostream>
#include "eigen.h"

using namespace std;


pair<double, Vector> power_iteration(const Matrix& X, unsigned num_iter, double eps)
{
    Vector b = Vector::Random(X.cols());
    double eigenvalue;
    float diff = 1;
	for (int i = 0; i < num_itter && diff > eps; i++)
	{
		Vector w = X * b;
		w = w / w.norm();
		diff = abs(w.norm() - b.norm()); // esto esta bien?
		b = w;
	}
	eigenvalue = (b.transpose() * (X * b));
	eigenvalue = eigenvalue / (b.transpose() * b);

    return make_pair(eigenvalue, b / b.norm());
}

pair<Vector, Matrix> get_first_eigenvalues(const Matrix& X, unsigned num, unsigned num_iter, double epsilon)
{
    Matrix A(X);
    Vector eigvalues(num);
    Matrix eigvectors(A.rows(), num);

	for(int i = 0; i < num; i++){
		pair<double, Vector> lambAndVect = power_iteration(A, num_iter, epsilon);
		double lambda = lambAndVect[0];
		Vector autovec = lambAndVect[1];
        eigvalues[i] = lambda;
        eigvectors[i] = autovec;
		A = A - lambda*(autovec * autovec.transpose());

	}
    return make_pair(eigvalues, eigvectors);
}
