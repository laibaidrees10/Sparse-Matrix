# 🧮 Sparse Matrix ADT (C++)

A generic **Sparse Matrix Abstract Data Type** implemented in C++ using templates and `std::vector`. This project supports operations like setting and retrieving values, diagonal sum (recursively), transposition, and multiplication of sparse matrices, optimized for space by storing only non-zero elements.

---

## 📁 File Structure

* main.cpp ── Contains usage examples and driver code
* sparseMatrix.h ── SparseMatrixADT template class definition

# 🧠 Core Concepts

* Sparse Matrix: Stores only non-zero values as ((row, col), value) pairs.

* Template-based: Supports any data type (e.g., int, float, double).

* Efficient Space Usage: Ideal for matrices with a large number of zero entries.

# 🚀 Features

* SetValue(row, col, value)
  
    Adds/updates a value at the specified position. Automatically removes zero entries.

* GetValue(row, col)
  
    Retrieves a value at the given position. Returns 0 if not explicitly set.

* RecursiveDiagonalSum(index)
 
    Calculates the sum of the main diagonal elements recursively.

* Transpose()
  
    Returns the transpose of the sparse matrix.

* Multiply(const SparseMatrixADT<T>& other)
  
    Performs sparse matrix multiplication with another compatible sparse matrix.

# 🛠️ How to Compile and Run

* Prerequisites
    * C++ compiler (like g++)

* Compile

      g++ main.cpp -o sparseMatrixApp
* Run

      ./sparseMatrixApp
