#include <iostream>

using namespace std;

// Fungsi untuk memeriksa apakah bilangan prima
bool BilanganPrima(int bp) {
    if (bp <= 1) return false;
    for (int i = 2; i * i <= bp; i++) {
        if (bp % i == 0) return false;
    }
    return true;
}

// Fungsi untuk memeriksa apakah bilangan palindrome
bool BilanganPalindrome(int angka) {
    if (angka < 0) return false;

    int BlganAseli = angka, balikan = 0;
    while (angka > 0) {
        int digit = angka % 10;
        balikan = balikan * 10 + digit;
        angka /= 10;
    }
    return BlganAseli == balikan;
}

// Fungsi untuk memeriksa login 
bool login(string inputUsername, string inputPassword) {
    string Username = "Muhammad Rizky Adha Putra";
    string Password = "2409106113";

    return (inputUsername == Username && inputPassword == Password);
}

int main() {
    int menuUtama;
    string username, password;
    int sandi;

    while (true) {
        cout << "== MENU UTAMA ==" << endl;
        cout << "1. Login" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menuUtama;
        cin.ignore(); // Menghindari bug input 

        if (menuUtama == 1) {
            int kesempatan = 3;

            while (kesempatan > 0) {
                cout << "== MENU LOGIN ==" << endl;
                cout << "Masukkan Username: ";
                getline(cin, username);
                
                cout << "Masukkan Password: ";
                getline(cin, password);
                
                if (login(username, password)) {
                    cout << "Login berhasil! Selamat datang, " << username << "!" << endl;
                    break;
                } else {
                    kesempatan--;
                    cout << "Login gagal! Kesempatan tersisa: " << kesempatan << " kali." << endl;
                    if (kesempatan == 0) {
                        cout << "Anda gagal login 3 kali. Kembali ke menu utama." << endl;
                    }
                }
            }

            if (kesempatan == 0) continue;

            do {
                cout << "Masukkan kode sandi (harus lebih dari 100 dan tidak boleh lebih dari 99999): ";
                cin >> sandi;

                if (sandi <= 100 || sandi > 99999) {
                    cout << "Kode sandi tidak valid! Harus lebih dari 100 dan tidak boleh lebih dari 99999." << endl;
                }
            } while (sandi <= 100 || sandi > 99999);
            
            int pilihan;
            while (true) {
                cout << "== Menu Program Verifikasi Password ==" << endl;
                cout << "Kode sandi yang Anda masukkan: " << sandi << endl;
                cout << "1. Cek kode sandi bilangan prima" << endl;
                cout << "2. Cek kode sandi habis dibagi 2 dan 3 tetapi tidak habis dibagi 5" << endl;
                cout << "3. Cek kode sandi bilangan palindrome" << endl;
                cout << "4. Cek kode sandi bilangan ganjil" << endl;
                cout << "5. Cek kode sandi bilangan genap" << endl;
                cout << "6. Kembali ke menu utama" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;

                cout << "Kode sandi: " << sandi << endl;

                switch (pilihan) {
                    case 1:
                        cout << (BilanganPrima(sandi) ? "Kode sandi adalah bilangan prima." : "Kode sandi bukan bilangan prima.") << endl;
                        break;
                    case 2:
                        cout << ((sandi % 2 == 0 && sandi % 3 == 0 && sandi % 5 != 0) ? "Kode sandi memenuhi syarat." : "Kode sandi tidak memenuhi syarat.") << endl;
                        break;
                    case 3:
                        cout << (BilanganPalindrome(sandi) ? "Kode sandi adalah bilangan palindrome." : "Kode sandi bukan bilangan palindrome.") << endl;
                        break;
                    case 4:
                        cout << ((sandi % 2 != 0) ? "Kode sandi adalah bilangan ganjil." : "Kode sandi bukan bilangan ganjil.") << endl;
                        break;
                    case 5:
                        cout << ((sandi % 2 == 0) ? "Kode sandi adalah bilangan genap." : "Kode sandi bukan bilangan genap.") << endl;
                        break;
                    case 6:
                        cout << "Anda telah kembali ke menu utama" << endl;
                        goto menu_utama;
                    default:
                        cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
                        break;
                }
            }

        } else if (menuUtama == 2) {
            cout << "Program telah berhenti. Terima kasih sudah menggunakan ^^" << endl;
            return 0;
        } else {
            cout << "Pilihan tidak valid! Silakan pilih 1 dan 2" << endl;
        }

        menu_utama:; // Label untuk kembali ke menu utama dari menu verifikasi password
    }
}
