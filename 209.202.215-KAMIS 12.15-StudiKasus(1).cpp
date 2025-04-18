#include<iostream>
using namespace std;
class kedaiAyam{
friend ostream& operator<<(ostream&,const kedaiAyam&);
friend istream& operator>>(istream&, kedaiAyam&);
private:
	string namaPelanggan;
	int HargaAyamGoreng=17000;
	int HargaAyamBakar=21000;
	int jumlahAyamGoreng,jumlahAyamBakar,total;
public:
	kedaiAyam():
	jumlahAyamGoreng(0),jumlahAyamBakar(0),total(0){
	}
	friend istream&operator>>(istream&in,kedaiAyam&k){
		cout<<"Masukan nama pelanggan: ";
		getline(in, k.namaPelanggan);
		int pilihan,jumlah;
	do{
		cout<<"\n======PILIHAN MENU=======\n";
		cout<<"1.Ayam goreng Rp17.000"<<endl;
		cout<<"2.Ayam Bakar Rp21.000"<<endl;
		cout<<"3.Keluar"<<endl;
		cout<<"Pilih menu: ";
		in>>pilihan;
		switch (pilihan) {
                case 1:
                    cout<<"Jumlah ayam goreng: ";
                    in>>jumlah;
                    k.jumlahAyamGoreng +=jumlah;
                    break;
                case 2:
                    cout<<"Jumlah ayam bakar: ";
                    in>>jumlah;
                    k.jumlahAyamBakar +=jumlah;
                    break;
                case 3:
                    break;
                default:
                    cout<<"Pilihan tidak valid!\n";
            }
	}while(pilihan!=3);
	return in;
	}
	void hitung_total(){
		total=(jumlahAyamGoreng*HargaAyamGoreng)+(jumlahAyamBakar*HargaAyamBakar);
		if(total>45000){
			total*=0.9;
		}
	}
	friend ostream&operator<<(ostream&out,const kedaiAyam&k){
		out<<"\n=========STRUCK PEMBAYARAN==========\n";
		out<<"Nama Pelanggan: "<<k.namaPelanggan<<endl;
		out<<"Ayam Goreng: "<<k.jumlahAyamGoreng<<" x Rp17.000"<<endl;
		out<<"Ayam Bakar : "<<k.jumlahAyamBakar<<" x Rp21.000"<<endl;
		out<<"Total Harga: Rp"<<k.total<<endl;
	}
	
};	
int main(){
	kedaiAyam pesanan;
	cin>>pesanan;
	pesanan.hitung_total();
	cout<<pesanan;
	return 0;
	
}