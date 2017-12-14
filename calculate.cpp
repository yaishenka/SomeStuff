//yaishenka prod
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <locale>
using namespace std ;
inline void error (const string&msg) {
    throw runtime_error(msg);
}
//const block//
const char ERROR='E';
const char CONST='C';
const char HELP='h';
const char PLUS = '+';
const char MINUS = '-';
const char NAME='a';
const char LET='L';
const char NUMBER ='8';
const string PROMPT =">>";
const string DECLKEY="let";
const string CONSKEY="const";
const char PRINT = ';';
const char QUIT = 'q';
const char RESULT = '=';
const string QUITKEY="quit";
const string QUITKEY1="Quit";
const string HELPKEY="help";
const string HELPKEY1="Help";
////////////////////////////////

struct Token;
double expression ();
double primary ();

void Help () {
    cout<<"how does it work?"<<endl; //this function displays on the screen instructions to the calculator
}
struct Token { //it is struct which contains symbol and his type
    char kind;
    double val;
    string name;
    Token (char k) : kind {k} {};
    Token (char k,double val) : kind {k},val{val} {};
    Token (char k,string s): kind {k},name{s} {} ;
    Token ()=default;
};
class TokenStream { //it is our input stream
private:
    Token buf;
    bool full;
public:
    Token get(){
        if (full) {
            full=false;
            return buf;
        }
        char ch;
        ch = cin.get();
        while(ch!='\n'&&isspace(ch)) {
            ch = cin.get();
        }
        switch (ch) {
            case '\n': return Token(PRINT);
            case '+' : case '*' :   case '-': case '/': case '!': case '(': case ')' :case '%' : case '^' : case RESULT: case QUIT: case PRINT: return Token {ch};
            case '0': case '1' :case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9': case '.': {
                cin.putback(ch);
                double val;
                cin>>val;
                return Token {'8',val};
            }
            default:
                if (isalpha(ch)) {
                    string s;
                    s+=ch;
                    while (cin.get(ch) && (isalpha(ch)||isdigit(ch) || ch=='_')) {
                        s+=ch;
                    }
                    cin.putback(ch);
                    if (s==DECLKEY) {
                        return Token {LET};
                    }
                    if (s==CONSKEY) {
                        return Token {CONST};
                    }
                    if (s==HELPKEY || s==HELPKEY1) {
                        return Token {HELP};
                    }
                    if (s==QUITKEY || s==QUITKEY1) {
                        return Token {QUIT};
                    }
                    return Token {NAME,s};
                } else {
                    error("invalid symbol");
                    return Token {ERROR};
                }
        }
        return Token {'f'};
    }
    void putback (Token t) {
        if (full) {
            error ("not good0");
        } else {
            buf=t;
            full=true;
        }
    }
};
TokenStream ts;
int fact (int u) { //this function calculate factorial
    if (u==1 || u==0) {
        return 1;
    } else {
        return u*fact(u-1);
    }
}
class Variable { //it is class which contains variable which user can set
public:
    string name;
    double value;
    bool cons;
};

struct Symbol_table { //it is struct which controls variables that user sets
    vector <Variable> var_table;
    
    double get_value (string name) {
        for (const Variable &var:var_table) {
            if (var.name==name) {
                return var.value;
            }
        }
        error ("nothing here");
        return 3; //shouldn't reach that
    }
    void set_value (string name, double val) {
        for (Variable &var:var_table) {
            if (var.name==name) {
                if (!var.cons) var.value=val;
            } else {
                error("nothing there");
            }
        }
        
    }
    bool is_declared (string name) {
        for (const Variable &var:var_table) {
            if (var.name==name) {
                return true;
            }
        }
        return false;
    }
    bool is_cons (string name) {
        for (const Variable &var:var_table) {
            if (var.name==name) {
                return var.cons;
            }
        }
        return false;
    }
    double define_name (string name, double val,bool cons) {
        if (is_declared(name)) {
            if (!is_cons(name) ) {
                set_value(name, val);
            } else error ("it is const");
        } else if (cons) {
            var_table.push_back(Variable{name,val,true});
        } else var_table.push_back(Variable{name,val,false});
        return val;
    }
};
Symbol_table symbol_t;
double declaration (bool cons) {
    Token t=ts.get();
    if (t.kind!=NAME) error (" wrong declaration");
    string var_name=t.name;
    if (ts.get().kind!= '=')  error (" ");
    double var_val=expression();
    return symbol_t.define_name(var_name, var_val,cons);
    
}

double statement() {
    Token t=ts.get();
    if (t.kind==LET) {
        return declaration(false);
    }
    if (t.kind==CONST) {
        return declaration(true);
    }
    ts.putback(t);
    return expression();
}
double primary () {
    Token t=ts.get();
    switch (t.kind) {
        case PLUS:return primary();
        case MINUS:return -primary();
        case NUMBER:return t.val;
        case NAME: return symbol_t.get_value(t.name);
        case '(': {
            double res=expression();
            if (ts.get().kind==')')
                return res;
            error ("not good1");
        }
        default: {
            ts.putback(t);
            return 0;
        }
    }
}
double subterm_for_st (){
    double res=primary();
    for (;;) {
        Token t=ts.get();
        //cerr << "s: " << t.kind << endl;
        switch (t.kind) {
            case '^' : res=pow(res, primary()); break;
            default: ts.putback(t); return res;
        }
    }
}
double subterm (){
    double res=subterm_for_st();
    for (;;) {
        Token t=ts.get();
        //cerr << "s: " << t.kind << endl;
        switch (t.kind) {
            case '!' : res=fact(res); break;
            default: ts.putback(t); return res;
        }
    }
}
double term () {
    double result=subterm();
    for (;;) {
        Token t=ts.get();
        // cerr << "t: " << t.kind << endl;
        switch (t.kind) {
            case '*' : result*=subterm(); break;
            case '/' : result/=subterm(); break;
            case '%' : result=(int) result % (int) subterm(); break;
            default: ts.putback(t); return result;
        }
    }
}
double expression () {
    double result=term();
    for (;;) {
        Token t=ts.get();
        switch (t.kind) {
            case '+' : result+=term(); break;
            case '-' : result-=term(); break;
            default: ts.putback(t); return result;
        }
    }
}

void calculate () {
    while (cin)
        try {
            cout<<PROMPT;
            Token t=ts.get();
            while (t.kind==PRINT) {
                t=ts.get();
            }
            if (t.kind==QUIT) return;
            if (t.kind==HELP) {
                Help();
                continue;
            }
            if (t.kind==ERROR) {
                continue;
            }
            ts.putback(t);
            cout<<RESULT<<statement()<<endl;
        }
    catch (exception &e) {
        cerr<<e.what()<<'\n';
    }
}
int main ()
try
{
    calculate();
    return 0;
}
catch (runtime_error &e)
{
    cerr<<e.what()<<endl;
    }
    
    
    
    
    
