#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

#define pb(x) push_back(x)

/*
	Given an augmented matrix "matrix",
	return the rank of the matrix if we are in modulo "modulo"
	If equations cannot be satisfied, -1 is returned.
	This is modeled after Vexorian's implementation of Gaussian-Jordan Elimination.
*/
int findRank(vector< vector<int> > matrix, const int& modulo) {
	int nE = matrix.size();
	int nV = matrix[0].size() - 1;

	vector<bool> used(nE, false);

	// perform row-reduction
	for(int varIdx = 0; varIdx < nV; varIdx++) {

		// find the row with non-zero coefficient for this variable
		int pivotIdx = -1;
		for(int eqIdx=0; pivotIdx == -1 && eqIdx < nE; eqIdx++) {
			if(used[eqIdx]) continue;
			if(matrix[eqIdx][varIdx] != 0) {
				used[eqIdx] = true;
				pivotIdx = eqIdx;
			}
		}

		if(pivotIdx == -1) continue;

		for(int eqIdx = 0; eqIdx < nE; eqIdx++) {
			if(used[eqIdx]) continue;
			if(matrix[eqIdx][varIdx] == 0) continue;

			int coeff = 1;
			while((matrix[pivotIdx][varIdx] * coeff + matrix[eqIdx][varIdx]) % modulo != 0)
				coeff++;

			for(int i=0; i <= nV; i++) {
				matrix[eqIdx][i] = (matrix[pivotIdx][i] * coeff + matrix[eqIdx][i]) % modulo;
			}
		}
	}

	// rank is the number of independent rows(= nonzero rows)
	int rank = nE;
	bool isValid = true;
	for(int eqIdx = 0; isValid && eqIdx < nE; eqIdx++) {
		bool isAllZero = true;
		for(int varIdx = 0; isAllZero && varIdx < nV; varIdx++)
			isAllZero &= matrix[eqIdx][varIdx] == 0;

		if(isAllZero) {
			rank--;
			isValid &= matrix[eqIdx][nV] == 0;
		}
	}

	return isValid ? rank : -1;
}

int main() {

	return 0;
}