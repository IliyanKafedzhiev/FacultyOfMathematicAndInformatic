//#include <iostream>
//using namespace std;
//void fun(int *array, int size, int *min, int *min , int * max, double * arg)
//{
//	*min=array[0];
//	for(int i=1;i<size;++i)
//		if(*min > array[i])
//			*min=array[i];
//}
//int main()
//{
//	
//
//	fun(a,n,&min,&max,&avg);
//	return 0;
//}

// 3 zadacha
#include <iostream>
using namespace std;
bool isWord(const char* word,const char* text,int len)
{
	if((word == text || *(word-1)==' ') && (word[len] == ' ' || word[len] == '\0'))
		return true;
	return false;
}
int getNextWordLen(const char* text)
{
	int l=0;
	while(text[l] && text[l] !=' ')
		++l;
	return l;
}
int countWord(const char* text, const char* word)
{
	int cnt=0;
	const char * it=text;
	while(it = strstr(it, word))
	{
		if(isWord(it,text,strlen(word)))
				++cnt;
		it=it+strlen(word)+1;
	}
	return cnt;
}

void printMCW(const char*text)
{
	int cnt=0;
	const char* it = text;
	char * best = NULL;
	while(*it)
	{
		int len=getNextWordLen(it);
		char * word=new char[len+1];
		if(!word) return;
		strncpy(word,it,len);
		word[len]=0;
		int c=countWord(it,word);
		if(c>cnt)
		{
			cnt=c;
			delete[] best;
			best=word;
			word=NULL;
		}
		delete[] word;
		it += len+1;
	}
	cout<<best;
	delete[] best;
}
	


void main()
{
	printMCW("zdrasti zdrasti kak si kak si zdrasti");	
}