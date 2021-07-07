// Daylan Quinn
// Program #4
// 3/31/2019
// Professor Bingham

// Algorithm: 
// 1. Create vector of type student to store current information about membership and items from input file
// 2. Take from another input file to adjust previous vector to current checkouts
// 3. Take from another input file to adjust previous vector to current checkins
//    # not exactly sure how the checkins were applied since they did not have ID along with
//		them so I just let it go random and whoever checked in an item is applied randomly. ¯\_(# #)_/¯
// 4. Take the created vector and output it to be used another day.								 V
// 
// I strayed away from the recomended path during this one. I just started going and forgot to look at the
// guidelines and next thing I knew I was almost done and had done things a different way. It has a few 
// bugs that I've noticed, but I'm currently stuck with them. As for prepping for bad input I did not know
// to expect other than file input being incorrect so I dropped the ball on that one. I'll call it a 
// "learning" experience.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "RecCenter.h"
using namespace std;

int main() {

	vector<Student> Members;

	//CREATES VECTOR OF TYPE STUDENT WITH ALL INFO
	Members = Student_Members();

	//CREATES SIMILAR VECTOR BUT WITH CURRENT CHECKOUTS APPLIED
	Members = Members_Checkouts(Members);
	
	//CREATES SIMILAR VECTOR BUT WITH CURRENT CHECKINS APPLIED
	Members = Members_End(Members);

	//WRITES ALL UPDATED INFO TO OUTPUT FILE
	Output_file(Members);

	return 0;
}
