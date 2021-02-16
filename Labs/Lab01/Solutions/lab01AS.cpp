#include <iostream>
#include <string>

int LetterCount(const std::string& word,char ch)
{
	int cnt = 0;
	
	for(int i = 0;word[i] != '\0';i += 1)
	{
		if(word[i] == ch)
		{
			cnt += 1;
		}
	}
	return cnt;
}

bool HasDuplicates(std::string word)
{
	for(int i = 0;word[i] != '\0';i += 1)
	{
		if(LetterCount(word,word[i]) > 1)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	return 0;
}
