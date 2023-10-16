#include <iostream>
#include <random>

int main() {
    // Seed the random number generator with a random device
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define a Poisson distribution with a specified mean (lambda)
    double lambda = 5.0; // Adjust the mean as needed
    std::poisson_distribution<int> distribution(lambda);

    // Generate and print Poisson random numbers
    for (int i = 0; i < 100; i++) {
        int poissonRandomNumber = distribution(gen);
        std::cout << "Poisson Random Number " << i + 1 << ": " << poissonRandomNumber << std::endl;
    }

    return 0;
}