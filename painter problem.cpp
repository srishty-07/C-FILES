/*You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to
 paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of
 board. Return the ans % 10000003

Input Format

First line contains three space seperated integers N,K and T ,where
N = Size of array,
K = No of painters available ,
T = Time taken to print each board by one painter
Next line contains N space seperated positive integers denoting size of N boards.

Constraints
1<=N<=100000
1<=K<=100000
1<=T<=1000000
1<=Li<=100000

Output Format
Return minimum time required to paint all boards % 10000003.

Sample Input
2 2 5
1 10
Sample Output
50
Explanation
The first painter can paint the first board in 5 units of time and the second painter will take 50 units of time to paint the second board. Since both
 can paint simultaneously , the total time required to paint both the boards is 50.*/
#include<iostream>
#include<algorithm>

using namespace std;//spoj book allocation problem
#define ll long long int
#define MOD 10000003
bool ispossible(ll boardsize[],ll boardnumbers,ll painter,ll currentmintimesuchthatalltheboardarepainted,ll time){
    ll painterused=1;
    ll boardspainting=0;
    for (ll i = 0; i <boardnumbers; ++i)
    {
    	if ((boardspainting)+((boardsize[i])*time)>currentmintimesuchthatalltheboardarepainted)
    	{
            boardspainting=boardsize[i]*time;
    		painterused++;

    		if(painterused>painter){
    			return false;
    		}

    	}
    	else{
    		boardspainting+=(boardsize[i]*time);
    	}
    }
    return true;


}
ll find_min_time(ll boardsize[],ll n,ll painter,ll time){
    ll sum=0;
    // if(books<students){
    // 	return -1;
    // }

    //count the number of pages
    for (ll i = 0; i < n; ++i)
    {
    	sum+=boardsize[i];

    }
    //making search spaces as pages

    ll maxi=0;
  for(ll i=0;i<n;i++){
        maxi=max(maxi,boardsize[i]);
  }
    //making search spaces as pages
    ll s=maxi*time;
 sum*=time;
    ll e=sum;
    ll ans=s;
    while(s<=e){
          ll mid=(s+e)/2;
		//   cout<<s<<' '<<e<<' '<<mid<<endl;
          if(ispossible(boardsize,n,painter,mid,time)){
              //here ans will be equal to mid
          	ans=mid;
          	e=mid-1;
          }
          else{
          	//it is not possible to divide at the mid pages
          	//increase the  number of pages
          	s=mid+1;
          }




    }
//take mod of ans as ans can have greater value
       return ans%MOD;

}
int main(){
    ll n;
    ll painter;
    ll time;
    cin>>n>>painter>>time;
   ll boardsize[100005]={0};
    for (ll i = 0; i < n; ++i)
    {
    	cin>>boardsize[i];
    }
	// sort(boardsize,boardsize+n);
    cout<<find_min_time(boardsize,n,painter,time)%MOD<<endl;
	return 0;
}
