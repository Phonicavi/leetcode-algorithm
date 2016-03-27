#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void printDay(vector<int> v) {
	for (int i=0; i<v.size(); ++i) {
		cout<<v[i]<<", ";
	}
}


int main(int argc, char const *argv[])
{
	int *p = (int*)malloc(sizeof(int)*1000000000000000000);
	cout<<p<<endl;
	// cout<<sizeof(AA)<<endl;
	vector< vector<int> > List(50);
	int unit=1;
	while (unit<=9) {
		int day = unit;
		List[day].push_back(unit);
		day+=1;
		List[day].push_back(unit);
		day+=2;
		List[day].push_back(unit);
		day+=4;
		List[day].push_back(unit);
		day+=7;
		List[day].push_back(unit);
		day+=11;
		List[day].push_back(unit);
		unit++;
	}

	cout<<" +++ TOEFL VOCABULARY +++ "<<endl;

	for (int i=1; i<List.size(); ++i) {
		if (List[i].size()) {
			cout<<"Day "<<i<<"\nUnit: \t";
			printDay(List[i]);
			cout<<endl;
		}
	}

	return 0;
}