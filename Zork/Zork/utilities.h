#ifndef __Utilities__
#define __Utilities__

#include <string>
#include <vector>

using namespace std;

bool Equal(const string& a, const char* b);
bool Equal(const string& a, const string& b);
void Tokenize(const char* str, vector<string>& result);


#endif 
