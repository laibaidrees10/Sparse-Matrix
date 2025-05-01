#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class SparseMatrixADT
{
private:
    vector<pair<pair<int, int>, T>> elements;
    int rows, cols;

public:
    SparseMatrixADT(int r, int c) : rows(r), cols(c) {}

    void SetValue(int row, int col, T value)
    {
        for (int i = 0; i < elements.size(); ++i)
        {
            if (elements[i].first.first == row && elements[i].first.second == col)
            {
                if (value == T{})
                {
                    elements.erase(elements.begin() + i);
                }
                else
                {
                    elements[i].second = value;
                }
                return;
            }
        }

        if (value != T{})
        {
            elements.push_back({{row, col}, value});
        }
    }

    T GetValue(int row, int col) const
    {
        for (auto element : elements)
        {
            if (element.first.first == row && element.first.second == col)
            {
                return element.second;
            }
        }
        return 0;
    }

    T RecursiveDiagonalSum(int index)
    {
        if (index >= rows || index >= cols)
        {
            return 0;
        }
        T diagonalValue = GetValue(index, index);
        return diagonalValue + RecursiveDiagonalSum(index + 1);
    }

    SparseMatrixADT<T> Transpose()
    {
        SparseMatrixADT<T> transposed(cols, rows);

        for (const auto &element : elements)
        {
            int row = element.first.first;
            int col = element.first.second;
            T value = element.second;
            transposed.SetValue(col, row, value);
        }

        return transposed;
    }

    SparseMatrixADT<T> Multiply(const SparseMatrixADT<T> &other) 
    {
        if (cols != other.rows)
        {
            throw invalid_argument("Matrix dimensions do not allow multiplication");
        }

        SparseMatrixADT<T> result(rows, other.cols);

        for (const auto &element1 : elements)
        {
            int row1 = element1.first.first;
            int col1 = element1.first.second;
            T value1 = element1.second;

            for (const auto &element2 : other.elements)
            {
                int row2 = element2.first.first;
                int col2 = element2.first.second;
                T value2 = element2.second;

                if (col1 == row2)
                {
                    T currentValue = result.GetValue(row1, col2);
                    result.SetValue(row1, col2, currentValue + (value1 * value2));
                }
            }
        }

        return result;
    }
};
