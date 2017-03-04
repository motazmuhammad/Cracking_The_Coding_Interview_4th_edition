#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool characters[256];
bool is_unique(string s)// an O(n) solution
{
	for(int i=0;i<s.length();i++)
	{
		if(characters[s[i]]) return false;
		characters[s[i]]=true;
		
	}
	return true;
}
bool is_unique2(string s)// an O(n^2) solution that does not use extra memory
{
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<s.length();j++)
		{
			if(i!=j&&s[i]==s[j]) return false;
		}
	}
	return true;
}
void test()
{
	vector<string> v;
	v.push_back("");// test an empty string
	v.push_back("a");// test a signle charachter
	v.push_back("who is it?");// test repetition to be non-Alphabet
	v.push_back("Really");//test the repetition to be an Alphabet
	v.push_back("John");//test if the bool array is really cleared
	cout<<"testing is_unique"<<endl;
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<256;j++) characters[j]=false;
		cout<<is_unique(v[i])<<' '<<v[i]<<endl;

	}
}
int main()
{
	test();

	return 0;
}