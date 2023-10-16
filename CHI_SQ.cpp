#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int factorial(int n) 
{ 
    return (n == 1 || n == 0) ? 1 : n * factorial( n - 1 );  
} 

double chiSquarePValue(double chiSquareValue, int degreesOfFreedom) {
    if (chiSquareValue < 0 || degreesOfFreedom < 1) {
        return 0.0; 
    }

    double pValue = 1.0 - erf(sqrt(chiSquareValue / 2.0));

    return pValue;
}

int main()
{
    int count1 = 0, CLASS[11] = {0}, K = 1000;
    double CLASSE[11], temp, sum = 0, temp_sum = 0;

    random_device rd;
    mt19937 gen(rd());

    int lambda = 5;
    poisson_distribution<int> distribution(lambda);

    while(count1 < K){
        // if(count1 % 10 == 0){cout << endl;}
        count1++;
        int poisson = distribution(gen);
        // cout << poisson << "\t";

        if(poisson > 9){
            CLASS[10]++;
        }
        else{
            CLASS[poisson]++;
        }
    }

    cout << endl;
    
    for (int i = 0; i < 10; i++)
    {
        CLASSE[i] = K*(exp(-lambda))*(pow(lambda,i)/factorial(i));
        cout << CLASS[i] << "\t";
        cout << CLASSE[i] << endl;
        sum = sum + ((CLASS[i] - CLASSE[i])*(CLASS[i] - CLASSE[i]))/CLASSE[i];
        temp_sum = temp_sum + CLASSE[i];
    }
    
    CLASSE[10] = K - temp_sum;
    sum = sum + ((CLASS[10] - CLASSE[10])*(CLASS[10] - CLASSE[10]))/CLASSE[10];
    cout << CLASS[10] << "\t";
    cout << CLASSE[10] << endl;

    cout << sum;

    double pValue = chiSquarePValue(sum, 9);
    cout << "\nP-Value: " << pValue << endl;
    
    return 0;
}