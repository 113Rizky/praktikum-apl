#include <iostream>
#include <iomanip>
using namespace std;

struct Film {
    string judul;
    string genre;
    int usia;
};

struct Profil {
    string nama;
    string nim;
};

struct User {
    Profil profil;
};

// Prosedur tambah film (Admin)
void tambahFilm(Film daftarFilm[], int& filmC) {
    if (filmC < 100) {
        cout << "Masukkan Judul Film: ";
        getline(cin, daftarFilm[filmC].judul);
        cout << "Masukkan Genre Film: ";
        getline(cin, daftarFilm[filmC].genre);
        cout << "Masukkan Usia Minimal: ";
        cin >> daftarFilm[filmC].usia;
        cin.ignore();
        filmC++;
        cout << "Film berhasil ditambahkan!" << endl;
    } else {
        cout << "Penyimpanan penuh!" << endl;
    }
}

// Prosedur lihat film
void lihatFilm(const Film daftarFilm[], int filmC) {
    cout << "Daftar Film:" << endl;
    cout << "+-------------------------------------+" << endl;
    cout << "| No | Judul          | Genre  | Usia |" << endl;
    cout << "+-------------------------------------+" << endl;
    for (int i = 0; i < filmC; ++i) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(14) << daftarFilm[i].judul << " | "
             << setw(6) << daftarFilm[i].genre << " | "
             << setw(4) << daftarFilm[i].usia << " |" << endl;
    }
    cout << "+-------------------------------------+" << endl;
}

// Prosedur ubah film
void ubahFilm(Film daftarFilm[], int filmC) {
    lihatFilm(daftarFilm, filmC);
    int index;
    cout << "Masukkan nomor film yang ingin diubah: ";
    cin >> index;
    cin.ignore();
    if (index > 0 && index <= filmC) {
        cout << "Masukkan judul baru: ";
        getline(cin, daftarFilm[index - 1].judul);
        cout << "Masukkan genre baru: ";
        getline(cin, daftarFilm[index - 1].genre);
        cout << "Masukkan usia minimal baru: ";
        cin >> daftarFilm[index - 1].usia;
        cin.ignore();
        cout << "Film berhasil diubah!" << endl;
    } else {
        cout << "Nomor film tidak valid!" << endl;
    }
}

// Prosedur hapus film
void hapusFilm(Film daftarFilm[], int& filmC) {
    lihatFilm(daftarFilm, filmC);
    int index;
    cout << "Masukkan nomor film yang ingin dihapus: ";
    cin >> index;
    cin.ignore();
    if (index > 0 && index <= filmC) {
        for (int i = index - 1; i < filmC - 1; ++i) {
            daftarFilm[i] = daftarFilm[i + 1];
        }
        filmC--;
        cout << "Film berhasil dihapus!" << endl;
    } else {
        cout << "Nomor film tidak valid!" << endl;
    }
}

// Fungsi untuk login
bool login(User akun[], int userC, bool& isAdmin, int& loginIndex) {
    int kesempatan = 3;
    while (kesempatan > 0) {
        string username, password;
        cout << "Masukkan Nama: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);

        for (int i = 0; i < userC; i++) {
            if (username == akun[i].profil.nama && password == akun[i].profil.nim) {
                isAdmin = (i == 0);
                loginIndex = i;
                return true;
            }
        }

        kesempatan--;
        cout << "User atau password salah! Sisa percobaan: " << kesempatan << endl;
    }

    return false;
}

// Prosedur untuk registrasi user baru
void registrasi(User akun[], int& userC) {
    if (userC < 10) {
        cout << "-------- Registrasi Akun Baru --------" << endl;
        cout << "Masukkan Username: ";
        getline(cin, akun[userC].profil.nama);
        cout << "Masukkan Password: ";
        getline(cin, akun[userC].profil.nim);
        userC++;
        cout << "Registrasi berhasil! Silahkan login untuk melanjutkan." << endl;
    } else {
        cout << "Maksimum user tercapai!" << endl;
    }
}

// Main program
int main() {
    Film daftarFilm[100] = {
        {"Up", "Comedy", 0},
        {"The Lion King", "Animasi", 0},
        {"Titanic", "Romance", 13},
        {"Avengers", "Aksi", 13},
        {"The Godfather", "Kriminal", 17}
    };
    User akun[10] = { { {"admin", "admin123"} } };
    int filmC = 5;
    int userC = 1;

    while (true) {
        int role;
        cout << "+----------------------+" << endl;
        cout << "|        APLIX         |" << endl;
        cout << "+----------------------+" << endl;
        cout << "| 1. Register Akun     |" << endl;
        cout << "| 2. Login             |" << endl;
        cout << "| 3. Keluar            |" << endl;
        cout << "+----------------------+" << endl;
        cout << "Pilih: ";
        cin >> role;
        cin.ignore();

        if (role == 3) {
            cout << "Terima Kasih Sudah Berkunjung Di APLIX." << endl;
            break;
        }

        if (role == 1) {
            registrasi(akun, userC);
        }

        if (role == 2) {
            bool isAdmin;
            int loginIndex;
            if (!login(akun, userC, isAdmin, loginIndex)) {
                cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
                break;
            }

            cout << "Login berhasil! Selamat datang, " << akun[loginIndex].profil.nama << "!" << endl;

            while (true) {
                int pilihan;
                cout << "+----------------------+" << endl;
                cout << "|       MENU           |" << endl;
                cout << "+----------------------+" << endl;
                if (isAdmin) {
                    cout << "| 1. Tambah Film       |" << endl;
                    cout << "| 2. Lihat Film        |" << endl;
                    cout << "| 3. Ubah Film         |" << endl;
                    cout << "| 4. Hapus Film        |" << endl;
                    cout << "| 5. Logout            |" << endl;
                } else {
                    cout << "| 1. Lihat Film        |" << endl;
                    cout << "| 2. Logout            |" << endl;
                }
                cout << "+----------------------+" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;
                cin.ignore();

                if (isAdmin) {
                    if (pilihan == 1) tambahFilm(daftarFilm, filmC);
                    else if (pilihan == 2) lihatFilm(daftarFilm, filmC);
                    else if (pilihan == 3) ubahFilm(daftarFilm, filmC);
                    else if (pilihan == 4) hapusFilm(daftarFilm, filmC);
                    else if (pilihan == 5) break;
                    else cout << "Pilihan tidak valid!" << endl;
                } else {
                    if (pilihan == 1) {
                        for (int i = 0; i < filmC; ++i) {
                            cout << i + 1 << ". " << daftarFilm[i].judul
                                 << " (" << daftarFilm[i].genre
                                 << ", " << daftarFilm[i].usia << "+)" << endl;
                        }
                    } else if (pilihan == 2) break;
                    else cout << "Pilihan tidak valid!" << endl;
                }
            }
        }
    }

    return 0;
} 
