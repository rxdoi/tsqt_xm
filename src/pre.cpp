#include<bits/stdc++.h>
using namespace std;

vector<string> V;
vector<int> I;

int main(){
	int n;
	string s,t;
	int v;
	while (cin>>s>>t>>v){
		V.push_back(s+t);
		I.push_back(v);
	}
	for (string s:V) printf("\"%s\",",s.c_str());
	puts("");
	for (int i:I) printf("%d,",i);
	puts("");
}