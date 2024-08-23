class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1, i = 0;
        int n = expression.size();

        while(i < n) {
            bool isNegative = false;
            if(expression[i] == '-'){
                isNegative = true;
            }
            if(expression[i] == '-' || expression[i] == '+'){
                i++;
            }
            int num =0;
            while(i < n && expression[i] >= '0' && expression[i] <= '9'){
                num= num*10 + (expression[i] - '0');
                i++;
            }
            if(isNegative){
                num = num*-1;
            }
            i++;
            int den = 0;
            while(i < n && expression[i] >= '0' && expression[i] <= '9'){
                den = den*10 + (expression[i] - '0');
                i++;
            }
            numerator = numerator*den + num*denominator;
            denominator = denominator*den;

            int hcf = gcd(abs(numerator), denominator);
            numerator = numerator/hcf;
            denominator = denominator/hcf;

        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};