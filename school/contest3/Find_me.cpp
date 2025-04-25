#include <bits/stdc++.h>


int main() {
    int n; std::cin >> n;
    int up_x = 1, down_x = n, l_y = 1, r_y = n;
    while(up_x < down_x || l_y < r_y){
        int m_x = (up_x + down_x) / 2;
        int m_y = (l_y + r_y) / 2;
      std::cout << m_x << " " << m_y << std::endl;
      std::string s; std::cin >> s;
        if(s == "N"){
           down_x = m_x - 1;
           l_y = m_y;
           r_y = m_y; 
        }
        if(s == "S"){
            up_x = m_x + 1;
            l_y = m_y;
            r_y = m_y;
        }
        if(s == "W"){
            up_x = m_x;
            down_x = m_x;
            r_y = m_y - 1;
        }
        if(s == "E"){
            up_x = m_x;
            down_x = m_x;
            l_y = m_y + 1;
        }
        if(s == "NE"){
            down_x = m_x - 1;
            l_y = m_y + 1;
        }
        if(s == "NW"){
            down_x = m_x - 1;
            r_y = m_y - 1;
        }
        if(s == "SE"){
            up_x = m_x + 1;
            l_y = m_y + 1;
        }
        if(s == "SW"){
            up_x = m_x + 1;
            r_y = m_y - 1;
        }
        if(s == "OK"){
            return 0;
        }
        }
        std::cout << up_x << " " << l_y << std::endl;
        std::string s; std::cin >> s;
}
