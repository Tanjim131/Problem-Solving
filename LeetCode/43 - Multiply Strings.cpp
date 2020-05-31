class Solution {
public:
    
    void normalize(std::string &s){
        for(int i = s.size() - 1; i >= 0 && s[i] == '0' ; --i){
            s.pop_back();
        }
    }
    
    string add(const std::string &num1, const std::string &num2){
        std::string ans;
        int carry = 0;
        int len = std::max(num1.size(), num2.size());
        for(int i = 0 ; i < len ; ++i){
            int sum = 0;
            if(i < num1.size() && i < num2.size()){
                sum = (num1[i] - '0') + (num2[i] - '0') + carry;
            } else if(i >= num1.size()){
                sum = (num2[i] - '0') + carry;
            } else{
                sum = (num1[i] - '0') + carry;
            }
            carry = sum / 10;
            ans += '0' + (sum % 10);
        }
        if(carry) ans += '0' + carry;
        normalize(ans);
        return ans.empty() ? "0" : ans;
    }
    
    string multiply(string num1, string num2) {
        std::string sum_of_products;
        for(int i = num1.size() - 1 ; i >= 0 ; --i){
            std::string product;
            for(int k =  0 ; k < num1.size() - 1 - i ; ++k) product += '0';
            int carry = 0;
            for(int j = num2.size() - 1 ; j >= 0 ; --j){
                int prod = (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = prod / 10;
                product += '0' + prod % 10;
            }
            
            if(carry) product += '0' + carry;
            //normalize(product);
            sum_of_products = add(sum_of_products, product);
        }
        normalize(sum_of_products);
        reverse(sum_of_products.begin(), sum_of_products.end());
        return sum_of_products.empty() ? "0" : sum_of_products;
    }
};