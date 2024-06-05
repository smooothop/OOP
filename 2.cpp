#include <iostream>
using namespace std;
class BasePrinter
{
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;

public:
    BasePrinter(string model, string manufacturer, int totalPapers);

protected:
    bool print(int pages = 1);
    string getModel() { return model; }
    string getManufacturer() { return manufacturer; }
    int getPrintedCount() { return printedCount; }
    int getAvailableCount() { return availableCount; }
    void show();
};
class InkJetPrinter : public BasePrinter
{
    int availableInk;

public:
    InkJetPrinter(string model, string manufacturer, int totalPapers, int totalInk);
    bool printInkJet(int pages = 1);
    void showState();
};
class LaserPrinter : public BasePrinter
{
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int totalPapers, int totalToner);
    bool printLaser(int pages = 1);
    void showState();
};
class PrinterManager
{
    InkJetPrinter *ip;
    LaserPrinter *lp;

public:
    PrinterManager();
    ~PrinterManager();
    void operate();
};
BasePrinter::BasePrinter(string model, string manufacturer, int totalPapers)
{
    this->model = model;
    this->manufacturer = manufacturer;
    this->printedCount = 0;
    this->availableCount = totalPapers;
}
bool BasePrinter::print(int pages)
{
    if (availableCount < pages)
    {
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        return false;
    }
    printedCount += pages;
    availableCount -= pages;
    return true;
}
void BasePrinter::show()
{
    cout << model + " ," << manufacturer << " ,남은 종이 " << availableCount << "장"
         << " ,";
}
InkJetPrinter::InkJetPrinter(string model, string manufacturer, int totalPapers, int totalInk)
    : BasePrinter(model, manufacturer, totalPapers)
{
    this->availableInk = totalInk;
}
bool InkJetPrinter::printInkJet(int pages)
{
    if (!print(pages)) // BasePrinter::print() 호출
        return false;  // 용지 부족
    if (availableInk < pages)
    {
        cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
        return false;
    }
    availableInk -= pages;
    cout << "프린트하였습니다. " << endl;
    return true;
}
void InkJetPrinter::showState()
{
    show(); // BasePrinter::show() 호출
    cout << "남은 잉크 " << availableInk;
}
LaserPrinter::LaserPrinter(string model, string manufacturer, int totalPapers, int totalToner)
    : BasePrinter(model, manufacturer, totalPapers)
{
    this->availableToner = totalToner;
}
bool LaserPrinter::printLaser(int pages)
{
    if (!print(pages)) // BasePrinter::print() 호출
        return false;  // 용지 부족
    if (availableToner < pages)
    {
        cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
        return false;
    }
    availableToner--;
    cout << "프린트하였습니다. " << endl;
    return true;
}
void LaserPrinter::showState()
{
    show(); // BasePrinter::show() 호출
    cout << "남은토너 " << availableToner;
}
PrinterManager::PrinterManager()
{
    ip = new InkJetPrinter("Officejet V40", "HP", 5, 10);
    lp = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
}
PrinterManager::~PrinterManager()
{
    delete ip;
    delete lp;
}
void PrinterManager::operate()
{
    cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
    cout << "잉크젯 : ";
    ip->showState();
    cout << endl;
    cout << "레이저 : ";
    lp->showState();
    cout << endl;
    int printer, pages;
    char conti;
    while (true)
    {
        cout << endl
             << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> printer >> pages;
        switch (printer)
        {
        case 1: // 잉크젯
            ip->printInkJet(pages);
            break;
        case 2: // 레이저
            lp->printLaser(pages);
            break;
        default:
            cout << "잘못된 입력입니다." << endl;
            continue;
        }
        ip->showState();
        cout << endl;
        lp->showState();
        cout << endl;
        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> conti;
        if (conti == 'y')
            continue;
        else
            break;
    }
}
int main()
{
    PrinterManager man;
    man.operate();
}