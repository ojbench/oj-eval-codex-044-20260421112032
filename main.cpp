#include <bits/stdc++.h>
using namespace std;

class mystring {
private:
    char *ch = nullptr;
    int len = 0;

public:
    mystring() : ch(nullptr), len(0) {}

    mystring(int _len, int c) : ch(nullptr), len(0) {
        if (_len > 0) {
            len = _len;
            ch = new char[len];
            std::fill(ch, ch + len, static_cast<char>(c));
        }
    }

    mystring(string &c) : ch(nullptr), len(0) {
        len = static_cast<int>(c.length());
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, c.data(), len);
        }
    }

    mystring(const mystring &other) : ch(nullptr), len(other.len) {
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, other.ch, len);
        }
    }

    mystring &operator=(const mystring &other) {
        if (this == &other) return *this;
        delete[] ch;
        ch = nullptr;
        len = other.len;
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, other.ch, len);
        }
        return *this;
    }

    ~mystring() {
        delete[] ch;
        ch = nullptr;
        len = 0;
    }

    char operator[](int idx) const {
        if (idx < 0 || idx >= len) return '\0';
        return ch[idx];
    }

    bool operator<(const mystring &rhs) const {
        int minlen = std::min(len, rhs.len);
        for (int i = 0; i < minlen; ++i) {
            if (ch[i] != rhs.ch[i]) return ch[i] < rhs.ch[i];
        }
        return len < rhs.len;
    }

    bool operator==(const mystring &rhs) const {
        if (len != rhs.len) return false;
        if (len == 0) return true;
        return memcmp(ch, rhs.ch, len) == 0;
    }

    void ADD(const mystring &rhs) {
        if (rhs.len == 0) return;
        if (len == 0) {
            delete[] ch;
            len = rhs.len;
            if (len > 0) {
                ch = new char[len];
                memcpy(ch, rhs.ch, len);
            }
            return;
        }
        int newlen = len + rhs.len;
        char *nw = new char[newlen];
        memcpy(nw, ch, len);
        memcpy(nw + len, rhs.ch, rhs.len);
        delete[] ch;
        ch = nw;
        len = newlen;
    }

    mystring &operator+=(const mystring &rhs) {
        ADD(rhs);
        return *this;
    }
    friend mystring operator+(mystring lhs, const mystring &rhs) {
        lhs += rhs;
        return lhs;
    }

    void out() const {
        for (int i = 0; i < len; ++i) cout << ch[i];
    }

    int get_len() const { return len; }

    friend ostream &operator<<(ostream &os, const mystring &s) {
        for (int i = 0; i < s.len; ++i) os << s.ch[i];
        return os;
    }
};

string str_in1, str_in2;
int n, id;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> id)) return 0;
    if (id == 1) {
        mystring str1(100, 'a');
        str1.out();
        puts("");
    } else if (id == 2) {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str2[x] << '\n';
        }
    } else if (id == 3) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << '\n';
    } else if (id == 4) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out();
        puts("");
    } else {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str3[x] << '\n';
        }
        cout << str2.get_len() << " " << str3.get_len() << '\n';
        cout << (int)(str2 < str3) << '\n';
        str2.ADD(str3);
        str2.out();
        puts("");
    }
    return 0;
}
