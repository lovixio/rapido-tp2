#include <iostream>
#include "pca.h"
#include "eigen.h"

using namespace std;


PCA::PCA(unsigned int n_components)
{

}

void PCA::fit(Matrix X)
{
}


MatrixXd PCA::transform(Matrix X)
{
  int n = X.cols();
	for(int i = 0; i < n; i++){
		X.col(i) = ( X.col(i) - X.col(i).mean()*Vector::Ones(n) )/sqrt(n-1);
	}

	return X.transpose()*X;
}
