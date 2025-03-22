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

int main() {
    // Deklarasi variabel lokal dalam fungsi main
    Film daftarFilm[100] = {
        {"Up", "Comedy", 0},
        {"The Lion King", "Animasi", 0},
        {"Titanic", "Romance", 13},
        {"Avengers", "Aksi", 13},
        {"The Godfather", "Kriminal", 17}
    };

    User akun[10] = { { {"admin", "admin123"} } }; // Akun Admin default
    int filmC = 5;   // Jumlah film yang sudah diinisialisasi
    int userC = 1;   // Mulai dari 1 karena admin sudah ada
    bool Admin;      // Akan diatur saat login

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
            return 0;
        }

        if (role == 1) { // Register User Baru
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
            continue;
        }

        if (role == 2) { // Login dengan batasan 3 kali percobaan
            bool loginBerhasil = false;
            int kesempatan = 3;
            int loginIndex = -1;  // Indeks user yang berhasil login

            while (kesempatan > 0) {
                string username, password;
                cout << "Masukkan Nama: ";
                getline(cin, username);
                cout << "Masukkan Password: ";
                getline(cin, password);

                for (int i = 0; i < userC; i++) {
                    if (username == akun[i].profil.nama && password == akun[i].profil.nim) {
                        Admin = (i == 0);
                        loginBerhasil = true;
                        loginIndex = i;
                        break;
                    }
                }

                if (loginBerhasil) break;

                kesempatan--;
                cout << "User atau password salah! Sisa percobaan: " << kesempatan << endl;
            }

            if (!loginBerhasil) {
                cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
                return 0;
            }
    
            cout << "Login berhasil! Selamat datang, " << akun[loginIndex].profil.nama << "!" << endl;
        
            while (true) {
                int pilihan;
                cout << "+----------------------+" << endl;
                cout << "|       MENU           |" << endl;
                cout << "+----------------------+" << endl;
                if (Admin) {
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
                
                if (Admin) {
                    if (pilihan == 1) { // Tambah Film
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
                    } else if (pilihan == 2) { // Lihat Film
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
                    } else if (pilihan == 3) { // Ubah Film
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
                    } else if (pilihan == 4) { // Hapus Film
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
                    } else if (pilihan == 5) {
                        // Logout
                        break;
                    } else {
                        cout << "Pilihan tidak valid!" << endl;
                    }
                } else {
                    if (pilihan == 1) { // Lihat Film untuk user biasa
                        cout << "Daftar Film:" << endl;
                        for (int i = 0; i < filmC; ++i) {
                            cout << i + 1 << ". " << daftarFilm[i].judul
                                 << " (" << daftarFilm[i].genre
                                 << ", " << daftarFilm[i].usia << "+)" << endl;
                        }
                    } else if (pilihan == 2) {
                        // Logout
                        break;
                    } else {
                        cout << "Pilihan tidak valid!" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
