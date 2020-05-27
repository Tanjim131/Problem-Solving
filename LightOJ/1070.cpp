#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class BigInteger{
    std::string number; 

    public:
        BigInteger() = default;
        BigInteger(const std::string &num) : number(num){
            std::reverse(number.begin(), number.end());
        }
        BigInteger(int num) : number(std::to_string(num)){
            std::reverse(number.begin(), number.end());
        }
        BigInteger (const BigInteger &b) : number(b.number){}
        BigInteger (BigInteger &&b) : number(std::move(b.number)){}
        BigInteger& operator = (const BigInteger &b){
            number = b.number;
            return *this;
        }
        BigInteger& operator = (int b){
            number = std::to_string(b);
            std::reverse(number.begin(), number.end());
            return *this;
        }
        
        int get_length() const{
            return number.size();
        }

        BigInteger& normalize(){
            for(int i = number.size() - 1 ; i >= 0 && number[i] == '0' ; --i){
                number.pop_back();
            }
            return *this;   
        }

        bool operator < (const BigInteger &b) const{
            if(number.size() != b.number.size()){
                return number.size() < b.number.size();
            }
            for(int i = number.size() - 1 ; i >= 0 ; --i){
                if(number[i] != b.number[i]){
                    return number[i] < b.number[i];
                } 
            }
            return false;
        } 

        bool operator == (const BigInteger &b) const{
            return number == b.number;
        }

        BigInteger operator - (const BigInteger &b) const{
            if(*this < b){
                std::cout << "OH NO!\n";
            }

            BigInteger output;
            int borrow = 0;

            for(int i = 0 ; i < number.size() ; ++i){
                int sub = (number[i] - '0');
                if(i < b.number.size()){
                    sub -= (b.number[i] - '0') + borrow;
                } else{
                    sub -= borrow;
                }

                if(sub < 0){
                    sub += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }

                output.number += '0' + (sub % 10);
            }

            return output.normalize(); 
        }

        BigInteger operator + (const BigInteger &b) const{
            BigInteger output; 
            int carry = 0;

            int len = std::max(number.size(), b.number.size());
            
            for(int i = 0 ; i < len ; ++i){
                int sum = 0;
                if(i >= number.size()){
                    sum = (b.number[i] - '0') + carry;
                } else if(i >= b.number.size()){
                    sum = (number[i] - '0') + carry;
                } else{
                    sum = (number[i] - '0') + (b.number[i] - '0') + carry;
                }
                carry = sum / 10;
                output.number += '0' + (sum % 10);
            }
            
            if(carry) output.number += '0' + carry;
            
            return output.normalize();
        }

        
        BigInteger operator * (const BigInteger &b) const{
            BigInteger product;
            for(int i = 0 ; i < number.size() ; ++i){
                int carry = 0;

                BigInteger sum;
                for(int k = 0 ; k < i ; ++k) sum.number += '0';

                for(int j = 0 ; j < b.number.size() ; ++j){
                    int p = (number[i] - '0') * (b.number[j] - '0') + carry;
                    carry = p / 10;
                    sum.number += '0' + (p % 10);
                }

                if(carry) sum.number += '0' + carry;
                sum.normalize();
                product += sum;
            }
            
            return product.normalize();
        }

        BigInteger operator / (const BigInteger &divisor) const{
            BigInteger quotient, remainder("0");
            for(int i = 0 ; i < number.size() ; ++i) quotient.number += '0';
            for(int i = number.size() - 1 ; i >= 0 ; --i){
                remainder.number.insert(remainder.number.begin(), '0');
                remainder += number.substr(i,1);
                //std::cout << "Rem " <<  remainder << "\n";
                while(!(remainder < divisor)) {
                    remainder -= divisor;
                    quotient.number[i]++;
                }
            }
            quotient.normalize();
            return quotient.number.empty() ? BigInteger("0") : quotient;
        }

        BigInteger operator % (const BigInteger &divisor) const{
            BigInteger remainder("0");
            for(int i = number.size() - 1 ; i >= 0 ; --i){
                remainder.number.insert(remainder.number.begin(), '0');
                remainder += number.substr(i,1);
                //std::cout << "Rem " <<  remainder << "\n";
                while(!(remainder < divisor)) {
                    remainder -= divisor;
                }
            }
            remainder.normalize();
            return remainder.number.empty() ? BigInteger("0") : remainder;
        }

        BigInteger operator + (int num) const{
            BigInteger b(std::to_string(num));
            return *this + b;
        }

        BigInteger operator - (int num) const{
            BigInteger b(std::to_string(num));
            return *this - b;
        }

        BigInteger operator * (int num) const{
            BigInteger b(std::to_string(num));
            return *this * b;
        }

        BigInteger operator / (int num) const{
            BigInteger b(std::to_string(num));
            return *this / b;
        }

        BigInteger operator % (int num) const{
            BigInteger b(std::to_string(num));
            return *this % b;
        }

        BigInteger& operator += (const BigInteger &b) {
            return *this = *this + b;
        }

        BigInteger& operator -= (const BigInteger &b) {
            return *this = *this - b;
        }

        BigInteger& operator *= (const BigInteger &b) {
            return *this = *this * b;
        }

        BigInteger& operator %= (const BigInteger &b) {
            return *this = *this % b;
        }

        BigInteger& operator /= (const BigInteger &b) {
            return *this = *this / b;
        }


        void print() const{
            for(int i = number.size() - 1 ; i >= 0 ; --i){
                std::cout << number[i];
            }
            std::cout << "\n";
        }
        
        friend std::ostream& operator << (std::ostream &, const BigInteger &);

        bool isZero() const{
            return number.size() ==  1 && number[0] == '0';
        }

        bool isOdd() const{
            return (number[0] - '0') & 1;
        }
};

std::ostream& operator << (std::ostream &out, const BigInteger &b){
    return out << b.number;
}

class Matrix{
    int rows, columns;         
    static constexpr int INIT_VALUE = 0;

    public:
        std::vector<std::vector <BigInteger>> matrix; 

        Matrix() = default;
        Matrix(int r, int c): rows(r), columns(c){
            perform_resize();
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
            matrix.resize(rows, std::vector <BigInteger> (columns, INIT_VALUE));
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
                    BigInteger sum_of_products = 0;
                    for(int k = 0 ; k < columns ; ++k){
                        sum_of_products += matrix[i][k] * mat.matrix[k][j];
                    }
                    product.matrix[i][j] = sum_of_products.normalize(); 
                }
            }

            return product;
        }

        Matrix& operator %(const BigInteger &mod){
            for(int i = 0 ; i < rows ; ++i){
                for(int j = 0 ; j < columns ; ++j){
                    matrix[i][j] %= mod;
                }
            }
            return *this;
        }

        Matrix generate_identity_matrix() const{
            Matrix identity(rows, columns);
            for(int i = 0 ; i < rows ; ++i){
                for(int j = 0 ; j < columns ; ++j){
                    if(i == j) identity.matrix[i][j] = 1;
                }
            }
            return identity;
        }
        
        Matrix exponentiation(int power, const BigInteger &MOD){
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

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T, Case = 0; std::cin >> T;
    BigInteger MOD("18446744073709551616");
    while(T--){
        int p, q, n;
        std::cin >> p >> q >> n;
        int r = std::sqrt(static_cast<long long>(p) * static_cast<long long>(p) - (static_cast<long long>(q) << 2)); // r = a - b
        int a = (static_cast<long long>(p) + static_cast<long long>(r)) >> 1;
        int b = (static_cast<long long>(p) - static_cast<long long>(r)) >> 1;
        BigInteger aa(a), bb(b), nn(n);
        Matrix mat1(1,2); mat1.matrix = {{aa,bb}};
        Matrix mat2(2,2); mat2.matrix = {{aa, 0}, {0, bb}};
        mat2 = mat2.exponentiation(n - 1, MOD);
        Matrix product = mat1 * mat2;
        BigInteger a_n = product.matrix[0][0];
        BigInteger b_n = product.matrix[0][1];
        BigInteger answer = (a_n + b_n) % MOD;
        std::cout << "Case " << ++Case << ": ";
        answer.print();
    }
    return 0;
}
