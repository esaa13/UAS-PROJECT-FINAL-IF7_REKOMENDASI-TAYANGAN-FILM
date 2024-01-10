#include <iostream>
// menggunakan library vector untuk memanipulasi vektor.
#include <vector>
// Menggunakan library iomanip untuk memanipulasi output.
#include <iomanip>

// Menggunakan namespace std untuk mempersingkat penulisan kode.
using namespace std;

// Fungsi ini bertujuan untuk membersihkan layar.
void clearScreen()
{
    // Menggunakan perintah system("cls") untuk membersihkan layar.
    system("cls");
}

// Fungsi ini bertujuan untuk menampilkan header dengan format "headerText" di layar. &headerText adalah referensi ke string yang berisi teks header.
void printHeader(const string& headerText)
{
    // Menampilkan header dengan format "headerText" di layar. dengan warna kuning. \033[33m adalah kode warna kuning.
    cout << "\033[33m" << " ====================================================== " << endl;
    cout << "\033[33m" << " ||                                                  || " << endl;
    cout << "\033[33m" << " || " << headerText << " || " << endl;
    cout << "\033[33m" << " ||                                                  || " << endl;
    cout << "\033[33m" << " ====================================================== " << endl;
    cout << "\033[0m"; // \033[0m adalah kode untuk mengembalikan warna ke default.
}

// Fungsi ini bertujuan untuk menampilkan menu dengan format "options" di layar. &options adalah referensi ke vektor string yang berisi pilihan menu.
void printMenu(const vector<string>& options)
{
    // Menampilkan menu dengan format "options" di layar.
    cout << "+======================================================+" << endl;
    // Melakukan iterasi melalui vektor 'options' untuk menampilkan setiap pilihan menu. &option adalah referensi ke string yang berisi pilihan menu.
    for (const auto& option : options)
    {
        // Menampilkan setiap pilihan menu dengan format "| option |" di layar. setw(54 - option.length()) digunakan untuk menampilkan spasi agar format tetap rapi.
        cout << "| " << option << setw(54 - option.length()) << "|" << endl;
    }
    cout << "+======================================================+" << endl;
}

// Fungsi ini bertujuan untuk menampilkan rekomendasi tayangan berdasarkan pilihan negara, jenis tayangan, dan genre.
// Parameter yang diterima adalah 'recommendations' (vektor rekomendasi), 'negara', 'pilihan', dan 'genre'.
void displayRecommendations(const vector<vector<vector<vector<string>>>>& recommendations, int negara, int pilihan, int genre)
{
    // Mendapatkan referensi ke vektor string yang berisi rekomendasi sesuai dengan input negara, pilihan, dan genre.
    const vector<string>& recs = recommendations[negara - 1][pilihan - 1][genre - 1];

    // Melakukan iterasi melalui vektor 'recs' untuk menampilkan setiap rekomendasi.
    for (const auto& recommendation : recs)
    {
        // Menampilkan setiap rekomendasi dengan format "nama_rekomendasi" di layar.
        cout << endl << "--- " << recommendation << " ---" << endl;
    }
}

int main()
{
    // Memanggil fungsi 'clearScreen' untuk membersihkan layar.
    clearScreen();
    // Memanggil fungsi 'printHeader' untuk menampilkan pesan "SELAMAT DATANG DI PROGRAM REKOMENDASI TAYANGAN" di layar.
    printHeader(" SELAMAT DATANG DI PROGRAM REKOMENDASI TAYANGAN ");

    // Deklarasi vektor 'countries' untuk menyimpan pilihan negara.
    vector<string> countries = { "1. Indonesia", "2. Korea Selatan", "3. Barat" };
    // Deklarasi vektor 'types' untuk menyimpan pilihan jenis tayangan.
    vector<string> types = { "1. Film", "2. Series" };
    // Deklarasi vektor 'genres' untuk menyimpan pilihan genre.
    vector<string> genres = { "1. Thriller", "2. Romance", "3. Action", "4. Comedy", "5. Horor", "6. Animasi" };
    // Deklarasi variabel 'negara', 'pilihan', dan 'genre' untuk menyimpan input dari user.
    int negara, pilihan, genre; 

    // memanggil fungsi 'printMenu' untuk menampilkan pilihan negara.
    printMenu(countries);
    cout << "Pilihanmu: ";
    cin >> negara;
    clearScreen();

    // memanggil fungsi 'printMenu' untuk menampilkan pilihan jenis tayangan.
    printMenu(types);
    cout << "Pilihanmu: ";
    cin >> pilihan;
    clearScreen();

    // memanggil fungsi 'printMenu' untuk menampilkan pilihan genre.
    printMenu(genres);
    cout << "Pilihanmu: ";
    cin >> genre;
    clearScreen();

    // Deklarasi vektor 'recommendations' untuk menyimpan rekomendasi tayangan berdasarkan negara, jenis, dan genre
    vector<vector<vector<vector<string>>>> recommendations = {
        // Indonesia
        {
            // Film
            {
                // Thriller
                {"Berbalas Kejam", "Pengabdi Setan", "Night Bus"},
                // Romance
                {"Mariposa", "Dilan 1990", "Habibie & Ainun"},
                // Action
                {"The Raid", "Gundala", "Hit & Run"},
                // Comedy
                {"Yowis Ben", "My Stupid Boss", "Susah Signal", "Cek Toko Sebelah"},
                // Horor
                {"Siksa Neraka", "Danur", "Alas Pati"},
                // Animasi
                {"Battle Of Surabaya", "Si Juki", "Knight Kris"}
              },
        // Series
        {
            // Thriller
            {"Paradise Garden", "Rencana Besar", "Hitam"},
            // Romance
            {"Mantan Tapi Menikah", "Kitab Kencan", "Jodoh Atau Bukan"},
            // Action
            {"Jawara", "Serigala Terakhir The Series", "Brutal"},
            // Comedy
            {"Drama Ratu Drama", "Imperfect The Series", "Suka Duka Berduka"},
            // Horor
            {"Twisted", "Ritual The Series", "Kisah Tanah Jawa : Merapi"},
            // Animasi
            {"Adit & Sopo Jarwo", "Keluarga Somat", "Petualangan Si Unyil"}
          }
      },
        // Korea Selatan
        {
            // Film
            {
                // Thriller
                {"Old boy", "Signal", "I Saw the Devil"},
                // Romance
                {"My Sassy girl", "Crash Landing on you", "The Beauty Inside"},
                // Action
                {"Train To Busan", "Vagabond", "The Man from Nowhere"},
                // Comedy
                {"My love from the star", "What's Wrong with secretary Kim", "Extreme Job"},
                // Horor
                {"The Wailling", "Kingdom", "A Tale of Two Sister"},
                // Animasi
                {"leafi. A Hen into the wild", "Yobi.The Five Tailed Fox", "Seoul Station"}
              },
        // Series
        {
            // Thriller
            {"Stranger", "Voice", "Save Me"},
            // Romance
            {"Crash landing and You", "Goblin", "My ID is Gangnam Beauty"},
            // Action
            {"Vagabond", "Descendants of the sun", "IRIS"},
            // Comedy
            {"Kingdom", "Strangers From Hell", "The Guest"},
            // Horor
            {"The Spectacular Journey", "The Little Fox", "Dibo the gift dragon"},
            // Animasi
            {"Reply 1988", "Eulachacha Waikiki", "Wok Of Love"}
          }
      },
        // Barat
        {
            // Film
            {
                // Thriller
                {"Plane", "Missing", "The Hunt"},
                // Romance
                {"Titanic", "Dear John", "Paper Town"},
                // Action
                {"Rango", "The Dark Tower", "The Revenant"},
                // Comedy
                {"Rush Hour", "Jumanji", "Hail The Judge"},
                // Horor
                {"The Ring", "Get Out", "The Shining"},
                // Animasi
                {"The Lion King", "Toy Story", "Epic"}
              },
        // Series
        {
            // Thriller
            {"Goodless", "Supernatural", "Freud"},
            // Romance
            {"Inside Man", "Devil In Ohio", "From Scratch"},
            // Action
            {"Archer", "Adventure Time", "Hollywood"},
            // Comedy
            {"New Girl", "The Good Place", "The Big Bang Theory"},
            // Horor
            {"Kingdom", "Sweet Home", "Midnight Mass"},
            // Animasi
            {"Over The Garden Wall", "Gravity Falls", "The Owl House"}
          }
      }
    };

    // Memanggil fungsi 'printHeader' untuk menampilkan pesan "REKOMENDASI TAYANGAN DARI KAMI" di layar.
    printHeader("REKOMENDASI TAYANGAN DARI KAMI");
    // Memanggil fungsi 'displayRecommendations' untuk menampilkan rekomendasi tayangan berdasarkan negara, jenis, dan genre.
    displayRecommendations(recommendations, negara, pilihan, genre);

    // Deklarasi variabel 'puas' untuk menyimpan input dari user.
    int puas;
    cout << endl << "Apakah anda puas dengan rekomendasi kami?" << endl;
    cout << "Ketik 1 jika puas, ketik 2 jika tidak puas: ";
    cin >> puas;

    // Memanggil fungsi 'clearScreen' untuk membersihkan layar.
    clearScreen();
    // Memanggil fungsi 'printHeader' untuk menampilkan pesan sesuai dengan input 'puas'.
    // jika puas tidak sama dengan 1, maka tampilkan pesan "Maaf jika rekomendasi dari kami tidak sesuai" di layar.
    // jika puas sama dengan 1, maka tampilkan pesan "Oke, Selamat Menonton :)" di layar.
    printHeader((puas != 1) ? " Maaf jika rekomendasi dari kami tidak sesuai " : "\t Oke, Selamat Menonton :) \t");

    return 0;
}