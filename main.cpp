#include <iostream>
#include <cmath>

 using namespace std;

 
 
void
generateMatrix (int **array, int t, int startRow, int startColumn)
{
  
 
if (t == 1)
    {
      
 
array[startRow][startColumn] = 1;
      
array[startRow + 1][startColumn] = 1;
      
array[startRow][startColumn + 1] = 0;
      
array[startRow + 1][startColumn + 1] = 1;
    
 
}
  
 
  else
    {
      
 
int nextT = t - 1;
      
 
int nextRow = startRow + pow (2, nextT);
      
 
int nextCol = startColumn + pow (2, nextT);
      
 
 
generateMatrix (array, nextT, startRow, startColumn);
      
generateMatrix (array, nextT, nextRow, startColumn);
      
generateMatrix (array, nextT, nextRow, nextCol);

} 
 
} 
 
void

mulitpyMatrix (int *a, int **matrix, int *b, int numberOfA)
{
  
 
 
 
bool notPrinted;
  
 
for (int i = 0; i < numberOfA; i++)
    {
      
 
 
notPrinted = true;
      
 
int result;
      
 
bool init = false;
      
 
for (int j = 0; j < numberOfA; j++)
	{
	  
 
if (matrix[i][j] == 1)
	    {
	      
 
 
if (init)
		{
		  
 
result ^= a[j];
		
 
}
	      
 
	      else
		{
		  
 
init = true;
		  
 
result = a[j];
		
 
}
	      
 
 
if (notPrinted)
		{
		  
 
cout << "b" << i << " = a" << j;
		  
notPrinted = false;
		
 
}
	      
 
	      else
		{
		  
 
cout << " XOR a" << j;
		
 
}
	    
}
	
 
}
      
 
b[i] = result;
      
 
cout << endl;
    
 
 
}

 
 
 
 
}


 
 
void
binaryAddition (int *arr, int position)
{
  
 
 
int result = arr[position] + 1;
  
 
 
if (result == 2)
    {
      
 
arr[position] = 0;
      
 
binaryAddition (arr, position + 1);
    
 
}
  
 
  else
    {
      
arr[position] = 1;
    
 
}

 
}


 
void
generateRedMuller (int *b, int numberOfVariables, int numberOfA)
{
  
 
 
int *binaryArray = new int[numberOfVariables];
  
 
bool notPrinted = true;
  
 
for (int i = 0; i < numberOfA; i++)
    {
      
 
 
if (b[i] == 1)
	{
	  
 
 
if (notPrinted)
	    {
	      
 
cout << "b" << i;
	      
notPrinted = false;
	    
}
	  
	  else
	    
cout << " XOR  b" << i;
	  
 
for (int j = 0; j < numberOfVariables; j++)
	    {
	      
 
if (binaryArray[j] == 1)
		{
		  
 
cout << "X" << j;
		
 
 
}
	    
 
 
}
	
 
 
 
}
      
binaryAddition (binaryArray, 0);
    
 
 
}

 
 
}


 
int
main ()
{
  
 
 
int numberOfVariables = 0;
  
 
cout << "Enter number of variables" << endl;
  
 
cin >> numberOfVariables;
  
 
 
while (numberOfVariables <= 0)
    {
      
 
cout << "Please Enter number more than 0 " << endl;
      
 
cin >> numberOfVariables;
    
 
}
  
 
int numberOfA = pow (2, numberOfVariables);
  
 
int a[numberOfA];
  
 
cout << "Enter A's Values" << endl;
  
 
for (int i = 0; i < numberOfA; i++)
    {
      
 
int temp;
      
 
cout << "Enter a" << i << endl;
      
cin >> temp;
      
 
while (temp > 1 || temp < 0)
	{
	  
 
cout << "Enter a valid value of A " << endl;
	  
 
cin >> temp;
	
 
}
      
 
a[i] = temp;
    
 
}
  
 
int **matrix = new int *[numberOfA];
  
 
for (int i = 0; i < numberOfA; i++)
    {
      
 
matrix[i] = new int[numberOfA];
      
 
for (int j = 0; j < numberOfA; j++)
	{
	  
 
matrix[i][j] = 0;
    
} 
 
} 
 
generateMatrix (matrix, numberOfVariables, 0, 0);
  
 
 
int *b = new int[numberOfA];
  
 
 
cout << "Relation between b and a " << endl;
  
 
mulitpyMatrix (a, matrix, b, numberOfA);
  
 
cout << endl << endl;
  
 
 
cout << "Conversion to Red Muller " << endl << "F (";
  
 
for (int i = 0; i < numberOfVariables; i++)
    {
      
 
 
if (i == numberOfVariables - 1)
	{
	  
 
cout << "X" << i;
	
 
}
      
 
      else
	
cout << "X" << i << " , ";
    
 
}
  
cout << ") = ";
  
 
generateRedMuller (b, numberOfVariables, numberOfA);
  
 
 
return 0;

}


 
 
 
