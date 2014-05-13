#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

#define pb(x) push_back(x)

const double EPS = 1e-8;

// return 0 if x == y,   -1 if x < y,    1 if x > y
int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

/*
	Given an augmented matrix "augMat",
	return the rank of the matrix if we are in modulo "modulo"
	This is modeled after Vexorian's implementation of Gaussian-Jordan Elimination.
*/
int findRank(vector< vector<int> >& augMat, const int& modulo) {
	int nE = augMat.size();
	int nV = augMat[0].size() - 1;

	vector<bool> used(nE, false);

	// perform row-reduction
	for(int i=0; i < nV; i++) {

		// find the row with non-zero coefficient for this variable
		int rowIdx = -1;
		for(int j=0; rowIdx == -1 && j < nE; j++) {
			if(used[j]) continue;
			if(augMat[j][i] != 0) {
				used[j] = true;
				rowIdx = j;
			}
		}

		if(rowIdx == -1) continue;

		for(int j=0; j < nE; j++) {
			if(used[j]) continue;
			if(augMat[j][i] == 0) continue;

			int mult = 1;
			while( (augMat[rowIdx][i] * mult + augMat[j][i]) % modulo != 0 )
				mult++;

			for(int k=0; k <= nV; k++)
				augMat[j][k] = (augMat[rowIdx][k] * mult + augMat[j][k]) % modulo;
		}
	}

	int rank = nE;
	bool isValid = true;

	// rank is the number of independent rows(= nonzero rows)
	for(int i=0; isValid && i < nE; i++) {
		bool isZero = true;
		for(int j=0; isZero && j < nV; j++)
			isZero &= augMat[i][j] == 0;
		if(isZero) {
			rank--;
			isValid &= augMat[i][nV] == 0;
		}
	}

	return isValid ? rank : -1;
}

/*
	The below class is a work in progress.
	Eventually I want to make it so that it can solve 
	a system of linear equations.
*/
class GaussianElimination {

private:
	vector< vector<double> > augMat; // augmented matrix of variableMat + valMat
	int nE; // the total number of equations
	int nV; // the total number of variables
	bool isReduced;

public:
	// variableMat.size() == valMart.size() must be satisfied
	GaussianElimination(const vector< vector<double> >& variableMat, const vector<double>& valMat) {
		// create an augmented matrix
		nE = variableMat.size();
		nV = variableMat[0].size();

		augMat.resize(nE);
		for(int i=0; i < nE; i++)
			augMat[i].resize(nV+1); // need one more column to store valMat

		for(int i=0; i < nE; i++) {
			for(int j=0; j < nV; j++)
				augMat[i][j] = variableMat[i][j];
			augMat[i][nV] = valMat[i];
		}

		isReduced = false; // not yet row-reduced
	}

	GaussianElimination(const vector< vector<double> > _augMat) {
		augMat = _augMat;
		nE = augMat.size();
		nV = augMat[0].size() - 1;
		isReduced = false;
	}

	void printMatrix() {
		cout<<"Total equations : "<<nE<<" , Total variables : "<<nV<<endl;

		int variableWidth = 10;
		int decimalPrecision = 2;
		for(int i=0; i < nE; i++) {
			for(int j=0; j < nV; j++)		
				cout<<setw(variableWidth)<<fixed<<setprecision(decimalPrecision)<<augMat[i][j];
			cout<<" | "<<fixed<<setprecision(2)<<augMat[i][nV]<<endl;
		}
	}	

	// Calling it will permantntly change augMat to row-reduced echolon form. (REF)
	void performRowReduction() {

		int sourceEq = 0;

		// go through each variables
		for(int varIdx=0; varIdx < nV; varIdx++) {

			/*
				find the row with the minimum coefficient, and swap the row
				with "sourceRow." Swap is needed to have lower half triangle
				filled with zeros.
			*/
			int targetEq = -1;
			double minCoeff = numeric_limits<double>::infinity();
			for(int eqIdx=sourceEq; eqIdx < nE; eqIdx++) {

				if(cmp(augMat[eqIdx][varIdx], 0.0) != 0) {
					if(cmp(abs(augMat[eqIdx][varIdx]), minCoeff) == -1) {
						minCoeff = abs(augMat[eqIdx][varIdx]);
						targetEq = eqIdx;
					}
				}
			}

			if(targetEq == -1) continue;

			// swap source equation with target equation
			augMat[sourceEq].swap(augMat[targetEq]);

			// Perform forward elimination phase
			for(int eqIdx = 0; eqIdx < nE; eqIdx++) {
				if( cmp(augMat[sourceEq][varIdx]) == 0 ) continue;
				if(eqIdx == sourceEq) continue;

				// If you are working in a modulo world, modify here
				double ratio = augMat[eqIdx][varIdx] / augMat[sourceEq][varIdx];

				// note that we apply to all variables AND the equation value
				for(int i=0; i <= nV; i++) {
					augMat[eqIdx][i] -= ratio * augMat[sourceEq][i];
				}
			}
			sourceEq++;
		}

		isReduced = true;
	}

	int getRank() {
		if(!isReduced) {
			performRowReduction();
		}

		int rank = nE;
		bool isValid = true;
		for(int eqIdx = 0; isValid && eqIdx < nE; eqIdx++) {
			bool allZeros = true;
			for(int varIdx = 0; allZeros && varIdx < nV; varIdx++)
				allZeros &= cmp(augMat[eqIdx][varIdx], 0.0) == 0;
			if(allZeros) {
				isValid &= cmp(augMat[eqIdx][nV], 0.0) == 0;
				rank--;
			}
		}

		return isValid ? rank : -1;
	}

	// solve the system of linear equations and return the result
	vector<double> solveEquations() {
		// I think a system of linear equations are solvable iff nE >= nV.
		// If nE < nV, then there are a system of possible answers.
		assert(nE == nV);
		if(!isReduced) {
			performRowReduction();
		}
		// TODO: implement this
		vector<double> res;
		return res;
	}
};

int main() {
	/*
		The first line of input should be nV and nE where 
		nV = number of variables
		nE = number of equations

		nE lines follow.
		For each line, there are (nV + 1) numbers.
		The first nV numbers represent coefficients for each variable.
		The last number is the value of the equation.

		For example, to input the below system of equations,
		2x + 3y = 5
		3x + y  = 3
		input the below
		2 2
		2 3 5
		3 1 3
	*/
	int nV, nE;
	cin>>nV>>nE;
	vector< vector<double> >augmentedMatrix(nE, vector<double>(nV+1) );
	for(int i=0; i < nE; i++)
		for(int j=0; j <= nV; j++)
			cin>>augmentedMatrix[i][j];
	
	GaussianElimination ge(augmentedMatrix);
	// ge.printMatrix();
	// ge.performRowReduction();
	cout<<ge.getRank()<<endl;
	ge.printMatrix();


	return 0;
}