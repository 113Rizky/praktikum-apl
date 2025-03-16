#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // **Deklarasi Array**
    string judul[100] = {"Inception", "Titanic", "Avengers", "The Matrix", "Interstellar"};
    string genre[100] = {"Sci-Fi", "Romance", "Action", "Sci-Fi", "Sci-Fi"};
    int usia[100] = {13, 12, 13, 15, 13};
    int filmC = 5; 
    bool Admin;

    while (true) { 
        int role;
        cout << "\n+----------------------+" << endl;
        cout << "|        APLIX        |" << endl;
        cout << "+----------------------+" << endl;
        cout << "| 1. Admin            |" << endl;
        cout << "| 2. User             |" << endl;
        cout << "| 3. Keluar           |" << endl;
        cout << "+----------------------+" << endl;
        cout << "Pilih: ";
        cin >> role;
        cin.ignore();

        
        if (role == 3) {  // Jika user memilih keluar
            cout << "Terima Kasih Sudah Berkunjung Di APLIX." << endl;
            return 0;
        }
        
        // **Login dengan batasan 3 kali percobaan**
        bool loginSuccess = false;
        int attempts = 3;
        
        while (attempts > 0) {
            string username, password;
            cout << "Masukkan Username: ";
            getline(cin, username);
            cout << "Masukkan Password: ";
            getline(cin, password);

             // **Validasi Login**
            if (role == 1 && username == "admin" && password == "admin123") {
                Admin = true;
                loginSuccess = true;
                break;
            } else if (role == 2 && username == "Muhammad Rizky Adha Putra" && password == "2409106113") {
                Admin = false;
                loginSuccess = true;
                break;
            }


            attempts--;  // Mengurangi jumlah percobaan
            if (attempts > 0) {
                cout << "User atau password anda salah! Sisa percobaan: " << attempts << endl;
            } else {
                cout << "Anda telah gagal login 3 kali. Program berhenti, Terima kasih sudah mengunjung APLIX." << endl;
                return 0;
            }
        }

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
                if (pilihan == 1) {  // Tambah film
                    if (filmC < 100) {
                        cout << "Masukkan Judul Film: ";
                        getline(cin, judul[filmC]);
                        cout << "Masukkan Genre Film: ";
                        getline(cin, genre[filmC]);
                        cout << "Masukkan Usia Minimal: ";
                        cin >> usia[filmC];
                        cin.ignore();
                        filmC++;
                        cout << "Film berhasil ditambahkan!" << endl;
                    } else {
                        cout << "Penyimpanan penuh!" << endl;
                    }


                } else if (pilihan == 2) {  // Lihat film
                    cout << "\n+-----------------------------------------------------+" << endl;
                    cout << "| No |          Judul          |   Genre   |  Usia  |" << endl;
                    cout << "+-----------------------------------------------------+" << endl;
                    for (int i = 0; i < filmC; ++i) {
                        cout << "| " << setw(2) << i + 1 << " | " << setw(20) << left << judul[i] << " | " << setw(10) << genre[i] << " | " << setw(5) << usia[i] << " |" << endl;
                    }
                    cout << "+-----------------------------------------------------+\n" << endl;


                } else if (pilihan == 3) {  // Ubah film
                    if (filmC == 0) {
                        cout << "Film belum tersedia." << endl;
                    } else {
                        cout << "\n+-----------------------------------------------------+" << endl;
                        cout << "| No |          Judul          |   Genre   |  Usia  |" << endl;
                        cout << "+-----------------------------------------------------+" << endl;
                        for (int i = 0; i < filmC; ++i) {
                            cout << "| " << setw(2) << i + 1 << " | " << setw(20) << left << judul[i] << " | " << setw(10) << genre[i] << " | " << setw(5) << usia[i] << " |" << endl;
                        }
                        cout << "+-----------------------------------------------------+\n" << endl;
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
                            cout << "Film berhasil diubah!" << endl;
                        } else {
                            cout << "Nomor film tidak valid!" << endl;
                        }
                    }



                } else if (pilihan == 4) {  // Hapus film
                    if (filmC == 0) {
                        cout << "Film belum tersedia." << endl;
                    } else {
                        cout << "\n+-----------------------------------------------------+" << endl;
                        cout << "| No |          Judul          |   Genre   |  Usia  |" << endl;
                        cout << "+-----------------------------------------------------+" << endl;
                        for (int i = 0; i < filmC; ++i) {
                            cout << "| " << setw(2) << i + 1 << " | " << setw(20) << left << judul[i] << " | " << setw(10) << genre[i] << " | " << setw(5) << usia[i] << " |" << endl;
                        }
                        cout << "+-----------------------------------------------------+\n" << endl;
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
                            cout << "Film yang anda pilih berhasil dihapus!" << endl;
                        } else {
                            cout << "Nomor film tidak valid!" << endl;
                        }
                    }
                } else if (pilihan == 5) {  // Logout
                    cout << "Logout berhasil!" << endl;
                    break;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }
            } else {  // Menu User
                if (pilihan == 1) {  // Lihat film
                    cout << "\n+-----------------------------------------------------+" << endl;
                    cout << "| No |          Judul          |   Genre   |  Usia  |" << endl;
                    cout << "+-----------------------------------------------------+" << endl;
                    for (int i = 0; i < filmC; ++i) {
                        cout << "| " << setw(2) << i + 1 << " | " << setw(20) << left << judul[i] << " | " << setw(10) << genre[i] << " | " << setw(5) << usia[i] << " |" << endl;
                    }
                    cout << "+-----------------------------------------------------+\n" << endl;
                } else if (pilihan == 2) {  // Logout
                    cout << "Logout berhasil!" << endl;
                    break;
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }
            }
        }
    }
    return 0;
}