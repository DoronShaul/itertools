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

    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0)
    {
        testcase.setname("containers tests")
        


        ;
        grade = testcase.grade();
    }
    else
    {
        testcase.print_signal(signal);
        grade = 0;
    }
    
    cout << "Your grade is: " << grade << endl;
    return 0;
}