/***************************************************************************
 * Name: Nicholas Knight
 * Email: nrknight@email.sc.edu
 * 
 * Function: This program does two different types of mulitiplication algos
                The first algo is brute force mulitiplication and the second
                is KaratSuba multiplication. These are both for large numbers
                (so large they are stored in vectors).
    Date: 12/3/2019 5:00 PM
 * 
 * Additional comments: KaratSuba is not complete. There are bugs that cause it to crash. 
 *                                                                         *
 ***************************************************************************/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<int> BruteForceMult(vector<int>, vector<int>);
vector<int> KaratMult (vector<int>, vector<int>);
vector<int> vectorAddition (vector<int>, vector<int>);

int main (int argc, char **argv){
	while (true) {      //used to test multiple times
	char c_num; 
	vector<int> number1, number2;
	
	//Read in number 1
	while(cin >> c_num && c_num != '*')
	{
		number1.push_back((int)c_num - 48); 
	}
	
	//Read in number 2
	while(cin >> c_num)
	{
		number2.push_back((int)c_num - 48);
		if(cin.peek() == '\n') break;
	}
	while (number2.size() < number1.size()) {
        number2.insert(number2.begin(), 0);
    }
    while (number1.size() < number2.size()) {
        number1.insert(number1.begin(), 0);
    }
	
	//Check to see if numbers filled properlly. 
	for(int i = 0; i < number1.size(); i++)
	{
		cout << number1[i] << " "; 
	}
	cout << endl;
	
	for(int i = 0; i < number2.size(); i++)
	{
		cout << number2[i] << " "; 
	}
	cout << endl;
    
    // Brute Force
    vector <int> result = BruteForceMult(number1, number2);
    cout << "B:" << endl;
     // print the answer
    for (int i = 0; i < result.size(); ++i)
        cout << result.at(i);
    cout << endl;

    // Karatsuba
    cout << "K: " << endl;
    result = KaratMult(number1, number2);
    
    // print the answer
    for (int i = 0; i < result.size(); ++i)
        cout << result.at(i);
    cout << endl;
}
}

vector<int> BruteForceMult(vector<int> num1, vector<int> num2) {
    while(num1.size() > num2.size()) 
            num2.push_back(0);
        while(num2.size() > num1.size())
            num1.push_back(0);
    vector<int> result;

    //set up the vector for the result
    for (int i = 0; i < num1.size() * 2; ++i)
        result.push_back(0);
    
    //do the multiplication
    
    for (int i = num2.size() - 1; i > -1; --i) {
        int carry = 0;                                                  //carry int
        for (int j = num1.size() ; j > 0; --j) {
            result.at(i + j) += carry + (num2.at(i) * num1.at(j - 1));  //set result to n1*n2 and add carry adjust later
            carry = result.at(i + j) / 10;                              //set carry
            result.at(i + j) = result.at(i + j) % 10;                   //fix the result to just 1 digit
            //cout << "*";                                              //used during testing to see number of loops
        }
        
        result.at(i + num2.size() - 2) += carry; 
    }

    return result;
   
    //Done!
}
vector<int> vectorMultiply (vector<int> num1, vector<int> num2) {
    return BruteForceMult(num1, num2);
}
vector<int> vectorAddition (vector<int> num1, vector<int> num2) {
    while(num1.size() > num2.size()) 
        num2.push_back(0);
    while(num2.size() > num1.size())
        num1.push_back(0);
    vector<int> result;
    //set up the vector for the result
    for (int i = 0; i < num1.size() + 1; ++i)
        result.push_back(0);
    
    for (int i = num1.size() - 2; i > -1; --i) {
        int carry = 0;                                              //carry int
        result.at(i+1) += carry + (num2.at(i) + num1.at(i));        //set result to n1*n2 and add carry adjust later
        carry = result.at(i+1) / 10;                                //set carry
        result.at(i+1) = result.at(i+1) % 10;                       //fix the result to just 1 digit
        result.at(i + num2.size() - 2) += carry; 
    }

    return result;
}
// vector subtraction does not work 
vector<int> vectorSubtraction(vector<int> num1, vector<int> num2) {
    while(num1.size() > num2.size()) 
            num2.push_back(0);
        while(num2.size() > num1.size())
            num1.push_back(0);
    return num1;
}
// currently this just returns num1
// it has bugs that can cause it to crash
// basic ideas are there just not finished
vector<int> KaratMult (vector<int> num1, vector<int> num2) {
    if (num1.size() <= 2) {
        return vectorMultiply(num1, num2);
    }
    else {
        while(num1.size() > num2.size()) 
            num2.push_back(0);
        while(num2.size() > num1.size())
            num1.push_back(0);
        //m = half the size for the numbers
        int m = num1.size() / 2;

        // a0 = bottom half of num1
        vector<int> a0;
        for (int i = 0; i < m; ++i) {
            a0.push_back(num1.at(num1.size() - i -1));
        }

        // a1 = top half of num1
        vector<int> a1;
        for (int i = 0; i < m; ++i) {
            a1.push_back(num1.at(m - i -1));
        }

        // b0 = bottom half of num2
        vector<int> b0;
        for (int i = 0; i < m; ++i) {
            b0.push_back(num2.at(num2.size() - i -1));
        }

        // b1 = top half of num2
        vector<int> b1;
        for (int i = 0; i < m; ++i) {
            b1.push_back(num2.at(m - i -1));
        }

        // c2 = KaratMult(a1,b1)
        vector<int> c2;
        c2 = KaratMult(a1,b1);

        // c0 = KaratMult(a0,b0)
        vector<int> c0;
        c0 = KaratMult(a0,b0);

        // c1 = Karatmult (a1 + a0, b1 + b0) - c2 -c0
        vector<int> c1;
        // this line breaks
        // c1 = vectorSubtraction(KaratMult(vectorAddition(a1, a0), vectorAddition(b1, b0)) , vectorAddition(c2, c0));

        // KaratMult(vectorAddition(a1, a0), vectorAddition(b1, b0));     //this is the problem spot



        // this is the idea behind the final return
        // return (10^(2m)) * c2 + (10^m) * c1 + c0;
        return num1;    // obviously not the end goal
    }
    
}