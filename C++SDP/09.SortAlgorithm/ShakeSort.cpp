#include <iostream>

using namespace std;

template <typename T>
void ShakeSort(T* arr,int size_c)
{
    bool isChanged = false;
    for(int j = 0 ; j < size_c-1 ;j++)
    {
        int i = 0;
        for(;i < size_c-j-1;i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i],arr[i+1]);
                isChanged = true;
            }
        }
        for(int z = size_c-j-1;z > j;z--)
        {
            if(arr[z] < arr[z-1])
            {
                swap(arr[z],arr[z-1]);
                isChanged = true;
            }
        }
        if(!isChanged)
        {
            return;
        }

    }
}
int main()
{
    int arr[6] = {4,7,5,2,4,3};
    ShakeSort(arr,6);
    for(int i = 0 ; i< 6; i++ )
    {
        cout << arr[i];
    }
    return 0;
}
