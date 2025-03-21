#include <iostream>
using namespace std;

class KTP{
	private:
		string nik,prov,kab,nama,tgl,jenis,alamat,kel,kec,agama,status,pekerjaan,kewarganegaraan;
		char gol;
		int rt,rw;
	public:
		void tulisKTP(){
			cout<<"Masukan NIK anda \t\t : ";
			cin>>nik;
			cin.ignore();
			cout<<"Masukan Provinsi Anda \t\t : ";
			getline(cin,prov);
			cout<<"Masukan Kabupaten/Kecamatan Anda : ";
			getline(cin,kab);
			cout<<"Masukan Nama Anda \t\t : ";
			getline(cin,nama);	
			cout<<"Masukan Tempat/Tgl Lahir Anda \t : ";
			getline(cin,tgl);
			cout<<"Masukan Jenis Kelamin Anda \t : ";
			getline(cin,jenis);
			cout<<"Masukan Golongan Darah Anda \t : ";
			cin>>gol;
			cin.ignore();
			cout<<"Masukan Alamat Anda \t\t : ";
			getline(cin,alamat);
			cout<<"Masukan RT Anda \t\t : ";
			cin>>rt;
			cout<<"Masukan RW Anda \t\t : ";
			cin>>rw;
			cout<<"Masukan Kelurahan/Desa Anda \t : ";
			cin>>kel;
			cout<<"Masukan Kecamatan Anda \t\t : ";
			cin>>kec;
			cout<<"Masukan Agama Anda \t\t : ";
			cin>>agama;
			cin.ignore();
			cout<<"Masukan Status Perkawinan Anda\t : ";
			getline(cin,status);
			cout<<"Masukan Pekerjaan Anda \t\t : ";
			cin>>pekerjaan;
			cout<<"Masukan Kewarganegaraan Anda\t : ";
			cin>>kewarganegaraan;
			cout<<endl;
			cout<<endl;
		}
		void tampilkanHasil(){
			cout<<"+=======================================================+\n";
			cout<<"\t\t  PROVINSI "<<prov<<" \t\t\t"<<endl;
			cout<<"\t\t  KABUPATEN "<<kab<<" \t\t\t"<<endl;
			cout<<"+=======================================================+\n";
			cout<<"NIK\t\t\t: "<<nik<<endl;
			cout<<"Nama\t\t\t: "<<nama<<endl;
			cout<<"Tempat/Tgl Lahir\t: "<<tgl<<endl;
			cout<<"Jenis Kelamin\t\t: "<<jenis<<"\t Gol. Darah: "<<gol<<endl;
			cout<<"Alamat\t\t\t: "<<alamat<<endl;
			cout<<"\t RT/RW \t\t: "<<rt<<"/"<<rw<<endl;
			cout<<"\t Kel/Desa \t: "<<kel<<endl;
			cout<<"\t Kecamatan \t: "<<kec<<endl;
			cout<<"Agama\t\t\t: "<<agama<<endl;
			cout<<"Status Perkawinan\t: "<<status<<endl;
			cout<<"Pekerjaan\t\t: "<<pekerjaan<<endl;
			cout<<"Kewarganegaraan\t\t: "<<kewarganegaraan<<endl;
			cout<<"Berlaku Hingga\t\t: SEUMUR HIDUP"<<endl;
			cout<<"+=======================================================+\n";
			
		}
	};
int main(){
	KTP data;
	data.tulisKTP();
	data.tampilkanHasil();
	return 0;
}
		