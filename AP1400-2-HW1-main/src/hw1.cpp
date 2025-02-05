#include "hw1.h"

static void check_empty(std::initializer_list<Matrix> ilm)
{
    for (auto it = ilm.begin() ; it != ilm.end() ; ++it)
    {
        if (it -> empty())
        {
            throw std::logic_error("matrix must be non-empty");
        }
    }
}

static void check_square(const Matrix& A)
{
    if (A.size() != A[0].size())
    {
        throw std::logic_error("matrix must be square");
    }
}

static void check_size(size_t n, size_t m)
{
    if (n == 0 || m == 0)
    {
        throw std::invalid_argument("size must be non-zero");
    }
}

namespace algebra {

Matrix zeros(size_t n, size_t m)
{
    check_size(n, m);
    return Matrix(n, std::vector<double>(m, 0.0));
}

Matrix ones(size_t n, size_t m)
{
    check_size(n, m);
    return Matrix(n, std::vector<double>(m, 1.0));
}

Matrix random(size_t n, size_t m, double min, double max)
{
    check_size(n, m);
    if (min >= max)
    {throw std::logic_error("interval leftside must be minor to rightside");}
    std::default_random_engine e;
    std::uniform_real_distribution<double> u(min, max);
    Matrix mat = zeros(n, m);
    for (auto& v : mat)
    {
        for (auto& elem : v)
        {
            elem = u(e);
        }
    }
    return mat;
}

}