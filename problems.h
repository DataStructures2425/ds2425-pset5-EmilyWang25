#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
using namespace std;


// PROBLEM 1 - LRU CACHE
struct Node{
    Node* next;
    Node* prev;
    int val;
    int capacity = 1;
    int key = 0;
    Node(int a){
        val = a;
    }
};

int capacities=0;

class LRUCache {
public:
    Node* head = new Node(-1);
    Node* tail = new Node(-1);
    int cap=0;
    
    unordered_map<int,Node*> element;

    LRUCache(int capacity) {
        capacities = 0;
        head = nullptr;
        tail = head;
        cap = capacity;
    }
    
    int get(int key) {
        if(element[key]!=nullptr){
            if(element[key]==nullptr) return -1;
            if(head==tail||element[key]->next==head){
                return element[key]->val;
            }
            
            //cout<<"contrast:"<<tail->val<<endl;
            Node* a = element[key]->prev;
            Node* b = element[key]->next;
            if(a) a->next = b;
            else  if (b) head = b;
            if(b) b->prev = a;
            tail->next = element[key];
            element[key]->prev = tail;
            element[key]->next = head;
            tail = tail->next;
            //cout<<"test:"<<tail->val<<endl;
            //cout<<"test:"<<head->val<<endl;
            return element[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(element.empty()){
            head = new Node(value);
            tail = head;
            element[key] = head;
            element[key]->key = key;
            head->next = tail;
            tail->prev = head;
            tail->next=head;
            head->prev = nullptr;
            capacities++;
        }else if(element.find(key)!=element.end()&&element[key]!=nullptr){
            element[key]->val=value;
        }else{
            element[key] =new Node(value);
            element[key]->key = key;
            if(capacities >= cap){

                //cout<<"right"<<endl;
                tail->next=element[key];

                element[key]->prev=tail;

                tail = tail->next;
                
                Node* help1 = head;

                head = head->next;
                element[help1->key]=nullptr;
                element[key]->next=head;
                //cout<<"2"<<endl;
                delete(help1);
                
            }else{
                element[key]->prev = tail;
                tail->next = element[key];
                element[key]->next = head;
                tail = tail->next;
                capacities++;
            }
        }
    }

    void printout(){
        Node* help = head;
        while(help!=nullptr){
            cout<<" "<<head->val<<"v"<<endl;
            help = help->next;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// PROBLEM 2 - REARRANGING FRUITS

long long minCost(vector<int>& basket1, vector<int>& basket2) 
{
        //first make sure if the solution is valid
        map<int,int> count;
        map<int,pair<int,int>> spcount;
        vector<int> ans;
        long long anss=0;

        for(auto x:basket1){
            count[x]++;
            spcount[x].first++;
        }
        for(auto x:basket2){
            count[x]++;
            spcount[x].second++;
        }

        for(auto it = count.begin();it!=count.end();it++){
            if(it->second%2!=0){
                return -1;
            }
        }


       /*for(int i=0;i<basket1.size();i++){
            for(int j=i+1;j<basket1.size();j++){
                if(basket1[i]>basket1[j]){
                    int help =basket1[i];
                    basket1[i]=basket1[j];
                    basket1[j]=help;
                }
            }
       }

    for(int i=0;i<basket2.size();i++){
            for(int j=i+1;j<basket2.size();j++){
                if(basket2[i]>basket2[j]){
                    int help =basket2[i];
                    basket2[i]=basket2[j];
                    basket2[j]=help;
                }
            }
    }*/

    for(auto it=spcount.begin();it!=spcount.end();it++){
        if(it->second.first!=it->second.second){
            for(int i=1;i<=abs(it->second.first-it->second.second)/2;i++){
                ans.push_back(it->first);
            }
        }
    }

    for(long long i=0;i<ans.size()/2;i++){
        anss+=ans[0];
    }

    return anss;

}


// PROBLEM 3 - SUDOKU SOLVER

// Hint - it would probably be helpful to write a function that
// print out the board for you!
int targeti,targetj;
bool b1[9][9];

bool help(vector<vector<char>>& board,int i,int j){
    if(b1[targeti][targetj]==false){
        return true;
    }

    if(b1[i][j]==true){
        for(int a=1;a<=9;a++){
            //if(i==2&&j==7) cout<<"hereeeeeee"<<endl;
            b1[i][j]=false;
            bool flag=0;
            char helps = a + '0';
            if(find(board[i].begin(),board[i].end(),helps)!=board[i].end()){
                continue;
            }
            for(int b=0;b<9;b++){
                //cout<<"yeppe"<<endl;
                if(board[b][j]==helps){
                    flag = 1;
                    break;
                }
            }

            for(int k=i/3*3;k<i/3*3+3;k++){
                //cout<<"Hey!"<<endl;
                for(int l=j/3*3;l<j/3*3+3;l++){
                    if(board[k][l]==helps){
                        flag=1;
                        break;
                    }
                }
            }

            if(flag){
                //cout<<"yep"<<endl;
                continue;
            }
           // cout<<"here"<<" "<<i<<" "<<j<<" "<<helps<<endl;
            board[i][j]=helps;
           // cout<<"Pppppppp"<<endl;
            if(j==8){
                if(help(board,i+1,0)) return true;
            }else{
                if(help(board,i,j+1)) return true;
            }
        }

        //cout<<i<<" "<<j<<endl;
        b1[i][j]=true;
        board[i][j]='.';
        return false;
    }else{
        if(j==8){
                if(help(board,i+1,0)) return true;
        }else{
                if(help(board,i,j+1)) return true;
        }
    }

    return false;

   
}

void solveSudoku(vector<vector<char>>& board) 
{
        
        for(int i=0;i<9;i++){
            for(int j=0; j<9;j++){
                //cout << board[i][j] << endl;
                if(board[i][j]=='.'){
                   // cout <<"a"<<endl;
                    b1[i][j] = true;
                    targeti = i;
                    targetj = j;
                }else{
                    //cout<<"b"<<endl;
                    b1[i][j] = false;
                }
            }
        }

       // cout<<"jelp"<<endl;

        if(help(board,0,0)){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
        }

}

