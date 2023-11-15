#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string s){
	int lower = 0;
	int upper = 0;

	for(int i = 0; i < s.length(); i++)
	{
		if(isalpha(s[i]) && islower(s[i]))
		{
			lower = 1;
		}
		if(isalpha(s[i]) && isupper(s[i]))
		{
			upper = 1;
		}
		if(lower == 1 && upper == 1)
		{
			return true;
		}
	}
	return false;
}

Password::Password() {
	pass_history.push_back("ChicoCA-95929");
}

void Password::set(string s) {
	if(s.length() == 8 && count_leading_characters(s) > 3 && has_mixed_case(s) && !authenticate(s))
	{
		pass_history.push_back(s);
	}
}

bool Password::authenticate(string s) {
	if(pass_history[pass_history.size()-1] == s)
	{
		return true;
	}
	return false;
}

