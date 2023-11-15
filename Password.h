#ifndef PRACTICE_H
#define PRACTICE_H

#include <string>
#include <vector>

using std::string;

class Password
{
private:
	std::vector<string> pass_history;
public:
  /*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
  */
  int count_leading_characters(string);
  bool has_mixed_case(string);
  Password();
  void set(string);
  bool authenticate(string);
};
#endif
