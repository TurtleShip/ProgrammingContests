#include <iostream>
using namespace std;

typedef long long LL;

LL seq[200010];
int empty = -1;

typedef struct Sequence {
	int firstPos; // first position of this sequence
	int firstPosWithValue; // first position of this sequence that contains nonempty value
	int secondPosWithValue; // second position of this sequence that contains nonempty value
	LL increment; 
	bool hasIncrement;

	// Note that increment = empty can't be used because increment can be -1
	Sequence() {
		firstPos = empty;
		firstPosWithValue = empty;
		secondPosWithValue = empty;
		hasIncrement = false;
	}

	void reset(int curPos) {
		firstPos = curPos;
		firstPosWithValue = empty;
		secondPosWithValue = empty;
		hasIncrement = false;

	}
	// Return what the value of this position should be
	LL getValueAt(int pos) {
		LL distance = LL(pos - firstPosWithValue);
		return seq[firstPosWithValue] + distance *  increment;
	}

} Sequence;
int main() {
	
	int N;

	cin>>N;

	for(int i=0; i < N; i++)
		cin>>seq[i];

	int numOfSeq = 1; // The total number of sequence.

	Sequence curSequence;

	for(int curPos=0; curPos < N; curPos++) {
		int value = seq[curPos];

		if(curSequence.firstPos == empty) {
			curSequence.firstPos = curPos;
		}

		if(value == empty) {

			if(curSequence.hasIncrement) {
				LL correctValue = curSequence.getValueAt(curPos);
				if(correctValue <= 0) {
					numOfSeq++;
					curSequence.reset(curPos);
				}
			}

		} else {

			if(curSequence.firstPosWithValue == empty) {
				curSequence.firstPosWithValue = curPos;
			} else if(curSequence.secondPosWithValue == empty) {
				curSequence.secondPosWithValue = curPos;
				// check if the sequence we saw so far is valid
				int distance = curPos - curSequence.firstPosWithValue;
				int diffInValue = seq[curPos] - seq[curSequence.firstPosWithValue];

				if(diffInValue % distance == 0) {
					curSequence.increment = LL(diffInValue / distance);
					curSequence.hasIncrement = true;
					// check if we can fill empty ones
					bool isValid = true;
					for(int prevPos = curSequence.firstPos; isValid && prevPos < curPos; prevPos++) {
						if(seq[prevPos] == empty) {
							LL correctValue = curSequence.getValueAt(prevPos);
							if(correctValue <= 0) isValid = false;
						}
					}
					if(!isValid) {
						numOfSeq++;
						curSequence.reset(curPos);
						curSequence.firstPos = curSequence.firstPosWithValue = curPos;	
					}
				} else {

					// Form a new sequence starting from here
					numOfSeq++;
					curSequence.reset(curPos);
					curSequence.firstPos = curSequence.firstPosWithValue = curPos;
				}
				
			} else {
				int correctValue = curSequence.getValueAt(curPos);
				if(correctValue != seq[curPos]) {
					numOfSeq++;
					curSequence.reset(curPos);
					curSequence.firstPos = curSequence.firstPosWithValue = curPos;
				}
			}
		}
	}
	cout<<numOfSeq<<endl;

	return 0;
}