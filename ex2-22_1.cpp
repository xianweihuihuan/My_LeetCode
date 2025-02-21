#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int main(){
    int q = 0;
    cin>>q;  
    while(q--){
        int n = 0;
        cin>>n;
        vector<int> pushed(n);
        vector<int> poped(n);
        for(int i = 0;i<n;i++){
            int tmp = 0;
            cin >> tmp;
            pushed[i]=tmp;
        }
        for(int i = 0;i<n;i++){
            int tmp = 0;
            cin >> tmp;
            poped[i] = tmp;
        }
        stack<int> st;
        int sum = 0;
        for(int i = 0;i<n;i++){
            st.push(pushed[i]);
            while((!st.empty())&&(st.top()==poped[sum])){
                st.pop();
                sum++;
            }
        }
        if(st.empty()){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        // while(!st.empty()){
        //     st.pop();
        // }
    }
}