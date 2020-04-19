#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long int lli;
typedef struct data
{
	data* child[26];
	int cnt=0;
}trie;
lli ans=0;
void insert(string &s,trie* head)
{
	trie* curr=head;
	lli i;
	for(i=0;i<s.length();i++)
	{
		if(!curr->child[s[i]-'A'])
			curr->child[s[i]-'A']=new trie();
		curr=curr->child[s[i]-'A'];
	}
	curr->cnt++;
}
void dfs(trie* curr,lli lvl,lli k)
{
	for(lli i=0;i<=25;i++)
	{
		if(curr->child[i])
		{
			dfs(curr->child[i],lvl+1,k);
			curr->cnt+=curr->child[i]->cnt;
		}
	}
	while(curr->cnt>=k)
	{
		curr->cnt-=k;
		ans+=lvl;
	}

}
int main()
{
	// 		#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	lli t,i;
	cin>>t;
	lli temp=t;
	while(t--)
	{
		lli n,k;
		cin>>n>>k;
		lli ans=0;
		trie* head=new trie();
		for(i=0;i<n;i++)
		{
			string str;
			cin>>str;
			insert(str,head);
		}
		dfs(head,0,k);
		cout<<"Case #"<<temp-t<<": "<<ans<<endl;

	}
}
