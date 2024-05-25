#include <bits/stdc++.h>

using namespace std;

class BigNum {
private:
    vector<int> vec;
public:
    BigNum() {
        vec.push_back(0); 
    }

    BigNum(int val) {
        if (val == 0) 
            re_size(1);
        for (; val > 0; val /= 10)
            vec.push_back(val%10);
        reverse(vec.begin(), vec.end());
    }

    BigNum(string str) {
        vec.resize(str.size());
        for (int i = 0; i < (int) vec.size(); ++i)
            vec[i] = str[i] - '0';
    }

    void re_size(int sz) {
        vec.resize(sz);
        fill(vec.begin(), vec.end(), 0);
    }

    void delete_zeros() {
        while (vec.size() > 1 && *vec.begin() == 0) 
            vec.erase(vec.begin());
    }

    void add_zeros(int len) {
        while (len--)
            vec.insert(vec.begin(), 0);
    }

    void add_zeros(BigNum &other) {
        int max_size = max(vec.size(), other.vec.size());
        this->add_zeros(max(0, max_size - (int) vec.size()));
        other.add_zeros(max(0, max_size - (int) other.vec.size()));
    }

    BigNum fix() {
        delete_zeros();
        while (!vec.empty() && vec[0] > 9) {
            vec.insert(vec.begin(), vec[0] / 10);
            vec[0] %= 10;
        }
        return *this;
    }

    friend ostream& operator << (ostream&, const BigNum &obj) {
        for (int x : obj.vec) 
            cout << x;
        return cout;
    }

    friend istream& operator >> (istream& cin, BigNum &obj) {
        string str;
        cin >> str;
        obj = BigNum(str);
        return cin;
    }

    bool operator == (BigNum other) {
        delete_zeros();
        other.delete_zeros();
        if (vec.size() != other.vec.size()) return false;
        for (int i = 0; i < vec.size(); ++i) 
            if (vec[i] != other.vec[i]) return false;
        return true; 
    }

    bool operator > (BigNum other) {
        delete_zeros();
        other.delete_zeros();
        if (vec.size() != other.vec.size()) {
            return vec.size() > other.vec.size();
        }
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] != other.vec[i]) 
                return vec[i] > other.vec[i];
        }
        return false;
    }

    bool operator < (BigNum other) {
        return !(*this >= other);
    }

    bool operator >= (BigNum other) {
        return *this > other || *this == other;
    }

    bool operator <= (BigNum other) {
        return !(*this > other);
    }

    bool operator != (BigNum other) {
        return !(*this == other);
    }

    BigNum operator ++ () {
        *this = *this + 1;
        return *this;
    }

    BigNum operator -- () {
        *this = *this - 1;
        return *this;
    }

    BigNum operator += (BigNum other) {
        *this = *this + other;
        return *this;
    }

    BigNum operator -= (BigNum other) {
        *this = *this - other;
        return *this;
    }

    BigNum operator *= (int other) {
        *this = *this * other;
        return *this;
    }

    BigNum operator *= (BigNum other) {
        *this = *this * other;
        return *this;
    }

    BigNum operator /= (int other) {
        *this = *this / other;
        return *this;
    }

    BigNum operator /= (BigNum other) {
        *this = *this / other;
        return *this;
    }

    BigNum operator %= (int other) {
        *this = *this % other;
        return *this;
    }

    BigNum operator %= (BigNum other) {
        *this = *this % other;
        return *this;
    }

    BigNum operator + (BigNum other) {
        this->delete_zeros();
        other.delete_zeros();
        this->add_zeros(other);

        BigNum result;
        result.re_size(vec.size());
        int remember = 0;
        for (int i = vec.size() - 1; i >= 0; --i) {
            int sum = vec[i] + other.vec[i] + remember;
            result.vec[i] = sum%10;
            remember = sum/10;
        }
        if (remember > 0) 
            result.vec.insert(result.vec.begin(), 1);
        return result;
    }

    BigNum subtract(BigNum other) {
        delete_zeros();
        other.delete_zeros();
        add_zeros(other);

        BigNum result;
        result.re_size(vec.size());
        int remember = 0;
        for (int i = vec.size() - 1; i >= 0; --i) {
            int diff = vec[i] - (other.vec[i] + remember);
            if (diff < 0) {
                diff += 10;
                remember = 1;
            } else {
                remember = 0;
            }
            result.vec[i] = diff;
        }
        result.delete_zeros();
        return result;
    }

    BigNum operator - (BigNum other) {
        if (*this > other) {
            return this->subtract(other);
        }
        BigNum result = other.subtract(*this);
        result.vec[0] *= -1;
        return result;
    }

    BigNum operator * (int other) {
        delete_zeros();
        BigNum result;
        result.re_size(vec.size());
        int remember = 0; 
        for (int i = vec.size() - 1; i >= 0; --i) {
            result.vec[i] = other * vec[i] + remember;
            remember = result.vec[i] / 10;
            result.vec[i] %= 10;
        }

        while (remember) {
            result.vec.insert(result.vec.begin(), remember%10);
            remember /= 10;
        }

        return result.fix();
    }

    BigNum operator * (BigNum other) {
        delete_zeros();
        other.delete_zeros();
        BigNum result;
        int sz = vec.size() + other.vec.size() - 1;
        result.re_size(sz);
        
        for (int j = other.vec.size() - 1; j >= 0; --j) {
            for (int i = vec.size() - 1; i >= 0; --i) {
                result.vec[i + j] += vec[i] * other.vec[j];
            }
        }

        int remember = 0;
        for (int i = sz - 1; i >= 0; --i) {
            if (i == 0 && result.vec[i] > 9) 
                remember = result.vec[i] / 10;
            else 
                result.vec[i - 1] += result.vec[i] / 10;
            result.vec[i] %= 10;
        }

        while (remember) {
            result.vec.insert(result.vec.begin(), remember%10);
            remember /= 10;
        }

        return result.fix();
    }

    BigNum operator / (int other) {
        delete_zeros();
        
        BigNum result(0);
        int cur = 0;
        for (int x : vec) {
            cur = cur * 10 + x;
            result.vec.push_back(cur / other);
            cur %= other;
        }
        result.delete_zeros();
        return result;
    }

    BigNum operator / (BigNum other) {
        delete_zeros();
        other.delete_zeros();
        if (*this < other) return BigNum(0);
        if (*this == other) return BigNum(1);
        BigNum result = 0;
        BigNum low = 1, high = *this;
        while (low <= high) {
            BigNum mid = (low + high) / 2;
            if (mid * other <= *this) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }   

    BigNum operator % (int other) {
        int result = 0;
        for (int num : vec) 
            result = (result * 10 + num) % other;
        return result;
    }

    BigNum operator % (BigNum other) {
        return *this - (*this / other) * other;
    }
};