#include <iostream>
#include <math.h>
using namespace std;

template <typename T>
void InsetionSortWithStep(T* arr,int size_c,int step)
{
    for(int i = 0 ; i < size_c ;i+=step)
    {
        int currentIndex = i;
        for(int j = i-step ;j >= 0;j-=step)
        {
            if(arr[currentIndex] < arr[j])
            {
                swap(arr[currentIndex],arr[j]);
                currentIndex = j;
            }
        }
    }
}
template <typename T>
void ShellSort(T* arr,int size_c)
{
    int k = 1;
    int step = size_c/(pow(2,k++));
    while(step > 1)
    {

        InsetionSortWithStep(arr,size_c,step);
        step = size_c/(pow(2,k++));
    }
}
int main()
{
    int arr[6] = {4,7,5,2,4,3};
    ShellSort(arr,6);
    for(int i = 0 ; i< 6; i++ )
    {
        cout << arr[i];
    }
    return 0;
}
