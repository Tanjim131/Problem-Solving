#include <iostream>
#include <algorithm>

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

        BigInteger& operator = (const BigInteger &b){
            number = b.number;
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

            output.normalize();
            return output.number.empty() ? BigInteger("0") : output;
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
            
            output.normalize();
            return output.number.empty() ? BigInteger("0") : output;
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
            
            product.normalize();
            return product.number.empty() ? BigInteger("0") : product;
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

BigInteger bigmod(const BigInteger &base, const BigInteger &exponent, const BigInteger &MOD){
    if(exponent.isZero()) return BigInteger("1");
    BigInteger ret = bigmod(base, exponent / 2, MOD);
    ret = (ret * ret) % MOD;    
    if(exponent.isOdd()) ret = (ret * base) % MOD;
    return ret;
}