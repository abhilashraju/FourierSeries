#include "fourierwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FourierWidget w;
    w.resize(1300,800);
    //random frequencies
//    FTerm t1{50,1.};
//    std::vector<FTerm> terms;
//    terms.push_back(t1);
//    terms.emplace_back(std::polar(2.,PI/2.) * t1);
//    terms.emplace_back((1.+2.i)*t1);
//    terms.emplace_back(FTerm{50,3});
//    w.addFourierTerm(terms);

    //square wave.
    std::vector<FTerm> terms;
    FReal radius=50.;
    for(int i =0;i<10;i++){
        FReal n=2.*i+1.;

        terms.emplace_back(FTerm{radius*4/(n*PI),  n});
    }
    w.addFourierTerm(terms);
    w.setDrawMode(FourierWidget::DrawY);
    w.show();

    return a.exec();
}