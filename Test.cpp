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
        string range1 = "", range2 = "", range3 = "";
        for (int i : range(-4, 2))
        {
            range1 += to_string(i);
        }
        for (int i : range(10, 10))
        {
            range2 += to_string(i);
        }
        for (char i : range('a', 'd'))
        {
            range3 += i;
        }
        tc.setname("range tests")

            .CHECK_OUTPUT(range1, "-4-3-2-101") //-4->1
            .CHECK_OUTPUT(range2, "")           //no output since 10=10
            .CHECK_OUTPUT(range3, "abc");
        //////~ range//////

        //////chain///////
        string chain1 = "", chain2 = "", chain3 = "";
        /*
        for (char i: chain(range('a','c'),range('x','z'))){
            chain1+= i+" ";}
        */
        for (int i : chain(range(6, 8), range(2, 3)))
        {
            chain2 += to_string(i) + " ";
        }
        for (int i : chain(range(6, 8), range(1, 2)))
        {
            chain3 += to_string(i) + " ";
        }

        tc.setname("chain tests")
            //.CHECK_OUTPUT(chain1,"a b x y ")
            .CHECK_OUTPUT(chain2, "6 7 2 ")
            .CHECK_OUTPUT(chain3, "6 7 1 ");

        //////~ chain/////

        /////////powerset////////

        string pow1 = "", pow2 = "";
        int i = 0;
        stringstream buff;

        for (auto subset : powerset(range(0, 2)))
        {
            buff << subset;
        }
        buff >> pow1;
        buff.clear();

        for (auto subset : powerset(range(0, 3)))
        {
            i++;
        }

        for (auto subset : powerset(range('a', 'd')))
        {
            buff << subset;
        }
        buff >> pow2;
        buff.clear();

        tc.setname("powerset tests")
            .CHECK_OUTPUT(pow1, "{}{0}{1}{0,1}")
            .CHECK_OUTPUT(i, "8") //amount of subset
            .CHECK_OUTPUT(pow2, "{}{a}{b}{a,b}{c}{a,c}{b,c}{a,b,c}");

        /////////~ powerset////////

        ///////////zip////////////
        string zip1 = "", zip2 = "", zipZip = "";

        for (auto zipFor : zip(range(1, 3), range(1, 3)))
        {
            buff << zipFor;
        }
        buff >> zip1;
        buff.clear();

        for (auto zipFor : zip(range('a', 'c'), range(1, 3)))
        {
            buff << zipFor;
        }
        buff >> zip2;
        buff.clear();

        for (auto zipFor : zip(zip(range(1, 3), string("xy")), zip(string("ab"), range(6, 8))))
        {
            buff << zipFor;
        }
        buff >> zipZip;
        buff.clear();

        tc.setname("zip tests")
            .CHECK_OUTPUT(zip1, "11,22,")
            .CHECK_OUTPUT(zip2, "a1,b2,")
            .CHECK_OUTPUT(zipZip, "1x,a6,,2y,b7,,");

        //////////~zip///////////

        ///////// product////////
        string prod1 = "", prod2 = "", prod3 = "";
        for (auto prodFor : product(range(0, 2), range(3, 5)))
        {
            buff << prodFor;
        }
        buff >> prod1;
        buff.clear();

        for (auto prodFor : product(string("abc"), range(6, 8)))
        {
            buff << prodFor;
        }
        buff >> prod2;
        buff.clear();

        for (auto prodFor : product(range('f', 'h'), range(7, 9)))
        {
            buff << prodFor;
        }
        buff >> prod3;
        buff.clear();

        tc.setname("product tests")
            .CHECK_OUTPUT(prod1, "03,04,13,14,")
            .CHECK_OUTPUT(prod2, "a6,a7,b6,b7,c6,c7,")
            .CHECK_OUTPUT(prod3, "f7,f8,g7,g8,");

        /////////~ product////////

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