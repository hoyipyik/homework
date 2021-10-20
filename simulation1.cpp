#include<iostream>
#include<fstream>
#include<cmath>
#include"mt19937ar.c"
using namespace std;

/**
 * Question 1
 * */

double randFunction1_1(unsigned x, unsigned &xn){
    int a = 2147483647;
    int b = 16807;
    xn = (b*x)%a;
    double c = xn/2147483647.0;
    return c;
}

void question1_1(){
    unsigned s = 1232;
    int count = 100000;
    ofstream outfile;
    outfile.open("q1_1.txt");
    for (int i = 0; i < count; i++)
    {
        outfile << randFunction1_1(s, s) << endl;
    }
    outfile.close(); 
}

void question1_2(){
    ofstream outfile;
    outfile.open("q1_2.txt");
    int count = 100000;
    for (size_t i = 0; i < count; i++)
    {
        outfile << genrand_real2() <<endl;
    }
    outfile.close();
}

void question1_3(){
    ofstream outfile;
    outfile.open("q1_3.txt");
    const unsigned long long m1 = pow(2, 32) - 209.0;
    const unsigned long long  m2 = pow(2, 32) - 22853.0;
    int count = 100000;
    unsigned long long x[count] = {0};
    unsigned long long y[count] = {0};
    x[0] = 4;x[1]= 2;x[2]=7;
    y[0] = 8;y[1]= 5;y[2]=6;

    for (size_t i = 3; i < count; i++)
    {
        x[i] = (1403580*x[i-2] - 810728*x[i-3])%m1;
        y[i] = (527612*y[i-1] - 1370589*y[i-3])%m2;
        // cout<<x[i]<<y[i]<<endl;
    }

    for (size_t i = 0; i < count; i++)
    {   
        double data = 0;
        if (x[i]<=y[i])
        {
            data = (double)(x[i] -y[i]+m1)/(double)(m1+1);
        }else{
            data = (double)(x[i]-y[i])/(double)(m1+1);
        }
        outfile << data <<endl;
    }
    outfile.close();
}

/**
 * Question 2
*/

double ParotoFunction(double a, double b, double x){
    double y;
    y = b/(pow((1-x),1/a));
    return y;
}

void question2(){
    long long count = 100000;
    double a = 10.34;
    double b = 1893;
    ofstream outfile;
    outfile.open("q2.txt");
    for (size_t i = 0; i < count; i++)
    {
        outfile << ParotoFunction(a, b, genrand_real2()) << endl;
    }
    outfile.close();
}

/**
 * Question 3
*/

void question3_1(){
    ofstream outfile;
    outfile.open("q3_1.txt");
    int count = 100000;
    const int n = 12;
    double y[n] = {0};
    double B = sqrt(12.0/n);
    // cout <<B<<endl;
    for (size_t i = 0; i < count; i++)
    {
        double x = 0; 
        for (size_t j = 0; j < n; j++)
        {
            y[j] = (genrand_real2()-0.5);
            x += y[j];
            x *= B;
        }

        outfile << x << endl;
    }
    outfile.close();
}

void question3_2(){
    ofstream file;
    file.open("q3_2.txt");
    int count = 10000;
    for (size_t i = 0; i < count; i++)
    {
        double data = 0;
        double rd1 = genrand_real2();
        double rd2 = genrand_real2();
        data = sqrt(-2*log(rd1))*cos(2*3.14159265*rd2);
        file << data <<endl;
    }
    file.close();
}

/**
 * Question 4
 */

void question4(){
    int count = 1000000;
    ofstream file;
    file.open("q4.txt");
    for (size_t i = 0; i < count; i++)
    {
        double result = 0;
        double x = 0;
        double rd1 = genrand_real2();
        double rd2 = genrand_real2();
        double judgeFlag = genrand_real2();
        x = sqrt(-2*log(rd1))*cos(2*3.14159265*rd2);
        double p[3] = {1/2.0, 1/3.0, 1/6.0};
        double a[3] = {-1.0, 0.0, 1.0};
        double b[3]= {1/4.0, 1.0, 1/2.0};
        if (judgeFlag<p[0])
        {
            result = x*b[0]+a[0];
        }else if (judgeFlag>p[0] && judgeFlag<(p[0]+p[1]))
        {
            result = x*b[1]+a[1];
        }else{
            result = x*b[2]+a[2];
        }
        file << result <<endl;
    }
    file.close();
}

/**
 * Question 5
 */

void question5(){
    ofstream outfile;
    outfile.open("q5.txt");
    double lambda = 2.0;
    int count = 10000;
   
    double x = 0;
    for (size_t i = 0; i < count; i++)
    {
         int k = 0;
        double holder = 0;
        for (size_t j = 0; j < count; j++)
        {
            x = -log(genrand_real2())/2.0;
            holder += x;
            // cout << x <<endl;
            if(holder>1) {
                // cout << j <<endl;
                k = j + 1;
                break;
            }
        }
        outfile << k <<endl;
    }
    outfile.close();
    
}

int main(){
    question1_1();
    question1_2();
    question1_3();
    question2();
    question3_1();
    question3_2();
    question4();
    question5();
    return 0;
}