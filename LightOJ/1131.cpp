#include <iostream>
#include <vector>

class Matrix{
    int rows, columns;         
    static constexpr int INIT_VALUE = 0;

    public:
        std::vector<std::vector <long long>> matrix; 

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


        void perform_resize(){
            matrix.resize(rows, std::vector <long long> (columns, INIT_VALUE));
        }

        int getRows() const {
            return rows;
        }

        int getColumns() const{
            return columns;
        }

        Matrix operator*(const Matrix &mat) const{
            int product_rows = rows;
            int product_columns = mat.getColumns();

            Matrix product(product_rows, product_columns);

            for(int i = 0 ; i < product_rows ; ++i){
                for(int j = 0 ; j < product_columns ; ++j){
                    long long sum_of_products = 0;
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
        
        Matrix exponentiation(int power, int MOD){
            if(power <= 0) return *this % MOD;
            Matrix result = generate_identity_matrix();
            while(power > 0){
                if((power & 1) == 1){
                    result = (result * (*this)) % MOD;
                }
                *this = ((*this) * (*this)) % MOD;
                power >>= 1;
            }
            return result % MOD;
        }
};

constexpr int Matrix::INIT_VALUE; // required up to C++ 14, deprecated in C++ 17

// matrix elements are in the order of 25000
// in cases of 6 x 6 matrix multiplication, 25000 * 25000 * 6 will overflow
// so long long is necessary

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T, Case = 0; std::cin >> T;
    while(T--){
        int a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,M,q;
        std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> f0 >> f1 >> f2 >> g0 >> g1 >> g2 >> M >> q;
        int result_f, result_g;
        std::cout << "Case " << ++Case << ":\n";
        for(int i = 0 ; i < q ; ++i){
            int n; std::cin >> n;
            if(n == 0){
                result_f = f0;
                result_g = g0;
            } else if(n == 1){
                result_f = f1;
                result_g = g1;
            } else if(n == 2){
                result_f = f2;
                result_g = g2;
            } else{
                Matrix mat1(1,6); mat1.matrix = {{g0, f0, g1, f1, g2, f2}};
                Matrix mat2(6,6); mat2.matrix = {{0, 0, 0, 0, 0 , c1}, {0, 0, 0, 0, c2, 0}, {1, 0, 0, 0, b2, 0}, {0, 1, 0, 0, 0, b1}, {0, 0, 1, 0, a2, 0}, {0, 0, 0, 1, 0, a1}};
                mat2 = mat2.exponentiation(n - 2, M);
                Matrix product = mat1 * mat2;
                result_f = product.matrix[0][5];
                result_g = product.matrix[0][4];
            }
            std::cout << result_f % M << " " << result_g % M << "\n";
        }
    }
    return 0;
}
