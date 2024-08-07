class Solution {
public:

    vector<string>unit = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string>ones = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string>tens = {"", "", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty", "Ninety"};


    vector<string>result;
    bool getThreeDigitToWords(string num) {
        string res = "";
        if(num.size() > 3) {
            num = num.substr(0, 3);
        }
        if(num == "000")
            return false;

        if(num[0] != '0') {
            result.push_back(unit[num[0]-'0']);
            result.push_back("Hundred");
        }
        if(num[1] == '1') {
            result.push_back(ones[num[2]- '0']);
        }else {
            if(tens[num[1] - '0'] != "")
                result.push_back(tens[num[1]-'0']);
            
            if(unit[num[2] - '0'] != "")
                result.push_back(unit[num[2]-'0']);
        }

        return true;
    }

    string numberToWords(int num) {
        if(num == 0)return "Zero";

        string number = to_string(num);
        int size = number.size();

        if(size % 3 == 1) {
            number = "00" + number;
        } else if(size % 3 == 2) {
            number = "0" + number;
        }

        size = number.size();

        string res = "";
        if(size == 12) {
            /*Billion Place - Finding the Billion value Substring*/
            string nums = number.substr(size-12, size-9);
            if(getThreeDigitToWords(nums)){
                result.push_back("Billion");
            }
        }
        if(size >= 9) {
            /*Million Place - Finding the Million value Substring*/
            string nums = number.substr(size-9, size-6);
            if(getThreeDigitToWords(nums)) {
                result.push_back("Million");
            }   
        }
        if(size >= 6) {
            /*Thousand Place - Finding the Thosuand value Substring*/
            string nums = number.substr(size-6, size-3);
            if(getThreeDigitToWords(nums)) {
                result.push_back("Thousand");
            }
        }
        if(size >= 3) {
            /*Hundred Place - Finding the Hundred value Substring*/
            string nums = number.substr(size-3, size);
            getThreeDigitToWords(nums);
        }

        for(auto& r : result) {
            if(res != ""){
                res = res + " ";
            }
            res += r;
        }

        return res;
    }

};