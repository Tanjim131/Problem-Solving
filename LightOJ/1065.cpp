#include <iostream>
#include <vector>

class Matrix{
    int rows, columns;         
    static constexpr int INIT_VALUE = 0;
    //static constexpr int MOD = 1e9 + 7;

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
        
        Matrix exponentiation(int power, int mod){
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

inline static int quick_pow10(int n)
{
    static int pow10[10] = {
        1, 10, 100, 1000, 10000
    };

    return pow10[n]; 
}

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T, Case = 0; std::cin >> T;
    while(T--){
        int a,b,n,m;
        std::cin >> a >> b >> n >> m;
        int result;
        if(n == 0) result = a;
        else if(n == 1) result = b;
        else{
            Matrix mat1(1,2); mat1.matrix = {{a, b}}; // F_0 = a , F_1 = b
            Matrix mat2(2,2); mat2.matrix = {{0, 1}, {1, 1}};
            mat2 = mat2.exponentiation(n - 1, quick_pow10(m));
            Matrix product = mat1 * mat2;
            result = product.matrix[0][1];
        }
        std::cout << "Case " << ++Case << ": " << result % quick_pow10(m) << "\n";
    }
    return 0;
}
