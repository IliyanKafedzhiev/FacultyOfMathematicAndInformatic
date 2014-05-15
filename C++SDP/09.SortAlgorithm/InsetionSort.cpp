#include <iostream>

using namespace std;

template <typename T>
void InsetionSort(T* arr,int size_c)
{
    for(int i = 0 ; i < size_c ;i++)
    {
        int currentIndex = i;
        for(int j = i-1 ;j >= 0;j--)
        {
            if(arr[currentIndex] < arr[j])
            {
                swap(arr[currentIndex],arr[j]);
                currentIndex = j;
            }
        }
    }
}
int main()
{
    int arr[6] = {4,7,5,2,4,3};
    InsetionSort(arr,6);
    for(int i = 0 ; i< 6; i++ )
    {
        cout << arr[i];
    }
    return 0;
}
