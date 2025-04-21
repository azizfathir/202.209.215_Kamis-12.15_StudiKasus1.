#include <iostream>
using namespace std;

class KTP{
	friend istream& operator>>(istream& in, KTP& ktp);
	friend ostream& operator<<(ostream& out, const KTP& ktp);
	private:
		string prov,kab,nama,tgl,jenis,alamat,kel,kec,agama,status,pekerjaan,kewarganegaraan;
		char gol;
		int rt,rw;
		long long int nik;
	public:
		istream& operator(istream& operator, KTP& ktp){
			cout<<"Masukan NIK anda \t\t : ";
			in>>ktp.nik;
			in.ignore();
			cin.ignore();
			cout<<"Masukan Provinsi Anda \t\t : ";
			getline(in,ktp.prov);
			cout<<"Masukan Kabupaten/Kecamatan Anda : ";
			getline(in,ktp.kab);
			cout<<"Masukan Nama Anda \t\t : ";
			getline(in,ktp.nama);	
			cout<<"Masukan Tempat/Tgl Lahir Anda \t : ";
			getline(in,ktp.tgl);
			cout<<"Masukan Jenis Kelamin Anda \t : ";
			getline(in,ktp.jenis);
			cout<<"Masukan Golongan Darah Anda \t : ";
			in>>gol;
			in.ignore();
			cout<<"Masukan Alamat Anda \t\t : ";
			getline(in,ktp.alamat);
			cout<<"Masukan RT Anda \t\t : ";
			in>>ktp.rt;
			in.ignore();
			cout<<"Masukan RW Anda \t\t : ";
			in>>ktp.rw;
			in.ignore();
			cout<<"Masukan Kelurahan/Desa Anda \t : ";
			getline(in,ktp.kel);
			cout<<"Masukan Kecamatan Anda \t\t : ";
			getline(in,ktp.kec);
			cout<<"Masukan Agama Anda \t\t : ";
			getline(in,ktp.agama);
			cout<<"Masukan Status Perkawinan Anda\t : ";
			getline(in,ktp.status);
			cout<<"Masukan Pekerjaan Anda \t\t : ";
			getline(in,ktp.pekerjaan);
			cout<<"Masukan Kewarganegaraan Anda\t : ";
			getline(in,ktp.kewarganegaraan);
			cout<<endl;
			cout<<endl;

			return in;
		}
		ostream& operator<<(ostream& out, const KTP& ktp) {
	out << "+=======================================================+\n";
	out << "\t\t  PROVINSI " << ktp.prov << " \t\t\t" << endl;
	out << "\t\t  KABUPATEN " << ktp.kab << " \t\t\t" << endl;
	out << "+=======================================================+\n";
	out << "NIK\t\t\t: " << ktp.nik << endl;
	out << "Nama\t\t\t: " << ktp.nama << endl;
	out << "Tempat/Tgl Lahir\t: " << ktp.tgl << endl;
	out << "Jenis Kelamin\t\t: " << ktp.jenis << "\t Gol. Darah: " << ktp.gol << endl;
	out << "Alamat\t\t\t: " << ktp.alamat << endl;
	out << "\t RT/RW \t\t: " << ktp.rt << "/" << ktp.rw << endl;
	out << "\t Kel/Desa \t: " << ktp.kel << endl;
	out << "\t Kecamatan \t: " << ktp.kec << endl;
	out << "Agama\t\t\t: " << ktp.agama << endl;
	out << "Status Perkawinan\t: " << ktp.status << endl;
	out << "Pekerjaan\t\t: " << ktp.pekerjaan << endl;
	out << "Kewarganegaraan\t\t: " << ktp.kewarganegaraan << endl;
	out << "Berlaku Hingga\t\t: SEUMUR HIDUP" << endl;
	out << "+=======================================================+\n";

	return out;
		}
};
int main(){
	KTP data;
	cin >> data;
	cout << data;
	return 0;
}
		
