#include <iostream>

using namespace std;

template <typename T>
void BubleSort(T* arr,int size_c)
{
    bool isChanged = false;
    for(int j = 0 ; j < size_c-1 ;j++)
    {
        for(int i = 0;i < size_c-j-1;i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i],arr[i+1]);
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
    BubleSort(arr,6);
    for(int i = 0 ; i< 6; i++ )
    {
        cout << arr[i];
    }
    return 0;
}
