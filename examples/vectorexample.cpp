#include <iostream>
#include <cstdlib>
#include "../include/vector.hpp"

/**
 * Example usage of vector.hpp and it's generic algorithms 
 * Author: Pietro Paniccia
 */

int main(int argc, char* argv[]) {
     mini_stl::Vector<double> vec1; 
     mini_stl::Vector<double> vec2;
     
     int n;
     std::cout << "Enter Size of Vectors: ";
     std::cin >> n;

     std::cout << "Enter elements of first Vector: ";
     for (int i = 0; i < n; i++){
        double x;
        std::cin >> x;
        vec1.push_back(x);
     }

     std::cout << "Enter elements of second Vector: ";
     for (int i = 0; i < n; i++){
        double y;
        std::cin >> y;
        vec2.push_back(y);
     }

     std::cout << "Choose operation 1:Addition, 2:Dot Product";
     int choice;
     std::cin >> choice;

     switch(choice) {
        case 1:{ // addition
            mini_stl::Vector<double> sum;
            sum.reserve(n);
            sum = vec1.add(vec2);
            std::cout << "Sum: <";
            for (int i = 0; i < n; ++i){
                if (i+1 == n)
                    std::cout << sum[i] << "";
                else 
                    std::cout << sum[i] << ", ";
            }
            std::cout << ">\n";
            break;
        }

        case 2:{ // dot product
            double result = 0;
            result = vec1.dot(vec2);
            std::cout << "Dot Product: " << result << "\n";
            break;
        }

        default:
            std::cout << "Invalid Choice";
     }
}