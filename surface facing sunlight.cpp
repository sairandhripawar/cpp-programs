// C++ program to count buildings that can 
// see sunlight. 
#include <iostream> 
using namespace std; 

struct Point 
{ 
    int x; 
    int y; 
}; 
// Returns count buildings that can see sunlight 
int countBuildings(int building[], int n) 
{ 
	// Initialuze result (Note that first building 
	// always sees sunlight) 
	int count = 1; 

	// Start traversing element 
	int curr_max = building[0]; 
	for (int i=1; i<n; i++) 
	{ 
		// If curr_element is maximum, 
		// update maximum and increment count 
		if (building[i] > curr_max) 
		{ 
			count++; 
			curr_max=building[i]; 
		} 
	} 

	return count; 
} 

// Driver code 
int main() 
{ 
	 Point building[] = {{4,0},{4,-5},{7,-5},{7,0}}; 
	int n = sizeof(building) / sizeof(building[0]); 
	cout << int countBuildings (building[], int n); 
	return 0; 
} 

