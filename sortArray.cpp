#include <iostream>
#include <iomanip>
using namespace std;

int frameSize;
const int FRAME_SIZE_LIMIT = 25;

bool getFrameSize();
void getNumsInput();
void swap(float,int);
void display(float*,int);
void bubbleSort(float*,int);

int main ()
{
    if(getFrameSize())
    {
        getNumsInput();
    }
    return 0;
}

bool getFrameSize()
{
    cout << "Enter Frame Size" << endl;
    cin >> frameSize;
    
    if(frameSize > FRAME_SIZE_LIMIT)
    {
        cout << "Number is greater than " << FRAME_SIZE_LIMIT;
        return false;
    } 
    else if (frameSize % 2 == 0)
    {
        cout << "Number is not odd";
        return false;
    }
    return true;
}

void getNumsInput()
{
    float numArr[frameSize]; 
    float num;
    cout << "Enter Numbers" << endl;
    for(int i = 0; i < frameSize; i++)
    {
        cin >> numArr[i];
    }
    bubbleSort(numArr,frameSize);
    display(numArr,frameSize);
}

void swap(float &a, int &b) 
{     
   float temp;
   temp = a;
   a = b;
   b = temp;
}

void display(float* array, int size) 
{
   for(int i = 0; i<size; i++)
   {
     cout << setprecision(3) << fixed << array[i] << " ";
   }
      
   cout << endl;
}

void bubbleSort(float* array, int size) 
{
   for(int i = 0; i<size; i++) 
   {
      int swaps = 0;      
      for(int j = 0; j<size-i-1; j++) 
      {
         if(array[j] > array[j+1]) 
         {       
            swap(array[j], array[j+1]);
            swaps = 1; 
         }
      }
      if(!swaps)
         break;      
   }
}
