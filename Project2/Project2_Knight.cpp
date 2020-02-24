/***************************************************************************
 * Name: Nicholas Knight
 * Email: nrknight@email.sc.edu
 * Date/Time of Completion: 11:10 PM Sunday 10/27/2019
 * 
 * Function: Depth first search on an Adj Matrix to help our mouse friend
 * 
 * Input: File redirect a "maze" file 
 * Output: the order of the nodes on how to get through the maze and 
 * 			the number of operations
 * 
 * Additional comments: The order is backwards, but still correct
 * 						Also your Maze2.txt did not have the correct 
 * 						values.	(It ended at D4) I fixed it for testing
 *                                                                         *
 ***************************************************************************/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

stack<int> dfsStack;
int numOps=0;

stack<int> dfs(vector< vector<int> > arr, int source,vector<bool> visited) {
	dfsStack.push(source);	//push source
	numOps++;
	visited[source] = 1;
	bool edge = false;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[source][i] == 1 && visited[i] == 0) {
			edge = true;
			dfs(arr, i, visited);
		}
	}
	if (!edge && dfsStack.top() != arr.size()-1) {
		dfsStack.pop();
		numOps++;
	}
	return dfsStack;
}

int main (int argc, char **argv)
{
	int size;

	//get size of matix
	cin >> size;
	//used to print the size of the matrix
	//cout << size << endl;
	vector<bool> visited(size);

	//make the matix and populate it
	vector<vector <int> > arr(size);
	int tmp;
	for(int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cin >> tmp;
			arr[i].push_back(tmp);
		}
	}
	//during testing this was used to print the matrix
	// for(int i = 0; i < size; ++i) {
	// 	for (int j = 0; j < size; ++j) {
	// 		cout << arr[i][j];
	// 	}
	// 	cout << endl;
	// }
	vector<char> verts;
	char tmpC;
	cin >> tmpC;	//take in S
	for(int i = 0; i < (size * 2) -4; ++i) {
		char label;
		cin >> label;
		verts.push_back(label);	
	}
	cin >> tmpC;	//take in E
	//make visited bool vector with 0 at the start
	for(int i = 0; i < size; ++i) {
		visited.at(i)=0;
	}
	
	//do the dfs
	dfsStack=dfs(arr,0, visited);
	//print the order ... which is backwards... but still correct
	cout << "Order of nodes: (E -> S)" << endl;
	while(!dfsStack.empty()) {
		if (dfsStack.top()==0) {
			cout << "S " ;
		}
		else if (dfsStack.top() == size -1)
			cout << "E, ";
		else {
			//this handles getting the correct label for the D's and G's 
			//it looks weird because of how I took them in
			//but it gets the correct labels
			cout << verts[(dfsStack.top() *2) - 2] << verts[(dfsStack.top() *2) - 1] << ", ";
		}
		dfsStack.pop();
	}
	cout << endl;
	cout << "Number of operations: " << numOps << endl;
	return 0;
}
