#include "problems.h"
using namespace std;

int main()
{
    // TEST YOUR CODE HERE... no really - test it!

    cout<<"test for LRUCache"<<endl;

    LRUCache help = LRUCache(2);
    help.put(1,1);
    help.put(2,2);
    //help.printout();
    cout<<help.get(1)<<endl;
    help.put(3,3);
    //help.printout();
    cout<<help.get(2)<<endl;
    help.put(4,4);
    //help.printout();
    //cout<<"fine"<<endl;
    cout<<help.get(1)<<endl;
    cout<<help.get(3)<<endl;
    cout<<help.get(4)<<endl;

    cout<<endl;

    cout<<"test 2:"<<endl;
    //{1,3,5,7,9,10} capacity 3 put 1 get 1 put 3 put 5 get 1 put 7 gte 5 put 9 get 1 put 10 get 5
    LRUCache a = LRUCache(3);
    a.put(1,1);
    cout<<a.get(1)<<endl;
    a.put(3,3);
    a.put(5,5);
    cout<<a.get(1)<<endl;
    a.put(7,7);
    cout<<a.get(3)<<endl;
    a.put(9,9);
    cout<<a.get(7)<<endl;
    cout<<a.get(5)<<endl;
    a.put(10,10);
    cout<<a.get(1)<<endl;
    cout<<a.get(7)<<endl;
    cout<<a.get(9)<<endl;
    cout<<a.get(10)<<endl;


    cout<<"test 3:"<<endl;
    LRUCache b = LRUCache(4);
    b.put(1,1);
    b.put(2,2);
    b.put(3,3);
    b.put(4,4);
    b.put(5,5);
    cout<<b.get(1)<<endl;
    cout<<b.get(3)<<endl;
    b.put(10,10);
    b.put(5,8);
    cout<<b.get(4)<<endl;
    cout<<b.get(3)<<endl;
    cout<<b.get(5)<<endl;
    cout<<b.get(10)<<endl;


    cout<<"test 4:"<<endl;
    LRUCache c = LRUCache(5);
    c.put(1,1);
    c.put(2,2);
    c.put(3,3);
    c.put(4,4);
    c.put(5,5);
    c.put(1,9);
    c.put(2,10);
    c.put(10,20);
    cout<<c.get(1)<<endl;
    

    cout<<"test 5:"<<endl;
    LRUCache t1 = LRUCache(2);
    t1.put(1,10);
    cout<<t1.get(1)<<endl;

    cout<<"test 6:"<<endl;
    LRUCache t2 = LRUCache(2);
    t2.put(1,10);
    t2.put(2,20);
    t2.put(3,30);
    cout<<t2.get(1)<<endl;
    cout<<t2.get(2)<<endl;
    cout<<t2.get(3)<<endl;

    cout<<"test 7:"<<endl;
    LRUCache t3 = LRUCache(2);
    t3.put(1,10);
    t3.put(2,10);
    cout<<t3.get(1)<<endl;
    t3.put(3,30);
    cout<<t3.get(2)<<endl;
    t3.put(4,40);
    cout<<t3.get(3)<<endl;
    cout<<t3.get(1)<<endl;

    cout<<"test 8:"<<endl;
    LRUCache t4 = LRUCache(2);
    t4.put(1,10);
    t4.put(2,20);
    cout<<t4.get(2)<<endl;
    cout<<t4.get(1)<<endl;
    cout<<t4.get(3)<<endl;

    cout<<"test 9:"<<endl;
    LRUCache t5 = LRUCache(2);
    t5.put(1,10);
    t5.put(2,20);
    cout<<t5.get(1)<<endl;
    t5.put(3,30);
    cout<<t5.get(2)<<endl;
    cout<<t5.get(1)<<endl;
    cout<<t5.get(3)<<endl;

    cout<<"test 10:"<<endl;
    LRUCache t6 = LRUCache(3);
    t6.put(1,10);
    t6.put(2,20);
    t6.put(3,30);
    cout<<t6.get(1)<<endl;
    t6.put(4,40);
    cout<<t6.get(2)<<endl;
    cout<<t6.get(1)<<endl;

    cout<<"test 11:"<<endl;
    LRUCache t7 = LRUCache(2);
    t7.put(1,10);
    t7.put(2,20);
    cout<<t7.get(3)<<endl;
    cout<<t7.get(1)<<endl;
    cout<<t7.get(2)<<endl;

    cout<<"test 12:"<<endl;
    LRUCache t8 = LRUCache(2);
    t8.put(1,10);
    t8.put(2,20);
    cout<<t8.get(1)<<endl;
    cout<<t8.get(2)<<endl;
    t8.put(3,30);
    cout<<t8.get(2)<<endl;
    cout<<t8.get(1)<<endl;


    cout<<"test 13:"<<endl;
    LRUCache t9 = LRUCache(3);
    t9.put(1,10);
    cout<<t9.get(1)<<endl;
    t9.put(2,20);
    cout<<t9.get(2)<<endl;
    t9.put(3,30);
    cout<<t9.get(3)<<endl;
    t9.put(4,40);
    cout<<t9.get(4)<<endl;

    cout<<"test 14:"<<endl;
    LRUCache t10 = LRUCache(4);
    t10.put(1,10);
    t10.put(2,20);
    t10.put(3,30);
    t10.put(4,40);
    cout<<t10.get(1)<<endl;
    cout<<t10.get(3)<<endl;
    t10.put(5,50);
    t10.put(6,60);
    cout<<t10.get(2)<<endl;
    cout<<t10.get(4)<<endl;
    cout<<t10.get(1)<<endl;
    cout<<t10.get(3)<<endl;
    cout<<t10.get(5)<<endl;
    cout<<t10.get(6)<<endl;

    cout<<"test 15:"<<endl;
    LRUCache t11 = LRUCache(2);
    t11.put(1,10);
    t11.put(3,30);
    t11.put(4,10);
    cout<<t11.get(1)<<endl;
    cout<<t11.get(4)<<endl;

    cout<<endl;
    cout<<"mincost"<<endl;
    vector<int> basket1 = {4,2,2,2};
    vector<int> basket2 = {1,4,1,2};
    cout<<minCost(basket1,basket2)<<endl;

    cout<<"mincost2"<<endl;
    vector<int> basket3 = {4,2,3};
    vector<int> basket4 = {3,2,4};
    cout<<minCost(basket3,basket4)<<endl;

    cout<<"mincost3"<<endl;
    vector<int> basket5 = {5,1,3};
    vector<int> basket6 = {3,1,6};
    cout<<minCost(basket5,basket6)<<endl;

    cout<<"mincost4"<<endl;
    vector<int> basket7 = {7,2,8,5};
    vector<int> basket8 = {2,5,7,9};
    cout<<minCost(basket7,basket8)<<endl;

    cout<<"mincost5"<<endl;
    vector<int> basket9 = {1,2,3};
    vector<int> basket10 = {4,5,6};
    cout<<minCost(basket9,basket10)<<endl;

    cout<<"mincost6"<<endl;
    vector<int> basket11 = {4,1,7};
    vector<int> basket12 = {7,1,3};
    cout<<minCost(basket11,basket12)<<endl;

    cout<<"mincost7"<<endl;
    vector<int> basket13 = {10,20,30,40,50};
    vector<int> basket14 = {50,40,30,20,10};
    cout<<minCost(basket13,basket14)<<endl;

    cout<<"mincost8"<<endl;
    vector<int> basket15 = {5,8,6};
    vector<int> basket16 = {8,5,7};
     cout<<minCost(basket15,basket16)<<endl;

    cout<<"mincost9"<<endl;
    vector<int> basket17 = {100,200,300};
    vector<int> basket18 = {10,20,30};
     cout<<minCost(basket17,basket18)<<endl;

    cout<<"mincost10"<<endl;
    vector<int> basket19 = {10,20,15,25,30,35};
    vector<int> basket20 = {25,35,10,20,15,30};
    cout<<minCost(basket19,basket20)<<endl;

    cout<<"mincost11"<<endl;
    vector<int> basket21 = {5,8,12,15};
    vector<int> basket22= {8,5,15,12};
    cout<<minCost(basket21,basket22)<<endl;

    cout<<"mincost12"<<endl;
    vector<int> basket23 = {3,3,6,6,9,9};
    vector<int> basket24= {6,6,3,3,9,9};
    cout<<minCost(basket23,basket24)<<endl;

    cout<<"mincost13"<<endl;
     vector<int> basket25 = {1000,2000,3000,4000};
    vector<int> basket26= {500,1500,2500,3500};
    cout<<minCost(basket25,basket26)<<endl;

    cout<<"mincost14"<<endl;
    vector<int> basket27 = {1000,2000,3000,4000};
    vector<int> basket28= {500,1500,2500,3500};
     cout<<minCost(basket25,basket26)<<endl;

     cout<<"mincost15"<<endl;
      vector<int> basket29 = {1,2,3,100};
    vector<int> basket30= {1,2,3,99};
    cout<<minCost(basket29,basket30)<<endl;


    cout<<endl;
    cout<<"sudoku"<<endl;
    vector<vector<char>> sk1 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(sk1);
    cout<<endl;

    vector<vector<char>> sk2 = {{'.','.','.','2','6','.','7','.','1'},{'6','8','.','.','7','.','.','9','.'},{'1','9','.','.','.','4','5','.','.'},{'8','2','.','1','.','.','.','4','.'},{'.','.','4','6','.','2','9','.','.'},{'.','5','.','.','.','3','.','2','8'},{'.','.','9','3','.','.','.','7','4'},{'.','4','.','.','5','.','.','3','6'},{'7','.','3','.','1','8','.','.','.'}};
    solveSudoku(sk2);
    cout<<endl;

    vector<vector<char>> sk3={{'.','2','.','.','.','.','.','.','.'},{'.','.','.','6','.','.','.','.','3'},{'.','7','4','.','8','.','.','.','.'},{'.','.','.','.','.','3','.','.','2'},{'.','8','.','.','4','.','.','1','.'},{'6','.','.','5','.','.','.','.','.'},{'.','.','.','.','1','.','7','8','.'},{'5','.','.','.','.','9','.','.','.'},{'.','.','.','.','.','.','.','4','.'}};
    solveSudoku(sk3);
    cout<<endl;

    vector<vector<char>> sk4={{'.','2','.','6','.','8','.','.','.'},{'5','8','.','.','.','9','7','.','.'},{'.','.','.','.','4','.','.','.','.'},{'3','7','.','.','.','.','5','.','.'},{'6','.','.','.','.','.','.','.','4'},{'.','.','8','.','.','.','.','1','3'},{'.','.','.','.','2','.','.','.','.'},{'.','.','9','8','.','.','.','3','6'},{'.','.','.','3','.','6','.','9','.'}};
    solveSudoku(sk4);
    cout<<endl;

    vector<vector<char>> sk5={{'2','.','.','3','.','.','.','.','.'},{'8','.','4','.','6','2','.','.','3'},{'.','1','3','8','.','.','2','.','.'},{'.','.','.','.','2','.','3','9','.'},{'5','.','7','.','.','.','6','2','1'},{'.','3','2','.','.','6','.','.','.'},{'.','2','.','.','.','9','1','4','.'},{'6','.','1','2','5','.','8','.','9'},{'.','.','.','.','.','1','.','.','2'}};
    solveSudoku(sk5);
    cout<<endl;

   // vector<vector<char>> sk2 = {}
}
