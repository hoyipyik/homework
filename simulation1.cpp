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
    int count = 1000;
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
    int count = 1000;
    for (size_t i = 0; i < count; i++)
    {
        outfile << genrand_real2() <<endl;
    }
    outfile.close();
}

void question1_3(){
    unsigned long long m1 = pow(2, 32) - 209.0;
    unsigned long long  m2 = pow(2, 32) - 22853.0;
    int x[1000] = {0};
    int y[1000] = {0};
    x[0] = 4;x[1]= 2;x[2]=7;
    y[0] = 8;y[1]= 5;y[2]=6;
    double data[1000] = {0};

    for (size_t i = 3; i < 1000; i++)
    {
        x[i] = (1403580*x[i-2] - 810728*x[i-3])%m1;
        y[i] = (527612*y[i-1] - 1370589*y[i-3])%m2;
        // cout<<x[i]<<y[i]<<endl;
    }

    for (size_t i = 0; i < 1000; i++)
    {
        if (x[i]<=y[i])
        {
            data[i] = (double)(x[i] -y[i]+m1)/(double)(m1+1);
        }else{
            data[i] = (double)(x[i]-y[i])/(double)(m1+1);
        }
    }

    ofstream outfile;
    outfile.open("q1_3.txt");
    for (size_t i = 0; i < 1000; i++)
    {
        outfile << data[i] <<endl;
    }
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
    double a = 3;
    double b = 1;
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
    int count = 10000;
    double data[count] = {0};
    for (size_t i = 0; i < count; i++)
    {
        double rd1 = genrand_real2();
        double rd2 = genrand_real2();
        data[i] = sqrt(-2*log(rd1))*cos(2*3.14159265*rd2);
    }
    ofstream file;
    file.open("q3_2.txt");
    for (size_t i = 0; i < count; i++)
    {
        file << data[i] <<endl;
    }
}

/**
 * Question 4
 */

void question4(){
    int count = 10000;
    double x[count] = {0};
    double result[count] = {0};
    for (size_t i = 0; i < count; i++)
    {
        double holder = 0;
        double rd1 = genrand_real2();
        double rd2 = genrand_real2();
        x[i] = sqrt(-2*log(rd1))*cos(2*3.14159265*rd2);
        double p[3] = {1/2.0, 1/3.0, 1/6.0};
        double a[3] = {-1.0, 0.0, 1.0};
        double b[3]= {1/4.0, 1.0, 1/2.0};
        for (size_t j = 0; j < 3; j++)
        {
            holder += p[j]*(x[i]*b[j]+a[j]);
            // cout << (x[i]-a[j])/b[j] <<endl;
            result[i] = holder;
        }
    }
    ofstream file;
    file.open("q4.txt");
    for (size_t i = 0; i < count; i++)
    {
        file << result[i] <<endl;
    } 

    file.close();
}

/**
 * Question 5
 */

void question5(){
    double lambda = 2.0;
    int count = 10000;
    int k[count] = {0};
    double x = 0;
    for (size_t i = 0; i < count; i++)
    {
        double holder = 0;
        for (size_t j = 0; j < count; j++)
        {
            x = -log(genrand_real2())/2.0;
            holder += x;
            // cout << x <<endl;
            if(holder>1) {
                // cout << j <<endl;
                k[i] = j + 1;
                break;
            }
        }
        
    }

    ofstream outfile;
    outfile.open("q5.txt");
    for (size_t i = 0; i < count; i++)
    {
        outfile << k[i] <<endl;
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