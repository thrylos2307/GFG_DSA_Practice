#include <bits/stdc++.h>
using namespace std;
struct greaters{  
bool operator()(const long& a,const long& b) const{  
    return a>b;  
}  
};

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		std::vector<int> v;
		int n,k,temp,i=0;
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			v.push_back(temp);
		}
		scanf("%d",&k);
		if(k>n/2){
		
		make_heap(v.begin(),v.end(),greaters());
		for(i=0;i<n-k;i++){
		pop_heap(v.begin(),v.end());
		v.pop_back();
		}
		cout<<v.front();
		}
		
		else{
			make_heap(v.begin(),v.end(),greaters());
		for(i=0;i<k;i++){
		pop_heap(v.begin(),v.end());
		v.pop_back();
		}
		cout<<v.front();
		}
	
		cout<<endl;
	}
	return 0;
}
