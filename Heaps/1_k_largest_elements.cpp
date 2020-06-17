#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		std::vector<int> v;
		int n,k,temp,i=0;
		scanf("%d %d",&n,&k);
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			v.push_back(temp);
		}
		for(i=0;i<k;i++){
		
		make_heap(v.begin(),v.end());
		printf("%d ",v.front());
		pop_heap(v.begin(),v.end());
		v.pop_back();
		}
		cout<<endl;
	}
	return 0;
}
