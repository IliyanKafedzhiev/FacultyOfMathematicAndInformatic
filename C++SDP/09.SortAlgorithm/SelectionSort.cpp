#include <iostream>

using namespace std;

template <typename T>
void SlectionSort(T* arr,int size_c)
{
    for(int j = 0 ; j < size_c ;j++)
    {
        int minIndex = j;
        for(int i = j+1;i < size_c;i++)
        {
            if(arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
        }
        swap(arr[j],arr[minIndex]);
    }
}
int main()
{
    int arr[6] = {4,3,5,2,4,7};
    SlectionSort(arr,6);
    for(int i = 0 ; i< 6; i++ )
    {
        cout << arr[i];
    }
    return 0;
}
