#include <iostream>

using namespace std;

int getOut(int s){
    int count = 0;
    int n= 0;
    int tmp_buffer = -1;
 
    while (count != s)
    {
        n++;
        int tmp_n = n;
        while (1)
        {
            // cout << tmp_n << endl;
            if (tmp_n < 10)
            {
                if (tmp_n != tmp_buffer)
                {
                    count++;
                    if (count == s)
                    {
                        return n;
                    }
                    tmp_buffer = tmp_n;
                }
                break;
            }
            int d = tmp_n%10;
            if (d != tmp_buffer)
            {
                count++;
                if (count == s)
                {
                    return n;
                }
                tmp_buffer = d;
            }
            tmp_n /=10;
        } 
    }
    return n;
}


int main(int argc, char const *argv[])
{
    int S;
    cin >> S;
    cout << getOut(S);
    return 0;
}
