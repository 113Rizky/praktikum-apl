#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // *Deklarasi Data Film*
    string judul[100] = {"Inception", "Titanic", "Avengers", "The Matrix", "Interstellar"};
    string genre[100] = {"Sci-Fi", "Romance", "Action", "Sci-Fi", "Sci-Fi"};
    int usia[100] = {13, 12, 13, 15, 13};
    int filmC = 5; // Jumlah film saat ini
    bool Admin;

    // *Deklarasi Data Login dalam Array Multidimensi*
    string akun[2][2] = {
        {"admin", "admin123"},
        {"Muhammad Rizky Adha Putra", "2409106113"}
    };

    while (true) {
        int role;
        cout << "\n+----------------------+" << endl;
        cout << "|        APLIX         |" << endl;
        cout << "+----------------------+" << endl;
        cout << "| 1. Admin            |" << endl;
        cout << "| 2. User             |" << endl;
        cout << "| 3. Keluar           |" << endl;
        cout << "+----------------------+" << endl;
        cout << "Pilih: ";
        cin >> role;
        cin.ignore();

        if (role == 3) {
            cout << "Terima Kasih Sudah Berkunjung Di APLIX.\n";
            return 0;
        }

        // *Login dengan batasan 3 kali percobaan*
        bool loginSuccess = false;
        int attempts = 3;

        while (attempts > 0) {
            string username, password;
            cout << "\nMasukkan Username: ";
            getline(cin, username);
            cout << "Masukkan Password: ";
            getline(cin, password);

            // *Validasi Login*
            if (role == 1 && username == akun[0][0] && password == akun[0][1]) {
                Admin = true;
                loginSuccess = true;
                break;
            } else if (role == 2 && username == akun[1][0] && password == akun[1][1]) {
                Admin = false;
                loginSuccess = true;
                break;
            }

            attempts--;
            cout << "User atau password salah! Sisa percobaan: " << attempts << endl;
        }

        if (!loginSuccess) {
            cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
            return 0;
        }

        cout << "\nLogin berhasil! Selamat datang " << (Admin ? "Admin" : "User") << "!\n";

        // *MENU ADMIN & USER*
        while (true) {
            int pilihan;
            cout << "\n+----------------------+" << endl;
            cout << "|       MENU          |" << endl;
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
                if (pilihan == 1) {  // *Tambah Film*
                    if (filmC < 100) {
                        cout << "Masukkan Judul Film: ";
                        getline(cin, judul[filmC]);
                        cout << "Masukkan Genre Film: ";
                        getline(cin, genre[filmC]);
                        cout << "Masukkan Usia Minimal: ";
                        cin >> usia[filmC];
                        cin.ignore();
                        filmC++;
                        cout << "Film berhasil ditambahkan!\n";
                    } else {
                        cout << "Penyimpanan penuh!\n";
                    }
                } else if (pilihan == 2) {  // *Lihat Film*
                    if (filmC == 0) {
                        cout << "Belum ada film yang tersedia.\n";
                    } else {
                        cout << "\n+-----------------------------------------------------+" << endl;
                        cout << "| No |          Judul          |   Genre   |  Usia  |" << endl;
                        cout << "+-----------------------------------------------------+" << endl;
                        for (int i = 0; i < filmC; ++i) {
                            cout << "| " << setw(2) << i + 1 << " | " << setw(20) << left << judul[i] << " | " << setw(10) << genre[i] << " | " << setw(5) << usia[i] << " |" << endl;
                        }
                        cout << "+-----------------------------------------------------+\n";
                    }
                } else if (pilihan == 3) {  // *Ubah Film*
                    if (filmC == 0) {
                        cout << "Belum ada film yang tersedia.\n";
                    } else {
                        cout << "\n+-----------------------------------------------------+" << endl;
                        cout << "| No |          Judul          |   Genre   |  Usia  |" << endl;
                        cout << "+-----------------------------------------------------+" << endl;
                        for (int i = 0; i < filmC; ++i) {
                            cout << "| " << setw(2) << i + 1 << " | " << setw(20) << left << judul[i] << " | " << setw(10) << genre[i] << " | " << setw(5) << usia[i] << " |" << endl;
                        }
                        cout << "+-----------------------------------------------------+\n";
                        cout << "Masukkan nomor film yang ingin diubah: ";
                        int nomorfilm;
                        cin >> nomorfilm;
                        cin.ignore();

                        if (nomorfilm > 0 && nomorfilm <= filmC) {
                            cout << "Masukkan judul baru: ";
                            getline(cin, judul[nomorfilm - 1]);
                            cout << "Masukkan genre baru: ";
                            getline(cin, genre[nomorfilm - 1]);
                            cout << "Masukkan usia minimal baru: ";
                            cin >> usia[nomorfilm - 1];
                            cin.ignore();
                            cout << "Film berhasil diubah!\n";
                        } else {
                            cout << "Nomor film tidak valid!\n";
                        }
                    }
                } else if (pilihan == 4) {  // *Hapus Film*
                    if (filmC == 0) {
                        cout << "Belum ada film yang tersedia.\n";
                    } else {
                        cout << "\n+-----------------------------------------------------+" << endl;
                        cout << "| No |          Judul          |   Genre   |  Usia  |" << endl;
                        cout << "+-----------------------------------------------------+" << endl;
                        for (int i = 0; i < filmC; ++i) {
                            cout << "| " << setw(2) << i + 1 << " | " << setw(20) << left << judul[i] << " | " << setw(10) << genre[i] << " | " << setw(5) << usia[i] << " |" << endl;
                        }
                        cout << "+-----------------------------------------------------+\n";
                        cout << "Masukkan nomor film yang ingin dihapus: ";
                        int nomorfilm;
                        cin >> nomorfilm;
                        cin.ignore();

                        if (nomorfilm > 0 && nomorfilm <= filmC) {
                            for (int i = nomorfilm - 1; i < filmC - 1; ++i) {
                                judul[i] = judul[i + 1];
                                genre[i] = genre[i + 1];
                                usia[i] = usia[i + 1];
                            }
                            filmC--;
                            cout << "Film berhasil dihapus!\n";
                        } else {
                            cout << "Nomor film tidak valid!\n";
                        }
                    }
                } else if (pilihan == 5) {  // *Logout*
                    cout << "Logout berhasil!\n";
                    break;
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            } else {  // *User Menu*
                if (pilihan == 1) {  // *Lihat Film*
                    cout << "Daftar Film:\n";
                    for (int i = 0; i < filmC; ++i) {
                        cout << i + 1 << ". " << judul[i] << " (" << genre[i] << ", " << usia[i] << "+)\n";
                    }
                } else if (pilihan == 2) {  // *Logout*
                    cout << "Logout berhasil!\n";
                    break;
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
        }
    }
}