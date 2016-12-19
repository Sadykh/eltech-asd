#include <list>
#include <string>

using namespace std;
//..........Массивы

class Set {
private:
    static int N;
    string S;
public:
    Set operator|(const Set &B) const {
        Set *C = new Set(*this);
        for (int i = 0; i < B.S.size(); i++) {
            bool f = true;
            for (int j = 0; j < S.size(); j++)
                if (B.S[i] == S[j]) f = false;
            if (f) C->S.push_back(B.S[i]);
        }
        return *C;
    }

    Set operator&(const Set &B) const {
        Set *C = new Set(*this);
        C->S = string();
        for (int i = 0; i < S.size(); i++) {
            for (int j = 0; j < B.S.size(); j++)
                if (S[i] == B.S[j]) C->S.push_back(S[i]);
        }
        return *C;
    }

    Set operator~() const {
        Set *C = new Set(*this);
        C->S = string();
        for (char c = 'A'; c <= 'Z'; c++) {
            bool f = true;
            for (int j = 0; j < S.size(); j++)
                if (c == S[j]) {
                    f = false;
                    break;
                }
            if (f) C->S.push_back(c);
        }
        return *C;
    }

    void Show() {
        cout << S << endl;
    }

    Set(string elements) { S = string(elements); }

    Set() {
        S = string();
        for (int i = 0; i < N; i++)
            if (rand() % 2)
                S.push_back(char(i + 'A'));
    }

    Set(const Set &B) : S(B.S) {}

    Set operator=(const Set &B) {
        if (this != &B) {
            N = B.N;
            S = string(B.S);
        }
        return *this;
    }

    ~Set() {}
};

//..........Списки

//class Set {
//private:
//    static int N;
//    list<char> S;
//public:
//    Set operator|(const Set &B) const {
//        Set *C = new Set(*this);
//        C->S = list<char>(S);
//        for (std::list<char>::const_iterator it = B.S.begin(); it != B.S.end(); ++it) {
//            bool f = true;
//            for (std::list<char>::const_iterator it2 = S.begin(); it2 != S.end(); ++it2)
//                if (*it == *it2) f = false;
//            if (f) C->S.push_back(*it);
//        }
//        return *C;
//    }
//
//    Set operator&(const Set &B) const {
//        Set *C = new Set(*this);
//        C->S = list<char>();
//        for (std::list<char>::const_iterator it = S.begin(); it != S.end(); ++it) {
//            for (std::list<char>::const_iterator it2 = B.S.begin(); it2 != B.S.end(); ++it2)
//                if (*it == *it2) C->S.push_back(*it);
//        }
//        return *C;
//    }
//
//    Set operator~() const {
//        Set *C = new Set(*this);
//        C->S = list<char>();
//        for (char c = 'A'; c <= 'Z'; c++) {
//            bool f = true;
//            for (std::list<char>::const_iterator it = S.begin(); it != S.end(); ++it)
//                if (c == *it) {
//                    f = false;
//                    break;
//                }
//            if (f) C->S.push_back(c);
//        }
//        return *C;
//    }
//
//    void Show() {
//        for (std::list<char>::const_iterator it = S.begin(); it != S.end(); ++it)
//            cout << *it;
//        cout << endl;
//    }
//
//    Set(string elements) {
//        S = list<char>();
//        for (int i = 0; i < elements.size(); i++)
//            S.push_back(elements[i]);
//    }
//
//    Set() {
//        S = list<char>();;
//        for (int i = 0; i < N; i++)
//            if (rand() % 2)
//                S.push_back(char(i + 'A'));
//    }
//
//    Set(const Set &B) : S(B.S) {}
//
//    Set operator=(const Set &B) {
//        if (this != &B) {
//            N = B.N;
//            S = list<char>(B.S);
//        }
//        return *this;
//    }
//
//    ~Set() {}
//};

//.........Массивы бит
//
//class Set {
//private:
//    static int N;
//    bool *S;
//public:
//    Set operator|(const Set &B) const {
//        Set *C = new Set(*this);
//        for (int i = 0; i < 26; i++)
//            C->S[i] = S[i] || B.S[i];
//        return *C;
//    }
//
//    Set operator&(const Set &B) const {
//        Set *C = new Set(*this);
//        for (int i = 0; i < 26; i++)
//            C->S[i] = S[i] && B.S[i];
//        return *C;
//    }
//
//    Set operator~() const {
//        Set *C = new Set(*this);
//        for (int i = 0; i < 26; i++)
//            C->S[i] = !S[i];
//        return *C;
//    }
//
//    void Show() {
//        for (int i = 0; i < 26; i++)
//            if (S[i])cout << char('A' + i);
//        cout << endl;
//    }
//
//    Set(string elements) {
//        S = new bool[26]{0};
//        for (int i = 0; i < elements.size(); i++)
//            S[elements[i] - 'A'] = 1;
//    }
//
//    Set() {
//        S = new bool[26]{0};
//        for (int i = 0; i < N; i++)
//            if (rand() % 2)
//                S[i] = 1;
//    }
//
//    Set(const Set &B) {
//        N = B.N;
//        S = new bool[26];
//        memcpy(this->S, B.S, (26) * sizeof(bool));
//    }
//
//    Set operator=(const Set &B) {
//        if (this != &B) {
//            N = B.N;
//            S = new bool[26];
//            memcpy(this->S, B.S, (26) * sizeof(bool));
//        }
//        return *this;
//    }
//
//    ~Set() {
//        delete[] S;
//        S = nullptr;
//    }
//};

//..........Машинные слова
//class Set {
//private:
//    static int N;
//    int S;
//public:
//    Set operator|(const Set &B) const {
//        Set *C = new Set(*this);
//        C->S = S | B.S;
//        return *C;
//    }
//
//    Set operator&(const Set &B) const {
//        Set *C = new Set(*this);
//        C->S = S & B.S;
//        return *C;
//    }
//
//    Set operator~() const {
//        Set *C = new Set(*this);
//        C->S = (~S);
//        return *C;
//    }
//
//    void Show() {
//        for (int i = 0; i < 26; i++)
//            if ((S >> i) & 1)
//                cout << char(i + 'A');
//        cout << endl;
//    }
//
//    Set(string elements) {
//        S = 0;
//        for (int i = 0; i < elements.size(); i++)
//            S = S | (1 << (elements[i] - 'A'));
//    }
//
//    Set() {
//        S = 0;
//        for (int i = 0; i < N; i++)
//            if (rand() % 2)
//                S = S | (1 << (i));
//    }
//
//    Set(const Set &B) {
//        N = B.N;
//        S = B.S;
//    }
//
//    Set operator=(const Set &B) {
//        if (this != &B) {
//            N = B.N;
//            S = B.S;
//        }
//        return *this;
//    }
//
//    ~Set() {}
//};

int Set::N = 26;
