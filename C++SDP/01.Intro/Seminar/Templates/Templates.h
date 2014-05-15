template <typename T>
T min (T left,T right)
{
	if (left < right)
	{
		return left;
	}
	return right;
}

char* min (char* left, char* right)
{
	if (strcmp(left,right) < 0)
	{
		return left;
	}
	return right;
}

template <typename T>
void swap (T &y,T &x)
{
	T temp = x;
	x=y;
	y=temp;
}

template <typename T>
void sorf (T* Array, int lenght)
{
	for (int i = 0; i <= lenght - 2 ; i++)
	{
		T min = Array[i];
		int minIndex = i;
		for (int j = i + 1; j < lenght - 1; j++)
		{
			if (min < Array[j])
			{
				min = Array[j];
				minIndex = j;
			}
		}
		swap<T> (Array[i],Array[minIndex]);
	}
}