#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

void mnk (double* x, double* y, int n) {
    double xym=0;
    double xm=0;
    double ym=0;
    double ypm=0; //среднее квадратов
    double ymp=0; //квадрат среднего
    double xpm=0; //среднее квадратов
    double xmp=0; //квадрат среднего
    for (int i(0); i<n; ++i) {
        xym+=x[i]*y[i];
        xm+=x[i];
        ym+=y[i];
        xpm+=x[i]*x[i];
        ypm+=y[i]*y[i];
    }
    xym/=n;
    xm/=n;
    ym/=n;
    xpm/=n;
    xmp=xm*xm;
    ypm/=n;
    ymp=ym*ym;
    double k=(xym-xm*ym)/ (xpm-xmp);
    double b=ym-k*xm;
    double tao = (k*3.14*pow(0.001,4))/(8*0.2);
    double Gk = (1/sqrt(n))*sqrt(( (ypm-ymp) / (xpm-xmp) ) - b*b);
    double Gb = Gk * sqrt(xpm-xmp);
    double Gtao = tao*sqrt (pow(Gk/k,2)+pow(0.001,2)+pow(0.0005/0.4,2));
    cout << endl;
    cout << "<xy>*10^-5 " << xym*100000 << endl;
    cout << "<x>*10^-5 " << xm*100000 << endl;
    cout << "<y> " << ym << endl;
    cout << "<x^2>*10^-10 " << xpm*10000000000 << endl;
    cout << "<x>^2*10^-10 " << xmp*10000000000 << endl;
    cout << "<y^2>" << ypm << endl;
    cout << "<y>^2 " << ymp << endl;
    cout << "k =" <<k << " b=" << b << endl;
    cout << "Gk " << Gk << endl;
    cout << "Gb " << Gb << endl;
    cout << "tao " << tao << endl;
    cout << "Gtao " << Gtao << endl;




}

int main () {
    //double dh[7] = {6.1, 5.5, 4.3, 3.6, 1.2, 1.1, 0.3};
    //double t[7] = {10.37, 11.36, 14.29, 17.10, 45.53, 50.84, 223.98};
    double dh[7] = {4.9, 4.4, 3.5, 2.8, 1.9, 0.8, 0.3};
    double t[7] = {9.27, 9.81, 10.48, 10.65, 15.67, 25.53, 58.22};
    double Re [7];
    double dv=0.001;
    double tao;
    double dp [7];
    double q[7];
    double d=0.0015;
    for (int i(0);i<7;++i) {
        dp[i]=820*9.87*dh[i]/1000;
        q[i]=dv/t[i];
        Re[i]=(q[i]*1.204*100000)/(d*3.14*1.8);
    }
    cout << "q: ";
    for (int i(0);i<7;++i) {
        cout << q[i]*100000 << " ";
    }
    cout << endl <<  "dp: " ;
    for (int i(0);i<7;++i) {
        cout << dp[i] << " ";
    }
    cout << endl <<  "Re: " ;
    for (int i(0);i<7;++i) {
        cout << Re[i] << " ";
    }
    mnk(q,dp,7);
    //cout << xym << " " << xm << " " << ym << " " << xp << " " << xmp << endl;
    /*cout << "p: ";
    for (int i(0);i<7;++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << "q: ";
    for (int i(0);i<7;++i) {
        cout << q[i] * 100000 << " ";
    }
    cout << endl;
    cout << "Re: ";
    for (int i(0);i<7;++i) {
        cout << Re[i] << " ";
    }
    double c = (8*0.2*1.204)/3.14;
    cout << c;*/
}


