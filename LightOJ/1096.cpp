#include <iostream>
#include <vector>

class Matrix{
    int rows, columns;         
    static constexpr int INIT_VALUE = 0;

    public:
        std::vector<std::vector <int>> matrix; 

        Matrix() = default;
        Matrix(int r, int c): rows(r), columns(c){
            perform_resize();
        }

        void takeInput(){
            std::cin >> rows >> columns;
            perform_resize();
            for(int i = 0 ; i < rows ; ++i){
                for(int j = 0 ; j < columns ; ++j){
                    std::cin >> matrix[i][j];
                }
            }
        }

        void perform_resize(){
            matrix.resize(rows, std::vector <int> (columns, INIT_VALUE));
        }

        int getRows() const {
            return rows;
        }

        int getColumns() const{
            return columns;
        }

        void printMatrix() const{
            std::cout << "Number of rows: " << rows << "\n";
            std::cout << "Number of columns: " << columns << "\n";

            for(int i = 0 ; i < rows ; ++i){
                for(int j = 0 ; j < columns ; ++j){
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }

        Matrix operator*(const Matrix &mat) const{
            int product_rows = rows;
            int product_columns = mat.getColumns();

            Matrix product(product_rows, product_columns);

            for(int i = 0 ; i < product_rows ; ++i){
                for(int j = 0 ; j < product_columns ; ++j){
                    int sum_of_products = 0;
                    for(int k = 0 ; k < columns ; ++k){
                        sum_of_products += matrix[i][k] * mat.matrix[k][j];
                    }
                    product.matrix[i][j] = sum_of_products; 
                }
            }

            return product;
        }

        Matrix& operator %(int mod){
            for(int i = 0 ; i < rows ; ++i){
                for(int j = 0 ; j < columns ; ++j){
                    matrix[i][j] %= mod;
                }
            }
            return *this;
        }

        Matrix generate_identity_matrix(){
            Matrix identity(rows, columns);
            for(int i = 0 ; i < rows ; ++i){
                for(int j = 0 ; j < columns ; ++j){
                    if(i == j) identity.matrix[i][j] = 1;
                }
            }
            return identity;
        }
        
        Matrix exponentiation(int power, int mod = 1e9 + 7){
            if(power <= 0) return *this % mod;
            Matrix result = generate_identity_matrix();
            while(power > 0){
                if((power & 1) == 1){
                    result = (result * (*this)) % mod;
                }
                *this = ((*this) * (*this)) % mod;
                power >>= 1;
            }
            return result % mod;
        }
};

constexpr int Matrix::INIT_VALUE; // required up to C++ 14, deprecated in C++ 17

int main(int argc, char const *argv[])
{
    int T, Case = 0; std::cin >> T;
    while(T--){
        int n,a,b,c;
        std::cin >> n >> a >> b >> c;
        int result, MOD = 1e4 + 7;
        if(n <= 2) result = 0;
        else{
            Matrix mat1(1,4); mat1.matrix = {{c, 0, 0, 0}}; // F_0 = a , F_1 = b
            Matrix mat2(4,4); mat2.matrix = {{1, 0, 0, 1}, {0, 0, 0, b}, {0, 1, 0, 0}, {0, 0, 1, a}};
            mat2 = mat2.exponentiation(n - 2, MOD);
            Matrix product = mat1 * mat2;
            result = product.matrix[0][3];
        }
        std::cout << "Case " << ++Case << ": " << result % MOD << "\n";
    }
    return 0;
}
