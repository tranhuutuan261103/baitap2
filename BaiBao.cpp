#include <bits/stdc++.h>
#include "BaiBao.h"

using namespace std;

bool BaiBao::checkMaCT(string maCT) const
{
	if(maCT.size()!=5)
	return false;
	for (int i=0;i<5;i++)
	{
		if(!(maCT[i]>='0' && maCT[i]<='9') ) return false;
	}
	return true;
}

BaiBao::BaiBao(const BaiBao &x)
{
    this->setMaCT(x.getMaCT());
    this->setNXB(x.getNXB());
    this->setKhuVuc(x.getKhuVuc());
    this->TenCT=x.TenCT;
    this->SoTacGia=x.SoTacGia;
}

BaiBao BaiBao::operator=(const BaiBao &x)
{
	if (this != &x)
	{
	    this->setMaCT(x.getMaCT());
	    this->setNXB(x.getNXB());
	    this->setKhuVuc(x.getKhuVuc());
	    this->TenCT=x.TenCT;
	    this->SoTacGia=x.SoTacGia;
	}
	return *this;
}

istream &operator>>(istream &in,BaiBao &B)
{
    string maCT;
    int nxb;
    int choose;
    bool khuvuc;
    cout << "Nhap ma cong trinh(ma gom 5 so):" << endl;
	do {
        cout << "->Ma cong trinh:";
        getline(in,maCT);
	} while (!B.checkMaCT(maCT));
    B.setMaCT(maCT);
    cout << "Nhap nam xuat ban(>1900):" << endl;
	do {
	    cout << "->Nam xuat ban:";
		in >> nxb;
	} while (nxb<1900);
	B.setNXB(nxb);
    cout << "Khu vuc xuat ban (1.Quoc te/0.Trong nuoc):" ;
	in >> choose;
	if (choose==1) khuvuc=true;
	else khuvuc=false;
	B.setKhuVuc(khuvuc);
	cout << "Nhap ten cong trinh:";
	cin.ignore();
	getline(in,B.TenCT);
	cout << "Nhap so tac gia:";
	in >> B.SoTacGia;
    return in;
}

void BaiBao::printfIntro() const
{
    cout << left << setw(10) << "Ma CT" ;
    cout << left << setw(10) << "Nam XB" ;
    cout << left << setw(15) << "Khu vuc";
    cout << left << setw(50) << "Ten Cong Trinh" ;
    cout << left << setw(10) << "So tac gia" << endl;
}

void BaiBao::printfNode() const
{
    cout << left << setw(10) << this->getMaCT();
    cout << left << setw(10) << this->getNXB();
    if (this->getKhuVuc()==true) cout << left << setw(15) << "Quoc te";
    else cout << left << setw(15) << "Trong nuoc";
    cout << left << setw(50) << this->TenCT;
    cout << left << setw(10) << this->SoTacGia << endl;
}

