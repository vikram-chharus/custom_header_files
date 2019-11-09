#include<iostream>
#include<windows.h>
using namespace std;
void printTillNow(string word,int index)
{
	for(int i=0;i<=index;i++)
	{
		cout<<word[i];
	}
}
void alpha(string word,int index)//(a,b,c,d,e...)
{
	for(int i=33;i<60;i++)
	{
		printTillNow(word,index);
		cout<<(char)i;
		Sleep(0.01);
		system("cls");
	}
}
void animateWord(string word)//call this function with a string parameter to animate the word while printing
{
	for(int i=0;i<word.length();i++)
	{
		alpha(word,i);
	}
}
