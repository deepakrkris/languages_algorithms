#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;
/**
 * @brief 
 * {"23456789234"}  we can make IP address of
 * 
 * @brief 
 * @param s 
 * @param curr 
 * @param pos 
 * @param ip 
 * @param result 
 * 
 * 
 *  11234
 *  1 12 3 4
 *  1 1 2 34
 * 
 *  1
 *  11
 *  112  
 *  
 */
void find_ip_comb(string s,
    string curr,
    int pos,
    vector<string> ip,
    vector<string>& result) {
    if (ip.size() == 4 && pos < s.length()) {
      return;
    } else if (ip.size() == 4) {
      return;
    }

    if (pos < s.length())
      return;
  
    if (curr != "" && std::stoi(curr + s[pos]) <= 255 ) {
      find_ip_comb(s, curr + s[pos], pos + 1, ip, result);
    }

    if (s[pos] != '0') {
      vector<string> new_ip(ip);
      ip.push_back(curr);
      find_ip_comb(s, "", pos + 1, new_ip, result);
    }
}

int main() {
  vector<string> result;
  vector<string> ip;
  find_ip_comb("112023", "", 0, ip, result);
}
