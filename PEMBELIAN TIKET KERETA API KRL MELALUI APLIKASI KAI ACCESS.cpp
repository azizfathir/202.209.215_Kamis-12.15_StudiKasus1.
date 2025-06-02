#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int Max_Akun=10;
const int Max_Jadwal=2;
const int Max_Jam=5;
const int Jumlah_Stasiun=13;

class Akun{
	public:
		string email;
		string password;
		
	Akun(){}
	Akun (string e,string p){
		email=e;
		password=p;
	}
};

class Jadwal {
	public:
		string asal;
		string tujuan;
		string jam[Max_Jam];
		int jumlahJam;
		
		Jadwal(){}
		Jadwal(string a,string t,string j[],int jml){
			asal=a;
			tujuan=t;
			jumlahJam=jml;
			for(int i=0;i<jumlahJam;i++){
				jam[i]=j[i];
			}
		}
};

class Stasiun{
	public:
		string nama;
		string waktu;
		
		void setStasiun(string n, string w){
			nama=n;
			waktu=w;
		}
		
		void tampilkan(int i){
			cout<<i+1<<". "<<waktu<<" - "<<nama<<endl;
			
		}
};

class Tiket{
	public:
		string nama;
		string asal;
		string tujuan;
		int jumlah;
		int hargaPerTiket;
		int total;
		
		Tiket(){}
		
		Tiket(string n,string a,string t,int jml,int harga){
			nama=n;
			asal=a;
			tujuan=t;
			jumlah=jml;
			hargaPerTiket=harga;
			total=jumlah * hargaPerTiket;
			
		}
		void cetakFile(){
			ofstream file("Tiket.txt", ios::app);
			if(file.is_open()){
			file<<"=====TIKET KERETA====-\n";
			file << "Nama Pelanggan  : " << nama << endl;
            file << "Dari Stasiun    : " << asal << endl;
            file << "Tujuan Stasiun  : " << tujuan << endl;
            file << "Jumlah Tiket    : " << jumlah << endl;
            file << "Harga per Tiket : Rp" << hargaPerTiket << endl;
            file << "Total Bayar     : Rp" << total << endl;
            file << "=====================\n\n";
            file.close();
            
            cout<<"Tiket berhasil dicetak ke file 'Tiket.txt'";
            
			}else{
				cout<<"Gagal mencetak tiket./n";
			}
		}
};

class KaiApp{
	private:
		Akun akun[Max_Akun];
		int jumlahAkun=1;
		
		string semuaStasiun[Jumlah_Stasiun]={
		"Palur", "Solo Jebres", "Solo Balapan", "Purwosari", "Gawok",
        "Delanggu", "Ceper", "Klaten", "Srowot", "Brambanan",
        "Maguwo", "Lempuyangan", "Yogyakarta"
        
		};
		
		Jadwal jadwalKereta[Max_Jadwal];
		int jumlahJadwal=0;
		
		Stasiun rute[Jumlah_Stasiun];
		
		void inisialisasiData(){
			akun[0]=Akun ("2400018209@webmail.uad.ac.id", "2400018209");
			
			string jam1[]= {"05:00", "06:05", "07:15", "08:20", "09:30" };
			string jam2[]= {"06:00", "07:10", "08:25", "09:40", "11:00"};
			
			jadwalKereta[0] = Jadwal("Palur", "Yogyakarta", jam1, 5);
  			jadwalKereta[1] = Jadwal("Yogyakarta", "Palur", jam2, 5);
   			jumlahJadwal = 2;
   			
   		 for (int i = 0; i <Jumlah_Stasiun; i++) {
        rute[i].setStasiun(semuaStasiun[i], "");
    }
			
		}
		
		void tampilkanMenu(){
		int pilih;
		
		do{
			cout<<"\n=== MENU KAI ===\n";
            cout<<"1. Tampilkan Semua Stasiun\n";
            cout<<"2. Cek Jadwal Kereta\n";
            cout<<"3. Pembelian Tiket\n";
            cout<<"4. Logout\n";
			cout<<"Pilih: ";
            cin>>pilih;
            cin.ignore();
			
			 switch (pilih) {
                case 1: tampilStasiun(); break;
                case 2: tampilJadwal(); break;
                case 3: beliTiket(); break;
                case 4: cout << "Logout berhasil.\n"; break;
                default: cout << "Pilihan tidak valid.\n";
            }
		}while(pilih !=4);	
			
		}
		
	void tampilStasiun() {
    cout << "\n=== DAFTAR STASIUN KRL ===\n";
    for (int i = 0; i < Jumlah_Stasiun; i++) {
        cout << i + 1 << ". " << rute[i].nama << endl;
    }
}

    
    void tampilJadwal(){
    	cout << "\n=== JADWAL KRL PALUR = YOGYAKARTA ===\n";
    	   for (int i= 0; i<jumlahJadwal;i++) {
            cout<< "- " <<jadwalKereta[i].asal<< " ke " <<jadwalKereta[i].tujuan<< ": ";
            for (int j= 0; j<jadwalKereta[i].jumlahJam;j++) {
                cout<<jadwalKereta[i].jam[j];
                if (j <jadwalKereta[i].jumlahJam -1) cout<<", ";
            }
            cout << endl;
        }
	}
	    void beliTiket() {
        string nama, asal, tujuan;
        int jumlahTiket;
        const int hargaTiket = 8000;

        cout<<"\n=== PEMBELIAN TIKET KERETA ===\n";
        cout<<"Masukkan Nama Anda       : ";
        getline(cin, nama);
        cout<<"Masukkan Stasiun Asal    : ";
        getline(cin, asal);
        cout<<"Masukkan Stasiun Tujuan  : ";
        getline(cin, tujuan);
        cout<<"Jumlah Tiket yang dibeli : ";
        cin>>jumlahTiket;
        cin.ignore();

        Tiket tiket(nama, asal, tujuan, jumlahTiket, hargaTiket);
        cout<<"\nSilakan bayar sebesar Rp"<<tiket.total<< "...\n";
        cout<<"Pembayaran berhasil!\n";

        tiket.cetakFile();
    }
    
    public:
    	KaiApp(){
    		
    		inisialisasiData();
    		
		}
		
		
		void signUp() {
        if (jumlahAkun >= Max_Akun) {
            cout<<"Maksimum akun tercapai.\n";
            return;
        }
		
		string email, password;
        cout<<"\n=== SIGN UP ===\n";
        cout<<"Email    : "; cin >> email;
        cout<< "Password : "; cin >> password;
	
	
		for (int i = 0; i < jumlahAkun; i++) {
            if (akun[i].email == email) {
                cout<<"Email sudah digunakan.\n";
                return;
            }
        }
		
		 akun[jumlahAkun++] = Akun(email, password);
        cout<<"Akun berhasil didaftarkan!\n";
    }
	
	 void login() {
        string email, password;
        cout<<"\n=== LOGIN ===\n";
        cout<<"Email    : "; cin>>email;
        cout<<"Password : "; cin>>password;

        for (int i = 0; i<jumlahAkun; i++) {
            if (akun[i].email == email && akun[i].password == password) {
                cout << "Login berhasil. Selamat datang!\n";
                tampilkanMenu();
                return;
            }
        }

        cout << "Login gagal.\n";
    }
};


int main() {
    KaiApp app;
    int pilih;

    do {
        cout<<"\n=== APLIKASI KAI ===\n";
        cout<<"1. Sign Up\n";
		cout<<"2. Login\n";
		cout<<"3. Keluar\n";
		cout<<"Pilih: ";
        cin>>pilih;

        switch (pilih) {
            case 1: app.signUp(); break;
            case 2: app.login(); break;
            case 3: cout << "Sampai jumpa!\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 3);
    return 0;
}
