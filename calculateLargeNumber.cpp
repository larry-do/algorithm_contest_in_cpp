#include <iostream>
#include <string>
using namespace std;
string sumPositiveNumber(string a, string b){
	if(a.length() >= b.length()) b.insert(0,a.length()-b.length(),'0');
	else a.insert(0,b.length()-a.length(),'0');
	string c = "";
	int memory = 0;
	for (int i = a.length()-1; i >= 0; --i){
		memory+=a[i]+b[i]-'0'-'0';
		c.insert(0, 1, memory%10+'0');
		memory/=10;
	}
	if(memory!=0) c.insert(0, 1, memory+'0');
	return c;
}
string minusPositiveNumber(string a, string b){
    if(a.length() >= b.length()) b.insert(0,a.length()-b.length(),'0');
	else a.insert(0,b.length()-a.length(),'0');
    string c = "";
    int memory = 0, compare = a.compare(b);
    for(int i = a.length() - 1; i >= 0; --i){
        int k = ((compare >= 0)?(a[i] - b[i]):(b[i] - a[i])) + memory;
        if(k >= 0){
            c.insert(0, 1, k + '0');
            memory = 0;
        }
        else{
            c.insert(0, 1, k + 10 + '0');
            memory = -1;
        }
    }
    while(c[0] == '0') c.erase(0, 1);
    if(compare < 0) c.insert(0, 1, '-');
    return (!c.length())?"0":c;
}
string addLargeNumber(string a, string b){
    if(a[0] != '-' && b[0] != '-') return sumPositiveNumber(a, b);
    else if(a[0] != '-' && b[0] == '-') return minusPositiveNumber(a, b.erase(0, 1));
    else if(a[0] == '-' && b[0] != '-') return minusPositiveNumber(b, a.erase(0, 1));
    else if(a[0] == '-' && b[0] == '-') return "-" + sumPositiveNumber(a.erase(0, 1), b.erase(0, 1));
}
string subtractLargeNumber(string a, string b){
    if(a[0] != '-' && b[0] != '-') return minusPositiveNumber(a, b);
    else if(a[0] != '-' && b[0] == '-') return sumPositiveNumber(a, b.erase(0, 1));
    else if(a[0] == '-' && b[0] != '-') return "-" + sumPositiveNumber(a.erase(0, 1), b);
    else if(a[0] == '-' && b[0] == '-') return minusPositiveNumber(b.erase(0, 1), a.erase(0, 1));
}
string multiPositiveLargeNumberWithDigit(string a, short b){
    string c = "";
    int memory = 0;
    for(int i = a.length() - 1; i >= 0; i--){
        memory+=(a[i] - '0')*b;
        c.insert(0, 1, memory%10 + '0');
        memory/=10;
    }
    if(memory != 0) c.insert(0, 1, memory + '0');
    while(c[0] == '0') c.erase(0, 1);
    return (!c.length())?"0":c;
}
string multiLargeNumber(string a, string b){
    string symbol = "";
    if((a[0] != '-' && b[0] == '-') || (a[0] == '-' && b[0] != '-')) symbol = "-";
    if(a[0] == '-') a.erase(0, 1);
    if(b[0] == '-') b.erase(0, 1);
    string c = "";
    for(int i = a.length() - 1; i >= 0; i--){
        string tmp = multiPositiveLargeNumberWithDigit(b, a[i] - '0');
        tmp.insert(tmp.length(), a.length() - 1 - i, '0');
        c = addLargeNumber(c, tmp);
    }
    while(c[0] == '0') c.erase(0, 1);
    return (!c.length())?"0":(symbol + c);
}
short compareLargeNumber(string a, string b){
    if(a[0] != '-' && b[0] != '-'){
        if(a.length() >= b.length()) b.insert(0,a.length()-b.length(),'0');
        else a.insert(0, b.length()-a.length(),'0');
        return a.compare(b);
    }
    else if(a[0] == '-' && b[0] != '-') return -1;
    else if(a[0] != '-' && b[0] == '-') return 1;
    else if(a[0] == '-' && b[0] == '-'){
        a.erase(0, 1);
        b.erase(0, 1);
        if(a.length() >= b.length()) b.insert(0,a.length()-b.length(),'0');
        else a.insert(0,b.length()-a.length(),'0');
        return 0 - a.compare(b);
    }
}
string division(string a, string b){
    string c = "";
    int pos = 0;
    string mod = a.substr(pos, 1);
    while(compareLargeNumber(mod, "0") >= 0 && pos < a.length()){
        int k = 0;
        while(compareLargeNumber(mod, multiPositiveLargeNumberWithDigit(b, k + 1)) >= 0) k++;
        c.push_back(k + '0');
        mod = subtractLargeNumber(mod, multiPositiveLargeNumberWithDigit(b, k)) + a.substr(++pos, 1);
    }
    while(c[0] == '0') c.erase(0, 1);
    return (!c.length())?"0":c;
}
string calulateRemainder(string a, string b){
    int pos = 0;
    string mod = a.substr(pos, 1);
    while(compareLargeNumber(mod, "0") >= 0 && pos < a.length()){
        int k = 0;
        while(compareLargeNumber(mod, multiPositiveLargeNumberWithDigit(b, k + 1)) >= 0) k++;
        mod = subtractLargeNumber(mod, multiPositiveLargeNumberWithDigit(b, k)) + a.substr(++pos, 1);
    }
    return mod;
}
int main(){
    string n; cin>>n;
    string result;
    result = multiLargeNumber(n, addLargeNumber(n, "1"));
    result = multiLargeNumber(result, addLargeNumber(multiPositiveLargeNumberWithDigit(n, 2), "1"));
    result = division(result, "6");
    cout<<result;
    return 0;
}
