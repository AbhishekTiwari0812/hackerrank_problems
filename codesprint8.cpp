#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<set>
using namespace std;
#define f(rotator,check_pa,b) for(long long rotator=check_pa;rotator<b;rotator++)
#define vec_long_long vector<long long int>
vec_long_long whole_table_graph[5*100020];
vec_long_long Linked_list[5*100020];
long long final_location_node_finder[5*100020];
long long final_list_identities[5*100020];
long long parent_chain[5*100020];
long long jointer=0;
long long check_pa[5*100020];
long long look_up_helper[5*100020][64];
map<long long,vector<long long> > hash_table;
map<long long,long long> my_answer_table,hash_checker_final;
void final_graph_scanner(long long current,long long papa_linker[],long long final_standing_in_the_list[])
{
    for(int rotator=0;rotator<whole_table_graph[current].size();rotator++)
    {
        if(papa_linker[current]!=whole_table_graph[current][rotator])
        {
            papa_linker[whole_table_graph[current][rotator]]=current;
            final_standing_in_the_list[whole_table_graph[current][rotator]]=final_standing_in_the_list[current]+1;
            final_graph_scanner(whole_table_graph[current][rotator],papa_linker,final_standing_in_the_list);
        }
    }
}
void create_linked_list(long long papa_linker[],long long n)
{
    for(int rotator=1;rotator<n;rotator++)
    {
        for(int iter_222=0;(1<<iter_222)<n;iter_222++)look_up_helper[rotator][iter_222]=-1;
    }
    for(int rotator=1;rotator<n;rotator++)look_up_helper[rotator][0]=papa_linker[rotator];
    for(int iter_222=1;(1<<iter_222)<n;iter_222++)
    {
        for(int rotator=1;rotator<n;rotator++)
        {
            if(look_up_helper[rotator][iter_222-1]!=-1)
                look_up_helper[rotator][iter_222]=look_up_helper[look_up_helper[rotator][iter_222-1]][iter_222-1];
        }
    }
}
long long lca(long long linker_papa,long long q,long long final_standing_in_the_list[],long long papa_linker[])
{
   if(final_standing_in_the_list[linker_papa]<final_standing_in_the_list[q])
   {
        int temp=linker_papa;linker_papa=q;q=temp;
   }
   int check_parent_link_true=0;
   for(check_parent_link_true=1;(1<<check_parent_link_true)<=final_standing_in_the_list[linker_papa];check_parent_link_true++);
   check_parent_link_true--;
   for(int rotator=check_parent_link_true;rotator>=0;rotator--)
   {
        if(final_standing_in_the_list[linker_papa]-(1<<rotator)>=final_standing_in_the_list[q])
            linker_papa=look_up_helper[linker_papa][rotator];
   }
   if(linker_papa==q)return q;
   for(int rotator=check_parent_link_true;rotator>=0;rotator--)
   {
        if(look_up_helper[linker_papa][rotator]!=-1 && look_up_helper[linker_papa][rotator]!=look_up_helper[q][rotator])
            {linker_papa=look_up_helper[linker_papa][rotator];q=look_up_helper[linker_papa][rotator];}
   }
   return papa_linker[linker_papa];
}
void graph_traversal_2(long long current,long long linker_papa,long long top)
{
    parent_chain[current]=top;
    Linked_list[jointer].push_back(current);
    final_list_identities[current]=jointer;
    bool final_check_pass=false;
    if(whole_table_graph[current].size()==1)jointer++;
    f(rotator,0,whole_table_graph[current].size()){
        if(whole_table_graph[current][rotator]!=linker_papa && final_check_pass==false){
            final_check_pass=true;
            graph_traversal_2(whole_table_graph[current][rotator],current,top);
        }
        else if(whole_table_graph[current][rotator]!=linker_papa && final_check_pass==true){
            graph_traversal_2(whole_table_graph[current][rotator],current,current);
        }
    }
}
vec_long_long reinitiator[5*100020];
long long graph_scan1(long long current,long long linker_papa,long long final_right_flagger)
{
    long long val=0;
    if(hash_checker_final[current]==1){val=1;final_right_flagger=1;}
    vec_long_long pls;
    f(rotator,0,whole_table_graph[current].size())
    {
        if(whole_table_graph[current][rotator]!=linker_papa)
         {
            long long x=graph_scan1(whole_table_graph[current][rotator],current,final_right_flagger);
            val|=x;
            if(x==1 && final_right_flagger==1)
                {
                    reinitiator[whole_table_graph[current][rotator]].push_back(current);
                    reinitiator[current].push_back(whole_table_graph[current][rotator]);
                }
         }
    }
    return val;
}
int main()
{
    long long n;
    cin>>n;
    long long papa_linker[5*100020];
    long long final_standing_in_the_list[5*100020];
    f(rotator,0,n-1)
    {
        int previous,next_node;
        cin>>previous>>next_node;
        whole_table_graph[previous].push_back(next_node);
        whole_table_graph[next_node].push_back(previous);
    }
    papa_linker[1]=1;final_standing_in_the_list[1]=1;
    final_graph_scanner(1,papa_linker,final_standing_in_the_list);
    create_linked_list(papa_linker,n+1);
    graph_traversal_2(1,1,0);
    long long q;
    cin>>q;
    f(rotator,0,5*100020)
    {
        f(iter_222,0,Linked_list[rotator].size())
            final_location_node_finder[Linked_list[rotator][iter_222]]=iter_222;
    }
   
    long long location_pointer=q;
    while(q)
    {
        q--;
        long long check_flag,commom_papa=0,first=0;
        cin>>check_flag;
        f(rotator,0,check_flag)
        {
            cin>>check_pa[rotator];
            hash_checker_final[check_pa[rotator]]=1;
            first=check_pa[rotator];
            if(rotator==0)commom_papa=check_pa[rotator];
            else commom_papa=lca(commom_papa,check_pa[rotator],final_standing_in_the_list,papa_linker);
        }
        if(location_pointer*n<10000000)
        {
        graph_scan1(first,first,0);
        long long final_output=0;
        f(rotator,0,n+1)
        {
            if(reinitiator[rotator].size()==1 && hash_checker_final[rotator]==1)final_output+=reinitiator[rotator].size();
        }
        if(final_output%2==0)cout<<final_output/2<<endl;
        else cout<<1+(final_output/2)<<endl;
        f(rotator,0,n+1)reinitiator[rotator].clear();
        hash_checker_final.clear();
        }
        else
        {
        if(check_flag==1)
        {
            cout<<0<<endl;
            continue;
        }
        f(rotator,0,check_flag)
            hash_table[final_list_identities[check_pa[rotator]]].push_back(check_pa[rotator]);    
        map<long long, vector<long long> >::iterator iter;
        long long las=0;
       
        for(iter=hash_table.begin();iter!=hash_table.end();iter++)
        {
            f(iter_222,0,hash_table[iter->first].size())
               {
                
                    long long final_index_after_mod=hash_table[iter->first][iter_222];
               
                
                    f(k,0,hash_table[final_list_identities[final_index_after_mod]].size())
                    {
                       
                        
                        if(hash_table[final_list_identities[final_index_after_mod]][k]!=commom_papa && hash_table[final_list_identities[final_index_after_mod]][k]!=final_index_after_mod
                           && final_location_node_finder[final_index_after_mod]>final_location_node_finder[hash_table[final_list_identities[final_index_after_mod]][k]])
                             hash_table[final_list_identities[final_index_after_mod]].erase(hash_table[final_list_identities[final_index_after_mod]].begin()+k);
                    }
                    final_index_after_mod=parent_chain[final_index_after_mod];
                while(final_index_after_mod!=parent_chain[commom_papa])
                {
                    f(k,0,hash_table[final_list_identities[final_index_after_mod]].size())
                    {
                        if(hash_table[final_list_identities[final_index_after_mod]][k]!=commom_papa && final_location_node_finder[final_index_after_mod]>=final_location_node_finder[hash_table[final_list_identities[final_index_after_mod]][k]])
                        {
                            hash_table[final_list_identities[final_index_after_mod]].erase(hash_table[final_list_identities[final_index_after_mod]].begin()+k);
                        }

                    }
                    final_index_after_mod=parent_chain[final_index_after_mod];
                }
            }
       }       
        for(iter=hash_table.begin();iter!=hash_table.end();iter++)
        {
           
            if(final_list_identities[commom_papa]==iter->first)continue;
            f(iter_222,0,hash_table[iter->first].size())
            {
                long long final_index_after_mod=hash_table[iter->first][iter_222];
                while(final_index_after_mod!=parent_chain[commom_papa])
                {
                    if(my_answer_table[final_list_identities[final_index_after_mod]]==1)break;
                    if(final_list_identities[final_index_after_mod]!=final_list_identities[commom_papa])
                        my_answer_table[final_list_identities[final_index_after_mod]]=1;
                    
                    if(final_list_identities[final_index_after_mod]==final_list_identities[commom_papa]){las++;break;}
                    final_index_after_mod=parent_chain[final_index_after_mod];
                }
            }
        }
        
        
        if(las+hash_table[final_list_identities[commom_papa]].size()-1>=2)
        {
            f(rotator,0,hash_table[final_list_identities[commom_papa]].size())
            {
                if(hash_table[final_list_identities[commom_papa]][rotator]==commom_papa)
                    hash_table[final_list_identities[commom_papa]].erase(hash_table[final_list_identities[commom_papa]].begin()+rotator);
            }
        }
        
        long long final_output=0;
        for(iter=hash_table.begin();iter!=hash_table.end();iter++)
        {
            final_output+=hash_table[iter->first].size();
        }
        if(final_output%2==0)
        cout<<final_output/2<<endl;
        else cout<<(final_output/2)+1<<endl;
        hash_table.clear();
        my_answer_table.clear();
      
    }
    }
}