/* vashishtha07 */

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

void show(vector<string> v){
	int a = v.size();
	for(int i = 0 ; i < a ; i++ ){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t ;
	t = 1 ;
	cin>> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<pair<int,int>> arr(n,{-1,-1}) ;
		
		
		for(int i = 0 ; i < n ; i++){
			int pnr, marks ;
			cin >> pnr >> marks ;
			if(arr[pnr%n].first==-1) {
				arr[pnr%n].first = marks ;
				arr[pnr%n].second = pnr ;
			}
			else{
				for(int j = pnr%n ; j <= pnr%n+n ; j++){
					if(arr[j%n].first==-1){
						arr[j%n].first = marks ;
						arr[j%n].second = pnr ;
						break ;
					}
				}
			}
		}
		
		
		// To delete ;
		
		for(auto val : arr) cout<<val.first<<" "<<val.second<<endl; ;
		int pnr ;
		cin >> pnr ;
		for(int i = pnr%n ; i < pnr%n+n ; i++){
			if(arr[i].second==pnr){
				arr[i].first = -1 ;
				arr[i].second = -1 ;
				break ;
			}
		}
		cout<<endl;
		for(auto val : arr) cout<<val.first<<" "<<val.second<<endl; ;
		
		
		// Linear Probing with chaining without replacement ;
		
		vector<int> chain(n,-1) ;
		for(int i = 0 ; i < n ; i++){
			int pnr, marks ;
			cin >> pnr >> marks ;
			if(arr[pnr%n].first==-1) {
				arr[pnr%n].first = marks ;
				arr[pnr%n].second = pnr ;
			}
			else{
				int flag = 0 ;
				if((arr[pnr%n].second%n)==pnr%n) {
					flag = 1 ;
				}
				int temp = pnr%n ;
				if(chain[pnr%n]!=-1){
					int te = chain[pnr%n];
					while(chain[te]!=-1){
						te = chain[te] ;
					}
					temp = te ;
				}
				for(int j = temp ; j <= temp+n ; j++){
					if(arr[j%n].first==-1){
						arr[j%n].first = marks ;
						arr[j%n].second = pnr ;
						if(flag) chain[temp%n] = j%n ;
						break ;
					}
				}
			}
		}
		for(auto val : arr) cout<<val.first<<" "<<val.second<<endl; ;
		show(chain);
		
		
		// Linear Probing with replacement ;
		
		vector<int> chain(n,-1) ;
		for(int i = 0 ; i < n ; i++){
			int pnr, marks ;
			cin >> pnr >> marks ;
			if(arr[pnr%n].first==-1) {
				arr[pnr%n].first = marks ;
				arr[pnr%n].second = pnr ;
			}
			else{
				int flag = 0 ;
				if((arr[pnr%n].second%n)==pnr%n) {
					flag = 1 ;
					int temp = pnr%n ;
					if(chain[pnr%n]!=-1){
						int te = chain[pnr%n];
						while(chain[te]!=-1){
							te = chain[te] ;
						}
						temp = te ;
					}
					for(int j = temp ; j <= temp+n ; j++){
						if(arr[j%n].first==-1){
							arr[j%n].first = marks ;
							arr[j%n].second = pnr ;
							if(flag) chain[temp%n] = j%n ;
							break ;
						}
					}
				}
				else{
					cout<<pnr<<endl;
					for(int j = pnr%n ; j < pnr%n+n ; j++){
						if(arr[j%n].first==-1){
							arr[j%n].first = arr[pnr%n].first ;
							arr[j%n].second = arr[pnr%n].second ;
							for(int k = 0 ; k < n ; k++){
								if(chain[k]==pnr%n) chain[k] = j%n ;
							}
							arr[pnr%n].first = marks ;
							arr[pnr%n].second = pnr ;
							break ;
						}
					}
				}
			}
		}
		for(auto val : arr) cout<<val.first<<" "<<val.second<<endl; ;
		show(chain);
		
		
		// Seperate Chaining ;
		
		vector<string> v[27] ;
		for(int i = 0 ; i < n ; i++){
			string s ;
			cin >> s ;
			int in = s[0]-'a' ;
			v[in].push_back(s) ;
			// show(v[in]);
		}
		for(int i = 0 ; i < 27 ; i++){
			vector<string> temp = v[i] ;
			cout<<i<<" ";
			show(temp);
		}
		string search ;
		cin >> search ;
		int in = search[0]-'a' ;
		int flag = 0 ;
		for(auto val : v[in]){
			if(val==search) flag = 1 ;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
}