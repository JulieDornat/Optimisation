#include <cassert>
#include <iostream>
#include <array>
#include <concepts>
#include <vector>

int main(){

    // Test for dyadic operator
    Householder_array<float,7> h({1,2,3,4,5,6,7});
    static_assert(std::is_same<decltype(h.get_mat()), matrix<float,7,7>>::value);
    const std::size_t N = 3;
    Householder_array<int,N> h1({1,2,3});
    Householder_array<float,N> h2({1,2,3});
    matrix<float,N,N> expected = {
        std::array<float,N>{6, -2, -3},
        std::array<float,N>{-2, 3, -6},
        std::array<float,N>{-3, -6, -2}
    };
    expected = expected/(float)7;
    matrix<float, N,N> value = h2.get_mat();
    static_assert(std::is_same<decltype(h1.get_mat()), matrix<int,N,N>>::value);
    for(std::size_t i = 0; i < N; i++){
        for(std::size_t j = 0; j < N; j++){
            printf("val = %d \n", value[i][j]);
            printf("expected = %d \n", expected[i][j]);
            assert((value[i][j] == expected[i][j]));
        }
    }
}