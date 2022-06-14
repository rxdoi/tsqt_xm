#include<bits/stdc++.h>
using namespace std;

vector<string> V;
vector<int> I;

int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		string s;
		int v;
		cin>>s>>v;
		V.push_back(s);
		I.push_back(v);
	}
	for (string s:V) printf("\"%s\",",s.c_str());
	for (int i:I) printf("%d,",i);
}