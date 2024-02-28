// ASSIGNMENT_NAME: EECS 348 Lab 6
// FUNCTION: Take in two matricies and perform matrix math with them
// INPUTS: matrix_input.txt
// OUTPUTS: Various matricies with the various operations
// AUTHOR_NAME: Michael Stang
// COLLABORATORS: NONE
// CREATION_DATE: 10/19/2023


#include <iostream>
#include <string>
#include <fstream>


int main() {
    
    std::ifstream in_file;
    in_file.open("matrix_input.txt", std::ios::in);

    std::string string_matrix_size;
    int matrix_size;
    std::getline(in_file, string_matrix_size);
    matrix_size = std::stoi(string_matrix_size);
    int largest_int = 4;
    
    std::cout<<"Matrix Size: "<<matrix_size<<"\n";
    
    int matrix_one[matrix_size][matrix_size];  // Will hold the first matrix
    int matrix_two[matrix_size][matrix_size];  // Will hold the second matrix

    // Convert .txt -> matrix
    for (int i = 0; i < matrix_size; i++) {  // Goes through each row
        for (int j = 0; j < matrix_size; j++) {  // Goes through each column
            in_file >> matrix_one[i][j];  // Uses IOStream to go from file to matrix
        }
    }

    // Same as above, but with matrix_two
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            in_file >> matrix_two[i][j];
        }
    }

    in_file.close();

    // Funtion to print a given matrix
    std::cout<<"Matrix A:\n";
    for (int i = 0; i < matrix_size; i++) {  // Each row
        for (int j = 0; j < matrix_size; j++) {  // Each column
            std::string value = std::to_string(matrix_one[i][j]);  // Store value in 'value' as string
            while (value.size() < largest_int) {  // Adjust length for formatting
                value = " " + value;
            }
            std::cout<<value<<" ";

        }
        std::cout<<"\n";
    }

    // Funtion to print a given matrix (same as above)
    std::cout<<"\nMatrix B:\n";
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            std::string value = std::to_string(matrix_two[i][j]);
            while (value.size() < largest_int) {
                value = " " + value;
            }
            std::cout<<value<<" ";

        }
        std::cout<<"\n";
    }


    // Matrix A + Matrix B
    int sum_matrix[matrix_size][matrix_size];
    for (int i=0; i < matrix_size; i++) {
        for (int j=0; j < matrix_size; j++) {
            sum_matrix[i][j] = matrix_one[i][j] + matrix_two[i][j];  // Just adds the values at the matching point to form a new matrix
        }
    }
        //Print Matrix A+B (same as above)
    std::cout<<"\nMatrix Sum (A+B):\n";
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            std::string value = std::to_string(sum_matrix[i][j]);
            while (value.size() < largest_int) {
                value = " " + value;
            }
            std::cout<<value<<" ";
        }
        std::cout<<"\n";
    }

    // Matrix A * Matrix B

    int product_matrix[matrix_size][matrix_size];
        for (int i=0; i < matrix_size; i++) {  // Each row
            for (int j=0; j < matrix_size; j++) {  // Each column
                int temp_sum = 0;  // Var that will hold the sum of the products
                for (int k=0; k < matrix_size; k++) {  // This is for summation
                    temp_sum += (matrix_one[i][k]*matrix_two[k][j]);  // Does matrix multiplication (each run of this code generates one product that will be summed)
                }
                product_matrix[i][j] = temp_sum;            
        }
    }

            //Print Matrix A*B (same as above)
    std::cout<<"\nMatrix Product (A*B):\n";
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            std::string value = std::to_string(product_matrix[i][j]);
            while (value.size() < largest_int) {
                value = " " + value;
            }
            std::cout<<value<<" ";
        }
        std::cout<<"\n";
    }

    // Matrix A - Matrix B
    int sub_matrix[matrix_size][matrix_size];
    for (int i=0; i < matrix_size; i++) {
        for (int j=0; j < matrix_size; j++) {
            sub_matrix[i][j] = matrix_one[i][j] - matrix_two[i][j];  // Just subtracts the values at the matching point to form a new matrix
        }
    }
        //Print Matrix A-B (same as above)
    std::cout<<"\nMatrix Difference (A-B):\n";
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            std::string value = std::to_string(sub_matrix[i][j]);
            while (value.size() < largest_int) {
                value = " " + value;
            }
            std::cout<<value<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}
