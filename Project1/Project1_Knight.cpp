/***************************************************************************
 * Name: Nicholas Knight
 * Email: nrknight@email.sc.edu
 * Date/Time of Completion: 08/28/19 5:50 pm
 * 
 * Function: Starting point for C++ code.
 * 
 * Input: Program will ask for 5 numbers from the user. 
 * Output: The program will output the sum of those 5 numbers
 * 
 * Additional comments: 
 *                                                                         *
 ***************************************************************************/

#include <cstdlib>
#include <iostream>


using namespace std;


int main (int argc, char **argv)
{
	//bool repeat = true;
	cout << "Hello World!" << endl; 
	while (true) {
		cout << "Give me 5 numbers: "; 
		int a(0),b(0), c(0), d(0), e(0); 
		cin >> a >> b >> c >> d >> e; 
		if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
			return 0;
		int sum = a + b + c + d + e;	
		
		cout << "The sum of the 5 numbers is: " << sum << endl;
	}
	

}
