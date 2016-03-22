#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	short lines;
	cin>>lines;

	string capo[200];
	int i = 0;
	do {
		cin>>capo[i];
	} while (i<200 && capo[i++]!="\n");


	return 0;
}