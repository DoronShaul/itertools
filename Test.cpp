#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
using namespace itertools;
#define COMMA ,

using namespace itertools;

int main()
{

    badkan::TestCase tc("Contains");
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0)
    {
        //////range ///////
        int a = 1, b = -5, c = 10;
        string range1 ="", range2 ="", range3 ="";
        for (int i: range(-4,2)){
            range1+= to_string(i);}
        for (int i: range(10,10)){
            range2+= to_string(i);}
        for (char i: range('a','d')){
            range3+= i;}
        tc.setname("range tests")
        
        .CHECK_OUTPUT(range1,"-4-3-2-101")//-4->1
        .CHECK_OUTPUT(range2,"") //no output since 10=10
        .CHECK_OUTPUT(range3,"abc");
       //////~ range//////
       
        //////chain///////
        string chain1="",chain2="",chain3="";
        for (char i: chain(range('a','c'),range('x','z'))){
            chain1+= i+" ";}
        for (int i: chain(range(6,8),range(2,3))){
            chain2+= to_string(i)+" ";}
        for (int i: chain(range(6,8),range(1,2))){
            chain3+= to_string(i)+" ";}   

        tc.setname("chain tests")
        .CHECK_OUTPUT(chain1,"a b x y ")
        .CHECK_OUTPUT(chain2,"6 7 2 ")
        .CHECK_OUTPUT(chain3,"6 7 1 ");

        //////~ chain/////
       

       
        grade = tc.grade();
    }
    else
    {
        tc.print_signal(signal);
        grade = 0;
    }

    cout << "Your grade is: " << grade << endl;
    return 0;
}