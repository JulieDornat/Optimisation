#include "calculopti.hpp"


template<typename T>
concept arithmetic = requires(T a, T b ){
    { a/b };
    {a*b} -> std::convertible_to<T>;
    {a - b} -> std::convertible_to<T>;
    {a + b} -> std::convertible_to<T>;
};

template<typename T>
concept factor = requires(T a, T b){
    { a/b };
    { a*b } -> std::convertible_to<T>;
};

template <arithmetic T, std::size_t N, std::size_t M> 
using matrix = std::array<std::array<T,N>,M>;

/// @brief Computes the dyadic tensor.
/// @tparam T factor type
/// @tparam N size
/// @param v first vector of size N.
/// @param u second vector of size N.
/// @return A (N,N) matrix containing the dyadic product.
template<factor T, std::size_t N>
matrix<T,N,N> dyadic_tensor(std::array<T,N> v, std::array<T,N> u){
    matrix<T,N,N> dyadic = {};
    for(std::size_t i = 0; i < N; i++){
        for(std::size_t j = 0; j < N; j++){
            dyadic[i][j] = v[i]*u[j];
        }
    }
    return dyadic;
}

/// @brief Computes the scalar product of a vector*.
/// @tparam T factor type
/// @tparam N size
/// @param v A vector of size N.
/// @return The scalar result of type T.
template<factor T, std::size_t N>
T scalar_product(std::array<T,N> v){
    T scalar = 0;
    for(std::size_t i = 0; i < N; i++){
        scalar += v[i]*v[i];
    }
    return scalar;
}

/// @brief Overloads the - operator to perform element-wise subtraction between two matrices.
/// @tparam T arithmetic type
/// @tparam N size
/// @tparam M size
/// @param m1 The first matrix of size (N,M)
/// @param m2 The second matrix of size (N,M)
/// @return A matrix of size (N,M) representing the difference.
template<arithmetic T, std::size_t N, std::size_t M> 
matrix<T,N,M> operator-(matrix<T,N,M> m1, matrix<T,N,M> m2 ){
    matrix<T,N,M> sub;
    for(std::size_t i = 0; i < N; i++){
        for(std::size_t j = 0; j < M; j++){
            sub[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return sub;
}

/// @brief Overloads the * operator to multiply all elements of a matrix by a scalar coefficient.
/// @tparam T arithmetic type
/// @tparam N size
/// @tparam M size
/// @param m1 A matrix of size (N,M).
/// @param coef A scalar of type T.
/// @return A matrix of size (N,M) with each element multiplied by coef.
template<arithmetic T, std::size_t N, std::size_t M> 
matrix<T,N,M> operator*(matrix<T,N,M> m1, T coef){
    matrix<T,N,M> prod;
    for(std::size_t i = 0; i < N; i++){
        for(std::size_t j = 0; j < M; j++){
            prod[i][j] = m1[i][j] * coef;
        }
    }
    return prod;
}

/// @brief Overloads the / operator to divide all elements of a matrix by a scalar coefficient.
/// @tparam T arithmetic type
/// @tparam N size
/// @tparam M size
/// @param m1 A matrix of size (N,M).
/// @param coef A scalar of type T.
/// @return A matrix of size (N,M) with each element divided by coef.
template<arithmetic T, std::size_t N, std::size_t M> 
matrix<T,N,M> operator/(matrix<T,N,M> m1, T coef){
    matrix<T,N,M> prod;
    for(std::size_t i = 0; i < N; i++){
        for(std::size_t j = 0; j < M; j++){
            prod[i][j] = m1[i][j] / coef;
        }
    }
    return prod;
}

/// @brief Represents a Householder using an array. It encapsulates the reflection operation for a given vector to compute Householder matrices or transformations.
/// @tparam T arithmetic type
/// @tparam N size
template<arithmetic T, std::size_t N>
struct Householder_array{
    private :
        matrix<T,N,N> mat;
    public:
        Householder_array(std::array<T,N> v){
            T scalar = scalar_product(v);
            matrix<T,N,N> dyadic = dyadic_tensor(v,v);
            for(std::size_t i = 0; i < N; i++){
                for(std::size_t j = 0; j < N; j++){
                    // i-j = 0 => diag
                    if(i == j){
                        mat[i][j] = 1 - 2*dyadic[i][j]/scalar;
                    }
                    else{
                        mat[i][j] = 2*dyadic[i][j]/scalar;
                    }
                    
                }
            } 
        }

        matrix<T,N,N> get_mat() const{
            return mat;
        }
};

/// @brief Represents a Householder transformation using a vector directly.
/// @tparam T arithmetic type
/// @tparam N size
template<arithmetic T, std::size_t N>
struct Householder_vector{
    private :
        std::vector<std::vector<T>> mat;
    public:
        Householder_vector(std::vector<T> v){
            
            
        }
};