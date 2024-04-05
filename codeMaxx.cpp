#include <iostream>
using namespace std;

int main()
{
    int elementNum = 0;



    cout << "Please enter the number of elements you would like to sort: " << endl;
    cin >> elementNum; //total number of elements in an array

    if (elementNum == 0)//fail condition
    {
        cout << "Please enter a number greater than zero." << endl;

            return 0;
    }

    cout << "You have chosen to enter " << elementNum << "elements for your list." << endl;

    int* numArray = new int(elementNum); //allocate a dynamic array in memory for unknown size

    cout << "Please now enter the numbers you would like to sort into your array: " << endl;

    for (int i = 0; i < elementNum; i++)
    {
        cin >> numArray[i];

    }

    cout << "You entered: ";

    for (int j = 0; j < elementNum; j++)
    {
        cout << numArray[j] << " ";
    }

    SelectionSort(numArray, elementNum);














}


int SelectionSort(int *arrayU, int &arrayLength)
{
    int maxIndex = 0;
   
    for (int i = 0; i < (arrayLength - 2); i++)
    {
        int maxIndex = i;
        min = A[i]; 

        for (int j = 1; j < (arrayLength - 1); j++)
        {

            arrayU[j] > A[maxIndex];
            maxIndex = j;


        }

        tmp = A[i];
        A[i] = A[maxIndex];
        A[maxIndex] = tmp;
    }

    cout << "The sorted list is now:  ";

    for (int k = 0; k < arrayLength ; k++)
    {
        cout << arrayU[k] << " ";
    }
