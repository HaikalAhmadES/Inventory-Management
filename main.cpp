#include <iostream>
#include <iomanip>

using namespace std;

string jenis[6] = {"makanan", "minuman", "alat tulis", "alat kebersihan", "barang rumah tangga", "lainnya"};

struct barang {
    int noreg;
    string merk;
    int harga;
    int jumlah;
    string jenis;
};

void drawline();
void menu();
void inputdata();
void outputdata();
bool memalloc();
void inputjumlah();
string pilihjenis(int no);

barang* databarang = nullptr;
int jmlbarang;

int main(int argc, const char * argv[]) {
    menu();
    if(databarang) {
        delete[] databarang;
    }
    return 0;
}

string pilihjenis(int no) {
    string jenis;
    switch(no) {
        case 1:
            jenis = "makanan";
            break;
        case 2:
            jenis = "minuman";
            break;
        case 3:
            jenis = "alat tulis";
            break;
        case 4:
            jenis = "alat kebersihan";
            break;
        case 5:
            jenis = "barang rumah tangga";
            break;
        case 6:
            jenis = "lainnya";
            break;
        default:
            jenis = "tidak terdefinisi";
            break;
    }
    return jenis;
}

bool memalloc() {
    databarang = new barang[jmlbarang];
    if(!databarang) {
        cout << "Alokasi memori tidak memenuhi" << endl;
        return false;
    } else {
        return true;
    }
}

void inputdata() {
    int pilihan;
    cout << "\t\tMASUKKAN BARANG-BARANG" << endl;
    for(int i = 0; i < jmlbarang; i++) {
        cout << "\t\tPilih jenis barang" << endl;
        for(int j = 0; j < 6; j++) {
            cout << "\t\t\t" << j + 1 << ". " << jenis[j] << endl;
        }
        cin >> pilihan;

        databarang[i].jenis = pilihjenis(pilihan);
        cout << "\t\tMasukkan no registrasi barang : ";
        cin >> databarang[i].noreg;
        cout << "\t\tMasukkan merk barang : ";
        cin.ignore();
        getline(cin, databarang[i].merk);
        cout << "\t\tMasukkan harga barang :";
        cin >> databarang[i].harga;
        cout << "\t\tMasukkan jumlah barang : ";
        cin >> databarang[i].jumlah;
    }
}

void outputdata() {
    cout << "\t\tBARANG-BARANG PADA GUDANG" << endl;
    drawline();
    cout << setw(10) << "No Reg" << setw(20) << "Merk" << setw(20) << "Jenis" << setw(10) << "Harga" << setw(10) << "Jumlah" << endl;
    drawline();
    for(int i = 0; i < jmlbarang; i++) {
        cout << setw(10) << databarang[i].noreg << setw(20) << databarang[i].merk << setw(20) << databarang[i].jenis << setw(10) << databarang[i].harga << setw(10) << databarang[i].jumlah << endl;
    }
}

void menu() {
    drawline();
    cout << "\t\t\tPROGRAM PENCATATAN INVENTARIS" << endl;
    drawline();
    cout << "\t\tMasukkan jumlah barang yang ingin dimasukkan ke dalam gudang : ";
    cin >> jmlbarang;
    if(!memalloc()) {
        cout << "Exiting....." << endl;
    } else {
        inputdata();
        outputdata();
    }
}

void drawline() {
    int i = 0;
    cout << "\t\t\t";
    while(i < 30) {
        cout << "=";
        i++;
    }
    cout << "\n";
}
